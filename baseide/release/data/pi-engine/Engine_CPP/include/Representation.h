#ifndef INCLUDED_Representation
#define INCLUDED_Representation

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Representation)


class Representation_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Representation_obj OBJ_;
		Representation_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Representation_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Representation_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Representation"); }

};


#endif /* INCLUDED_Representation */ 
