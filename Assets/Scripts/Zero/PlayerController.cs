using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {

    enum DirectionState
    {
        RIGHT = 0,
        LEFT = 1,
        FRONT = 2,
        BACK = 3,
    }

    DirectionState directionState;

    [SerializeField]
    private float needTapDistance = 2f;
    [SerializeField]
    private float moveSpeed = 2f;

    //タップポジションの保管
    private Vector3 touchBeginePos;
    private Vector3 touchNowPos;

    private Animator anim;

    //方向転換
    private bool isDirectionMode;

	// Use this for initialization
	void Start () {
        anim = GetComponent<Animator>();
        isDirectionMode = false;
	}
	
	// Update is called once per frame
	void Update () {

        TouchInfo info = AppUtil.GetTouch();

        if (info == TouchInfo.Began)
        {
            touchBeginePos = AppUtil.GetTouchPosition();
        }
        else if (info == TouchInfo.Moved)
        {
            touchNowPos = AppUtil.GetTouchPosition() - touchBeginePos;
            if (touchNowPos.magnitude > needTapDistance)
            {
                Debug.Log(isDirectionMode);
                SetDirection();
                if(!isDirectionMode)
                    Move();
            }
        }
        else if (info == TouchInfo.Ended)
        {
            anim.SetBool("Run",false);
        }
	}
    
    /// <summary>
    /// 前に移動
    /// </summary>
    void Move()
    {
        anim.SetBool("Run",true);
        transform.position += transform.forward * Time.deltaTime;
    }

    /// <summary>
    /// 方向を決める
    /// </summary>
    void SetDirection()
    {
        Vector3 distance = touchNowPos;
        float rad = Mathf.Atan2(distance.y, distance.x);
        float nowAngle = rad * 180 / Mathf.PI - 90;

        transform.eulerAngles = new Vector3(0,-nowAngle,0);
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
    ///　アクションボタンが押されたとき
    ///　前方向のブロックを探索して壊す、または直す
    /// </summary>
    public void OnActionButton()
    {
        return;
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

}
