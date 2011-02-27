// generated by Fast Light User Interface Designer (fluid) version 1.0109

#ifndef nle_h
#define nle_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include "ProgressDialog/ProgressDialog.h"
#include "Renderer.H"
#include "Prefs.H"
#include "LoadSaveManager/LoadSaveManager.H"
#include "DocManager.H"
#include "Timeline.H"
#include "VideoTrack.H"
#include "AudioTrack.H"
#include "color_schemes.H"
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Group.H>
#include "VideoViewGL.H"
#include <FL/Fl_Slider.H>
#include "IPlaybackCore.H"
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include "MediaPanel.H"
#include "FilterScroll.H"
#include "FltkEffectMenu.H"
#include "SpecialClipsBrowser.H"
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <math.h>
#include <FL/fl_show_colormap.H>
#include "fl_font_browser.h"
#include <FL/Fl_Choice.H>
#include "Ruler.H"
#include <FL/Fl_Scrollbar.H>
#include "TimelineScroll.H"
#include "TimelineView.H"
#include "Flmm_Scalebar.H"
#include "globals.H"
using namespace std;
#include "SwitchBoard.H"

class NleUI {
public:
  NleUI();
  Fl_Double_Window *mainWindow;
private:
  void cb_mainWindow_i(Fl_Double_Window*, void*);
  static void cb_mainWindow(Fl_Double_Window*, void*);
  static Fl_Menu_Item menu_Black[];
  void cb_New_i(Fl_Menu_*, void*);
  static void cb_New(Fl_Menu_*, void*);
  void cb_Save_i(Fl_Menu_*, void*);
  static void cb_Save(Fl_Menu_*, void*);
  void cb_Render_i(Fl_Menu_*, void*);
  static void cb_Render(Fl_Menu_*, void*);
  void cb_Export_i(Fl_Menu_*, void*);
  static void cb_Export(Fl_Menu_*, void*);
  void cb_Export1_i(Fl_Menu_*, void*);
  static void cb_Export1(Fl_Menu_*, void*);
  void cb_Quit_i(Fl_Menu_*, void*);
  static void cb_Quit(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *undo_item;
private:
  void cb_undo_item_i(Fl_Menu_*, void*);
  static void cb_undo_item(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *redo_item;
private:
  void cb_redo_item_i(Fl_Menu_*, void*);
  static void cb_redo_item(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *cut_item;
private:
  void cb_cut_item_i(Fl_Menu_*, void*);
  static void cb_cut_item(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *copy_item;
private:
  void cb_copy_item_i(Fl_Menu_*, void*);
  static void cb_copy_item(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *paste_item;
private:
  void cb_paste_item_i(Fl_Menu_*, void*);
  static void cb_paste_item(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *delete_item;
private:
  void cb_delete_item_i(Fl_Menu_*, void*);
  static void cb_delete_item(Fl_Menu_*, void*);
  void cb_Add_i(Fl_Menu_*, void*);
  static void cb_Add(Fl_Menu_*, void*);
  void cb_Add1_i(Fl_Menu_*, void*);
  static void cb_Add1(Fl_Menu_*, void*);
  void cb_Add2_i(Fl_Menu_*, void*);
  static void cb_Add2(Fl_Menu_*, void*);
  void cb_Fullscreen_i(Fl_Menu_*, void*);
  static void cb_Fullscreen(Fl_Menu_*, void*);
  void cb_Normal_i(Fl_Menu_*, void*);
  static void cb_Normal(Fl_Menu_*, void*);
  void cb_Plastic_i(Fl_Menu_*, void*);
  static void cb_Plastic(Fl_Menu_*, void*);
  void cb_Shark_i(Fl_Menu_*, void*);
  static void cb_Shark(Fl_Menu_*, void*);
  void cb_Tutorial_i(Fl_Menu_*, void*);
  static void cb_Tutorial(Fl_Menu_*, void*);
  void cb_About_i(Fl_Menu_*, void*);
  static void cb_About(Fl_Menu_*, void*);
public:
  Fl_Tile *timeline_tile;
  Fl_Tile *preview_tile;
  Fl_Group *file_browser_tile_group;
  Fl_Group *m_video_view_group;
  nle::VideoViewGL *m_videoView;
  Fl_Slider *zoom_slider;
private:
  void cb_zoom_slider_i(Fl_Slider*, void*);
  static void cb_zoom_slider(Fl_Slider*, void*);
  void cb__i(Fl_Button*, void*);
  static void cb_(Fl_Button*, void*);
  void cb_9_i(Fl_Button*, void*);
  static void cb_9(Fl_Button*, void*);
public:
  Fl_Menu_Button *fps_pb_menu;
  static Fl_Menu_Item menu_fps_pb_menu[];
private:
  void cb_flexible_i(Fl_Menu_*, void*);
  static void cb_flexible(Fl_Menu_*, void*);
  void cb_25_i(Fl_Menu_*, void*);
  static void cb_25(Fl_Menu_*, void*);
  void cb_29_i(Fl_Menu_*, void*);
  static void cb_29(Fl_Menu_*, void*);
  void cb_24_i(Fl_Menu_*, void*);
  static void cb_24(Fl_Menu_*, void*);
  void cb_15_i(Fl_Menu_*, void*);
  static void cb_15(Fl_Menu_*, void*);
  void cb_50_i(Fl_Menu_*, void*);
  static void cb_50(Fl_Menu_*, void*);
  void cb_60_i(Fl_Menu_*, void*);
  static void cb_60(Fl_Menu_*, void*);
  static Fl_Menu_Item menu_Aspect[];
  void cb_4_i(Fl_Menu_*, void*);
  static void cb_4(Fl_Menu_*, void*);
  void cb_16_i(Fl_Menu_*, void*);
  static void cb_16(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *black_border_item;
private:
  void cb_black_border_item_i(Fl_Menu_*, void*);
  static void cb_black_border_item(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *black_border_item_2_35;
private:
  void cb_black_border_item_2_35_i(Fl_Menu_*, void*);
  static void cb_black_border_item_2_35(Fl_Menu_*, void*);
public:
  Fl_Box *m_timecode_box;
  Fl_Group *preview_tile_group;
  Fl_Tabs *tab_view;
  nle::FilterScroll *filter_scroll;
private:
  void cb_filter_scroll_i(nle::FilterScroll*, void*);
  static void cb_filter_scroll(nle::FilterScroll*, void*);
public:
  nle::FltkEffectMenu *m_effectMenu;
  nle::SpecialClipsBrowser *special_clips;
private:
  Fl_Group *titles_tab;
public:
  Fl_Input *titles_text;
private:
  void cb_titles_text_i(Fl_Input*, void*);
  static void cb_titles_text(Fl_Input*, void*);
public:
  Fl_Value_Input *titles_size;
private:
  void cb_titles_size_i(Fl_Value_Input*, void*);
  static void cb_titles_size(Fl_Value_Input*, void*);
public:
  Fl_Button *titles_color;
private:
  void cb_titles_color_i(Fl_Button*, void*);
  static void cb_titles_color(Fl_Button*, void*);
public:
  Fl_Slider *titles_x;
private:
  void cb_titles_x_i(Fl_Slider*, void*);
  static void cb_titles_x(Fl_Slider*, void*);
public:
  Fl_Slider *titles_y;
private:
  void cb_titles_y_i(Fl_Slider*, void*);
  static void cb_titles_y(Fl_Slider*, void*);
  void cb_Font_i(Fl_Button*, void*);
  static void cb_Font(Fl_Button*, void*);
public:
  Fl_Choice *titles_font;
private:
  void cb_titles_font_i(Fl_Choice*, void*);
  static void cb_titles_font(Fl_Choice*, void*);
  static Fl_Menu_Item menu_titles_font[];
public:
  Fl_Button *playButton;
private:
  void cb_playButton_i(Fl_Button*, void*);
  static void cb_playButton(Fl_Button*, void*);
public:
  Fl_Button *lastButton;
private:
  void cb_lastButton_i(Fl_Button*, void*);
  static void cb_lastButton(Fl_Button*, void*);
public:
  Fl_Button *firstButton;
private:
  void cb_firstButton_i(Fl_Button*, void*);
  static void cb_firstButton(Fl_Button*, void*);
public:
  Fl_Button *backButton;
private:
  void cb_backButton_i(Fl_Button*, void*);
  static void cb_backButton(Fl_Button*, void*);
public:
  Fl_Button *forwardButton;
private:
  void cb_forwardButton_i(Fl_Button*, void*);
  static void cb_forwardButton(Fl_Button*, void*);
public:
  Fl_Button *projectNameInput;
private:
  void cb_projectNameInput_i(Fl_Button*, void*);
  static void cb_projectNameInput(Fl_Button*, void*);
public:
  Fl_Group *timeline_tile_group;
private:
  void cb_1_i(Fl_Button*, void*);
  static void cb_1(Fl_Button*, void*);
  void cb_2_i(Fl_Button*, void*);
  static void cb_2(Fl_Button*, void*);
public:
  Fl_Scrollbar *vScrollBar;
private:
  void cb_vScrollBar_i(Fl_Scrollbar*, void*);
  static void cb_vScrollBar(Fl_Scrollbar*, void*);
public:
  nle::TimelineScroll *scroll_area;
private:
  void cb_scroll_area_i(nle::TimelineScroll*, void*);
  static void cb_scroll_area(nle::TimelineScroll*, void*);
public:
  nle::TimelineView *m_timelineView;
private:
  Flmm_Scalebar *scaleBar;
  void cb_scaleBar_i(Flmm_Scalebar*, void*);
  static void cb_scaleBar(Flmm_Scalebar*, void*);
public:
  Fl_Button *magnify_plus;
private:
  void cb_magnify_plus_i(Fl_Button*, void*);
  static void cb_magnify_plus(Fl_Button*, void*);
public:
  Fl_Button *magnify_minus;
private:
  void cb_magnify_minus_i(Fl_Button*, void*);
  static void cb_magnify_minus(Fl_Button*, void*);
public:
  Fl_Button *positioningButton;
  Fl_Button *automationsButton;
private:
  Fl_Box *trashCan;
public:
  Fl_Button *razorButton;
  Fl_Choice *projectChoice;
private:
  void cb_projectChoice_i(Fl_Choice*, void*);
  static void cb_projectChoice(Fl_Choice*, void*);
public:
  void show( int argc, char **argv );
  ~NleUI();
  int automationsMode();
  void deactivate_titles();
  void activate_titles(int font, int size, const char* text, float x, float y, Fl_Color color );
  void portaudio();
  void jack();
};
extern Flmm_Scalebar* g_scrollBar; 
#include <FL/Fl_Return_Button.H>

class ChangesDialog {
public:
  ChangesDialog();
};
extern Fl_Box *g_trashCan; 
extern float g_fps; 
#include "config.h"
#include <FL/Fl_Text_Display.H>

class AboutDialog {
public:
  AboutDialog();
  Fl_Double_Window *aboutDialog;
private:
  void cb_Close_i(Fl_Return_Button*, void*);
  static void cb_Close(Fl_Return_Button*, void*);
public:
  Fl_Box *version_box;
  Fl_Text_Display *system_info_display;
  void show();
  int shown();
  ~AboutDialog();
private:
  Fl_Text_Buffer buf; 
};
extern Fl_Button* g_playButton; 
extern Fl_Button* g_firstButton; 
extern Fl_Button* g_lastButton; 
extern Fl_Button* g_backButton; 
extern Fl_Button* g_forwardButton; 
extern bool g_snap; 
extern bool g_backseek; 
extern Fl_Scrollbar* g_v_scrollbar; 
extern bool g_16_9; 
extern bool g_black_borders; 
extern bool g_black_borders_2_35; 
void font_dialog_callback( Fl_Widget*, void* v );
extern Fl_Font titleFont; 
#include <FL/Fl_Browser.H>
#include <FL/Fl_File_Input.H>
extern Fl_File_Input *export_filename_simple;
#include <stdlib.h>
#include <FL/Fl_File_Chooser.H>
Fl_Double_Window* encoder_2_dlg();
extern Fl_Menu_Item menu_Framerate[];
extern Fl_Menu_Item menu_Framesize[];
extern Fl_Menu_Item menu_Samplerate[];
extern Fl_Menu_Item menu_Quality[];
extern Fl_Menu_Item menu_Aspect1[];
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

class SmilExportDialog {
public:
  SmilExportDialog();
  Fl_Double_Window *dialog_window;
  Fl_File_Input *export_filename;
private:
  void cb_File1_i(Fl_Button*, void*);
  static void cb_File1(Fl_Button*, void*);
public:
  Fl_Choice *track_choice;
private:
  void cb_Export2_i(Fl_Return_Button*, void*);
  static void cb_Export2(Fl_Return_Button*, void*);
  void cb_Cancel_i(Fl_Button*, void*);
  static void cb_Cancel(Fl_Button*, void*);
public:
  int shown();
  void show();
  ~SmilExportDialog();
};

class DvgrabImportDialog {
public:
  DvgrabImportDialog();
  Fl_Double_Window *dialog_window;
  ~DvgrabImportDialog();
};

class SrtExportDialog {
public:
  SrtExportDialog();
  Fl_Double_Window *dialog_window;
  Fl_File_Input *export_filename;
private:
  void cb_File2_i(Fl_Button*, void*);
  static void cb_File2(Fl_Button*, void*);
public:
  Fl_Choice *track_choice;
private:
  void cb_Export3_i(Fl_Return_Button*, void*);
  static void cb_Export3(Fl_Return_Button*, void*);
  void cb_Cancel1_i(Fl_Button*, void*);
  static void cb_Cancel1(Fl_Button*, void*);
public:
  int shown();
  void show();
  ~SrtExportDialog();
};
extern bool g_lock; 
#include <FL/Fl_Output.H>

class ClipInfoDialog {
public:
  ClipInfoDialog();
  Fl_Double_Window *dialog_window;
  Fl_Output *clip_filename_out;
  Fl_Output *clip_folder_out;
  Fl_Output *clip_decoder_out;
  Fl_Output *clip_framerate_out;
  Fl_Output *clip_aspect_out;
  Fl_Output *clip_interlacing_out;
private:
  void cb_Close1_i(Fl_Return_Button*, void*);
  static void cb_Close1(Fl_Return_Button*, void*);
public:
  ~ClipInfoDialog();
  void show();
  int shown();
  void set_info( const char* filename, const char* folder, const char* decoder, const char* framerate, const char* aspect, const char* interlacing );
};
std::string read_file_if_exists( const char* filename );
#endif
