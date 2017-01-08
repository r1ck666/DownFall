using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {

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

    private Animator anim;

    //方向転換
    private bool isDirectionMode;

    private Rigidbody rigidbody;

    private bool isAttack;

	// Use this for initialization
	void Start () {
        anim = GetComponent<Animator>();
        rigidbody = GetComponent<Rigidbody>();
        isDirectionMode = false;
        isAttack = false;
        animState = AnimState.NONE;
        directionState = GetDirection(transform.eulerAngles.y);
	}

	// Update is called once per frame
	void FixedUpdate () {

        TouchInfo info = AppUtil.GetTouch();

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
            case TouchInfo.Ended:
                anim.SetBool("Run", false);
                break;
        }
        Maker();
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
    /// ボタンが押されたか離されたか
    /// </summary>
    public void OnDirectionButton(bool isPush)
    {
        isDirectionMode = isPush;
    }

    /// <summary>
    ///　アクション時にゲームマネージャーに送る情報
    ///　前方向のブロックを探索して壊す、または直す
    /// </summary>
    public void SendFroundBlock()
    {
        int x = Mathf.RoundToInt(transform.position.x);
        int z = Mathf.RoundToInt(transform.position.y);
        
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

        NormalGameManager.Instance.ActionJudge(x,z);
        
    }

    public void ActionAnimation(AnimState aState)
    {
        animState = aState;
    }

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

    public void OnActionMotionEnter()
    {
        isAttack = true;
        iTween.RotateTo(gameObject, iTween.Hash("x", 20, "islocal", true));
    }

    public void OnActionMotionExit()
    {
        isAttack = false;
        SendFroundBlock();
        iTween.RotateTo(gameObject, iTween.Hash("x", 0, "islocal", true, "time", 0.5f));
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