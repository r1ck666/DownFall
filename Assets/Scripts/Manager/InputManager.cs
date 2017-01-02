using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputManager : SingletonMonoBehaviour<InputManager> {

	//とりあえず宣言しておく
	public enum InputKey {
		Left_Click,
		Right_Click,
		Wheel,
		Horizontal,
		Vertical,
		Enter,
		Space,
		Shift,
		Control,
		Input_Num,
	}

	public delegate void InputDelegate();
	public InputDelegate[] InputKeyDown;


	protected override void Awake() {
		base.Awake();

		InputKeyDown = new InputDelegate[ (int) InputKey.Input_Num];
		//Debug
		InputKeyDown[(int)InputKey.Left_Click] = LeftClick;
	}

	void Update () {
		if (Input.GetKeyDown( KeyCode.Mouse0 )) {
			InputKeyDown[(int)InputKey.Left_Click]();
		}
	}

	//Debug
	void LeftClick() {
		Debug.Log("LeftClick!");
	}
}
