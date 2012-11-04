#include <hxcpp.h>

#ifndef INCLUDED_GameObject
#include <GameObject.h>
#endif
#ifndef INCLUDED_Representation
#include <Representation.h>
#endif

Void GameObject_obj::__construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_z)
{
HX_STACK_PUSH("GameObject::new","GameObject.hx",35);
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
Float z = __o_z.Default(0);
{
	HX_STACK_LINE(36)
	this->x = x;
	HX_STACK_LINE(37)
	this->y = y;
	HX_STACK_LINE(38)
	this->z = z;
	HX_STACK_LINE(40)
	this->xrot = (int)0;
	HX_STACK_LINE(41)
	this->yrot = (int)0;
	HX_STACK_LINE(42)
	this->zrot = (int)0;
	HX_STACK_LINE(44)
	this->representation = null();
}
;
	return null();
}

GameObject_obj::~GameObject_obj() { }

Dynamic GameObject_obj::__CreateEmpty() { return  new GameObject_obj; }
hx::ObjectPtr< GameObject_obj > GameObject_obj::__new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_z)
{  hx::ObjectPtr< GameObject_obj > result = new GameObject_obj();
	result->__construct(__o_x,__o_y,__o_z);
	return result;}

Dynamic GameObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameObject_obj > result = new GameObject_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Float GameObject_obj::_setZrot( Float zrot){
	HX_STACK_PUSH("GameObject::_setZrot","GameObject.hx",31);
	HX_STACK_THIS(this);
	HX_STACK_ARG(zrot,"zrot");
	HX_STACK_LINE(31)
	this->zrot = zrot;
	HX_STACK_LINE(31)
	return this->zrot;
}


HX_DEFINE_DYNAMIC_FUNC1(GameObject_obj,_setZrot,return )

Float GameObject_obj::_getZrot( ){
	HX_STACK_PUSH("GameObject::_getZrot","GameObject.hx",30);
	HX_STACK_THIS(this);
	HX_STACK_LINE(30)
	return this->zrot;
}


HX_DEFINE_DYNAMIC_FUNC0(GameObject_obj,_getZrot,return )

Void GameObject_obj::draw( ){
{
		HX_STACK_PUSH("GameObject::draw","GameObject.hx",24);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameObject_obj,draw,(void))


GameObject_obj::GameObject_obj()
{
}

void GameObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameObject);
	HX_MARK_MEMBER_NAME(representation,"representation");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(zrot,"zrot");
	HX_MARK_MEMBER_NAME(yrot,"yrot");
	HX_MARK_MEMBER_NAME(xrot,"xrot");
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void GameObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(representation,"representation");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(zrot,"zrot");
	HX_VISIT_MEMBER_NAME(yrot,"yrot");
	HX_VISIT_MEMBER_NAME(xrot,"xrot");
	HX_VISIT_MEMBER_NAME(z,"z");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic GameObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"zrot") ) { return zrot; }
		if (HX_FIELD_EQ(inName,"yrot") ) { return yrot; }
		if (HX_FIELD_EQ(inName,"xrot") ) { return xrot; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_setZrot") ) { return _setZrot_dyn(); }
		if (HX_FIELD_EQ(inName,"_getZrot") ) { return _getZrot_dyn(); }
		if (HX_FIELD_EQ(inName,"rotation") ) { return inCallProp ? _getZrot() : rotation; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"representation") ) { return representation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"zrot") ) { zrot=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yrot") ) { yrot=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xrot") ) { xrot=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { if (inCallProp) return _setZrot(inValue);rotation=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"representation") ) { representation=inValue.Cast< ::Representation >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("representation"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("zrot"));
	outFields->push(HX_CSTRING("yrot"));
	outFields->push(HX_CSTRING("xrot"));
	outFields->push(HX_CSTRING("z"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_setZrot"),
	HX_CSTRING("_getZrot"),
	HX_CSTRING("representation"),
	HX_CSTRING("draw"),
	HX_CSTRING("rotation"),
	HX_CSTRING("zrot"),
	HX_CSTRING("yrot"),
	HX_CSTRING("xrot"),
	HX_CSTRING("z"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameObject_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameObject_obj::__mClass,"__mClass");
};

Class GameObject_obj::__mClass;

void GameObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("GameObject"), hx::TCanCast< GameObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GameObject_obj::__boot()
{
}

