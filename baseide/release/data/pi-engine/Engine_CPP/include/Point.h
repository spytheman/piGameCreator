#ifndef INCLUDED_Point
#define INCLUDED_Point

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Point)


class Point_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Point_obj OBJ_;
		Point_obj();
		Void __construct(Dynamic __o_X,Dynamic __o_Y,Dynamic __o_Z);

	public:
		static hx::ObjectPtr< Point_obj > __new(Dynamic __o_X,Dynamic __o_Y,Dynamic __o_Z);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Point_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Point"); }

		static Float x; /* REM */ 
		static Float y; /* REM */ 
		static Float z; /* REM */ 
};


#endif /* INCLUDED_Point */ 
