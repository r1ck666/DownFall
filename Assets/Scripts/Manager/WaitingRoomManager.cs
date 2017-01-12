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

	/// <summary>
	/// ゲームスタートボタン
	/// </summary>
	[SerializeField] GameObject gameStartButton;
	[SerializeField] Text gameStartButtonText;

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
		OpenPlayerUI();
	}

	void Update() {
		UpdatePlayerUI();
	}


	//================================
	// UI関連
	//================================
	void InitializeUI() {
		foreach (GameObject playerObject in playerObjects){
			playerObject.SetActive(false);
		}
		if (playerUI != null) playerUI.SetActive(false);
		gameStartButton.SetActive(false);
		roomName.text = "Room "+ PhotonNetwork.room.Name;
		maxPlayers = PhotonNetwork.room.MaxPlayers;
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

		if (playerList == PhotonNetwork.playerList) return;
		playerList = PhotonNetwork.playerList;
		playerCount = PhotonNetwork.room.playerCount;
		gameStartButtonText.text = playerCount + " / " + maxPlayers;

		for (int i = 0; i < playerCount; i++ ) {
			player_Text[i].text = "PlayerName:\n" + playerList[i].NickName;
		}

		// GameStart条件を満たした時だけGameStartを表示する
		if (PhotonNetwork.player.IsMasterClient && PhotonNetwork.room.MaxPlayers == PhotonNetwork.room.playerCount) {
			gameStartButtonText.text = "GameStart!";
		}

	}

	public void ActiveObject() {
		for (int i = 0; i < playerCount; i++ ) {
			playerObjects[i].SetActive(true);
		}
	}

	public void GameStart() {
		var room = PhotonNetwork.room;
		if ( PhotonNetwork.player.isMasterClient && room.maxPlayers == room.playerCount ) {
			PhotonNetwork.room.open = false;	//誰も入れないようにルームを閉じます
			PhotonNetwork.isMessageQueueRunning = false;
			PhotonNetwork.LoadLevel("NormalGame_" + room.name);
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
