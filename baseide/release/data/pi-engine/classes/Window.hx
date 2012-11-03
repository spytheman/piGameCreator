class Window
{
    /**
        Provides rendering windows. 
        Each window contains layers.
        More than one windows may be used on platforms that support them.
    */
    
    //var viewports: Array
    //var layers
    public var modal: Bool;
    public var mode: Int;
    public var fullscreen: Bool;
    public var id(_getId,null): Int;
    
    public var viewports: Array<Viewport>;
    public var layers: Array<Layer>;
    
    //Opened windows
    public static var _windows: Array<Window>;

	public function new()
	{
        Sys.println("NEW Window");
        if(!Application.isInitialized)
        {
            var msg: String =
            "Cannot create window when the application is not initialized."+
            "\nCall Application.init() first!";
            throw msg;
        };
        Window._windows.push(this);
		
	}
    
    function setModality(modal:Bool)
    {
    }
    
    function setMode(mode: Bool)
    {
        
    }
    
    function setFullscreen(fullscreen: Bool)
    {
        
    }
    
    public function _getId()
    {
        return id;
    }
    
#if cpp
    // DLL function                             ARGS            RETVAL
    public static var _pi_window_create:        Int->String->   Int;    //0 if fail
    public static var _pi_window_destroy:       Int->           Bool;
    public static var _pi_window_set_visible:   Int->Bool->     Void;   //open & show are 1 thing!

    public static var _pi_window_get_title:     Int->Void->     String;
    public static var _pi_window_set_title:     Int->String->   Void;
    
    public static var _pi_window_move_rect:     Int->Point->    Void;
    public static var _pi_window_move_xy:       Int->Int->Int-> Void;
    public static var _pi_window_get_pos:       Int->           Point;
    public static var _pi_window_get_size:      Int->           Rect;
    public static var _pi_window_resize_rect:   Int->Rect->     Void;
    public static var _pi_window_resize_wh:     Int->Int->Int-> Void;
    
    public static var _pi_window_maximize:      Int->           Void;
    public static var _pi_window_minimize:      Int->           Void;
    public static var _pi_window_restore:       Int->           Void;
    
    public static var _pi_window_set_video_mode:Int->Int->Int->Int->Bool->  Bool;
    public static var _pi_window_list_modes:    Void-> Array<{width:Int,height:Int,depth:Int}>;
    
#end
    
}















