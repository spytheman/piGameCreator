#ifndef INCLUDED_EngineTestApp
#define INCLUDED_EngineTestApp

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EngineTestApp)


class EngineTestApp_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EngineTestApp_obj OBJ_;
		EngineTestApp_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EngineTestApp_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EngineTestApp_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EngineTestApp"); }

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_EngineTestApp */ 
