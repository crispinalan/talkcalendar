/***************************************************************************
 * GPL v3.0 license (see license document distributed with this software)
 * Diphone wav paths 
 * Author: crispinalan@gmail.com
 ***************************************************************************/

//#include <gtk/gtk.h> 
#include "diphone.h"

//---------------------------------------------------------------------
// get diphone wav path
//---------------------------------------------------------------------
char* get_diphone_wav_path(char* dp_str) {

	char* diphone_str = g_ascii_strdown(dp_str, -1); //convert to lower case	
	
	char* result="";
	
	//aa diphones
	
	if (g_strcmp0(diphone_str,"aa-aa")==0) {
	result ="diphones/aa-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ae")==0) {
	result ="diphones/aa-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ah")==0) {
	result ="diphones/aa-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ao")==0) {
	result ="diphones/aa-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-aw")==0) {
	result ="diphones/aa-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ax")==0) {
	result ="diphones/aa-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ay")==0) {
	result ="diphones/aa-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-b")==0) {
	result ="diphones/aa-b.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ch")==0) {
	result ="diphones/aa-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-d")==0) {
	result ="diphones/aa-d.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-dh")==0) {
	result ="diphones/aa-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-eh")==0) {
	result ="diphones/aa-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-er")==0) {
	result ="diphones/aa-er.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ey")==0) {
	result ="diphones/aa-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-f")==0) {
	result ="diphones/aa-f.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-g")==0) {
	result ="diphones/aa-g.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-hh")==0) {
	result ="diphones/aa-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ih")==0) {
	result ="diphones/aa-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-iy")==0) {
	result ="diphones/aa-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-jh")==0) {
	result ="diphones/aa-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-k")==0) {
	result ="diphones/aa-k.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-l")==0) {
	result ="diphones/aa-l.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-m")==0) {
	result ="diphones/aa-m.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-n")==0) {
	result ="diphones/aa-n.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ng")==0) {
	result ="diphones/aa-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ow")==0) {
	result ="diphones/aa-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-oy")==0) {
	result ="diphones/aa-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-p")==0) {
	result ="diphones/aa-p.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-pau")==0) {
	result ="diphones/aa-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-r")==0) {
	result ="diphones/aa-r.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-s")==0) {
	result ="diphones/aa-s.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-sh")==0) {
	result ="diphones/aa-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-t")==0) {
	result ="diphones/aa-t.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-th")==0) {
	result ="diphones/aa-th.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-uh")==0) {
	result ="diphones/aa-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-uw")==0) {
	result ="diphones/aa-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-v")==0) {
	result ="diphones/aa-v.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-w")==0) {
	result ="diphones/aa-w.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-y")==0) {
	result ="diphones/aa-y.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-z")==0) {
	result ="diphones/aa-z.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-zh")==0) {
	result ="diphones/aa-zh.wav";	
	}
	
	//ae diphones
	if (g_strcmp0(diphone_str,"ae-aa")==0) {
	result ="diphones/ae-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ae")==0) {
	result ="diphones/ae-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ah")==0) {
	result ="diphones/ae-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ao")==0) {
	result ="diphones/ae-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-aw")==0) {
	result ="diphones/ae-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ax")==0) {
	result ="diphones/ae-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ay")==0) {
	result ="diphones/ae-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-b")==0) {
	result ="diphones/ae-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ch")==0) {
	result ="diphones/ae-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-d")==0) {
	result ="diphones/ae-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-dh")==0) {
	result ="diphones/ae-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-eh")==0) {
	result ="diphones/ae-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-er")==0) {
	result ="diphones/ae-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ey")==0) {
	result ="diphones/ae-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-f")==0) {
	result ="diphones/ae-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-g")==0) {
	result ="diphones/ae-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-hh")==0) {
	result ="diphones/ae-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ih")==0) {
	result ="diphones/ae-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-iy")==0) {
	result ="diphones/ae-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-jh")==0) {
	result ="diphones/ae-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-k")==0) {
	result ="diphones/ae-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-l")==0) {
	result ="diphones/ae-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-m")==0) {
	result ="diphones/ae-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-n")==0) {
	result ="diphones/ae-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ng")==0) {
	result ="diphones/ae-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ow")==0) {
	result ="diphones/ae-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-oy")==0) {
	result ="diphones/ae-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-p")==0) {
	result ="diphones/ae-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-pau")==0) {
	result ="diphones/ae-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-r")==0) {
	result ="diphones/ae-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-s")==0) {
	result ="diphones/ae-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-sh")==0) {
	result ="diphones/ae-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-t")==0) {
	result ="diphones/ae-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-th")==0) {
	result ="diphones/ae-th.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-uh")==0) {
	result ="diphones/ae-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-uw")==0) {
	result ="diphones/ae-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-v")==0) {
	result ="diphones/ae-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-e")==0) {
	result ="diphones/ae-e.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-y")==0) {
	result ="diphones/ae-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-z")==0) {
	result ="diphones/ae-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-zh")==0) {
	result ="diphones/ae-zh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-aa")==0) {
	result ="diphones/ah-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ae")==0) {
	result ="diphones/ah-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ah")==0) {
	result ="diphones/ah-ah.wav";	
	}
	
	//ah diphones
	if (g_strcmp0(diphone_str,"ah-ao")==0) {
	result ="diphones/ah-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-aw")==0) {
	result ="diphones/ah-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ax")==0) {
	result ="diphones/ah-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ay")==0) {
	result ="diphones/ah-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-b")==0) {
	result ="diphones/ah-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ch")==0) {
	result ="diphones/ah-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-d")==0) {
	result ="diphones/ah-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-dh")==0) {
	result ="diphones/ah-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-eh")==0) {
	result ="diphones/ah-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-er")==0) {
	result ="diphones/ah-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ey")==0) {
	result ="diphones/ah-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-f")==0) {
	result ="diphones/ah-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-g")==0) {
	result ="diphones/ah-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-hh")==0) {
	result ="diphones/ah-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ih")==0) {
	result ="diphones/ah-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-iy")==0) {
	result ="diphones/ah-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-jh")==0) {
	result ="diphones/ah-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-k")==0) {
	result ="diphones/ah-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-l")==0) {
	result ="diphones/ah-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-m")==0) {
	result ="diphones/ah-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-n")==0) {
	result ="diphones/ah-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ng")==0) {
	result ="diphones/ah-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ow")==0) {
	result ="diphones/ah-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-oy")==0) {
	result ="diphones/ah-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-p")==0) {
	result ="diphones/ah-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-pau")==0) {
	result ="diphones/ah-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-r")==0) {
	result ="diphones/ah-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-s")==0) {
	result ="diphones/ah-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-sh")==0) {
	result ="diphones/ah-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-t")==0) {
	result ="diphones/ah-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-th")==0) {
	result ="diphones/ah-th.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-uh")==0) {
	result ="diphones/ah-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-uw")==0) {
	result ="diphones/ah-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-v")==0) {
	result ="diphones/ah-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-w")==0) {
	result ="diphones/ah-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-y")==0) {
	result ="diphones/ah-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-z")==0) {
	result ="diphones/ah-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-zh")==0) {
	result ="diphones/ah-zh.wav";	
	}
	
	//ao diphones	
	if (g_strcmp0(diphone_str,"ao-aa")==0) {
	result ="diphones/ao-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ae")==0) {
	result ="diphones/ao-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ah")==0) {
	result ="diphones/ao-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ao")==0) {
	result ="diphones/ao-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-aw")==0) {
	result ="diphones/ao-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ax")==0) {
	result ="diphones/ao-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ay")==0) {
	result ="diphones/ao-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-b")==0) {
	result ="diphones/ao-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ch")==0) {
	result ="diphones/ao-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-d")==0) {
	result ="diphones/ao-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-dh")==0) {
	result ="diphones/ao-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-eh")==0) {
	result ="diphones/ao-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-er")==0) {
	result ="diphones/ao-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ey")==0) {
	result ="diphones/ao-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-f")==0) {
	result ="diphones/ao-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-g")==0) {
	result ="diphones/ao-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-hh")==0) {
	result ="diphones/ao-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ih")==0) {
	result ="diphones/ao-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-iy")==0) {
	result ="diphones/ao-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-jh")==0) {
	result ="diphones/ao-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-k")==0) {
	result ="diphones/ao-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-l")==0) {
	result ="diphones/ao-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-m")==0) {
	result ="diphones/ao-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-n")==0) {
	result ="diphones/ao-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ng")==0) {
	result ="diphones/ao-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ow")==0) {
	result ="diphones/ao-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-oy")==0) {
	result ="diphones/ao-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-p")==0) {
	result ="diphones/ao-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-pau")==0) {
	result ="diphones/ao-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-r")==0) {
	result ="diphones/ao-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-s")==0) {
	result ="diphones/ao-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-sh")==0) {
	result ="diphones/ao-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-t")==0) {
	result ="diphones/ao-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-th")==0) {
	result ="diphones/ao-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ao-uh")==0) {
	result ="diphones/ao-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-uw")==0) {
	result ="diphones/ao-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-v")==0) {
	result ="diphones/ao-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-w")==0) {
	result ="diphones/ao-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-y")==0) {
	result ="diphones/ao-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-z")==0) {
	result ="diphones/ao-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-zh")==0) {
	result ="diphones/ao-zh.wav";	
	}
	
	//aw diphones
	if (g_strcmp0(diphone_str,"aw-aa")==0) {
	result ="diphones/aw-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ae")==0) {
	result ="diphones/aw-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ah")==0) {
	result ="diphones/aw-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ao")==0) {
	result ="diphones/aw-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-aw")==0) {
	result ="diphones/aw-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ax")==0) {
	result ="diphones/aw-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ay")==0) {
	result ="diphones/aw-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-b")==0) {
	result ="diphones/aw-b.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ch")==0) {
	result ="diphones/aw-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-d")==0) {
	result ="diphones/aw-d.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-dh")==0) {
	result ="diphones/aw-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-eh")==0) {
	result ="diphones/aw-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-er")==0) {
	result ="diphones/aw-er.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ey")==0) {
	result ="diphones/aw-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-f")==0) {
	result ="diphones/aw-f.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-g")==0) {
	result ="diphones/aw-g.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-hh")==0) {
	result ="diphones/aw-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ih")==0) {
	result ="diphones/aw-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-iy")==0) {
	result ="diphones/aw-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-jh")==0) {
	result ="diphones/aw-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-k")==0) {
	result ="diphones/aw-k.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-l")==0) {
	result ="diphones/aw-l.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-m")==0) {
	result ="diphones/aw-m.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-n")==0) {
	result ="diphones/aw-n.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ng")==0) {
	result ="diphones/aw-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ow")==0) {
	result ="diphones/aw-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-oy")==0) {
	result ="diphones/aw-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-p")==0) {
	result ="diphones/aw-p.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-pau")==0) {
	result ="diphones/aw-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-r")==0) {
	result ="diphones/aw-r.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-s")==0) {
	result ="diphones/aw-s.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-sh")==0) {
	result ="diphones/aw-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-t")==0) {
	result ="diphones/aw-t.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-th")==0) {
	result ="diphones/aw-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"aw-uh")==0) {
	result ="diphones/aw-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-uw")==0) {
	result ="diphones/aw-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-v")==0) {
	result ="diphones/aw-v.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-w")==0) {
	result ="diphones/aw-w.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-y")==0) {
	result ="diphones/aw-y.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-z")==0) {
	result ="diphones/aw-z.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-zh")==0) {
	result ="diphones/aw-zh.wav";	
	}
	
	//ax diphones
	if (g_strcmp0(diphone_str,"ax-aa")==0) {
	result ="diphones/ax-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ae")==0) {
	result ="diphones/ax-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ah")==0) {
	result ="diphones/ax-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ao")==0) {
	result ="diphones/ax-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-aw")==0) {
	result ="diphones/ax-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ax")==0) {
	result ="diphones/ax-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ay")==0) {
	result ="diphones/ax-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-b")==0) {
	result ="diphones/ax-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ch")==0) {
	result ="diphones/ax-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-d")==0) {
	result ="diphones/ax-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-dh")==0) {
	result ="diphones/ax-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-eh")==0) {
	result ="diphones/ax-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-er")==0) {
	result ="diphones/ax-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ey")==0) {
	result ="diphones/ax-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-f")==0) {
	result ="diphones/ax-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-g")==0) {
	result ="diphones/ax-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-hh")==0) {
	result ="diphones/ax-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ih")==0) {
	result ="diphones/ax-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-iy")==0) {
	result ="diphones/ax-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-jh")==0) {
	result ="diphones/ax-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-k")==0) {
	result ="diphones/ax-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-l")==0) {
	result ="diphones/ax-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-m")==0) {
	result ="diphones/ax-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-n")==0) {
	result ="diphones/ax-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ng")==0) {
	result ="diphones/ax-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ow")==0) {
	result ="diphones/ax-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-oy")==0) {
	result ="diphones/ax-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-p")==0) {
	result ="diphones/ax-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-pau")==0) {
	result ="diphones/ax-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-r")==0) {
	result ="diphones/ax-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-s")==0) {
	result ="diphones/ax-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-sh")==0) {
	result ="diphones/ax-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-t")==0) {
	result ="diphones/ax-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-th")==0) {
	result ="diphones/ax-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ax-uh")==0) {
	result ="diphones/ax-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-uw")==0) {
	result ="diphones/ax-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-v")==0) {
	result ="diphones/ax-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-w")==0) {
	result ="diphones/ax-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-y")==0) {
	result ="diphones/ax-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-z")==0) {
	result ="diphones/ax-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-zh")==0) {
	result ="diphones/ax-zh.wav";	
	}
	
	//ay diphones
	if (g_strcmp0(diphone_str,"ay-aa")==0) {
	result ="diphones/ay-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ae")==0) {
	result ="diphones/ay-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ah")==0) {
	result ="diphones/ay-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ao")==0) {
	result ="diphones/ay-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-aw")==0) {
	result ="diphones/ay-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ax")==0) {
	result ="diphones/ay-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ay")==0) {
	result ="diphones/ay-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-b")==0) {
	result ="diphones/ay-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ch")==0) {
	result ="diphones/ay-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-d")==0) {
	result ="diphones/ay-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-dh")==0) {
	result ="diphones/ay-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-eh")==0) {
	result ="diphones/ay-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-er")==0) {
	result ="diphones/ay-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ey")==0) {
	result ="diphones/ay-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-f")==0) {
	result ="diphones/ay-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-g")==0) {
	result ="diphones/ay-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-hh")==0) {
	result ="diphones/ay-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ih")==0) {
	result ="diphones/ay-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-iy")==0) {
	result ="diphones/ay-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-jh")==0) {
	result ="diphones/ay-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-k")==0) {
	result ="diphones/ay-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-l")==0) {
	result ="diphones/ay-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-m")==0) {
	result ="diphones/ay-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-n")==0) {
	result ="diphones/ay-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ng")==0) {
	result ="diphones/ay-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ow")==0) {
	result ="diphones/ay-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-oy")==0) {
	result ="diphones/ay-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-p")==0) {
	result ="diphones/ay-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-pau")==0) {
	result ="diphones/ay-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-r")==0) {
	result ="diphones/ay-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-s")==0) {
	result ="diphones/ay-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-sh")==0) {
	result ="diphones/ay-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-t")==0) {
	result ="diphones/ay-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-th")==0) {
	result ="diphones/ay-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ay-uh")==0) {
	result ="diphones/ay-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-uw")==0) {
	result ="diphones/ay-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-v")==0) {
	result ="diphones/ay-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-w")==0) {
	result ="diphones/ay-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-y")==0) {
	result ="diphones/ay-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-z")==0) {
	result ="diphones/ay-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-zh")==0) {
	result ="diphones/ay-zh.wav";	
	}
	
	//b diphones
	if (g_strcmp0(diphone_str,"b-aa")==0) {
	result ="diphones/b-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ae")==0) {
	result ="diphones/b-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ah")==0) {
	result ="diphones/b-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ao")==0) {
	result ="diphones/b-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"b-aw")==0) {
	result ="diphones/b-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ax")==0) {
	result ="diphones/b-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ay")==0) {
	result ="diphones/b-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"b-b")==0) {
	result ="diphones/b-b.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ch")==0) {
	result ="diphones/b-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"b-d")==0) {
	result ="diphones/b-d.wav";	
	}
	if (g_strcmp0(diphone_str,"b-dh")==0) {
	result ="diphones/b-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-eh")==0) {
	result ="diphones/b-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-er")==0) {
	result ="diphones/b-er.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ey")==0) {
	result ="diphones/b-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"b-f")==0) {
	result ="diphones/b-f.wav";	
	}
	if (g_strcmp0(diphone_str,"b-g")==0) {
	result ="diphones/b-g.wav";	
	}
	if (g_strcmp0(diphone_str,"b-hh")==0) {
	result ="diphones/b-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ih")==0) {
	result ="diphones/b-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"b-iy")==0) {
	result ="diphones/b-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"b-jh")==0) {
	result ="diphones/b-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-k")==0) {
	result ="diphones/b-k.wav";	
	}
	if (g_strcmp0(diphone_str,"b-l")==0) {
	result ="diphones/b-l.wav";	
	}
	if (g_strcmp0(diphone_str,"b-m")==0) {
	result ="diphones/b-m.wav";	
	}
	if (g_strcmp0(diphone_str,"b-n")==0) {
	result ="diphones/b-n.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ng")==0) {
	result ="diphones/b-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ow")==0) {
	result ="diphones/b-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"b-oy")==0) {
	result ="diphones/b-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"b-p")==0) {
	result ="diphones/b-p.wav";	
	}
	if (g_strcmp0(diphone_str,"b-pau")==0) {
	result ="diphones/b-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"b-r")==0) {
	result ="diphones/b-r.wav";	
	}
	if (g_strcmp0(diphone_str,"b-s")==0) {
	result ="diphones/b-s.wav";	
	}
	if (g_strcmp0(diphone_str,"b-sh")==0) {
	result ="diphones/b-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-t")==0) {
	result ="diphones/b-t.wav";	
	}
	if (g_strcmp0(diphone_str,"b-th")==0) {
	result ="diphones/b-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"b-uh")==0) {
	result ="diphones/b-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-uw")==0) {
	result ="diphones/b-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"b-v")==0) {
	result ="diphones/b-v.wav";	
	}
	if (g_strcmp0(diphone_str,"b-w")==0) {
	result ="diphones/b-w.wav";	
	}
	if (g_strcmp0(diphone_str,"b-y")==0) {
	result ="diphones/b-y.wav";	
	}	
	if (g_strcmp0(diphone_str,"b-z")==0) {
	result ="diphones/b-z.wav";	
	}
	if (g_strcmp0(diphone_str,"b-zh")==0) {
	result ="diphones/b-zh.wav";	
	}
	
	//b alternative
	if (g_strcmp0(diphone_str,"b_-_y")==0) {
	result ="diphones/b_-_y.wav";	
	}
	
	//ch diphones
	if (g_strcmp0(diphone_str,"ch-aa")==0) {
	result ="diphones/ch-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ae")==0) {
	result ="diphones/ch-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ah")==0) {
	result ="diphones/ch-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ao")==0) {
	result ="diphones/ch-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-aw")==0) {
	result ="diphones/ch-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ax")==0) {
	result ="diphones/ch-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ay")==0) {
	result ="diphones/ch-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-b")==0) {
	result ="diphones/ch-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ch")==0) {
	result ="diphones/ch-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-d")==0) {
	result ="diphones/ch-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-dh")==0) {
	result ="diphones/ch-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-eh")==0) {
	result ="diphones/ch-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-er")==0) {
	result ="diphones/ch-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ey")==0) {
	result ="diphones/ch-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-f")==0) {
	result ="diphones/ch-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-g")==0) {
	result ="diphones/ch-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-hh")==0) {
	result ="diphones/ch-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ih")==0) {
	result ="diphones/ch-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-iy")==0) {
	result ="diphones/ch-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-jh")==0) {
	result ="diphones/ch-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-k")==0) {
	result ="diphones/ch-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-l")==0) {
	result ="diphones/ch-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-m")==0) {
	result ="diphones/ch-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-n")==0) {
	result ="diphones/ch-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ng")==0) {
	result ="diphones/ch-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ow")==0) {
	result ="diphones/ch-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-oy")==0) {
	result ="diphones/ch-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-p")==0) {
	result ="diphones/ch-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-pau")==0) {
	result ="diphones/ch-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-r")==0) {
	result ="diphones/ch-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-s")==0) {
	result ="diphones/ch-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-sh")==0) {
	result ="diphones/ch-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-t")==0) {
	result ="diphones/ch-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-th")==0) {
	result ="diphones/ch-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ch-uh")==0) {
	result ="diphones/ch-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-uw")==0) {
	result ="diphones/ch-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-v")==0) {
	result ="diphones/ch-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-w")==0) {
	result ="diphones/ch-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-y")==0) {
	result ="diphones/ch-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-z")==0) {
	result ="diphones/ch-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-zh")==0) {
	result ="diphones/ch-zh.wav";	
	}
	
	//d diphones
	if (g_strcmp0(diphone_str,"d-aa")==0) {
	result ="diphones/d-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ae")==0) {
	result ="diphones/d-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ah")==0) {
	result ="diphones/d-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ao")==0) {
	result ="diphones/d-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"d-aw")==0) {
	result ="diphones/d-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ax")==0) {
	result ="diphones/d-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ay")==0) {
	result ="diphones/d-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"d-b")==0) {
	result ="diphones/d-b.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ch")==0) {
	result ="diphones/d-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"d-d")==0) {
	result ="diphones/d-d.wav";	
	}
	if (g_strcmp0(diphone_str,"d-dh")==0) {
	result ="diphones/d-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-eh")==0) {
	result ="diphones/d-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-er")==0) {
	result ="diphones/d-er.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ey")==0) {
	result ="diphones/d-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"d-f")==0) {
	result ="diphones/d-f.wav";	
	}
	if (g_strcmp0(diphone_str,"d-g")==0) {
	result ="diphones/d-g.wav";	
	}
	if (g_strcmp0(diphone_str,"d-hh")==0) {
	result ="diphones/d-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ih")==0) {
	result ="diphones/d-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"d-iy")==0) {
	result ="diphones/d-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"d-jh")==0) {
	result ="diphones/d-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-k")==0) {
	result ="diphones/d-k.wav";	
	}
	if (g_strcmp0(diphone_str,"d-l")==0) {
	result ="diphones/d-l.wav";	
	}
	if (g_strcmp0(diphone_str,"d-m")==0) {
	result ="diphones/d-m.wav";	
	}
	if (g_strcmp0(diphone_str,"d-n")==0) {
	result ="diphones/d-n.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ng")==0) {
	result ="diphones/d-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ow")==0) {
	result ="diphones/d-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"d-oy")==0) {
	result ="diphones/d-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"d-p")==0) {
	result ="diphones/d-p.wav";	
	}
	if (g_strcmp0(diphone_str,"d-pau")==0) {
	result ="diphones/d-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"d-r")==0) {
	result ="diphones/d-r.wav";	
	}
	if (g_strcmp0(diphone_str,"d-s")==0) {
	result ="diphones/d-s.wav";	
	}
	if (g_strcmp0(diphone_str,"d-sh")==0) {
	result ="diphones/d-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-t")==0) {
	result ="diphones/d-t.wav";	
	}
	if (g_strcmp0(diphone_str,"d-th")==0) {
	result ="diphones/d-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"d-uh")==0) {
	result ="diphones/d-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-uw")==0) {
	result ="diphones/d-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"d-v")==0) {
	result ="diphones/d-v.wav";	
	}
	if (g_strcmp0(diphone_str,"d-w")==0) {
	result ="diphones/d-w.wav";	
	}
	if (g_strcmp0(diphone_str,"d-y")==0) {
	result ="diphones/d-y.wav";	
	}
	if (g_strcmp0(diphone_str,"d-z")==0) {
	result ="diphones/d-z.wav";	
	}
	if (g_strcmp0(diphone_str,"d-zh")==0) {
	result ="diphones/d-zh.wav";	
	}
	
	//dh diphones
	if (g_strcmp0(diphone_str,"dh-aa")==0) {
	result ="diphones/dh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ae")==0) {
	result ="diphones/dh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ah")==0) {
	result ="diphones/dh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ao")==0) {
	result ="diphones/dh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-aw")==0) {
	result ="diphones/dh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ax")==0) {
	result ="diphones/dh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ay")==0) {
	result ="diphones/dh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-b")==0) {
	result ="diphones/dh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ch")==0) {
	result ="diphones/dh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-d")==0) {
	result ="diphones/dh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-dh")==0) {
	result ="diphones/dh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-eh")==0) {
	result ="diphones/dh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-er")==0) {
	result ="diphones/dh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ey")==0) {
	result ="diphones/dh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-f")==0) {
	result ="diphones/dh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-g")==0) {
	result ="diphones/dh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-hh")==0) {
	result ="diphones/dh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ih")==0) {
	result ="diphones/dh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-iy")==0) {
	result ="diphones/dh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-jh")==0) {
	result ="diphones/dh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-k")==0) {
	result ="diphones/dh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-l")==0) {
	result ="diphones/dh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-m")==0) {
	result ="diphones/dh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-n")==0) {
	result ="diphones/dh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ng")==0) {
	result ="diphones/dh-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ow")==0) {
	result ="diphones/dh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-oy")==0) {
	result ="diphones/dh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-p")==0) {
	result ="diphones/dh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-pau")==0) {
	result ="diphones/dh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-r")==0) {
	result ="diphones/dh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-s")==0) {
	result ="diphones/dh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-sh")==0) {
	result ="diphones/dh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-t")==0) {
	result ="diphones/dh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-th")==0) {
	result ="diphones/dh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"dh-uh")==0) {
	result ="diphones/dh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-uw")==0) {
	result ="diphones/dh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-v")==0) {
	result ="diphones/dh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-w")==0) {
	result ="diphones/dh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-y")==0) {
	result ="diphones/dh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-z")==0) {
	result ="diphones/dh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-zh")==0) {
	result ="diphones/dh-zh.wav";	
	}
	
	//eh diphones
	if (g_strcmp0(diphone_str,"eh-aa")==0) {
	result ="diphones/eh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ae")==0) {
	result ="diphones/eh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ah")==0) {
	result ="diphones/eh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ao")==0) {
	result ="diphones/eh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-aw")==0) {
	result ="diphones/eh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ax")==0) {
	result ="diphones/eh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ay")==0) {
	result ="diphones/eh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-b")==0) {
	result ="diphones/eh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ch")==0) {
	result ="diphones/eh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-d")==0) {
	result ="diphones/eh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-dh")==0) {
	result ="diphones/eh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-eh")==0) {
	result ="diphones/eh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-er")==0) {
	result ="diphones/eh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ey")==0) {
	result ="diphones/eh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-f")==0) {
	result ="diphones/eh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-g")==0) {
	result ="diphones/eh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-hh")==0) {
	result ="diphones/eh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ih")==0) {
	result ="diphones/eh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-iy")==0) {
	result ="diphones/eh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-jh")==0) {
	result ="diphones/eh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-k")==0) {
	result ="diphones/eh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-l")==0) {
	result ="diphones/eh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-m")==0) {
	result ="diphones/eh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-n")==0) {
	result ="diphones/eh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ng")==0) {
	result ="diphones/eh-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ow")==0) {
	result ="diphones/eh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-oy")==0) {
	result ="diphones/eh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-p")==0) {
	result ="diphones/eh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-pau")==0) {
	result ="diphones/eh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-r")==0) {
	result ="diphones/eh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-s")==0) {
	result ="diphones/eh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-sh")==0) {
	result ="diphones/eh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-t")==0) {
	result ="diphones/eh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-th")==0) {
	result ="diphones/eh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"eh-uh")==0) {
	result ="diphones/eh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-uw")==0) {
	result ="diphones/eh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-v")==0) {
	result ="diphones/eh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-w")==0) {
	result ="diphones/eh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-y")==0) {
	result ="diphones/eh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-z")==0) {
	result ="diphones/eh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-zh")==0) {
	result ="diphones/eh-zh.wav";	
	}
	
	// er diphones
	
	if (g_strcmp0(diphone_str,"er-aa")==0) {
	result ="diphones/er-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ae")==0) {
	result ="diphones/er-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ah")==0) {
	result ="diphones/er-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ao")==0) {
	result ="diphones/er-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"er-aw")==0) {
	result ="diphones/er-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ax")==0) {
	result ="diphones/er-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ay")==0) {
	result ="diphones/er-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"er-b")==0) {
	result ="diphones/er-b.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ch")==0) {
	result ="diphones/er-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"er-d")==0) {
	result ="diphones/er-d.wav";	
	}
	if (g_strcmp0(diphone_str,"er-dh")==0) {
	result ="diphones/er-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-eh")==0) {
	result ="diphones/er-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-er")==0) {
	result ="diphones/er-er.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ey")==0) {
	result ="diphones/er-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"er-f")==0) {
	result ="diphones/er-f.wav";	
	}
	if (g_strcmp0(diphone_str,"er-g")==0) {
	result ="diphones/er-g.wav";	
	}
	if (g_strcmp0(diphone_str,"er-hh")==0) {
	result ="diphones/er-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ih")==0) {
	result ="diphones/er-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"er-iy")==0) {
	result ="diphones/er-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"er-jh")==0) {
	result ="diphones/er-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-k")==0) {
	result ="diphones/er-k.wav";	
	}
	if (g_strcmp0(diphone_str,"er-l")==0) {
	result ="diphones/er-l.wav";	
	}
	if (g_strcmp0(diphone_str,"er-m")==0) {
	result ="diphones/er-m.wav";	
	}
	if (g_strcmp0(diphone_str,"er-n")==0) {
	result ="diphones/er-n.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ng")==0) {
	result ="diphones/er-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ow")==0) {
	result ="diphones/er-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"er-oy")==0) {
	result ="diphones/er-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"er-p")==0) {
	result ="diphones/er-p.wav";	
	}
	if (g_strcmp0(diphone_str,"er-pau")==0) {
	result ="diphones/er-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"er-r")==0) {
	result ="diphones/er-r.wav";	
	}
	if (g_strcmp0(diphone_str,"er-s")==0) {
	result ="diphones/er-s.wav";	
	}
	if (g_strcmp0(diphone_str,"er-sh")==0) {
	result ="diphones/er-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-t")==0) {
	result ="diphones/er-t.wav";	
	}
	if (g_strcmp0(diphone_str,"er-th")==0) {
	result ="diphones/er-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"er-uh")==0) {
	result ="diphones/er-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-uw")==0) {
	result ="diphones/er-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"er-v")==0) {
	result ="diphones/er-v.wav";	
	}
	if (g_strcmp0(diphone_str,"er-w")==0) {
	result ="diphones/er-w.wav";	
	}
	if (g_strcmp0(diphone_str,"er-y")==0) {
	result ="diphones/er-y.wav";	
	}
	if (g_strcmp0(diphone_str,"er-z")==0) {
	result ="diphones/er-z.wav";	
	}
	if (g_strcmp0(diphone_str,"er-zh")==0) {
	result ="diphones/er-zh.wav";	
	}
	
	//ey diphones
	if (g_strcmp0(diphone_str,"ey-aa")==0) {
	result ="diphones/ey-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ae")==0) {
	result ="diphones/ey-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ah")==0) {
	result ="diphones/ey-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ao")==0) {
	result ="diphones/ey-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-aw")==0) {
	result ="diphones/ey-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ax")==0) {
	result ="diphones/ey-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ay")==0) {
	result ="diphones/ey-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-b")==0) {
	result ="diphones/ey-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ch")==0) {
	result ="diphones/ey-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-d")==0) {
	result ="diphones/ey-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-dh")==0) {
	result ="diphones/ey-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-eh")==0) {
	result ="diphones/ey-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-er")==0) {
	result ="diphones/ey-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ey")==0) {
	result ="diphones/ey-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-f")==0) {
	result ="diphones/ey-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-g")==0) {
	result ="diphones/ey-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-hh")==0) {
	result ="diphones/ey-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ih")==0) {
	result ="diphones/ey-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-iy")==0) {
	result ="diphones/ey-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-jh")==0) {
	result ="diphones/ey-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-k")==0) {
	result ="diphones/ey-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-l")==0) {
	result ="diphones/ey-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-m")==0) {
	result ="diphones/ey-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-n")==0) {
	result ="diphones/ey-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ng")==0) {
	result ="diphones/ey-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ow")==0) {
	result ="diphones/ey-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-oy")==0) {
	result ="diphones/ey-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-p")==0) {
	result ="diphones/ey-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-pau")==0) {
	result ="diphones/ey-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-r")==0) {
	result ="diphones/ey-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-s")==0) {
	result ="diphones/ey-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-sh")==0) {
	result ="diphones/ey-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-t")==0) {
	result ="diphones/ey-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-th")==0) {
	result ="diphones/ey-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ey-uh")==0) {
	result ="diphones/ey-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-uw")==0) {
	result ="diphones/ey-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-v")==0) {
	result ="diphones/ey-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-w")==0) {
	result ="diphones/ey-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-y")==0) {
	result ="diphones/ey-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-z")==0) {
	result ="diphones/ey-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-zh")==0) {
	result ="diphones/ey-zh.wav";	
	}
	
	//f diphones
	if (g_strcmp0(diphone_str,"f-aa")==0) {
	result ="diphones/f-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ae")==0) {
	result ="diphones/f-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ah")==0) {
	result ="diphones/f-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ao")==0) {
	result ="diphones/f-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"f-aw")==0) {
	result ="diphones/f-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ax")==0) {
	result ="diphones/f-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ay")==0) {
	result ="diphones/f-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"f-b")==0) {
	result ="diphones/f-b.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ch")==0) {
	result ="diphones/f-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"f-d")==0) {
	result ="diphones/f-d.wav";	
	}
	if (g_strcmp0(diphone_str,"f-dh")==0) {
	result ="diphones/f-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-eh")==0) {
	result ="diphones/f-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-er")==0) {
	result ="diphones/f-er.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ey")==0) {
	result ="diphones/f-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"f-f")==0) {
	result ="diphones/f-f.wav";	
	}
	if (g_strcmp0(diphone_str,"f-g")==0) {
	result ="diphones/f-g.wav";	
	}
	if (g_strcmp0(diphone_str,"f-hh")==0) {
	result ="diphones/f-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ih")==0) {
	result ="diphones/f-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"f-iy")==0) {
	result ="diphones/f-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"f-jh")==0) {
	result ="diphones/f-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-k")==0) {
	result ="diphones/f-k.wav";	
	}
	if (g_strcmp0(diphone_str,"f-l")==0) {
	result ="diphones/f-l.wav";	
	}
	if (g_strcmp0(diphone_str,"f-m")==0) {
	result ="diphones/f-m.wav";	
	}
	if (g_strcmp0(diphone_str,"f-n")==0) {
	result ="diphones/f-n.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ng")==0) {
	result ="diphones/f-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ow")==0) {
	result ="diphones/f-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"f-oy")==0) {
	result ="diphones/f-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"f-p")==0) {
	result ="diphones/f-p.wav";	
	}
	if (g_strcmp0(diphone_str,"f-pau")==0) {
	result ="diphones/f-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"f-r")==0) {
	result ="diphones/f-r.wav";	
	}
	if (g_strcmp0(diphone_str,"f-s")==0) {
	result ="diphones/f-s.wav";	
	}
	if (g_strcmp0(diphone_str,"f-sh")==0) {
	result ="diphones/f-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-t")==0) {
	result ="diphones/f-t.wav";	
	}
	if (g_strcmp0(diphone_str,"f-th")==0) {
	result ="diphones/f-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"f-uh")==0) {
	result ="diphones/f-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-uw")==0) {
	result ="diphones/f-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"f-v")==0) {
	result ="diphones/f-v.wav";	
	}
	if (g_strcmp0(diphone_str,"f-w")==0) {
	result ="diphones/f-w.wav";	
	}
	if (g_strcmp0(diphone_str,"f-y")==0) {
	result ="diphones/f-y.wav";	
	}
	if (g_strcmp0(diphone_str,"f-z")==0) {
	result ="diphones/f-z.wav";	
	}
	if (g_strcmp0(diphone_str,"f-zh")==0) {
	result ="diphones/f-zh.wav";	
	}
	
	//g diphones
	if (g_strcmp0(diphone_str,"g-aa")==0) {
	result ="diphones/g-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ae")==0) {
	result ="diphones/g-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ah")==0) {
	result ="diphones/g-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ao")==0) {
	result ="diphones/g-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"g-aw")==0) {
	result ="diphones/g-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ax")==0) {
	result ="diphones/g-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ay")==0) {
	result ="diphones/g-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"g-b")==0) {
	result ="diphones/g-b.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ch")==0) {
	result ="diphones/g-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"g-d")==0) {
	result ="diphones/g-d.wav";	
	}
	if (g_strcmp0(diphone_str,"g-dh")==0) {
	result ="diphones/g-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-eh")==0) {
	result ="diphones/g-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-er")==0) {
	result ="diphones/g-er.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ey")==0) {
	result ="diphones/g-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"g-f")==0) {
	result ="diphones/g-f.wav";	
	}
	if (g_strcmp0(diphone_str,"g-g")==0) {
	result ="diphones/g-g.wav";	
	}
	if (g_strcmp0(diphone_str,"g-hh")==0) {
	result ="diphones/g-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ih")==0) {
	result ="diphones/g-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"g-iy")==0) {
	result ="diphones/g-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"g-jh")==0) {
	result ="diphones/g-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-k")==0) {
	result ="diphones/g-k.wav";	
	}
	if (g_strcmp0(diphone_str,"g-l")==0) {
	result ="diphones/g-l.wav";	
	}
	if (g_strcmp0(diphone_str,"g-m")==0) {
	result ="diphones/g-m.wav";	
	}
	if (g_strcmp0(diphone_str,"g-n")==0) {
	result ="diphones/g-n.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ng")==0) {
	result ="diphones/g-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ow")==0) {
	result ="diphones/g-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"g-oy")==0) {
	result ="diphones/-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"g-p")==0) {
	result ="diphones/-p.wav";	
	}
	if (g_strcmp0(diphone_str,"g-pau")==0) {
	result ="diphones/g-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"g-r")==0) {
	result ="diphones/g-r.wav";	
	}
	if (g_strcmp0(diphone_str,"g-s")==0) {
	result ="diphones/g-s.wav";	
	}
	if (g_strcmp0(diphone_str,"g-sh")==0) {
	result ="diphones/g-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-t")==0) {
	result ="diphones/g-t.wav";	
	}
	if (g_strcmp0(diphone_str,"g-th")==0) {
	result ="diphones/g-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"g-uh")==0) {
	result ="diphones/g-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-uw")==0) {
	result ="diphones/g-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"g-v")==0) {
	result ="diphones/g-v.wav";	
	}
	if (g_strcmp0(diphone_str,"g-w")==0) {
	result ="diphones/g-w.wav";	
	}
	if (g_strcmp0(diphone_str,"g-y")==0) {
	result ="diphones/g-y.wav";	
	}
	if (g_strcmp0(diphone_str,"g-z")==0) {
	result ="diphones/g-z.wav";	
	}
	if (g_strcmp0(diphone_str,"g-zh")==0) {
	result ="diphones/g-zh.wav";	
	}
	
	//g alternatives
	if (g_strcmp0(diphone_str,"g_-_l")==0) {
	result ="diphones/g_-_l.wav";	
	}
	if (g_strcmp0(diphone_str,"g_-_r")==0) {
	result ="diphones/g_-_r.wav";	
	}
	if (g_strcmp0(diphone_str,"g_-_w")==0) {
	result ="diphones/g_-_w.wav";	
	}
	if (g_strcmp0(diphone_str,"g_-_y")==0) {
	result ="diphones/g_-_y.wav";	
	}
	
	//hh diphones
	if (g_strcmp0(diphone_str,"hh-aa")==0) {
	result ="diphones/hh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ae")==0) {
	result ="diphones/hh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ah")==0) {
	result ="diphones/hh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ao")==0) {
	result ="diphones/hh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-aw")==0) {
	result ="diphones/hh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ax")==0) {
	result ="diphones/hh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ay")==0) {
	result ="diphones/hh-ay.wav";	
	}
	//if (g_strcmp0(diphone_str,"hh-b")==0) {
	//result ="diphones/hh-b.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-ch")==0) {
	//result ="diphones/hh-ch.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-d")==0) {
	//result ="diphones/hh-d.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-dh")==0) {
	//result ="diphones/hh-dh.wav";	
	//}
	if (g_strcmp0(diphone_str,"hh-eh")==0) {
	result ="diphones/hh-eh.wav";	
	}
	//if (g_strcmp0(diphone_str,"hh-er")==0) {
	//result ="diphones/hh-er.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-ey")==0) {
	//result ="diphones/hh-ey.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-f")==0) {
	//result ="diphones/hh-f.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-g")==0) {
	//result ="diphones/hh-g.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-hh")==0) {
	//result ="diphones/hh-hh.wav";	
	//}
	if (g_strcmp0(diphone_str,"hh-ih")==0) {
	result ="diphones/hh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-iy")==0) {
	result ="diphones/hh-iy.wav";	
	}
	//if (g_strcmp0(diphone_str,"hh-jh")==0) {
	//result ="diphones/hh-jh.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-k")==0) {
	//result ="diphones/hh-k.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-l")==0) {
	//result ="diphones/hh-l.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-m")==0) {
	//result ="diphones/hh-m.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-n")==0) {
	//result ="diphones/hh-n.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-ng")==0) {
	//result ="diphones/hh-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"hh-ow")==0) {
	result ="diphones/hh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-oy")==0) {
	result ="diphones/hh-oy.wav";	
	}
	//if (g_strcmp0(diphone_str,"hh-p")==0) {
	//result ="diphones/hh-p.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-pau")==0) {
	//result ="diphones/hh-pau.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-r")==0) {
	//result ="diphones/hh-r.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-s")==0) {
	//result ="diphones/hh-s.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-sh")==0) {
	//result ="diphones/hh-sh.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-t")==0) {
	//result ="diphones/hh-t.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-th")==0) {
	//result ="diphones/hh-th.wav";	
	//}	
	if (g_strcmp0(diphone_str,"hh-uh")==0) {
	result ="diphones/hh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-uw")==0) {
	result ="diphones/hh-uw.wav";	
	}
	//if (g_strcmp0(diphone_str,"hh-v")==0) {
	//result ="diphones/-v.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-w")==0) {
	//result ="diphones/-w.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-y")==0) {
	//result ="diphones/hh-y.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-z")==0) {
	//result ="diphones/-z.wav";	
	//}
	//if (g_strcmp0(diphone_str,"hh-zh")==0) {
	//result ="diphones/hh-zh.wav";	
	//}
	
	//hh alternative
	if (g_strcmp0(diphone_str,"hh_-_y")==0) {
	result ="diphones/hh_-_y.wav";	
	}
	
	//ih diphones
	if (g_strcmp0(diphone_str,"ih-aa")==0) {
	result ="diphones/ih-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ae")==0) {
	result ="diphones/ih-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ah")==0) {
	result ="diphones/ih-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ao")==0) {
	result ="diphones/ih-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-aw")==0) {
	result ="diphones/ih-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ax")==0) {
	result ="diphones/ih-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ay")==0) {
	result ="diphones/ih-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-b")==0) {
	result ="diphones/ih-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ch")==0) {
	result ="diphones/ih-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-d")==0) {
	result ="diphones/ih-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-dh")==0) {
	result ="diphones/ih-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-eh")==0) {
	result ="diphones/ih-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-er")==0) {
	result ="diphones/ih-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ey")==0) {
	result ="diphones/ih-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-f")==0) {
	result ="diphones/ih-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-g")==0) {
	result ="diphones/ih-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-hh")==0) {
	result ="diphones/ih-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ih")==0) {
	result ="diphones/ih-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-iy")==0) {
	result ="diphones/ih-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-jh")==0) {
	result ="diphones/ih-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-k")==0) {
	result ="diphones/ih-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-l")==0) {
	result ="diphones/ih-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-m")==0) {
	result ="diphones/ih-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-n")==0) {
	result ="diphones/ih-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ng")==0) {
	result ="diphones/ih-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ow")==0) {
	result ="diphones/ih-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-oy")==0) {
	result ="diphones/ih-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-p")==0) {
	result ="diphones/ih-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-pau")==0) {
	result ="diphones/ih-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-r")==0) {
	result ="diphones/ih-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-s")==0) {
	result ="diphones/ih-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-sh")==0) {
	result ="diphones/ih-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-t")==0) {
	result ="diphones/ih-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-th")==0) {
	result ="diphones/ih-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ih-uh")==0) {
	result ="diphones/ih-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-uw")==0) {
	result ="diphones/ih-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-v")==0) {
	result ="diphones/ih-v.wav";	
	}
	if (g_strcmp0(diphone_str,"-w")==0) {
	result ="diphones/-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-y")==0) {
	result ="diphones/ih-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-z")==0) {
	result ="diphones/ih-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-zh")==0) {
	result ="diphones/ih-zh.wav";	
	}
	
	
	//iy diphones
	if (g_strcmp0(diphone_str,"iy-aa")==0) {
	result ="diphones/iy-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ae")==0) {
	result ="diphones/iy-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ah")==0) {
	result ="diphones/iy-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ao")==0) {
	result ="diphones/iy-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-aw")==0) {
	result ="diphones/iy-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ax")==0) {
	result ="diphones/iy-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ay")==0) {
	result ="diphones/iy-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-b")==0) {
	result ="diphones/iy-b.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ch")==0) {
	result ="diphones/iy-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-d")==0) {
	result ="diphones/iy-d.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-dh")==0) {
	result ="diphones/iy-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-eh")==0) {
	result ="diphones/iy-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-er")==0) {
	result ="diphones/iy-er.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ey")==0) {
	result ="diphones/iy-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-f")==0) {
	result ="diphones/iy-f.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-g")==0) {
	result ="diphones/iy-g.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-hh")==0) {
	result ="diphones/iy-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ih")==0) {
	result ="diphones/iy-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-iy")==0) {
	result ="diphones/iy-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-jh")==0) {
	result ="diphones/iy-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-k")==0) {
	result ="diphones/iy-k.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-l")==0) {
	result ="diphones/iy-l.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-m")==0) {
	result ="diphones/iy-m.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-n")==0) {
	result ="diphones/iy-n.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ng")==0) {
	result ="diphones/iy-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ow")==0) {
	result ="diphones/iy-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-oy")==0) {
	result ="diphones/iy-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-p")==0) {
	result ="diphones/iy-p.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-pau")==0) {
	result ="diphones/iy-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-r")==0) {
	result ="diphones/iy-r.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-s")==0) {
	result ="diphones/iy-s.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-sh")==0) {
	result ="diphones/iy-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-t")==0) {
	result ="diphones/iy-t.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-th")==0) {
	result ="diphones/iy-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"iy-uh")==0) {
	result ="diphones/iy-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-uw")==0) {
	result ="diphones/iy-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-v")==0) {
	result ="diphones/iy-v.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-w")==0) {
	result ="diphones/iy-w.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-y")==0) {
	result ="diphones/iy-y.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-z")==0) {
	result ="diphones/iy-z.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-zh")==0) {
	result ="diphones/iy-zh.wav";	
	}
	
	//jh diphones
	if (g_strcmp0(diphone_str,"jh-aa")==0) {
	result ="diphones/jh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ae")==0) {
	result ="diphones/jh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ah")==0) {
	result ="diphones/jh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ao")==0) {
	result ="diphones/jh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-aw")==0) {
	result ="diphones/jh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ax")==0) {
	result ="diphones/jh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ay")==0) {
	result ="diphones/jh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-b")==0) {
	result ="diphones/jh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ch")==0) {
	result ="diphones/jh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-d")==0) {
	result ="diphones/jh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-dh")==0) {
	result ="diphones/jh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-eh")==0) {
	result ="diphones/jh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-er")==0) {
	result ="diphones/jh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ey")==0) {
	result ="diphones/jh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-f")==0) {
	result ="diphones/jh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-g")==0) {
	result ="diphones/jh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-hh")==0) {
	result ="diphones/jh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ih")==0) {
	result ="diphones/jh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-iy")==0) {
	result ="diphones/jh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-jh")==0) {
	result ="diphones/jh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-k")==0) {
	result ="diphones/jh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-l")==0) {
	result ="diphones/jh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-m")==0) {
	result ="diphones/jh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-n")==0) {
	result ="diphones/jh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ng")==0) {
	result ="diphones/jh-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ow")==0) {
	result ="diphones/jh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-oy")==0) {
	result ="diphones/jh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-p")==0) {
	result ="diphones/jh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-pau")==0) {
	result ="diphones/jh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-r")==0) {
	result ="diphones/jh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-s")==0) {
	result ="diphones/jh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-sh")==0) {
	result ="diphones/jh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-t")==0) {
	result ="diphones/jh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-th")==0) {
	result ="diphones/jh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"jh-uh")==0) {
	result ="diphones/jh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-uw")==0) {
	result ="diphones/jh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-v")==0) {
	result ="diphones/jh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-w")==0) {
	result ="diphones/jh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-y")==0) {
	result ="diphones/jh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-z")==0) {
	result ="diphones/jh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-zh")==0) {
	result ="diphones/jh-zh.wav";	
	}
	
	//k diphones
	
	if (g_strcmp0(diphone_str,"k-aa")==0) {
	result ="diphones/k-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ae")==0) {
	result ="diphones/k-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ah")==0) {
	result ="diphones/k-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ao")==0) {
	result ="diphones/k-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"k-aw")==0) {
	result ="diphones/k-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ax")==0) {
	result ="diphones/k-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ay")==0) {
	result ="diphones/k-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"k-b")==0) {
	result ="diphones/k-b.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ch")==0) {
	result ="diphones/k-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"k-d")==0) {
	result ="diphones/k-d.wav";	
	}
	if (g_strcmp0(diphone_str,"k-dh")==0) {
	result ="diphones/k-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-eh")==0) {
	result ="diphones/k-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-er")==0) {
	result ="diphones/k-er.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ey")==0) {
	result ="diphones/k-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"k-f")==0) {
	result ="diphones/k-f.wav";	
	}
	if (g_strcmp0(diphone_str,"k-g")==0) {
	result ="diphones/k-g.wav";	
	}
	if (g_strcmp0(diphone_str,"k-hh")==0) {
	result ="diphones/k-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ih")==0) {
	result ="diphones/k-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"k-iy")==0) {
	result ="diphones/k-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"k-jh")==0) {
	result ="diphones/k-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-k")==0) {
	result ="diphones/k-k.wav";	
	}
	if (g_strcmp0(diphone_str,"k-l")==0) {
	result ="diphones/k-l.wav";	
	}
	if (g_strcmp0(diphone_str,"k-m")==0) {
	result ="diphones/k-m.wav";	
	}
	if (g_strcmp0(diphone_str,"k-n")==0) {
	result ="diphones/k-n.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ng")==0) {
	result ="diphones/k-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ow")==0) {
	result ="diphones/k-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"k-oy")==0) {
	result ="diphones/k-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"k-p")==0) {
	result ="diphones/k-p.wav";	
	}
	if (g_strcmp0(diphone_str,"k-pau")==0) {
	result ="diphones/k-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"k-r")==0) {
	result ="diphones/k-r.wav";	
	}
	if (g_strcmp0(diphone_str,"k-s")==0) {
	result ="diphones/k-s.wav";	
	}
	if (g_strcmp0(diphone_str,"k-sh")==0) {
	result ="diphones/k-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-t")==0) {
	result ="diphones/k-t.wav";	
	}
	if (g_strcmp0(diphone_str,"k-th")==0) {
	result ="diphones/k-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"k-uh")==0) {
	result ="diphones/k-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-uw")==0) {
	result ="diphones/k-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"k-v")==0) {
	result ="diphones/k-v.wav";	
	}
	if (g_strcmp0(diphone_str,"k-w")==0) {
	result ="diphones/k-w.wav";	
	}
	if (g_strcmp0(diphone_str,"k-y")==0) {
	result ="diphones/k-y.wav";	
	}
	if (g_strcmp0(diphone_str,"k-z")==0) {
	result ="diphones/k-z.wav";	
	}
	if (g_strcmp0(diphone_str,"k-zh")==0) {
	result ="diphones/k-zh.wav";	
	}
	
	//k alternatives
	if (g_strcmp0(diphone_str,"k_-_l")==0) {
	result ="diphones/k_-_l.wav";	
	}
	if (g_strcmp0(diphone_str,"k_-_r")==0) {
	result ="diphones/k_-_r.wav";	
	}
	if (g_strcmp0(diphone_str,"k_-_w")==0) {
	result ="diphones/k_-_w.wav";	
	}
	if (g_strcmp0(diphone_str,"k_-_y")==0) {
	result ="diphones/k_-_y.wav";	
	}
	
	//l diphones
	if (g_strcmp0(diphone_str,"l-aa")==0) {
	result ="diphones/l-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ae")==0) {
	result ="diphones/l-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ah")==0) {
	result ="diphones/l-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ao")==0) {
	result ="diphones/l-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"l-aw")==0) {
	result ="diphones/l-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ax")==0) {
	result ="diphones/l-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ay")==0) {
	result ="diphones/l-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"l-b")==0) {
	result ="diphones/l-b.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ch")==0) {
	result ="diphones/l-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"l-d")==0) {
	result ="diphones/l-d.wav";	
	}
	if (g_strcmp0(diphone_str,"l-dh")==0) {
	result ="diphones/l-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-eh")==0) {
	result ="diphones/l-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-er")==0) {
	result ="diphones/l-er.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ey")==0) {
	result ="diphones/l-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"l-f")==0) {
	result ="diphones/l-f.wav";	
	}
	if (g_strcmp0(diphone_str,"l-g")==0) {
	result ="diphones/l-g.wav";	
	}
	if (g_strcmp0(diphone_str,"l-hh")==0) {
	result ="diphones/l-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ih")==0) {
	result ="diphones/l-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"l-iy")==0) {
	result ="diphones/l-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"l-jh")==0) {
	result ="diphones/l-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-k")==0) {
	result ="diphones/l-k.wav";	
	}
	if (g_strcmp0(diphone_str,"l-l")==0) {
	result ="diphones/l-l.wav";	
	}
	if (g_strcmp0(diphone_str,"l-m")==0) {
	result ="diphones/l-m.wav";	
	}
	if (g_strcmp0(diphone_str,"l-n")==0) {
	result ="diphones/l-n.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ng")==0) {
	result ="diphones/l-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ow")==0) {
	result ="diphones/l-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"l-oy")==0) {
	result ="diphones/l-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"l-p")==0) {
	result ="diphones/l-p.wav";	
	}
	if (g_strcmp0(diphone_str,"l-pau")==0) {
	result ="diphones/l-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"l-r")==0) {
	result ="diphones/l-r.wav";	
	}
	if (g_strcmp0(diphone_str,"l-s")==0) {
	result ="diphones/l-s.wav";	
	}
	if (g_strcmp0(diphone_str,"l-sh")==0) {
	result ="diphones/l-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-t")==0) {
	result ="diphones/l-t.wav";	
	}
	if (g_strcmp0(diphone_str,"l-th")==0) {
	result ="diphones/l-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"l-uh")==0) {
	result ="diphones/l-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-uw")==0) {
	result ="diphones/l-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"l-v")==0) {
	result ="diphones/l-v.wav";	
	}
	if (g_strcmp0(diphone_str,"l-w")==0) {
	result ="diphones/l-w.wav";	
	}
	if (g_strcmp0(diphone_str,"l-y")==0) {
	result ="diphones/l-y.wav";	
	}
	if (g_strcmp0(diphone_str,"l-z")==0) {
	result ="diphones/l-z.wav";	
	}
	if (g_strcmp0(diphone_str,"l-zh")==0) {
	result ="diphones/l-zh.wav";	
	}
	
	//m diphones
	if (g_strcmp0(diphone_str,"m-aa")==0) {
	result ="diphones/m-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ae")==0) {
	result ="diphones/m-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ah")==0) {
	result ="diphones/m-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ao")==0) {
	result ="diphones/m-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"m-aw")==0) {
	result ="diphones/m-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ax")==0) {
	result ="diphones/m-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ay")==0) {
	result ="diphones/m-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"m-b")==0) {
	result ="diphones/m-b.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ch")==0) {
	result ="diphones/m-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"m-d")==0) {
	result ="diphones/m-d.wav";	
	}
	if (g_strcmp0(diphone_str,"m-dh")==0) {
	result ="diphones/m-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-eh")==0) {
	result ="diphones/m-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-er")==0) {
	result ="diphones/m-er.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ey")==0) {
	result ="diphones/m-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"m-f")==0) {
	result ="diphones/m-f.wav";	
	}
	if (g_strcmp0(diphone_str,"m-g")==0) {
	result ="diphones/m-g.wav";	
	}
	if (g_strcmp0(diphone_str,"m-hh")==0) {
	result ="diphones/m-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ih")==0) {
	result ="diphones/m-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"m-iy")==0) {
	result ="diphones/m-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"m-jh")==0) {
	result ="diphones/m-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-k")==0) {
	result ="diphones/m-k.wav";	
	}
	if (g_strcmp0(diphone_str,"m-l")==0) {
	result ="diphones/m-l.wav";	
	}
	if (g_strcmp0(diphone_str,"m-m")==0) {
	result ="diphones/m-m.wav";	
	}
	if (g_strcmp0(diphone_str,"m-n")==0) {
	result ="diphones/m-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"m-ng")==0) {
	//result ="diphones/m-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"m-ow")==0) {
	result ="diphones/m-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"m-oy")==0) {
	result ="diphones/m-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"m-p")==0) {
	result ="diphones/m-p.wav";	
	}
	if (g_strcmp0(diphone_str,"m-pau")==0) {
	result ="diphones/m-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"m-r")==0) {
	result ="diphones/m-r.wav";	
	}
	if (g_strcmp0(diphone_str,"m-s")==0) {
	result ="diphones/m-s.wav";	
	}
	if (g_strcmp0(diphone_str,"m-sh")==0) {
	result ="diphones/m-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-t")==0) {
	result ="diphones/m-t.wav";	
	}
	if (g_strcmp0(diphone_str,"m-th")==0) {
	result ="diphones/m-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"m-uh")==0) {
	result ="diphones/m-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-uw")==0) {
	result ="diphones/m-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"m-v")==0) {
	result ="diphones/m-v.wav";	
	}
	if (g_strcmp0(diphone_str,"m-w")==0) {
	result ="diphones/m-w.wav";	
	}
	if (g_strcmp0(diphone_str,"m-y")==0) {
	result ="diphones/m-y.wav";	
	}
	if (g_strcmp0(diphone_str,"m-z")==0) {
	result ="diphones/m-z.wav";	
	}
	if (g_strcmp0(diphone_str,"m-zh")==0) {
	result ="diphones/m-zh.wav";	
	}
	
	//n diphones
	if (g_strcmp0(diphone_str,"n-aa")==0) {
	result ="diphones/n-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ae")==0) {
	result ="diphones/n-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ah")==0) {
	result ="diphones/n-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ao")==0) {
	result ="diphones/n-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"n-aw")==0) {
	result ="diphones/n-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ax")==0) {
	result ="diphones/n-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ay")==0) {
	result ="diphones/n-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"n-b")==0) {
	result ="diphones/n-b.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ch")==0) {
	result ="diphones/n-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"n-d")==0) {
	result ="diphones/n-d.wav";	
	}
	if (g_strcmp0(diphone_str,"n-dh")==0) {
	result ="diphones/n-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-eh")==0) {
	result ="diphones/n-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-er")==0) {
	result ="diphones/n-er.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ey")==0) {
	result ="diphones/n-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"n-f")==0) {
	result ="diphones/n-f.wav";	
	}
	if (g_strcmp0(diphone_str,"n-g")==0) {
	result ="diphones/n-g.wav";	
	}
	if (g_strcmp0(diphone_str,"n-hh")==0) {
	result ="diphones/n-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ih")==0) {
	result ="diphones/n-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"n-iy")==0) {
	result ="diphones/n-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"n-jh")==0) {
	result ="diphones/n-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-k")==0) {
	result ="diphones/n-k.wav";	
	}
	if (g_strcmp0(diphone_str,"n-l")==0) {
	result ="diphones/n-l.wav";	
	}
	if (g_strcmp0(diphone_str,"n-m")==0) {
	result ="diphones/n-m.wav";	
	}
	if (g_strcmp0(diphone_str,"n-n")==0) {
	result ="diphones/n-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"n-ng")==0) {
	//result ="diphones/n-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"n-ow")==0) {
	result ="diphones/n-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"n-oy")==0) {
	result ="diphones/n-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"n-p")==0) {
	result ="diphones/n-p.wav";	
	}
	if (g_strcmp0(diphone_str,"n-pau")==0) {
	result ="diphones/n-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"n-r")==0) {
	result ="diphones/n-r.wav";	
	}
	if (g_strcmp0(diphone_str,"n-s")==0) {
	result ="diphones/n-s.wav";	
	}
	if (g_strcmp0(diphone_str,"n-sh")==0) {
	result ="diphones/n-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-t")==0) {
	result ="diphones/n-t.wav";	
	}
	if (g_strcmp0(diphone_str,"n-th")==0) {
	result ="diphones/n-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"n-uh")==0) {
	result ="diphones/n-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-uw")==0) {
	result ="diphones/n-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"n-v")==0) {
	result ="diphones/-v.wav";	
	}
	if (g_strcmp0(diphone_str,"n-w")==0) {
	result ="diphones/n-w.wav";	
	}
	if (g_strcmp0(diphone_str,"n-y")==0) {
	result ="diphones/n-y.wav";	
	}
	if (g_strcmp0(diphone_str,"n-z")==0) {
	result ="diphones/n-z.wav";	
	}
	if (g_strcmp0(diphone_str,"n-zh")==0) {
	result ="diphones/-zh.wav";	
	}
	
	//n alternatives
	if (g_strcmp0(diphone_str,"n_-_y")==0) {
	result ="diphones/n_-_y.wav";	
	}
	

	//ng diphones
	if (g_strcmp0(diphone_str,"ng-aa")==0) {
	result ="diphones/ng-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ae")==0) {
	result ="diphones/ng-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ah")==0) {
	result ="diphones/ng-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ao")==0) {
	result ="diphones/ng-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-aw")==0) {
	result ="diphones/ng-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ax")==0) {
	result ="diphones/ng-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ay")==0) {
	result ="diphones/ng-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-b")==0) {
	result ="diphones/ng-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ch")==0) {
	result ="diphones/ng-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-d")==0) {
	result ="diphones/ng-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-dh")==0) {
	result ="diphones/ng-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-eh")==0) {
	result ="diphones/ng-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-er")==0) {
	result ="diphones/ng-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ey")==0) {
	result ="diphones/ng-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-f")==0) {
	result ="diphones/ng-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-g")==0) {
	result ="diphones/ng-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-hh")==0) {
	result ="diphones/ng-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ih")==0) {
	result ="diphones/ng-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-iy")==0) {
	result ="diphones/ng-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-jh")==0) {
	result ="diphones/ng-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-k")==0) {
	result ="diphones/ng-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-l")==0) {
	result ="diphones/ng-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-m")==0) {
	result ="diphones/ng-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-n")==0) {
	result ="diphones/-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"ng-ng")==0) {
	//result ="diphones/ng-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"ng-ow")==0) {
	result ="diphones/ng-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-oy")==0) {
	result ="diphones/ng-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-p")==0) {
	result ="diphones/ng-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-pau")==0) {
	result ="diphones/ng-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-r")==0) {
	result ="diphones/ng-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-s")==0) {
	result ="diphones/ng-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-sh")==0) {
	result ="diphones/ng-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-t")==0) {
	result ="diphones/ng-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-th")==0) {
	result ="diphones/ng-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ng-uh")==0) {
	result ="diphones/ng-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-uw")==0) {
	result ="diphones/ng-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-v")==0) {
	result ="diphones/ng-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-w")==0) {
	result ="diphones/ng-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-y")==0) {
	result ="diphones/ng-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-z")==0) {
	result ="diphones/ng-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-zh")==0) {
	result ="diphones/ng-zh.wav";	
	}
	
	//ow diphones
	if (g_strcmp0(diphone_str,"ow-aa")==0) {
	result ="diphones/ow-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ae")==0) {
	result ="diphones/ow-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ah")==0) {
	result ="diphones/ow-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ao")==0) {
	result ="diphones/ow-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-aw")==0) {
	result ="diphones/ow-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ax")==0) {
	result ="diphones/ow-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ay")==0) {
	result ="diphones/ow-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-b")==0) {
	result ="diphones/ow-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ch")==0) {
	result ="diphones/ow-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-d")==0) {
	result ="diphones/ow-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-dh")==0) {
	result ="diphones/ow-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-eh")==0) {
	result ="diphones/ow-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-er")==0) {
	result ="diphones/ow-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ey")==0) {
	result ="diphones/ow-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-f")==0) {
	result ="diphones/ow-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-g")==0) {
	result ="diphones/ow-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-hh")==0) {
	result ="diphones/ow-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ih")==0) {
	result ="diphones/ow-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-iy")==0) {
	result ="diphones/ow-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-jh")==0) {
	result ="diphones/ow-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-k")==0) {
	result ="diphones/ow-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-l")==0) {
	result ="diphones/ow-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-m")==0) {
	result ="diphones/ow-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-n")==0) {
	result ="diphones/ow-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ng")==0) {
	result ="diphones/ow-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ow")==0) {
	result ="diphones/ow-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-oy")==0) {
	result ="diphones/ow-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-p")==0) {
	result ="diphones/ow-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-pau")==0) {
	result ="diphones/ow-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-r")==0) {
	result ="diphones/ow-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-s")==0) {
	result ="diphones/ow-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-sh")==0) {
	result ="diphones/ow-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-t")==0) {
	result ="diphones/ow-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-th")==0) {
	result ="diphones/ow-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ow-uh")==0) {
	result ="diphones/ow-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-uw")==0) {
	result ="diphones/ow-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-v")==0) {
	result ="diphones/ow-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-w")==0) {
	result ="diphones/ow-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-y")==0) {
	result ="diphones/ow-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-z")==0) {
	result ="diphones/ow-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-zh")==0) {
	result ="diphones/ow-zh.wav";	
	}
	
	//oy diphones
	if (g_strcmp0(diphone_str,"oy-aa")==0) {
	result ="diphones/oy-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ae")==0) {
	result ="diphones/oy-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ah")==0) {
	result ="diphones/oy-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ao")==0) {
	result ="diphones/oy-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-aw")==0) {
	result ="diphones/oy-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ax")==0) {
	result ="diphones/oy-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ay")==0) {
	result ="diphones/oy-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-b")==0) {
	result ="diphones/oy-b.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ch")==0) {
	result ="diphones/oy-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-d")==0) {
	result ="diphones/oy-d.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-dh")==0) {
	result ="diphones/oy-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-eh")==0) {
	result ="diphones/oy-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-er")==0) {
	result ="diphones/oy-er.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ey")==0) {
	result ="diphones/oy-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-f")==0) {
	result ="diphones/oy-f.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-g")==0) {
	result ="diphones/oy-g.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-hh")==0) {
	result ="diphones/oy-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ih")==0) {
	result ="diphones/oy-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-iy")==0) {
	result ="diphones/oy-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-jh")==0) {
	result ="diphones/oy-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-k")==0) {
	result ="diphones/oy-k.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-l")==0) {
	result ="diphones/oy-l.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-m")==0) {
	result ="diphones/oy-m.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-n")==0) {
	result ="diphones/oy-n.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ng")==0) {
	result ="diphones/oy-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ow")==0) {
	result ="diphones/oy-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-oy")==0) {
	result ="diphones/oy-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-p")==0) {
	result ="diphones/oy-p.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-pau")==0) {
	result ="diphones/oy-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-r")==0) {
	result ="diphones/oy-r.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-s")==0) {
	result ="diphones/oy-s.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-sh")==0) {
	result ="diphones/oy-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-t")==0) {
	result ="diphones/oy-t.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-th")==0) {
	result ="diphones/oy-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"oy-uh")==0) {
	result ="diphones/oy-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-uw")==0) {
	result ="diphones/oy-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-v")==0) {
	result ="diphones/oy-v.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-w")==0) {
	result ="diphones/oy-w.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-y")==0) {
	result ="diphones/oy-y.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-z")==0) {
	result ="diphones/oy-z.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-zh")==0) {
	result ="diphones/oy-zh.wav";	
	}
	
	//p diphones
	if (g_strcmp0(diphone_str,"p-aa")==0) {
	result ="diphones/p-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ae")==0) {
	result ="diphones/p-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ah")==0) {
	result ="diphones/p-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ao")==0) {
	result ="diphones/p-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"p-aw")==0) {
	result ="diphones/p-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ax")==0) {
	result ="diphones/p-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ay")==0) {
	result ="diphones/p-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"p-b")==0) {
	result ="diphones/p-b.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ch")==0) {
	result ="diphones/p-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"p-d")==0) {
	result ="diphones/p-d.wav";	
	}
	if (g_strcmp0(diphone_str,"p-dh")==0) {
	result ="diphones/p-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-eh")==0) {
	result ="diphones/p-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-er")==0) {
	result ="diphones/p-er.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ey")==0) {
	result ="diphones/p-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"p-f")==0) {
	result ="diphones/p-f.wav";	
	}
	if (g_strcmp0(diphone_str,"p-g")==0) {
	result ="diphones/p-g.wav";	
	}
	if (g_strcmp0(diphone_str,"p-hh")==0) {
	result ="diphones/p-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"-ih")==0) {
	result ="diphones/-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"p-iy")==0) {
	result ="diphones/p-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"p-jh")==0) {
	result ="diphones/p-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-k")==0) {
	result ="diphones/p-k.wav";	
	}
	if (g_strcmp0(diphone_str,"p-l")==0) {
	result ="diphones/p-l.wav";	
	}
	if (g_strcmp0(diphone_str,"p-m")==0) {
	result ="diphones/p-m.wav";	
	}
	if (g_strcmp0(diphone_str,"p-n")==0) {
	result ="diphones/p-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"p-ng")==0) {
	//result ="diphones/p-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"p-ow")==0) {
	result ="diphones/p-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"p-oy")==0) {
	result ="diphones/p-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"p-p")==0) {
	result ="diphones/p-p.wav";	
	}
	if (g_strcmp0(diphone_str,"p-pau")==0) {
	result ="diphones/p-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"p-r")==0) {
	result ="diphones/p-r.wav";	
	}
	if (g_strcmp0(diphone_str,"p-s")==0) {
	result ="diphones/p-s.wav";	
	}
	if (g_strcmp0(diphone_str,"p-sh")==0) {
	result ="diphones/p-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-t")==0) {
	result ="diphones/p-t.wav";	
	}
	if (g_strcmp0(diphone_str,"p-th")==0) {
	result ="diphones/p-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"p-uh")==0) {
	result ="diphones/p-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-uw")==0) {
	result ="diphones/p-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"p-v")==0) {
	result ="diphones/p-v.wav";	
	}
	if (g_strcmp0(diphone_str,"p-w")==0) {
	result ="diphones/p-w.wav";	
	}
	if (g_strcmp0(diphone_str,"p-y")==0) {
	result ="diphones/p-y.wav";	
	}
	if (g_strcmp0(diphone_str,"p-z")==0) {
	result ="diphones/p-z.wav";	
	}
	if (g_strcmp0(diphone_str,"p-zh")==0) {
	result ="diphones/p-zh.wav";	
	}
	
	// p alternatives
	if (g_strcmp0(diphone_str,"p_-_l")==0) {
	result ="diphones/p_-_l.wav";	
	}
	if (g_strcmp0(diphone_str,"p_-_r")==0) {
	result ="diphones/p_-_r.wav";	
	}
	if (g_strcmp0(diphone_str,"p_-_w")==0) {
	result ="diphones/p_-_w.wav";	
	}
	if (g_strcmp0(diphone_str,"p_-_y")==0) {
	result ="diphones/p_-_y.wav";	
	}
	
	//pau diphones
	if (g_strcmp0(diphone_str,"pau-aa")==0) {
	result ="diphones/pau-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ae")==0) {
	result ="diphones/pau-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ah")==0) {
	result ="diphones/pau-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ao")==0) {
	result ="diphones/pau-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-aw")==0) {
	result ="diphones/pau-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ax")==0) {
	result ="diphones/pau-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ay")==0) {
	result ="diphones/pau-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-b")==0) {
	result ="diphones/pau-b.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ch")==0) {
	result ="diphones/pau-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-d")==0) {
	result ="diphones/pau-d.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-dh")==0) {
	result ="diphones/pau-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-eh")==0) {
	result ="diphones/pau-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-er")==0) {
	result ="diphones/pau-er.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ey")==0) {
	result ="diphones/pau-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-f")==0) {
	result ="diphones/pau-f.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-g")==0) {
	result ="diphones/pau-g.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-hh")==0) {
	result ="diphones/pau-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ih")==0) {
	result ="diphones/pau-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-iy")==0) {
	result ="diphones/pau-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-jh")==0) {
	result ="diphones/pau-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-k")==0) {
	result ="diphones/pau-k.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-l")==0) {
	result ="diphones/pau-l.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-m")==0) {
	result ="diphones/pau-m.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-n")==0) {
	result ="diphones/pau-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"pau-ng")==0) {
	//result ="diphones/pau-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"pau-ow")==0) {
	result ="diphones/pau-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-oy")==0) {
	result ="diphones/pau-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-p")==0) {
	result ="diphones/pau-p.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-pau")==0) {
	result ="diphones/pau-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-r")==0) {
	result ="diphones/pau-r.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-s")==0) {
	result ="diphones/pau-s.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-sh")==0) {
	result ="diphones/pau-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-t")==0) {
	result ="diphones/pau-t.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-th")==0) {
	result ="diphones/pau-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"pau-uh")==0) {
	result ="diphones/pau-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-uw")==0) {
	result ="diphones/pau-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-v")==0) {
	result ="diphones/pau-v.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-w")==0) {
	result ="diphones/pau-w.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-y")==0) {
	result ="diphones/pau-y.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-z")==0) {
	result ="diphones/pau-z.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-zh")==0) {
	result ="diphones/pau-zh.wav";	
	}
	
	//r diphones
	
	if (g_strcmp0(diphone_str,"r-aa")==0) {
	result ="diphones/r-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ae")==0) {
	result ="diphones/r-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ah")==0) {
	result ="diphones/r-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ao")==0) {
	result ="diphones/r-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"r-aw")==0) {
	result ="diphones/r-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ax")==0) {
	result ="diphones/r-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ay")==0) {
	result ="diphones/r-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"r-b")==0) {
	result ="diphones/r-b.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ch")==0) {
	result ="diphones/r-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"r-d")==0) {
	result ="diphones/r-d.wav";	
	}
	if (g_strcmp0(diphone_str,"r-dh")==0) {
	result ="diphones/r-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-eh")==0) {
	result ="diphones/r-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-er")==0) {
	result ="diphones/r-er.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ey")==0) {
	result ="diphones/r-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"r-f")==0) {
	result ="diphones/r-f.wav";	
	}
	if (g_strcmp0(diphone_str,"r-g")==0) {
	result ="diphones/r-g.wav";	
	}
	if (g_strcmp0(diphone_str,"r-hh")==0) {
	result ="diphones/r-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ih")==0) {
	result ="diphones/r-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"r-iy")==0) {
	result ="diphones/r-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"r-jh")==0) {
	result ="diphones/r-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-k")==0) {
	result ="diphones/r-k.wav";	
	}
	if (g_strcmp0(diphone_str,"r-l")==0) {
	result ="diphones/r-l.wav";	
	}
	if (g_strcmp0(diphone_str,"r-m")==0) {
	result ="diphones/r-m.wav";	
	}
	if (g_strcmp0(diphone_str,"r-n")==0) {
	result ="diphones/r-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"r-ng")==0) {
	//result ="diphones/r-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"r-ow")==0) {
	result ="diphones/r-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"r-oy")==0) {
	result ="diphones/r-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"r-p")==0) {
	result ="diphones/r-p.wav";	
	}
	if (g_strcmp0(diphone_str,"r-pau")==0) {
	result ="diphones/r-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"r-r")==0) {
	result ="diphones/r-r.wav";	
	}
	if (g_strcmp0(diphone_str,"r-s")==0) {
	result ="diphones/r-s.wav";	
	}
	if (g_strcmp0(diphone_str,"r-sh")==0) {
	result ="diphones/r-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-t")==0) {
	result ="diphones/r-t.wav";	
	}
	if (g_strcmp0(diphone_str,"r-th")==0) {
	result ="diphones/r-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"r-uh")==0) {
	result ="diphones/r-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-uw")==0) {
	result ="diphones/r-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"r-v")==0) {
	result ="diphones/r-v.wav";	
	}
	if (g_strcmp0(diphone_str,"r-w")==0) {
	result ="diphones/r-w.wav";	
	}
	if (g_strcmp0(diphone_str,"r-y")==0) {
	result ="diphones/r-y.wav";	
	}
	if (g_strcmp0(diphone_str,"r-z")==0) {
	result ="diphones/r-z.wav";	
	}
	if (g_strcmp0(diphone_str,"r-zh")==0) {
	result ="diphones/r-zh.wav";	
	}
	
	//s diphones
	if (g_strcmp0(diphone_str,"s-aa")==0) {
	result ="diphones/s-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ae")==0) {
	result ="diphones/s-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ah")==0) {
	result ="diphones/s-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ao")==0) {
	result ="diphones/s-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"s-aw")==0) {
	result ="diphones/s-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ax")==0) {
	result ="diphones/s-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ay")==0) {
	result ="diphones/s-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"s-b")==0) {
	result ="diphones/s-b.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ch")==0) {
	result ="diphones/s-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"s-d")==0) {
	result ="diphones/s-d.wav";	
	}
	if (g_strcmp0(diphone_str,"s-dh")==0) {
	result ="diphones/s-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-eh")==0) {
	result ="diphones/s-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-er")==0) {
	result ="diphones/s-er.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ey")==0) {
	result ="diphones/s-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"s-f")==0) {
	result ="diphones/s-f.wav";	
	}
	if (g_strcmp0(diphone_str,"s-g")==0) {
	result ="diphones/s-g.wav";	
	}
	if (g_strcmp0(diphone_str,"s-hh")==0) {
	result ="diphones/s-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ih")==0) {
	result ="diphones/s-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"s-iy")==0) {
	result ="diphones/s-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"s-jh")==0) {
	result ="diphones/s-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-k")==0) {
	result ="diphones/s-k.wav";	
	}
	if (g_strcmp0(diphone_str,"s-l")==0) {
	result ="diphones/s-l.wav";	
	}
	if (g_strcmp0(diphone_str,"s-m")==0) {
	result ="diphones/s-m.wav";	
	}
	if (g_strcmp0(diphone_str,"s-n")==0) {
	result ="diphones/s-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"s-ng")==0) {
	//result ="diphones/s-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"s-ow")==0) {
	result ="diphones/s-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"s-oy")==0) {
	result ="diphones/s-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"s-p")==0) {
	result ="diphones/s-p.wav";	
	}
	if (g_strcmp0(diphone_str,"s-pau")==0) {
	result ="diphones/s-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"s-r")==0) {
	result ="diphones/s-r.wav";	
	}
	if (g_strcmp0(diphone_str,"s-s")==0) {
	result ="diphones/s-s.wav";	
	}
	if (g_strcmp0(diphone_str,"s-sh")==0) {
	result ="diphones/s-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-t")==0) {
	result ="diphones/s-t.wav";	
	}
	if (g_strcmp0(diphone_str,"s-th")==0) {
	result ="diphones/s-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"s-uh")==0) {
	result ="diphones/s-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-uw")==0) {
	result ="diphones/s-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"s-v")==0) {
	result ="diphones/s-v.wav";	
	}
	if (g_strcmp0(diphone_str,"s-w")==0) {
	result ="diphones/s-w.wav";	
	}
	if (g_strcmp0(diphone_str,"s-y")==0) {
	result ="diphones/s-y.wav";	
	}
	if (g_strcmp0(diphone_str,"s-z")==0) {
	result ="diphones/s-z.wav";	
	}
	if (g_strcmp0(diphone_str,"s-zh")==0) {
	result ="diphones/-zh.wav";	
	}
	
	//s alternatives
	if (g_strcmp0(diphone_str,"s_-_k")==0) {
	result ="diphones/s_-_k.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_l")==0) {
	result ="diphones/s_-_l.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_m")==0) {
	result ="diphones/s_-_m.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_n")==0) {
	result ="diphones/s_-_n.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_p")==0) {
	result ="diphones/s_-_p.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_t")==0) {
	result ="diphones/s_-_t.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_y")==0) {
	result ="diphones/s_-_y.wav";	
	}
	
	//sh diphones
	if (g_strcmp0(diphone_str,"sh-aa")==0) {
	result ="diphones/sh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ae")==0) {
	result ="diphones/sh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ah")==0) {
	result ="diphones/sh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ao")==0) {
	result ="diphones/sh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-aw")==0) {
	result ="diphones/sh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ax")==0) {
	result ="diphones/sh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ay")==0) {
	result ="diphones/sh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-b")==0) {
	result ="diphones/sh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ch")==0) {
	result ="diphones/sh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-d")==0) {
	result ="diphones/sh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-dh")==0) {
	result ="diphones/sh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-eh")==0) {
	result ="diphones/sh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-er")==0) {
	result ="diphones/sh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ey")==0) {
	result ="diphones/sh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-f")==0) {
	result ="diphones/sh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-g")==0) {
	result ="diphones/sh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-hh")==0) {
	result ="diphones/sh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ih")==0) {
	result ="diphones/sh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-iy")==0) {
	result ="diphones/sh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-jh")==0) {
	result ="diphones/sh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-k")==0) {
	result ="diphones/sh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-l")==0) {
	result ="diphones/sh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-m")==0) {
	result ="diphones/sh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-n")==0) {
	result ="diphones/sh-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"sh-ng")==0) {
	//result ="diphones/sh-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"sh-ow")==0) {
	result ="diphones/sh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-oy")==0) {
	result ="diphones/sh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-p")==0) {
	result ="diphones/sh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-pau")==0) {
	result ="diphones/sh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-r")==0) {
	result ="diphones/sh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-s")==0) {
	result ="diphones/sh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-sh")==0) {
	result ="diphones/sh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-t")==0) {
	result ="diphones/sh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-th")==0) {
	result ="diphones/sh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"sh-uh")==0) {
	result ="diphones/sh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-uw")==0) {
	result ="diphones/sh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-v")==0) {
	result ="diphones/sh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-w")==0) {
	result ="diphones/sh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-y")==0) {
	result ="diphones/sh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-z")==0) {
	result ="diphones/sh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-zh")==0) {
	result ="diphones/sh-zh.wav";	
	}
	
	//t diphones
	if (g_strcmp0(diphone_str,"t-aa")==0) {
	result ="diphones/t-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ae")==0) {
	result ="diphones/t-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ah")==0) {
	result ="diphones/t-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ao")==0) {
	result ="diphones/t-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"t-aw")==0) {
	result ="diphones/t-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ax")==0) {
	result ="diphones/t-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ay")==0) {
	result ="diphones/t-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"t-b")==0) {
	result ="diphones/t-b.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ch")==0) {
	result ="diphones/t-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"t-d")==0) {
	result ="diphones/t-d.wav";	
	}
	if (g_strcmp0(diphone_str,"t-dh")==0) {
	result ="diphones/t-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-eh")==0) {
	result ="diphones/t-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-er")==0) {
	result ="diphones/t-er.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ey")==0) {
	result ="diphones/t-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"t-f")==0) {
	result ="diphones/t-f.wav";	
	}
	if (g_strcmp0(diphone_str,"t-g")==0) {
	result ="diphones/t-g.wav";	
	}
	if (g_strcmp0(diphone_str,"t-hh")==0) {
	result ="diphones/t-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ih")==0) {
	result ="diphones/t-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"t-iy")==0) {
	result ="diphones/t-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"t-jh")==0) {
	result ="diphones/t-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-k")==0) {
	result ="diphones/t-k.wav";	
	}
	if (g_strcmp0(diphone_str,"t-l")==0) {
	result ="diphones/t-l.wav";	
	}
	if (g_strcmp0(diphone_str,"t-m")==0) {
	result ="diphones/t-m.wav";	
	}
	if (g_strcmp0(diphone_str,"t-n")==0) {
	result ="diphones/t-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"t-ng")==0) {
	//result ="diphones/t-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"t-ow")==0) {
	result ="diphones/t-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"t-oy")==0) {
	result ="diphones/t-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"t-p")==0) {
	result ="diphones/t-p.wav";	
	}
	if (g_strcmp0(diphone_str,"t-pau")==0) {
	result ="diphones/t-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"t-r")==0) {
	result ="diphones/t-r.wav";	
	}
	if (g_strcmp0(diphone_str,"t-s")==0) {
	result ="diphones/t-s.wav";	
	}
	if (g_strcmp0(diphone_str,"t-sh")==0) {
	result ="diphones/t-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"-t")==0) {
	result ="diphones/-t.wav";	
	}
	if (g_strcmp0(diphone_str,"t-th")==0) {
	result ="diphones/t-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"t-uh")==0) {
	result ="diphones/t-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-uw")==0) {
	result ="diphones/t-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"t-v")==0) {
	result ="diphones/t-v.wav";	
	}
	if (g_strcmp0(diphone_str,"t-w")==0) {
	result ="diphones/t-w.wav";	
	}
	if (g_strcmp0(diphone_str,"t-y")==0) {
	result ="diphones/t-y.wav";	
	}
	if (g_strcmp0(diphone_str,"t-z")==0) {
	result ="diphones/t-z.wav";	
	}
	if (g_strcmp0(diphone_str,"t-zh")==0) {
	result ="diphones/t-zh.wav";	
	}
	
	//t alternatives
	if (g_strcmp0(diphone_str,"t_-_l")==0) {
	result ="diphones/t_-_l.wav";	
	}
	if (g_strcmp0(diphone_str,"t_-_w")==0) {
	result ="diphones/t_-_w.wav";	
	}
	if (g_strcmp0(diphone_str,"t_-_y")==0) {
	result ="diphones/t_-_y.wav";	
	}
	
	//th diphones
	if (g_strcmp0(diphone_str,"th-aa")==0) {
	result ="diphones/th-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ae")==0) {
	result ="diphones/th-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ah")==0) {
	result ="diphones/th-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ao")==0) {
	result ="diphones/th-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"th-aw")==0) {
	result ="diphones/th-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ax")==0) {
	result ="diphones/th-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ay")==0) {
	result ="diphones/th-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"th-b")==0) {
	result ="diphones/th-b.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ch")==0) {
	result ="diphones/th-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"th-d")==0) {
	result ="diphones/th-d.wav";	
	}
	if (g_strcmp0(diphone_str,"th-dh")==0) {
	result ="diphones/th-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-eh")==0) {
	result ="diphones/th-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-er")==0) {
	result ="diphones/th-er.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ey")==0) {
	result ="diphones/th-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"th-f")==0) {
	result ="diphones/th-f.wav";	
	}
	if (g_strcmp0(diphone_str,"th-g")==0) {
	result ="diphones/th-g.wav";	
	}
	if (g_strcmp0(diphone_str,"th-hh")==0) {
	result ="diphones/th-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ih")==0) {
	result ="diphones/th-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"th-iy")==0) {
	result ="diphones/th-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"th-jh")==0) {
	result ="diphones/th-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-k")==0) {
	result ="diphones/th-k.wav";	
	}
	if (g_strcmp0(diphone_str,"th-l")==0) {
	result ="diphones/th-l.wav";	
	}
	if (g_strcmp0(diphone_str,"th-m")==0) {
	result ="diphones/th-m.wav";	
	}
	if (g_strcmp0(diphone_str,"th-n")==0) {
	result ="diphones/th-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"th-ng")==0) {
	//result ="diphones/th-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"th-ow")==0) {
	result ="diphones/th-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"th-oy")==0) {
	result ="diphones/th-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"th-p")==0) {
	result ="diphones/th-p.wav";	
	}
	if (g_strcmp0(diphone_str,"th-pau")==0) {
	result ="diphones/th-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"th-r")==0) {
	result ="diphones/th-r.wav";	
	}
	if (g_strcmp0(diphone_str,"th-s")==0) {
	result ="diphones/th-s.wav";	
	}
	if (g_strcmp0(diphone_str,"th-sh")==0) {
	result ="diphones/th-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-t")==0) {
	result ="diphones/th-t.wav";	
	}
	if (g_strcmp0(diphone_str,"th-th")==0) {
	result ="diphones/th-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"th-uh")==0) {
	result ="diphones/th-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-uw")==0) {
	result ="diphones/th-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"th-v")==0) {
	result ="diphones/th-v.wav";	
	}
	if (g_strcmp0(diphone_str,"th-w")==0) {
	result ="diphones/th-w.wav";	
	}
	if (g_strcmp0(diphone_str,"th-y")==0) {
	result ="diphones/th-y.wav";	
	}
	if (g_strcmp0(diphone_str,"th-z")==0) {
	result ="diphones/th-z.wav";	
	}
	if (g_strcmp0(diphone_str,"th-zh")==0) {
	result ="diphones/th-zh.wav";	
	}
	
	//uh diphones
	if (g_strcmp0(diphone_str,"uh-aa")==0) {
	result ="diphones/uh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ae")==0) {
	result ="diphones/uh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ah")==0) {
	result ="diphones/uh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ao")==0) {
	result ="diphones/uh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-aw")==0) {
	result ="diphones/uh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ax")==0) {
	result ="diphones/uh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ay")==0) {
	result ="diphones/uh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-b")==0) {
	result ="diphones/uh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ch")==0) {
	result ="diphones/uh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-d")==0) {
	result ="diphones/uh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-dh")==0) {
	result ="diphones/uh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-eh")==0) {
	result ="diphones/uh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-er")==0) {
	result ="diphones/uh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ey")==0) {
	result ="diphones/uh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-f")==0) {
	result ="diphones/uh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-g")==0) {
	result ="diphones/uh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-hh")==0) {
	result ="diphones/uh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ih")==0) {
	result ="diphones/uh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-iy")==0) {
	result ="diphones/uh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-jh")==0) {
	result ="diphones/uh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-k")==0) {
	result ="diphones/uh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-l")==0) {
	result ="diphones/uh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-m")==0) {
	result ="diphones/uh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-n")==0) {
	result ="diphones/uh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ng")==0) {
	result ="diphones/uh-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"-ow")==0) {
	result ="diphones/-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-oy")==0) {
	result ="diphones/uh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-p")==0) {
	result ="diphones/uh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-pau")==0) {
	result ="diphones/uh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-r")==0) {
	result ="diphones/uh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-s")==0) {
	result ="diphones/uh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-sh")==0) {
	result ="diphones/uh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-t")==0) {
	result ="diphones/uh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-th")==0) {
	result ="diphones/uh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"uh-uh")==0) {
	result ="diphones/uh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-uw")==0) {
	result ="diphones/uh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-v")==0) {
	result ="diphones/uh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-w")==0) {
	result ="diphones/uh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-y")==0) {
	result ="diphones/uh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-z")==0) {
	result ="diphones/uh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-zh")==0) {
	result ="diphones/uh-zh.wav";	
	}
	
	//uw diphones
	if (g_strcmp0(diphone_str,"uw-aa")==0) {
	result ="diphones/uw-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ae")==0) {
	result ="diphones/uw-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ah")==0) {
	result ="diphones/uw-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ao")==0) {
	result ="diphones/uw-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-aw")==0) {
	result ="diphones/uw-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ax")==0) {
	result ="diphones/uw-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ay")==0) {
	result ="diphones/uw-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-b")==0) {
	result ="diphones/uw-b.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ch")==0) {
	result ="diphones/uw-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-d")==0) {
	result ="diphones/uw-d.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-dh")==0) {
	result ="diphones/uw-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-eh")==0) {
	result ="diphones/uw-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-er")==0) {
	result ="diphones/uw-er.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ey")==0) {
	result ="diphones/uw-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-f")==0) {
	result ="diphones/uw-f.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-g")==0) {
	result ="diphones/uw-g.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-hh")==0) {
	result ="diphones/uw-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ih")==0) {
	result ="diphones/uw-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-iy")==0) {
	result ="diphones/uw-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-jh")==0) {
	result ="diphones/uw-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-k")==0) {
	result ="diphones/uw-k.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-l")==0) {
	result ="diphones/uw-l.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-m")==0) {
	result ="diphones/uw-m.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-n")==0) {
	result ="diphones/uw-n.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ng")==0) {
	result ="diphones/uw-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ow")==0) {
	result ="diphones/uw-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-oy")==0) {
	result ="diphones/uw-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-p")==0) {
	result ="diphones/uw-p.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-pau")==0) {
	result ="diphones/uw-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-r")==0) {
	result ="diphones/uw-r.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-s")==0) {
	result ="diphones/uw-s.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-sh")==0) {
	result ="diphones/uw-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-t")==0) {
	result ="diphones/uw-t.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-th")==0) {
	result ="diphones/uw-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"uw-uh")==0) {
	result ="diphones/uw-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-uw")==0) {
	result ="diphones/uw-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-v")==0) {
	result ="diphones/uw-v.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-w")==0) {
	result ="diphones/uw-w.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-y")==0) {
	result ="diphones/uw-y.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-z")==0) {
	result ="diphones/uw-z.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-zh")==0) {
	result ="diphones/uw-zh.wav";	
	}
	
	//v diphones
	if (g_strcmp0(diphone_str,"v-aa")==0) {
	result ="diphones/v-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ae")==0) {
	result ="diphones/v-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ah")==0) {
	result ="diphones/v-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ao")==0) {
	result ="diphones/v-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"v-aw")==0) {
	result ="diphones/v-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ax")==0) {
	result ="diphones/v-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ay")==0) {
	result ="diphones/v-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"v-b")==0) {
	result ="diphones/v-b.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ch")==0) {
	result ="diphones/v-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"v-d")==0) {
	result ="diphones/v-d.wav";	
	}
	if (g_strcmp0(diphone_str,"v-dh")==0) {
	result ="diphones/v-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-eh")==0) {
	result ="diphones/v-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-er")==0) {
	result ="diphones/v-er.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ey")==0) {
	result ="diphones/v-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"v-f")==0) {
	result ="diphones/v-f.wav";	
	}
	if (g_strcmp0(diphone_str,"v-g")==0) {
	result ="diphones/v-g.wav";	
	}
	if (g_strcmp0(diphone_str,"v-hh")==0) {
	result ="diphones/v-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ih")==0) {
	result ="diphones/v-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"v-iy")==0) {
	result ="diphones/v-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"v-jh")==0) {
	result ="diphones/v-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-k")==0) {
	result ="diphones/v-k.wav";	
	}
	if (g_strcmp0(diphone_str,"v-l")==0) {
	result ="diphones/v-l.wav";	
	}
	if (g_strcmp0(diphone_str,"v-m")==0) {
	result ="diphones/v-m.wav";	
	}
	if (g_strcmp0(diphone_str,"v-n")==0) {
	result ="diphones/v-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"v-ng")==0) {
	//result ="diphones/v-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"v-ow")==0) {
	result ="diphones/v-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"v-oy")==0) {
	result ="diphones/v-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"v-p")==0) {
	result ="diphones/v-p.wav";	
	}
	if (g_strcmp0(diphone_str,"v-pau")==0) {
	result ="diphones/v-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"v-r")==0) {
	result ="diphones/v-r.wav";	
	}
	if (g_strcmp0(diphone_str,"v-s")==0) {
	result ="diphones/v-s.wav";	
	}
	if (g_strcmp0(diphone_str,"v-sh")==0) {
	result ="diphones/v-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-t")==0) {
	result ="diphones/v-t.wav";	
	}
	if (g_strcmp0(diphone_str,"v-th")==0) {
	result ="diphones/v-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"v-uh")==0) {
	result ="diphones/v-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-uw")==0) {
	result ="diphones/v-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"v-v")==0) {
	result ="diphones/v-v.wav";	
	}
	if (g_strcmp0(diphone_str,"v-w")==0) {
	result ="diphones/v-w.wav";	
	}
	if (g_strcmp0(diphone_str,"v-y")==0) {
	result ="diphones/v-y.wav";	
	}
	if (g_strcmp0(diphone_str,"v-z")==0) {
	result ="diphones/v-z.wav";	
	}
	if (g_strcmp0(diphone_str,"v-zh")==0) {
	result ="diphones/v-zh.wav";	
	}
	
	//w diphones
	if (g_strcmp0(diphone_str,"w-aa")==0) {
	result ="diphones/w-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ae")==0) {
	result ="diphones/w-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ah")==0) {
	result ="diphones/w-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ao")==0) {
	result ="diphones/w-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"w-aw")==0) {
	result ="diphones/w-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ax")==0) {
	result ="diphones/w-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ay")==0) {
	result ="diphones/w-ay.wav";	
	}
	//if (g_strcmp0(diphone_str,"-b")==0) {
	//result ="diphones/-b.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-ch")==0) {
	//result ="diphones/-ch.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-d")==0) {
	//result ="diphones/-d.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-dh")==0) {
	//result ="diphones/-dh.wav";	
	//}
	if (g_strcmp0(diphone_str,"w-eh")==0) {
	result ="diphones/w-eh.wav";	
	}
	//if (g_strcmp0(diphone_str,"w-er")==0) {
	//result ="diphones/w-er.wav";	
	//}
	//if (g_strcmp0(diphone_str,"w-ey")==0) {
	//result ="diphones/w-ey.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-f")==0) {
	//result ="diphones/-f.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-g")==0) {
	//result ="diphones/-g.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-hh")==0) {
	//result ="diphones/-hh.wav";	
	//}
	if (g_strcmp0(diphone_str,"w-ih")==0) {
	result ="diphones/w-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"w-iy")==0) {
	result ="diphones/w-iy.wav";	
	}
	//if (g_strcmp0(diphone_str,"-jh")==0) {
	//result ="diphones/-jh.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-k")==0) {
	//result ="diphones/-k.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-l")==0) {
	//result ="diphones/-l.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-m")==0) {
	//result ="diphones/-m.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-n")==0) {
	//result ="diphones/-n.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-ng")==0) {
	//result ="diphones/-ng.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-ow")==0) {
	//result ="diphones/-ow.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-oy")==0) {
	//result ="diphones/-oy.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-p")==0) {
	//result ="diphones/-p.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-pau")==0) {
	//result ="diphones/-pau.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-r")==0) {
	//result ="diphones/-r.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-s")==0) {
	//result ="diphones/-s.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-sh")==0) {
	//result ="diphones/-sh.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-t")==0) {
	//result ="diphones/-t.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-th")==0) {
	//result ="diphones/-th.wav";	
	//}	
	if (g_strcmp0(diphone_str,"w-uh")==0) {
	result ="diphones/w-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"w-uw")==0) {
	result ="diphones/w-uw.wav";	
	}
	//if (g_strcmp0(diphone_str,"-v")==0) {
	//result ="diphones/-v.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-w")==0) {
	//result ="diphones/-w.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-y")==0) {
	//result ="diphones/-y.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-z")==0) {
	//result ="diphones/-z.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-zh")==0) {
	//result ="diphones/-zh.wav";	
	//}
	
	//y diphones
	
	if (g_strcmp0(diphone_str,"y-aa")==0) {
	result ="diphones/y-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ae")==0) {
	result ="diphones/y-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ah")==0) {
	result ="diphones/y-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ao")==0) {
	result ="diphones/y-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"y-aw")==0) {
	result ="diphones/y-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ax")==0) {
	result ="diphones/y-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ay")==0) {
	result ="diphones/y-ay.wav";	
	}
	//if (g_strcmp0(diphone_str,"-b")==0) {
	//result ="diphones/-b.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-ch")==0) {
	//result ="diphones/-ch.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-d")==0) {
	//result ="diphones/-d.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-dh")==0) {
	//result ="diphones/-dh.wav";	
	//}
	if (g_strcmp0(diphone_str,"y-eh")==0) {
	result ="diphones/y-eh.wav";	
	}
	//if (g_strcmp0(diphone_str,"-er")==0) {
	//result ="diphones/-er.wav";	
	//}
	if (g_strcmp0(diphone_str,"y-ey")==0) {
	result ="diphones/y-ey.wav";	
	}
	//if (g_strcmp0(diphone_str,"-f")==0) {
	//result ="diphones/-f.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-g")==0) {
	//result ="diphones/-g.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-hh")==0) {
	//result ="diphones/-hh.wav";	
	//}
	if (g_strcmp0(diphone_str,"y-ih")==0) {
	result ="diphones/y-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"y-iy")==0) {
	result ="diphones/y-iy.wav";	
	}
	//if (g_strcmp0(diphone_str,"-jh")==0) {
	//result ="diphones/-jh.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-k")==0) {
	//result ="diphones/-k.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-l")==0) {
	//result ="diphones/-l.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-m")==0) {
	//result ="diphones/-m.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-n")==0) {
	//result ="diphones/-n.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-ng")==0) {
	//result ="diphones/-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"y-ow")==0) {
	result ="diphones/y-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"y-oy")==0) {
	result ="diphones/y-oy.wav";	
	}
	//if (g_strcmp0(diphone_str,"-p")==0) {
	//result ="diphones/-p.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-pau")==0) {
	//result ="diphones/-pau.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-r")==0) {
	//result ="diphones/-r.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-s")==0) {
	//result ="diphones/-s.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-sh")==0) {
	//result ="diphones/-sh.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-t")==0) {
	//result ="diphones/-t.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-th")==0) {
	//result ="diphones/-th.wav";	
	//}	
	if (g_strcmp0(diphone_str,"y-uh")==0) {
	result ="diphones/y-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"y-uw")==0) {
	result ="diphones/y-uw.wav";	
	}
	//if (g_strcmp0(diphone_str,"-v")==0) {
	//result ="diphones/-v.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-w")==0) {
	//result ="diphones/-w.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-y")==0) {
	//result ="diphones/-y.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-z")==0) {
	//result ="diphones/-z.wav";	
	//}
	//if (g_strcmp0(diphone_str,"-zh")==0) {
	//result ="diphones/-zh.wav";	
	//}
	
	//z diphones
	
	if (g_strcmp0(diphone_str,"z-aa")==0) {
	result ="diphones/z-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ae")==0) {
	result ="diphones/z-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ah")==0) {
	result ="diphones/z-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ao")==0) {
	result ="diphones/z-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"z-aw")==0) {
	result ="diphones/z-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ax")==0) {
	result ="diphones/z-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ay")==0) {
	result ="diphones/z-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"z-b")==0) {
	result ="diphones/z-b.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ch")==0) {
	result ="diphones/z-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"z-d")==0) {
	result ="diphones/z-d.wav";	
	}
	if (g_strcmp0(diphone_str,"z-dh")==0) {
	result ="diphones/z-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-eh")==0) {
	result ="diphones/z-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-er")==0) {
	result ="diphones/z-er.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ey")==0) {
	result ="diphones/z-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"z-f")==0) {
	result ="diphones/z-f.wav";	
	}
	if (g_strcmp0(diphone_str,"z-g")==0) {
	result ="diphones/z-g.wav";	
	}
	if (g_strcmp0(diphone_str,"z-hh")==0) {
	result ="diphones/z-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ih")==0) {
	result ="diphones/z-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"z-iy")==0) {
	result ="diphones/z-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"z-jh")==0) {
	result ="diphones/z-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-k")==0) {
	result ="diphones/z-k.wav";	
	}
	if (g_strcmp0(diphone_str,"z-l")==0) {
	result ="diphones/z-l.wav";	
	}
	if (g_strcmp0(diphone_str,"z-m")==0) {
	result ="diphones/z-m.wav";	
	}
	if (g_strcmp0(diphone_str,"z-n")==0) {
	result ="diphones/z-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"z-ng")==0) {
	//result ="diphones/z-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"z-ow")==0) {
	result ="diphones/z-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"z-oy")==0) {
	result ="diphones/z-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"z-p")==0) {
	result ="diphones/z-p.wav";	
	}
	if (g_strcmp0(diphone_str,"z-pau")==0) {
	result ="diphones/z-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"z-r")==0) {
	result ="diphones/z-r.wav";	
	}
	if (g_strcmp0(diphone_str,"z-s")==0) {
	result ="diphones/z-s.wav";	
	}
	if (g_strcmp0(diphone_str,"z-sh")==0) {
	result ="diphones/z-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-t")==0) {
	result ="diphones/z-t.wav";	
	}
	if (g_strcmp0(diphone_str,"z-th")==0) {
	result ="diphones/z-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"z-uh")==0) {
	result ="diphones/z-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-uw")==0) {
	result ="diphones/z-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"z-v")==0) {
	result ="diphones/z-v.wav";	
	}
	if (g_strcmp0(diphone_str,"z-w")==0) {
	result ="diphones/z-w.wav";	
	}
	if (g_strcmp0(diphone_str,"z-y")==0) {
	result ="diphones/z-y.wav";	
	}
	if (g_strcmp0(diphone_str,"z-z")==0) {
	result ="diphones/z-z.wav";	
	}
	if (g_strcmp0(diphone_str,"z-zh")==0) {
	result ="diphones/-zh.wav";	
	}
	
	//zh diphones
	if (g_strcmp0(diphone_str,"zh-aa")==0) {
	result ="diphones/zh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ae")==0) {
	result ="diphones/zh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ah")==0) {
	result ="diphones/zh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ao")==0) {
	result ="diphones/zh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-aw")==0) {
	result ="diphones/zh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ax")==0) {
	result ="diphones/zh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ay")==0) {
	result ="diphones/zh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-b")==0) {
	result ="diphones/zh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ch")==0) {
	result ="diphones/zh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-d")==0) {
	result ="diphones/zh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-dh")==0) {
	result ="diphones/zh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"-zheh")==0) {
	result ="diphones/zh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-er")==0) {
	result ="diphones/zh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ey")==0) {
	result ="diphones/zh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-f")==0) {
	result ="diphones/zh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-g")==0) {
	result ="diphones/zh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-hh")==0) {
	result ="diphones/zh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ih")==0) {
	result ="diphones/zh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-iy")==0) {
	result ="diphones/zh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-jh")==0) {
	result ="diphones/zh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-k")==0) {
	result ="diphones/zh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-l")==0) {
	result ="diphones/zh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-m")==0) {
	result ="diphones/zh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-n")==0) {
	result ="diphones/zh-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"zh-ng")==0) {
	//result ="diphones/zh-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"zh-ow")==0) {
	result ="diphones/zh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-oy")==0) {
	result ="diphones/zh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-p")==0) {
	result ="diphones/zh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-pau")==0) {
	result ="diphones/zh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-r")==0) {
	result ="diphones/zh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-s")==0) {
	result ="diphones/zh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-sh")==0) {
	result ="diphones/zh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-t")==0) {
	result ="diphones/zh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-th")==0) {
	result ="diphones/zh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"zh-uh")==0) {
	result ="diphones/zh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-uw")==0) {
	result ="diphones/zh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-v")==0) {
	result ="diphones/zh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-w")==0) {
	result ="diphones/zh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-y")==0) {
	result ="diphones/zh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-z")==0) {
	result ="diphones/zh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-zh")==0) {
	result ="diphones/zh-zh.wav";	
	}
	
	
	
	return result;	  
}

