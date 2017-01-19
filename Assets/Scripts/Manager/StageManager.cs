using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

//できればエラーの例外処理ができるようになりたいな。。。

public class StageManager : SingletonMonoBehaviour<StageManager> {

	//　現在選択中のステージ
	Stage stage;
	public Stage Stage { get { return stage; } }
	// Stageが格納されているオブジェクト
	GameObject stageObject;
	// BlockのPrefabが格納されているリスト
	List<GameObject> blockList;
	Block[,,] blocksObject;
	public Block[,,] BlocksObject { get { return blocksObject; } }

	protected override void Awake() {
		base.Awake();
		string stageData = ResourcesLoad ("TestMap");
		stage = MapLoad(stageData);
		CreateMap(stage);
		CreateDeadArea(stage);
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

		//初期位置の読み込み（posX, posY, posZ, rotX, rotY, rotZ)...オイラー角計算
		uint startPositionSize = uint.Parse(lines[2]);
	 	int[,] startPosition = new int[startPositionSize, 6];

		for (uint i = 0; i < startPositionSize; i++) {
			var startTemp = lines[3+i].Split(' ').Select(start => int.Parse(start)).ToArray();
			for (uint j = 0; j < 6; j++) {
				startPosition[i, j] = startTemp[j];
			}
		}

		uint[,,] blocks = new uint[x, y, z];

		// ステージデータの読み込み
		for (uint j = 0; j < y; j++) {
			for (uint k = 0; k < z; k++) {
				var xLine = lines[j * z + k + 3 + startPositionSize]	//これまでに読み込んだ行を足してる
							.Split(new[] {' '}, System.StringSplitOptions.RemoveEmptyEntries)
							.Select(l => uint.Parse(l)).ToArray();
				for (uint i = 0; i < x; i++) {
					blocks[i, j, k] = xLine[i];
				}
			}
		}
		stageData = null;	//メモリ解放

		return new Stage(stageName, x, y, z, startPosition, blocks);
	}

	void CreateMap ( Stage stage )
	{
		stageObject = new GameObject("Stage");
		blocksObject = new Block[stage.X, stage.Y, stage.Z];
		for (uint j = 0; j < stage.Y; j++) {
			for (uint k = 0; k < stage.Z; k++) {
				for (uint i = 0; i < stage.X; i++) {
					GameObject go = Instantiate (blockList[(int)stage[i, j, k]], new Vector3(i, j, k), Quaternion.identity);
					go.transform.parent = stageObject.transform;
					blocksObject[i, j, k] = go.GetComponent<Block>();
				}
			}
		}
	}

	void CreateDeadArea ( Stage stage )
	{
		var deadArea = new GameObject("DeadArea");
		deadArea.transform.parent = stageObject.transform;
		deadArea.AddComponent<BoxCollider>();
		deadArea.GetComponent<BoxCollider>().size = new Vector3(stage.X*10, 1, stage.Z*10);
		deadArea.GetComponent<BoxCollider>().isTrigger = true;
		deadArea.transform.position = new Vector3(0, -10, 0);
		deadArea.tag = "DeadArea";
	}


}
