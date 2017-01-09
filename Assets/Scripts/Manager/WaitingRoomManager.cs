using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class WaitingRoomManager : SingletonPhotonMonoBehaviour<WaitingRoomManager> {

	[SerializeField] GameObject player1;
	[SerializeField] GameObject player2;

	protected override void Awake () {
		base.Awake();
		PhotonNetwork.isMessageQueueRunning = true;
	}

	// Use this for initialization
	void Start () {

	}

	// Update is called once per frame
	void Update () {

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

	public void GameStart()
	{

	}
}
