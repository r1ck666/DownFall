public class Stage  {

	string stageName;
	public string StageName { get { return stageName; } }

	uint x;
	public uint X { get { return x; } }

	uint y;
	public uint Y { get { return y;} }

	uint z;
	public uint Z { get { return z; } }

	int[,] startPosition;
	public int[,] StartPosition { get { return startPosition; } }

	uint[,,] blocks;
	public uint[,,] Blocks { get { return blocks; } }

	public uint this[uint x, uint y, uint z]
    {
        get { return this.blocks[x, y, z]; }
    }

	public Stage (string stageName, uint x, uint y, uint z, int[,] startPosition, uint[,,] blocks) {
		this.stageName = stageName;
		this.x = x;
		this.y = y;
		this.z = z;
		this.startPosition = startPosition;
		this.blocks = blocks;
	}
}
