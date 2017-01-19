using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : SingletonMonoBehaviour<UIManager> {

    private PlayerController playerController;
    //private PlayerAnimationControll playerAnimationController;
    [SerializeField] private Text limitTimeText;
    [SerializeField] Text timeCount;
    [SerializeField] Text winnerName;
    [SerializeField] GameObject gameEndButton;

    protected override void Awake()
    {
        base.Awake();
    }

	// Use this for initialization
	void Start () {
        //SetPlayer();
        InitializeUI();

	}

	// Update is called once per frame
	void Update () {

	}

    void InitializeUI () {
        gameEndButton.SetActive(false);
        timeCount.transform.parent.gameObject.SetActive(false);
        winnerName.transform.parent.gameObject.SetActive(false);
    }

    public void OnDirectionButton(bool isPush)
    {
        playerController.OnDirectionButton(isPush);
    }

    public void OnActionButton(bool isPush)
    {
        playerController.OnActionButton(isPush);
    }

    public void SetLimitTime(float time)
    {
        limitTimeText.text = ((int)time).ToString();
    }

    public void SetPlayer(){
        var playerObj = GameObject.FindGameObjectWithTag("Player");
        playerController = playerObj.GetComponent<PlayerController>();
        //playerAnimationController = playerObj.GetComponent<PlayerAnimationControll>();
    }

    public void TimeCount (string count) {
        timeCount.transform.parent.gameObject.SetActive(true);
        timeCount.text = count;
        iTween.ScaleFrom(timeCount.gameObject, iTween.Hash(
				"x", 0,
				"y", 0,
				"z", 0,
                "time", 1,
				"oncomplete", "CloseTimeCount",
				"oncompletetarget", this.gameObject
			));
    }

    void CloseTimeCount() {
        timeCount.text = "";
        timeCount.transform.parent.gameObject.SetActive(false);
    }

    public void GameEnd(string name) {
        winnerName.transform.parent.gameObject.SetActive(true);
        winnerName.text = name;
        gameEndButton.SetActive(true);
    }

}
