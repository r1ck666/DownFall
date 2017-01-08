using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerNetworkController : Photon.MonoBehaviour{

    //他のプレイヤー用
    private Vector3 correctPlayerPos = Vector3.zero;
    private Quaternion correctPlayerRot = Quaternion.identity;

    private PlayerController playerController;

    private bool isMine;

	void Awake () {
        isMine = photonView.isMine;
        playerController = GetComponent<PlayerController>();
        playerController.enabled = isMine;
        if (isMine)
            gameObject.tag = "Player";
        else
            gameObject.tag = "Enemy";
        //デバック用
        //gameObject.tag = "Player";
        //isMine = true;
        //playerController.enabled = true;
	}

	// Update is called once per frame
	void Update () {
        //自分のキャラクター以外の時はLerpを使って滑らかに位置と角度を変更
        if (!isMine)
        {
            transform.position = Vector3.Lerp(transform.position, this.correctPlayerPos, Time.deltaTime * 5);
            transform.rotation = Quaternion.Lerp(transform.rotation, this.correctPlayerRot, Time.deltaTime * 5);
        }
	}

    void OnPhotonSerializeView(PhotonStream stream, PhotonMessageInfo info)
    {
        //このプレイヤーのデータを他のプレイヤーに送信
        if (stream.isWriting)
        {
            stream.SendNext(transform.position);
            stream.SendNext(transform.rotation);
        }
        //ネットワークプレイヤーのデータを受信
        else
        {
            correctPlayerPos = (Vector3)stream.ReceiveNext();
            correctPlayerRot = (Quaternion)stream.ReceiveNext();
        }
    }


}
