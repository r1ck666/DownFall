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
	// NormalGameManager
	// ===============================
	[SerializeField, HeaderAttribute("NormalGameManager")] GameObject normalUI;
	[SerializeField] int normalX = 5;
	[SerializeField] int normalZ = 5;


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
						+ "PlayerName: " + player.name + "\n"
						+ "UserID: " + player.userId + "\n"
						+ "isMasterClient: " + player.isMasterClient.ToString() + "\n";
	}

	void ShowNowRoomProperty()
	{
		var room = PhotonNetwork.room;
		if (room != null) {
			debugText.text = "現在いるルーム名: " + room.name + "\n"
							+ "現在いるルームの人数: " + room.playerCount.ToString() + "\n"
							+ "現在いるルームの最大人数 :" + room.maxPlayers.ToString() + "\n"
							+ "現在いるルームのMaster: " + PhotonNetwork.masterClient.name + "\n";
			debugText.text += "現在ルームにいるPlayer(ID: , Name: ): " + "\n";
			var playerList = PhotonNetwork.playerList;
			foreach (var player in playerList){
				debugText.text += "ID: " + player.ID.ToString() + "Name: " + player.name + "\n";
			}
			debugText.text += "\n";
		} else {
			debugText.text = "あなたはどのルームにも所属していません";
		}
	}

	// ===============================
	// NormalGame Method
	// ===============================
	public void SetActiveNormalUI() {
		if (normalUI.activeSelf){
			normalUI.SetActive (false);
		} else {
			normalUI.SetActive (true);
		}
	}

	public void ActionButton() {
		NormalGameManager.Instance.ActionJudge (normalX, normalZ);
	}

}
