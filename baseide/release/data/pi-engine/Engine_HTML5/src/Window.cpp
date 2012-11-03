#include <hxcpp.h>

#ifndef INCLUDED_Application
#include <Application.h>
#endif
#ifndef INCLUDED_Layer
#include <Layer.h>
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
HX_STACK_PUSH("Window::new","Window.hx",19);
{
	HX_STACK_LINE(20)
	::Sys_obj::println(HX_CSTRING("NEW Window"));
	HX_STACK_LINE(21)
	if ((!(::Application_obj::isInitialized))){
		HX_STACK_LINE(23)
		::String msg = (HX_CSTRING("Cannot create window when the application is not initialized.") + HX_CSTRING("\nCall Application.init() first!"));		HX_STACK_VAR(msg,"msg");
		HX_STACK_LINE(27)
		::Sys_obj::println(msg);
		HX_STACK_LINE(28)
		::Sys_obj::command(HX_CSTRING("pause"),null());
		HX_STACK_LINE(29)
		hx::Throw (msg);
	}
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

Void Window_obj::setFullscreen( bool fullscreen){
{
		HX_STACK_PUSH("Window::setFullscreen","Window.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_ARG(fullscreen,"fullscreen");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,setFullscreen,(void))

Void Window_obj::setMode( bool mode){
{
		HX_STACK_PUSH("Window::setMode","Window.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mode,"mode");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,setMode,(void))

Void Window_obj::setModality( bool modal){
{
		HX_STACK_PUSH("Window::setModality","Window.hx",35);
		HX_STACK_THIS(this);
		HX_STACK_ARG(modal,"modal");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,setModality,(void))


Window_obj::Window_obj()
{
}

void Window_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Window);
	HX_MARK_MEMBER_NAME(layers,"layers");
	HX_MARK_MEMBER_NAME(viewports,"viewports");
	HX_MARK_MEMBER_NAME(fullscreen,"fullscreen");
	HX_MARK_MEMBER_NAME(mode,"mode");
	HX_MARK_MEMBER_NAME(modal,"modal");
	HX_MARK_END_CLASS();
}

void Window_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(layers,"layers");
	HX_VISIT_MEMBER_NAME(viewports,"viewports");
	HX_VISIT_MEMBER_NAME(fullscreen,"fullscreen");
	HX_VISIT_MEMBER_NAME(mode,"mode");
	HX_VISIT_MEMBER_NAME(modal,"modal");
}

Dynamic Window_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { return mode; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"modal") ) { return modal; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"layers") ) { return layers; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setMode") ) { return setMode_dyn(); }
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
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Window_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { mode=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"modal") ) { modal=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"layers") ) { layers=inValue.Cast< Array< ::Layer > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"viewports") ) { viewports=inValue.Cast< Array< ::Viewport > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fullscreen") ) { fullscreen=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Window_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("layers"));
	outFields->push(HX_CSTRING("viewports"));
	outFields->push(HX_CSTRING("fullscreen"));
	outFields->push(HX_CSTRING("mode"));
	outFields->push(HX_CSTRING("modal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setFullscreen"),
	HX_CSTRING("setMode"),
	HX_CSTRING("setModality"),
	HX_CSTRING("layers"),
	HX_CSTRING("viewports"),
	HX_CSTRING("fullscreen"),
	HX_CSTRING("mode"),
	HX_CSTRING("modal"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Window_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Window_obj::__mClass,"__mClass");
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

