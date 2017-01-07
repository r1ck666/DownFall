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

	//================================
	// Stage関連
	//================================
	Stage stage;
	List<GameObject> blockList;
	//================================

	void Awake() {
		base.Awake();
		string stageData = ResourcesLoad ("TestMap");
		stage = MapLoad(stageData);
		MapCreate(stage);
	}

	//===================================
	// Map関連
	//===================================

	string ResourcesLoad (string mapName)
	{
		// BlockPrefabの読み込み
		BlockLoad();

		//マップデータを読み込み
		stageData = Resources.Load <TextAsset> ("Map/"+mapName).text;
	}

	void BlockLoad ()
	{
		GameObject[] blockArray  = Resources.LoadAll<GameObject>("Blocks/");
		blockList = new List<GameObject>();
		blockList.AddRange(blockArray);
	}

	Stage MapLoad (string stageData)
	{
		// 配列に格納
		var lines = stageData.Split(new[] { '\n', '\r' }, System.StringSplitOptions.RemoveEmptyEntries)
			.Where(line => line.IndexOf ("#") == -1) // コメント行を取り除く
			.ToArray();

		// ステージ名
		string stageName = lines[0];

		// ステージサイズの読み込み
		var stageSize = lines[1].Split(' ').Select(size => uint.Parse(size)).ToArray();
		uint x = stageSize[0];
		uint y = stageSize[1];
		uint z = stageSize[2];

		uint[,,] blocks = new uint[x, y, z];

		// ステージデータの読み込み
		for (uint j = 0; j < y; j++) {
			for (uint k = 0; k < z; k++) {
				var xLine = lines[j * z + k + 2]
							.Split(new[] {' '}, System.StringSplitOptions.RemoveEmptyEntries)
							.Select(l => uint.Parse(l)).ToArray();
				for (uint i = 0; i < x; i++) {
					blocks[i, j, k] = xLine[i];
				}
			}
		}
		stageData = null;	//メモリ解放

		return new Stage(stageName, x, y, z, blocks);
	}

	void MapCreate( Stage stage )
	{
		for (uint j = 0; j < y; j++) {
			for (uint k = 0; k < z; k++) {
				for (uint i = 0; i < x; i++) {

				}
			}
		}
	}
}
