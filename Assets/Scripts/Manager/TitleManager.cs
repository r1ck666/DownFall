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
	/// エラーログを表示するウィンドウ
	/// </summary>
	[SerializeField] GameObject errorDialog;
	[SerializeField] Text errorText;

	/// <summary>
	/// ルーム選択画面のメニュー
	/// </summary>
	[SerializeField] GameObject menu;
	[SerializeField] Text[] menuText;

	/// <summary>
	/// 名前入力ウィンドウ
	/// </summary>
	[SerializeField] GameObject nameField;
	[SerializeField] InputField inputNameField;

	RoomInfo[] roomInfo;

	protected override void Awake()
	{
		base.Awake();
		// Photon

		// #NotImportant
        PhotonNetwork.logLevel = Loglevel;

        // 自動でロビーに入るかどうかを設定します
        PhotonNetwork.autoJoinLobby = false;

		// #Critical
        // マスタークライアントに合わせて同じルームのプレイヤーがシーンをロードするかを決めます
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
		nameField.SetActive(false);
		progressLabel.SetActive(false);
		menu.SetActive(false);
		gameVersionLabel.transform.parent.gameObject.SetActive(true);
		errorDialog.SetActive(false);
	}

    /// <summary>
    /// ロビーに接続します
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
			if (PhotonNetwork.player.NickName == "") {
				OpenNameField();
			} else {
				OpenMenu();
			}
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
		OpenErrorDialog ("ルームの接続に失敗しました。");

	}


	/// <summary>
    /// 名前入力欄を表示します
    /// </summary>
	public void OpenNameField() {
		nameField.SetActive(true);
		iTween.ScaleFrom(nameField, iTween.Hash("x", 0, "y", 0, "z", 0));
		progressLabel.SetActive(false);
	}

	/// <summary>
    /// 名前をPhotonServerに送ります
    /// </summary>
	public void SubmitName() {
		progressLabel.SetActive(true);
		PhotonNetwork.player.NickName = inputNameField.text;
		nameField.SetActive(false);
		OpenMenu();
	}

	/// <summary>
    /// MainMenuを表示します
    /// </summary>
	public void OpenMenu() {
		menu.SetActive(true);
		iTween.ScaleFrom(menu, iTween.Hash("x", 0, "y", 0, "z", 0));
		UpdateRoomInfo();
		progressLabel.SetActive(false);
	}

	/// <summary>
    /// MenuButtonから呼び出してルームに接続します
    /// </summary>
	public void JoinRoom (int n) {
		progressLabel.SetActive(true);
		switch (n) {
			case 2:
				PhotonNetwork.JoinOrCreateRoom("2", new RoomOptions { MaxPlayers = 2 }, null);
				break;
			case 4:
				PhotonNetwork.JoinOrCreateRoom("4", new RoomOptions { MaxPlayers = 4 }, null);
				break;
			case 6:
				PhotonNetwork.JoinOrCreateRoom("6", new RoomOptions { MaxPlayers = 6 }, null);
				break;
			case 8:
				PhotonNetwork.JoinOrCreateRoom("8", new RoomOptions { MaxPlayers = 8 }, null);
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
			int n = int.Parse(info.Name);
			counts[n/2-1] = info.PlayerCount;
		}
		for (int i=0; i<4; i++) {
			menuText[i].text = "現在の人数： " + counts[i].ToString() + " / " + ((i+1)*2).ToString();
		}
	}

	/// <summary>
    /// エラーダイアログを表示します
    /// </summary>
	public void OpenErrorDialog (string mes) {
		errorDialog.SetActive(true);
		errorText.text = mes;
	}

	/// <summary>
    /// エラーダイアログを閉じます
    /// </summary>
	public void CloseErrorDialog(){
		errorDialog.SetActive(false);
		errorText.text = "";
	}

}
