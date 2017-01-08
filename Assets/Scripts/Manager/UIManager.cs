﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : SingletonMonoBehaviour<UIManager> {

    private PlayerController playerController;
    [SerializeField]
    private Text limitTimeText;

    protected override void Awake()
    {
        base.Awake();
    }

	// Use this for initialization
	void Start () {
        playerController = GameObject.FindGameObjectWithTag("Player").GetComponent<PlayerController>();
	}
	
	// Update is called once per frame
	void Update () {
		
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
        limitTimeText.text = time.ToString();
    }

}
