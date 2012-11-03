#include <hxcpp.h>

#ifndef INCLUDED_Application
#include <Application.h>
#endif
#ifndef INCLUDED_WinDLLHost
#include <WinDLLHost.h>
#endif

Void WinDLLHost_obj::__construct()
{
	return null();
}

WinDLLHost_obj::~WinDLLHost_obj() { }

Dynamic WinDLLHost_obj::__CreateEmpty() { return  new WinDLLHost_obj; }
hx::ObjectPtr< WinDLLHost_obj > WinDLLHost_obj::__new()
{  hx::ObjectPtr< WinDLLHost_obj > result = new WinDLLHost_obj();
	result->__construct();
	return result;}

Dynamic WinDLLHost_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WinDLLHost_obj > result = new WinDLLHost_obj();
	result->__construct();
	return result;}

Void WinDLLHost_obj::main( ){
{
		HX_STACK_PUSH("WinDLLHost::main","WinDLLHost.hx",6);
		HX_STACK_LINE(7)
		::Application_obj::title = HX_CSTRING("pi|engine testing application");
		HX_STACK_LINE(9)
		::Application_obj::init();
		HX_STACK_LINE(10)
		::Application_obj::exec();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(WinDLLHost_obj,main,(void))


WinDLLHost_obj::WinDLLHost_obj()
{
}

void WinDLLHost_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WinDLLHost);
	HX_MARK_END_CLASS();
}

void WinDLLHost_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic WinDLLHost_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WinDLLHost_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void WinDLLHost_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WinDLLHost_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WinDLLHost_obj::__mClass,"__mClass");
};

Class WinDLLHost_obj::__mClass;

void WinDLLHost_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("WinDLLHost"), hx::TCanCast< WinDLLHost_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void WinDLLHost_obj::__boot()
{
}

