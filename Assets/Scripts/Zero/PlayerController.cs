using System.Collections;
using System.Collections.Generic;
using UnityEngine;
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
    private bool isPushAttackButton;

	// Use this for initialization
	void Start () {
        Debug.Log("isattack" + isAttack);
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

    /*----------以下イベント関数（ボタン(Manager経由も含む)、アニメーションなど）----------*/

    /// <summary>
    /// アクションモーション入り時に呼び出す関数
    /// </summary>
    public void OnActionMotionEnter()
    {
        isAttack = true;
        iTween.RotateTo(gameObject, iTween.Hash("x", 20, "islocal", true));
    }

    /// <summary>
    /// アクションの最中に呼び出される
    /// </summary>
    public void OnActionMotion()
    {
        SendFroundBlock();
        iTween.RotateTo(gameObject, iTween.Hash("x", 0, "islocal", true, "time", 0.5f));
    }

    /// <summary>
    /// アクションが終わるときに呼び出される
    /// アタックボタンが押されていたらそのままアタックへ
    /// </summary>
    public void OnActionMotionExit()
    {
        Debug.Log("ABunton" + isPushAttackButton);
        isAttack = false;
        if(isPushAttackButton)
            anim.SetTrigger("Attack");
    }

    /// <summary>
    /// ボタンが押されたか離されたか
    /// </summary>
    public void OnDirectionButton(bool isPush)
    {
        isDirectionMode = isPush;
    }

    /// <summary>
    /// UIManagerからアクションボタンが押された、離されたときに呼び出される
    /// </summary>
    public void OnActionButton(bool isPush)
    {
        isPushAttackButton = isPush;
        if (!isAttack && isPush)
        {
            OnActionMotionEnter();
            anim.SetTrigger("Attack");
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