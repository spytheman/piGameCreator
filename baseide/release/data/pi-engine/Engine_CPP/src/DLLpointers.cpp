#include <hxcpp.h>

#ifndef INCLUDED_DLLpointers
#include <DLLpointers.h>
#endif

Void DLLpointers_obj::__construct()
{
	return null();
}

DLLpointers_obj::~DLLpointers_obj() { }

Dynamic DLLpointers_obj::__CreateEmpty() { return  new DLLpointers_obj; }
hx::ObjectPtr< DLLpointers_obj > DLLpointers_obj::__new()
{  hx::ObjectPtr< DLLpointers_obj > result = new DLLpointers_obj();
	result->__construct();
	return result;}

Dynamic DLLpointers_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DLLpointers_obj > result = new DLLpointers_obj();
	result->__construct();
	return result;}

Dynamic DLLpointers_obj::pi_query_system_info;


DLLpointers_obj::DLLpointers_obj()
{
}

void DLLpointers_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DLLpointers);
	HX_MARK_END_CLASS();
}

void DLLpointers_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic DLLpointers_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"pi_query_system_info") ) { return pi_query_system_info; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DLLpointers_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"pi_query_system_info") ) { pi_query_system_info=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DLLpointers_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("pi_query_system_info"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DLLpointers_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DLLpointers_obj::pi_query_system_info,"pi_query_system_info");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DLLpointers_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DLLpointers_obj::pi_query_system_info,"pi_query_system_info");
};

Class DLLpointers_obj::__mClass;

void DLLpointers_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("DLLpointers"), hx::TCanCast< DLLpointers_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DLLpointers_obj::__boot()
{
}

