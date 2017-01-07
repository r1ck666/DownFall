using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

//できればエラーの例外処理ができるようになりたいな。。。

public class StageManager : SingletonMonoBehaviour<StageManager> {

	//　現在選択中のステージ
	Stage stage;
	// Stageが格納されているオブジェクト
	GameObject stageObject;
	// BlockのPrefabが格納されているリスト
	List<GameObject> blockList;
	GameObject[,,] blocksObject;

	protected override void Awake() {
		base.Awake();
		string stageData = ResourcesLoad ("TestMap");
		stage = MapLoad(stageData);
		MapCreate(stage);
	}

	public Stage GetStage() {
		return stage;
	}

	public GameObject[,,] GetBlocksObject() {
		return blocksObject;
	}

	string ResourcesLoad (string mapName)
	{
		// BlockPrefabの読み込み
		BlockLoad();

		//マップデータを読み込み
		return Resources.Load <TextAsset> ("Map/"+mapName).text;
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
		stageObject = new GameObject("Stage");
		blocksObject = new GameObject[stage.X, stage.Y, stage.Z];
		for (uint j = 0; j < stage.Y; j++) {
			for (uint k = 0; k < stage.Z; k++) {
				for (uint i = 0; i < stage.X; i++) {
					GameObject go = Instantiate (blockList[(int)stage[i, j, k]], new Vector3(i, j, k), Quaternion.identity);
					go.transform.parent = stageObject.transform;
					blocksObject[i, j, k] = go;
				}
			}
		}
	}


}
