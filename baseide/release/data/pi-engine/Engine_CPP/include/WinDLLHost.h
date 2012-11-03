#ifndef INCLUDED_WinDLLHost
#define INCLUDED_WinDLLHost

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(WinDLLHost)


class WinDLLHost_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef WinDLLHost_obj OBJ_;
		WinDLLHost_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< WinDLLHost_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~WinDLLHost_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("WinDLLHost"); }

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_WinDLLHost */ 
