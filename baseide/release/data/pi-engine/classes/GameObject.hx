class GameObject
{
    /** Object's X coordinate '*/
    public var x:Float;
    /** Object's Y coordinate '*/
    public var y:Float;
    /** Object's Z coordinate '*/
    public var z:Float;
    
    /** Object's X rotation */
    public var xrot:Float;
    /** Object's Y rotation */
    public var yrot:Float;
    /** Object's Z rotation */
    public var zrot:Float;
    /** Object's Z rotation */
    public var rotation( _getZrot,_setZrot ):Float;
    
    /** Object's representation, if this object needs to be displayed */
    public var representation:Representation;
    public function _getZrot() {return zrot;}
    public function _setZrot(zrot:Float) {this.zrot=zrot;return this.zrot;}
    
    /** New game object. You can optionally pass the x,y and z coordinates. */
	public function new(x:Float=0,y:Float=0,z:Float=0)
	{
		this.x=x;
        this.y=y;
        this.z=z;
        
        this.xrot=0;
        this.yrot=0;
        this.zrot=0;
        
        this.representation=null;
	}
}
