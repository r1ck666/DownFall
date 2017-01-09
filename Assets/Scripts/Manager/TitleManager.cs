using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TitleManager : SingletonPhotonMonoBehaviour<TitleManager> {

	/// <summary>
    /// This client's version number. Users are separated from each other by gameversion (which allows you to make breaking changes).
    /// </summary>
    string _gameVersion = "v1.0";

	/// <summary>
	/// The PUN loglevel.
	/// </summary>
	public PhotonLogLevel Loglevel = PhotonLogLevel.Informational;

	/// <summary>
	/// PlayStartのボタン
	/// </summary>
	[SerializeField] GameObject playStart;
	bool isPlay = false;
	/// <summary>
	/// Connectingを表示するラベル
	/// </summary>
	[SerializeField] GameObject progressLabel;

	/// <summary>
	/// GameVesionを表示するラベル
	/// </summary>
	[SerializeField] Text gameVersionLabel;

	/// <summary>
	/// エラーログを表示するラベル
	/// </summary>
	[SerializeField] Text errorDialog;

	/// <summary>
	/// ルーム選択画面のメニュー
	/// </summary>
	[SerializeField] GameObject menu;
	[SerializeField] Text[] menuText;

	/// <summary>
	/// 現在選択中のゲームシーンのNo.
	/// </summary>
	int sceneNum = 0;

	RoomInfo[] roomInfo;

	protected override void Awake()
	{
		base.Awake();
		// Photon

		// #NotImportant
        PhotonNetwork.logLevel = Loglevel;

		// #Critical
        // we don't join the lobby. There is no need to join a lobby to get the list of rooms.
        PhotonNetwork.autoJoinLobby = false;

		// #Critical
        // this makes sure we can use PhotonNetwork.LoadLevel() on the master client and all clients in the same room sync their level automatically
        PhotonNetwork.automaticallySyncScene = false;

	}


	void Start() {
		gameVersionLabel.text = "GameVersion: " + _gameVersion;
		InitializeUI();
	}

	void Update() {
		if (menu.activeSelf) {
			UpdateRoomInfo();
		}
	}
	/// <summary>
	/// UI画面を初期化します
	/// </summary>
	public void InitializeUI() {
		playStart.SetActive(true);
		progressLabel.SetActive(false);
		menu.SetActive(false);
		gameVersionLabel.transform.parent.gameObject.SetActive(true);
		errorDialog.transform.parent.gameObject.SetActive(false);
	}

    /// <summary>
    /// Start the connection process.
    /// - If already connected, we attempt joining a random room
    /// - if not yet connected, Connect this application instance to Photon Cloud Network
    /// </summary>
    public void Connect()
    {
		isPlay = true;
		progressLabel.SetActive(true);
        // we check if we are connected or not, we join if we are , else we initiate the connection to the server.
        if (PhotonNetwork.connected)
        {
            PhotonNetwork.JoinLobby();
        }else{
            // #Critical, we must first and foremost connect to Photon Online Server.
            PhotonNetwork.ConnectUsingSettings(_gameVersion);
        }
    }

	/// <summary>
    /// Photon.PunBehabiourのコールバックメソッド
    /// </summary>
	public override void OnConnectedToMaster()
	{
    	DebugLogger.Log("TitleManager: OnConnectedToMaster() was called by PUN");
		// #Critical: The first we try to do is to join a potential existing room. If there is, good, else, we'll be called back with OnPhotonRandomJoinFailed()
		PhotonNetwork.JoinLobby();

	}

	public override void OnJoinedLobby()
	{
		DebugLogger.Log("TitleManager: OnJoinedLobby() was called by PUN");
		if ( isPlay ) {
			isPlay = false;
			menu.SetActive(true);
			iTween.ScaleFrom(menu, iTween.Hash("x", 0, "y", 0, "z", 0));
			progressLabel.SetActive(false);
			UpdateRoomInfo();
		} else {
			InitializeUI();
		}

	}

	public override void OnDisconnectedFromPhoton()
	{
		progressLabel.SetActive(false);
    	Debug.LogWarning("TitleManager: OnDisconnectedFromPhoton() was called by PUN");
	}

	public override void OnPhotonCreateRoomFailed(object[] codeAndMsg)
	{
		DebugLogger.Log("TitleManager: OnPhotonCreateGameFailed() was called by PUN");
	}

	public override void OnJoinedRoom()
	{
    	DebugLogger.Log("TitleManger: OnJoinedRoom() called by PUN. Now this client is in a room.");
		PhotonNetwork.isMessageQueueRunning = false;
		PhotonNetwork.LoadLevel("WaitingRoom");
	}

	public override void OnPhotonJoinRoomFailed(object[] codAndMsg)
	{
		DebugLogger.Log("TitleManger: OnPhotonJoinRoomFailed() called by PUN");
		ErrorDialog ("ルームの接続に失敗しました。");

	}


	/// <summary>
    /// MenuButtonから呼び出してルームに接続します
    /// </summary>
	public void JoinRoom (int n) {
		progressLabel.SetActive(true);
		switch (n) {
			case 2:
				if (PhotonNetwork.JoinOrCreateRoom("2", new RoomOptions { maxPlayers = 2 }, null)){
					sceneNum = 1;
				}
				break;
			case 4:
				if (PhotonNetwork.JoinOrCreateRoom("4", new RoomOptions { maxPlayers = 4 }, null)) {
					sceneNum = 2;
				}
				break;
			case 6:
				if (PhotonNetwork.JoinOrCreateRoom("6", new RoomOptions { maxPlayers = 6 }, null)) {
					sceneNum = 3;
				}
				break;
			case 8:
				if (PhotonNetwork.JoinOrCreateRoom("8", new RoomOptions { maxPlayers = 8 }, null)) {
					sceneNum = 4;
				}
				break;
		}
	}

	/// <summary>
    /// ルーム人数を更新してMenuに表示します
    /// </summary>
	public void UpdateRoomInfo(){
		roomInfo = PhotonNetwork.GetRoomList();
		int[] counts = new int[] {0, 0, 0, 0};
		foreach(RoomInfo info in roomInfo){
			int n = int.Parse(info.name);
			counts[n/2-1] = info.playerCount;
		}
		for (int i=0; i<4; i++) {
			menuText[i].text = "現在の人数： " + counts[i].ToString() + " / " + ((i+1)*2).ToString();
		}
	}

	public void ErrorDialog (string mes) {
		errorDialog.transform.parent.gameObject.SetActive(true);
		errorDialog.text = mes;
	}

}
