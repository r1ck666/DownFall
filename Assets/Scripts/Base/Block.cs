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

	/// <summary>
    /// iTweenで落下した位置を元に戻します(コライダも消します)
    /// </summary>
	public void InitializePosY()
	{
		Vector3 pos = transform.position;
		transform.position = new Vector3 (pos.x, 0, pos.z);
		GetComponent<Renderer>().enabled = false;
		GetComponent<BoxCollider>().enabled = false;
	}
}
