#ifndef INCLUDED_Application
#define INCLUDED_Application

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Application)


class Application_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Application_obj OBJ_;
		Application_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Application_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Application_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Application"); }

		static int shit; /* REM */ 
		static ::String title; /* REM */ 
		static ::String author; /* REM */ 
		static ::String description; /* REM */ 
		static ::String organization; /* REM */ 
		static ::String url; /* REM */ 
		static ::String version; /* REM */ 
		static bool debugMode; /* REM */ 
		static bool _gDebugMode( );
		static Dynamic _gDebugMode_dyn();

		static bool serverMode; /* REM */ 
		static bool devMode; /* REM */ 
		static bool isInitialized; /* REM */ 
		static Void init( );
		static Dynamic init_dyn();

		static Void exec( );
		static Dynamic exec_dyn();

		static Array< ::String > args( );
		static Dynamic args_dyn();

		static Void terminate( hx::Null< int >  exitCode);
		static Dynamic terminate_dyn();

		static Dynamic _pi_query_system_info; /* REM */ 
		static Dynamic &_pi_query_system_info_dyn() { return _pi_query_system_info;}
		static Dynamic _pi_init_control_thread; /* REM */ 
		static Dynamic &_pi_init_control_thread_dyn() { return _pi_init_control_thread;}
		static Void pause( );
		static Dynamic pause_dyn();

};


#endif /* INCLUDED_Application */ 
