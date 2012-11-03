#ifndef INCLUDED_Window
#define INCLUDED_Window

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Layer)
HX_DECLARE_CLASS0(Viewport)
HX_DECLARE_CLASS0(Window)


class Window_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Window_obj OBJ_;
		Window_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Window_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Window_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Window"); }

		virtual Void setFullscreen( bool fullscreen);
		Dynamic setFullscreen_dyn();

		virtual Void setMode( bool mode);
		Dynamic setMode_dyn();

		virtual Void setModality( bool modal);
		Dynamic setModality_dyn();

		Array< ::Layer > layers; /* REM */ 
		Array< ::Viewport > viewports; /* REM */ 
		bool fullscreen; /* REM */ 
		int mode; /* REM */ 
		bool modal; /* REM */ 
};


#endif /* INCLUDED_Window */ 
