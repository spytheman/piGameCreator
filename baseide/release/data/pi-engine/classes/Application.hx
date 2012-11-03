class Application
{
    private static var shit: Int;
    /** 
        @description: Application is the main class for all pi|engine game 
        or multimedia modules. Application is a static class that provides 
        basic data about the current project and its features.
        
        From this class you can also query the application modes - is the engine
        running in debug mode, in Developer mode or in server mode.
    */

    // Basic data about the application:    
    public static var title: String;
    public static var author: String;
    public static var description: String;
    public static var organization: String;
    public static var url: String;
    public static var version: String;
    
    /** Read-only. If set, the application is running in debug mode. */
    public static var debugMode(_gDebugMode,null): Bool;
    public static function _gDebugMode(){return debugMode;}
    
    public static var serverMode: Bool;
    public static var devMode: Bool;
    
    public static var isInitialized : Bool = false;
    
    
    public static function init()
    {
        debugMode = true;
        try
        {
            Sys.println("Application.exec() called.\nInitializing pi|engine...");
            _pi_query_system_info = cpp.Lib.load("pi-engine", "pi_query_system_info",0);
            Window._windows = new Array<Window>();
        }
        catch(e: Dynamic)
        {
            trace(e);
        }
        isInitialized = true;
    }
    
    /** Starts the game event loop */
    public static function exec()
    {
        try
        {
            if(!isInitialized) 
            {
                Sys.println("Unable to execute the application when it is not initialized!"+
                    "\nCall Init() first!");
                pause();
                terminate(1);
            }
            if(Window._windows.length==0)
            {
                Sys.println("The application must have at least one window to be able to run!");
                pause();
                terminate(1);
            }
            
            //Event loop goes here:
            Sys.println("Starting the event loop...");
            
            //TODO: Plan the event loop!
            while(Window._windows.length>0)
            {
                //how to actually do this?
            }
            
            
            Sys.println("Event loop completed successfully! exec() will now return!");
            return;
        }
        #if cpp
        catch(ex: String)
        {
            Sys.println("Exception was thrown: \n"+ex);
            Sys.println(haxe.Stack.toString(haxe.Stack.callStack()));
            pause();
            terminate(1);
        }
        catch(ex: Dynamic)
        {
            trace(ex);
            Sys.println(haxe.Stack.toString(haxe.Stack.callStack()));
            pause();
            terminate(1);
        }
        #end
    }
    
    /**
        Windows, Mac, Linux:
        Returns the command line arguments passed to the application.
        HTML and JavaScript:
        The query string.
    */
    public static function args()
    {
        #if cpp
        return Sys.args();
        #end
    }
    
    /** Closes the application with given exit code(if supported) */
    public static function terminate(exitCode: Int = 0)
    {
        Sys.exit(exitCode);
        // Must find a way to kill the application.
    }

#if cpp
    // pi-engine shared library pointers. Must remain unlisted.
    public static var _pi_query_system_info: Void->Dynamic;
    //public static var _pi_native_engine_step: Void->Void;
    
    public static function pause()
    {
        Sys.command("pause");
    }
#end
}
















