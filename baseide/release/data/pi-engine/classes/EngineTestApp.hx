@:no_completion
class EngineTestApp
{
    /** Pi engine testing application. */
    public static function main()
    {    
        try
        {
            Application.title = "pi|engine testing application";
            
            Application.init();        
            trace("Application init successful");
            //Create a window:
            
            var w = new Window();
            
            w.title = "Pesho";
            w.open();
            
            Application.exec();
            Application.pause();
        }
        catch(e:Dynamic)
        {
            Sys.println("Application exception occurred");
            trace(e);
            Sys.println("---------- CALL STACK ----------");
            trace(haxe.Stack.callStack());
            Application.pause();
        }
    }
}
