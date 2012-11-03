#include <hxcpp.h>

#include <sys/io/FileSeek.h>
#include <sys/io/FileOutput.h>
#include <sys/io/FileInput.h>
#include <haxe/io/Output.h>
#include <haxe/io/Input.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/BytesBuffer.h>
#include <haxe/io/Bytes.h>
#include <haxe/Stack.h>
#include <haxe/StackItem.h>
#include <haxe/Log.h>
#include <Window.h>
#include <Viewport.h>
#include <Sys.h>
#include <cpp/Lib.h>
#include <StringBuf.h>
#include <Std.h>
#include <Layer.h>
#include <IntIter.h>
#include <Hash.h>
#include <EngineTestApp.h>
#include <Application.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::sys::io::FileSeek_obj::__register();
::sys::io::FileOutput_obj::__register();
::sys::io::FileInput_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::Stack_obj::__register();
::haxe::StackItem_obj::__register();
::haxe::Log_obj::__register();
::Window_obj::__register();
::Viewport_obj::__register();
::Sys_obj::__register();
::cpp::Lib_obj::__register();
::StringBuf_obj::__register();
::Std_obj::__register();
::Layer_obj::__register();
::IntIter_obj::__register();
::Hash_obj::__register();
::EngineTestApp_obj::__register();
::Application_obj::__register();
::cpp::Lib_obj::__boot();
::haxe::Log_obj::__boot();
::Application_obj::__boot();
::EngineTestApp_obj::__boot();
::Hash_obj::__boot();
::IntIter_obj::__boot();
::Layer_obj::__boot();
::Std_obj::__boot();
::StringBuf_obj::__boot();
::Sys_obj::__boot();
::Viewport_obj::__boot();
::Window_obj::__boot();
::haxe::StackItem_obj::__boot();
::haxe::Stack_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::Input_obj::__boot();
::haxe::io::Output_obj::__boot();
::sys::io::FileInput_obj::__boot();
::sys::io::FileOutput_obj::__boot();
::sys::io::FileSeek_obj::__boot();
}

