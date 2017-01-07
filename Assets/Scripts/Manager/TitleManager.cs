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
	/// The maximum number of players per room. When a room is full, it can't be joined by new players, and so new room will be created.
	/// </summary>
	[Tooltip("ルームに入れる最大人数(待機用のルーム)")]
	public byte MaxPlayersPerRoom = 8;

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
	[SerializeField] Text ErrorLabrl;

	[SerializeField] GameObject errorButton;

	protected override void Awake()
	{
		base.Awake();
		// Photon

		// #NotImportant
        // Force Full LogLevel
        PhotonNetwork.logLevel = Loglevel;

		// #Critical
        // we don't join the lobby. There is no need to join a lobby to get the list of rooms.
        PhotonNetwork.autoJoinLobby = false;

		// #Critical
        // this makes sure we can use PhotonNetwork.LoadLevel() on the master client and all clients in the same room sync their level automatically
        PhotonNetwork.automaticallySyncScene = true;

	}

	void Start() {
		progressLabel.SetActive(false);
		gameVersionLabel.text = "GameVersion: " + _gameVersion;
	}

    /// <summary>
    /// Start the connection process.
    /// - If already connected, we attempt joining a random room
    /// - if not yet connected, Connect this application instance to Photon Cloud Network
    /// </summary>
    public void Connect()
    {
		progressLabel.SetActive(true);
        // we check if we are connected or not, we join if we are , else we initiate the connection to the server.
        if (PhotonNetwork.connected)
        {
            if (!PhotonNetwork.JoinRoom("Waiting_Room")) {
				PhotonNetwork.CreateRoom("Waiting_Room", new RoomOptions() { maxPlayers = MaxPlayersPerRoom }, null);
			}
        }else{
            // #Critical, we must first and foremost connect to Photon Online Server.
            PhotonNetwork.ConnectUsingSettings(_gameVersion);
        }
    }

	public override void OnConnectedToMaster()
	{
    	DebugLogger.Log("TitleManager: OnConnectedToMaster() was called by PUN");
		// #Critical: The first we try to do is to join a potential existing room. If there is, good, else, we'll be called back with OnPhotonRandomJoinFailed()
		PhotonNetwork.JoinRandomRoom();

	}

	public override void OnDisconnectedFromPhoton()
	{
		progressLabel.SetActive(false);
    	Debug.LogWarning("TitleManager: OnDisconnectedFromPhoton() was called by PUN");
	}

	public  void OnPhotonCreateGameFailed()
	{

	}

	public override void OnJoinedRoom()
	{
    	DebugLogger.Log("TitleManger: OnJoinedRoom() called by PUN. Now this client is in a room.");
		if (PhotonNetwork.room.playerCount == 1)
    	{
        	Debug.Log("We load the 'Room_for_2' ");

        	// #Critical
        	// Load the Room Level.
        	PhotonNetwork.LoadLevel("Room_for_2");
    	}
	}
}
