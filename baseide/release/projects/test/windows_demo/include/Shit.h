#ifndef INCLUDED_Shit
#define INCLUDED_Shit

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Shit)


class Shit_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Shit_obj OBJ_;
		Shit_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Shit_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Shit_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Shit"); }

		virtual Void shit( );
		Dynamic shit_dyn();

};


#endif /* INCLUDED_Shit */ 
