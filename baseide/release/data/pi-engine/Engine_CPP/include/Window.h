#ifndef INCLUDED_Window
#define INCLUDED_Window

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Layer)
HX_DECLARE_CLASS0(Point)
HX_DECLARE_CLASS0(Rect)
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

		virtual ::String _setTitle( ::String title);
		Dynamic _setTitle_dyn();

		virtual bool _setFullscreen( bool fullscreen);
		Dynamic _setFullscreen_dyn();

		virtual int _setMode( int mode);
		Dynamic _setMode_dyn();

		virtual bool _setModality( bool modal);
		Dynamic _setModality_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual Void hide( );
		Dynamic hide_dyn();

		virtual Void open( );
		Dynamic open_dyn();

		virtual Void show( );
		Dynamic show_dyn();

		Array< ::Layer > layers; /* REM */ 
		Array< ::Viewport > viewports; /* REM */ 
		int nativeId; /* REM */ 
		::String title; /* REM */ 
		bool fullscreen; /* REM */ 
		int mode; /* REM */ 
		bool modal; /* REM */ 
		static Array< ::Window > _windows; /* REM */ 
		static Dynamic _pi_window_create; /* REM */ 
		static Dynamic &_pi_window_create_dyn() { return _pi_window_create;}
		static Dynamic _pi_window_destroy; /* REM */ 
		static Dynamic &_pi_window_destroy_dyn() { return _pi_window_destroy;}
		static Dynamic _pi_window_set_visible; /* REM */ 
		static Dynamic &_pi_window_set_visible_dyn() { return _pi_window_set_visible;}
		static Dynamic _pi_window_get_title; /* REM */ 
		static Dynamic &_pi_window_get_title_dyn() { return _pi_window_get_title;}
		static Dynamic _pi_window_set_title; /* REM */ 
		static Dynamic &_pi_window_set_title_dyn() { return _pi_window_set_title;}
		static Dynamic _pi_window_set_modality; /* REM */ 
		static Dynamic &_pi_window_set_modality_dyn() { return _pi_window_set_modality;}
		static Dynamic _pi_window_set_fullscreen; /* REM */ 
		static Dynamic &_pi_window_set_fullscreen_dyn() { return _pi_window_set_fullscreen;}
		static Dynamic _pi_window_set_mode; /* REM */ 
		static Dynamic &_pi_window_set_mode_dyn() { return _pi_window_set_mode;}
		static Dynamic _pi_window_move_rect; /* REM */ 
		static Dynamic &_pi_window_move_rect_dyn() { return _pi_window_move_rect;}
		static Dynamic _pi_window_move_xy; /* REM */ 
		static Dynamic &_pi_window_move_xy_dyn() { return _pi_window_move_xy;}
		static Dynamic _pi_window_get_pos; /* REM */ 
		static Dynamic &_pi_window_get_pos_dyn() { return _pi_window_get_pos;}
		static Dynamic _pi_window_get_size; /* REM */ 
		static Dynamic &_pi_window_get_size_dyn() { return _pi_window_get_size;}
		static Dynamic _pi_window_resize_rect; /* REM */ 
		static Dynamic &_pi_window_resize_rect_dyn() { return _pi_window_resize_rect;}
		static Dynamic _pi_window_resize_wh; /* REM */ 
		static Dynamic &_pi_window_resize_wh_dyn() { return _pi_window_resize_wh;}
		static Dynamic _pi_window_maximize; /* REM */ 
		static Dynamic &_pi_window_maximize_dyn() { return _pi_window_maximize;}
		static Dynamic _pi_window_minimize; /* REM */ 
		static Dynamic &_pi_window_minimize_dyn() { return _pi_window_minimize;}
		static Dynamic _pi_window_restore; /* REM */ 
		static Dynamic &_pi_window_restore_dyn() { return _pi_window_restore;}
		static Dynamic _pi_window_set_video_mode; /* REM */ 
		static Dynamic &_pi_window_set_video_mode_dyn() { return _pi_window_set_video_mode;}
		static Dynamic _pi_window_list_modes; /* REM */ 
		static Dynamic &_pi_window_list_modes_dyn() { return _pi_window_list_modes;}
};


#endif /* INCLUDED_Window */ 
