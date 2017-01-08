using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum BlockState {
	NONE,
	NORMAL,
	UNBREAK,
	BROKEN,
}

public class Block : MonoBehaviour {

	[SerializeField] string name;
	public string Name {
		get { return name; }
		set { name = value; }
	}

	[SerializeField] int durability;
	public int Durability {
		get { return durability; }
		set { durability = value; }
	}

	[SerializeField] BlockState state;
	public BlockState State {
		get { return state; }
		set { state = value; }
	}
}
