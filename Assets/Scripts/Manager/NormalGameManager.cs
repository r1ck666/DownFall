using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

public class NormalGameManager : SingletonMonoBehaviour<NormalGameManager> {


	//================================
	// GameRole関連
	//================================

	// 制限時間
	[SerializeField] float timeLimit = 300f;
	// 岩ブロック最大数
	[SerializeField] uint rockNum = 10;


	void Awake() {
		base.Awake();

	}



}
