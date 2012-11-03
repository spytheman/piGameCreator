#include <hxcpp.h>

#ifndef INCLUDED_Rect
#include <Rect.h>
#endif

Void Rect_obj::__construct()
{
HX_STACK_PUSH("Rect::new","Rect.hx",10);
{
	HX_STACK_LINE(11)
	this->width = (int)0;
	HX_STACK_LINE(12)
	this->height = (int)0;
}
;
	return null();
}

Rect_obj::~Rect_obj() { }

Dynamic Rect_obj::__CreateEmpty() { return  new Rect_obj; }
hx::ObjectPtr< Rect_obj > Rect_obj::__new()
{  hx::ObjectPtr< Rect_obj > result = new Rect_obj();
	result->__construct();
	return result;}

Dynamic Rect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rect_obj > result = new Rect_obj();
	result->__construct();
	return result;}

Float Rect_obj::area( ){
	HX_STACK_PUSH("Rect::area","Rect.hx",16);
	HX_STACK_THIS(this);
	HX_STACK_LINE(16)
	return (this->width * this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rect_obj,area,return )


Rect_obj::Rect_obj()
{
}

void Rect_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Rect);
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_END_CLASS();
}

void Rect_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
}

Dynamic Rect_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"area") ) { return area_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Rect_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Rect_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("area"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Rect_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Rect_obj::__mClass,"__mClass");
};

Class Rect_obj::__mClass;

void Rect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Rect"), hx::TCanCast< Rect_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Rect_obj::__boot()
{
}

