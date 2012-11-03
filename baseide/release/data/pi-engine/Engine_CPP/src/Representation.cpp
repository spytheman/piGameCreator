#include <hxcpp.h>

#ifndef INCLUDED_Representation
#include <Representation.h>
#endif

Void Representation_obj::__construct()
{
HX_STACK_PUSH("Representation::new","Representation.hx",4);
{
}
;
	return null();
}

Representation_obj::~Representation_obj() { }

Dynamic Representation_obj::__CreateEmpty() { return  new Representation_obj; }
hx::ObjectPtr< Representation_obj > Representation_obj::__new()
{  hx::ObjectPtr< Representation_obj > result = new Representation_obj();
	result->__construct();
	return result;}

Dynamic Representation_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Representation_obj > result = new Representation_obj();
	result->__construct();
	return result;}


Representation_obj::Representation_obj()
{
}

void Representation_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Representation);
	HX_MARK_END_CLASS();
}

void Representation_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Representation_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Representation_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Representation_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Representation_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Representation_obj::__mClass,"__mClass");
};

Class Representation_obj::__mClass;

void Representation_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Representation"), hx::TCanCast< Representation_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Representation_obj::__boot()
{
}

