// generated by Fast Light User Interface Designer (fluid) version 1.0109

#include "RenderDialog.H"
#include "VideoWriterQT.H"
#include "EncodingPreset.H"
#include "helper.H"
#include <tinyxml.h>

void RenderDialog::cb_File_i(Fl_Button*, void*) {
  export_filename->value( fl_file_chooser( "Set Export Filename", 0, 0 ) );
}
void RenderDialog::cb_File(Fl_Button* o, void* v) {
  ((RenderDialog*)(o->parent()->user_data()))->cb_File_i(o,v);
}

void RenderDialog::cb_Encode_i(Fl_Return_Button* o, void*) {
  if ( strcmp( "", export_filename->value() ) == 0 ) {
	fl_alert( "Please select a filename." );
	return;
}




if ( presets_browser->value() == 0 ) {
	fl_alert( "Please select a Format Preset." );
	return;
}



nle::EncodingPreset* preset = (nle::EncodingPreset*)presets_browser->data(presets_browser->value());

#if (LQT_CODEC_API_VERSION & 0xffff) > 6
char buffer[FL_PATH_MAX];
strncpy( buffer, export_filename->value(), FL_PATH_MAX );
buffer[FL_PATH_MAX-1] = '\0';
switch ( preset->m_file_type ) {
	case LQT_FILE_QT:
		fl_filename_setext( buffer, ".mov" );
		break;
	case LQT_FILE_AVI_ODML:
		fl_filename_setext( buffer, ".avi" );
		break;
	case LQT_FILE_MP4:
		fl_filename_setext( buffer, ".mp4" );
		break;
	case LQT_FILE_3GP:
		fl_filename_setext( buffer, ".3gp" );
		break;
}
export_filename->value( buffer );
#endif

struct stat statbuf;
int r = stat( export_filename->value(), &statbuf );
if ( r == 0 ) {
	r = fl_choice( "File exists, replace?\nWill be overwritten.", "&Cancel", "&Replace", 0 );
	if ( r == 0 ) {
		return;
	}
}


go = true;
o->window()->hide();
}
void RenderDialog::cb_Encode(Fl_Return_Button* o, void* v) {
  ((RenderDialog*)(o->parent()->user_data()))->cb_Encode_i(o,v);
}

void RenderDialog::cb_Cancel_i(Fl_Button* o, void*) {
  go = false;
o->window()->hide();
}
void RenderDialog::cb_Cancel(Fl_Button* o, void* v) {
  ((RenderDialog*)(o->parent()->user_data()))->cb_Cancel_i(o,v);
}

void RenderDialog::cb_presets_browser_i(Fl_Hold_Browser* o, void*) {
  if ( o->value() > 0 ) {
	information_display->buffer()->text(o->text(o->value()));
	nle::EncodingPreset* preset = (nle::EncodingPreset*)presets_browser->data(presets_browser->value());
	char buffer[256];
	if (preset) {
		nle::video_format fmt;
		preset->getFormat(&fmt);
		snprintf( buffer, 256, "\n%dx%d, %.4f, %.2f fps\n", fmt.w, fmt.h, fmt.pixel_aspect_ratio, ((float)fmt.framerate.timescale/fmt.framerate.frame_duration) );
		information_display->buffer()->append(buffer);
		snprintf(buffer, 256, "Video: %s\nAudio: %s, %d\n", fmt.video_codec, fmt.audio_codec, fmt.samplerate );
		information_display->buffer()->append(buffer);
		switch (fmt.interlacing) {
			case 1:
				information_display->buffer()->append("Top field first");
				break;
			case 2:
				information_display->buffer()->append("Bottom field first");
				break;
		}
		if ( preset->m_readonly ) {
			remove_format_button->deactivate();
			edit_format_button->deactivate();
		} else {
			remove_format_button->activate();
			edit_format_button->activate();
		}
	} else {
		remove_format_button->deactivate();
		edit_format_button->deactivate();
	} 
	
} else {
	remove_format_button->deactivate();
	edit_format_button->deactivate();
};
}
void RenderDialog::cb_presets_browser(Fl_Hold_Browser* o, void* v) {
  ((RenderDialog*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_presets_browser_i(o,v);
}

void RenderDialog::cb__i(Fl_Button*, void*) {
  CustomFormatDialog dlg;
dlg.show();
while (dlg.shown())
  Fl::wait();
  
nle::EncodingPreset* preset = dlg.getEncodingPreset();


if ( preset ) {
	nle::video_format fmt;
	preset->getFormat(&fmt);
	presets_browser->add(fmt.name, preset);
};
}
void RenderDialog::cb_(Fl_Button* o, void* v) {
  ((RenderDialog*)(o->parent()->parent()->parent()->parent()->parent()->user_data()))->cb__i(o,v);
}

void RenderDialog::cb_edit_format_button_i(Fl_Button*, void*) {
  CustomFormatDialog dlg;

nle::EncodingPreset* preset = (nle::EncodingPreset*)presets_browser->data(presets_browser->value());

dlg.setEncodingPreset(preset);
if ( !preset ) {
	return;
}

dlg.show();
while (dlg.shown())
  Fl::wait();


nle::EncodingPreset* preset_new = dlg.getEncodingPreset();


if ( preset_new ) {
	nle::video_format fmt;
	preset_new->getFormat(&fmt);
	delete preset;
	
	presets_browser->data(presets_browser->value(), preset_new);
	presets_browser->text(presets_browser->value(), fmt.name);
	
	
	char buffer[256];
	information_display->buffer()->text(fmt.name);
	snprintf( buffer, 256, "\n%dx%d, %.4f, %.2f fps\n", fmt.w, fmt.h, fmt.pixel_aspect_ratio, ((float)fmt.framerate.timescale/fmt.framerate.frame_duration) );
	information_display->buffer()->append(buffer);
	snprintf(buffer, 256, "Video: %s\nAudio: %s, %d\n", fmt.video_codec, fmt.audio_codec, fmt.samplerate );
	information_display->buffer()->append(buffer);
	switch (fmt.interlacing) {
		case 1:
			information_display->buffer()->append("Top field first");
			break;
		case 2:
			information_display->buffer()->append("Bottom field first");
			break;
	}
};
}
void RenderDialog::cb_edit_format_button(Fl_Button* o, void* v) {
  ((RenderDialog*)(o->parent()->parent()->parent()->parent()->parent()->user_data()))->cb_edit_format_button_i(o,v);
}

void RenderDialog::cb_remove_format_button_i(Fl_Button*, void*) {
  if ( presets_browser->value() > 3 ) {
	void* data = presets_browser->data(presets_browser->value());
	if ( data ) {
		nle::EncodingPreset* preset = (nle::EncodingPreset*)data;
		delete preset;
		presets_browser->remove( presets_browser->value() );
	}
};
}
void RenderDialog::cb_remove_format_button(Fl_Button* o, void* v) {
  ((RenderDialog*)(o->parent()->parent()->parent()->parent()->parent()->user_data()))->cb_remove_format_button_i(o,v);
}

RenderDialog::RenderDialog() {
  { dialog_window = new Fl_Double_Window(560, 405, "Export");
    dialog_window->user_data((void*)(this));
    { Fl_Box* o = new Fl_Box(0, 0, 560, 40, "Export");
      o->labelfont(1);
      o->labelsize(16);
    } // Fl_Box* o
    { export_filename = new Fl_File_Input(165, 45, 205, 35, "Filename");
    } // Fl_File_Input* export_filename
    { Fl_Button* o = new Fl_Button(375, 55, 75, 25, "File...");
      o->callback((Fl_Callback*)cb_File);
    } // Fl_Button* o
    { Fl_Return_Button* o = new Fl_Return_Button(290, 365, 245, 25, "Encode");
      o->callback((Fl_Callback*)cb_Encode);
      o->window()->hotspot(o);
    } // Fl_Return_Button* o
    { Fl_Button* o = new Fl_Button(30, 365, 245, 25, "Cancel");
      o->callback((Fl_Callback*)cb_Cancel);
    } // Fl_Button* o
    { Fl_Group* o = new Fl_Group(30, 100, 505, 255, "Video");
      o->box(FL_ENGRAVED_FRAME);
      o->labelfont(1);
      o->align(FL_ALIGN_TOP_LEFT);
      { Fl_Group* o = new Fl_Group(40, 125, 485, 220);
        { information_display = new Fl_Text_Display(285, 125, 240, 220, "Information");
          information_display->labelfont(1);
          information_display->align(FL_ALIGN_TOP_LEFT);
        } // Fl_Text_Display* information_display
        { Fl_Group* o = new Fl_Group(40, 125, 240, 220);
          { presets_browser = new Fl_Hold_Browser(40, 125, 240, 195, "Presets");
            presets_browser->box(FL_NO_BOX);
            presets_browser->color(FL_BACKGROUND2_COLOR);
            presets_browser->selection_color(FL_SELECTION_COLOR);
            presets_browser->labeltype(FL_NORMAL_LABEL);
            presets_browser->labelfont(1);
            presets_browser->labelsize(14);
            presets_browser->labelcolor(FL_FOREGROUND_COLOR);
            presets_browser->callback((Fl_Callback*)cb_presets_browser);
            presets_browser->align(FL_ALIGN_TOP_LEFT);
            presets_browser->when(FL_WHEN_RELEASE_ALWAYS);
            Fl_Group::current()->resizable(presets_browser);
          } // Fl_Hold_Browser* presets_browser
          { Fl_Group* o = new Fl_Group(40, 320, 240, 25);
            { Fl_Button* o = new Fl_Button(65, 320, 25, 25, "+");
              o->labelfont(1);
              o->labelsize(16);
              o->callback((Fl_Callback*)cb_);
            } // Fl_Button* o
            { edit_format_button = new Fl_Button(90, 320, 190, 25, "Edit...");
              edit_format_button->callback((Fl_Callback*)cb_edit_format_button);
              edit_format_button->deactivate();
              Fl_Group::current()->resizable(edit_format_button);
            } // Fl_Button* edit_format_button
            { remove_format_button = new Fl_Button(40, 320, 25, 25, "-");
              remove_format_button->labelfont(1);
              remove_format_button->labelsize(16);
              remove_format_button->callback((Fl_Callback*)cb_remove_format_button);
              remove_format_button->deactivate();
            } // Fl_Button* remove_format_button
            o->end();
          } // Fl_Group* o
          o->end();
        } // Fl_Group* o
        o->end();
        Fl_Group::current()->resizable(o);
      } // Fl_Group* o
      o->end();
      Fl_Group::current()->resizable(o);
    } // Fl_Group* o
    dialog_window->set_modal();
    dialog_window->end();
  } // Fl_Double_Window* dialog_window
  go = false;
information_display->buffer(new Fl_Text_Buffer);


nle::EncodingPreset* encoding_preset = new nle::EncodingPreset();
nle::video_format format;




encoding_preset->m_readonly = true;
format.w = 768;
format.h = 576;
format.pixel_aspect_ratio = 1.0;
format.interlacing = 0;
strcpy(format.name, "Quicktime 7");
strcpy(format.audio_codec, "faac" );
strcpy(format.video_codec, "ffmpeg_mpg4" );
format.framerate.frame_duration = 1200;
format.framerate.timescale = 30000;
format.framerate.audio_frames_per_chunk = 19200;
format.framerate.video_frames_per_chunk = 10;

encoding_preset->setFormat(&format);
lqt_codec_info_t** vcodec = lqt_find_video_codec_by_name( "ffmpeg_mpg4" );
lqt_codec_info_t** acodec = lqt_find_audio_codec_by_name("faac");

if ( vcodec && acodec && vcodec[0] && acodec[0] ) {
	encoding_preset->setVideoCodec( vcodec[0] );
	encoding_preset->setAudioCodec( acodec[0] );
	presets_browser->add(format.name, encoding_preset);
} else {
	delete encoding_preset;
	if ( !vcodec || !vcodec[0] ) {
		cout << "Video Codec Missing: ffmpeg_mpg4, Hint: install ffmpeg with shared libs before installing libquicktime" << endl;
	}
	if ( !acodec || !acodec[0] ) {
		cout << "Audio Codec Missing: faac, Hint: install libfaac before installing libquicktime" << endl;
	}
}
lqt_destroy_codec_info( vcodec );
lqt_destroy_codec_info( acodec );

/*-----*/

encoding_preset = new nle::EncodingPreset();
encoding_preset->getFormat(&format);

encoding_preset->m_readonly = true;
encoding_preset->m_avi_odml = true;
format.w = 768;
format.h = 576;
format.pixel_aspect_ratio = 1.0;
format.interlacing = 0;
strcpy(format.name, "MSMpeg 4v3, mp3 AVI (768x576)");
strcpy(format.audio_codec, "lame" );
strcpy(format.video_codec, "ffmpeg_msmpeg4v3" );
format.framerate.frame_duration = 1200;
format.framerate.timescale = 30000;
format.framerate.audio_frames_per_chunk = 19200;
format.framerate.video_frames_per_chunk = 10;

encoding_preset->setFormat(&format);

vcodec = lqt_find_video_codec_by_name( "ffmpeg_msmpeg4v3" );
acodec = lqt_find_audio_codec_by_name("lame");

if ( vcodec && acodec && vcodec[0] && acodec[0] ) {
	encoding_preset->setVideoCodec( vcodec[0] );
	encoding_preset->setAudioCodec( acodec[0] );
	presets_browser->add(format.name, encoding_preset);
} else {
	delete encoding_preset;
	if ( !vcodec || !vcodec[0] ) {
		cout << "Video Codec Missing: ffmpeg_msmpeg4v3, Hint: install ffmpeg with shared libs before installing libquicktime" << endl;
	}
	if ( !acodec || !acodec[0] ) {
		cout << "Audio Codec Missing: lame, Hint: install lame before installing libquicktime" << endl;
	}
}
lqt_destroy_codec_info( vcodec );
lqt_destroy_codec_info( acodec );


encoding_preset = new nle::EncodingPreset();
encoding_preset->getFormat(&format);

encoding_preset->m_readonly = true;
format.w = 720;
format.h = 576;
format.pixel_aspect_ratio = 1.094;
format.interlacing = 2;
strcpy(format.name, "Quicktime DV");
strcpy(format.video_codec, "dv_pal" );
strcpy(format.audio_codec, "twos" );
format.framerate.frame_duration = 1200;
format.framerate.timescale = 30000;
format.framerate.audio_frames_per_chunk = 19200;
format.framerate.video_frames_per_chunk = 10;
encoding_preset->setFormat(&format);
vcodec = lqt_find_video_codec_by_name( "dv_pal" );

acodec = lqt_find_audio_codec_by_name( "twos" );

if ( vcodec && acodec && vcodec[0] && acodec[0] ) {
	encoding_preset->setVideoCodec( vcodec[0] );
	encoding_preset->setAudioCodec( acodec[0] );
	presets_browser->add(format.name, encoding_preset);
} else {
	delete encoding_preset;
	if ( !vcodec || !vcodec[0] ) {
		cout << "Video Codec Missing: DV, Hint: install libdv before installing libquicktime" << endl;
	}
}
lqt_destroy_codec_info( vcodec );
lqt_destroy_codec_info( acodec );




/*presets_browser->add("Quicktime DV (PAL)");
presets_browser->add("MSMpeg 4v3, mp3 AVI (768x576)");
presets_browser->add("Quicktime 7");*/

//Load Presets XML
string presets_filename = "";
presets_filename += getenv("HOME");
presets_filename += ("/.openme.presets");
TiXmlDocument doc( presets_filename.c_str() );
if ( !doc.LoadFile() ) {
	return;
}
TiXmlHandle docH( &doc );

TiXmlElement* preset = docH.FirstChild( "preset" ).Element();

for ( ; preset; preset = preset->NextSiblingElement( "preset" ) ) {
	nle::EncodingPreset* encoding_preset = new nle::EncodingPreset();
	encoding_preset->readXML(preset);
	nle::video_format fmt;
	encoding_preset->getFormat(&fmt);
	presets_browser->add(fmt.name, encoding_preset);
}

TiXmlText* text = docH.FirstChildElement( "lastRenderFilename" ).Child( 0 ).Text();
if ( text ) {
	export_filename->value( text->Value() );
}

//export_filename->value( nle::g_preferences->lastRenderFilename().c_str() );
}

nle::IVideoFileWriter* RenderDialog::getFileWriter() {
  if ( !go ) {
	return 0;
}

if (presets_browser->value()==0) {
	return 0;
}

nle::EncodingPreset* preset = (nle::EncodingPreset*)presets_browser->data(presets_browser->value());

return preset->getFileWriter( export_filename->value() );
}

RenderDialog::~RenderDialog() {
  int s = presets_browser->size();
void* data;
nle::EncodingPreset* preset;

string presets_filename = "";
presets_filename += getenv("HOME");
presets_filename += ("/.openme.presets");
TiXmlDocument doc( presets_filename.c_str() );
TiXmlDeclaration *dec = new TiXmlDeclaration( "1.0", "", "no" );
doc.LinkEndChild( dec );
TiXmlElement *item = new TiXmlElement( "version" );
doc.LinkEndChild( item );
//TiXmlText* text = new TiXmlText( VERSION );
//item->LinkEndChild( text );


for ( int i = 1; i <= s; i++ ) {
	data = presets_browser->data(i);
	if ( data ) {
		preset = (nle::EncodingPreset*)data;
		if ( preset->m_readonly ) {
			delete preset;
			continue;
		}
		nle::video_format fmt;
		preset->getFormat(&fmt);
		
		TiXmlElement* preset_xml = new TiXmlElement( "preset" );
		doc.LinkEndChild( preset_xml );
		preset->writeXML( preset_xml );
		
		delete preset;
	}
}

item = new TiXmlElement( "lastRenderFilename" );
doc.LinkEndChild( item );
TiXmlText* text = new TiXmlText( export_filename->value() );
item->LinkEndChild( text );

doc.SaveFile();
delete dialog_window;
}

int RenderDialog::shown() {
  return dialog_window->shown();
}

void RenderDialog::show() {
  dialog_window->show();
}

void CustomFormatDialog::cb_video_codec_menu_i(Fl_Choice* o, void*) {
  video_codec = o->menu()[o->value()].user_data();
m_preset->setVideoCodec( (lqt_codec_info_t*)video_codec );
video_bitrate->value( m_preset->bitrate() );
if ( video_bitrate->value() < 0 ) {
	video_bitrate->deactivate();
} else {
	video_bitrate->activate();
};
}
void CustomFormatDialog::cb_video_codec_menu(Fl_Choice* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_video_codec_menu_i(o,v);
}

void CustomFormatDialog::cb_video_options_i(Fl_Button*, void*) {
  if ( video_codec ) {
	Fl_Group::current( dialog_window );
	CodecOptions dlg;
	dlg.m_audio = false;
	dlg.m_preset = m_preset;
	nle::setCodecInfo( &dlg, video_codec );
	dlg.codecOptions->show();
	while (dlg.codecOptions->shown())
		Fl::wait();
	video_bitrate->value( m_preset->bitrate() );
};
}
void CustomFormatDialog::cb_video_options(Fl_Button* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_video_options_i(o,v);
}

void CustomFormatDialog::cb_audio_codec_menu_i(Fl_Choice* o, void*) {
  audio_codec = o->menu()[o->value()].user_data();
m_preset->setAudioCodec( (lqt_codec_info_t*)audio_codec );
audio_bitrate->value( m_preset->audiobitrate() );
if ( audio_bitrate->value() < 0 ) {
	audio_bitrate->deactivate();
} else {
	audio_bitrate->activate();
};
}
void CustomFormatDialog::cb_audio_codec_menu(Fl_Choice* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_audio_codec_menu_i(o,v);
}

void CustomFormatDialog::cb_audio_options_i(Fl_Button*, void*) {
  if ( audio_codec ) {
	Fl_Group::current( dialog_window );
	CodecOptions dlg;
	dlg.m_audio = true;
	dlg.m_preset = m_preset;
	nle::setCodecInfo( &dlg, audio_codec );
	dlg.codecOptions->show();
	while (dlg.codecOptions->shown())
		Fl::wait();
	audio_bitrate->value( m_preset->audiobitrate() );
};
}
void CustomFormatDialog::cb_audio_options(Fl_Button* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_audio_options_i(o,v);
}

Fl_Menu_Item CustomFormatDialog::menu_samplerate[] = {
 {"48000", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Menu_Item CustomFormatDialog::menu_frame_rate_choice[] = {
 {"25 (PAL)", 0,  0, (void*)(&fps25x48000), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"29.97 (NTSC)", 0,  0, (void*)(&fps29_97x48000), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"24", 0,  0, (void*)(&fps24x48000), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"15", 0,  0, (void*)(&fps15x48000), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"50", 0,  0, (void*)(&fps50x48000), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"60", 0,  0, (void*)(&fps60x48000), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Menu_Item CustomFormatDialog::menu_interlacing[] = {
 {"None", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Top field first", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"bottom field first", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

void CustomFormatDialog::cb_Save_i(Fl_Return_Button* o, void*) {
  go = true;
o->window()->hide();
}
void CustomFormatDialog::cb_Save(Fl_Return_Button* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_Save_i(o,v);
}

void CustomFormatDialog::cb_Cancel1_i(Fl_Button* o, void*) {
  o->window()->hide();
}
void CustomFormatDialog::cb_Cancel1(Fl_Button* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_Cancel1_i(o,v);
}

Fl_Menu_Item CustomFormatDialog::menu_pixel_aspect_ratio[] = {
 {"1", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"0.9117 (NTSC)", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"1.21557 (NTSC 16:9)", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"1.094 (PAL)", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"1.4587 (PAL 16:9)", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"1.333 (HDV 1440x1080)", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

void CustomFormatDialog::cb_video_bitrate_i(Fl_Value_Input*, void*) {
  m_preset->bitrate( video_bitrate->value() );
}
void CustomFormatDialog::cb_video_bitrate(Fl_Value_Input* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_video_bitrate_i(o,v);
}

void CustomFormatDialog::cb_audio_bitrate_i(Fl_Value_Input*, void*) {
  m_preset->audiobitrate( audio_bitrate->value() );
}
void CustomFormatDialog::cb_audio_bitrate(Fl_Value_Input* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_audio_bitrate_i(o,v);
}

void CustomFormatDialog::cb_Quicktime_i(Fl_Menu_*, void*) {
  nle::setAudioCodecMenu( audio_codec_menu, LQT_FILE_QT );
nle::setVideoCodecMenu( video_codec_menu, LQT_FILE_QT );
}
void CustomFormatDialog::cb_Quicktime(Fl_Menu_* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_Quicktime_i(o,v);
}

void CustomFormatDialog::cb_AVI_i(Fl_Menu_*, void*) {
  nle::setAudioCodecMenu( audio_codec_menu, LQT_FILE_AVI_ODML | LQT_FILE_AVI );
nle::setVideoCodecMenu( video_codec_menu, LQT_FILE_AVI_ODML | LQT_FILE_AVI );
}
void CustomFormatDialog::cb_AVI(Fl_Menu_* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_AVI_i(o,v);
}

void CustomFormatDialog::cb_MP4_i(Fl_Menu_*, void*) {
  nle::setAudioCodecMenu( audio_codec_menu, LQT_FILE_MP4 );
nle::setVideoCodecMenu( video_codec_menu, LQT_FILE_MP4 );
}
void CustomFormatDialog::cb_MP4(Fl_Menu_* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_MP4_i(o,v);
}

void CustomFormatDialog::cb_3GP_i(Fl_Menu_*, void*) {
  nle::setAudioCodecMenu( audio_codec_menu, LQT_FILE_3GP );
nle::setVideoCodecMenu( video_codec_menu, LQT_FILE_3GP );
}
void CustomFormatDialog::cb_3GP(Fl_Menu_* o, void* v) {
  ((CustomFormatDialog*)(o->parent()->user_data()))->cb_3GP_i(o,v);
}

Fl_Menu_Item CustomFormatDialog::menu_lqt_container_menu[] = {
 {"Quicktime (.mov)", 0,  (Fl_Callback*)CustomFormatDialog::cb_Quicktime, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"AVI", 0,  (Fl_Callback*)CustomFormatDialog::cb_AVI, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"MP4", 0,  (Fl_Callback*)CustomFormatDialog::cb_MP4, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"3GP", 0,  (Fl_Callback*)CustomFormatDialog::cb_3GP, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

CustomFormatDialog::CustomFormatDialog() {
  audio_codec = 0;
video_codec = 0;
m_preset = new nle::EncodingPreset();
  { dialog_window = new Fl_Double_Window(690, 405, "Custom Video Format");
    dialog_window->user_data((void*)(this));
    { Fl_Box* o = new Fl_Box(350, 110, 330, 260);
      o->box(FL_ENGRAVED_FRAME);
      o->labelfont(1);
      o->align(FL_ALIGN_TOP_LEFT);
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(0, 0, 690, 45, "Custom Video Format");
      o->labelfont(1);
      o->labelsize(16);
    } // Fl_Box* o
    { video_codec_menu = new Fl_Choice(125, 120, 205, 25, "Video Codec");
      video_codec_menu->down_box(FL_BORDER_BOX);
      video_codec_menu->callback((Fl_Callback*)cb_video_codec_menu);
    } // Fl_Choice* video_codec_menu
    { video_options = new Fl_Button(255, 150, 75, 25, "Options...");
      video_options->callback((Fl_Callback*)cb_video_options);
    } // Fl_Button* video_options
    { audio_codec_menu = new Fl_Choice(125, 245, 205, 25, "Audio Codec");
      audio_codec_menu->down_box(FL_BORDER_BOX);
      audio_codec_menu->callback((Fl_Callback*)cb_audio_codec_menu);
    } // Fl_Choice* audio_codec_menu
    { audio_options = new Fl_Button(255, 275, 75, 25, "Options...");
      audio_options->callback((Fl_Callback*)cb_audio_options);
    } // Fl_Button* audio_options
    { samplerate = new Fl_Choice(125, 305, 205, 25, "Samplerate");
      samplerate->down_box(FL_BORDER_BOX);
      samplerate->menu(menu_samplerate);
    } // Fl_Choice* samplerate
    { name = new Fl_Input(495, 120, 150, 25, "Preset Name");
    } // Fl_Input* name
    { Fl_Button* o = new Fl_Button(645, 120, 25, 25, "@-3<-");
      o->tooltip("Generate");
    } // Fl_Button* o
    { frame_rate_choice = new Fl_Choice(495, 150, 175, 25, "Framerate");
      frame_rate_choice->down_box(FL_BORDER_BOX);
      frame_rate_choice->menu(menu_frame_rate_choice);
    } // Fl_Choice* frame_rate_choice
    { frame_size_w = new Fl_Spinner(495, 180, 85, 25, "Framesize");
      frame_size_w->value(1);
    } // Fl_Spinner* frame_size_w
    { frame_size_h = new Fl_Spinner(585, 180, 85, 25);
      frame_size_h->value(1);
    } // Fl_Spinner* frame_size_h
    { Fl_Box* o = new Fl_Box(10, 110, 330, 105, "Video");
      o->box(FL_ENGRAVED_FRAME);
      o->labelfont(1);
      o->align(FL_ALIGN_TOP_LEFT);
    } // Fl_Box* o
    { interlacing = new Fl_Choice(495, 210, 175, 25, "Interlacing");
      interlacing->down_box(FL_BORDER_BOX);
      interlacing->menu(menu_interlacing);
    } // Fl_Choice* interlacing
    { Fl_Return_Button* o = new Fl_Return_Button(350, 375, 330, 25, "Save Custom Format");
      o->callback((Fl_Callback*)cb_Save);
    } // Fl_Return_Button* o
    { Fl_Box* o = new Fl_Box(10, 235, 330, 135, "Audio");
      o->box(FL_ENGRAVED_FRAME);
      o->labelfont(1);
      o->align(FL_ALIGN_TOP_LEFT);
    } // Fl_Box* o
    { Fl_Check_Button* o = new Fl_Check_Button(20, 150, 235, 25, "Render Video");
      o->down_box(FL_DOWN_BOX);
      o->value(1);
      o->deactivate();
    } // Fl_Check_Button* o
    { Fl_Check_Button* o = new Fl_Check_Button(20, 275, 230, 25, "Render Audio");
      o->down_box(FL_DOWN_BOX);
      o->value(1);
      o->deactivate();
    } // Fl_Check_Button* o
    { Fl_Button* o = new Fl_Button(10, 375, 330, 25, "Cancel");
      o->callback((Fl_Callback*)cb_Cancel1);
    } // Fl_Button* o
    { pixel_aspect_ratio = new Fl_Input_Choice(495, 240, 175, 25, "Pixel Aspect Ratio");
      pixel_aspect_ratio->menu(menu_pixel_aspect_ratio);
    } // Fl_Input_Choice* pixel_aspect_ratio
    { video_bitrate = new Fl_Value_Input(255, 180, 75, 25, "Bitrate (kbps)");
      video_bitrate->maximum(10000);
      video_bitrate->step(1);
      video_bitrate->value(8192);
      video_bitrate->callback((Fl_Callback*)cb_video_bitrate);
    } // Fl_Value_Input* video_bitrate
    { audio_bitrate = new Fl_Value_Input(255, 335, 75, 25, "Bitrate (kbps)");
      audio_bitrate->maximum(10000);
      audio_bitrate->step(1);
      audio_bitrate->value(128);
      audio_bitrate->callback((Fl_Callback*)cb_audio_bitrate);
    } // Fl_Value_Input* audio_bitrate
    { Fl_Box* o = new Fl_Box(10, 45, 670, 45, "Container");
      o->box(FL_ENGRAVED_FRAME);
      o->labelfont(1);
      o->align(FL_ALIGN_TOP_LEFT);
    } // Fl_Box* o
    { lqt_container_menu = new Fl_Choice(210, 55, 255, 25, "File Type");
      lqt_container_menu->down_box(FL_BORDER_BOX);
      lqt_container_menu->labelfont(1);
      lqt_container_menu->menu(menu_lqt_container_menu);
    } // Fl_Choice* lqt_container_menu
    dialog_window->set_modal();
    dialog_window->end();
  } // Fl_Double_Window* dialog_window
  nle::setAudioCodecMenu( audio_codec_menu, LQT_FILE_QT );
nle::setVideoCodecMenu( video_codec_menu, LQT_FILE_QT );
go = false;
frame_size_w->range(1,2048);
frame_size_h->range(1,2048);
frame_size_w->value(640);
frame_size_h->value(480);
video_codec_menu->value(0);
audio_codec_menu->value(2);
pixel_aspect_ratio->value("1");

audio_codec = audio_codec_menu->menu()[audio_codec_menu->value()].user_data();
m_preset->setAudioCodec( (lqt_codec_info_t*)audio_codec );

video_codec = video_codec_menu->menu()[video_codec_menu->value()].user_data();
m_preset->setVideoCodec( (lqt_codec_info_t*)video_codec );

#if (LQT_CODEC_API_VERSION & 0xffff) <= 6
lqt_container_menu->hide();
#endif
}

int CustomFormatDialog::shown() {
  return dialog_window->shown();
}

void CustomFormatDialog::show() {
  dialog_window->show();
}

CustomFormatDialog::~CustomFormatDialog() {
  delete dialog_window;
delete m_preset;
}

nle::EncodingPreset* CustomFormatDialog::getEncodingPreset() {
  if ( !go ) {
	return 0;
}
nle::video_format fmt;
nle::EncodingPreset* preset = new nle::EncodingPreset( m_preset );
preset->getFormat(&fmt);

strcpy( fmt.name, name->value());


lqt_codec_info_t* codec_info = (lqt_codec_info_t*)video_codec_menu->menu()[video_codec_menu->value()].user_data();
strcpy( fmt.video_codec, codec_info->name );

codec_info = (lqt_codec_info_t*)audio_codec_menu->menu()[audio_codec_menu->value()].user_data();
strcpy( fmt.audio_codec, codec_info->name );



fmt.w = (int)frame_size_w->value();
fmt.h = (int)frame_size_h->value();
fmt.interlacing = interlacing->value();
fmt.samplerate = 48000;
fmt.pixel_aspect_ratio = nle::string_to_pixel_aspect_ratio( pixel_aspect_ratio->value() );


switch ( frame_rate_choice->value() ) {
	case 0: // 25
		fmt.framerate.frame_duration = 1200;
		fmt.framerate.timescale = 30000;
		fmt.framerate.audio_frames_per_chunk = 19200;
		fmt.framerate.video_frames_per_chunk = 10;
		break;
	case 1: //29.97
		fmt.framerate.frame_duration = 1001;
		fmt.framerate.timescale = 30000;
		fmt.framerate.audio_frames_per_chunk = 16016;
		fmt.framerate.video_frames_per_chunk = 10;
		break;
	case 2: // 24
		fmt.framerate.frame_duration = 1250;
		fmt.framerate.timescale = 30000;
		fmt.framerate.audio_frames_per_chunk = 20000;
		fmt.framerate.video_frames_per_chunk = 10;
		break;
	case 3: // 15
		fmt.framerate.frame_duration = 2000;
		fmt.framerate.timescale = 30000;
		fmt.framerate.audio_frames_per_chunk = 32000;
		fmt.framerate.video_frames_per_chunk = 10;
		break;
	case 4: //50
		fmt.framerate.frame_duration = 600;
		fmt.framerate.timescale = 30000;
		fmt.framerate.audio_frames_per_chunk = 19200;
		fmt.framerate.video_frames_per_chunk = 20;
		break;
	case 5: // 60
		fmt.framerate.frame_duration = 500;
		fmt.framerate.timescale = 30000;
		fmt.framerate.audio_frames_per_chunk = 16000;
		fmt.framerate.video_frames_per_chunk = 20;
		break;
}

preset->setFormat(&fmt);
#if (LQT_CODEC_API_VERSION & 0xffff) > 6
switch ( lqt_container_menu->value() ) {
	case 0:
		preset->m_file_type = LQT_FILE_QT;
		break;
	case 1:
		preset->m_file_type = LQT_FILE_AVI_ODML;
		break;
	case 2:
		preset->m_file_type = LQT_FILE_MP4;
		break;
	case 3:
		preset->m_file_type = LQT_FILE_3GP;
		break;
	
}
#endif
return preset;
}

void CustomFormatDialog::setEncodingPreset(nle::EncodingPreset* preset) {
  nle::video_format fmt;
preset->getFormat(&fmt);

delete m_preset;
m_preset = new nle::EncodingPreset( preset );

name->value(fmt.name);
frame_size_w->value(fmt.w);
frame_size_h->value(fmt.h);
interlacing->value(fmt.interlacing);
pixel_aspect_ratio->value(nle::pixel_aspect_ratio_to_string(fmt.pixel_aspect_ratio));

nle::setAudioCodecMenu( audio_codec_menu, m_preset->m_file_type );
nle::setVideoCodecMenu( video_codec_menu, m_preset->m_file_type );

int len = video_codec_menu->size();
for ( int i = 0; i < len; i++ ) {
	lqt_codec_info_t* codec_info = (lqt_codec_info_t*)video_codec_menu->menu()[i].user_data();
	if ( strcmp( fmt.video_codec, codec_info->name ) == 0 ) {
		video_codec_menu->value(i);
		video_codec = codec_info;
		m_preset->setVideoCodec( (lqt_codec_info_t*)video_codec );
		video_bitrate->value( m_preset->bitrate() );
		if ( video_bitrate->value() <= 0 ) {
			video_bitrate->deactivate();
		} else {
			video_bitrate->activate();
		}
		break;
	}
}


len = audio_codec_menu->size();
for ( int i = 0; i < len; i++ ) {
	lqt_codec_info_t* codec_info = (lqt_codec_info_t*)audio_codec_menu->menu()[i].user_data();
	if ( strcmp( fmt.audio_codec, codec_info->name ) == 0 ) {
		audio_codec_menu->value(i);
		audio_codec = codec_info;
		m_preset->setAudioCodec( (lqt_codec_info_t*)audio_codec );
		audio_bitrate->value( m_preset->audiobitrate() );
		if ( audio_bitrate->value() <= 0 ) {
			audio_bitrate->deactivate();
		} else {
			audio_bitrate->activate();
		}
		break;
	}
}


switch ( fmt.framerate.frame_duration ) {
	case 1200: // 25
		frame_rate_choice->value( 0 );
		break;
	case 1001: //29.97
		frame_rate_choice->value( 1 );
		break;
	case 1250: // 24
		frame_rate_choice->value( 2 );
		break;
	case 2000: // 15
		frame_rate_choice->value( 3 );
		break;
	case 600: //50
		frame_rate_choice->value( 4 );
		break;
	case 500: // 60
		frame_rate_choice->value( 5 );
		break;
}
#if (LQT_CODEC_API_VERSION & 0xffff) > 6
switch ( m_preset->m_file_type ) {
	case LQT_FILE_QT:
		lqt_container_menu->value( 0 );
		break;
	case LQT_FILE_AVI_ODML:
		lqt_container_menu->value( 1 );
		break;
	case LQT_FILE_MP4:
		lqt_container_menu->value( 2 );
		break;
	case LQT_FILE_3GP:
		lqt_container_menu->value( 3 );
		break;
}
#endif
}

void CodecOptions::cb_parameters_browser_i(Fl_Hold_Browser*, void*) {
  if ( parameters_browser->value() ) {
	nle::setCodecParameter( this, parameters_browser->data( parameters_browser->value() ) );
};
}
void CodecOptions::cb_parameters_browser(Fl_Hold_Browser* o, void* v) {
  ((CodecOptions*)(o->parent()->parent()->user_data()))->cb_parameters_browser_i(o,v);
}

void CodecOptions::cb_parameter_int_input_i(Fl_Value_Input* o, void*) {
  nle::ParameterValue val( (int)o->value() );
lqt_parameter_info_t* info = (lqt_parameter_info_t*)parameters_browser->data( parameters_browser->value() );
if ( m_audio ) {
	m_preset->setAudioParameter( info->name, val );
} else {
	m_preset->setVideoParameter( info->name, val );
};
}
void CodecOptions::cb_parameter_int_input(Fl_Value_Input* o, void* v) {
  ((CodecOptions*)(o->parent()->parent()->parent()->user_data()))->cb_parameter_int_input_i(o,v);
}

void CodecOptions::cb_parameter_string_input_i(Fl_Input* o, void*) {
  nle::ParameterValue val( o->value() );
lqt_parameter_info_t* info = (lqt_parameter_info_t*)parameters_browser->data( parameters_browser->value() );
if ( m_audio ) {
	m_preset->setAudioParameter( info->name, val );
} else {
	m_preset->setVideoParameter( info->name, val );
};
}
void CodecOptions::cb_parameter_string_input(Fl_Input* o, void* v) {
  ((CodecOptions*)(o->parent()->parent()->parent()->user_data()))->cb_parameter_string_input_i(o,v);
}

void CodecOptions::cb_parameter_stringlist_input_i(Fl_Choice* o, void*) {
  nle::ParameterValue val( o->text() );
lqt_parameter_info_t* info = (lqt_parameter_info_t*)parameters_browser->data( parameters_browser->value() );
if ( m_audio ) {
	m_preset->setAudioParameter( info->name, val );
} else {
	m_preset->setVideoParameter( info->name, val );
};
}
void CodecOptions::cb_parameter_stringlist_input(Fl_Choice* o, void* v) {
  ((CodecOptions*)(o->parent()->parent()->parent()->user_data()))->cb_parameter_stringlist_input_i(o,v);
}

void CodecOptions::cb_Cancel2_i(Fl_Button* o, void*) {
  o->window()->hide();
}
void CodecOptions::cb_Cancel2(Fl_Button* o, void* v) {
  ((CodecOptions*)(o->parent()->parent()->user_data()))->cb_Cancel2_i(o,v);
}

void CodecOptions::cb_Ok_i(Fl_Return_Button* o, void*) {
  o->window()->hide();
}
void CodecOptions::cb_Ok(Fl_Return_Button* o, void* v) {
  ((CodecOptions*)(o->parent()->parent()->user_data()))->cb_Ok_i(o,v);
}

CodecOptions::CodecOptions() {
  { codecOptions = new Fl_Double_Window(345, 305, "Codec Options");
    codecOptions->user_data((void*)(this));
    { codec_label = new Fl_Box(0, 0, 345, 35, "Codec");
      codec_label->labelfont(1);
      codec_label->labelsize(16);
    } // Fl_Box* codec_label
    { Fl_Group* o = new Fl_Group(0, 35, 345, 230);
      { parameters_browser = new Fl_Hold_Browser(5, 40, 165, 220);
        parameters_browser->box(FL_NO_BOX);
        parameters_browser->color(FL_BACKGROUND2_COLOR);
        parameters_browser->selection_color(FL_SELECTION_COLOR);
        parameters_browser->labeltype(FL_NORMAL_LABEL);
        parameters_browser->labelfont(0);
        parameters_browser->labelsize(14);
        parameters_browser->labelcolor(FL_FOREGROUND_COLOR);
        parameters_browser->callback((Fl_Callback*)cb_parameters_browser);
        parameters_browser->align(FL_ALIGN_BOTTOM);
        parameters_browser->when(FL_WHEN_RELEASE_ALWAYS);
        Fl_Group::current()->resizable(parameters_browser);
      } // Fl_Hold_Browser* parameters_browser
      { Fl_Group* o = new Fl_Group(170, 35, 175, 230);
        { parameter_int_input = new Fl_Value_Input(175, 40, 165, 25);
          parameter_int_input->step(1);
          parameter_int_input->callback((Fl_Callback*)cb_parameter_int_input);
          parameter_int_input->deactivate();
        } // Fl_Value_Input* parameter_int_input
        { parameter_string_input = new Fl_Input(175, 70, 165, 25);
          parameter_string_input->callback((Fl_Callback*)cb_parameter_string_input);
          parameter_string_input->deactivate();
        } // Fl_Input* parameter_string_input
        { parameter_stringlist_input = new Fl_Choice(175, 100, 165, 25);
          parameter_stringlist_input->down_box(FL_BORDER_BOX);
          parameter_stringlist_input->callback((Fl_Callback*)cb_parameter_stringlist_input);
          parameter_stringlist_input->deactivate();
        } // Fl_Choice* parameter_stringlist_input
        { Fl_Box* o = new Fl_Box(230, 175, 25, 25);
          Fl_Group::current()->resizable(o);
        } // Fl_Box* o
        o->end();
      } // Fl_Group* o
      o->end();
      Fl_Group::current()->resizable(o);
    } // Fl_Group* o
    { Fl_Group* o = new Fl_Group(0, 265, 345, 40);
      { Fl_Button* o = new Fl_Button(20, 275, 140, 25, "Cancel");
        o->callback((Fl_Callback*)cb_Cancel2);
        o->hide();
      } // Fl_Button* o
      { Fl_Return_Button* o = new Fl_Return_Button(20, 275, 305, 25, "Ok");
        o->callback((Fl_Callback*)cb_Ok);
        Fl_Group::current()->resizable(o);
        o->window()->hotspot(o);
      } // Fl_Return_Button* o
      o->end();
    } // Fl_Group* o
    codecOptions->set_modal();
    codecOptions->end();
  } // Fl_Double_Window* codecOptions
}

CodecOptions::~CodecOptions() {
  delete codecOptions;
}
