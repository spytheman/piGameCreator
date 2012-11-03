#include <hxcpp.h>

#include <haxe/Log.h>
#include <Std.h>
#include <Shit.h>
#include <Main.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::haxe::Log_obj::__register();
::Std_obj::__register();
::Shit_obj::__register();
::Main_obj::__register();
::haxe::Log_obj::__boot();
::Main_obj::__boot();
::Shit_obj::__boot();
::Std_obj::__boot();
}

