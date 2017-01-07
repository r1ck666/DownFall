public class Stage  {

	string stageName;
	public string StageName { get { return stageName; } }

	uint x;
	public uint X { get { return x; } }

	uint y;
	public uint Y { get { return y;} }

	uint z;
	public uint Z { get { return z; } }

	uint[,,] blocks;

	uint[,,] GetBlocks() {
		return blocks;
	}

	public uint this[uint x, uint y, uint z]
    {
        get { return this.blocks[x, y, z]; }
    }

	public Stage (string stageName, uint x, uint y, uint z, uint[,,] blocks) {
		this.stageName = stageName;
		this.x = x;
		this.y = y;
		this.z = z;
		this.blocks = blocks;
	}
}
