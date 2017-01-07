using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

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
	GameObject[,,] blocksObject;


	void Awake()
	{
		base.Awake();
		// Photon

		// #NotImportant
        // Force Full LogLevel
        PhotonNetwork.logLevel = PhotonLogLevel.Full;

		// #Critical
        // we don't join the lobby. There is no need to join a lobby to get the list of rooms.
        PhotonNetwork.autoJoinLobby = false;

		// #Critical
        // this makes sure we can use PhotonNetwork.LoadLevel() on the master client and all clients in the same room sync their level automatically
        PhotonNetwork.automaticallySyncScene = true;

	}

	void Start()
	{
		// Stage関連のキャッシュ
		stage = StageManager.Instance.GetStage();
		blocks = stage.GetBlocks();
		blocksObject = StageManager.Instance.GetBlocksObject();

		// Photonに接続
		Connect();

	}

	//==================================
	// Photon関連のメソッド
	//==================================

	public void Connect()
	{
		if (PhotonNetwork.connected)
		{
			PhotonNetwork.JoinRandomRoom();
		} else {
			PhotonNetwork.ConnectUsingSettings(_gameVersion);
		}
	}

	// Lobbyへ接続成功
	void OnJoinedLobby() {
		Debug.Log("OnJoinedLobby");
		// 現在あるRoomにランダムで接続
		PhotonNetwork.JoinRandomRoom();
	}

	//ランダムでRoomに接続失敗
	void OnPhotonRandomJoinFailed() {
		Debug.Log("OnPhotonRandomJoinFailed");
		// Room作成
		PhotonNetwork.CreateRoom(null);
	}

	// Room作成成功
	void OnCreatedRoom() {
		Debug.Log("OnCreatedRoom");
		// 自動的にOnJoinedRoom呼び出し
	}

	// Room入室成功時
	void OnJoinedRoom() {
		Debug.Log("OnJoinedRoom");
	}



}
