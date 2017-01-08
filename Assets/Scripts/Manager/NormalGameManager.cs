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
	[SerializeField] uint rockNum = 10;

	//================================
	// StageManager関連
	//================================

	Stage stage;
	uint[,,] blocks;
	Block[,,] blocksObject;

	//================================
	// UI関連
	//================================

	public GameObject button;

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

	public bool ActionJudge (uint x, uint z) {

		if (blocksObject[x,1,z].State = State.NONE ) {

			switch (blocksObject[x, 0, z].State) {
				case BlockState.NONE:
					blocksObject[x, 0, z].Durability = blocksObject[x, 0, z].Durability - 1;
					if (blocksObject[x, 0, z].Durability <= 0) {
						
					}
					break;
				case BlockState.NORMAL:
					break;
				case BlockState.UNBREAK:
					break;
				case BlockState.BROKEN:
					break;
			}
		} else {
			return false;
		}
		//これは自分だけ処理が早い
		photonView.RPC("StageChange", PhotonTargets.AllBuffered);
		//y座標が1の時にブロックがなければ、y座標0を調べる
		return AnimState.BREAK;

	}

	void ChangeBlock (int x, int y, int z, BlockState state)
	{

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
	// Photon関連
	// RPC系
	//================================

	[PunRPC]
	void StageChange()
	{
		//アクションボタンを押した時の処理
		DebugLogger.Log("StageChange!");
	}
}
