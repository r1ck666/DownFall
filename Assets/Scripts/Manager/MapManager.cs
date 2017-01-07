using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MapManager : SingletonMonoBehaviour<MapManager> {

	// Use this for initialization
	void Start () {

	}

	// Update is called once per frame
	void Update () {

	}

	//csvファイル（txtファイル)から読み込み
	void MapLoad()
	{
		//mapの大きさを調べる
		//charをそのままSplitの引数に指定するとエラーが出る...（ネットでは別の書式と認識されるからっぽい？）
		char[] separator = new char[]{'\n'};
		string[] lines = textMap.text.Split(separator, System.StringSplitOptions.RemoveEmptyEntries);
		string[] line = lines[0].Split(',');
		row = lines.Length;
		column = line.Length;
		map = new string[row,column];
		for (i=0; i<row; i++){
			line = lines[i].Split(',');
			for(j=0; j<column; j++){
				map[i,j] = line[j];
			}
		}
	}

	void MapLoadLinq (string stageData)
	{
		var lines = stageData.Split(new[] { '\n', '\r' }, System.StringSplitOptions.RemoveEmptyEntries)
			.Where(line => !(line.IndexOf ("abc") == -1))
			.ToArray();
	}

	public Stage(string stageData) {
		var lines = stageData.Split(new[] { '\n', '\r' }, System.StringSplitOptions.RemoveEmptyEntries)
			.Where(line => !line.StartsWith("#"))	// コメント行を取り除く
			.ToArray();

		// ステージ名
		stageName = lines[0];

		timeLimit = int.Parse(lines[1]);

		// ブロック生成・破壊可能回数
		var times = lines[2].Split(' ').Select(time => uint.Parse(time)).ToArray();
		createTime = times[0];
		breakTime = times[1];

		// ステージサイズの読み込み
		var stageSize = lines[3].Split(' ').Select(size => uint.Parse(size)).ToArray();
		x = stageSize[0];
		y = stageSize[1];
		z = stageSize[2];

		blocks = new Block[x, y, z];

		// ステージデータ
		for (uint j = 0; j < y; j++) {
			for (uint k = 0; k < z; k++) {
				var xLine = lines[j * z + k + 4]
							.Split(new[] {' '}, System.StringSplitOptions.RemoveEmptyEntries)
							.Select(l => uint.Parse(l)).ToArray();
				for (uint i = 0; i < x; i++) {
					blocks[i, j, k] = (Block) xLine[i];
				}
			}
		}
	}
}
