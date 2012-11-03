#ifndef INCLUDED_Layer
#define INCLUDED_Layer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Layer)


class Layer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Layer_obj OBJ_;
		Layer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Layer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Layer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Layer"); }

};


#endif /* INCLUDED_Layer */ 
