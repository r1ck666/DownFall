using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NormalGameManager : SingletonPhotonMonoBehaviour<NormalGameManager> {


	//================================
	// Character関連
	//================================

	[SerializeField] GameObject playerPrefab;
	[SerializeField] GameObject player;
	// プレイヤーの番号
	[SerializeField] int playerNum;

	//================================
	// GameRole関連
	//================================

	// 制限時間
	[SerializeField] float limitTime = 120.0f;
	// 岩ブロック最大数
	[SerializeField] readonly int ROCK_MAX = 10;
	// プレイヤーのPower
	[SerializeField] int power = 1;
	// ゲーム開始カウント
	[SerializeField] int preCount = 5;
	// 同期時間周期
	[SerializeField] float timePeriod = 10.0f;

	//================================
	// StageManager関連
	//================================

	// プロパティ宣言
	Stage stage;
	public Stage Stage { get { return stage; } }
	uint[,,] blocks;
	public uint[,,] Blocks { get { return blocks; } }
	Block[,,] blocksObject;
	public Block[,,] BlocksObject { get { return blocksObject; } }

	// ブロック耐久度
	[SerializeField] readonly int DURABILITY_NONE = 3;
	[SerializeField] readonly int DURABILITY_NORMAL = 1;
	[SerializeField] readonly int DURABILITY_UNBREAK = 999;
	[SerializeField] readonly int DURABILITY_BROKEN = 1;

	// ブロックのTexture
	[SerializeField] Material MATERIAL_NORMAL;
	[SerializeField] Material MATERIAL_UNBREAK;
	[SerializeField] Material MATERIAL_BROKEN;

	// 再起関数用（上・下・左・右）
	int[] dicX = new int[] {0, 0, -1, 1};
	int[] dicZ = new int[] {1, -1, 0, 0};


	//================================
	// UI関連
	//================================


	//================================

	protected override void Awake()
	{
		base.Awake();
		PhotonNetwork.isMessageQueueRunning = true;
	}

	void Start()
	{
		// Stage関連のキャッシュ
		stage = StageManager.Instance.Stage;
		blocks = stage.Blocks;
		blocksObject = StageManager.Instance.BlocksObject;

		//PhotonInstantiate
		if (playerPrefab == null) {
    		Debug.LogError("NormalGameManager: PlayerPrefabをインスペクタから設定してください");
		} else {
    			InitializePlayer();
		}

		StartCoroutine(Ready());

	}

	//================================
	// Photon関連
	// 入室・退室処理
	//================================

	public override void OnLeftRoom()
	{
		SceneManager.LoadScene(0);
	}

	public void LeaveRoom()
	{
		PhotonNetwork.LeaveRoom();
	}

	//================================
	// Character関連
	//================================

	/// <summary>
    /// プレイヤーの情報などを初期化します
    /// </summary>
	void InitializePlayer() {
		var playerList = PhotonNetwork.playerList;
		var playerCount = PhotonNetwork.room.PlayerCount;

		// PlayerListのソート
		for (int i = 0; i < playerCount-1; i++) {
			for(int j=0; j < playerCount-1 - i; j++ ) {
				if (playerList[j].ID > playerList[j+1].ID){
					var temp = playerList[j];
					playerList[j] = playerList[j+1];
					playerList[j+1] = temp;
				}
			}
		}

		// Playerの番号を取得
		for (int i = 0; i < playerCount; i++ ){
			if (playerList[i] == PhotonNetwork.player) {
				playerNum = i;
				break;
			}
		}

		// Stageクラスの初期位置を読み込み
		var startPos = new Vector3(stage.StartPosition[playerNum, 0], stage.StartPosition[playerNum, 1], stage.StartPosition[playerNum, 2]);
		var startRot = Quaternion.Euler(stage.StartPosition[playerNum, 3], stage.StartPosition[playerNum, 4], stage.StartPosition[playerNum, 5]);
		player = PhotonNetwork.Instantiate(playerPrefab.name, startPos, startRot, 0);
		player.GetComponent<PlayerController>().IsPlay = false;

		var camera = Camera.main.GetComponent<FollowCamera>();
		camera.LookTarget = player.transform;
		camera.HorizontalAngle = stage.StartPosition[playerNum, 4];
		UIManager.Instance.SetPlayer();
	}

	//================================
	// GameSystem関連
	//================================

	IEnumerator Ready () {
		int count = preCount;
		while (true) {
			if (count <= 0) break;
			UIManager.Instance.TimeCount(count.ToString());
			count -= 1;
			yield return new WaitForSeconds(1);
		}
		UIManager.Instance.TimeCount("GO!");
		GameStart();
	}

	IEnumerator LimitTime () {
		float count = limitTime;
		while (true) {
			UIManager.Instance.SetLimitTime(count);
			yield return null;
			count -= Time.deltaTime;
			if (count < 0 ) break;
		}
		GameEnd();
	}

	void GameStart () {
		player.GetComponent<PlayerController>().IsPlay = true;
		StartCoroutine(LimitTime());
	}

	void GameEnd () {
		player.GetComponent<PlayerController>().IsPlay = false;
	}


	/// <summary>
    /// ブロックを修復・破壊するメソッド
    /// </summary>
    /// <param name="x">破壊するブロックのX座標</param>
	/// <param name="z">破壊するブロックのZ座標</param>
    /// <returns>ブロックが修復・破壊可能かを返します</returns>
	public bool ActionJudge (int x, int z) {

		//DebugLogger.Log("ActionJudge called X:" + x + " Z:" + z);

		if (blocksObject[x,1,z].State == BlockState.NONE ) {

			Block block = blocksObject[x, 0, z];
			if ( block.State != BlockState.UNBREAK ) {
				photonView.RPC("UpdateStage", PhotonTargets.AllBufferedViaServer, x, 0, z);
				return true;
			}
			return false;
		} else {
			return false;
		}
	}

	/// <summary>
    /// ブロックの変更を行います
    /// </summary>
    /// <param name="x">破壊するブロックのX座標</param>
	/// <param name="y">破壊するブロックのY座標</param>
	/// <param name="z">破壊するブロックのZ座標</param>
	/// <param name="state">変更先のブロックの種類</param>
	void ChangeBlock (int x, int y, int z, BlockState state)
	{

		//DebugLogger.Log("ChangeBlock called X:" + x + " Y:" + y + " Z:" + z);

		Block block = blocksObject[x, y, z];
		Renderer re = block.GetComponent<Renderer>();

		switch (state) {
			case BlockState.NONE:
				//DebugLogger.Log("ChangeBlock called State: NONE");
				blocks[x, y, z] = 0;
				block.Durability = DURABILITY_NONE;
				block.State = state;
				block.GetComponent<BoxCollider>().enabled = false;
				re.enabled = false;
				photonView.RPC("DownFall", PhotonTargets.AllBufferedViaServer, x, z);
				break;
			case BlockState.NORMAL:
				//DebugLogger.Log("ChangeBlock called State: NORMAL");
				blocks[x, y, z] = 1;
				block.Durability = DURABILITY_NORMAL;
				block.State = state;
				block.GetComponent<BoxCollider>().enabled = true;
				re.enabled = true;
				re.material = MATERIAL_NORMAL;
			 	break;
			case BlockState.UNBREAK:
				//DebugLogger.Log("ChangeBlock called State: UNBREAK");
				blocks[x, y, z] = 2;
				block.Durability = DURABILITY_UNBREAK;
				block.State = state;
				block.GetComponent<BoxCollider>().enabled = true;
				re.enabled = true;
				re.material = MATERIAL_UNBREAK;
				break;
			case BlockState.BROKEN:
				//DebugLogger.Log("ChangeBlock called State: BROKEN");
				blocks[x, y, z] = 3;
				block.Durability = DURABILITY_BROKEN;
				block.State = state;
				block.GetComponent<BoxCollider>().enabled = true;
				re.enabled = true;
				re.material = MATERIAL_BROKEN;
				break;
		}
	}

	/// <summary>
    /// ブロックの変更を更新します (耐久度などの情報も更新)
    /// </summary>
    /// <param name="x">破壊するブロックのX座標</param>
	/// <param name="y">破壊するブロックのY座標</param>
	/// <param name="z">破壊するブロックのZ座標</param>
	[PunRPC]
	void UpdateStage(int x, int y, int z)
	{
		//アクションボタンを押した時の処理
		//DebugLogger.Log("UpdateStage called X:" + x + " Y:" + y + " Z:" + z);

		Block block = blocksObject[x, y, z];

		switch (block.State) {
			case BlockState.NONE:
				block.Durability -= power;
				if (block.Durability <= 0) {
					ChangeBlock (x, 0, z, BlockState.NORMAL);
				}
				break;
			case BlockState.NORMAL:
				block.Durability -= power;
				if (block.Durability <= 0) {
					ChangeBlock (x, 0, z, BlockState.BROKEN);
				}
				break;
			case BlockState.UNBREAK:
				break;
			case BlockState.BROKEN:
				block.Durability -= power;
				if (block.Durability <= 0) {
					ChangeBlock (x, 0, z, BlockState.NONE);
				}
				break;
		}

	}

	//================================
	// 落下処理１
	//================================

	/*
	/// <summary>
    /// ブロックの落下の処理をします
    /// </summary>
    /// <param name="x">変更のあったブロックのX座標</param>
	/// <param name="z">変更のあったブロックのZ座標</param>
	[PunRPC]
	void DownFall　(int x, int z)
	{
		bool[,] memo = new bool[stage.X, stage.Z];
		bool[,] flg = new bool[stage.X, stage.Z];
		//DebugLogger.Log("DownFall called X:" + x + " Z:" + z);
		for (int i=0; i<4; i++) {
			bool[,] done = new bool[stage.X, stage.Z];
			//DebugLogger.Log("DownFall called i:" + i + " Start");
			RecursiveJudge (x, z, x+dicX[i], z+dicZ[i], done, memo, flg);
			//DebugLogger.Log("DownFall called i:" + i + " End");
		}
	}

	/// <summary>
    /// 隣接したブロックがない場合、ブロックを落下させる再起の探索を行います
    /// </summary>
	/// <param name="prex">1つ前ののX座標</param>
	/// <param name="prez">１つ前のZ座標</param>
    /// <param name="x">探索中ののX座標</param>
	/// <param name="z">探索中のZ座標</param>
	/// <param name="done">探索済みフラグ</param>
	/// <param name="memo">メモ化漸化式用</param>
	/// <param name="flg">スキップ用フラグ</param>
	bool RecursiveJudge (int prex, int prez, int x, int z, bool[,] done, bool[,] memo, bool[,] flg)
	{
		//DebugLogger.Log("RecursiveJudge called X:" + x + " Z:" + z);
		if ( blocksObject[x, 0, z].State == BlockState.UNBREAK ) return memo[x, z] = true;
		if ( blocksObject[x, 0, z].State == BlockState.NONE ) return memo[x, z] = false;
		if ( memo[x, z] ) return true;	//メモ化再起
		if ( flg[x, z] ) return false;
		if ( done[x, z] ) {
			flg[x, z] = true;
			return RecursiveJudge (x, z, prex, prez, done, memo, flg);
		}
		done[x, z] = true;
		for (int i=0; i<4; i++) {
			//DebugLogger.Log("RecursiveJudge called X:" + x + " Z:" + z + " i:" + i);
			if (RecursiveJudge (x, z, x+dicX[i], z+dicZ[i], done, memo, flg) ){
				return memo[x, z] = true;
			}
		}
		// 落下処理
		//DebugLogger.Log("X:" + x + " Z: " + z + "が落下しました。");
		iTween.MoveTo(blocksObject[x, 0, z].gameObject, iTween.Hash(
				"y", -10,
				"time", 5,
				"oncomplete", "InitializePosY",
				"oncompletetarget", blocksObject[x, 0, z].gameObject
		));
		blocks[x, 0, z] = 0;
		blocksObject[x, 0, z].State = BlockState.NONE;
		blocksObject[x, 0, z].Durability = DURABILITY_NONE;
		return memo[x, z] = false;
	}

	*/

	//================================
	// 落下処理２（こっちを採用）
	//================================

	/// <summary>
    /// ブロックの落下の処理をします
    /// </summary>
    /// <param name="x">変更のあったブロックのX座標</param>
	/// <param name="z">変更のあったブロックのZ座標</param>
	[PunRPC]
	void DownFall　(int x, int z)
	{

		//DebugLogger.Log("DownFall called X:" + x + " Z:" + z);
		for (int i=0; i<4; i++) {
			bool[,] done = new bool[stage.X, stage.Z];
			List<int> fallX = new List<int>();
			List<int> fallZ = new List<int>();
			//DebugLogger.Log("DownFall called i:" + i + " Start");

			// falseが返ってきた時に落下処理を行う
			if (!RecursiveJudge (x+dicX[i], z+dicZ[i], ref done, ref fallX, ref fallZ)){
				//落下処理
				for (int j = 0; j < fallX.Count; j++) {

					//DebugLogger.Log("X:" + fallX[j] + " Z: " + fallZ[j] + "が落下しました。");
					iTween.MoveTo(blocksObject[fallX[j], 0, fallZ[j]].gameObject, iTween.Hash(
							"y", -10,
							"time", 5,
							"oncomplete", "InitializePosY",
							"oncompletetarget", blocksObject[fallX[j], 0, fallZ[j]].gameObject
					));
					blocks[fallX[j], 0, fallZ[j]] = 0;
					blocksObject[fallX[j], 0, fallZ[j]].State = BlockState.NONE;
					blocksObject[fallX[j], 0, fallZ[j]].Durability = DURABILITY_NONE;
				}
			}
			//DebugLogger.Log("DownFall called i:" + i + " End");
		}
	}

	/// <summary>
    /// 隣接したブロックがない場合、ブロックを落下させる再起の探索を行います
    /// </summary>
    /// <param name="x">探索中ののX座標</param>
	/// <param name="z">探索中のZ座標</param>
	/// <param name="done">探索済みフラグ</param>
	/// <param name="fallX">探索済みブロックのX座標リスト</param>
	/// <param name="fallZ">探索済みブロックのZ座標リスト</param>
	bool RecursiveJudge (int x, int z, ref bool[,] done, ref List<int> fallX, ref List<int> fallZ)
	{
		//DebugLogger.Log("RecursiveJudge called X:" + x + " Z:" + z);
		if ( blocksObject[x, 0, z].State == BlockState.UNBREAK ) return true;
		if ( blocksObject[x, 0, z].State == BlockState.NONE ) return false;
		if ( done[x, z] ) return false;
		done[x, z] = true;
		for (int i=0; i<4; i++) {
			//DebugLogger.Log("RecursiveJudge called X:" + x + " Z:" + z + " i:" + i);
			if (RecursiveJudge (x+dicX[i], z+dicZ[i], ref done, ref fallX, ref fallZ) ){
				return true;
			}
		}
		//falseが返ってきた場合、リストに追加する
		fallX.Add(x);
		fallZ.Add(z);

		return false;
	}
}
