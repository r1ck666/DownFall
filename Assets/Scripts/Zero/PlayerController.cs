﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class PlayerController : MonoBehaviour {

    //ステート
    DirectionState directionState;
    AnimState animState;

    [SerializeField]
    private float needTapDistance = 2f;
    [SerializeField]
    private float moveSpeed = 2f;

    [SerializeField]
    private GameObject maker;

    //タップポジションの保管
    private Vector3 touchBeginePos;
    private Vector3 touchDistancePos;

    //コンポーネント
    private Animator anim;
    private Rigidbody rigidbody;

    //方向転換モード
    private bool isDirectionMode;
    //アタック中かどうか
    private bool isAttack;
    public bool IsAttack
    {
        get{
            return isAttack;
        }
        set{
            isAttack = value;
        }
    }
    private bool isPushAttackButton;
    public bool IsPushAttackButton
    {
        get{
            return isPushAttackButton;
        }
        set{
            isPushAttackButton = true;
        }
    }

    //自分自身かどうか
    private bool isMine;
    public bool IsMine
    {
        get
        {
            return isMine;
        }
        set
        {
            isMine = value;
        }
    }

    private bool isPlay;
    public bool IsPlay
    {
        get
        {
            return isPlay;
        }
        set
        {
            isPlay = value;
        }
    }

    // AudioClip用の一時変数
    int s = 0;

    //private Text t;

	// Use this for initialization
	void Start () {
        isPlay = false;
        //t = GameObject.Find("TestCanvas/test").GetComponent<Text>();
        if (isMine)
        {
            maker = GameObject.FindGameObjectWithTag("Maker");
            Debug.Log("isattack" + isAttack);
            rigidbody = GetComponent<Rigidbody>();
            isDirectionMode = false;
            isAttack = false;
            animState = AnimState.NONE;
            directionState = GetDirection(transform.eulerAngles.y);
        }
        anim = GetComponent<Animator>();
	}

    void Update()
    {
    }



	// Update is called once per frame
	void FixedUpdate () {

        if (isMine && isPlay)
        {

            TouchInfo info = AppUtil.GetTouch();

            //t.text = info.ToString();

            switch (info)
            {
                case TouchInfo.Began:
                    touchBeginePos = AppUtil.GetTouchPosition();
                    break;

                case TouchInfo.Moved:
                    touchDistancePos = AppUtil.GetTouchPosition() - touchBeginePos;
                    if (touchDistancePos.magnitude > needTapDistance && !isAttack)
                    {
                        SetDirection();
                        if (!isDirectionMode)
                            Move();
                    }
                    break;
                case TouchInfo.Stationary:
                    if (touchDistancePos.magnitude > needTapDistance && !isAttack)
                    {
                        SetDirection();
                        if (!isDirectionMode)
                            Move();
                    }
                    break;
                case TouchInfo.Ended:
                    ResetPosition();
                    break;
                case TouchInfo.Canceled:
                    ResetPosition();
                    break;
            }
            Maker();

            //以下はスマホのみ、それ以外（エディターなど使用）はコメントアウトしてください
            if (Application.platform == RuntimePlatform.IPhonePlayer ||
                Application.platform == RuntimePlatform.Android) {
                    if (Input.touchCount < 1)
                        ResetPosition();
            }
        }
	}

    void ResetPosition()
    {
        anim.SetBool("Run", false);
        //anim.SetBool("attack", false);
        touchBeginePos.Set(0,0,0);
        touchDistancePos.Set(0,0,0);
        isPushAttackButton = false;
    }

    /// <summary>
    /// マーカー目の前に出す
    /// </summary>
    void Maker()
    {
        uint x = (uint)Mathf.RoundToInt(transform.position.x);
        uint z = (uint)Mathf.RoundToInt(transform.position.z);
        uint y = (uint)Mathf.RoundToInt(transform.position.y);

        switch (directionState)
        {
            case DirectionState.RIGHT:
                x++;
                break;
            case DirectionState.LEFT:
                x--;
                break;
            case DirectionState.FRONT:
                z++;
                break;
            case DirectionState.BACK:
                z--;
                break;
        }

        maker.transform.position = new Vector3(x,y-0.4f,z);

    }
    /*
    bool CheckGrounded()
    {

        RaycastHit hitCollider;
        Vector3 playerPos = transform.position;
        if (Physics.Linecast(playerPos , (playerPos - transform.up * 1.5f), out hitCollider))
        {
            return true;
        }

        return false;
    }
    */


    /// <summary>
    /// 前に移動
    /// </summary>
    void Move()
    {
        /*
        Vector3 velocity = Vector3.zero;
        velocity = new Vector3(touchDistancePos.x,0,touchDistancePos.y);
        velocity *= moveSpeed;
        */
        anim.SetBool("Run",true);
        //transform.position += transform.forward * Time.deltaTime * moveSpeed;
        rigidbody.MovePosition(transform.position + transform.forward * Time.deltaTime * moveSpeed);
    }

    /// <summary>
    /// 方向を決める
    /// </summary>
    void SetDirection()
    {
        Vector3 distance = touchDistancePos;
        float rad = Mathf.Atan2(distance.y, distance.x);
        float nowAngle = rad * 180 / Mathf.PI - 90;

        transform.eulerAngles = new Vector3(0,-nowAngle,0);
        directionState = GetDirection(transform.eulerAngles.y);
        //Debug.Log(transform.eulerAngles);
    }


    /// <summary>
    ///　アクション時にゲームマネージャーに送る情報
    ///　前方向のブロックを探索して壊す、または直す
    /// </summary>
    public void SendFroundBlock()
    {
        uint x = (uint)Mathf.RoundToInt(transform.position.x);
        uint z = (uint)Mathf.RoundToInt(transform.position.z);

        switch (directionState)
        {
            case DirectionState.RIGHT:
                x++;
                break;
            case DirectionState.LEFT:
                x--;
                break;
            case DirectionState.FRONT:
                z++;
                break;
            case DirectionState.BACK:
                z--;
                break;
        }

        NormalGameManager.Instance.ActionJudge((int)x,(int)z);

    }

    public void ActionAnimation(AnimState aState)
    {
        animState = aState;
    }


    /// <summary>
    /// 現在の回転から方向ステートを取る関数
    /// </summary>
    /// <param name="angleY">Yの回転</param>
    /// <returns>方向のステート</returns>
    DirectionState GetDirection(float angleY)
    {
        if (45f <= angleY && angleY < 135f)
            return DirectionState.RIGHT;
        else if (135f <= angleY && angleY < 225f)
            return DirectionState.BACK;
        else if (225f <= angleY && angleY < 315f)
            return DirectionState.LEFT;
        else
            return DirectionState.FRONT;
    }

    /// <summary>
    /// ボタンが押されたか離されたか
    /// </summary>
    public void OnDirectionButton(bool isPush)
    {
        isDirectionMode = isPush;
    }

    //----------以下イベント関数（ボタン(Manager経由も含む)、アニメーションなど）----------


    /// <summary>
    /// アクションモーション入る前に呼び出す関数
    /// </summary>
    public void OnActionMotionEnter()
    {
        isAttack = true;
        anim.SetBool("attack",isAttack);
        iTween.RotateTo(gameObject, iTween.Hash("x", 20, "islocal", true));
        //Debug.Log("攻撃開始");
        // SE用
        SoundManager.Instance.SoundSe(SoundManager.Instance.SE[s]);
        s++;
        if (s>2) s = 0;
    }

    /// <summary>
    /// アクションの最中に呼び出される
    /// </summary>
    public void OnActionMotion()
    {
        if(isMine)
            SendFroundBlock();
        iTween.RotateTo(gameObject, iTween.Hash("x", 0, "islocal", true, "time", 0.5f));
    }

    /// <summary>
    /// アクションが終わるときに呼び出される
    /// アタックボタンが押されていたらそのままアタックへ
    /// </summary>
    public void OnActionMotionExit()
    {
        //Debug.Log("ABunton" + isPushAttackButton);
        isAttack = false;
        if (isPushAttackButton){
            OnActionMotionEnter();
        }
        else
        {
            anim.SetBool("attack", false);
        }

        //if(isPushAttackButton)
        //    anim.SetTrigger("Attack");
    }


    /// <summary>
    /// UIManagerからアクションボタンが押された、離されたときに呼び出される
    /// </summary>
    public void OnActionButton(bool isPush)
    {
        if (isPlay)
        {
            //Debug.Log("isPush : " + isPush + " isAttack : " + isAttack);
            isPushAttackButton = isPush;
            if (!isAttack && isPush)
            {
                OnActionMotionEnter();
            }
        }
    }


    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "DeadArea")
        {
            isPlay = false;
            SoundManager.Instance.SoundSe(SoundManager.Instance.SE[3]);
            NormalGameManager.Instance.PlayerDead(NormalGameManager.Instance.PlayerNum);
            gameObject.SetActive(false);
        }
    }


}


public enum DirectionState
{
    RIGHT = -1,
    LEFT = 1,
    FRONT = 2,
    BACK = 3,
    NONE = 4
}

public enum AnimState
{
    BREAK,
    REPAIR,
    NONE
}
