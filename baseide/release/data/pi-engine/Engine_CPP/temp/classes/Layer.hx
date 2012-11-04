class Layer
{
    
    public var layers:Array<Layer>;
    public var objects:Array<GameObject>;
    public var isLoaded(default,null):Bool;
    
    public var active(default,_setActive):Bool;
    function _setActive(active:Bool)
    {
        //add/remove it thom activeLayers
        return active;
    }
    
    /** Contains all currently loaded layers in all windows. */
    public static var availableLayers: Array<Layer>;
    
    /** Contains only currently active layers that should be processed */
    public static var activeLayers:Array<Layer>;
    
    public function step()
    {
        trace("How to actually do this STEP?? TODO: Plan the final version!");
    }
    public function draw()
    {
        for(o in objects)
        o.draw()
    }
    
	public function new()
	{
		
	}
}
