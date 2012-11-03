#include <hxcpp.h>

#ifndef INCLUDED_Layer
#include <Layer.h>
#endif

Void Layer_obj::__construct()
{
HX_STACK_PUSH("Layer::new","Layer.hx",4);
{
}
;
	return null();
}

Layer_obj::~Layer_obj() { }

Dynamic Layer_obj::__CreateEmpty() { return  new Layer_obj; }
hx::ObjectPtr< Layer_obj > Layer_obj::__new()
{  hx::ObjectPtr< Layer_obj > result = new Layer_obj();
	result->__construct();
	return result;}

Dynamic Layer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Layer_obj > result = new Layer_obj();
	result->__construct();
	return result;}


Layer_obj::Layer_obj()
{
}

void Layer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Layer);
	HX_MARK_END_CLASS();
}

void Layer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Layer_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Layer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Layer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Layer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Layer_obj::__mClass,"__mClass");
};

Class Layer_obj::__mClass;

void Layer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Layer"), hx::TCanCast< Layer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Layer_obj::__boot()
{
}

