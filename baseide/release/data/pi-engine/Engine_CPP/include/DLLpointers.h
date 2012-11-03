#ifndef INCLUDED_DLLpointers
#define INCLUDED_DLLpointers

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(DLLpointers)


class DLLpointers_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DLLpointers_obj OBJ_;
		DLLpointers_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DLLpointers_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DLLpointers_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DLLpointers"); }

		static Dynamic pi_query_system_info; /* REM */ 
		static Dynamic &pi_query_system_info_dyn() { return pi_query_system_info;}
};


#endif /* INCLUDED_DLLpointers */ 
