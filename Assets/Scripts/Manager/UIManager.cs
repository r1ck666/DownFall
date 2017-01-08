using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : SingletonMonoBehaviour<UIManager> {

    private PlayerController playerController;

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

    public void OnActionButton()
    {
        playerController.OnActionButton();
    }



}
