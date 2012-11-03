#include <hxcpp.h>

#ifndef INCLUDED_Point
#include <Point.h>
#endif

Void Point_obj::__construct(Dynamic __o_X,Dynamic __o_Y,Dynamic __o_Z)
{
HX_STACK_PUSH("Point::new","Point.hx",8);
Dynamic X = __o_X.Default(0);
Dynamic Y = __o_Y.Default(0);
Dynamic Z = __o_Z.Default(0);
{
	HX_STACK_LINE(9)
	::Point_obj::x = X;
	HX_STACK_LINE(10)
	::Point_obj::y = Y;
	HX_STACK_LINE(11)
	::Point_obj::z = Z;
}
;
	return null();
}

Point_obj::~Point_obj() { }

Dynamic Point_obj::__CreateEmpty() { return  new Point_obj; }
hx::ObjectPtr< Point_obj > Point_obj::__new(Dynamic __o_X,Dynamic __o_Y,Dynamic __o_Z)
{  hx::ObjectPtr< Point_obj > result = new Point_obj();
	result->__construct(__o_X,__o_Y,__o_Z);
	return result;}

Dynamic Point_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Point_obj > result = new Point_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Float Point_obj::x;

Float Point_obj::y;

Float Point_obj::z;


Point_obj::Point_obj()
{
}

void Point_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Point);
	HX_MARK_END_CLASS();
}

void Point_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Point_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Point_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Point_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("z"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Point_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Point_obj::x,"x");
	HX_MARK_MEMBER_NAME(Point_obj::y,"y");
	HX_MARK_MEMBER_NAME(Point_obj::z,"z");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Point_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Point_obj::x,"x");
	HX_VISIT_MEMBER_NAME(Point_obj::y,"y");
	HX_VISIT_MEMBER_NAME(Point_obj::z,"z");
};

Class Point_obj::__mClass;

void Point_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Point"), hx::TCanCast< Point_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Point_obj::__boot()
{
}

