@:no_completion
class EngineTestApp
{
    /** Pi engine testing application. */
    public static function main()
    {    
        Application.title = "pi|engine testing application";
        
        Application.init();        
        
        var o:GameObject;
        o = new GameObject();
        o.zrot = 10;
        
        trace(o.rotation);
        o.rotation = 50;
        
        trace(o.zrot);
        vm.
        
        Application.exec();
        Application.pause();
    }
}
