#include <hxcpp.h>

#ifndef INCLUDED_Shit
#include <Shit.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void Shit_obj::__construct()
{
HX_STACK_PUSH("Shit::new","Shit.hx",7);
{
}
;
	return null();
}

Shit_obj::~Shit_obj() { }

Dynamic Shit_obj::__CreateEmpty() { return  new Shit_obj; }
hx::ObjectPtr< Shit_obj > Shit_obj::__new()
{  hx::ObjectPtr< Shit_obj > result = new Shit_obj();
	result->__construct();
	return result;}

Dynamic Shit_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Shit_obj > result = new Shit_obj();
	result->__construct();
	return result;}

Void Shit_obj::shit( ){
{
		HX_STACK_PUSH("Shit::shit","Shit.hx",4);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4)
		::haxe::Log_obj::trace(HX_CSTRING("Shitting"),hx::SourceInfo(HX_CSTRING("Shit.hx"),5,HX_CSTRING("Shit"),HX_CSTRING("shit")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Shit_obj,shit,(void))


Shit_obj::Shit_obj()
{
}

void Shit_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Shit);
	HX_MARK_END_CLASS();
}

void Shit_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Shit_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"shit") ) { return shit_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Shit_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Shit_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("shit"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Shit_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Shit_obj::__mClass,"__mClass");
};

Class Shit_obj::__mClass;

void Shit_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Shit"), hx::TCanCast< Shit_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Shit_obj::__boot()
{
}

