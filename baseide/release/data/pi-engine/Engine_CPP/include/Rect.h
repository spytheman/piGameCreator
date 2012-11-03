#ifndef INCLUDED_Rect
#define INCLUDED_Rect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Rect)


class Rect_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Rect_obj OBJ_;
		Rect_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Rect_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Rect_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Rect"); }

		virtual Float area( );
		Dynamic area_dyn();

		Float height; /* REM */ 
		Float width; /* REM */ 
};


#endif /* INCLUDED_Rect */ 
