using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NormalGameManager : SingletonPhotonMonoBehaviour<NormalGameManager> {

	//================================
	// Network設定関連
	//================================
	string _gameVersion = "1";

	//================================
	// GameRole関連
	//================================

	// 制限時間
	[SerializeField] float timeLimit = 300f;
	// 岩ブロック最大数
	[SerializeField] uint rockNum = 10;

	//================================
	// StageManager関連
	//================================
	Stage stage;
	uint[,,] blocks;
	GameObject[,,] blocksObject;

	protected override void Awake()
	{
		base.Awake();
	}

	void Start()
	{
		// Stage関連のキャッシュ
		stage = StageManager.Instance.GetStage();
		blocks = stage.GetBlocks();
		blocksObject = StageManager.Instance.GetBlocksObject();

	}

	/*
	public AnimState ActionJudge (uint x, uint z) {
		//y座標が1の時にブロックがなければ、y座標0を調べる
		return AnimState.Break;
	}
	*/

}
