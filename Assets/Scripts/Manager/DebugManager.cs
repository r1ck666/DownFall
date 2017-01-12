using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DebugManager : SingletonPhotonMonoBehaviour<DebugManager> {

	// ===============================
	// Public
	// ===============================
	[SerializeField, HeaderAttribute("Public")] GameObject debugUI;
	[SerializeField] GameObject publicUI;
	[SerializeField] Text debugText;
	[SerializeField] Dropdown debugDropdown;
	// ===============================
	// TitleManager
	// ===============================
	[SerializeField, HeaderAttribute("TitleManager")] GameObject titleUI;
	// ===============================
	// WaitingRoomManager
	// ===============================
	[SerializeField, HeaderAttribute("WaitingRoomManager")] GameObject waitingUI;
	// ===============================
	// NormalGameManager
	// ===============================
	[SerializeField, HeaderAttribute("NormalGameManager")] GameObject normalUI;
	[SerializeField] InputField normalInputFieldX;
	[SerializeField] InputField normalInputFieldZ;
	[SerializeField] int normalX;
	[SerializeField] int normalZ;


	protected override void Awake () {
		base.Awake();
		DontDestroyOnLoad(transform.gameObject);
	}

	// Use this for initialization
	void Start () {

	}

	// Update is called once per frame
	void Update () {

	}

	// ===============================
	// Public Method
	// ===============================

	//DebugUIのアクティブ化
	public void SetActiveDebugUI() {
		if (debugUI.activeSelf){
			debugUI.SetActive (false);
		} else {
			debugUI.SetActive (true);
		}
	}

	void InitializeUI () {
		publicUI.SetActive(false);
		waitingUI.SetActive(false);
		normalUI.SetActive(false);
	}

	public void SetActivePublicUI () {
		InitializeUI();
		publicUI.SetActive(true);
	}

	public void SelectDropDown()
	{
		switch (debugDropdown.value){
		case 0:
			break;
		case 1:
			ShowPlayerProperty();
			break;
		case 2:
			ShowNowRoomProperty();
			break;
		default:
			break;
		}
	}

	void ShowPlayerProperty()
	{
		var player = PhotonNetwork.player;
		debugText.text = "PlayerID: " + player.ID.ToString() + "\n"
						+ "PlayerName: " + player.NickName + "\n"
						+ "UserID: " + player.UserId + "\n"
						+ "isMasterClient: " + player.IsMasterClient.ToString() + "\n";
	}

	void ShowNowRoomProperty()
	{
		var room = PhotonNetwork.room;
		if (room != null) {
			debugText.text = "現在いるルーム名: " + room.Name + "\n"
							+ "現在いるルームの人数: " + room.PlayerCount.ToString() + "\n"
							+ "現在いるルームの最大人数 :" + room.MaxPlayers.ToString() + "\n"
							+ "現在いるルームのMaster: " + PhotonNetwork.masterClient.NickName + "\n";
			debugText.text += "現在ルームにいるPlayer(ID: , Name: ): " + "\n";
			var playerList = PhotonNetwork.playerList;
			foreach (var player in playerList){
				debugText.text += "ID: " + player.ID.ToString() + "Name: " + player.NickName + "\n";
			}
			debugText.text += "\n";
		} else {
			debugText.text = "あなたはどのルームにも所属していません";
		}
	}

	// ===============================
	// WaitingRoom Method
	// ===============================
	public void SetActiveWaitingUI () {
		InitializeUI();
		waitingUI.SetActive(true);

	}

	public void GameStart() {
		var room = PhotonNetwork.room;
		PhotonNetwork.isMessageQueueRunning = false;
		PhotonNetwork.LoadLevel("NormalGame_" + room.Name);
	}

	// ===============================
	// NormalGame Method
	// ===============================
	public void SetActiveNormalUI() {
		InitializeUI();
		normalUI.SetActive (true);

	}

	public void ActionButton() {
		normalX =　int.Parse(normalInputFieldX.text);
		normalZ = int.Parse(normalInputFieldZ.text);
		NormalGameManager.Instance.ActionJudge (normalX, normalZ);
	}


}
