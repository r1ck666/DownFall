using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using System.Linq;

public class WaitingRoomManager : SingletonPhotonMonoBehaviour<WaitingRoomManager> {

	/// <summary>
	/// 操作キャラクターのプレファブを格納している配列
	/// </summary>
	[SerializeField] GameObject[] character;

	/// <summary>
	/// 表示するルームのゲームオブジェクトを格納する変数
	/// </summary>
	[SerializeField] GameObject roomMenu;
	[SerializeField] Text[] roomText;
	[SerializeField] GameObject[] roomCharacter;
	bool isMenu = false;

	/// <summary>
	/// 各ルームのMenuを表示するGameObjectとText
	/// </summary>
	[SerializeField,HeaderAttribute("Room_2")] GameObject roomMenu_2;
	[SerializeField] Text[] roomText_2;

	/// <summary>
	/// ルーム名を表示するラベル
	/// </summary>
	[SerializeField] Text roomName;

	/// <summary>
	/// ゲームスタートボタン
	/// </summary>
	[SerializeField] GameObject gameStartButton;
	[SerializeField] Text gameStartButtonText;

	/// <summary>
	/// Connecting...を表示するラベル
	/// </summary>
	[SerializeField] GameObject progressLabel;

	/// <summary>
	/// エラーログを表示するウィンドウ
	/// </summary>
	[SerializeField] GameObject errorDialog;
	[SerializeField] Text errorText;

	/// <summary>
	/// PhotonNetwork関連の変数
	/// </summary>
	PhotonPlayer[] playerList;
	int playerCount;
	int maxPlayers;

	protected override void Awake () {
		base.Awake();
		PhotonNetwork.isMessageQueueRunning = true;
		PhotonNetwork.automaticallySyncScene = true;
	}

	// Use this for initialization
	void Start () {
		InitializeUI();
		OpenRoomMenu();
	}

	void Update() {
		if (isMenu) UpdateRoomMenu();
	}


	//================================
	// UI関連
	//================================
	void InitializeUI() {
		progressLabel.SetActive(true);
		if (roomMenu != null) roomMenu.SetActive(false);
		gameStartButton.SetActive(false);
		roomName.text = "Room "+ PhotonNetwork.room.Name;
		maxPlayers = PhotonNetwork.room.MaxPlayers;
		isMenu = false;
	}

	void OpenRoomMenu() {
		int roomNum = int.Parse(PhotonNetwork.room.Name);
		switch (roomNum) {
			case 2:
				roomMenu = roomMenu_2;
				roomText = new Text[2];
				roomCharacter = new GameObject[2];
				roomCharacter[0] = Instantiate(character[0],new Vector3(-0.5f,0f,-2.0f), Quaternion.identity);
				roomCharacter[1] = Instantiate(character[0],new Vector3(-0.5f,-1.1f,-2.0f), Quaternion.identity);
				for (int i=0; i<2; i++) {
					roomText[i] = roomText_2[i];
					roomCharacter[i].transform.LookAt(Camera.main.transform);
				}
				break;
			case 4:
				break;
			case 6:
				break;
			case 8:
				break;
		}
		roomMenu.SetActive(true);
		iTween.ScaleFrom(roomMenu, iTween.Hash(
				"x", 0,
				"y", 0,
				"z", 0,
				"oncomplete", "UpdateRoomMenu",
				"oncompletetarget", this.gameObject
			));
		gameStartButton.SetActive(true);
	}


	public void UpdateRoomMenu() {

		isMenu = true;

		if (playerList == PhotonNetwork.playerList) return;
		playerList = PhotonNetwork.playerList;
		playerCount = PhotonNetwork.room.PlayerCount;
		gameStartButtonText.text = playerCount + " / " + maxPlayers;

		for (int i = 0; i < maxPlayers; i++ ) {

			if (i < playerCount) {
				roomText[i].text = "PlayerName:\n" + playerList[i].NickName +"\n";
				if (playerList[i].IsMasterClient) roomText[i].text += "ホスト";
				roomCharacter[i].SetActive(true);
			} else {
				roomText[i].text = "";
				roomCharacter[i].SetActive(false);
			}

		}

		// GameStart条件を満たした時だけGameStartを表示する
		if (PhotonNetwork.player.IsMasterClient && PhotonNetwork.room.MaxPlayers == PhotonNetwork.room.PlayerCount) {
			gameStartButtonText.text = "GameStart!";
		}

	}

	public void GameStart() {
		var room = PhotonNetwork.room;
		if ( PhotonNetwork.player.IsMasterClient && room.MaxPlayers == room.PlayerCount ) {
			PhotonNetwork.room.IsOpen = false;	//誰も入れないようにルームを閉じます
			PhotonNetwork.isMessageQueueRunning = false;
			PhotonNetwork.LoadLevel("NormalGame_" + room.Name);
		} else {
			DebugLogger.Log("ルームの人数が足りません");
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

}
