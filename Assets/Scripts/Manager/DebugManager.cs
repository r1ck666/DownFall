using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DebugManager : SingletonMonoBehaviour<DebugManager> {

	// ===============================
	// Public
	// ===============================
	[SerializeField, HeaderAttribute("Public")] GameObject debugUI;
	// ===============================
	// TitleManager
	// ===============================
	[SerializeField, HeaderAttribute("TitleManager")] GameObject titleUI;


	protected override void Awake () {
		base.Awake();
		DontDestroyOnLoad(transform.gameObject);
	}

	// Use this for initialization
	void Start () {

	}

	// Update is called once per frame
	void Update () {

	}

	// ===============================
	// Public Method
	// ===============================

	//DebugUIのアクティブ化
	public void SetActiveDebugUI() {
		if (debugUI.activeSelf){
			debugUI.SetActive (false);
		} else {
			debugUI.SetActive (true);
		}
	}
}
