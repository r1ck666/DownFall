﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TitleManager : SingletonPhotonMonoBehaviour<TitleManager> {

	/// <summary>
    /// This client's version number. Users are separated from each other by gameversion (which allows you to make breaking changes).
    /// </summary>
    string _gameVersion = "1";

	/// <summary>
	/// The PUN loglevel.
	/// </summary>
	public PhotonLogLevel Loglevel = PhotonLogLevel.Informational;

	/// <summary>
	/// The maximum number of players per room. When a room is full, it can't be joined by new players, and so new room will be created.
	/// </summary>
	[Tooltip("ルームに入れる最大人数")]
	public byte MaxPlayersPerRoom = 4;



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

    /// <summary>
    /// Start the connection process.
    /// - If already connected, we attempt joining a random room
    /// - if not yet connected, Connect this application instance to Photon Cloud Network
    /// </summary>
    public void Connect()
    {

        // we check if we are connected or not, we join if we are , else we initiate the connection to the server.
        if (PhotonNetwork.connected)
        {
            // #Critical we need at this point to attempt joining a Random Room. If it fails, we'll get notified in OnPhotonRandomJoinFailed() and we'll create one.
            PhotonNetwork.JoinRandomRoom();
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
    	DebugLogger.Log("TitleManager: OnDisconnectedFromPhoton() was called by PUN");
	}

	public override void OnPhotonRandomJoinFailed (object[] codeAndMsg)
	{
    	DebugLogger.Log("TitleManger:OnPhotonRandomJoinFailed() was called by PUN. No random room available, so we create one.\nCalling: PhotonNetwork.CreateRoom(null, new RoomOptions() {maxPlayers = 4}, null);");

    	// #Critical: we failed to join a random room, maybe none exists or they are all full. No worries, we create a new room.
    	PhotonNetwork.CreateRoom(null, new RoomOptions() { maxPlayers = MaxPlayersPerRoom }, null);
	}

	public override void OnJoinedRoom()
	{
    	DebugLogger.Log("TitleManger: OnJoinedRoom() called by PUN. Now this client is in a room.");
	}
}
