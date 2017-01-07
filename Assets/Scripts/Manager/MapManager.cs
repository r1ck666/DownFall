using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

public class MapManager : SingletonMonoBehaviour<MapManager> {

	[SerializeField] string stageName;
	[SerializeField] uint x;
	[SerializeField] uint y;
	[SerializeField] uint z;

	public string stageData;

	[SerializeField] GameObject[,,] blocks;
	List<GameObject> blockList;
	[SerializeField] GameObject debug1;
	[SerializeField] GameObject debug2;

	new void Awake() {
		base.Awake();
		ResourcesLoad ("TestMap");
		debug1 = blockList[0];
		debug2 = blockList[1];
		MapLoad(stageData);
	}


	void MapLoad (string stageData)
	{
		// 配列に格納
		var lines = stageData.Split(new[] { '\n', '\r' }, System.StringSplitOptions.RemoveEmptyEntries)
			.Where(line => line.IndexOf ("#") == -1) // コメント行を取り除く
			.ToArray();

		// ステージ名
		stageName = lines[0];

		// ステージサイズの読み込み
		var stageSize = lines[1].Split(' ').Select(size => uint.Parse(size)).ToArray();
		x = stageSize[0];
		y = stageSize[1];
		z = stageSize[2];

		blocks = new GameObject[x, y, z];

		// ステージデータの読み込み
		for (uint j = 0; j < y; j++) {
			for (uint k = 0; k < z; k++) {
				var xLine = lines[j * z + k + 2]
							.Split(new[] {' '}, System.StringSplitOptions.RemoveEmptyEntries)
							.Select(l => int.Parse(l)).ToArray();
				for (uint i = 0; i < x; i++) {
					Debug.Log("X:"+i+" Y:"+j+" Z:"+k+" xLine:"+xLine[i]);
					blocks[i, j, k] = blockList[xLine[i]];
				}
			}
		}
		stageData = null;	//メモリ解放
	}

	void ResourcesLoad (string mapName)
	{
		//ブロックPrefabの読み込み
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

	void MapCreate ()
	{

	}
}
