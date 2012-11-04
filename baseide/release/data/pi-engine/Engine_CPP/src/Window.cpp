#include <hxcpp.h>

#ifndef INCLUDED_Application
#include <Application.h>
#endif
#ifndef INCLUDED_Layer
#include <Layer.h>
#endif
#ifndef INCLUDED_Point
#include <Point.h>
#endif
#ifndef INCLUDED_Rect
#include <Rect.h>
#endif
#ifndef INCLUDED_Viewport
#include <Viewport.h>
#endif
#ifndef INCLUDED_Window
#include <Window.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void Window_obj::__construct()
{
HX_STACK_PUSH("Window::new","Window.hx",54);
{
	HX_STACK_LINE(55)
	::haxe::Log_obj::trace(HX_CSTRING("NEW Window"),hx::SourceInfo(HX_CSTRING("Window.hx"),55,HX_CSTRING("Window"),HX_CSTRING("new")));
	HX_STACK_LINE(56)
	if ((!(::Application_obj::isInitialized))){
		HX_STACK_LINE(58)
		::String msg = (HX_CSTRING("Cannot create window when the application is not initialized.") + HX_CSTRING("\nCall Application.init() first!"));		HX_STACK_VAR(msg,"msg");
		HX_STACK_LINE(61)
		hx::Throw (msg);
	}
	HX_STACK_LINE(63)
	::haxe::Log_obj::trace(HX_CSTRING("Creating window..."),hx::SourceInfo(HX_CSTRING("Window.hx"),63,HX_CSTRING("Window"),HX_CSTRING("new")));
	HX_STACK_LINE(64)
	this->nativeId = ::Window_obj::_pi_window_create();
	HX_STACK_LINE(65)
	::haxe::Log_obj::trace(HX_CSTRING("Window created"),hx::SourceInfo(HX_CSTRING("Window.hx"),65,HX_CSTRING("Window"),HX_CSTRING("new")));
	HX_STACK_LINE(66)
	if (((this->nativeId == (int)0))){
		HX_STACK_LINE(66)
		hx::Throw (HX_CSTRING("Unable to create the window!"));
	}
	HX_STACK_LINE(67)
	::haxe::Log_obj::trace(this->nativeId,hx::SourceInfo(HX_CSTRING("Window.hx"),67,HX_CSTRING("Window"),HX_CSTRING("new")));
	HX_STACK_LINE(68)
	::Window_obj::_windows->push(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Window_obj::~Window_obj() { }

Dynamic Window_obj::__CreateEmpty() { return  new Window_obj; }
hx::ObjectPtr< Window_obj > Window_obj::__new()
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct();
	return result;}

Dynamic Window_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct();
	return result;}

::String Window_obj::_setTitle( ::String title){
	HX_STACK_PUSH("Window::_setTitle","Window.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_ARG(title,"title");
	HX_STACK_LINE(117)
	::Window_obj::_pi_window_set_title(this->nativeId,title);
	HX_STACK_LINE(119)
	return title;
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,_setTitle,return )

bool Window_obj::_setFullscreen( bool fullscreen){
	HX_STACK_PUSH("Window::_setFullscreen","Window.hx",107);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fullscreen,"fullscreen");
	HX_STACK_LINE(109)
	::Window_obj::_pi_window_set_fullscreen(this->nativeId,fullscreen);
	HX_STACK_LINE(111)
	return fullscreen;
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,_setFullscreen,return )

int Window_obj::_setMode( int mode){
	HX_STACK_PUSH("Window::_setMode","Window.hx",99);
	HX_STACK_THIS(this);
	HX_STACK_ARG(mode,"mode");
	HX_STACK_LINE(101)
	::Window_obj::_pi_window_set_mode(this->nativeId,mode);
	HX_STACK_LINE(103)
	return mode;
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,_setMode,return )

bool Window_obj::_setModality( bool modal){
	HX_STACK_PUSH("Window::_setModality","Window.hx",91);
	HX_STACK_THIS(this);
	HX_STACK_ARG(modal,"modal");
	HX_STACK_LINE(93)
	::Window_obj::_pi_window_set_modality(this->nativeId,modal);
	HX_STACK_LINE(95)
	return modal;
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,_setModality,return )

Void Window_obj::close( ){
{
		HX_STACK_PUSH("Window::close","Window.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_LINE(86)
		::Window_obj::_pi_window_set_visible(this->nativeId,false);
		HX_STACK_LINE(87)
		::Window_obj::_pi_window_destroy(this->nativeId);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,close,(void))

Void Window_obj::hide( ){
{
		HX_STACK_PUSH("Window::hide","Window.hx",81);
		HX_STACK_THIS(this);
		HX_STACK_LINE(81)
		::Window_obj::_pi_window_set_visible(this->nativeId,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,hide,(void))

Void Window_obj::open( ){
{
		HX_STACK_PUSH("Window::open","Window.hx",77);
		HX_STACK_THIS(this);
		HX_STACK_LINE(77)
		::Window_obj::_pi_window_set_visible(this->nativeId,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,open,(void))

Void Window_obj::show( ){
{
		HX_STACK_PUSH("Window::show","Window.hx",72);
		HX_STACK_THIS(this);
		HX_STACK_LINE(73)
		::haxe::Log_obj::trace(HX_CSTRING("Showing the window..."),hx::SourceInfo(HX_CSTRING("Window.hx"),73,HX_CSTRING("Window"),HX_CSTRING("show")));
		HX_STACK_LINE(74)
		::Window_obj::_pi_window_set_visible(this->nativeId,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,show,(void))

Array< ::Window > Window_obj::_windows;

Dynamic Window_obj::_pi_window_create;

Dynamic Window_obj::_pi_window_destroy;

Dynamic Window_obj::_pi_window_set_visible;

Dynamic Window_obj::_pi_window_get_title;

Dynamic Window_obj::_pi_window_set_title;

Dynamic Window_obj::_pi_window_set_modality;

Dynamic Window_obj::_pi_window_set_fullscreen;

Dynamic Window_obj::_pi_window_set_mode;

Dynamic Window_obj::_pi_window_move_rect;

Dynamic Window_obj::_pi_window_move_xy;

Dynamic Window_obj::_pi_window_get_pos;

Dynamic Window_obj::_pi_window_get_size;

Dynamic Window_obj::_pi_window_resize_rect;

Dynamic Window_obj::_pi_window_resize_wh;

Dynamic Window_obj::_pi_window_maximize;

Dynamic Window_obj::_pi_window_minimize;

Dynamic Window_obj::_pi_window_restore;

Dynamic Window_obj::_pi_window_set_video_mode;

Dynamic Window_obj::_pi_window_list_modes;


Window_obj::Window_obj()
{
}

void Window_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Window);
	HX_MARK_MEMBER_NAME(layers,"layers");
	HX_MARK_MEMBER_NAME(viewports,"viewports");
	HX_MARK_MEMBER_NAME(nativeId,"nativeId");
	HX_MARK_MEMBER_NAME(title,"title");
	HX_MARK_MEMBER_NAME(fullscreen,"fullscreen");
	HX_MARK_MEMBER_NAME(mode,"mode");
	HX_MARK_MEMBER_NAME(modal,"modal");
	HX_MARK_END_CLASS();
}

void Window_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(layers,"layers");
	HX_VISIT_MEMBER_NAME(viewports,"viewports");
	HX_VISIT_MEMBER_NAME(nativeId,"nativeId");
	HX_VISIT_MEMBER_NAME(title,"title");
	HX_VISIT_MEMBER_NAME(fullscreen,"fullscreen");
	HX_VISIT_MEMBER_NAME(mode,"mode");
	HX_VISIT_MEMBER_NAME(modal,"modal");
}

Dynamic Window_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"hide") ) { return hide_dyn(); }
		if (HX_FIELD_EQ(inName,"open") ) { return open_dyn(); }
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		if (HX_FIELD_EQ(inName,"mode") ) { return mode; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"title") ) { return title; }
		if (HX_FIELD_EQ(inName,"modal") ) { return modal; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"layers") ) { return layers; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_windows") ) { return _windows; }
		if (HX_FIELD_EQ(inName,"_setMode") ) { return _setMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nativeId") ) { return nativeId; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_setTitle") ) { return _setTitle_dyn(); }
		if (HX_FIELD_EQ(inName,"viewports") ) { return viewports; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fullscreen") ) { return fullscreen; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_setModality") ) { return _setModality_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_setFullscreen") ) { return _setFullscreen_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_pi_window_create") ) { return _pi_window_create; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_pi_window_destroy") ) { return _pi_window_destroy; }
		if (HX_FIELD_EQ(inName,"_pi_window_move_xy") ) { return _pi_window_move_xy; }
		if (HX_FIELD_EQ(inName,"_pi_window_get_pos") ) { return _pi_window_get_pos; }
		if (HX_FIELD_EQ(inName,"_pi_window_restore") ) { return _pi_window_restore; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_pi_window_set_mode") ) { return _pi_window_set_mode; }
		if (HX_FIELD_EQ(inName,"_pi_window_get_size") ) { return _pi_window_get_size; }
		if (HX_FIELD_EQ(inName,"_pi_window_maximize") ) { return _pi_window_maximize; }
		if (HX_FIELD_EQ(inName,"_pi_window_minimize") ) { return _pi_window_minimize; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_pi_window_get_title") ) { return _pi_window_get_title; }
		if (HX_FIELD_EQ(inName,"_pi_window_set_title") ) { return _pi_window_set_title; }
		if (HX_FIELD_EQ(inName,"_pi_window_move_rect") ) { return _pi_window_move_rect; }
		if (HX_FIELD_EQ(inName,"_pi_window_resize_wh") ) { return _pi_window_resize_wh; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_pi_window_list_modes") ) { return _pi_window_list_modes; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_pi_window_set_visible") ) { return _pi_window_set_visible; }
		if (HX_FIELD_EQ(inName,"_pi_window_resize_rect") ) { return _pi_window_resize_rect; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_pi_window_set_modality") ) { return _pi_window_set_modality; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_pi_window_set_fullscreen") ) { return _pi_window_set_fullscreen; }
		if (HX_FIELD_EQ(inName,"_pi_window_set_video_mode") ) { return _pi_window_set_video_mode; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Window_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { if (inCallProp) return _setMode(inValue);mode=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { if (inCallProp) return _setTitle(inValue);title=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"modal") ) { if (inCallProp) return _setModality(inValue);modal=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"layers") ) { layers=inValue.Cast< Array< ::Layer > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_windows") ) { _windows=inValue.Cast< Array< ::Window > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nativeId") ) { nativeId=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"viewports") ) { viewports=inValue.Cast< Array< ::Viewport > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fullscreen") ) { if (inCallProp) return _setFullscreen(inValue);fullscreen=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_pi_window_create") ) { _pi_window_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_pi_window_destroy") ) { _pi_window_destroy=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_move_xy") ) { _pi_window_move_xy=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_get_pos") ) { _pi_window_get_pos=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_restore") ) { _pi_window_restore=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_pi_window_set_mode") ) { _pi_window_set_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_get_size") ) { _pi_window_get_size=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_maximize") ) { _pi_window_maximize=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_minimize") ) { _pi_window_minimize=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_pi_window_get_title") ) { _pi_window_get_title=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_set_title") ) { _pi_window_set_title=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_move_rect") ) { _pi_window_move_rect=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_resize_wh") ) { _pi_window_resize_wh=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_pi_window_list_modes") ) { _pi_window_list_modes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_pi_window_set_visible") ) { _pi_window_set_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_resize_rect") ) { _pi_window_resize_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_pi_window_set_modality") ) { _pi_window_set_modality=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_pi_window_set_fullscreen") ) { _pi_window_set_fullscreen=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pi_window_set_video_mode") ) { _pi_window_set_video_mode=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Window_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("layers"));
	outFields->push(HX_CSTRING("viewports"));
	outFields->push(HX_CSTRING("nativeId"));
	outFields->push(HX_CSTRING("title"));
	outFields->push(HX_CSTRING("fullscreen"));
	outFields->push(HX_CSTRING("mode"));
	outFields->push(HX_CSTRING("modal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_windows"),
	HX_CSTRING("_pi_window_create"),
	HX_CSTRING("_pi_window_destroy"),
	HX_CSTRING("_pi_window_set_visible"),
	HX_CSTRING("_pi_window_get_title"),
	HX_CSTRING("_pi_window_set_title"),
	HX_CSTRING("_pi_window_set_modality"),
	HX_CSTRING("_pi_window_set_fullscreen"),
	HX_CSTRING("_pi_window_set_mode"),
	HX_CSTRING("_pi_window_move_rect"),
	HX_CSTRING("_pi_window_move_xy"),
	HX_CSTRING("_pi_window_get_pos"),
	HX_CSTRING("_pi_window_get_size"),
	HX_CSTRING("_pi_window_resize_rect"),
	HX_CSTRING("_pi_window_resize_wh"),
	HX_CSTRING("_pi_window_maximize"),
	HX_CSTRING("_pi_window_minimize"),
	HX_CSTRING("_pi_window_restore"),
	HX_CSTRING("_pi_window_set_video_mode"),
	HX_CSTRING("_pi_window_list_modes"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_setTitle"),
	HX_CSTRING("_setFullscreen"),
	HX_CSTRING("_setMode"),
	HX_CSTRING("_setModality"),
	HX_CSTRING("close"),
	HX_CSTRING("hide"),
	HX_CSTRING("open"),
	HX_CSTRING("show"),
	HX_CSTRING("layers"),
	HX_CSTRING("viewports"),
	HX_CSTRING("nativeId"),
	HX_CSTRING("title"),
	HX_CSTRING("fullscreen"),
	HX_CSTRING("mode"),
	HX_CSTRING("modal"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Window_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Window_obj::_windows,"_windows");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_create,"_pi_window_create");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_destroy,"_pi_window_destroy");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_set_visible,"_pi_window_set_visible");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_get_title,"_pi_window_get_title");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_set_title,"_pi_window_set_title");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_set_modality,"_pi_window_set_modality");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_set_fullscreen,"_pi_window_set_fullscreen");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_set_mode,"_pi_window_set_mode");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_move_rect,"_pi_window_move_rect");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_move_xy,"_pi_window_move_xy");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_get_pos,"_pi_window_get_pos");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_get_size,"_pi_window_get_size");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_resize_rect,"_pi_window_resize_rect");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_resize_wh,"_pi_window_resize_wh");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_maximize,"_pi_window_maximize");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_minimize,"_pi_window_minimize");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_restore,"_pi_window_restore");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_set_video_mode,"_pi_window_set_video_mode");
	HX_MARK_MEMBER_NAME(Window_obj::_pi_window_list_modes,"_pi_window_list_modes");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Window_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Window_obj::_windows,"_windows");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_create,"_pi_window_create");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_destroy,"_pi_window_destroy");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_set_visible,"_pi_window_set_visible");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_get_title,"_pi_window_get_title");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_set_title,"_pi_window_set_title");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_set_modality,"_pi_window_set_modality");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_set_fullscreen,"_pi_window_set_fullscreen");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_set_mode,"_pi_window_set_mode");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_move_rect,"_pi_window_move_rect");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_move_xy,"_pi_window_move_xy");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_get_pos,"_pi_window_get_pos");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_get_size,"_pi_window_get_size");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_resize_rect,"_pi_window_resize_rect");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_resize_wh,"_pi_window_resize_wh");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_maximize,"_pi_window_maximize");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_minimize,"_pi_window_minimize");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_restore,"_pi_window_restore");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_set_video_mode,"_pi_window_set_video_mode");
	HX_VISIT_MEMBER_NAME(Window_obj::_pi_window_list_modes,"_pi_window_list_modes");
};

Class Window_obj::__mClass;

void Window_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Window"), hx::TCanCast< Window_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Window_obj::__boot()
{
}

