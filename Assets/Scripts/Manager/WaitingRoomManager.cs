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
	[SerializeField] GameObject nameField;
	[SerializeField] InputField inputNameField;

	int playerCount;

	protected override void Awake () {
		base.Awake();
		PhotonNetwork.isMessageQueueRunning = true;
	}

	// Use this for initialization
	void Start () {
		InitializeUI();
		ActiveNameField();

	}

	//================================
	// UI関連
	//================================
	void InitializeUI() {
		foreach (GameObject playerObject in playerObjects){
			playerObject.SetActive(false);
		}
		gameStartButton.SetActive(false);
		nameField.SetActive(false);
		playerUI.SetActive(false);
		roomName.text = "Room "+ PhotonNetwork.room.name;
	}

	public void SetUserName() {
		PhotonNetwork.player.name = inputNameField.text;
		nameField.SetActive(false);
		UpdatePlayerUI();
	}

	void ActiveNameField() {
		nameField.SetActive(true);
		iTween.ScaleFrom(nameField, iTween.Hash("x", 0, "y", 0, "z", 0));
	}

	public void UpdatePlayerUI() {

		var playerList = PhotonNetwork.playerList;
		playerCount = PhotonNetwork.room.playerCount;

		playerUI.SetActive(true);
		iTween.ScaleFrom(playerUI, iTween.Hash(
				"x", 0,
				"y", 0,
				"z", 0,
				"oncomplete", "ActiveObject",
				"oncompletetarget", this.gameObject
			));


		for (int i = 0; i < playerCount; i++ ) {
			player_Text[i].text = "PlayerName:\n" + playerList[i].name;
		}
	}

	public void ActiveObject() {
		for (int i = 0; i < playerCount; i++ ) {
			playerObjects[i].SetActive(true);
		}
	}

	public void GameStart() {
		var room = PhotonNetwork.room;
		if ( room.maxPlayers == room.playerCount ) {
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
