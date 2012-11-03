#ifndef INCLUDED_Viewport
#define INCLUDED_Viewport

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Viewport)


class Viewport_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Viewport_obj OBJ_;
		Viewport_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Viewport_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Viewport_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Viewport"); }

};


#endif /* INCLUDED_Viewport */ 
