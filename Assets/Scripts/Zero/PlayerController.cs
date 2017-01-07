using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {

    [SerializeField]
    private float needTapDistance = 2f;
    [SerializeField]
    private float moveSpeed = 2f;

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
    }

    /// <summary>
    /// ボタンが押されたか離されたか
    /// </summary>
    public void OnDirectionButton(bool isPush)
    {
        isDirectionMode = isPush;
    }
}
