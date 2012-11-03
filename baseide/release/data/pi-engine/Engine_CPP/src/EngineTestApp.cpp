#include <hxcpp.h>

#ifndef INCLUDED_Application
#include <Application.h>
#endif
#ifndef INCLUDED_EngineTestApp
#include <EngineTestApp.h>
#endif
#ifndef INCLUDED_GameObject
#include <GameObject.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void EngineTestApp_obj::__construct()
{
	return null();
}

EngineTestApp_obj::~EngineTestApp_obj() { }

Dynamic EngineTestApp_obj::__CreateEmpty() { return  new EngineTestApp_obj; }
hx::ObjectPtr< EngineTestApp_obj > EngineTestApp_obj::__new()
{  hx::ObjectPtr< EngineTestApp_obj > result = new EngineTestApp_obj();
	result->__construct();
	return result;}

Dynamic EngineTestApp_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EngineTestApp_obj > result = new EngineTestApp_obj();
	result->__construct();
	return result;}

Void EngineTestApp_obj::main( ){
{
		HX_STACK_PUSH("EngineTestApp::main","EngineTestApp.hx",6);
		HX_STACK_LINE(7)
		::Application_obj::title = HX_CSTRING("pi|engine testing application");
		HX_STACK_LINE(9)
		::Application_obj::init();
		HX_STACK_LINE(11)
		::GameObject o;		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(12)
		o = ::GameObject_obj::__new(null(),null(),null());
		HX_STACK_LINE(13)
		o->zrot = (int)10;
		HX_STACK_LINE(14)
		::haxe::Log_obj::trace(o->_getZrot(),hx::SourceInfo(HX_CSTRING("EngineTestApp.hx"),14,HX_CSTRING("EngineTestApp"),HX_CSTRING("main")));
		HX_STACK_LINE(15)
		o->_setZrot((int)50);
		HX_STACK_LINE(16)
		::haxe::Log_obj::trace(o->zrot,hx::SourceInfo(HX_CSTRING("EngineTestApp.hx"),16,HX_CSTRING("EngineTestApp"),HX_CSTRING("main")));
		HX_STACK_LINE(18)
		::Application_obj::exec();
		HX_STACK_LINE(19)
		::Application_obj::pause();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(EngineTestApp_obj,main,(void))


EngineTestApp_obj::EngineTestApp_obj()
{
}

void EngineTestApp_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EngineTestApp);
	HX_MARK_END_CLASS();
}

void EngineTestApp_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic EngineTestApp_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EngineTestApp_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void EngineTestApp_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EngineTestApp_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EngineTestApp_obj::__mClass,"__mClass");
};

Class EngineTestApp_obj::__mClass;

void EngineTestApp_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("EngineTestApp"), hx::TCanCast< EngineTestApp_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EngineTestApp_obj::__boot()
{
}

