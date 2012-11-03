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
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_Viewport
#include <Viewport.h>
#endif
#ifndef INCLUDED_Window
#include <Window.h>
#endif

Void Window_obj::__construct()
{
HX_STACK_PUSH("Window::new","Window.hx",23);
{
	HX_STACK_LINE(24)
	::Sys_obj::println(HX_CSTRING("NEW Window"));
	HX_STACK_LINE(25)
	if ((!(::Application_obj::isInitialized))){
		HX_STACK_LINE(27)
		::String msg = (HX_CSTRING("Cannot create window when the application is not initialized.") + HX_CSTRING("\nCall Application.init() first!"));		HX_STACK_VAR(msg,"msg");
		HX_STACK_LINE(30)
		hx::Throw (msg);
	}
	HX_STACK_LINE(32)
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

int Window_obj::_getId( ){
	HX_STACK_PUSH("Window::_getId","Window.hx",51);
	HX_STACK_THIS(this);
	HX_STACK_LINE(51)
	return this->id;
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,_getId,return )

Void Window_obj::setFullscreen( bool fullscreen){
{
		HX_STACK_PUSH("Window::setFullscreen","Window.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_ARG(fullscreen,"fullscreen");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,setFullscreen,(void))

Void Window_obj::setMode( bool mode){
{
		HX_STACK_PUSH("Window::setMode","Window.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mode,"mode");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,setMode,(void))

Void Window_obj::setModality( bool modal){
{
		HX_STACK_PUSH("Window::setModality","Window.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(modal,"modal");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,setModality,(void))

Array< ::Window > Window_obj::_windows;

Dynamic Window_obj::_pi_window_create;

Dynamic Window_obj::_pi_window_destroy;

Dynamic Window_obj::_pi_window_set_visible;

Dynamic Window_obj::_pi_window_get_title;

Dynamic Window_obj::_pi_window_set_title;

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
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(fullscreen,"fullscreen");
	HX_MARK_MEMBER_NAME(mode,"mode");
	HX_MARK_MEMBER_NAME(modal,"modal");
	HX_MARK_END_CLASS();
}

void Window_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(layers,"layers");
	HX_VISIT_MEMBER_NAME(viewports,"viewports");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(fullscreen,"fullscreen");
	HX_VISIT_MEMBER_NAME(mode,"mode");
	HX_VISIT_MEMBER_NAME(modal,"modal");
}

Dynamic Window_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return inCallProp ? _getId() : id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { return mode; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"modal") ) { return modal; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_getId") ) { return _getId_dyn(); }
		if (HX_FIELD_EQ(inName,"layers") ) { return layers; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setMode") ) { return setMode_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_windows") ) { return _windows; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"viewports") ) { return viewports; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fullscreen") ) { return fullscreen; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setModality") ) { return setModality_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setFullscreen") ) { return setFullscreen_dyn(); }
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
	case 25:
		if (HX_FIELD_EQ(inName,"_pi_window_set_video_mode") ) { return _pi_window_set_video_mode; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Window_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { mode=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"modal") ) { modal=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"layers") ) { layers=inValue.Cast< Array< ::Layer > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_windows") ) { _windows=inValue.Cast< Array< ::Window > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"viewports") ) { viewports=inValue.Cast< Array< ::Viewport > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fullscreen") ) { fullscreen=inValue.Cast< bool >(); return inValue; }
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
	case 25:
		if (HX_FIELD_EQ(inName,"_pi_window_set_video_mode") ) { _pi_window_set_video_mode=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Window_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("layers"));
	outFields->push(HX_CSTRING("viewports"));
	outFields->push(HX_CSTRING("id"));
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
	HX_CSTRING("_getId"),
	HX_CSTRING("setFullscreen"),
	HX_CSTRING("setMode"),
	HX_CSTRING("setModality"),
	HX_CSTRING("layers"),
	HX_CSTRING("viewports"),
	HX_CSTRING("id"),
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

