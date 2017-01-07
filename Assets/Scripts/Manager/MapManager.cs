using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

public class MapManager : SingletonMonoBehaviour<MapManager> {


/*
	void MapLoadLinq (string stageData)
	{
		// 配列に格納
		var lines = stageData.Split(new[] { '\n', '\r' }, System.StringSplitOptions.RemoveEmptyEntries)
			.Where(line => !(line.IndexOf ("#") == -1)) // コメント行を取り除く
			.ToArray();

		// ステージ名
		stageName = lines[0];

		// ステージサイズの読み込み
		var stageSize = lines[2].Split(' ').Select(size => uint.Parse(size)).ToArray();
	}
	*/

/*
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
	*/
}
