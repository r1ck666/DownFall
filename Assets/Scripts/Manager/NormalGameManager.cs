using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NormalGameManager : SingletonPhotonMonoBehaviour<NormalGameManager> {

	//================================
	// Network設定関連
	//================================
	string _gameVersion = "1";

	//================================
	// GameRole関連
	//================================

	// 制限時間
	[SerializeField] float timeLimit = 300f;
	// 岩ブロック最大数
	[SerializeField] readonly int ROCK_MAX = 10;
	// プレイヤーのPower
	[SerializeField] int power = 1;

	//================================
	// StageManager関連
	//================================

	// プロパティ宣言
	Stage stage;
	public Stage Stage {
		get { return stage; }
	}
	uint[,,] blocks;
	public uint[,,] Blocks {
		get { return blocks; }
	}
	Block[,,] blocksObject;
	public Block[,,] BlocksObject {
		get { return blocksObject; }
	}

	// ブロック耐久度
	[SerializeField] readonly int DURABILITY_NONE = 3;
	[SerializeField] readonly int DURABILITY_NORMAL = 1;
	[SerializeField] readonly int DURABILITY_UNBREAK = 999;
	[SerializeField] readonly int DURABILITY_BROKEN = 1;

	// ブロックのTexture
	[SerializeField] Material MATERIAL_NORMAL;
	[SerializeField] Material MATERIAL_UNBREAK;
	[SerializeField] Material MATERIAL_BROKEN;

	//================================
	// UI関連
	//================================


	//================================

	protected override void Awake()
	{
		base.Awake();
	}

	void Start()
	{
		// Stage関連のキャッシュ
		stage = StageManager.Instance.GetStage();
		blocks = stage.GetBlocks();
		blocksObject = StageManager.Instance.GetBlocksObject();

	}

	//================================
	// Photon関連
	// 入室・退室処理
	//================================

	public override  void OnLeftRoom()
	{
		SceneManager.LoadScene(0);
	}

	public void LeaveRoom()
	{
		PhotonNetwork.LeaveRoom();
	}

	public override void OnPhotonPlayerConnected( PhotonPlayer other  )
	{
    	Debug.Log( "OnPhotonPlayerConnected() " + other.name ); // not seen if you're the player connecting

    	if ( PhotonNetwork.isMasterClient )
    	{
        	Debug.Log( "OnPhotonPlayerConnected isMasterClient " + PhotonNetwork.isMasterClient ); // called before OnPhotonPlayerDisconnected

    	}
	}

	public override void OnPhotonPlayerDisconnected( PhotonPlayer other  )
	{
    	Debug.Log( "OnPhotonPlayerDisconnected() " + other.name ); // seen when other disconnects

    	if ( PhotonNetwork.isMasterClient )
    	{
        	Debug.Log( "OnPhotonPlayerConnected isMasterClient " + PhotonNetwork.isMasterClient ); // called before OnPhotonPlayerDisconnected

    	}
	}

	//================================
	// Character関連
	//================================

	//もしかして参照しているから、チェンジしても反映されない？
	// ChangeBlock後にChangeされているか確認しよう

	/// <summary>
    /// ブロックを修復・破壊するメソッド
    /// </summary>
    /// <param name="x">破壊するブロックのX座標</param>
	/// <param name="z">破壊するブロックのZ座標</param>
    /// <returns>ブロックが修復・破壊可能かを返します</returns>
	public bool ActionJudge (int x, int z) {

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

		Block block = blocksObject[x, y, z];
		Renderer re = block.GetComponent<Renderer>();

		switch (state) {
			case BlockState.NONE:
				blocks[x, y, z] = 0;
				block.Durability = DURABILITY_NONE;
				block.State = state;
				re.enabled = false;
				photonView.RPC("DownFall", PhotonTargets.AllBufferedViaServer, x, y, z);
				break;
			case BlockState.NORMAL:
				blocks[x, y, z] = 1;
				block.Durability = DURABILITY_NORMAL;
				block.State = state;
				re.enabled = true;
				re.material = MATERIAL_NORMAL;
			 	break;
			case BlockState.UNBREAK:
				blocks[x, y, z] = 2;
				block.Durability = DURABILITY_UNBREAK;
				block.State = state;
				re.enabled = true;
				re.material = MATERIAL_UNBREAK;
				break;
			case BlockState.BROKEN:
				blocks[x, y, z] = 3;
				block.Durability = DURABILITY_BROKEN;
				block.State = state;
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
		DebugLogger.Log("UpdateStage!");

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

	/// <summary>
    /// ブロックの落下の処理をします
    /// </summary>
    /// <param name="x">変更のあったブロックのX座標</param>
	/// <param name="y">変更のあったブロックのY座標</param>
	/// <param name="z">変更のあったブロックのZ座標</param>
	[PunRPC]
	void DownFall　(int x, int y, int z)
	{

	}
}
