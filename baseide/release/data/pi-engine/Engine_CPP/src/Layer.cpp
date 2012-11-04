#include <hxcpp.h>

#ifndef INCLUDED_GameObject
#include <GameObject.h>
#endif
#ifndef INCLUDED_Layer
#include <Layer.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void Layer_obj::__construct()
{
HX_STACK_PUSH("Layer::new","Layer.hx",31);
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

Void Layer_obj::draw( ){
{
		HX_STACK_PUSH("Layer::draw","Layer.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_LINE(27)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::GameObject > _g1 = this->objects;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(27)
		while(((_g < _g1->length))){
			HX_STACK_LINE(27)
			::GameObject o = _g1->__get(_g);		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(27)
			++(_g);
			HX_STACK_LINE(27)
			o->draw();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Layer_obj,draw,(void))

Void Layer_obj::step( ){
{
		HX_STACK_PUSH("Layer::step","Layer.hx",22);
		HX_STACK_THIS(this);
		HX_STACK_LINE(22)
		::haxe::Log_obj::trace(HX_CSTRING("How to actually do this STEP?? TODO: Plan the final version!"),hx::SourceInfo(HX_CSTRING("Layer.hx"),23,HX_CSTRING("Layer"),HX_CSTRING("step")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Layer_obj,step,(void))

bool Layer_obj::_setActive( bool active){
	HX_STACK_PUSH("Layer::_setActive","Layer.hx",10);
	HX_STACK_THIS(this);
	HX_STACK_ARG(active,"active");
	HX_STACK_LINE(10)
	return active;
}


HX_DEFINE_DYNAMIC_FUNC1(Layer_obj,_setActive,return )

Array< ::Layer > Layer_obj::availableLayers;

Array< ::Layer > Layer_obj::activeLayers;


Layer_obj::Layer_obj()
{
}

void Layer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Layer);
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(isLoaded,"isLoaded");
	HX_MARK_MEMBER_NAME(objects,"objects");
	HX_MARK_MEMBER_NAME(layers,"layers");
	HX_MARK_END_CLASS();
}

void Layer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(active,"active");
	HX_VISIT_MEMBER_NAME(isLoaded,"isLoaded");
	HX_VISIT_MEMBER_NAME(objects,"objects");
	HX_VISIT_MEMBER_NAME(layers,"layers");
}

Dynamic Layer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		if (HX_FIELD_EQ(inName,"layers") ) { return layers; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"objects") ) { return objects; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isLoaded") ) { return isLoaded; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_setActive") ) { return _setActive_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"activeLayers") ) { return activeLayers; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"availableLayers") ) { return availableLayers; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Layer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { if (inCallProp) return _setActive(inValue);active=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"layers") ) { layers=inValue.Cast< Array< ::Layer > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"objects") ) { objects=inValue.Cast< Array< ::GameObject > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isLoaded") ) { isLoaded=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"activeLayers") ) { activeLayers=inValue.Cast< Array< ::Layer > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"availableLayers") ) { availableLayers=inValue.Cast< Array< ::Layer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Layer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("isLoaded"));
	outFields->push(HX_CSTRING("objects"));
	outFields->push(HX_CSTRING("layers"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("availableLayers"),
	HX_CSTRING("activeLayers"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("draw"),
	HX_CSTRING("step"),
	HX_CSTRING("_setActive"),
	HX_CSTRING("active"),
	HX_CSTRING("isLoaded"),
	HX_CSTRING("objects"),
	HX_CSTRING("layers"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Layer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Layer_obj::availableLayers,"availableLayers");
	HX_MARK_MEMBER_NAME(Layer_obj::activeLayers,"activeLayers");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Layer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Layer_obj::availableLayers,"availableLayers");
	HX_VISIT_MEMBER_NAME(Layer_obj::activeLayers,"activeLayers");
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

