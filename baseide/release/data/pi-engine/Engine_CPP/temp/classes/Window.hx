class Window
{
    /**
        Provides rendering windows. 
        Each window contains layers.
        More than one windows may be used on platforms that support them.
    */
    
    //var viewports: Array
    //var layers
    public var modal(default,_setModality): Bool;
    
    /**
    Mode is platform-specific window mode.

    WIN32: 
    0 - normal window with titlebar
    1 - frameless window.
    
    HTML5: 
    0 - <div> with titlebar and canvas inside
    1 - new browser popup window
    2 - Frameless div (first window is such)
    
    ANDROID:
    Will only support one window. Additional windows can only be modal!
    
    Can't set mode on full-screen window!
    */
    public var mode(default,_setMode): Int;
    
    /**
    Returns or sets this window as fullscreen (without changing the video mode)
    On Android, all windows by default are fullscreen. Setting this to false will show the top bar.
    On HTML5, this will use the browser's full screen ability if such exists.
    */
    public var fullscreen(default, _setFullscreen): Bool;
    
    public var title(default, _setTitle):String;
    
    /**
    Platform native window ID/Handle.
    HWND on Windows
    */
    public var nativeId(default,null): Int;
    
    public var viewports: Array<Viewport>;
    public var layers: Array<Layer>;
    
    //Opened windows
    public static var _windows: Array<Window>;

	public function new()
	{
        trace("NEW Window");
        if(!Application.isInitialized)
        {
            var msg: String =
            "Cannot create window when the application is not initialized."+
            "\nCall Application.init() first!";
            throw msg;
        };
        trace("Creating window...");
        this.nativeId = Window._pi_window_create();
        trace("Window created");
        if(nativeId==0)throw "Unable to create the window!";
        trace()
        Window._windows.push(this);
	}
    
    public function show()
    {
        trace("Showing the window...");
        Window._pi_window_set_visible(nativeId,true);
    }
    public function open()
    {
        Window._pi_window_set_visible(nativeId,true);
    }    
    public function hide()
    {
        Window._pi_window_set_visible(nativeId,false);
    }
    public function close()
    {
        Window._pi_window_set_visible(nativeId,false);
        Window._pi_window_destroy(nativeId);
    }
    
    function _setModality(modal:Bool)
    {
        #if cpp
        _pi_window_set_modality(nativeId, modal);
        #end
        return modal;
    }
    
    function _setMode(mode: Int)
    {
        #if cpp
        _pi_window_set_mode(nativeId, mode);
        #end
        return mode;
    }
    
    function _setFullscreen(fullscreen: Bool)
    {
        #if cpp
        _pi_window_set_fullscreen(nativeId, fullscreen);
        #end
        return fullscreen;
    }

    function _setTitle(title:String)
    {
        #if cpp
        _pi_window_set_title(nativeId, title);
        #end
        return title;
    }
    
#if cpp
    // DLL function                             ARGS            RETVAL
    public static var _pi_window_create:        Void->          Int;    //0 if fail
    public static var _pi_window_destroy:       Int->           Bool;
    public static var _pi_window_set_visible:   Int->Bool->     Void;   //open & show are 1 thing!

    public static var _pi_window_get_title:     Int->Void->     String;
    public static var _pi_window_set_title:     Int->String->   Void;
    
    public static var _pi_window_set_modality:  Int->Bool->     Void;
    public static var _pi_window_set_fullscreen:Int->Bool->      Void;
    public static var _pi_window_set_mode:      Int->Int->      Void;
    
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















