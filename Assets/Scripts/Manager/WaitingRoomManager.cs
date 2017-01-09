using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using System.Linq;

public class WaitingRoomManager : SingletonPhotonMonoBehaviour<WaitingRoomManager> {

	[SerializeField] GameObject playerUI;
	[SerializeField] GameObject[] playerObjects;
	[SerializeField] Text[] player_Text;

	[SerializeField] Text roomName;

	[SerializeField] GameObject gameStartButton;
	[SerializeField] Text gameStartButtonText;
	[SerializeField] GameObject nameField;
	[SerializeField] InputField inputNameField;

	int playerCount;
	int maxPlayers;
	bool isOpenUI = false;

	protected override void Awake () {
		base.Awake();
		PhotonNetwork.isMessageQueueRunning = true;
		PhotonNetwork.automaticallySyncScene = true;
	}

	// Use this for initialization
	void Start () {
		InitializeUI();
		ActiveNameField();

	}

	void Update() {
		if (isOpenUI) {
			UpdatePlayerUI();
			ActiveObject();
		}
	}


	//================================
	// UI関連
	//================================
	void InitializeUI() {
		foreach (GameObject playerObject in playerObjects){
			playerObject.SetActive(false);
		}
		isOpenUI = false;
		gameStartButton.SetActive(false);
		nameField.SetActive(false);
		playerUI.SetActive(false);
		roomName.text = "Room "+ PhotonNetwork.room.name;
		maxPlayers = PhotonNetwork.room.maxPlayers;
	}

	public void SetUserName() {
		PhotonNetwork.player.name = inputNameField.text;
		nameField.SetActive(false);
		OpenPlayerUI();
	}

	void ActiveNameField() {
		nameField.SetActive(true);
		iTween.ScaleFrom(nameField, iTween.Hash("x", 0, "y", 0, "z", 0));
	}

	void OpenPlayerUI() {
		playerUI.SetActive(true);
		iTween.ScaleFrom(playerUI, iTween.Hash(
				"x", 0,
				"y", 0,
				"z", 0,
				"oncomplete", "ActiveObject",
				"oncompletetarget", this.gameObject
			));
		gameStartButton.SetActive(true);
	}

	public void UpdatePlayerUI() {

		var playerList = PhotonNetwork.playerList;
		playerCount = PhotonNetwork.room.playerCount;
		gameStartButtonText.text = playerCount + " / " + maxPlayers;

		for (int i = 0; i < playerCount; i++ ) {
			player_Text[i].text = "PlayerName:\n" + playerList[i].name;
		}

		if (PhotonNetwork.player.isMasterClient && PhotonNetwork.room.maxPlayers == PhotonNetwork.room.playerCount) {
			gameStartButtonText.text = "GameStart!";
		}

	}

	public void ActiveObject() {
		isOpenUI = true;
		for (int i = 0; i < playerCount; i++ ) {
			playerObjects[i].SetActive(true);
		}
	}

	public void GameStart() {
		var room = PhotonNetwork.room;
		if ( PhotonNetwork.player.isMasterClient && room.maxPlayers == room.playerCount ) {

			PhotonNetwork.isMessageQueueRunning = false;
			PhotonNetwork.LoadLevel("NormalGame_" + room.name);
		} else {
			DebugLogger.Log("ルームの人数が足りません");
		}
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
