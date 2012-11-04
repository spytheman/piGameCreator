#ifndef INCLUDED_GameObject
#define INCLUDED_GameObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(GameObject)
HX_DECLARE_CLASS0(Representation)


class GameObject_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GameObject_obj OBJ_;
		GameObject_obj();
		Void __construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_z);

	public:
		static hx::ObjectPtr< GameObject_obj > __new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_z);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameObject"); }

		virtual Float _setZrot( Float zrot);
		Dynamic _setZrot_dyn();

		virtual Float _getZrot( );
		Dynamic _getZrot_dyn();

		::Representation representation; /* REM */ 
		virtual Void draw( );
		Dynamic draw_dyn();

		Float rotation; /* REM */ 
		Float zrot; /* REM */ 
		Float yrot; /* REM */ 
		Float xrot; /* REM */ 
		Float z; /* REM */ 
		Float y; /* REM */ 
		Float x; /* REM */ 
};


#endif /* INCLUDED_GameObject */ 
