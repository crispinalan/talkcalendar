/***************************************************************************
 * GPL v3.0 license (see license document distributed with this software)
 * Diphone wav paths 
 * Author: crispinalan@gmail.com
 ***************************************************************************/

//#include <gtk/gtk.h> 

#include "diphone.h"


void file_write(char* path, unsigned long *audio_buf, unsigned long size )
{
	FILE *fp = fopen(path,"wb"); 

if (!fp) { 
	fprintf ( stderr , "fopen failed!\n" ); 
    return ; 
}

fwrite(audio_buf, size, 1 , fp);
fclose(fp);
}



void create_diphones() {

//aa diphones  
unsigned  long * audio_buf_aa_aa = ( unsigned  long *)&_binary_aa_aa_wav_start; 
unsigned long size_aa_aa = ( unsigned long )&_binary_aa_aa_wav_size;
unsigned  long * audio_buf_aa_ae = ( unsigned  long *)&_binary_aa_ae_wav_start;
unsigned long size_aa_ae = ( unsigned long )&_binary_aa_ae_wav_size;
unsigned  long * audio_buf_aa_ah = ( unsigned  long *)&_binary_aa_ah_wav_start;
unsigned long size_aa_ah = ( unsigned long )&_binary_aa_ah_wav_size;
unsigned  long * audio_buf_aa_ao = ( unsigned  long *)&_binary_aa_ao_wav_start;
unsigned long size_aa_ao = ( unsigned long )&_binary_aa_ao_wav_size;
unsigned  long * audio_buf_aa_aw = ( unsigned  long *)&_binary_aa_aw_wav_start;
unsigned long size_aa_aw = ( unsigned long )&_binary_aa_aw_wav_size;
unsigned  long * audio_buf_aa_ax = ( unsigned  long *)&_binary_aa_ax_wav_start;
unsigned long size_aa_ax = ( unsigned long )&_binary_aa_ax_wav_size;
unsigned  long * audio_buf_aa_ay = ( unsigned  long *)&_binary_aa_ay_wav_start;
unsigned long size_aa_ay = ( unsigned long )&_binary_aa_ay_wav_size;
unsigned  long * audio_buf_aa_b = ( unsigned  long *)&_binary_aa_b_wav_start;
unsigned long size_aa_b = ( unsigned long )&_binary_aa_b_wav_size;
unsigned  long * audio_buf_aa_ch = ( unsigned  long *)&_binary_aa_ch_wav_start;
unsigned long size_aa_ch = ( unsigned long )&_binary_aa_ch_wav_size;
unsigned  long * audio_buf_aa_d = ( unsigned  long *)&_binary_aa_d_wav_start;
unsigned long size_aa_d = ( unsigned long )&_binary_aa_d_wav_size;
unsigned  long * audio_buf_aa_dh = ( unsigned  long *)&_binary_aa_dh_wav_start;
unsigned long size_aa_dh = ( unsigned long )&_binary_aa_dh_wav_size;
unsigned  long * audio_buf_aa_eh = ( unsigned  long *)&_binary_aa_eh_wav_start;
unsigned long size_aa_eh = ( unsigned long )&_binary_aa_eh_wav_size;
unsigned  long * audio_buf_aa_er = ( unsigned  long *)&_binary_aa_er_wav_start;
unsigned long size_aa_er = ( unsigned long )&_binary_aa_er_wav_size;
unsigned  long * audio_buf_aa_ey = ( unsigned  long *)&_binary_aa_ey_wav_start;
unsigned long size_aa_ey = ( unsigned long )&_binary_aa_ey_wav_size;
unsigned  long * audio_buf_aa_f = ( unsigned  long *)&_binary_aa_f_wav_start;
unsigned long size_aa_f = ( unsigned long )&_binary_aa_f_wav_size;
unsigned  long * audio_buf_aa_g = ( unsigned  long *)&_binary_aa_g_wav_start;
unsigned long size_aa_g = ( unsigned long )&_binary_aa_g_wav_size;
unsigned  long * audio_buf_aa_hh = ( unsigned  long *)&_binary_aa_hh_wav_start;
unsigned long size_aa_hh = ( unsigned long )&_binary_aa_hh_wav_size;
unsigned  long * audio_buf_aa_ih = ( unsigned  long *)&_binary_aa_ih_wav_start;
unsigned long size_aa_ih = ( unsigned long )&_binary_aa_ih_wav_size;
unsigned  long * audio_buf_aa_iy = ( unsigned  long *)&_binary_aa_iy_wav_start;
unsigned long size_aa_iy = ( unsigned long )&_binary_aa_iy_wav_size;
unsigned  long * audio_buf_aa_jh = ( unsigned  long *)&_binary_aa_jh_wav_start;
unsigned long size_aa_jh = ( unsigned long )&_binary_aa_jh_wav_size;
unsigned  long * audio_buf_aa_k = ( unsigned  long *)&_binary_aa_k_wav_start;
unsigned long size_aa_k = ( unsigned long )&_binary_aa_k_wav_size;
unsigned  long * audio_buf_aa_l = ( unsigned  long *)&_binary_aa_l_wav_start;
unsigned long size_aa_l = ( unsigned long )&_binary_aa_l_wav_size;
unsigned  long * audio_buf_aa_m = ( unsigned  long *)&_binary_aa_m_wav_start;
unsigned long size_aa_m = ( unsigned long )&_binary_aa_m_wav_size;
unsigned  long * audio_buf_aa_n = ( unsigned  long *)&_binary_aa_n_wav_start;
unsigned long size_aa_n = ( unsigned long )&_binary_aa_n_wav_size;
unsigned  long * audio_buf_aa_ng = ( unsigned  long *)&_binary_aa_ng_wav_start;
unsigned long size_aa_ng = ( unsigned long )&_binary_aa_ng_wav_size;
unsigned  long * audio_buf_aa_ow = ( unsigned  long *)&_binary_aa_ow_wav_start;
unsigned long size_aa_ow = ( unsigned long )&_binary_aa_ow_wav_size;
unsigned  long * audio_buf_aa_oy = ( unsigned  long *)&_binary_aa_oy_wav_start;
unsigned long size_aa_oy = ( unsigned long )&_binary_aa_oy_wav_size;
unsigned  long * audio_buf_aa_p = ( unsigned  long *)&_binary_aa_p_wav_start;
unsigned long size_aa_p = ( unsigned long )&_binary_aa_p_wav_size;
unsigned  long * audio_buf_aa_pau = ( unsigned  long *)&_binary_aa_pau_wav_start;
unsigned long size_aa_pau = ( unsigned long )&_binary_aa_pau_wav_size;
unsigned  long * audio_buf_aa_r = ( unsigned  long *)&_binary_aa_r_wav_start;
unsigned long size_aa_r = ( unsigned long )&_binary_aa_r_wav_size;
unsigned  long * audio_buf_aa_s = ( unsigned  long *)&_binary_aa_s_wav_start;
unsigned long size_aa_s = ( unsigned long )&_binary_aa_s_wav_size;
unsigned  long * audio_buf_aa_sh = ( unsigned  long *)&_binary_aa_sh_wav_start;
unsigned long size_aa_sh = ( unsigned long )&_binary_aa_sh_wav_size;
unsigned  long * audio_buf_aa_t = ( unsigned  long *)&_binary_aa_t_wav_start;
unsigned long size_aa_t = ( unsigned long )&_binary_aa_t_wav_size;
unsigned  long * audio_buf_aa_th = ( unsigned  long *)&_binary_aa_th_wav_start;
unsigned long size_aa_th = ( unsigned long )&_binary_aa_th_wav_size;
unsigned  long * audio_buf_aa_uh = ( unsigned  long *)&_binary_aa_uh_wav_start;
unsigned long size_aa_uh = ( unsigned long )&_binary_aa_uh_wav_size;
unsigned  long * audio_buf_aa_uw = ( unsigned  long *)&_binary_aa_uw_wav_start;
unsigned long size_aa_uw = ( unsigned long )&_binary_aa_uw_wav_size;
unsigned  long * audio_buf_aa_v = ( unsigned  long *)&_binary_aa_v_wav_start;
unsigned long size_aa_v = ( unsigned long )&_binary_aa_v_wav_size;
unsigned  long * audio_buf_aa_w = ( unsigned  long *)&_binary_aa_w_wav_start;
unsigned long size_aa_w = ( unsigned long )&_binary_aa_w_wav_size;
unsigned  long * audio_buf_aa_y = ( unsigned  long *)&_binary_aa_y_wav_start;
unsigned long size_aa_y = ( unsigned long )&_binary_aa_y_wav_size;
unsigned  long * audio_buf_aa_z = ( unsigned  long *)&_binary_aa_z_wav_start;
unsigned long size_aa_z = ( unsigned long )&_binary_aa_z_wav_size;
unsigned  long * audio_buf_aa_zh = ( unsigned  long *)&_binary_aa_zh_wav_start;
unsigned long size_aa_zh = ( unsigned long )&_binary_aa_zh_wav_size;
//aa diphones
file_write("/tmp/aa-aa.wav",audio_buf_aa_aa,size_aa_aa);
file_write("/tmp/aa-ae.wav",audio_buf_aa_ae,size_aa_ae);
file_write("/tmp/aa-ah.wav",audio_buf_aa_ah,size_aa_ah);
file_write("/tmp/aa-ao.wav",audio_buf_aa_ao,size_aa_ao);
file_write("/tmp/aa-aw.wav",audio_buf_aa_aw,size_aa_aw);
file_write("/tmp/aa-ax.wav",audio_buf_aa_ax,size_aa_ax);
file_write("/tmp/aa-ay.wav",audio_buf_aa_ay,size_aa_ay);
file_write("/tmp/aa-b.wav",audio_buf_aa_b,size_aa_b);
file_write("/tmp/aa-ch.wav",audio_buf_aa_ch,size_aa_ch);
file_write("/tmp/aa-d.wav",audio_buf_aa_d,size_aa_d);
file_write("/tmp/aa-dh.wav",audio_buf_aa_dh,size_aa_dh);
file_write("/tmp/aa-eh.wav",audio_buf_aa_eh,size_aa_eh);
file_write("/tmp/aa-er.wav",audio_buf_aa_er,size_aa_er);
file_write("/tmp/aa-ey.wav",audio_buf_aa_ey,size_aa_ey);
file_write("/tmp/aa-f.wav",audio_buf_aa_f,size_aa_f);
file_write("/tmp/aa-g.wav",audio_buf_aa_g,size_aa_g);
file_write("/tmp/aa-hh.wav",audio_buf_aa_hh,size_aa_hh);
file_write("/tmp/aa-ih.wav",audio_buf_aa_ih,size_aa_ih);
file_write("/tmp/aa-iy.wav",audio_buf_aa_iy,size_aa_iy);
file_write("/tmp/aa-jh.wav",audio_buf_aa_jh,size_aa_jh);
file_write("/tmp/aa-k.wav",audio_buf_aa_k,size_aa_k);
file_write("/tmp/aa-l.wav",audio_buf_aa_l,size_aa_l);
file_write("/tmp/aa-m.wav",audio_buf_aa_m,size_aa_m);
file_write("/tmp/aa-n.wav",audio_buf_aa_n,size_aa_n);
file_write("/tmp/aa-ng.wav",audio_buf_aa_ng,size_aa_ng);
file_write("/tmp/aa-ow.wav",audio_buf_aa_ow,size_aa_ow);
file_write("/tmp/aa-oy.wav",audio_buf_aa_oy,size_aa_oy);
file_write("/tmp/aa-p.wav",audio_buf_aa_p,size_aa_p);
file_write("/tmp/aa-pau.wav",audio_buf_aa_pau,size_aa_pau);
file_write("/tmp/aa-r.wav",audio_buf_aa_r,size_aa_r);
file_write("/tmp/aa-s.wav",audio_buf_aa_s,size_aa_s);
file_write("/tmp/aa-sh.wav",audio_buf_aa_sh,size_aa_sh);
file_write("/tmp/aa-t.wav",audio_buf_aa_t,size_aa_t);
file_write("/tmp/aa-th.wav",audio_buf_aa_th,size_aa_th);
file_write("/tmp/aa-uh.wav",audio_buf_aa_uh,size_aa_uh);
file_write("/tmp/aa-uw.wav",audio_buf_aa_uw,size_aa_uw);
file_write("/tmp/aa-v.wav",audio_buf_aa_v,size_aa_v);
file_write("/tmp/aa-w.wav",audio_buf_aa_w,size_aa_w);
file_write("/tmp/aa-y.wav",audio_buf_aa_y,size_aa_y);
file_write("/tmp/aa-z.wav",audio_buf_aa_z,size_aa_z);
file_write("/tmp/aa-zh.wav",audio_buf_aa_zh,size_aa_zh);

//ae diphones  
unsigned  long * audio_buf_ae_aa = ( unsigned  long *)&_binary_ae_aa_wav_start; 
unsigned long size_ae_aa = ( unsigned long )&_binary_ae_aa_wav_size;
unsigned  long * audio_buf_ae_ae = ( unsigned  long *)&_binary_ae_ae_wav_start;
unsigned long size_ae_ae = ( unsigned long )&_binary_ae_ae_wav_size;
unsigned  long * audio_buf_ae_ah = ( unsigned  long *)&_binary_ae_ah_wav_start;
unsigned long size_ae_ah = ( unsigned long )&_binary_ae_ah_wav_size;
unsigned  long * audio_buf_ae_ao = ( unsigned  long *)&_binary_ae_ao_wav_start;
unsigned long size_ae_ao = ( unsigned long )&_binary_ae_ao_wav_size;
unsigned  long * audio_buf_ae_aw = ( unsigned  long *)&_binary_ae_aw_wav_start;
unsigned long size_ae_aw = ( unsigned long )&_binary_ae_aw_wav_size;
unsigned  long * audio_buf_ae_ax = ( unsigned  long *)&_binary_ae_ax_wav_start;
unsigned long size_ae_ax = ( unsigned long )&_binary_ae_ax_wav_size;
unsigned  long * audio_buf_ae_ay = ( unsigned  long *)&_binary_ae_ay_wav_start;
unsigned long size_ae_ay = ( unsigned long )&_binary_ae_ay_wav_size;
unsigned  long * audio_buf_ae_b = ( unsigned  long *)&_binary_ae_b_wav_start;
unsigned long size_ae_b = ( unsigned long )&_binary_ae_b_wav_size;
unsigned  long * audio_buf_ae_ch = ( unsigned  long *)&_binary_ae_ch_wav_start;
unsigned long size_ae_ch = ( unsigned long )&_binary_ae_ch_wav_size;
unsigned  long * audio_buf_ae_d = ( unsigned  long *)&_binary_ae_d_wav_start;
unsigned long size_ae_d = ( unsigned long )&_binary_ae_d_wav_size;
unsigned  long * audio_buf_ae_dh = ( unsigned  long *)&_binary_ae_dh_wav_start;
unsigned long size_ae_dh = ( unsigned long )&_binary_ae_dh_wav_size;
unsigned  long * audio_buf_ae_eh = ( unsigned  long *)&_binary_ae_eh_wav_start;
unsigned long size_ae_eh = ( unsigned long )&_binary_ae_eh_wav_size;
unsigned  long * audio_buf_ae_er = ( unsigned  long *)&_binary_ae_er_wav_start;
unsigned long size_ae_er = ( unsigned long )&_binary_ae_er_wav_size;
unsigned  long * audio_buf_ae_ey = ( unsigned  long *)&_binary_ae_ey_wav_start;
unsigned long size_ae_ey = ( unsigned long )&_binary_ae_ey_wav_size;
unsigned  long * audio_buf_ae_f = ( unsigned  long *)&_binary_ae_f_wav_start;
unsigned long size_ae_f = ( unsigned long )&_binary_ae_f_wav_size;
unsigned  long * audio_buf_ae_g = ( unsigned  long *)&_binary_ae_g_wav_start;
unsigned long size_ae_g = ( unsigned long )&_binary_ae_g_wav_size;
unsigned  long * audio_buf_ae_hh = ( unsigned  long *)&_binary_ae_hh_wav_start;
unsigned long size_ae_hh = ( unsigned long )&_binary_ae_hh_wav_size;
unsigned  long * audio_buf_ae_ih = ( unsigned  long *)&_binary_ae_ih_wav_start;
unsigned long size_ae_ih = ( unsigned long )&_binary_ae_ih_wav_size;
unsigned  long * audio_buf_ae_iy = ( unsigned  long *)&_binary_ae_iy_wav_start;
unsigned long size_ae_iy = ( unsigned long )&_binary_ae_iy_wav_size;
unsigned  long * audio_buf_ae_jh = ( unsigned  long *)&_binary_ae_jh_wav_start;
unsigned long size_ae_jh = ( unsigned long )&_binary_ae_jh_wav_size;
unsigned  long * audio_buf_ae_k = ( unsigned  long *)&_binary_ae_k_wav_start;
unsigned long size_ae_k = ( unsigned long )&_binary_ae_k_wav_size;
unsigned  long * audio_buf_ae_l = ( unsigned  long *)&_binary_ae_l_wav_start;
unsigned long size_ae_l = ( unsigned long )&_binary_ae_l_wav_size;
unsigned  long * audio_buf_ae_m = ( unsigned  long *)&_binary_ae_m_wav_start;
unsigned long size_ae_m = ( unsigned long )&_binary_ae_m_wav_size;
unsigned  long * audio_buf_ae_n = ( unsigned  long *)&_binary_ae_n_wav_start;
unsigned long size_ae_n = ( unsigned long )&_binary_ae_n_wav_size;
unsigned  long * audio_buf_ae_ng = ( unsigned  long *)&_binary_ae_ng_wav_start;
unsigned long size_ae_ng = ( unsigned long )&_binary_ae_ng_wav_size;
unsigned  long * audio_buf_ae_ow = ( unsigned  long *)&_binary_ae_ow_wav_start;
unsigned long size_ae_ow = ( unsigned long )&_binary_ae_ow_wav_size;
unsigned  long * audio_buf_ae_oy = ( unsigned  long *)&_binary_ae_oy_wav_start;
unsigned long size_ae_oy = ( unsigned long )&_binary_ae_oy_wav_size;
unsigned  long * audio_buf_ae_p = ( unsigned  long *)&_binary_ae_p_wav_start;
unsigned long size_ae_p = ( unsigned long )&_binary_ae_p_wav_size;
unsigned  long * audio_buf_ae_pau = ( unsigned  long *)&_binary_ae_pau_wav_start;
unsigned long size_ae_pau = ( unsigned long )&_binary_ae_pau_wav_size;
unsigned  long * audio_buf_ae_r = ( unsigned  long *)&_binary_ae_r_wav_start;
unsigned long size_ae_r = ( unsigned long )&_binary_ae_r_wav_size;
unsigned  long * audio_buf_ae_s = ( unsigned  long *)&_binary_ae_s_wav_start;
unsigned long size_ae_s = ( unsigned long )&_binary_ae_s_wav_size;
unsigned  long * audio_buf_ae_sh = ( unsigned  long *)&_binary_ae_sh_wav_start;
unsigned long size_ae_sh = ( unsigned long )&_binary_ae_sh_wav_size;
unsigned  long * audio_buf_ae_t = ( unsigned  long *)&_binary_ae_t_wav_start;
unsigned long size_ae_t = ( unsigned long )&_binary_ae_t_wav_size;
unsigned  long * audio_buf_ae_th = ( unsigned  long *)&_binary_ae_th_wav_start;
unsigned long size_ae_th = ( unsigned long )&_binary_ae_th_wav_size;
unsigned  long * audio_buf_ae_uh = ( unsigned  long *)&_binary_ae_uh_wav_start;
unsigned long size_ae_uh = ( unsigned long )&_binary_ae_uh_wav_size;
unsigned  long * audio_buf_ae_uw = ( unsigned  long *)&_binary_ae_uw_wav_start;
unsigned long size_ae_uw = ( unsigned long )&_binary_ae_uw_wav_size;
unsigned  long * audio_buf_ae_v = ( unsigned  long *)&_binary_ae_v_wav_start;
unsigned long size_ae_v = ( unsigned long )&_binary_ae_v_wav_size;
unsigned  long * audio_buf_ae_w = ( unsigned  long *)&_binary_ae_w_wav_start;
unsigned long size_ae_w = ( unsigned long )&_binary_ae_w_wav_size;
unsigned  long * audio_buf_ae_y = ( unsigned  long *)&_binary_ae_y_wav_start;
unsigned long size_ae_y = ( unsigned long )&_binary_ae_y_wav_size;
unsigned  long * audio_buf_ae_z = ( unsigned  long *)&_binary_ae_z_wav_start;
unsigned long size_ae_z = ( unsigned long )&_binary_ae_z_wav_size;
unsigned  long * audio_buf_ae_zh = ( unsigned  long *)&_binary_ae_zh_wav_start;
unsigned long size_ae_zh = ( unsigned long )&_binary_ae_zh_wav_size;
//ae diphones
file_write("/tmp/ae-aa.wav",audio_buf_ae_aa,size_ae_aa);
file_write("/tmp/ae-ae.wav",audio_buf_ae_ae,size_ae_ae);
file_write("/tmp/ae-ah.wav",audio_buf_ae_ah,size_ae_ah);
file_write("/tmp/ae-ao.wav",audio_buf_ae_ao,size_ae_ao);
file_write("/tmp/ae-aw.wav",audio_buf_ae_aw,size_ae_aw);
file_write("/tmp/ae-ax.wav",audio_buf_ae_ax,size_ae_ax);
file_write("/tmp/ae-ay.wav",audio_buf_ae_ay,size_ae_ay);
file_write("/tmp/ae-b.wav",audio_buf_ae_b,size_ae_b);
file_write("/tmp/ae-ch.wav",audio_buf_ae_ch,size_ae_ch);
file_write("/tmp/ae-d.wav",audio_buf_ae_d,size_ae_d);
file_write("/tmp/ae-dh.wav",audio_buf_ae_dh,size_ae_dh);
file_write("/tmp/ae-eh.wav",audio_buf_ae_eh,size_ae_eh);
file_write("/tmp/ae-er.wav",audio_buf_ae_er,size_ae_er);
file_write("/tmp/ae-ey.wav",audio_buf_ae_ey,size_ae_ey);
file_write("/tmp/ae-f.wav",audio_buf_ae_f,size_ae_f);
file_write("/tmp/ae-g.wav",audio_buf_ae_g,size_ae_g);
file_write("/tmp/ae-hh.wav",audio_buf_ae_hh,size_ae_hh);
file_write("/tmp/ae-ih.wav",audio_buf_ae_ih,size_ae_ih);
file_write("/tmp/ae-iy.wav",audio_buf_ae_iy,size_ae_iy);
file_write("/tmp/ae-jh.wav",audio_buf_ae_jh,size_ae_jh);
file_write("/tmp/ae-k.wav",audio_buf_ae_k,size_ae_k);
file_write("/tmp/ae-l.wav",audio_buf_ae_l,size_ae_l);
file_write("/tmp/ae-m.wav",audio_buf_ae_m,size_ae_m);
file_write("/tmp/ae-n.wav",audio_buf_ae_n,size_ae_n);
file_write("/tmp/ae-ng.wav",audio_buf_ae_ng,size_ae_ng);
file_write("/tmp/ae-ow.wav",audio_buf_ae_ow,size_ae_ow);
file_write("/tmp/ae-oy.wav",audio_buf_ae_oy,size_ae_oy);
file_write("/tmp/ae-p.wav",audio_buf_ae_p,size_ae_p);
file_write("/tmp/ae-pau.wav",audio_buf_ae_pau,size_ae_pau);
file_write("/tmp/ae-r.wav",audio_buf_ae_r,size_ae_r);
file_write("/tmp/ae-s.wav",audio_buf_ae_s,size_ae_s);
file_write("/tmp/ae-sh.wav",audio_buf_ae_sh,size_ae_sh);
file_write("/tmp/ae-t.wav",audio_buf_ae_t,size_ae_t);
file_write("/tmp/ae-th.wav",audio_buf_ae_th,size_ae_th);
file_write("/tmp/ae-uh.wav",audio_buf_ae_uh,size_ae_uh);
file_write("/tmp/ae-uw.wav",audio_buf_ae_uw,size_ae_uw);
file_write("/tmp/ae-v.wav",audio_buf_ae_v,size_ae_v);
file_write("/tmp/ae-w.wav",audio_buf_ae_w,size_ae_w);
file_write("/tmp/ae-y.wav",audio_buf_ae_y,size_ae_y);
file_write("/tmp/ae-z.wav",audio_buf_ae_z,size_ae_z);
file_write("/tmp/ae-zh.wav",audio_buf_ae_zh,size_ae_zh);

//ah diphones  
unsigned  long * audio_buf_ah_aa = ( unsigned  long *)&_binary_ah_aa_wav_start; 
unsigned long size_ah_aa = ( unsigned long )&_binary_ah_aa_wav_size;
unsigned  long * audio_buf_ah_ae = ( unsigned  long *)&_binary_ah_ae_wav_start;
unsigned long size_ah_ae = ( unsigned long )&_binary_ah_ae_wav_size;
unsigned  long * audio_buf_ah_ah = ( unsigned  long *)&_binary_ah_ah_wav_start;
unsigned long size_ah_ah = ( unsigned long )&_binary_ah_ah_wav_size;
unsigned  long * audio_buf_ah_ao = ( unsigned  long *)&_binary_ah_ao_wav_start;
unsigned long size_ah_ao = ( unsigned long )&_binary_ah_ao_wav_size;
unsigned  long * audio_buf_ah_aw = ( unsigned  long *)&_binary_ah_aw_wav_start;
unsigned long size_ah_aw = ( unsigned long )&_binary_ah_aw_wav_size;
unsigned  long * audio_buf_ah_ax = ( unsigned  long *)&_binary_ah_ax_wav_start;
unsigned long size_ah_ax = ( unsigned long )&_binary_ah_ax_wav_size;
unsigned  long * audio_buf_ah_ay = ( unsigned  long *)&_binary_ah_ay_wav_start;
unsigned long size_ah_ay = ( unsigned long )&_binary_ah_ay_wav_size;
unsigned  long * audio_buf_ah_b = ( unsigned  long *)&_binary_ah_b_wav_start;
unsigned long size_ah_b = ( unsigned long )&_binary_ah_b_wav_size;
unsigned  long * audio_buf_ah_ch = ( unsigned  long *)&_binary_ah_ch_wav_start;
unsigned long size_ah_ch = ( unsigned long )&_binary_ah_ch_wav_size;
unsigned  long * audio_buf_ah_d = ( unsigned  long *)&_binary_ah_d_wav_start;
unsigned long size_ah_d = ( unsigned long )&_binary_ah_d_wav_size;
unsigned  long * audio_buf_ah_dh = ( unsigned  long *)&_binary_ah_dh_wav_start;
unsigned long size_ah_dh = ( unsigned long )&_binary_ah_dh_wav_size;
unsigned  long * audio_buf_ah_eh = ( unsigned  long *)&_binary_ah_eh_wav_start;
unsigned long size_ah_eh = ( unsigned long )&_binary_ah_eh_wav_size;
unsigned  long * audio_buf_ah_er = ( unsigned  long *)&_binary_ah_er_wav_start;
unsigned long size_ah_er = ( unsigned long )&_binary_ah_er_wav_size;
unsigned  long * audio_buf_ah_ey = ( unsigned  long *)&_binary_ah_ey_wav_start;
unsigned long size_ah_ey = ( unsigned long )&_binary_ah_ey_wav_size;
unsigned  long * audio_buf_ah_f = ( unsigned  long *)&_binary_ah_f_wav_start;
unsigned long size_ah_f = ( unsigned long )&_binary_ah_f_wav_size;
unsigned  long * audio_buf_ah_g = ( unsigned  long *)&_binary_ah_g_wav_start;
unsigned long size_ah_g = ( unsigned long )&_binary_ah_g_wav_size;
unsigned  long * audio_buf_ah_hh = ( unsigned  long *)&_binary_ah_hh_wav_start;
unsigned long size_ah_hh = ( unsigned long )&_binary_ah_hh_wav_size;
unsigned  long * audio_buf_ah_ih = ( unsigned  long *)&_binary_ah_ih_wav_start;
unsigned long size_ah_ih = ( unsigned long )&_binary_ah_ih_wav_size;
unsigned  long * audio_buf_ah_iy = ( unsigned  long *)&_binary_ah_iy_wav_start;
unsigned long size_ah_iy = ( unsigned long )&_binary_ah_iy_wav_size;
unsigned  long * audio_buf_ah_jh = ( unsigned  long *)&_binary_ah_jh_wav_start;
unsigned long size_ah_jh = ( unsigned long )&_binary_ah_jh_wav_size;
unsigned  long * audio_buf_ah_k = ( unsigned  long *)&_binary_ah_k_wav_start;
unsigned long size_ah_k = ( unsigned long )&_binary_ah_k_wav_size;
unsigned  long * audio_buf_ah_l = ( unsigned  long *)&_binary_ah_l_wav_start;
unsigned long size_ah_l = ( unsigned long )&_binary_ah_l_wav_size;
unsigned  long * audio_buf_ah_m = ( unsigned  long *)&_binary_ah_m_wav_start;
unsigned long size_ah_m = ( unsigned long )&_binary_ah_m_wav_size;
unsigned  long * audio_buf_ah_n = ( unsigned  long *)&_binary_ah_n_wav_start;
unsigned long size_ah_n = ( unsigned long )&_binary_ah_n_wav_size;
unsigned  long * audio_buf_ah_ng = ( unsigned  long *)&_binary_ah_ng_wav_start;
unsigned long size_ah_ng = ( unsigned long )&_binary_ah_ng_wav_size;
unsigned  long * audio_buf_ah_ow = ( unsigned  long *)&_binary_ah_ow_wav_start;
unsigned long size_ah_ow = ( unsigned long )&_binary_ah_ow_wav_size;
unsigned  long * audio_buf_ah_oy = ( unsigned  long *)&_binary_ah_oy_wav_start;
unsigned long size_ah_oy = ( unsigned long )&_binary_ah_oy_wav_size;
unsigned  long * audio_buf_ah_p = ( unsigned  long *)&_binary_ah_p_wav_start;
unsigned long size_ah_p = ( unsigned long )&_binary_ah_p_wav_size;
unsigned  long * audio_buf_ah_pau = ( unsigned  long *)&_binary_ah_pau_wav_start;
unsigned long size_ah_pau = ( unsigned long )&_binary_ah_pau_wav_size;
unsigned  long * audio_buf_ah_r = ( unsigned  long *)&_binary_ah_r_wav_start;
unsigned long size_ah_r = ( unsigned long )&_binary_ah_r_wav_size;
unsigned  long * audio_buf_ah_s = ( unsigned  long *)&_binary_ah_s_wav_start;
unsigned long size_ah_s = ( unsigned long )&_binary_ah_s_wav_size;
unsigned  long * audio_buf_ah_sh = ( unsigned  long *)&_binary_ah_sh_wav_start;
unsigned long size_ah_sh = ( unsigned long )&_binary_ah_sh_wav_size;
unsigned  long * audio_buf_ah_t = ( unsigned  long *)&_binary_ah_t_wav_start;
unsigned long size_ah_t = ( unsigned long )&_binary_ah_t_wav_size;
unsigned  long * audio_buf_ah_th = ( unsigned  long *)&_binary_ah_th_wav_start;
unsigned long size_ah_th = ( unsigned long )&_binary_ah_th_wav_size;
unsigned  long * audio_buf_ah_uh = ( unsigned  long *)&_binary_ah_uh_wav_start;
unsigned long size_ah_uh = ( unsigned long )&_binary_ah_uh_wav_size;
unsigned  long * audio_buf_ah_uw = ( unsigned  long *)&_binary_ah_uw_wav_start;
unsigned long size_ah_uw = ( unsigned long )&_binary_ah_uw_wav_size;
unsigned  long * audio_buf_ah_v = ( unsigned  long *)&_binary_ah_v_wav_start;
unsigned long size_ah_v = ( unsigned long )&_binary_ah_v_wav_size;
unsigned  long * audio_buf_ah_w = ( unsigned  long *)&_binary_ah_w_wav_start;
unsigned long size_ah_w = ( unsigned long )&_binary_ah_w_wav_size;
unsigned  long * audio_buf_ah_y = ( unsigned  long *)&_binary_ah_y_wav_start;
unsigned long size_ah_y = ( unsigned long )&_binary_ah_y_wav_size;
unsigned  long * audio_buf_ah_z = ( unsigned  long *)&_binary_ah_z_wav_start;
unsigned long size_ah_z = ( unsigned long )&_binary_ah_z_wav_size;
unsigned  long * audio_buf_ah_zh = ( unsigned  long *)&_binary_ah_zh_wav_start;
unsigned long size_ah_zh = ( unsigned long )&_binary_ah_zh_wav_size;
//ah diphones
file_write("/tmp/ah-aa.wav",audio_buf_ah_aa,size_ah_aa);
file_write("/tmp/ah-ae.wav",audio_buf_ah_ae,size_ah_ae);
file_write("/tmp/ah-ah.wav",audio_buf_ah_ah,size_ah_ah);
file_write("/tmp/ah-ao.wav",audio_buf_ah_ao,size_ah_ao);
file_write("/tmp/ah-aw.wav",audio_buf_ah_aw,size_ah_aw);
file_write("/tmp/ah-ax.wav",audio_buf_ah_ax,size_ah_ax);
file_write("/tmp/ah-ay.wav",audio_buf_ah_ay,size_ah_ay);
file_write("/tmp/ah-b.wav",audio_buf_ah_b,size_ah_b);
file_write("/tmp/ah-ch.wav",audio_buf_ah_ch,size_ah_ch);
file_write("/tmp/ah-d.wav",audio_buf_ah_d,size_ah_d);
file_write("/tmp/ah-dh.wav",audio_buf_ah_dh,size_ah_dh);
file_write("/tmp/ah-eh.wav",audio_buf_ah_eh,size_ah_eh);
file_write("/tmp/ah-er.wav",audio_buf_ah_er,size_ah_er);
file_write("/tmp/ah-ey.wav",audio_buf_ah_ey,size_ah_ey);
file_write("/tmp/ah-f.wav",audio_buf_ah_f,size_ah_f);
file_write("/tmp/ah-g.wav",audio_buf_ah_g,size_ah_g);
file_write("/tmp/ah-hh.wav",audio_buf_ah_hh,size_ah_hh);
file_write("/tmp/ah-ih.wav",audio_buf_ah_ih,size_ah_ih);
file_write("/tmp/ah-iy.wav",audio_buf_ah_iy,size_ah_iy);
file_write("/tmp/ah-jh.wav",audio_buf_ah_jh,size_ah_jh);
file_write("/tmp/ah-k.wav",audio_buf_ah_k,size_ah_k);
file_write("/tmp/ah-l.wav",audio_buf_ah_l,size_ah_l);
file_write("/tmp/ah-m.wav",audio_buf_ah_m,size_ah_m);
file_write("/tmp/ah-n.wav",audio_buf_ah_n,size_ah_n);
file_write("/tmp/ah-ng.wav",audio_buf_ah_ng,size_ah_ng);
file_write("/tmp/ah-ow.wav",audio_buf_ah_ow,size_ah_ow);
file_write("/tmp/ah-oy.wav",audio_buf_ah_oy,size_ah_oy);
file_write("/tmp/ah-p.wav",audio_buf_ah_p,size_ah_p);
file_write("/tmp/ah-pau.wav",audio_buf_ah_pau,size_ah_pau);
file_write("/tmp/ah-r.wav",audio_buf_ah_r,size_ah_r);
file_write("/tmp/ah-s.wav",audio_buf_ah_s,size_ah_s);
file_write("/tmp/ah-sh.wav",audio_buf_ah_sh,size_ah_sh);
file_write("/tmp/ah-t.wav",audio_buf_ah_t,size_ah_t);
file_write("/tmp/ah-th.wav",audio_buf_ah_th,size_ah_th);
file_write("/tmp/ah-uh.wav",audio_buf_ah_uh,size_ah_uh);
file_write("/tmp/ah-uw.wav",audio_buf_ah_uw,size_ah_uw);
file_write("/tmp/ah-v.wav",audio_buf_ah_v,size_ah_v);
file_write("/tmp/ah-w.wav",audio_buf_ah_w,size_ah_w);
file_write("/tmp/ah-y.wav",audio_buf_ah_y,size_ah_y);
file_write("/tmp/ah-z.wav",audio_buf_ah_z,size_ah_z);
file_write("/tmp/ah-zh.wav",audio_buf_ah_zh,size_ah_zh);

//ao diphones  
unsigned  long * audio_buf_ao_aa = ( unsigned  long *)&_binary_ao_aa_wav_start; 
unsigned long size_ao_aa = ( unsigned long )&_binary_ao_aa_wav_size;
unsigned  long * audio_buf_ao_ae = ( unsigned  long *)&_binary_ao_ae_wav_start;
unsigned long size_ao_ae = ( unsigned long )&_binary_ao_ae_wav_size;
unsigned  long * audio_buf_ao_ah = ( unsigned  long *)&_binary_ao_ah_wav_start;
unsigned long size_ao_ah = ( unsigned long )&_binary_ao_ah_wav_size;
unsigned  long * audio_buf_ao_ao = ( unsigned  long *)&_binary_ao_ao_wav_start;
unsigned long size_ao_ao = ( unsigned long )&_binary_ao_ao_wav_size;
unsigned  long * audio_buf_ao_aw = ( unsigned  long *)&_binary_ao_aw_wav_start;
unsigned long size_ao_aw = ( unsigned long )&_binary_ao_aw_wav_size;
unsigned  long * audio_buf_ao_ax = ( unsigned  long *)&_binary_ao_ax_wav_start;
unsigned long size_ao_ax = ( unsigned long )&_binary_ao_ax_wav_size;
unsigned  long * audio_buf_ao_ay = ( unsigned  long *)&_binary_ao_ay_wav_start;
unsigned long size_ao_ay = ( unsigned long )&_binary_ao_ay_wav_size;
unsigned  long * audio_buf_ao_b = ( unsigned  long *)&_binary_ao_b_wav_start;
unsigned long size_ao_b = ( unsigned long )&_binary_ao_b_wav_size;
unsigned  long * audio_buf_ao_ch = ( unsigned  long *)&_binary_ao_ch_wav_start;
unsigned long size_ao_ch = ( unsigned long )&_binary_ao_ch_wav_size;
unsigned  long * audio_buf_ao_d = ( unsigned  long *)&_binary_ao_d_wav_start;
unsigned long size_ao_d = ( unsigned long )&_binary_ao_d_wav_size;
unsigned  long * audio_buf_ao_dh = ( unsigned  long *)&_binary_ao_dh_wav_start;
unsigned long size_ao_dh = ( unsigned long )&_binary_ao_dh_wav_size;
unsigned  long * audio_buf_ao_eh = ( unsigned  long *)&_binary_ao_eh_wav_start;
unsigned long size_ao_eh = ( unsigned long )&_binary_ao_eh_wav_size;
unsigned  long * audio_buf_ao_er = ( unsigned  long *)&_binary_ao_er_wav_start;
unsigned long size_ao_er = ( unsigned long )&_binary_ao_er_wav_size;
unsigned  long * audio_buf_ao_ey = ( unsigned  long *)&_binary_ao_ey_wav_start;
unsigned long size_ao_ey = ( unsigned long )&_binary_ao_ey_wav_size;
unsigned  long * audio_buf_ao_f = ( unsigned  long *)&_binary_ao_f_wav_start;
unsigned long size_ao_f = ( unsigned long )&_binary_ao_f_wav_size;
unsigned  long * audio_buf_ao_g = ( unsigned  long *)&_binary_ao_g_wav_start;
unsigned long size_ao_g = ( unsigned long )&_binary_ao_g_wav_size;
unsigned  long * audio_buf_ao_hh = ( unsigned  long *)&_binary_ao_hh_wav_start;
unsigned long size_ao_hh = ( unsigned long )&_binary_ao_hh_wav_size;
unsigned  long * audio_buf_ao_ih = ( unsigned  long *)&_binary_ao_ih_wav_start;
unsigned long size_ao_ih = ( unsigned long )&_binary_ao_ih_wav_size;
unsigned  long * audio_buf_ao_iy = ( unsigned  long *)&_binary_ao_iy_wav_start;
unsigned long size_ao_iy = ( unsigned long )&_binary_ao_iy_wav_size;
unsigned  long * audio_buf_ao_jh = ( unsigned  long *)&_binary_ao_jh_wav_start;
unsigned long size_ao_jh = ( unsigned long )&_binary_ao_jh_wav_size;
unsigned  long * audio_buf_ao_k = ( unsigned  long *)&_binary_ao_k_wav_start;
unsigned long size_ao_k = ( unsigned long )&_binary_ao_k_wav_size;
unsigned  long * audio_buf_ao_l = ( unsigned  long *)&_binary_ao_l_wav_start;
unsigned long size_ao_l = ( unsigned long )&_binary_ao_l_wav_size;
unsigned  long * audio_buf_ao_m = ( unsigned  long *)&_binary_ao_m_wav_start;
unsigned long size_ao_m = ( unsigned long )&_binary_ao_m_wav_size;
unsigned  long * audio_buf_ao_n = ( unsigned  long *)&_binary_ao_n_wav_start;
unsigned long size_ao_n = ( unsigned long )&_binary_ao_n_wav_size;
unsigned  long * audio_buf_ao_ng = ( unsigned  long *)&_binary_ao_ng_wav_start;
unsigned long size_ao_ng = ( unsigned long )&_binary_ao_ng_wav_size;
unsigned  long * audio_buf_ao_ow = ( unsigned  long *)&_binary_ao_ow_wav_start;
unsigned long size_ao_ow = ( unsigned long )&_binary_ao_ow_wav_size;
unsigned  long * audio_buf_ao_oy = ( unsigned  long *)&_binary_ao_oy_wav_start;
unsigned long size_ao_oy = ( unsigned long )&_binary_ao_oy_wav_size;
unsigned  long * audio_buf_ao_p = ( unsigned  long *)&_binary_ao_p_wav_start;
unsigned long size_ao_p = ( unsigned long )&_binary_ao_p_wav_size;
unsigned  long * audio_buf_ao_pau = ( unsigned  long *)&_binary_ao_pau_wav_start;
unsigned long size_ao_pau = ( unsigned long )&_binary_ao_pau_wav_size;
unsigned  long * audio_buf_ao_r = ( unsigned  long *)&_binary_ao_r_wav_start;
unsigned long size_ao_r = ( unsigned long )&_binary_ao_r_wav_size;
unsigned  long * audio_buf_ao_s = ( unsigned  long *)&_binary_ao_s_wav_start;
unsigned long size_ao_s = ( unsigned long )&_binary_ao_s_wav_size;
unsigned  long * audio_buf_ao_sh = ( unsigned  long *)&_binary_ao_sh_wav_start;
unsigned long size_ao_sh = ( unsigned long )&_binary_ao_sh_wav_size;
unsigned  long * audio_buf_ao_t = ( unsigned  long *)&_binary_ao_t_wav_start;
unsigned long size_ao_t = ( unsigned long )&_binary_ao_t_wav_size;
unsigned  long * audio_buf_ao_th = ( unsigned  long *)&_binary_ao_th_wav_start;
unsigned long size_ao_th = ( unsigned long )&_binary_ao_th_wav_size;
unsigned  long * audio_buf_ao_uh = ( unsigned  long *)&_binary_ao_uh_wav_start;
unsigned long size_ao_uh = ( unsigned long )&_binary_ao_uh_wav_size;
unsigned  long * audio_buf_ao_uw = ( unsigned  long *)&_binary_ao_uw_wav_start;
unsigned long size_ao_uw = ( unsigned long )&_binary_ao_uw_wav_size;
unsigned  long * audio_buf_ao_v = ( unsigned  long *)&_binary_ao_v_wav_start;
unsigned long size_ao_v = ( unsigned long )&_binary_ao_v_wav_size;
unsigned  long * audio_buf_ao_w = ( unsigned  long *)&_binary_ao_w_wav_start;
unsigned long size_ao_w = ( unsigned long )&_binary_ao_w_wav_size;
unsigned  long * audio_buf_ao_y = ( unsigned  long *)&_binary_ao_y_wav_start;
unsigned long size_ao_y = ( unsigned long )&_binary_ao_y_wav_size;
unsigned  long * audio_buf_ao_z = ( unsigned  long *)&_binary_ao_z_wav_start;
unsigned long size_ao_z = ( unsigned long )&_binary_ao_z_wav_size;
unsigned  long * audio_buf_ao_zh = ( unsigned  long *)&_binary_ao_zh_wav_start;
unsigned long size_ao_zh = ( unsigned long )&_binary_ao_zh_wav_size;
//ao diphones
file_write("/tmp/ao-aa.wav",audio_buf_ao_aa,size_ao_aa);
file_write("/tmp/ao-ae.wav",audio_buf_ao_ae,size_ao_ae);
file_write("/tmp/ao-ah.wav",audio_buf_ao_ah,size_ao_ah);
file_write("/tmp/ao-ao.wav",audio_buf_ao_ao,size_ao_ao);
file_write("/tmp/ao-aw.wav",audio_buf_ao_aw,size_ao_aw);
file_write("/tmp/ao-ax.wav",audio_buf_ao_ax,size_ao_ax);
file_write("/tmp/ao-ay.wav",audio_buf_ao_ay,size_ao_ay);
file_write("/tmp/ao-b.wav",audio_buf_ao_b,size_ao_b);
file_write("/tmp/ao-ch.wav",audio_buf_ao_ch,size_ao_ch);
file_write("/tmp/ao-d.wav",audio_buf_ao_d,size_ao_d);
file_write("/tmp/ao-dh.wav",audio_buf_ao_dh,size_ao_dh);
file_write("/tmp/ao-eh.wav",audio_buf_ao_eh,size_ao_eh);
file_write("/tmp/ao-er.wav",audio_buf_ao_er,size_ao_er);
file_write("/tmp/ao-ey.wav",audio_buf_ao_ey,size_ao_ey);
file_write("/tmp/ao-f.wav",audio_buf_ao_f,size_ao_f);
file_write("/tmp/ao-g.wav",audio_buf_ao_g,size_ao_g);
file_write("/tmp/ao-hh.wav",audio_buf_ao_hh,size_ao_hh);
file_write("/tmp/ao-ih.wav",audio_buf_ao_ih,size_ao_ih);
file_write("/tmp/ao-iy.wav",audio_buf_ao_iy,size_ao_iy);
file_write("/tmp/ao-jh.wav",audio_buf_ao_jh,size_ao_jh);
file_write("/tmp/ao-k.wav",audio_buf_ao_k,size_ao_k);
file_write("/tmp/ao-l.wav",audio_buf_ao_l,size_ao_l);
file_write("/tmp/ao-m.wav",audio_buf_ao_m,size_ao_m);
file_write("/tmp/ao-n.wav",audio_buf_ao_n,size_ao_n);
file_write("/tmp/ao-ng.wav",audio_buf_ao_ng,size_ao_ng);
file_write("/tmp/ao-ow.wav",audio_buf_ao_ow,size_ao_ow);
file_write("/tmp/ao-oy.wav",audio_buf_ao_oy,size_ao_oy);
file_write("/tmp/ao-p.wav",audio_buf_ao_p,size_ao_p);
file_write("/tmp/ao-pau.wav",audio_buf_ao_pau,size_ao_pau);
file_write("/tmp/ao-r.wav",audio_buf_ao_r,size_ao_r);
file_write("/tmp/ao-s.wav",audio_buf_ao_s,size_ao_s);
file_write("/tmp/ao-sh.wav",audio_buf_ao_sh,size_ao_sh);
file_write("/tmp/ao-t.wav",audio_buf_ao_t,size_ao_t);
file_write("/tmp/ao-th.wav",audio_buf_ao_th,size_ao_th);
file_write("/tmp/ao-uh.wav",audio_buf_ao_uh,size_ao_uh);
file_write("/tmp/ao-uw.wav",audio_buf_ao_uw,size_ao_uw);
file_write("/tmp/ao-v.wav",audio_buf_ao_v,size_ao_v);
file_write("/tmp/ao-w.wav",audio_buf_ao_w,size_ao_w);
file_write("/tmp/ao-y.wav",audio_buf_ao_y,size_ao_y);
file_write("/tmp/ao-z.wav",audio_buf_ao_z,size_ao_z);
file_write("/tmp/ao-zh.wav",audio_buf_ao_zh,size_ao_zh);

//aw diphones  
unsigned  long * audio_buf_aw_aa = ( unsigned  long *)&_binary_aw_aa_wav_start; 
unsigned long size_aw_aa = ( unsigned long )&_binary_aw_aa_wav_size;
unsigned  long * audio_buf_aw_ae = ( unsigned  long *)&_binary_aw_ae_wav_start;
unsigned long size_aw_ae = ( unsigned long )&_binary_aw_ae_wav_size;
unsigned  long * audio_buf_aw_ah = ( unsigned  long *)&_binary_aw_ah_wav_start;
unsigned long size_aw_ah = ( unsigned long )&_binary_aw_ah_wav_size;
unsigned  long * audio_buf_aw_ao = ( unsigned  long *)&_binary_aw_ao_wav_start;
unsigned long size_aw_ao = ( unsigned long )&_binary_aw_ao_wav_size;
unsigned  long * audio_buf_aw_aw = ( unsigned  long *)&_binary_aw_aw_wav_start;
unsigned long size_aw_aw = ( unsigned long )&_binary_aw_aw_wav_size;
unsigned  long * audio_buf_aw_ax = ( unsigned  long *)&_binary_aw_ax_wav_start;
unsigned long size_aw_ax = ( unsigned long )&_binary_aw_ax_wav_size;
unsigned  long * audio_buf_aw_ay = ( unsigned  long *)&_binary_aw_ay_wav_start;
unsigned long size_aw_ay = ( unsigned long )&_binary_aw_ay_wav_size;
unsigned  long * audio_buf_aw_b = ( unsigned  long *)&_binary_aw_b_wav_start;
unsigned long size_aw_b = ( unsigned long )&_binary_aw_b_wav_size;
unsigned  long * audio_buf_aw_ch = ( unsigned  long *)&_binary_aw_ch_wav_start;
unsigned long size_aw_ch = ( unsigned long )&_binary_aw_ch_wav_size;
unsigned  long * audio_buf_aw_d = ( unsigned  long *)&_binary_aw_d_wav_start;
unsigned long size_aw_d = ( unsigned long )&_binary_aw_d_wav_size;
unsigned  long * audio_buf_aw_dh = ( unsigned  long *)&_binary_aw_dh_wav_start;
unsigned long size_aw_dh = ( unsigned long )&_binary_aw_dh_wav_size;
unsigned  long * audio_buf_aw_eh = ( unsigned  long *)&_binary_aw_eh_wav_start;
unsigned long size_aw_eh = ( unsigned long )&_binary_aw_eh_wav_size;
unsigned  long * audio_buf_aw_er = ( unsigned  long *)&_binary_aw_er_wav_start;
unsigned long size_aw_er = ( unsigned long )&_binary_aw_er_wav_size;
unsigned  long * audio_buf_aw_ey = ( unsigned  long *)&_binary_aw_ey_wav_start;
unsigned long size_aw_ey = ( unsigned long )&_binary_aw_ey_wav_size;
unsigned  long * audio_buf_aw_f = ( unsigned  long *)&_binary_aw_f_wav_start;
unsigned long size_aw_f = ( unsigned long )&_binary_aw_f_wav_size;
unsigned  long * audio_buf_aw_g = ( unsigned  long *)&_binary_aw_g_wav_start;
unsigned long size_aw_g = ( unsigned long )&_binary_aw_g_wav_size;
unsigned  long * audio_buf_aw_hh = ( unsigned  long *)&_binary_aw_hh_wav_start;
unsigned long size_aw_hh = ( unsigned long )&_binary_aw_hh_wav_size;
unsigned  long * audio_buf_aw_ih = ( unsigned  long *)&_binary_aw_ih_wav_start;
unsigned long size_aw_ih = ( unsigned long )&_binary_aw_ih_wav_size;
unsigned  long * audio_buf_aw_iy = ( unsigned  long *)&_binary_aw_iy_wav_start;
unsigned long size_aw_iy = ( unsigned long )&_binary_aw_iy_wav_size;
unsigned  long * audio_buf_aw_jh = ( unsigned  long *)&_binary_aw_jh_wav_start;
unsigned long size_aw_jh = ( unsigned long )&_binary_aw_jh_wav_size;
unsigned  long * audio_buf_aw_k = ( unsigned  long *)&_binary_aw_k_wav_start;
unsigned long size_aw_k = ( unsigned long )&_binary_aw_k_wav_size;
unsigned  long * audio_buf_aw_l = ( unsigned  long *)&_binary_aw_l_wav_start;
unsigned long size_aw_l = ( unsigned long )&_binary_aw_l_wav_size;
unsigned  long * audio_buf_aw_m = ( unsigned  long *)&_binary_aw_m_wav_start;
unsigned long size_aw_m = ( unsigned long )&_binary_aw_m_wav_size;
unsigned  long * audio_buf_aw_n = ( unsigned  long *)&_binary_aw_n_wav_start;
unsigned long size_aw_n = ( unsigned long )&_binary_aw_n_wav_size;
unsigned  long * audio_buf_aw_ng = ( unsigned  long *)&_binary_aw_ng_wav_start;
unsigned long size_aw_ng = ( unsigned long )&_binary_aw_ng_wav_size;
unsigned  long * audio_buf_aw_ow = ( unsigned  long *)&_binary_aw_ow_wav_start;
unsigned long size_aw_ow = ( unsigned long )&_binary_aw_ow_wav_size;
unsigned  long * audio_buf_aw_oy = ( unsigned  long *)&_binary_aw_oy_wav_start;
unsigned long size_aw_oy = ( unsigned long )&_binary_aw_oy_wav_size;
unsigned  long * audio_buf_aw_p = ( unsigned  long *)&_binary_aw_p_wav_start;
unsigned long size_aw_p = ( unsigned long )&_binary_aw_p_wav_size;
unsigned  long * audio_buf_aw_pau = ( unsigned  long *)&_binary_aw_pau_wav_start;
unsigned long size_aw_pau = ( unsigned long )&_binary_aw_pau_wav_size;
unsigned  long * audio_buf_aw_r = ( unsigned  long *)&_binary_aw_r_wav_start;
unsigned long size_aw_r = ( unsigned long )&_binary_aw_r_wav_size;
unsigned  long * audio_buf_aw_s = ( unsigned  long *)&_binary_aw_s_wav_start;
unsigned long size_aw_s = ( unsigned long )&_binary_aw_s_wav_size;
unsigned  long * audio_buf_aw_sh = ( unsigned  long *)&_binary_aw_sh_wav_start;
unsigned long size_aw_sh = ( unsigned long )&_binary_aw_sh_wav_size;
unsigned  long * audio_buf_aw_t = ( unsigned  long *)&_binary_aw_t_wav_start;
unsigned long size_aw_t = ( unsigned long )&_binary_aw_t_wav_size;
unsigned  long * audio_buf_aw_th = ( unsigned  long *)&_binary_aw_th_wav_start;
unsigned long size_aw_th = ( unsigned long )&_binary_aw_th_wav_size;
unsigned  long * audio_buf_aw_uh = ( unsigned  long *)&_binary_aw_uh_wav_start;
unsigned long size_aw_uh = ( unsigned long )&_binary_aw_uh_wav_size;
unsigned  long * audio_buf_aw_uw = ( unsigned  long *)&_binary_aw_uw_wav_start;
unsigned long size_aw_uw = ( unsigned long )&_binary_aw_uw_wav_size;
unsigned  long * audio_buf_aw_v = ( unsigned  long *)&_binary_aw_v_wav_start;
unsigned long size_aw_v = ( unsigned long )&_binary_aw_v_wav_size;
unsigned  long * audio_buf_aw_w = ( unsigned  long *)&_binary_aw_w_wav_start;
unsigned long size_aw_w = ( unsigned long )&_binary_aw_w_wav_size;
unsigned  long * audio_buf_aw_y = ( unsigned  long *)&_binary_aw_y_wav_start;
unsigned long size_aw_y = ( unsigned long )&_binary_aw_y_wav_size;
unsigned  long * audio_buf_aw_z = ( unsigned  long *)&_binary_aw_z_wav_start;
unsigned long size_aw_z = ( unsigned long )&_binary_aw_z_wav_size;
unsigned  long * audio_buf_aw_zh = ( unsigned  long *)&_binary_aw_zh_wav_start;
unsigned long size_aw_zh = ( unsigned long )&_binary_aw_zh_wav_size;
//aw diphones
file_write("/tmp/aw-aa.wav",audio_buf_aw_aa,size_aw_aa);
file_write("/tmp/aw-ae.wav",audio_buf_aw_ae,size_aw_ae);
file_write("/tmp/aw-ah.wav",audio_buf_aw_ah,size_aw_ah);
file_write("/tmp/aw-ao.wav",audio_buf_aw_ao,size_aw_ao);
file_write("/tmp/aw-aw.wav",audio_buf_aw_aw,size_aw_aw);
file_write("/tmp/aw-ax.wav",audio_buf_aw_ax,size_aw_ax);
file_write("/tmp/aw-ay.wav",audio_buf_aw_ay,size_aw_ay);
file_write("/tmp/aw-b.wav",audio_buf_aw_b,size_aw_b);
file_write("/tmp/aw-ch.wav",audio_buf_aw_ch,size_aw_ch);
file_write("/tmp/aw-d.wav",audio_buf_aw_d,size_aw_d);
file_write("/tmp/aw-dh.wav",audio_buf_aw_dh,size_aw_dh);
file_write("/tmp/aw-eh.wav",audio_buf_aw_eh,size_aw_eh);
file_write("/tmp/aw-er.wav",audio_buf_aw_er,size_aw_er);
file_write("/tmp/aw-ey.wav",audio_buf_aw_ey,size_aw_ey);
file_write("/tmp/aw-f.wav",audio_buf_aw_f,size_aw_f);
file_write("/tmp/aw-g.wav",audio_buf_aw_g,size_aw_g);
file_write("/tmp/aw-hh.wav",audio_buf_aw_hh,size_aw_hh);
file_write("/tmp/aw-ih.wav",audio_buf_aw_ih,size_aw_ih);
file_write("/tmp/aw-iy.wav",audio_buf_aw_iy,size_aw_iy);
file_write("/tmp/aw-jh.wav",audio_buf_aw_jh,size_aw_jh);
file_write("/tmp/aw-k.wav",audio_buf_aw_k,size_aw_k);
file_write("/tmp/aw-l.wav",audio_buf_aw_l,size_aw_l);
file_write("/tmp/aw-m.wav",audio_buf_aw_m,size_aw_m);
file_write("/tmp/aw-n.wav",audio_buf_aw_n,size_aw_n);
file_write("/tmp/aw-ng.wav",audio_buf_aw_ng,size_aw_ng);
file_write("/tmp/aw-ow.wav",audio_buf_aw_ow,size_aw_ow);
file_write("/tmp/aw-oy.wav",audio_buf_aw_oy,size_aw_oy);
file_write("/tmp/aw-p.wav",audio_buf_aw_p,size_aw_p);
file_write("/tmp/aw-pau.wav",audio_buf_aw_pau,size_aw_pau);
file_write("/tmp/aw-r.wav",audio_buf_aw_r,size_aw_r);
file_write("/tmp/aw-s.wav",audio_buf_aw_s,size_aw_s);
file_write("/tmp/aw-sh.wav",audio_buf_aw_sh,size_aw_sh);
file_write("/tmp/aw-t.wav",audio_buf_aw_t,size_aw_t);
file_write("/tmp/aw-th.wav",audio_buf_aw_th,size_aw_th);
file_write("/tmp/aw-uh.wav",audio_buf_aw_uh,size_aw_uh);
file_write("/tmp/aw-uw.wav",audio_buf_aw_uw,size_aw_uw);
file_write("/tmp/aw-v.wav",audio_buf_aw_v,size_aw_v);
file_write("/tmp/aw-w.wav",audio_buf_aw_w,size_aw_w);
file_write("/tmp/aw-y.wav",audio_buf_aw_y,size_aw_y);
file_write("/tmp/aw-z.wav",audio_buf_aw_z,size_aw_z);
file_write("/tmp/aw-zh.wav",audio_buf_aw_zh,size_aw_zh);

//ax diphones  
unsigned  long * audio_buf_ax_aa = ( unsigned  long *)&_binary_ax_aa_wav_start; 
unsigned long size_ax_aa = ( unsigned long )&_binary_ax_aa_wav_size;
unsigned  long * audio_buf_ax_ae = ( unsigned  long *)&_binary_ax_ae_wav_start;
unsigned long size_ax_ae = ( unsigned long )&_binary_ax_ae_wav_size;
unsigned  long * audio_buf_ax_ah = ( unsigned  long *)&_binary_ax_ah_wav_start;
unsigned long size_ax_ah = ( unsigned long )&_binary_ax_ah_wav_size;
unsigned  long * audio_buf_ax_ao = ( unsigned  long *)&_binary_ax_ao_wav_start;
unsigned long size_ax_ao = ( unsigned long )&_binary_ax_ao_wav_size;
unsigned  long * audio_buf_ax_aw = ( unsigned  long *)&_binary_ax_aw_wav_start;
unsigned long size_ax_aw = ( unsigned long )&_binary_ax_aw_wav_size;
unsigned  long * audio_buf_ax_ax = ( unsigned  long *)&_binary_ax_ax_wav_start;
unsigned long size_ax_ax = ( unsigned long )&_binary_ax_ax_wav_size;
unsigned  long * audio_buf_ax_ay = ( unsigned  long *)&_binary_ax_ay_wav_start;
unsigned long size_ax_ay = ( unsigned long )&_binary_ax_ay_wav_size;
unsigned  long * audio_buf_ax_b = ( unsigned  long *)&_binary_ax_b_wav_start;
unsigned long size_ax_b = ( unsigned long )&_binary_ax_b_wav_size;
unsigned  long * audio_buf_ax_ch = ( unsigned  long *)&_binary_ax_ch_wav_start;
unsigned long size_ax_ch = ( unsigned long )&_binary_ax_ch_wav_size;
unsigned  long * audio_buf_ax_d = ( unsigned  long *)&_binary_ax_d_wav_start;
unsigned long size_ax_d = ( unsigned long )&_binary_ax_d_wav_size;
unsigned  long * audio_buf_ax_dh = ( unsigned  long *)&_binary_ax_dh_wav_start;
unsigned long size_ax_dh = ( unsigned long )&_binary_ax_dh_wav_size;
unsigned  long * audio_buf_ax_eh = ( unsigned  long *)&_binary_ax_eh_wav_start;
unsigned long size_ax_eh = ( unsigned long )&_binary_ax_eh_wav_size;
unsigned  long * audio_buf_ax_er = ( unsigned  long *)&_binary_ax_er_wav_start;
unsigned long size_ax_er = ( unsigned long )&_binary_ax_er_wav_size;
unsigned  long * audio_buf_ax_ey = ( unsigned  long *)&_binary_ax_ey_wav_start;
unsigned long size_ax_ey = ( unsigned long )&_binary_ax_ey_wav_size;
unsigned  long * audio_buf_ax_f = ( unsigned  long *)&_binary_ax_f_wav_start;
unsigned long size_ax_f = ( unsigned long )&_binary_ax_f_wav_size;
unsigned  long * audio_buf_ax_g = ( unsigned  long *)&_binary_ax_g_wav_start;
unsigned long size_ax_g = ( unsigned long )&_binary_ax_g_wav_size;
unsigned  long * audio_buf_ax_hh = ( unsigned  long *)&_binary_ax_hh_wav_start;
unsigned long size_ax_hh = ( unsigned long )&_binary_ax_hh_wav_size;
unsigned  long * audio_buf_ax_ih = ( unsigned  long *)&_binary_ax_ih_wav_start;
unsigned long size_ax_ih = ( unsigned long )&_binary_ax_ih_wav_size;
unsigned  long * audio_buf_ax_iy = ( unsigned  long *)&_binary_ax_iy_wav_start;
unsigned long size_ax_iy = ( unsigned long )&_binary_ax_iy_wav_size;
unsigned  long * audio_buf_ax_jh = ( unsigned  long *)&_binary_ax_jh_wav_start;
unsigned long size_ax_jh = ( unsigned long )&_binary_ax_jh_wav_size;
unsigned  long * audio_buf_ax_k = ( unsigned  long *)&_binary_ax_k_wav_start;
unsigned long size_ax_k = ( unsigned long )&_binary_ax_k_wav_size;
unsigned  long * audio_buf_ax_l = ( unsigned  long *)&_binary_ax_l_wav_start;
unsigned long size_ax_l = ( unsigned long )&_binary_ax_l_wav_size;
unsigned  long * audio_buf_ax_m = ( unsigned  long *)&_binary_ax_m_wav_start;
unsigned long size_ax_m = ( unsigned long )&_binary_ax_m_wav_size;
unsigned  long * audio_buf_ax_n = ( unsigned  long *)&_binary_ax_n_wav_start;
unsigned long size_ax_n = ( unsigned long )&_binary_ax_n_wav_size;
unsigned  long * audio_buf_ax_ng = ( unsigned  long *)&_binary_ax_ng_wav_start;
unsigned long size_ax_ng = ( unsigned long )&_binary_ax_ng_wav_size;
unsigned  long * audio_buf_ax_ow = ( unsigned  long *)&_binary_ax_ow_wav_start;
unsigned long size_ax_ow = ( unsigned long )&_binary_ax_ow_wav_size;
unsigned  long * audio_buf_ax_oy = ( unsigned  long *)&_binary_ax_oy_wav_start;
unsigned long size_ax_oy = ( unsigned long )&_binary_ax_oy_wav_size;
unsigned  long * audio_buf_ax_p = ( unsigned  long *)&_binary_ax_p_wav_start;
unsigned long size_ax_p = ( unsigned long )&_binary_ax_p_wav_size;
unsigned  long * audio_buf_ax_pau = ( unsigned  long *)&_binary_ax_pau_wav_start;
unsigned long size_ax_pau = ( unsigned long )&_binary_ax_pau_wav_size;
unsigned  long * audio_buf_ax_r = ( unsigned  long *)&_binary_ax_r_wav_start;
unsigned long size_ax_r = ( unsigned long )&_binary_ax_r_wav_size;
unsigned  long * audio_buf_ax_s = ( unsigned  long *)&_binary_ax_s_wav_start;
unsigned long size_ax_s = ( unsigned long )&_binary_ax_s_wav_size;
unsigned  long * audio_buf_ax_sh = ( unsigned  long *)&_binary_ax_sh_wav_start;
unsigned long size_ax_sh = ( unsigned long )&_binary_ax_sh_wav_size;
unsigned  long * audio_buf_ax_t = ( unsigned  long *)&_binary_ax_t_wav_start;
unsigned long size_ax_t = ( unsigned long )&_binary_ax_t_wav_size;
unsigned  long * audio_buf_ax_th = ( unsigned  long *)&_binary_ax_th_wav_start;
unsigned long size_ax_th = ( unsigned long )&_binary_ax_th_wav_size;
unsigned  long * audio_buf_ax_uh = ( unsigned  long *)&_binary_ax_uh_wav_start;
unsigned long size_ax_uh = ( unsigned long )&_binary_ax_uh_wav_size;
unsigned  long * audio_buf_ax_uw = ( unsigned  long *)&_binary_ax_uw_wav_start;
unsigned long size_ax_uw = ( unsigned long )&_binary_ax_uw_wav_size;
unsigned  long * audio_buf_ax_v = ( unsigned  long *)&_binary_ax_v_wav_start;
unsigned long size_ax_v = ( unsigned long )&_binary_ax_v_wav_size;
unsigned  long * audio_buf_ax_w = ( unsigned  long *)&_binary_ax_w_wav_start;
unsigned long size_ax_w = ( unsigned long )&_binary_ax_w_wav_size;
unsigned  long * audio_buf_ax_y = ( unsigned  long *)&_binary_ax_y_wav_start;
unsigned long size_ax_y = ( unsigned long )&_binary_ax_y_wav_size;
unsigned  long * audio_buf_ax_z = ( unsigned  long *)&_binary_ax_z_wav_start;
unsigned long size_ax_z = ( unsigned long )&_binary_ax_z_wav_size;
unsigned  long * audio_buf_ax_zh = ( unsigned  long *)&_binary_ax_zh_wav_start;
unsigned long size_ax_zh = ( unsigned long )&_binary_ax_zh_wav_size;
//ax diphones
file_write("/tmp/ax-aa.wav",audio_buf_ax_aa,size_ax_aa);
file_write("/tmp/ax-ae.wav",audio_buf_ax_ae,size_ax_ae);
file_write("/tmp/ax-ah.wav",audio_buf_ax_ah,size_ax_ah);
file_write("/tmp/ax-ao.wav",audio_buf_ax_ao,size_ax_ao);
file_write("/tmp/ax-aw.wav",audio_buf_ax_aw,size_ax_aw);
file_write("/tmp/ax-ax.wav",audio_buf_ax_ax,size_ax_ax);
file_write("/tmp/ax-ay.wav",audio_buf_ax_ay,size_ax_ay);
file_write("/tmp/ax-b.wav",audio_buf_ax_b,size_ax_b);
file_write("/tmp/ax-ch.wav",audio_buf_ax_ch,size_ax_ch);
file_write("/tmp/ax-d.wav",audio_buf_ax_d,size_ax_d);
file_write("/tmp/ax-dh.wav",audio_buf_ax_dh,size_ax_dh);
file_write("/tmp/ax-eh.wav",audio_buf_ax_eh,size_ax_eh);
file_write("/tmp/ax-er.wav",audio_buf_ax_er,size_ax_er);
file_write("/tmp/ax-ey.wav",audio_buf_ax_ey,size_ax_ey);
file_write("/tmp/ax-f.wav",audio_buf_ax_f,size_ax_f);
file_write("/tmp/ax-g.wav",audio_buf_ax_g,size_ax_g);
file_write("/tmp/ax-hh.wav",audio_buf_ax_hh,size_ax_hh);
file_write("/tmp/ax-ih.wav",audio_buf_ax_ih,size_ax_ih);
file_write("/tmp/ax-iy.wav",audio_buf_ax_iy,size_ax_iy);
file_write("/tmp/ax-jh.wav",audio_buf_ax_jh,size_ax_jh);
file_write("/tmp/ax-k.wav",audio_buf_ax_k,size_ax_k);
file_write("/tmp/ax-l.wav",audio_buf_ax_l,size_ax_l);
file_write("/tmp/ax-m.wav",audio_buf_ax_m,size_ax_m);
file_write("/tmp/ax-n.wav",audio_buf_ax_n,size_ax_n);
file_write("/tmp/ax-ng.wav",audio_buf_ax_ng,size_ax_ng);
file_write("/tmp/ax-ow.wav",audio_buf_ax_ow,size_ax_ow);
file_write("/tmp/ax-oy.wav",audio_buf_ax_oy,size_ax_oy);
file_write("/tmp/ax-p.wav",audio_buf_ax_p,size_ax_p);
file_write("/tmp/ax-pau.wav",audio_buf_ax_pau,size_ax_pau);
file_write("/tmp/ax-r.wav",audio_buf_ax_r,size_ax_r);
file_write("/tmp/ax-s.wav",audio_buf_ax_s,size_ax_s);
file_write("/tmp/ax-sh.wav",audio_buf_ax_sh,size_ax_sh);
file_write("/tmp/ax-t.wav",audio_buf_ax_t,size_ax_t);
file_write("/tmp/ax-th.wav",audio_buf_ax_th,size_ax_th);
file_write("/tmp/ax-uh.wav",audio_buf_ax_uh,size_ax_uh);
file_write("/tmp/ax-uw.wav",audio_buf_ax_uw,size_ax_uw);
file_write("/tmp/ax-v.wav",audio_buf_ax_v,size_ax_v);
file_write("/tmp/ax-w.wav",audio_buf_ax_w,size_ax_w);
file_write("/tmp/ax-y.wav",audio_buf_ax_y,size_ax_y);
file_write("/tmp/ax-z.wav",audio_buf_ax_z,size_ax_z);
file_write("/tmp/ax-zh.wav",audio_buf_ax_zh,size_ax_zh);

//ay diphones  
unsigned  long * audio_buf_ay_aa = ( unsigned  long *)&_binary_ay_aa_wav_start; 
unsigned long size_ay_aa = ( unsigned long )&_binary_ay_aa_wav_size;
unsigned  long * audio_buf_ay_ae = ( unsigned  long *)&_binary_ay_ae_wav_start;
unsigned long size_ay_ae = ( unsigned long )&_binary_ay_ae_wav_size;
unsigned  long * audio_buf_ay_ah = ( unsigned  long *)&_binary_ay_ah_wav_start;
unsigned long size_ay_ah = ( unsigned long )&_binary_ay_ah_wav_size;
unsigned  long * audio_buf_ay_ao = ( unsigned  long *)&_binary_ay_ao_wav_start;
unsigned long size_ay_ao = ( unsigned long )&_binary_ay_ao_wav_size;
unsigned  long * audio_buf_ay_aw = ( unsigned  long *)&_binary_ay_aw_wav_start;
unsigned long size_ay_aw = ( unsigned long )&_binary_ay_aw_wav_size;
unsigned  long * audio_buf_ay_ax = ( unsigned  long *)&_binary_ay_ax_wav_start;
unsigned long size_ay_ax = ( unsigned long )&_binary_ay_ax_wav_size;
unsigned  long * audio_buf_ay_ay = ( unsigned  long *)&_binary_ay_ay_wav_start;
unsigned long size_ay_ay = ( unsigned long )&_binary_ay_ay_wav_size;
unsigned  long * audio_buf_ay_b = ( unsigned  long *)&_binary_ay_b_wav_start;
unsigned long size_ay_b = ( unsigned long )&_binary_ay_b_wav_size;
unsigned  long * audio_buf_ay_ch = ( unsigned  long *)&_binary_ay_ch_wav_start;
unsigned long size_ay_ch = ( unsigned long )&_binary_ay_ch_wav_size;
unsigned  long * audio_buf_ay_d = ( unsigned  long *)&_binary_ay_d_wav_start;
unsigned long size_ay_d = ( unsigned long )&_binary_ay_d_wav_size;
unsigned  long * audio_buf_ay_dh = ( unsigned  long *)&_binary_ay_dh_wav_start;
unsigned long size_ay_dh = ( unsigned long )&_binary_ay_dh_wav_size;
unsigned  long * audio_buf_ay_eh = ( unsigned  long *)&_binary_ay_eh_wav_start;
unsigned long size_ay_eh = ( unsigned long )&_binary_ay_eh_wav_size;
unsigned  long * audio_buf_ay_er = ( unsigned  long *)&_binary_ay_er_wav_start;
unsigned long size_ay_er = ( unsigned long )&_binary_ay_er_wav_size;
unsigned  long * audio_buf_ay_ey = ( unsigned  long *)&_binary_ay_ey_wav_start;
unsigned long size_ay_ey = ( unsigned long )&_binary_ay_ey_wav_size;
unsigned  long * audio_buf_ay_f = ( unsigned  long *)&_binary_ay_f_wav_start;
unsigned long size_ay_f = ( unsigned long )&_binary_ay_f_wav_size;
unsigned  long * audio_buf_ay_g = ( unsigned  long *)&_binary_ay_g_wav_start;
unsigned long size_ay_g = ( unsigned long )&_binary_ay_g_wav_size;
unsigned  long * audio_buf_ay_hh = ( unsigned  long *)&_binary_ay_hh_wav_start;
unsigned long size_ay_hh = ( unsigned long )&_binary_ay_hh_wav_size;
unsigned  long * audio_buf_ay_ih = ( unsigned  long *)&_binary_ay_ih_wav_start;
unsigned long size_ay_ih = ( unsigned long )&_binary_ay_ih_wav_size;
unsigned  long * audio_buf_ay_iy = ( unsigned  long *)&_binary_ay_iy_wav_start;
unsigned long size_ay_iy = ( unsigned long )&_binary_ay_iy_wav_size;
unsigned  long * audio_buf_ay_jh = ( unsigned  long *)&_binary_ay_jh_wav_start;
unsigned long size_ay_jh = ( unsigned long )&_binary_ay_jh_wav_size;
unsigned  long * audio_buf_ay_k = ( unsigned  long *)&_binary_ay_k_wav_start;
unsigned long size_ay_k = ( unsigned long )&_binary_ay_k_wav_size;
unsigned  long * audio_buf_ay_l = ( unsigned  long *)&_binary_ay_l_wav_start;
unsigned long size_ay_l = ( unsigned long )&_binary_ay_l_wav_size;
unsigned  long * audio_buf_ay_m = ( unsigned  long *)&_binary_ay_m_wav_start;
unsigned long size_ay_m = ( unsigned long )&_binary_ay_m_wav_size;
unsigned  long * audio_buf_ay_n = ( unsigned  long *)&_binary_ay_n_wav_start;
unsigned long size_ay_n = ( unsigned long )&_binary_ay_n_wav_size;
unsigned  long * audio_buf_ay_ng = ( unsigned  long *)&_binary_ay_ng_wav_start;
unsigned long size_ay_ng = ( unsigned long )&_binary_ay_ng_wav_size;
unsigned  long * audio_buf_ay_ow = ( unsigned  long *)&_binary_ay_ow_wav_start;
unsigned long size_ay_ow = ( unsigned long )&_binary_ay_ow_wav_size;
unsigned  long * audio_buf_ay_oy = ( unsigned  long *)&_binary_ay_oy_wav_start;
unsigned long size_ay_oy = ( unsigned long )&_binary_ay_oy_wav_size;
unsigned  long * audio_buf_ay_p = ( unsigned  long *)&_binary_ay_p_wav_start;
unsigned long size_ay_p = ( unsigned long )&_binary_ay_p_wav_size;
unsigned  long * audio_buf_ay_pau = ( unsigned  long *)&_binary_ay_pau_wav_start;
unsigned long size_ay_pau = ( unsigned long )&_binary_ay_pau_wav_size;
unsigned  long * audio_buf_ay_r = ( unsigned  long *)&_binary_ay_r_wav_start;
unsigned long size_ay_r = ( unsigned long )&_binary_ay_r_wav_size;
unsigned  long * audio_buf_ay_s = ( unsigned  long *)&_binary_ay_s_wav_start;
unsigned long size_ay_s = ( unsigned long )&_binary_ay_s_wav_size;
unsigned  long * audio_buf_ay_sh = ( unsigned  long *)&_binary_ay_sh_wav_start;
unsigned long size_ay_sh = ( unsigned long )&_binary_ay_sh_wav_size;
unsigned  long * audio_buf_ay_t = ( unsigned  long *)&_binary_ay_t_wav_start;
unsigned long size_ay_t = ( unsigned long )&_binary_ay_t_wav_size;
unsigned  long * audio_buf_ay_th = ( unsigned  long *)&_binary_ay_th_wav_start;
unsigned long size_ay_th = ( unsigned long )&_binary_ay_th_wav_size;
unsigned  long * audio_buf_ay_uh = ( unsigned  long *)&_binary_ay_uh_wav_start;
unsigned long size_ay_uh = ( unsigned long )&_binary_ay_uh_wav_size;
unsigned  long * audio_buf_ay_uw = ( unsigned  long *)&_binary_ay_uw_wav_start;
unsigned long size_ay_uw = ( unsigned long )&_binary_ay_uw_wav_size;
unsigned  long * audio_buf_ay_v = ( unsigned  long *)&_binary_ay_v_wav_start;
unsigned long size_ay_v = ( unsigned long )&_binary_ay_v_wav_size;
unsigned  long * audio_buf_ay_w = ( unsigned  long *)&_binary_ay_w_wav_start;
unsigned long size_ay_w = ( unsigned long )&_binary_ay_w_wav_size;
unsigned  long * audio_buf_ay_y = ( unsigned  long *)&_binary_ay_y_wav_start;
unsigned long size_ay_y = ( unsigned long )&_binary_ay_y_wav_size;
unsigned  long * audio_buf_ay_z = ( unsigned  long *)&_binary_ay_z_wav_start;
unsigned long size_ay_z = ( unsigned long )&_binary_ay_z_wav_size;
unsigned  long * audio_buf_ay_zh = ( unsigned  long *)&_binary_ay_zh_wav_start;
unsigned long size_ay_zh = ( unsigned long )&_binary_ay_zh_wav_size;
//ay diphones
file_write("/tmp/ay-aa.wav",audio_buf_ay_aa,size_ay_aa);
file_write("/tmp/ay-ae.wav",audio_buf_ay_ae,size_ay_ae);
file_write("/tmp/ay-ah.wav",audio_buf_ay_ah,size_ay_ah);
file_write("/tmp/ay-ao.wav",audio_buf_ay_ao,size_ay_ao);
file_write("/tmp/ay-aw.wav",audio_buf_ay_aw,size_ay_aw);
file_write("/tmp/ay-ax.wav",audio_buf_ay_ax,size_ay_ax);
file_write("/tmp/ay-ay.wav",audio_buf_ay_ay,size_ay_ay);
file_write("/tmp/ay-b.wav",audio_buf_ay_b,size_ay_b);
file_write("/tmp/ay-ch.wav",audio_buf_ay_ch,size_ay_ch);
file_write("/tmp/ay-d.wav",audio_buf_ay_d,size_ay_d);
file_write("/tmp/ay-dh.wav",audio_buf_ay_dh,size_ay_dh);
file_write("/tmp/ay-eh.wav",audio_buf_ay_eh,size_ay_eh);
file_write("/tmp/ay-er.wav",audio_buf_ay_er,size_ay_er);
file_write("/tmp/ay-ey.wav",audio_buf_ay_ey,size_ay_ey);
file_write("/tmp/ay-f.wav",audio_buf_ay_f,size_ay_f);
file_write("/tmp/ay-g.wav",audio_buf_ay_g,size_ay_g);
file_write("/tmp/ay-hh.wav",audio_buf_ay_hh,size_ay_hh);
file_write("/tmp/ay-ih.wav",audio_buf_ay_ih,size_ay_ih);
file_write("/tmp/ay-iy.wav",audio_buf_ay_iy,size_ay_iy);
file_write("/tmp/ay-jh.wav",audio_buf_ay_jh,size_ay_jh);
file_write("/tmp/ay-k.wav",audio_buf_ay_k,size_ay_k);
file_write("/tmp/ay-l.wav",audio_buf_ay_l,size_ay_l);
file_write("/tmp/ay-m.wav",audio_buf_ay_m,size_ay_m);
file_write("/tmp/ay-n.wav",audio_buf_ay_n,size_ay_n);
file_write("/tmp/ay-ng.wav",audio_buf_ay_ng,size_ay_ng);
file_write("/tmp/ay-ow.wav",audio_buf_ay_ow,size_ay_ow);
file_write("/tmp/ay-oy.wav",audio_buf_ay_oy,size_ay_oy);
file_write("/tmp/ay-p.wav",audio_buf_ay_p,size_ay_p);
file_write("/tmp/ay-pau.wav",audio_buf_ay_pau,size_ay_pau);
file_write("/tmp/ay-r.wav",audio_buf_ay_r,size_ay_r);
file_write("/tmp/ay-s.wav",audio_buf_ay_s,size_ay_s);
file_write("/tmp/ay-sh.wav",audio_buf_ay_sh,size_ay_sh);
file_write("/tmp/ay-t.wav",audio_buf_ay_t,size_ay_t);
file_write("/tmp/ay-th.wav",audio_buf_ay_th,size_ay_th);
file_write("/tmp/ay-uh.wav",audio_buf_ay_uh,size_ay_uh);
file_write("/tmp/ay-uw.wav",audio_buf_ay_uw,size_ay_uw);
file_write("/tmp/ay-v.wav",audio_buf_ay_v,size_ay_v);
file_write("/tmp/ay-w.wav",audio_buf_ay_w,size_ay_w);
file_write("/tmp/ay-y.wav",audio_buf_ay_y,size_ay_y);
file_write("/tmp/ay-z.wav",audio_buf_ay_z,size_ay_z);
file_write("/tmp/ay-zh.wav",audio_buf_ay_zh,size_ay_zh);

//b diphones  
unsigned  long * audio_buf_b_aa = ( unsigned  long *)&_binary_b_aa_wav_start; 
unsigned long size_b_aa = ( unsigned long )&_binary_b_aa_wav_size;
unsigned  long * audio_buf_b_ae = ( unsigned  long *)&_binary_b_ae_wav_start;
unsigned long size_b_ae = ( unsigned long )&_binary_b_ae_wav_size;
unsigned  long * audio_buf_b_ah = ( unsigned  long *)&_binary_b_ah_wav_start;
unsigned long size_b_ah = ( unsigned long )&_binary_b_ah_wav_size;
unsigned  long * audio_buf_b_ao = ( unsigned  long *)&_binary_b_ao_wav_start;
unsigned long size_b_ao = ( unsigned long )&_binary_b_ao_wav_size;
unsigned  long * audio_buf_b_aw = ( unsigned  long *)&_binary_b_aw_wav_start;
unsigned long size_b_aw = ( unsigned long )&_binary_b_aw_wav_size;
unsigned  long * audio_buf_b_ax = ( unsigned  long *)&_binary_b_ax_wav_start;
unsigned long size_b_ax = ( unsigned long )&_binary_b_ax_wav_size;
unsigned  long * audio_buf_b_ay = ( unsigned  long *)&_binary_b_ay_wav_start;
unsigned long size_b_ay = ( unsigned long )&_binary_b_ay_wav_size;
unsigned  long * audio_buf_b_b = ( unsigned  long *)&_binary_b_b_wav_start;
unsigned long size_b_b = ( unsigned long )&_binary_b_b_wav_size;
unsigned  long * audio_buf_b_ch = ( unsigned  long *)&_binary_b_ch_wav_start;
unsigned long size_b_ch = ( unsigned long )&_binary_b_ch_wav_size;
unsigned  long * audio_buf_b_d = ( unsigned  long *)&_binary_b_d_wav_start;
unsigned long size_b_d = ( unsigned long )&_binary_b_d_wav_size;
unsigned  long * audio_buf_b_dh = ( unsigned  long *)&_binary_b_dh_wav_start;
unsigned long size_b_dh = ( unsigned long )&_binary_b_dh_wav_size;
unsigned  long * audio_buf_b_eh = ( unsigned  long *)&_binary_b_eh_wav_start;
unsigned long size_b_eh = ( unsigned long )&_binary_b_eh_wav_size;
unsigned  long * audio_buf_b_er = ( unsigned  long *)&_binary_b_er_wav_start;
unsigned long size_b_er = ( unsigned long )&_binary_b_er_wav_size;
unsigned  long * audio_buf_b_ey = ( unsigned  long *)&_binary_b_ey_wav_start;
unsigned long size_b_ey = ( unsigned long )&_binary_b_ey_wav_size;
unsigned  long * audio_buf_b_f = ( unsigned  long *)&_binary_b_f_wav_start;
unsigned long size_b_f = ( unsigned long )&_binary_b_f_wav_size;
unsigned  long * audio_buf_b_g = ( unsigned  long *)&_binary_b_g_wav_start;
unsigned long size_b_g = ( unsigned long )&_binary_b_g_wav_size;
unsigned  long * audio_buf_b_hh = ( unsigned  long *)&_binary_b_hh_wav_start;
unsigned long size_b_hh = ( unsigned long )&_binary_b_hh_wav_size;
unsigned  long * audio_buf_b_ih = ( unsigned  long *)&_binary_b_ih_wav_start;
unsigned long size_b_ih = ( unsigned long )&_binary_b_ih_wav_size;
unsigned  long * audio_buf_b_iy = ( unsigned  long *)&_binary_b_iy_wav_start;
unsigned long size_b_iy = ( unsigned long )&_binary_b_iy_wav_size;
unsigned  long * audio_buf_b_jh = ( unsigned  long *)&_binary_b_jh_wav_start;
unsigned long size_b_jh = ( unsigned long )&_binary_b_jh_wav_size;
unsigned  long * audio_buf_b_k = ( unsigned  long *)&_binary_b_k_wav_start;
unsigned long size_b_k = ( unsigned long )&_binary_b_k_wav_size;
unsigned  long * audio_buf_b_l = ( unsigned  long *)&_binary_b_l_wav_start;
unsigned long size_b_l = ( unsigned long )&_binary_b_l_wav_size;
unsigned  long * audio_buf_b_m = ( unsigned  long *)&_binary_b_m_wav_start;
unsigned long size_b_m = ( unsigned long )&_binary_b_m_wav_size;
unsigned  long * audio_buf_b_n = ( unsigned  long *)&_binary_b_n_wav_start;
unsigned long size_b_n = ( unsigned long )&_binary_b_n_wav_size;
unsigned  long * audio_buf_b_ow = ( unsigned  long *)&_binary_b_ow_wav_start;
unsigned long size_b_ow = ( unsigned long )&_binary_b_ow_wav_size;
unsigned  long * audio_buf_b_oy = ( unsigned  long *)&_binary_b_oy_wav_start;
unsigned long size_b_oy = ( unsigned long )&_binary_b_oy_wav_size;
unsigned  long * audio_buf_b_p = ( unsigned  long *)&_binary_b_p_wav_start;
unsigned long size_b_p = ( unsigned long )&_binary_b_p_wav_size;
unsigned  long * audio_buf_b_pau = ( unsigned  long *)&_binary_b_pau_wav_start;
unsigned long size_b_pau = ( unsigned long )&_binary_b_pau_wav_size;
unsigned  long * audio_buf_b_r = ( unsigned  long *)&_binary_b_r_wav_start;
unsigned long size_b_r = ( unsigned long )&_binary_b_r_wav_size;
unsigned  long * audio_buf_b_s = ( unsigned  long *)&_binary_b_s_wav_start;
unsigned long size_b_s = ( unsigned long )&_binary_b_s_wav_size;
unsigned  long * audio_buf_b_sh = ( unsigned  long *)&_binary_b_sh_wav_start;
unsigned long size_b_sh = ( unsigned long )&_binary_b_sh_wav_size;
unsigned  long * audio_buf_b_t = ( unsigned  long *)&_binary_b_t_wav_start;
unsigned long size_b_t = ( unsigned long )&_binary_b_t_wav_size;
unsigned  long * audio_buf_b_th = ( unsigned  long *)&_binary_b_th_wav_start;
unsigned long size_b_th = ( unsigned long )&_binary_b_th_wav_size;
unsigned  long * audio_buf_b_uh = ( unsigned  long *)&_binary_b_uh_wav_start;
unsigned long size_b_uh = ( unsigned long )&_binary_b_uh_wav_size;
unsigned  long * audio_buf_b_uw = ( unsigned  long *)&_binary_b_uw_wav_start;
unsigned long size_b_uw = ( unsigned long )&_binary_b_uw_wav_size;
unsigned  long * audio_buf_b_v = ( unsigned  long *)&_binary_b_v_wav_start;
unsigned long size_b_v = ( unsigned long )&_binary_b_v_wav_size;
unsigned  long * audio_buf_b_w = ( unsigned  long *)&_binary_b_w_wav_start;
unsigned long size_b_w = ( unsigned long )&_binary_b_w_wav_size;
unsigned  long * audio_buf_b_y = ( unsigned  long *)&_binary_b_y_wav_start;
unsigned long size_b_y = ( unsigned long )&_binary_b_y_wav_size;
unsigned  long * audio_buf_b_z = ( unsigned  long *)&_binary_b_z_wav_start;
unsigned long size_b_z = ( unsigned long )&_binary_b_z_wav_size;
unsigned  long * audio_buf_b_zh = ( unsigned  long *)&_binary_b_zh_wav_start;
unsigned long size_b_zh = ( unsigned long )&_binary_b_zh_wav_size;
//b diphones
file_write("/tmp/b-aa.wav",audio_buf_b_aa,size_b_aa);
file_write("/tmp/b-ae.wav",audio_buf_b_ae,size_b_ae);
file_write("/tmp/b-ah.wav",audio_buf_b_ah,size_b_ah);
file_write("/tmp/b-ao.wav",audio_buf_b_ao,size_b_ao);
file_write("/tmp/b-aw.wav",audio_buf_b_aw,size_b_aw);
file_write("/tmp/b-ax.wav",audio_buf_b_ax,size_b_ax);
file_write("/tmp/b-ay.wav",audio_buf_b_ay,size_b_ay);
file_write("/tmp/b-b.wav",audio_buf_b_b,size_b_b);
file_write("/tmp/b-ch.wav",audio_buf_b_ch,size_b_ch);
file_write("/tmp/b-d.wav",audio_buf_b_d,size_b_d);
file_write("/tmp/b-dh.wav",audio_buf_b_dh,size_b_dh);
file_write("/tmp/b-eh.wav",audio_buf_b_eh,size_b_eh);
file_write("/tmp/b-er.wav",audio_buf_b_er,size_b_er);
file_write("/tmp/b-ey.wav",audio_buf_b_ey,size_b_ey);
file_write("/tmp/b-f.wav",audio_buf_b_f,size_b_f);
file_write("/tmp/b-g.wav",audio_buf_b_g,size_b_g);
file_write("/tmp/b-hh.wav",audio_buf_b_hh,size_b_hh);
file_write("/tmp/b-ih.wav",audio_buf_b_ih,size_b_ih);
file_write("/tmp/b-iy.wav",audio_buf_b_iy,size_b_iy);
file_write("/tmp/b-jh.wav",audio_buf_b_jh,size_b_jh);
file_write("/tmp/b-k.wav",audio_buf_b_k,size_b_k);
file_write("/tmp/b-l.wav",audio_buf_b_l,size_b_l);
file_write("/tmp/b-m.wav",audio_buf_b_m,size_b_m);
file_write("/tmp/b-n.wav",audio_buf_b_n,size_b_n);
file_write("/tmp/b-ow.wav",audio_buf_b_ow,size_b_ow);
file_write("/tmp/b-oy.wav",audio_buf_b_oy,size_b_oy);
file_write("/tmp/b-p.wav",audio_buf_b_p,size_b_p);
file_write("/tmp/b-pau.wav",audio_buf_b_pau,size_b_pau);
file_write("/tmp/b-r.wav",audio_buf_b_r,size_b_r);
file_write("/tmp/b-s.wav",audio_buf_b_s,size_b_s);
file_write("/tmp/b-sh.wav",audio_buf_b_sh,size_b_sh);
file_write("/tmp/b-t.wav",audio_buf_b_t,size_b_t);
file_write("/tmp/b-th.wav",audio_buf_b_th,size_b_th);
file_write("/tmp/b-uh.wav",audio_buf_b_uh,size_b_uh);
file_write("/tmp/b-uw.wav",audio_buf_b_uw,size_b_uw);
file_write("/tmp/b-v.wav",audio_buf_b_v,size_b_v);
file_write("/tmp/b-w.wav",audio_buf_b_w,size_b_w);
file_write("/tmp/b-y.wav",audio_buf_b_y,size_b_y);
file_write("/tmp/b-z.wav",audio_buf_b_z,size_b_z);
file_write("/tmp/b-zh.wav",audio_buf_b_zh,size_b_zh);

//ch diphones  
unsigned  long * audio_buf_ch_aa = ( unsigned  long *)&_binary_ch_aa_wav_start; 
unsigned long size_ch_aa = ( unsigned long )&_binary_ch_aa_wav_size;
unsigned  long * audio_buf_ch_ae = ( unsigned  long *)&_binary_ch_ae_wav_start;
unsigned long size_ch_ae = ( unsigned long )&_binary_ch_ae_wav_size;
unsigned  long * audio_buf_ch_ah = ( unsigned  long *)&_binary_ch_ah_wav_start;
unsigned long size_ch_ah = ( unsigned long )&_binary_ch_ah_wav_size;
unsigned  long * audio_buf_ch_ao = ( unsigned  long *)&_binary_ch_ao_wav_start;
unsigned long size_ch_ao = ( unsigned long )&_binary_ch_ao_wav_size;
unsigned  long * audio_buf_ch_aw = ( unsigned  long *)&_binary_ch_aw_wav_start;
unsigned long size_ch_aw = ( unsigned long )&_binary_ch_aw_wav_size;
unsigned  long * audio_buf_ch_ax = ( unsigned  long *)&_binary_ch_ax_wav_start;
unsigned long size_ch_ax = ( unsigned long )&_binary_ch_ax_wav_size;
unsigned  long * audio_buf_ch_ay = ( unsigned  long *)&_binary_ch_ay_wav_start;
unsigned long size_ch_ay = ( unsigned long )&_binary_ch_ay_wav_size;
unsigned  long * audio_buf_ch_b = ( unsigned  long *)&_binary_ch_b_wav_start;
unsigned long size_ch_b = ( unsigned long )&_binary_ch_b_wav_size;
unsigned  long * audio_buf_ch_ch = ( unsigned  long *)&_binary_ch_ch_wav_start;
unsigned long size_ch_ch = ( unsigned long )&_binary_ch_ch_wav_size;
unsigned  long * audio_buf_ch_d = ( unsigned  long *)&_binary_ch_d_wav_start;
unsigned long size_ch_d = ( unsigned long )&_binary_ch_d_wav_size;
unsigned  long * audio_buf_ch_dh = ( unsigned  long *)&_binary_ch_dh_wav_start;
unsigned long size_ch_dh = ( unsigned long )&_binary_ch_dh_wav_size;
unsigned  long * audio_buf_ch_eh = ( unsigned  long *)&_binary_ch_eh_wav_start;
unsigned long size_ch_eh = ( unsigned long )&_binary_ch_eh_wav_size;
unsigned  long * audio_buf_ch_er = ( unsigned  long *)&_binary_ch_er_wav_start;
unsigned long size_ch_er = ( unsigned long )&_binary_ch_er_wav_size;
unsigned  long * audio_buf_ch_ey = ( unsigned  long *)&_binary_ch_ey_wav_start;
unsigned long size_ch_ey = ( unsigned long )&_binary_ch_ey_wav_size;
unsigned  long * audio_buf_ch_f = ( unsigned  long *)&_binary_ch_f_wav_start;
unsigned long size_ch_f = ( unsigned long )&_binary_ch_f_wav_size;
unsigned  long * audio_buf_ch_g = ( unsigned  long *)&_binary_ch_g_wav_start;
unsigned long size_ch_g = ( unsigned long )&_binary_ch_g_wav_size;
unsigned  long * audio_buf_ch_hh = ( unsigned  long *)&_binary_ch_hh_wav_start;
unsigned long size_ch_hh = ( unsigned long )&_binary_ch_hh_wav_size;
unsigned  long * audio_buf_ch_ih = ( unsigned  long *)&_binary_ch_ih_wav_start;
unsigned long size_ch_ih = ( unsigned long )&_binary_ch_ih_wav_size;
unsigned  long * audio_buf_ch_iy = ( unsigned  long *)&_binary_ch_iy_wav_start;
unsigned long size_ch_iy = ( unsigned long )&_binary_ch_iy_wav_size;
unsigned  long * audio_buf_ch_jh = ( unsigned  long *)&_binary_ch_jh_wav_start;
unsigned long size_ch_jh = ( unsigned long )&_binary_ch_jh_wav_size;
unsigned  long * audio_buf_ch_k = ( unsigned  long *)&_binary_ch_k_wav_start;
unsigned long size_ch_k = ( unsigned long )&_binary_ch_k_wav_size;
unsigned  long * audio_buf_ch_l = ( unsigned  long *)&_binary_ch_l_wav_start;
unsigned long size_ch_l = ( unsigned long )&_binary_ch_l_wav_size;
unsigned  long * audio_buf_ch_m = ( unsigned  long *)&_binary_ch_m_wav_start;
unsigned long size_ch_m = ( unsigned long )&_binary_ch_m_wav_size;
unsigned  long * audio_buf_ch_n = ( unsigned  long *)&_binary_ch_n_wav_start;
unsigned long size_ch_n = ( unsigned long )&_binary_ch_n_wav_size;
unsigned  long * audio_buf_ch_ow = ( unsigned  long *)&_binary_ch_ow_wav_start;
unsigned long size_ch_ow = ( unsigned long )&_binary_ch_ow_wav_size;
unsigned  long * audio_buf_ch_oy = ( unsigned  long *)&_binary_ch_oy_wav_start;
unsigned long size_ch_oy = ( unsigned long )&_binary_ch_oy_wav_size;
unsigned  long * audio_buf_ch_p = ( unsigned  long *)&_binary_ch_p_wav_start;
unsigned long size_ch_p = ( unsigned long )&_binary_ch_p_wav_size;
unsigned  long * audio_buf_ch_pau = ( unsigned  long *)&_binary_ch_pau_wav_start;
unsigned long size_ch_pau = ( unsigned long )&_binary_ch_pau_wav_size;
unsigned  long * audio_buf_ch_r = ( unsigned  long *)&_binary_ch_r_wav_start;
unsigned long size_ch_r = ( unsigned long )&_binary_ch_r_wav_size;
unsigned  long * audio_buf_ch_s = ( unsigned  long *)&_binary_ch_s_wav_start;
unsigned long size_ch_s = ( unsigned long )&_binary_ch_s_wav_size;
unsigned  long * audio_buf_ch_sh = ( unsigned  long *)&_binary_ch_sh_wav_start;
unsigned long size_ch_sh = ( unsigned long )&_binary_ch_sh_wav_size;
unsigned  long * audio_buf_ch_t = ( unsigned  long *)&_binary_ch_t_wav_start;
unsigned long size_ch_t = ( unsigned long )&_binary_ch_t_wav_size;
unsigned  long * audio_buf_ch_th = ( unsigned  long *)&_binary_ch_th_wav_start;
unsigned long size_ch_th = ( unsigned long )&_binary_ch_th_wav_size;
unsigned  long * audio_buf_ch_uh = ( unsigned  long *)&_binary_ch_uh_wav_start;
unsigned long size_ch_uh = ( unsigned long )&_binary_ch_uh_wav_size;
unsigned  long * audio_buf_ch_uw = ( unsigned  long *)&_binary_ch_uw_wav_start;
unsigned long size_ch_uw = ( unsigned long )&_binary_ch_uw_wav_size;
unsigned  long * audio_buf_ch_v = ( unsigned  long *)&_binary_ch_v_wav_start;
unsigned long size_ch_v = ( unsigned long )&_binary_ch_v_wav_size;
unsigned  long * audio_buf_ch_w = ( unsigned  long *)&_binary_ch_w_wav_start;
unsigned long size_ch_w = ( unsigned long )&_binary_ch_w_wav_size;
unsigned  long * audio_buf_ch_y = ( unsigned  long *)&_binary_ch_y_wav_start;
unsigned long size_ch_y = ( unsigned long )&_binary_ch_y_wav_size;
unsigned  long * audio_buf_ch_z = ( unsigned  long *)&_binary_ch_z_wav_start;
unsigned long size_ch_z = ( unsigned long )&_binary_ch_z_wav_size;
unsigned  long * audio_buf_ch_zh = ( unsigned  long *)&_binary_ch_zh_wav_start;
unsigned long size_ch_zh = ( unsigned long )&_binary_ch_zh_wav_size;
//ch diphones
file_write("/tmp/ch-aa.wav",audio_buf_ch_aa,size_ch_aa);
file_write("/tmp/ch-ae.wav",audio_buf_ch_ae,size_ch_ae);
file_write("/tmp/ch-ah.wav",audio_buf_ch_ah,size_ch_ah);
file_write("/tmp/ch-ao.wav",audio_buf_ch_ao,size_ch_ao);
file_write("/tmp/ch-aw.wav",audio_buf_ch_aw,size_ch_aw);
file_write("/tmp/ch-ax.wav",audio_buf_ch_ax,size_ch_ax);
file_write("/tmp/ch-ay.wav",audio_buf_ch_ay,size_ch_ay);
file_write("/tmp/ch-b.wav",audio_buf_ch_b,size_ch_b);
file_write("/tmp/ch-ch.wav",audio_buf_ch_ch,size_ch_ch);
file_write("/tmp/ch-d.wav",audio_buf_ch_d,size_ch_d);
file_write("/tmp/ch-dh.wav",audio_buf_ch_dh,size_ch_dh);
file_write("/tmp/ch-eh.wav",audio_buf_ch_eh,size_ch_eh);
file_write("/tmp/ch-er.wav",audio_buf_ch_er,size_ch_er);
file_write("/tmp/ch-ey.wav",audio_buf_ch_ey,size_ch_ey);
file_write("/tmp/ch-f.wav",audio_buf_ch_f,size_ch_f);
file_write("/tmp/ch-g.wav",audio_buf_ch_g,size_ch_g);
file_write("/tmp/ch-hh.wav",audio_buf_ch_hh,size_ch_hh);
file_write("/tmp/ch-ih.wav",audio_buf_ch_ih,size_ch_ih);
file_write("/tmp/ch-iy.wav",audio_buf_ch_iy,size_ch_iy);
file_write("/tmp/ch-jh.wav",audio_buf_ch_jh,size_ch_jh);
file_write("/tmp/ch-k.wav",audio_buf_ch_k,size_ch_k);
file_write("/tmp/ch-l.wav",audio_buf_ch_l,size_ch_l);
file_write("/tmp/ch-m.wav",audio_buf_ch_m,size_ch_m);
file_write("/tmp/ch-n.wav",audio_buf_ch_n,size_ch_n);
file_write("/tmp/ch-ow.wav",audio_buf_ch_ow,size_ch_ow);
file_write("/tmp/ch-oy.wav",audio_buf_ch_oy,size_ch_oy);
file_write("/tmp/ch-p.wav",audio_buf_ch_p,size_ch_p);
file_write("/tmp/ch-pau.wav",audio_buf_ch_pau,size_ch_pau);
file_write("/tmp/ch-r.wav",audio_buf_ch_r,size_ch_r);
file_write("/tmp/ch-s.wav",audio_buf_ch_s,size_ch_s);
file_write("/tmp/ch-sh.wav",audio_buf_ch_sh,size_ch_sh);
file_write("/tmp/ch-t.wav",audio_buf_ch_t,size_ch_t);
file_write("/tmp/ch-th.wav",audio_buf_ch_th,size_ch_th);
file_write("/tmp/ch-uh.wav",audio_buf_ch_uh,size_ch_uh);
file_write("/tmp/ch-uw.wav",audio_buf_ch_uw,size_ch_uw);
file_write("/tmp/ch-v.wav",audio_buf_ch_v,size_ch_v);
file_write("/tmp/ch-w.wav",audio_buf_ch_w,size_ch_w);
file_write("/tmp/ch-y.wav",audio_buf_ch_y,size_ch_y);
file_write("/tmp/ch-z.wav",audio_buf_ch_z,size_ch_z);
file_write("/tmp/ch-zh.wav",audio_buf_ch_zh,size_ch_zh);

//d diphones  
unsigned  long * audio_buf_d_aa = ( unsigned  long *)&_binary_d_aa_wav_start; 
unsigned long size_d_aa = ( unsigned long )&_binary_d_aa_wav_size;
unsigned  long * audio_buf_d_ae = ( unsigned  long *)&_binary_d_ae_wav_start;
unsigned long size_d_ae = ( unsigned long )&_binary_d_ae_wav_size;
unsigned  long * audio_buf_d_ah = ( unsigned  long *)&_binary_d_ah_wav_start;
unsigned long size_d_ah = ( unsigned long )&_binary_d_ah_wav_size;
unsigned  long * audio_buf_d_ao = ( unsigned  long *)&_binary_d_ao_wav_start;
unsigned long size_d_ao = ( unsigned long )&_binary_d_ao_wav_size;
unsigned  long * audio_buf_d_aw = ( unsigned  long *)&_binary_d_aw_wav_start;
unsigned long size_d_aw = ( unsigned long )&_binary_d_aw_wav_size;
unsigned  long * audio_buf_d_ax = ( unsigned  long *)&_binary_d_ax_wav_start;
unsigned long size_d_ax = ( unsigned long )&_binary_d_ax_wav_size;
unsigned  long * audio_buf_d_ay = ( unsigned  long *)&_binary_d_ay_wav_start;
unsigned long size_d_ay = ( unsigned long )&_binary_d_ay_wav_size;
unsigned  long * audio_buf_d_b = ( unsigned  long *)&_binary_d_b_wav_start;
unsigned long size_d_b = ( unsigned long )&_binary_d_b_wav_size;
unsigned  long * audio_buf_d_ch = ( unsigned  long *)&_binary_d_ch_wav_start;
unsigned long size_d_ch = ( unsigned long )&_binary_d_ch_wav_size;
unsigned  long * audio_buf_d_d = ( unsigned  long *)&_binary_d_d_wav_start;
unsigned long size_d_d = ( unsigned long )&_binary_d_d_wav_size;
unsigned  long * audio_buf_d_dh = ( unsigned  long *)&_binary_d_dh_wav_start;
unsigned long size_d_dh = ( unsigned long )&_binary_d_dh_wav_size;
unsigned  long * audio_buf_d_eh = ( unsigned  long *)&_binary_d_eh_wav_start;
unsigned long size_d_eh = ( unsigned long )&_binary_d_eh_wav_size;
unsigned  long * audio_buf_d_er = ( unsigned  long *)&_binary_d_er_wav_start;
unsigned long size_d_er = ( unsigned long )&_binary_d_er_wav_size;
unsigned  long * audio_buf_d_ey = ( unsigned  long *)&_binary_d_ey_wav_start;
unsigned long size_d_ey = ( unsigned long )&_binary_d_ey_wav_size;
unsigned  long * audio_buf_d_f = ( unsigned  long *)&_binary_d_f_wav_start;
unsigned long size_d_f = ( unsigned long )&_binary_d_f_wav_size;
unsigned  long * audio_buf_d_g = ( unsigned  long *)&_binary_d_g_wav_start;
unsigned long size_d_g = ( unsigned long )&_binary_d_g_wav_size;
unsigned  long * audio_buf_d_hh = ( unsigned  long *)&_binary_d_hh_wav_start;
unsigned long size_d_hh = ( unsigned long )&_binary_d_hh_wav_size;
unsigned  long * audio_buf_d_ih = ( unsigned  long *)&_binary_d_ih_wav_start;
unsigned long size_d_ih = ( unsigned long )&_binary_d_ih_wav_size;
unsigned  long * audio_buf_d_iy = ( unsigned  long *)&_binary_d_iy_wav_start;
unsigned long size_d_iy = ( unsigned long )&_binary_d_iy_wav_size;
unsigned  long * audio_buf_d_jh = ( unsigned  long *)&_binary_d_jh_wav_start;
unsigned long size_d_jh = ( unsigned long )&_binary_d_jh_wav_size;
unsigned  long * audio_buf_d_k = ( unsigned  long *)&_binary_d_k_wav_start;
unsigned long size_d_k = ( unsigned long )&_binary_d_k_wav_size;
unsigned  long * audio_buf_d_l = ( unsigned  long *)&_binary_d_l_wav_start;
unsigned long size_d_l = ( unsigned long )&_binary_d_l_wav_size;
unsigned  long * audio_buf_d_m = ( unsigned  long *)&_binary_d_m_wav_start;
unsigned long size_d_m = ( unsigned long )&_binary_d_m_wav_size;
unsigned  long * audio_buf_d_n = ( unsigned  long *)&_binary_d_n_wav_start;
unsigned long size_d_n = ( unsigned long )&_binary_d_n_wav_size;
unsigned  long * audio_buf_d_ow = ( unsigned  long *)&_binary_d_ow_wav_start;
unsigned long size_d_ow = ( unsigned long )&_binary_d_ow_wav_size;
unsigned  long * audio_buf_d_oy = ( unsigned  long *)&_binary_d_oy_wav_start;
unsigned long size_d_oy = ( unsigned long )&_binary_d_oy_wav_size;
unsigned  long * audio_buf_d_p = ( unsigned  long *)&_binary_d_p_wav_start;
unsigned long size_d_p = ( unsigned long )&_binary_d_p_wav_size;
unsigned  long * audio_buf_d_pau = ( unsigned  long *)&_binary_d_pau_wav_start;
unsigned long size_d_pau = ( unsigned long )&_binary_d_pau_wav_size;
unsigned  long * audio_buf_d_r = ( unsigned  long *)&_binary_d_r_wav_start;
unsigned long size_d_r = ( unsigned long )&_binary_d_r_wav_size;
unsigned  long * audio_buf_d_s = ( unsigned  long *)&_binary_d_s_wav_start;
unsigned long size_d_s = ( unsigned long )&_binary_d_s_wav_size;
unsigned  long * audio_buf_d_sh = ( unsigned  long *)&_binary_d_sh_wav_start;
unsigned long size_d_sh = ( unsigned long )&_binary_d_sh_wav_size;
unsigned  long * audio_buf_d_t = ( unsigned  long *)&_binary_d_t_wav_start;
unsigned long size_d_t = ( unsigned long )&_binary_d_t_wav_size;
unsigned  long * audio_buf_d_th = ( unsigned  long *)&_binary_d_th_wav_start;
unsigned long size_d_th = ( unsigned long )&_binary_d_th_wav_size;
unsigned  long * audio_buf_d_uh = ( unsigned  long *)&_binary_d_uh_wav_start;
unsigned long size_d_uh = ( unsigned long )&_binary_d_uh_wav_size;
unsigned  long * audio_buf_d_uw = ( unsigned  long *)&_binary_d_uw_wav_start;
unsigned long size_d_uw = ( unsigned long )&_binary_d_uw_wav_size;
unsigned  long * audio_buf_d_v = ( unsigned  long *)&_binary_d_v_wav_start;
unsigned long size_d_v = ( unsigned long )&_binary_d_v_wav_size;
unsigned  long * audio_buf_d_w = ( unsigned  long *)&_binary_d_w_wav_start;
unsigned long size_d_w = ( unsigned long )&_binary_d_w_wav_size;
unsigned  long * audio_buf_d_y = ( unsigned  long *)&_binary_d_y_wav_start;
unsigned long size_d_y = ( unsigned long )&_binary_d_y_wav_size;
unsigned  long * audio_buf_d_z = ( unsigned  long *)&_binary_d_z_wav_start;
unsigned long size_d_z = ( unsigned long )&_binary_d_z_wav_size;
unsigned  long * audio_buf_d_zh = ( unsigned  long *)&_binary_d_zh_wav_start;
unsigned long size_d_zh = ( unsigned long )&_binary_d_zh_wav_size;
//d diphones
file_write("/tmp/d-aa.wav",audio_buf_d_aa,size_d_aa);
file_write("/tmp/d-ae.wav",audio_buf_d_ae,size_d_ae);
file_write("/tmp/d-ah.wav",audio_buf_d_ah,size_d_ah);
file_write("/tmp/d-ao.wav",audio_buf_d_ao,size_d_ao);
file_write("/tmp/d-aw.wav",audio_buf_d_aw,size_d_aw);
file_write("/tmp/d-ax.wav",audio_buf_d_ax,size_d_ax);
file_write("/tmp/d-ay.wav",audio_buf_d_ay,size_d_ay);
file_write("/tmp/d-b.wav",audio_buf_d_b,size_d_b);
file_write("/tmp/d-ch.wav",audio_buf_d_ch,size_d_ch);
file_write("/tmp/d-d.wav",audio_buf_d_d,size_d_d);
file_write("/tmp/d-dh.wav",audio_buf_d_dh,size_d_dh);
file_write("/tmp/d-eh.wav",audio_buf_d_eh,size_d_eh);
file_write("/tmp/d-er.wav",audio_buf_d_er,size_d_er);
file_write("/tmp/d-ey.wav",audio_buf_d_ey,size_d_ey);
file_write("/tmp/d-f.wav",audio_buf_d_f,size_d_f);
file_write("/tmp/d-g.wav",audio_buf_d_g,size_d_g);
file_write("/tmp/d-hh.wav",audio_buf_d_hh,size_d_hh);
file_write("/tmp/d-ih.wav",audio_buf_d_ih,size_d_ih);
file_write("/tmp/d-iy.wav",audio_buf_d_iy,size_d_iy);
file_write("/tmp/d-jh.wav",audio_buf_d_jh,size_d_jh);
file_write("/tmp/d-k.wav",audio_buf_d_k,size_d_k);
file_write("/tmp/d-l.wav",audio_buf_d_l,size_d_l);
file_write("/tmp/d-m.wav",audio_buf_d_m,size_d_m);
file_write("/tmp/d-n.wav",audio_buf_d_n,size_d_n);
file_write("/tmp/d-ow.wav",audio_buf_d_ow,size_d_ow);
file_write("/tmp/d-oy.wav",audio_buf_d_oy,size_d_oy);
file_write("/tmp/d-p.wav",audio_buf_d_p,size_d_p);
file_write("/tmp/d-pau.wav",audio_buf_d_pau,size_d_pau);
file_write("/tmp/d-r.wav",audio_buf_d_r,size_d_r);
file_write("/tmp/d-s.wav",audio_buf_d_s,size_d_s);
file_write("/tmp/d-sh.wav",audio_buf_d_sh,size_d_sh);
file_write("/tmp/d-t.wav",audio_buf_d_t,size_d_t);
file_write("/tmp/d-th.wav",audio_buf_d_th,size_d_th);
file_write("/tmp/d-uh.wav",audio_buf_d_uh,size_d_uh);
file_write("/tmp/d-uw.wav",audio_buf_d_uw,size_d_uw);
file_write("/tmp/d-v.wav",audio_buf_d_v,size_d_v);
file_write("/tmp/d-w.wav",audio_buf_d_w,size_d_w);
file_write("/tmp/d-y.wav",audio_buf_d_y,size_d_y);
file_write("/tmp/d-z.wav",audio_buf_d_z,size_d_z);
file_write("/tmp/d-zh.wav",audio_buf_d_zh,size_d_zh);

//dh diphones  
unsigned  long * audio_buf_dh_aa = ( unsigned  long *)&_binary_dh_aa_wav_start; 
unsigned long size_dh_aa = ( unsigned long )&_binary_dh_aa_wav_size;
unsigned  long * audio_buf_dh_ae = ( unsigned  long *)&_binary_dh_ae_wav_start;
unsigned long size_dh_ae = ( unsigned long )&_binary_dh_ae_wav_size;
unsigned  long * audio_buf_dh_ah = ( unsigned  long *)&_binary_dh_ah_wav_start;
unsigned long size_dh_ah = ( unsigned long )&_binary_dh_ah_wav_size;
unsigned  long * audio_buf_dh_ao = ( unsigned  long *)&_binary_dh_ao_wav_start;
unsigned long size_dh_ao = ( unsigned long )&_binary_dh_ao_wav_size;
unsigned  long * audio_buf_dh_aw = ( unsigned  long *)&_binary_dh_aw_wav_start;
unsigned long size_dh_aw = ( unsigned long )&_binary_dh_aw_wav_size;
unsigned  long * audio_buf_dh_ax = ( unsigned  long *)&_binary_dh_ax_wav_start;
unsigned long size_dh_ax = ( unsigned long )&_binary_dh_ax_wav_size;
unsigned  long * audio_buf_dh_ay = ( unsigned  long *)&_binary_dh_ay_wav_start;
unsigned long size_dh_ay = ( unsigned long )&_binary_dh_ay_wav_size;
unsigned  long * audio_buf_dh_b = ( unsigned  long *)&_binary_dh_b_wav_start;
unsigned long size_dh_b = ( unsigned long )&_binary_dh_b_wav_size;
unsigned  long * audio_buf_dh_ch = ( unsigned  long *)&_binary_dh_ch_wav_start;
unsigned long size_dh_ch = ( unsigned long )&_binary_dh_ch_wav_size;
unsigned  long * audio_buf_dh_d = ( unsigned  long *)&_binary_dh_d_wav_start;
unsigned long size_dh_d = ( unsigned long )&_binary_dh_d_wav_size;
unsigned  long * audio_buf_dh_dh = ( unsigned  long *)&_binary_dh_dh_wav_start;
unsigned long size_dh_dh = ( unsigned long )&_binary_dh_dh_wav_size;
unsigned  long * audio_buf_dh_eh = ( unsigned  long *)&_binary_dh_eh_wav_start;
unsigned long size_dh_eh = ( unsigned long )&_binary_dh_eh_wav_size;
unsigned  long * audio_buf_dh_er = ( unsigned  long *)&_binary_dh_er_wav_start;
unsigned long size_dh_er = ( unsigned long )&_binary_dh_er_wav_size;
unsigned  long * audio_buf_dh_ey = ( unsigned  long *)&_binary_dh_ey_wav_start;
unsigned long size_dh_ey = ( unsigned long )&_binary_dh_ey_wav_size;
unsigned  long * audio_buf_dh_f = ( unsigned  long *)&_binary_dh_f_wav_start;
unsigned long size_dh_f = ( unsigned long )&_binary_dh_f_wav_size;
unsigned  long * audio_buf_dh_g = ( unsigned  long *)&_binary_dh_g_wav_start;
unsigned long size_dh_g = ( unsigned long )&_binary_dh_g_wav_size;
unsigned  long * audio_buf_dh_hh = ( unsigned  long *)&_binary_dh_hh_wav_start;
unsigned long size_dh_hh = ( unsigned long )&_binary_dh_hh_wav_size;
unsigned  long * audio_buf_dh_ih = ( unsigned  long *)&_binary_dh_ih_wav_start;
unsigned long size_dh_ih = ( unsigned long )&_binary_dh_ih_wav_size;
unsigned  long * audio_buf_dh_iy = ( unsigned  long *)&_binary_dh_iy_wav_start;
unsigned long size_dh_iy = ( unsigned long )&_binary_dh_iy_wav_size;
unsigned  long * audio_buf_dh_jh = ( unsigned  long *)&_binary_dh_jh_wav_start;
unsigned long size_dh_jh = ( unsigned long )&_binary_dh_jh_wav_size;
unsigned  long * audio_buf_dh_k = ( unsigned  long *)&_binary_dh_k_wav_start;
unsigned long size_dh_k = ( unsigned long )&_binary_dh_k_wav_size;
unsigned  long * audio_buf_dh_l = ( unsigned  long *)&_binary_dh_l_wav_start;
unsigned long size_dh_l = ( unsigned long )&_binary_dh_l_wav_size;
unsigned  long * audio_buf_dh_m = ( unsigned  long *)&_binary_dh_m_wav_start;
unsigned long size_dh_m = ( unsigned long )&_binary_dh_m_wav_size;
unsigned  long * audio_buf_dh_n = ( unsigned  long *)&_binary_dh_n_wav_start;
unsigned long size_dh_n = ( unsigned long )&_binary_dh_n_wav_size;
unsigned  long * audio_buf_dh_ow = ( unsigned  long *)&_binary_dh_ow_wav_start;
unsigned long size_dh_ow = ( unsigned long )&_binary_dh_ow_wav_size;
unsigned  long * audio_buf_dh_oy = ( unsigned  long *)&_binary_dh_oy_wav_start;
unsigned long size_dh_oy = ( unsigned long )&_binary_dh_oy_wav_size;
unsigned  long * audio_buf_dh_p = ( unsigned  long *)&_binary_dh_p_wav_start;
unsigned long size_dh_p = ( unsigned long )&_binary_dh_p_wav_size;
unsigned  long * audio_buf_dh_pau = ( unsigned  long *)&_binary_dh_pau_wav_start;
unsigned long size_dh_pau = ( unsigned long )&_binary_dh_pau_wav_size;
unsigned  long * audio_buf_dh_r = ( unsigned  long *)&_binary_dh_r_wav_start;
unsigned long size_dh_r = ( unsigned long )&_binary_dh_r_wav_size;
unsigned  long * audio_buf_dh_s = ( unsigned  long *)&_binary_dh_s_wav_start;
unsigned long size_dh_s = ( unsigned long )&_binary_dh_s_wav_size;
unsigned  long * audio_buf_dh_sh = ( unsigned  long *)&_binary_dh_sh_wav_start;
unsigned long size_dh_sh = ( unsigned long )&_binary_dh_sh_wav_size;
unsigned  long * audio_buf_dh_t = ( unsigned  long *)&_binary_dh_t_wav_start;
unsigned long size_dh_t = ( unsigned long )&_binary_dh_t_wav_size;
unsigned  long * audio_buf_dh_th = ( unsigned  long *)&_binary_dh_th_wav_start;
unsigned long size_dh_th = ( unsigned long )&_binary_dh_th_wav_size;
unsigned  long * audio_buf_dh_uh = ( unsigned  long *)&_binary_dh_uh_wav_start;
unsigned long size_dh_uh = ( unsigned long )&_binary_dh_uh_wav_size;
unsigned  long * audio_buf_dh_uw = ( unsigned  long *)&_binary_dh_uw_wav_start;
unsigned long size_dh_uw = ( unsigned long )&_binary_dh_uw_wav_size;
unsigned  long * audio_buf_dh_v = ( unsigned  long *)&_binary_dh_v_wav_start;
unsigned long size_dh_v = ( unsigned long )&_binary_dh_v_wav_size;
unsigned  long * audio_buf_dh_w = ( unsigned  long *)&_binary_dh_w_wav_start;
unsigned long size_dh_w = ( unsigned long )&_binary_dh_w_wav_size;
unsigned  long * audio_buf_dh_y = ( unsigned  long *)&_binary_dh_y_wav_start;
unsigned long size_dh_y = ( unsigned long )&_binary_dh_y_wav_size;
unsigned  long * audio_buf_dh_z = ( unsigned  long *)&_binary_dh_z_wav_start;
unsigned long size_dh_z = ( unsigned long )&_binary_dh_z_wav_size;
unsigned  long * audio_buf_dh_zh = ( unsigned  long *)&_binary_dh_zh_wav_start;
unsigned long size_dh_zh = ( unsigned long )&_binary_dh_zh_wav_size;
//dh diphones
file_write("/tmp/dh-aa.wav",audio_buf_dh_aa,size_dh_aa);
file_write("/tmp/dh-ae.wav",audio_buf_dh_ae,size_dh_ae);
file_write("/tmp/dh-ah.wav",audio_buf_dh_ah,size_dh_ah);
file_write("/tmp/dh-ao.wav",audio_buf_dh_ao,size_dh_ao);
file_write("/tmp/dh-aw.wav",audio_buf_dh_aw,size_dh_aw);
file_write("/tmp/dh-ax.wav",audio_buf_dh_ax,size_dh_ax);
file_write("/tmp/dh-ay.wav",audio_buf_dh_ay,size_dh_ay);
file_write("/tmp/dh-b.wav",audio_buf_dh_b,size_dh_b);
file_write("/tmp/dh-ch.wav",audio_buf_dh_ch,size_dh_ch);
file_write("/tmp/dh-d.wav",audio_buf_dh_d,size_dh_d);
file_write("/tmp/dh-dh.wav",audio_buf_dh_dh,size_dh_dh);
file_write("/tmp/dh-eh.wav",audio_buf_dh_eh,size_dh_eh);
file_write("/tmp/dh-er.wav",audio_buf_dh_er,size_dh_er);
file_write("/tmp/dh-ey.wav",audio_buf_dh_ey,size_dh_ey);
file_write("/tmp/dh-f.wav",audio_buf_dh_f,size_dh_f);
file_write("/tmp/dh-g.wav",audio_buf_dh_g,size_dh_g);
file_write("/tmp/dh-hh.wav",audio_buf_dh_hh,size_dh_hh);
file_write("/tmp/dh-ih.wav",audio_buf_dh_ih,size_dh_ih);
file_write("/tmp/dh-iy.wav",audio_buf_dh_iy,size_dh_iy);
file_write("/tmp/dh-jh.wav",audio_buf_dh_jh,size_dh_jh);
file_write("/tmp/dh-k.wav",audio_buf_dh_k,size_dh_k);
file_write("/tmp/dh-l.wav",audio_buf_dh_l,size_dh_l);
file_write("/tmp/dh-m.wav",audio_buf_dh_m,size_dh_m);
file_write("/tmp/dh-n.wav",audio_buf_dh_n,size_dh_n);
file_write("/tmp/dh-ow.wav",audio_buf_dh_ow,size_dh_ow);
file_write("/tmp/dh-oy.wav",audio_buf_dh_oy,size_dh_oy);
file_write("/tmp/dh-p.wav",audio_buf_dh_p,size_dh_p);
file_write("/tmp/dh-pau.wav",audio_buf_dh_pau,size_dh_pau);
file_write("/tmp/dh-r.wav",audio_buf_dh_r,size_dh_r);
file_write("/tmp/dh-s.wav",audio_buf_dh_s,size_dh_s);
file_write("/tmp/dh-sh.wav",audio_buf_dh_sh,size_dh_sh);
file_write("/tmp/dh-t.wav",audio_buf_dh_t,size_dh_t);
file_write("/tmp/dh-th.wav",audio_buf_dh_th,size_dh_th);
file_write("/tmp/dh-uh.wav",audio_buf_dh_uh,size_dh_uh);
file_write("/tmp/dh-uw.wav",audio_buf_dh_uw,size_dh_uw);
file_write("/tmp/dh-v.wav",audio_buf_dh_v,size_dh_v);
file_write("/tmp/dh-w.wav",audio_buf_dh_w,size_dh_w);
file_write("/tmp/dh-y.wav",audio_buf_dh_y,size_dh_y);
file_write("/tmp/dh-z.wav",audio_buf_dh_z,size_dh_z);
file_write("/tmp/dh-zh.wav",audio_buf_dh_zh,size_dh_zh);

//eh diphones  
unsigned  long * audio_buf_eh_aa = ( unsigned  long *)&_binary_eh_aa_wav_start; 
unsigned long size_eh_aa = ( unsigned long )&_binary_eh_aa_wav_size;
unsigned  long * audio_buf_eh_ae = ( unsigned  long *)&_binary_eh_ae_wav_start;
unsigned long size_eh_ae = ( unsigned long )&_binary_eh_ae_wav_size;
unsigned  long * audio_buf_eh_ah = ( unsigned  long *)&_binary_eh_ah_wav_start;
unsigned long size_eh_ah = ( unsigned long )&_binary_eh_ah_wav_size;
unsigned  long * audio_buf_eh_ao = ( unsigned  long *)&_binary_eh_ao_wav_start;
unsigned long size_eh_ao = ( unsigned long )&_binary_eh_ao_wav_size;
unsigned  long * audio_buf_eh_aw = ( unsigned  long *)&_binary_eh_aw_wav_start;
unsigned long size_eh_aw = ( unsigned long )&_binary_eh_aw_wav_size;
unsigned  long * audio_buf_eh_ax = ( unsigned  long *)&_binary_eh_ax_wav_start;
unsigned long size_eh_ax = ( unsigned long )&_binary_eh_ax_wav_size;
unsigned  long * audio_buf_eh_ay = ( unsigned  long *)&_binary_eh_ay_wav_start;
unsigned long size_eh_ay = ( unsigned long )&_binary_eh_ay_wav_size;
unsigned  long * audio_buf_eh_b = ( unsigned  long *)&_binary_eh_b_wav_start;
unsigned long size_eh_b = ( unsigned long )&_binary_eh_b_wav_size;
unsigned  long * audio_buf_eh_ch = ( unsigned  long *)&_binary_eh_ch_wav_start;
unsigned long size_eh_ch = ( unsigned long )&_binary_eh_ch_wav_size;
unsigned  long * audio_buf_eh_d = ( unsigned  long *)&_binary_eh_d_wav_start;
unsigned long size_eh_d = ( unsigned long )&_binary_eh_d_wav_size;
unsigned  long * audio_buf_eh_dh = ( unsigned  long *)&_binary_eh_dh_wav_start;
unsigned long size_eh_dh = ( unsigned long )&_binary_eh_dh_wav_size;
unsigned  long * audio_buf_eh_eh = ( unsigned  long *)&_binary_eh_eh_wav_start;
unsigned long size_eh_eh = ( unsigned long )&_binary_eh_eh_wav_size;
unsigned  long * audio_buf_eh_er = ( unsigned  long *)&_binary_eh_er_wav_start;
unsigned long size_eh_er = ( unsigned long )&_binary_eh_er_wav_size;
unsigned  long * audio_buf_eh_ey = ( unsigned  long *)&_binary_eh_ey_wav_start;
unsigned long size_eh_ey = ( unsigned long )&_binary_eh_ey_wav_size;
unsigned  long * audio_buf_eh_f = ( unsigned  long *)&_binary_eh_f_wav_start;
unsigned long size_eh_f = ( unsigned long )&_binary_eh_f_wav_size;
unsigned  long * audio_buf_eh_g = ( unsigned  long *)&_binary_eh_g_wav_start;
unsigned long size_eh_g = ( unsigned long )&_binary_eh_g_wav_size;
unsigned  long * audio_buf_eh_hh = ( unsigned  long *)&_binary_eh_hh_wav_start;
unsigned long size_eh_hh = ( unsigned long )&_binary_eh_hh_wav_size;
unsigned  long * audio_buf_eh_ih = ( unsigned  long *)&_binary_eh_ih_wav_start;
unsigned long size_eh_ih = ( unsigned long )&_binary_eh_ih_wav_size;
unsigned  long * audio_buf_eh_iy = ( unsigned  long *)&_binary_eh_iy_wav_start;
unsigned long size_eh_iy = ( unsigned long )&_binary_eh_iy_wav_size;
unsigned  long * audio_buf_eh_jh = ( unsigned  long *)&_binary_eh_jh_wav_start;
unsigned long size_eh_jh = ( unsigned long )&_binary_eh_jh_wav_size;
unsigned  long * audio_buf_eh_k = ( unsigned  long *)&_binary_eh_k_wav_start;
unsigned long size_eh_k = ( unsigned long )&_binary_eh_k_wav_size;
unsigned  long * audio_buf_eh_l = ( unsigned  long *)&_binary_eh_l_wav_start;
unsigned long size_eh_l = ( unsigned long )&_binary_eh_l_wav_size;
unsigned  long * audio_buf_eh_m = ( unsigned  long *)&_binary_eh_m_wav_start;
unsigned long size_eh_m = ( unsigned long )&_binary_eh_m_wav_size;
unsigned  long * audio_buf_eh_n = ( unsigned  long *)&_binary_eh_n_wav_start;
unsigned long size_eh_n = ( unsigned long )&_binary_eh_n_wav_size;
unsigned  long * audio_buf_eh_ng = ( unsigned  long *)&_binary_eh_ng_wav_start;
unsigned long size_eh_ng = ( unsigned long )&_binary_eh_ng_wav_size;
unsigned  long * audio_buf_eh_ow = ( unsigned  long *)&_binary_eh_ow_wav_start;
unsigned long size_eh_ow = ( unsigned long )&_binary_eh_ow_wav_size;
unsigned  long * audio_buf_eh_oy = ( unsigned  long *)&_binary_eh_oy_wav_start;
unsigned long size_eh_oy = ( unsigned long )&_binary_eh_oy_wav_size;
unsigned  long * audio_buf_eh_p = ( unsigned  long *)&_binary_eh_p_wav_start;
unsigned long size_eh_p = ( unsigned long )&_binary_eh_p_wav_size;
unsigned  long * audio_buf_eh_pau = ( unsigned  long *)&_binary_eh_pau_wav_start;
unsigned long size_eh_pau = ( unsigned long )&_binary_eh_pau_wav_size;
unsigned  long * audio_buf_eh_r = ( unsigned  long *)&_binary_eh_r_wav_start;
unsigned long size_eh_r = ( unsigned long )&_binary_eh_r_wav_size;
unsigned  long * audio_buf_eh_s = ( unsigned  long *)&_binary_eh_s_wav_start;
unsigned long size_eh_s = ( unsigned long )&_binary_eh_s_wav_size;
unsigned  long * audio_buf_eh_sh = ( unsigned  long *)&_binary_eh_sh_wav_start;
unsigned long size_eh_sh = ( unsigned long )&_binary_eh_sh_wav_size;
unsigned  long * audio_buf_eh_t = ( unsigned  long *)&_binary_eh_t_wav_start;
unsigned long size_eh_t = ( unsigned long )&_binary_eh_t_wav_size;
unsigned  long * audio_buf_eh_th = ( unsigned  long *)&_binary_eh_th_wav_start;
unsigned long size_eh_th = ( unsigned long )&_binary_eh_th_wav_size;
unsigned  long * audio_buf_eh_uh = ( unsigned  long *)&_binary_eh_uh_wav_start;
unsigned long size_eh_uh = ( unsigned long )&_binary_eh_uh_wav_size;
unsigned  long * audio_buf_eh_uw = ( unsigned  long *)&_binary_eh_uw_wav_start;
unsigned long size_eh_uw = ( unsigned long )&_binary_eh_uw_wav_size;
unsigned  long * audio_buf_eh_v = ( unsigned  long *)&_binary_eh_v_wav_start;
unsigned long size_eh_v = ( unsigned long )&_binary_eh_v_wav_size;
unsigned  long * audio_buf_eh_w = ( unsigned  long *)&_binary_eh_w_wav_start;
unsigned long size_eh_w = ( unsigned long )&_binary_eh_w_wav_size;
unsigned  long * audio_buf_eh_y = ( unsigned  long *)&_binary_eh_y_wav_start;
unsigned long size_eh_y = ( unsigned long )&_binary_eh_y_wav_size;
unsigned  long * audio_buf_eh_z = ( unsigned  long *)&_binary_eh_z_wav_start;
unsigned long size_eh_z = ( unsigned long )&_binary_eh_z_wav_size;
unsigned  long * audio_buf_eh_zh = ( unsigned  long *)&_binary_eh_zh_wav_start;
unsigned long size_eh_zh = ( unsigned long )&_binary_eh_zh_wav_size;
//eh diphones
file_write("/tmp/eh-aa.wav",audio_buf_eh_aa,size_eh_aa);
file_write("/tmp/eh-ae.wav",audio_buf_eh_ae,size_eh_ae);
file_write("/tmp/eh-ah.wav",audio_buf_eh_ah,size_eh_ah);
file_write("/tmp/eh-ao.wav",audio_buf_eh_ao,size_eh_ao);
file_write("/tmp/eh-aw.wav",audio_buf_eh_aw,size_eh_aw);
file_write("/tmp/eh-ax.wav",audio_buf_eh_ax,size_eh_ax);
file_write("/tmp/eh-ay.wav",audio_buf_eh_ay,size_eh_ay);
file_write("/tmp/eh-b.wav",audio_buf_eh_b,size_eh_b);
file_write("/tmp/eh-ch.wav",audio_buf_eh_ch,size_eh_ch);
file_write("/tmp/eh-d.wav",audio_buf_eh_d,size_eh_d);
file_write("/tmp/eh-dh.wav",audio_buf_eh_dh,size_eh_dh);
file_write("/tmp/eh-eh.wav",audio_buf_eh_eh,size_eh_eh);
file_write("/tmp/eh-er.wav",audio_buf_eh_er,size_eh_er);
file_write("/tmp/eh-ey.wav",audio_buf_eh_ey,size_eh_ey);
file_write("/tmp/eh-f.wav",audio_buf_eh_f,size_eh_f);
file_write("/tmp/eh-g.wav",audio_buf_eh_g,size_eh_g);
file_write("/tmp/eh-hh.wav",audio_buf_eh_hh,size_eh_hh);
file_write("/tmp/eh-ih.wav",audio_buf_eh_ih,size_eh_ih);
file_write("/tmp/eh-iy.wav",audio_buf_eh_iy,size_eh_iy);
file_write("/tmp/eh-jh.wav",audio_buf_eh_jh,size_eh_jh);
file_write("/tmp/eh-k.wav",audio_buf_eh_k,size_eh_k);
file_write("/tmp/eh-l.wav",audio_buf_eh_l,size_eh_l);
file_write("/tmp/eh-m.wav",audio_buf_eh_m,size_eh_m);
file_write("/tmp/eh-n.wav",audio_buf_eh_n,size_eh_n);
file_write("/tmp/eh-ng.wav",audio_buf_eh_ng,size_eh_ng);
file_write("/tmp/eh-ow.wav",audio_buf_eh_ow,size_eh_ow);
file_write("/tmp/eh-oy.wav",audio_buf_eh_oy,size_eh_oy);
file_write("/tmp/eh-p.wav",audio_buf_eh_p,size_eh_p);
file_write("/tmp/eh-pau.wav",audio_buf_eh_pau,size_eh_pau);
file_write("/tmp/eh-r.wav",audio_buf_eh_r,size_eh_r);
file_write("/tmp/eh-s.wav",audio_buf_eh_s,size_eh_s);
file_write("/tmp/eh-sh.wav",audio_buf_eh_sh,size_eh_sh);
file_write("/tmp/eh-t.wav",audio_buf_eh_t,size_eh_t);
file_write("/tmp/eh-th.wav",audio_buf_eh_th,size_eh_th);
file_write("/tmp/eh-uh.wav",audio_buf_eh_uh,size_eh_uh);
file_write("/tmp/eh-uw.wav",audio_buf_eh_uw,size_eh_uw);
file_write("/tmp/eh-v.wav",audio_buf_eh_v,size_eh_v);
file_write("/tmp/eh-w.wav",audio_buf_eh_w,size_eh_w);
file_write("/tmp/eh-y.wav",audio_buf_eh_y,size_eh_y);
file_write("/tmp/eh-z.wav",audio_buf_eh_z,size_eh_z);
file_write("/tmp/eh-zh.wav",audio_buf_eh_zh,size_eh_zh);

//er diphones  
unsigned  long * audio_buf_er_aa = ( unsigned  long *)&_binary_er_aa_wav_start; 
unsigned long size_er_aa = ( unsigned long )&_binary_er_aa_wav_size;
unsigned  long * audio_buf_er_ae = ( unsigned  long *)&_binary_er_ae_wav_start;
unsigned long size_er_ae = ( unsigned long )&_binary_er_ae_wav_size;
unsigned  long * audio_buf_er_ah = ( unsigned  long *)&_binary_er_ah_wav_start;
unsigned long size_er_ah = ( unsigned long )&_binary_er_ah_wav_size;
unsigned  long * audio_buf_er_ao = ( unsigned  long *)&_binary_er_ao_wav_start;
unsigned long size_er_ao = ( unsigned long )&_binary_er_ao_wav_size;
unsigned  long * audio_buf_er_aw = ( unsigned  long *)&_binary_er_aw_wav_start;
unsigned long size_er_aw = ( unsigned long )&_binary_er_aw_wav_size;
unsigned  long * audio_buf_er_ax = ( unsigned  long *)&_binary_er_ax_wav_start;
unsigned long size_er_ax = ( unsigned long )&_binary_er_ax_wav_size;
unsigned  long * audio_buf_er_ay = ( unsigned  long *)&_binary_er_ay_wav_start;
unsigned long size_er_ay = ( unsigned long )&_binary_er_ay_wav_size;
unsigned  long * audio_buf_er_b = ( unsigned  long *)&_binary_er_b_wav_start;
unsigned long size_er_b = ( unsigned long )&_binary_er_b_wav_size;
unsigned  long * audio_buf_er_ch = ( unsigned  long *)&_binary_er_ch_wav_start;
unsigned long size_er_ch = ( unsigned long )&_binary_er_ch_wav_size;
unsigned  long * audio_buf_er_d = ( unsigned  long *)&_binary_er_d_wav_start;
unsigned long size_er_d = ( unsigned long )&_binary_er_d_wav_size;
unsigned  long * audio_buf_er_dh = ( unsigned  long *)&_binary_er_dh_wav_start;
unsigned long size_er_dh = ( unsigned long )&_binary_er_dh_wav_size;
unsigned  long * audio_buf_er_eh = ( unsigned  long *)&_binary_er_eh_wav_start;
unsigned long size_er_eh = ( unsigned long )&_binary_er_eh_wav_size;
unsigned  long * audio_buf_er_er = ( unsigned  long *)&_binary_er_er_wav_start;
unsigned long size_er_er = ( unsigned long )&_binary_er_er_wav_size;
unsigned  long * audio_buf_er_ey = ( unsigned  long *)&_binary_er_ey_wav_start;
unsigned long size_er_ey = ( unsigned long )&_binary_er_ey_wav_size;
unsigned  long * audio_buf_er_f = ( unsigned  long *)&_binary_er_f_wav_start;
unsigned long size_er_f = ( unsigned long )&_binary_er_f_wav_size;
unsigned  long * audio_buf_er_g = ( unsigned  long *)&_binary_er_g_wav_start;
unsigned long size_er_g = ( unsigned long )&_binary_er_g_wav_size;
unsigned  long * audio_buf_er_hh = ( unsigned  long *)&_binary_er_hh_wav_start;
unsigned long size_er_hh = ( unsigned long )&_binary_er_hh_wav_size;
unsigned  long * audio_buf_er_ih = ( unsigned  long *)&_binary_er_ih_wav_start;
unsigned long size_er_ih = ( unsigned long )&_binary_er_ih_wav_size;
unsigned  long * audio_buf_er_iy = ( unsigned  long *)&_binary_er_iy_wav_start;
unsigned long size_er_iy = ( unsigned long )&_binary_er_iy_wav_size;
unsigned  long * audio_buf_er_jh = ( unsigned  long *)&_binary_er_jh_wav_start;
unsigned long size_er_jh = ( unsigned long )&_binary_er_jh_wav_size;
unsigned  long * audio_buf_er_k = ( unsigned  long *)&_binary_er_k_wav_start;
unsigned long size_er_k = ( unsigned long )&_binary_er_k_wav_size;
unsigned  long * audio_buf_er_l = ( unsigned  long *)&_binary_er_l_wav_start;
unsigned long size_er_l = ( unsigned long )&_binary_er_l_wav_size;
unsigned  long * audio_buf_er_m = ( unsigned  long *)&_binary_er_m_wav_start;
unsigned long size_er_m = ( unsigned long )&_binary_er_m_wav_size;
unsigned  long * audio_buf_er_n = ( unsigned  long *)&_binary_er_n_wav_start;
unsigned long size_er_n = ( unsigned long )&_binary_er_n_wav_size;
unsigned  long * audio_buf_er_ow = ( unsigned  long *)&_binary_er_ow_wav_start;
unsigned long size_er_ow = ( unsigned long )&_binary_er_ow_wav_size;
unsigned  long * audio_buf_er_oy = ( unsigned  long *)&_binary_er_oy_wav_start;
unsigned long size_er_oy = ( unsigned long )&_binary_er_oy_wav_size;
unsigned  long * audio_buf_er_p = ( unsigned  long *)&_binary_er_p_wav_start;
unsigned long size_er_p = ( unsigned long )&_binary_er_p_wav_size;
unsigned  long * audio_buf_er_pau = ( unsigned  long *)&_binary_er_pau_wav_start;
unsigned long size_er_pau = ( unsigned long )&_binary_er_pau_wav_size;
unsigned  long * audio_buf_er_r = ( unsigned  long *)&_binary_er_r_wav_start;
unsigned long size_er_r = ( unsigned long )&_binary_er_r_wav_size;
unsigned  long * audio_buf_er_s = ( unsigned  long *)&_binary_er_s_wav_start;
unsigned long size_er_s = ( unsigned long )&_binary_er_s_wav_size;
unsigned  long * audio_buf_er_sh = ( unsigned  long *)&_binary_er_sh_wav_start;
unsigned long size_er_sh = ( unsigned long )&_binary_er_sh_wav_size;
unsigned  long * audio_buf_er_t = ( unsigned  long *)&_binary_er_t_wav_start;
unsigned long size_er_t = ( unsigned long )&_binary_er_t_wav_size;
unsigned  long * audio_buf_er_th = ( unsigned  long *)&_binary_er_th_wav_start;
unsigned long size_er_th = ( unsigned long )&_binary_er_th_wav_size;
unsigned  long * audio_buf_er_uh = ( unsigned  long *)&_binary_er_uh_wav_start;
unsigned long size_er_uh = ( unsigned long )&_binary_er_uh_wav_size;
unsigned  long * audio_buf_er_uw = ( unsigned  long *)&_binary_er_uw_wav_start;
unsigned long size_er_uw = ( unsigned long )&_binary_er_uw_wav_size;
unsigned  long * audio_buf_er_v = ( unsigned  long *)&_binary_er_v_wav_start;
unsigned long size_er_v = ( unsigned long )&_binary_er_v_wav_size;
unsigned  long * audio_buf_er_w = ( unsigned  long *)&_binary_er_w_wav_start;
unsigned long size_er_w = ( unsigned long )&_binary_er_w_wav_size;
unsigned  long * audio_buf_er_y = ( unsigned  long *)&_binary_er_y_wav_start;
unsigned long size_er_y = ( unsigned long )&_binary_er_y_wav_size;
unsigned  long * audio_buf_er_z = ( unsigned  long *)&_binary_er_z_wav_start;
unsigned long size_er_z = ( unsigned long )&_binary_er_z_wav_size;
unsigned  long * audio_buf_er_zh = ( unsigned  long *)&_binary_er_zh_wav_start;
unsigned long size_er_zh = ( unsigned long )&_binary_er_zh_wav_size;
//er diphones
file_write("/tmp/er-aa.wav",audio_buf_er_aa,size_er_aa);
file_write("/tmp/er-ae.wav",audio_buf_er_ae,size_er_ae);
file_write("/tmp/er-ah.wav",audio_buf_er_ah,size_er_ah);
file_write("/tmp/er-ao.wav",audio_buf_er_ao,size_er_ao);
file_write("/tmp/er-aw.wav",audio_buf_er_aw,size_er_aw);
file_write("/tmp/er-ax.wav",audio_buf_er_ax,size_er_ax);
file_write("/tmp/er-ay.wav",audio_buf_er_ay,size_er_ay);
file_write("/tmp/er-b.wav",audio_buf_er_b,size_er_b);
file_write("/tmp/er-ch.wav",audio_buf_er_ch,size_er_ch);
file_write("/tmp/er-d.wav",audio_buf_er_d,size_er_d);
file_write("/tmp/er-dh.wav",audio_buf_er_dh,size_er_dh);
file_write("/tmp/er-eh.wav",audio_buf_er_eh,size_er_eh);
file_write("/tmp/er-er.wav",audio_buf_er_er,size_er_er);
file_write("/tmp/er-ey.wav",audio_buf_er_ey,size_er_ey);
file_write("/tmp/er-f.wav",audio_buf_er_f,size_er_f);
file_write("/tmp/er-g.wav",audio_buf_er_g,size_er_g);
file_write("/tmp/er-hh.wav",audio_buf_er_hh,size_er_hh);
file_write("/tmp/er-ih.wav",audio_buf_er_ih,size_er_ih);
file_write("/tmp/er-iy.wav",audio_buf_er_iy,size_er_iy);
file_write("/tmp/er-jh.wav",audio_buf_er_jh,size_er_jh);
file_write("/tmp/er-k.wav",audio_buf_er_k,size_er_k);
file_write("/tmp/er-l.wav",audio_buf_er_l,size_er_l);
file_write("/tmp/er-m.wav",audio_buf_er_m,size_er_m);
file_write("/tmp/er-n.wav",audio_buf_er_n,size_er_n);
file_write("/tmp/er-ow.wav",audio_buf_er_ow,size_er_ow);
file_write("/tmp/er-oy.wav",audio_buf_er_oy,size_er_oy);
file_write("/tmp/er-p.wav",audio_buf_er_p,size_er_p);
file_write("/tmp/er-pau.wav",audio_buf_er_pau,size_er_pau);
file_write("/tmp/er-r.wav",audio_buf_er_r,size_er_r);
file_write("/tmp/er-s.wav",audio_buf_er_s,size_er_s);
file_write("/tmp/er-sh.wav",audio_buf_er_sh,size_er_sh);
file_write("/tmp/er-t.wav",audio_buf_er_t,size_er_t);
file_write("/tmp/er-th.wav",audio_buf_er_th,size_er_th);
file_write("/tmp/er-uh.wav",audio_buf_er_uh,size_er_uh);
file_write("/tmp/er-uw.wav",audio_buf_er_uw,size_er_uw);
file_write("/tmp/er-v.wav",audio_buf_er_v,size_er_v);
file_write("/tmp/er-w.wav",audio_buf_er_w,size_er_w);
file_write("/tmp/er-y.wav",audio_buf_er_y,size_er_y);
file_write("/tmp/er-z.wav",audio_buf_er_z,size_er_z);
file_write("/tmp/er-zh.wav",audio_buf_er_zh,size_er_zh);

//ey diphones  
unsigned  long * audio_buf_ey_aa = ( unsigned  long *)&_binary_ey_aa_wav_start; 
unsigned long size_ey_aa = ( unsigned long )&_binary_ey_aa_wav_size;
unsigned  long * audio_buf_ey_ae = ( unsigned  long *)&_binary_ey_ae_wav_start;
unsigned long size_ey_ae = ( unsigned long )&_binary_ey_ae_wav_size;
unsigned  long * audio_buf_ey_ah = ( unsigned  long *)&_binary_ey_ah_wav_start;
unsigned long size_ey_ah = ( unsigned long )&_binary_ey_ah_wav_size;
unsigned  long * audio_buf_ey_ao = ( unsigned  long *)&_binary_ey_ao_wav_start;
unsigned long size_ey_ao = ( unsigned long )&_binary_ey_ao_wav_size;
unsigned  long * audio_buf_ey_aw = ( unsigned  long *)&_binary_ey_aw_wav_start;
unsigned long size_ey_aw = ( unsigned long )&_binary_ey_aw_wav_size;
unsigned  long * audio_buf_ey_ax = ( unsigned  long *)&_binary_ey_ax_wav_start;
unsigned long size_ey_ax = ( unsigned long )&_binary_ey_ax_wav_size;
unsigned  long * audio_buf_ey_ay = ( unsigned  long *)&_binary_ey_ay_wav_start;
unsigned long size_ey_ay = ( unsigned long )&_binary_ey_ay_wav_size;
unsigned  long * audio_buf_ey_b = ( unsigned  long *)&_binary_ey_b_wav_start;
unsigned long size_ey_b = ( unsigned long )&_binary_ey_b_wav_size;
unsigned  long * audio_buf_ey_ch = ( unsigned  long *)&_binary_ey_ch_wav_start;
unsigned long size_ey_ch = ( unsigned long )&_binary_ey_ch_wav_size;
unsigned  long * audio_buf_ey_d = ( unsigned  long *)&_binary_ey_d_wav_start;
unsigned long size_ey_d = ( unsigned long )&_binary_ey_d_wav_size;
unsigned  long * audio_buf_ey_dh = ( unsigned  long *)&_binary_ey_dh_wav_start;
unsigned long size_ey_dh = ( unsigned long )&_binary_ey_dh_wav_size;
unsigned  long * audio_buf_ey_eh = ( unsigned  long *)&_binary_ey_eh_wav_start;
unsigned long size_ey_eh = ( unsigned long )&_binary_ey_eh_wav_size;
unsigned  long * audio_buf_ey_er = ( unsigned  long *)&_binary_ey_er_wav_start;
unsigned long size_ey_er = ( unsigned long )&_binary_ey_er_wav_size;
unsigned  long * audio_buf_ey_ey = ( unsigned  long *)&_binary_ey_ey_wav_start;
unsigned long size_ey_ey = ( unsigned long )&_binary_ey_ey_wav_size;
unsigned  long * audio_buf_ey_f = ( unsigned  long *)&_binary_ey_f_wav_start;
unsigned long size_ey_f = ( unsigned long )&_binary_ey_f_wav_size;
unsigned  long * audio_buf_ey_g = ( unsigned  long *)&_binary_ey_g_wav_start;
unsigned long size_ey_g = ( unsigned long )&_binary_ey_g_wav_size;
unsigned  long * audio_buf_ey_hh = ( unsigned  long *)&_binary_ey_hh_wav_start;
unsigned long size_ey_hh = ( unsigned long )&_binary_ey_hh_wav_size;
unsigned  long * audio_buf_ey_ih = ( unsigned  long *)&_binary_ey_ih_wav_start;
unsigned long size_ey_ih = ( unsigned long )&_binary_ey_ih_wav_size;
unsigned  long * audio_buf_ey_iy = ( unsigned  long *)&_binary_ey_iy_wav_start;
unsigned long size_ey_iy = ( unsigned long )&_binary_ey_iy_wav_size;
unsigned  long * audio_buf_ey_jh = ( unsigned  long *)&_binary_ey_jh_wav_start;
unsigned long size_ey_jh = ( unsigned long )&_binary_ey_jh_wav_size;
unsigned  long * audio_buf_ey_k = ( unsigned  long *)&_binary_ey_k_wav_start;
unsigned long size_ey_k = ( unsigned long )&_binary_ey_k_wav_size;
unsigned  long * audio_buf_ey_l = ( unsigned  long *)&_binary_ey_l_wav_start;
unsigned long size_ey_l = ( unsigned long )&_binary_ey_l_wav_size;
unsigned  long * audio_buf_ey_m = ( unsigned  long *)&_binary_ey_m_wav_start;
unsigned long size_ey_m = ( unsigned long )&_binary_ey_m_wav_size;
unsigned  long * audio_buf_ey_n = ( unsigned  long *)&_binary_ey_n_wav_start;
unsigned long size_ey_n = ( unsigned long )&_binary_ey_n_wav_size;
unsigned  long * audio_buf_ey_ng = ( unsigned  long *)&_binary_ey_ng_wav_start;
unsigned long size_ey_ng = ( unsigned long )&_binary_ey_ng_wav_size;
unsigned  long * audio_buf_ey_ow = ( unsigned  long *)&_binary_ey_ow_wav_start;
unsigned long size_ey_ow = ( unsigned long )&_binary_ey_ow_wav_size;
unsigned  long * audio_buf_ey_oy = ( unsigned  long *)&_binary_ey_oy_wav_start;
unsigned long size_ey_oy = ( unsigned long )&_binary_ey_oy_wav_size;
unsigned  long * audio_buf_ey_p = ( unsigned  long *)&_binary_ey_p_wav_start;
unsigned long size_ey_p = ( unsigned long )&_binary_ey_p_wav_size;
unsigned  long * audio_buf_ey_pau = ( unsigned  long *)&_binary_ey_pau_wav_start;
unsigned long size_ey_pau = ( unsigned long )&_binary_ey_pau_wav_size;
unsigned  long * audio_buf_ey_r = ( unsigned  long *)&_binary_ey_r_wav_start;
unsigned long size_ey_r = ( unsigned long )&_binary_ey_r_wav_size;
unsigned  long * audio_buf_ey_s = ( unsigned  long *)&_binary_ey_s_wav_start;
unsigned long size_ey_s = ( unsigned long )&_binary_ey_s_wav_size;
unsigned  long * audio_buf_ey_sh = ( unsigned  long *)&_binary_ey_sh_wav_start;
unsigned long size_ey_sh = ( unsigned long )&_binary_ey_sh_wav_size;
unsigned  long * audio_buf_ey_t = ( unsigned  long *)&_binary_ey_t_wav_start;
unsigned long size_ey_t = ( unsigned long )&_binary_ey_t_wav_size;
unsigned  long * audio_buf_ey_th = ( unsigned  long *)&_binary_ey_th_wav_start;
unsigned long size_ey_th = ( unsigned long )&_binary_ey_th_wav_size;
unsigned  long * audio_buf_ey_uh = ( unsigned  long *)&_binary_ey_uh_wav_start;
unsigned long size_ey_uh = ( unsigned long )&_binary_ey_uh_wav_size;
unsigned  long * audio_buf_ey_uw = ( unsigned  long *)&_binary_ey_uw_wav_start;
unsigned long size_ey_uw = ( unsigned long )&_binary_ey_uw_wav_size;
unsigned  long * audio_buf_ey_v = ( unsigned  long *)&_binary_ey_v_wav_start;
unsigned long size_ey_v = ( unsigned long )&_binary_ey_v_wav_size;
unsigned  long * audio_buf_ey_w = ( unsigned  long *)&_binary_ey_w_wav_start;
unsigned long size_ey_w = ( unsigned long )&_binary_ey_w_wav_size;
unsigned  long * audio_buf_ey_y = ( unsigned  long *)&_binary_ey_y_wav_start;
unsigned long size_ey_y = ( unsigned long )&_binary_ey_y_wav_size;
unsigned  long * audio_buf_ey_z = ( unsigned  long *)&_binary_ey_z_wav_start;
unsigned long size_ey_z = ( unsigned long )&_binary_ey_z_wav_size;
unsigned  long * audio_buf_ey_zh = ( unsigned  long *)&_binary_ey_zh_wav_start;
unsigned long size_ey_zh = ( unsigned long )&_binary_ey_zh_wav_size;
//ey diphones
file_write("/tmp/ey-aa.wav",audio_buf_ey_aa,size_ey_aa);
file_write("/tmp/ey-ae.wav",audio_buf_ey_ae,size_ey_ae);
file_write("/tmp/ey-ah.wav",audio_buf_ey_ah,size_ey_ah);
file_write("/tmp/ey-ao.wav",audio_buf_ey_ao,size_ey_ao);
file_write("/tmp/ey-aw.wav",audio_buf_ey_aw,size_ey_aw);
file_write("/tmp/ey-ax.wav",audio_buf_ey_ax,size_ey_ax);
file_write("/tmp/ey-ay.wav",audio_buf_ey_ay,size_ey_ay);
file_write("/tmp/ey-b.wav",audio_buf_ey_b,size_ey_b);
file_write("/tmp/ey-ch.wav",audio_buf_ey_ch,size_ey_ch);
file_write("/tmp/ey-d.wav",audio_buf_ey_d,size_ey_d);
file_write("/tmp/ey-dh.wav",audio_buf_ey_dh,size_ey_dh);
file_write("/tmp/ey-eh.wav",audio_buf_ey_eh,size_ey_eh);
file_write("/tmp/ey-er.wav",audio_buf_ey_er,size_ey_er);
file_write("/tmp/ey-ey.wav",audio_buf_ey_ey,size_ey_ey);
file_write("/tmp/ey-f.wav",audio_buf_ey_f,size_ey_f);
file_write("/tmp/ey-g.wav",audio_buf_ey_g,size_ey_g);
file_write("/tmp/ey-hh.wav",audio_buf_ey_hh,size_ey_hh);
file_write("/tmp/ey-ih.wav",audio_buf_ey_ih,size_ey_ih);
file_write("/tmp/ey-iy.wav",audio_buf_ey_iy,size_ey_iy);
file_write("/tmp/ey-jh.wav",audio_buf_ey_jh,size_ey_jh);
file_write("/tmp/ey-k.wav",audio_buf_ey_k,size_ey_k);
file_write("/tmp/ey-l.wav",audio_buf_ey_l,size_ey_l);
file_write("/tmp/ey-m.wav",audio_buf_ey_m,size_ey_m);
file_write("/tmp/ey-n.wav",audio_buf_ey_n,size_ey_n);
file_write("/tmp/ey-ng.wav",audio_buf_ey_ng,size_ey_ng);
file_write("/tmp/ey-ow.wav",audio_buf_ey_ow,size_ey_ow);
file_write("/tmp/ey-oy.wav",audio_buf_ey_oy,size_ey_oy);
file_write("/tmp/ey-p.wav",audio_buf_ey_p,size_ey_p);
file_write("/tmp/ey-pau.wav",audio_buf_ey_pau,size_ey_pau);
file_write("/tmp/ey-r.wav",audio_buf_ey_r,size_ey_r);
file_write("/tmp/ey-s.wav",audio_buf_ey_s,size_ey_s);
file_write("/tmp/ey-sh.wav",audio_buf_ey_sh,size_ey_sh);
file_write("/tmp/ey-t.wav",audio_buf_ey_t,size_ey_t);
file_write("/tmp/ey-th.wav",audio_buf_ey_th,size_ey_th);
file_write("/tmp/ey-uh.wav",audio_buf_ey_uh,size_ey_uh);
file_write("/tmp/ey-uw.wav",audio_buf_ey_uw,size_ey_uw);
file_write("/tmp/ey-v.wav",audio_buf_ey_v,size_ey_v);
file_write("/tmp/ey-w.wav",audio_buf_ey_w,size_ey_w);
file_write("/tmp/ey-y.wav",audio_buf_ey_y,size_ey_y);
file_write("/tmp/ey-z.wav",audio_buf_ey_z,size_ey_z);
file_write("/tmp/ey-zh.wav",audio_buf_ey_zh,size_ey_zh);

//f diphones  
unsigned  long * audio_buf_f_aa = ( unsigned  long *)&_binary_f_aa_wav_start; 
unsigned long size_f_aa = ( unsigned long )&_binary_f_aa_wav_size;
unsigned  long * audio_buf_f_ae = ( unsigned  long *)&_binary_f_ae_wav_start;
unsigned long size_f_ae = ( unsigned long )&_binary_f_ae_wav_size;
unsigned  long * audio_buf_f_ah = ( unsigned  long *)&_binary_f_ah_wav_start;
unsigned long size_f_ah = ( unsigned long )&_binary_f_ah_wav_size;
unsigned  long * audio_buf_f_ao = ( unsigned  long *)&_binary_f_ao_wav_start;
unsigned long size_f_ao = ( unsigned long )&_binary_f_ao_wav_size;
unsigned  long * audio_buf_f_aw = ( unsigned  long *)&_binary_f_aw_wav_start;
unsigned long size_f_aw = ( unsigned long )&_binary_f_aw_wav_size;
unsigned  long * audio_buf_f_ax = ( unsigned  long *)&_binary_f_ax_wav_start;
unsigned long size_f_ax = ( unsigned long )&_binary_f_ax_wav_size;
unsigned  long * audio_buf_f_ay = ( unsigned  long *)&_binary_f_ay_wav_start;
unsigned long size_f_ay = ( unsigned long )&_binary_f_ay_wav_size;
unsigned  long * audio_buf_f_b = ( unsigned  long *)&_binary_f_b_wav_start;
unsigned long size_f_b = ( unsigned long )&_binary_f_b_wav_size;
unsigned  long * audio_buf_f_ch = ( unsigned  long *)&_binary_f_ch_wav_start;
unsigned long size_f_ch = ( unsigned long )&_binary_f_ch_wav_size;
unsigned  long * audio_buf_f_d = ( unsigned  long *)&_binary_f_d_wav_start;
unsigned long size_f_d = ( unsigned long )&_binary_f_d_wav_size;
unsigned  long * audio_buf_f_dh = ( unsigned  long *)&_binary_f_dh_wav_start;
unsigned long size_f_dh = ( unsigned long )&_binary_f_dh_wav_size;
unsigned  long * audio_buf_f_eh = ( unsigned  long *)&_binary_f_eh_wav_start;
unsigned long size_f_eh = ( unsigned long )&_binary_f_eh_wav_size;
unsigned  long * audio_buf_f_er = ( unsigned  long *)&_binary_f_er_wav_start;
unsigned long size_f_er = ( unsigned long )&_binary_f_er_wav_size;
unsigned  long * audio_buf_f_ey = ( unsigned  long *)&_binary_f_ey_wav_start;
unsigned long size_f_ey = ( unsigned long )&_binary_f_ey_wav_size;
unsigned  long * audio_buf_f_f = ( unsigned  long *)&_binary_f_f_wav_start;
unsigned long size_f_f = ( unsigned long )&_binary_f_f_wav_size;
unsigned  long * audio_buf_f_g = ( unsigned  long *)&_binary_f_g_wav_start;
unsigned long size_f_g = ( unsigned long )&_binary_f_g_wav_size;
unsigned  long * audio_buf_f_hh = ( unsigned  long *)&_binary_f_hh_wav_start;
unsigned long size_f_hh = ( unsigned long )&_binary_f_hh_wav_size;
unsigned  long * audio_buf_f_ih = ( unsigned  long *)&_binary_f_ih_wav_start;
unsigned long size_f_ih = ( unsigned long )&_binary_f_ih_wav_size;
unsigned  long * audio_buf_f_iy = ( unsigned  long *)&_binary_f_iy_wav_start;
unsigned long size_f_iy = ( unsigned long )&_binary_f_iy_wav_size;
unsigned  long * audio_buf_f_jh = ( unsigned  long *)&_binary_f_jh_wav_start;
unsigned long size_f_jh = ( unsigned long )&_binary_f_jh_wav_size;
unsigned  long * audio_buf_f_k = ( unsigned  long *)&_binary_f_k_wav_start;
unsigned long size_f_k = ( unsigned long )&_binary_f_k_wav_size;
unsigned  long * audio_buf_f_l = ( unsigned  long *)&_binary_f_l_wav_start;
unsigned long size_f_l = ( unsigned long )&_binary_f_l_wav_size;
unsigned  long * audio_buf_f_m = ( unsigned  long *)&_binary_f_m_wav_start;
unsigned long size_f_m = ( unsigned long )&_binary_f_m_wav_size;
unsigned  long * audio_buf_f_n = ( unsigned  long *)&_binary_f_n_wav_start;
unsigned long size_f_n = ( unsigned long )&_binary_f_n_wav_size;
unsigned  long * audio_buf_f_ow = ( unsigned  long *)&_binary_f_ow_wav_start;
unsigned long size_f_ow = ( unsigned long )&_binary_f_ow_wav_size;
unsigned  long * audio_buf_f_oy = ( unsigned  long *)&_binary_f_oy_wav_start;
unsigned long size_f_oy = ( unsigned long )&_binary_f_oy_wav_size;
unsigned  long * audio_buf_f_p = ( unsigned  long *)&_binary_f_p_wav_start;
unsigned long size_f_p = ( unsigned long )&_binary_f_p_wav_size;
unsigned  long * audio_buf_f_pau = ( unsigned  long *)&_binary_f_pau_wav_start;
unsigned long size_f_pau = ( unsigned long )&_binary_f_pau_wav_size;
unsigned  long * audio_buf_f_r = ( unsigned  long *)&_binary_f_r_wav_start;
unsigned long size_f_r = ( unsigned long )&_binary_f_r_wav_size;
unsigned  long * audio_buf_f_s = ( unsigned  long *)&_binary_f_s_wav_start;
unsigned long size_f_s = ( unsigned long )&_binary_f_s_wav_size;
unsigned  long * audio_buf_f_sh = ( unsigned  long *)&_binary_f_sh_wav_start;
unsigned long size_f_sh = ( unsigned long )&_binary_f_sh_wav_size;
unsigned  long * audio_buf_f_t = ( unsigned  long *)&_binary_f_t_wav_start;
unsigned long size_f_t = ( unsigned long )&_binary_f_t_wav_size;
unsigned  long * audio_buf_f_th = ( unsigned  long *)&_binary_f_th_wav_start;
unsigned long size_f_th = ( unsigned long )&_binary_f_th_wav_size;
unsigned  long * audio_buf_f_uh = ( unsigned  long *)&_binary_f_uh_wav_start;
unsigned long size_f_uh = ( unsigned long )&_binary_f_uh_wav_size;
unsigned  long * audio_buf_f_uw = ( unsigned  long *)&_binary_f_uw_wav_start;
unsigned long size_f_uw = ( unsigned long )&_binary_f_uw_wav_size;
unsigned  long * audio_buf_f_v = ( unsigned  long *)&_binary_f_v_wav_start;
unsigned long size_f_v = ( unsigned long )&_binary_f_v_wav_size;
unsigned  long * audio_buf_f_w = ( unsigned  long *)&_binary_f_w_wav_start;
unsigned long size_f_w = ( unsigned long )&_binary_f_w_wav_size;
unsigned  long * audio_buf_f_y = ( unsigned  long *)&_binary_f_y_wav_start;
unsigned long size_f_y = ( unsigned long )&_binary_f_y_wav_size;
unsigned  long * audio_buf_f_z = ( unsigned  long *)&_binary_f_z_wav_start;
unsigned long size_f_z = ( unsigned long )&_binary_f_z_wav_size;
unsigned  long * audio_buf_f_zh = ( unsigned  long *)&_binary_f_zh_wav_start;
unsigned long size_f_zh = ( unsigned long )&_binary_f_zh_wav_size;
//f diphones
file_write("/tmp/f-aa.wav",audio_buf_f_aa,size_f_aa);
file_write("/tmp/f-ae.wav",audio_buf_f_ae,size_f_ae);
file_write("/tmp/f-ah.wav",audio_buf_f_ah,size_f_ah);
file_write("/tmp/f-ao.wav",audio_buf_f_ao,size_f_ao);
file_write("/tmp/f-aw.wav",audio_buf_f_aw,size_f_aw);
file_write("/tmp/f-ax.wav",audio_buf_f_ax,size_f_ax);
file_write("/tmp/f-ay.wav",audio_buf_f_ay,size_f_ay);
file_write("/tmp/f-b.wav",audio_buf_f_b,size_f_b);
file_write("/tmp/f-ch.wav",audio_buf_f_ch,size_f_ch);
file_write("/tmp/f-d.wav",audio_buf_f_d,size_f_d);
file_write("/tmp/f-dh.wav",audio_buf_f_dh,size_f_dh);
file_write("/tmp/f-eh.wav",audio_buf_f_eh,size_f_eh);
file_write("/tmp/f-er.wav",audio_buf_f_er,size_f_er);
file_write("/tmp/f-ey.wav",audio_buf_f_ey,size_f_ey);
file_write("/tmp/f-f.wav",audio_buf_f_f,size_f_f);
file_write("/tmp/f-g.wav",audio_buf_f_g,size_f_g);
file_write("/tmp/f-hh.wav",audio_buf_f_hh,size_f_hh);
file_write("/tmp/f-ih.wav",audio_buf_f_ih,size_f_ih);
file_write("/tmp/f-iy.wav",audio_buf_f_iy,size_f_iy);
file_write("/tmp/f-jh.wav",audio_buf_f_jh,size_f_jh);
file_write("/tmp/f-k.wav",audio_buf_f_k,size_f_k);
file_write("/tmp/f-l.wav",audio_buf_f_l,size_f_l);
file_write("/tmp/f-m.wav",audio_buf_f_m,size_f_m);
file_write("/tmp/f-n.wav",audio_buf_f_n,size_f_n);
file_write("/tmp/f-ow.wav",audio_buf_f_ow,size_f_ow);
file_write("/tmp/f-oy.wav",audio_buf_f_oy,size_f_oy);
file_write("/tmp/f-p.wav",audio_buf_f_p,size_f_p);
file_write("/tmp/f-pau.wav",audio_buf_f_pau,size_f_pau);
file_write("/tmp/f-r.wav",audio_buf_f_r,size_f_r);
file_write("/tmp/f-s.wav",audio_buf_f_s,size_f_s);
file_write("/tmp/f-sh.wav",audio_buf_f_sh,size_f_sh);
file_write("/tmp/f-t.wav",audio_buf_f_t,size_f_t);
file_write("/tmp/f-th.wav",audio_buf_f_th,size_f_th);
file_write("/tmp/f-uh.wav",audio_buf_f_uh,size_f_uh);
file_write("/tmp/f-uw.wav",audio_buf_f_uw,size_f_uw);
file_write("/tmp/f-v.wav",audio_buf_f_v,size_f_v);
file_write("/tmp/f-w.wav",audio_buf_f_w,size_f_w);
file_write("/tmp/f-y.wav",audio_buf_f_y,size_f_y);
file_write("/tmp/f-z.wav",audio_buf_f_z,size_f_z);
file_write("/tmp/f-zh.wav",audio_buf_f_zh,size_f_zh);

//g diphones  
unsigned  long * audio_buf_g_aa = ( unsigned  long *)&_binary_g_aa_wav_start; 
unsigned long size_g_aa = ( unsigned long )&_binary_g_aa_wav_size;
unsigned  long * audio_buf_g_ae = ( unsigned  long *)&_binary_g_ae_wav_start;
unsigned long size_g_ae = ( unsigned long )&_binary_g_ae_wav_size;
unsigned  long * audio_buf_g_ah = ( unsigned  long *)&_binary_g_ah_wav_start;
unsigned long size_g_ah = ( unsigned long )&_binary_g_ah_wav_size;
unsigned  long * audio_buf_g_ao = ( unsigned  long *)&_binary_g_ao_wav_start;
unsigned long size_g_ao = ( unsigned long )&_binary_g_ao_wav_size;
unsigned  long * audio_buf_g_aw = ( unsigned  long *)&_binary_g_aw_wav_start;
unsigned long size_g_aw = ( unsigned long )&_binary_g_aw_wav_size;
unsigned  long * audio_buf_g_ax = ( unsigned  long *)&_binary_g_ax_wav_start;
unsigned long size_g_ax = ( unsigned long )&_binary_g_ax_wav_size;
unsigned  long * audio_buf_g_ay = ( unsigned  long *)&_binary_g_ay_wav_start;
unsigned long size_g_ay = ( unsigned long )&_binary_g_ay_wav_size;
unsigned  long * audio_buf_g_b = ( unsigned  long *)&_binary_g_b_wav_start;
unsigned long size_g_b = ( unsigned long )&_binary_g_b_wav_size;
unsigned  long * audio_buf_g_ch = ( unsigned  long *)&_binary_g_ch_wav_start;
unsigned long size_g_ch = ( unsigned long )&_binary_g_ch_wav_size;
unsigned  long * audio_buf_g_d = ( unsigned  long *)&_binary_g_d_wav_start;
unsigned long size_g_d = ( unsigned long )&_binary_g_d_wav_size;
unsigned  long * audio_buf_g_dh = ( unsigned  long *)&_binary_g_dh_wav_start;
unsigned long size_g_dh = ( unsigned long )&_binary_g_dh_wav_size;
unsigned  long * audio_buf_g_eh = ( unsigned  long *)&_binary_g_eh_wav_start;
unsigned long size_g_eh = ( unsigned long )&_binary_g_eh_wav_size;
unsigned  long * audio_buf_g_er = ( unsigned  long *)&_binary_g_er_wav_start;
unsigned long size_g_er = ( unsigned long )&_binary_g_er_wav_size;
unsigned  long * audio_buf_g_ey = ( unsigned  long *)&_binary_g_ey_wav_start;
unsigned long size_g_ey = ( unsigned long )&_binary_g_ey_wav_size;
unsigned  long * audio_buf_g_f = ( unsigned  long *)&_binary_g_f_wav_start;
unsigned long size_g_f = ( unsigned long )&_binary_g_f_wav_size;
unsigned  long * audio_buf_g_g = ( unsigned  long *)&_binary_g_g_wav_start;
unsigned long size_g_g = ( unsigned long )&_binary_g_g_wav_size;
unsigned  long * audio_buf_g_hh = ( unsigned  long *)&_binary_g_hh_wav_start;
unsigned long size_g_hh = ( unsigned long )&_binary_g_hh_wav_size;
unsigned  long * audio_buf_g_ih = ( unsigned  long *)&_binary_g_ih_wav_start;
unsigned long size_g_ih = ( unsigned long )&_binary_g_ih_wav_size;
unsigned  long * audio_buf_g_iy = ( unsigned  long *)&_binary_g_iy_wav_start;
unsigned long size_g_iy = ( unsigned long )&_binary_g_iy_wav_size;
unsigned  long * audio_buf_g_jh = ( unsigned  long *)&_binary_g_jh_wav_start;
unsigned long size_g_jh = ( unsigned long )&_binary_g_jh_wav_size;
unsigned  long * audio_buf_g_k = ( unsigned  long *)&_binary_g_k_wav_start;
unsigned long size_g_k = ( unsigned long )&_binary_g_k_wav_size;
unsigned  long * audio_buf_g_l = ( unsigned  long *)&_binary_g_l_wav_start;
unsigned long size_g_l = ( unsigned long )&_binary_g_l_wav_size;
unsigned  long * audio_buf_g_m = ( unsigned  long *)&_binary_g_m_wav_start;
unsigned long size_g_m = ( unsigned long )&_binary_g_m_wav_size;
unsigned  long * audio_buf_g_n = ( unsigned  long *)&_binary_g_n_wav_start;
unsigned long size_g_n = ( unsigned long )&_binary_g_n_wav_size;
unsigned  long * audio_buf_g_ow = ( unsigned  long *)&_binary_g_ow_wav_start;
unsigned long size_g_ow = ( unsigned long )&_binary_g_ow_wav_size;
unsigned  long * audio_buf_g_oy = ( unsigned  long *)&_binary_g_oy_wav_start;
unsigned long size_g_oy = ( unsigned long )&_binary_g_oy_wav_size;
unsigned  long * audio_buf_g_p = ( unsigned  long *)&_binary_g_p_wav_start;
unsigned long size_g_p = ( unsigned long )&_binary_g_p_wav_size;
unsigned  long * audio_buf_g_pau = ( unsigned  long *)&_binary_g_pau_wav_start;
unsigned long size_g_pau = ( unsigned long )&_binary_g_pau_wav_size;
unsigned  long * audio_buf_g_r = ( unsigned  long *)&_binary_g_r_wav_start;
unsigned long size_g_r = ( unsigned long )&_binary_g_r_wav_size;
unsigned  long * audio_buf_g_s = ( unsigned  long *)&_binary_g_s_wav_start;
unsigned long size_g_s = ( unsigned long )&_binary_g_s_wav_size;
unsigned  long * audio_buf_g_sh = ( unsigned  long *)&_binary_g_sh_wav_start;
unsigned long size_g_sh = ( unsigned long )&_binary_g_sh_wav_size;
unsigned  long * audio_buf_g_t = ( unsigned  long *)&_binary_g_t_wav_start;
unsigned long size_g_t = ( unsigned long )&_binary_g_t_wav_size;
unsigned  long * audio_buf_g_th = ( unsigned  long *)&_binary_g_th_wav_start;
unsigned long size_g_th = ( unsigned long )&_binary_g_th_wav_size;
unsigned  long * audio_buf_g_uh = ( unsigned  long *)&_binary_g_uh_wav_start;
unsigned long size_g_uh = ( unsigned long )&_binary_g_uh_wav_size;
unsigned  long * audio_buf_g_uw = ( unsigned  long *)&_binary_g_uw_wav_start;
unsigned long size_g_uw = ( unsigned long )&_binary_g_uw_wav_size;
unsigned  long * audio_buf_g_v = ( unsigned  long *)&_binary_g_v_wav_start;
unsigned long size_g_v = ( unsigned long )&_binary_g_v_wav_size;
unsigned  long * audio_buf_g_w = ( unsigned  long *)&_binary_g_w_wav_start;
unsigned long size_g_w = ( unsigned long )&_binary_g_w_wav_size;
unsigned  long * audio_buf_g_y = ( unsigned  long *)&_binary_g_y_wav_start;
unsigned long size_g_y = ( unsigned long )&_binary_g_y_wav_size;
unsigned  long * audio_buf_g_z = ( unsigned  long *)&_binary_g_z_wav_start;
unsigned long size_g_z = ( unsigned long )&_binary_g_z_wav_size;
unsigned  long * audio_buf_g_zh = ( unsigned  long *)&_binary_g_zh_wav_start;
unsigned long size_g_zh = ( unsigned long )&_binary_g_zh_wav_size;
//g diphones
file_write("/tmp/g-aa.wav",audio_buf_g_aa,size_g_aa);
file_write("/tmp/g-ae.wav",audio_buf_g_ae,size_g_ae);
file_write("/tmp/g-ah.wav",audio_buf_g_ah,size_g_ah);
file_write("/tmp/g-ao.wav",audio_buf_g_ao,size_g_ao);
file_write("/tmp/g-aw.wav",audio_buf_g_aw,size_g_aw);
file_write("/tmp/g-ax.wav",audio_buf_g_ax,size_g_ax);
file_write("/tmp/g-ay.wav",audio_buf_g_ay,size_g_ay);
file_write("/tmp/g-b.wav",audio_buf_g_b,size_g_b);
file_write("/tmp/g-ch.wav",audio_buf_g_ch,size_g_ch);
file_write("/tmp/g-d.wav",audio_buf_g_d,size_g_d);
file_write("/tmp/g-dh.wav",audio_buf_g_dh,size_g_dh);
file_write("/tmp/g-eh.wav",audio_buf_g_eh,size_g_eh);
file_write("/tmp/g-er.wav",audio_buf_g_er,size_g_er);
file_write("/tmp/g-ey.wav",audio_buf_g_ey,size_g_ey);
file_write("/tmp/g-f.wav",audio_buf_g_f,size_g_f);
file_write("/tmp/g-g.wav",audio_buf_g_g,size_g_g);
file_write("/tmp/g-hh.wav",audio_buf_g_hh,size_g_hh);
file_write("/tmp/g-ih.wav",audio_buf_g_ih,size_g_ih);
file_write("/tmp/g-iy.wav",audio_buf_g_iy,size_g_iy);
file_write("/tmp/g-jh.wav",audio_buf_g_jh,size_g_jh);
file_write("/tmp/g-k.wav",audio_buf_g_k,size_g_k);
file_write("/tmp/g-l.wav",audio_buf_g_l,size_g_l);
file_write("/tmp/g-m.wav",audio_buf_g_m,size_g_m);
file_write("/tmp/g-n.wav",audio_buf_g_n,size_g_n);
file_write("/tmp/g-ow.wav",audio_buf_g_ow,size_g_ow);
file_write("/tmp/g-oy.wav",audio_buf_g_oy,size_g_oy);
file_write("/tmp/g-p.wav",audio_buf_g_p,size_g_p);
file_write("/tmp/g-pau.wav",audio_buf_g_pau,size_g_pau);
file_write("/tmp/g-r.wav",audio_buf_g_r,size_g_r);
file_write("/tmp/g-s.wav",audio_buf_g_s,size_g_s);
file_write("/tmp/g-sh.wav",audio_buf_g_sh,size_g_sh);
file_write("/tmp/g-t.wav",audio_buf_g_t,size_g_t);
file_write("/tmp/g-th.wav",audio_buf_g_th,size_g_th);
file_write("/tmp/g-uh.wav",audio_buf_g_uh,size_g_uh);
file_write("/tmp/g-uw.wav",audio_buf_g_uw,size_g_uw);
file_write("/tmp/g-v.wav",audio_buf_g_v,size_g_v);
file_write("/tmp/g-w.wav",audio_buf_g_w,size_g_w);
file_write("/tmp/g-y.wav",audio_buf_g_y,size_g_y);
file_write("/tmp/g-z.wav",audio_buf_g_z,size_g_z);
file_write("/tmp/g-zh.wav",audio_buf_g_zh,size_g_zh);

//hh diphones  
unsigned  long * audio_buf_hh_aa = ( unsigned  long *)&_binary_hh_aa_wav_start; 
unsigned long size_hh_aa = ( unsigned long )&_binary_hh_aa_wav_size;
unsigned  long * audio_buf_hh_ae = ( unsigned  long *)&_binary_hh_ae_wav_start;
unsigned long size_hh_ae = ( unsigned long )&_binary_hh_ae_wav_size;
unsigned  long * audio_buf_hh_ah = ( unsigned  long *)&_binary_hh_ah_wav_start;
unsigned long size_hh_ah = ( unsigned long )&_binary_hh_ah_wav_size;
unsigned  long * audio_buf_hh_ao = ( unsigned  long *)&_binary_hh_ao_wav_start;
unsigned long size_hh_ao = ( unsigned long )&_binary_hh_ao_wav_size;
unsigned  long * audio_buf_hh_aw = ( unsigned  long *)&_binary_hh_aw_wav_start;
unsigned long size_hh_aw = ( unsigned long )&_binary_hh_aw_wav_size;
unsigned  long * audio_buf_hh_ax = ( unsigned  long *)&_binary_hh_ax_wav_start;
unsigned long size_hh_ax = ( unsigned long )&_binary_hh_ax_wav_size;
unsigned  long * audio_buf_hh_ay = ( unsigned  long *)&_binary_hh_ay_wav_start;
unsigned long size_hh_ay = ( unsigned long )&_binary_hh_ay_wav_size;
unsigned  long * audio_buf_hh_eh = ( unsigned  long *)&_binary_hh_eh_wav_start;
unsigned long size_hh_eh = ( unsigned long )&_binary_hh_eh_wav_size;
unsigned  long * audio_buf_hh_ih = ( unsigned  long *)&_binary_hh_ih_wav_start;
unsigned long size_hh_ih = ( unsigned long )&_binary_hh_ih_wav_size;
unsigned  long * audio_buf_hh_iy = ( unsigned  long *)&_binary_hh_iy_wav_start;
unsigned long size_hh_iy = ( unsigned long )&_binary_hh_iy_wav_size;
unsigned  long * audio_buf_hh_ow = ( unsigned  long *)&_binary_hh_ow_wav_start;
unsigned long size_hh_ow = ( unsigned long )&_binary_hh_ow_wav_size;
unsigned  long * audio_buf_hh_oy = ( unsigned  long *)&_binary_hh_oy_wav_start;
unsigned long size_hh_oy = ( unsigned long )&_binary_hh_oy_wav_size;
unsigned  long * audio_buf_hh_uh = ( unsigned  long *)&_binary_hh_uh_wav_start;
unsigned long size_hh_uh = ( unsigned long )&_binary_hh_uh_wav_size;
unsigned  long * audio_buf_hh_uw = ( unsigned  long *)&_binary_hh_uw_wav_start;
unsigned long size_hh_uw = ( unsigned long )&_binary_hh_uw_wav_size;
//hh diphones
file_write("/tmp/hh-aa.wav",audio_buf_hh_aa,size_hh_aa);
file_write("/tmp/hh-ae.wav",audio_buf_hh_ae,size_hh_ae);
file_write("/tmp/hh-ah.wav",audio_buf_hh_ah,size_hh_ah);
file_write("/tmp/hh-ao.wav",audio_buf_hh_ao,size_hh_ao);
file_write("/tmp/hh-aw.wav",audio_buf_hh_aw,size_hh_aw);
file_write("/tmp/hh-ax.wav",audio_buf_hh_ax,size_hh_ax);
file_write("/tmp/hh-ay.wav",audio_buf_hh_ay,size_hh_ay);
file_write("/tmp/hh-eh.wav",audio_buf_hh_eh,size_hh_eh);
file_write("/tmp/hh-ih.wav",audio_buf_hh_ih,size_hh_ih);
file_write("/tmp/hh-iy.wav",audio_buf_hh_iy,size_hh_iy);
file_write("/tmp/hh-ow.wav",audio_buf_hh_ow,size_hh_ow);
file_write("/tmp/hh-oy.wav",audio_buf_hh_oy,size_hh_oy);
file_write("/tmp/hh-uh.wav",audio_buf_hh_uh,size_hh_uh);
file_write("/tmp/hh-uw.wav",audio_buf_hh_uw,size_hh_uw);

//ih diphones  
unsigned  long * audio_buf_ih_aa = ( unsigned  long *)&_binary_ih_aa_wav_start; 
unsigned long size_ih_aa = ( unsigned long )&_binary_ih_aa_wav_size;
unsigned  long * audio_buf_ih_ae = ( unsigned  long *)&_binary_ih_ae_wav_start;
unsigned long size_ih_ae = ( unsigned long )&_binary_ih_ae_wav_size;
unsigned  long * audio_buf_ih_ah = ( unsigned  long *)&_binary_ih_ah_wav_start;
unsigned long size_ih_ah = ( unsigned long )&_binary_ih_ah_wav_size;
unsigned  long * audio_buf_ih_ao = ( unsigned  long *)&_binary_ih_ao_wav_start;
unsigned long size_ih_ao = ( unsigned long )&_binary_ih_ao_wav_size;
unsigned  long * audio_buf_ih_aw = ( unsigned  long *)&_binary_ih_aw_wav_start;
unsigned long size_ih_aw = ( unsigned long )&_binary_ih_aw_wav_size;
unsigned  long * audio_buf_ih_ax = ( unsigned  long *)&_binary_ih_ax_wav_start;
unsigned long size_ih_ax = ( unsigned long )&_binary_ih_ax_wav_size;
unsigned  long * audio_buf_ih_ay = ( unsigned  long *)&_binary_ih_ay_wav_start;
unsigned long size_ih_ay = ( unsigned long )&_binary_ih_ay_wav_size;
unsigned  long * audio_buf_ih_b = ( unsigned  long *)&_binary_ih_b_wav_start;
unsigned long size_ih_b = ( unsigned long )&_binary_ih_b_wav_size;
unsigned  long * audio_buf_ih_ch = ( unsigned  long *)&_binary_ih_ch_wav_start;
unsigned long size_ih_ch = ( unsigned long )&_binary_ih_ch_wav_size;
unsigned  long * audio_buf_ih_d = ( unsigned  long *)&_binary_ih_d_wav_start;
unsigned long size_ih_d = ( unsigned long )&_binary_ih_d_wav_size;
unsigned  long * audio_buf_ih_dh = ( unsigned  long *)&_binary_ih_dh_wav_start;
unsigned long size_ih_dh = ( unsigned long )&_binary_ih_dh_wav_size;
unsigned  long * audio_buf_ih_eh = ( unsigned  long *)&_binary_ih_eh_wav_start;
unsigned long size_ih_eh = ( unsigned long )&_binary_ih_eh_wav_size;
unsigned  long * audio_buf_ih_er = ( unsigned  long *)&_binary_ih_er_wav_start;
unsigned long size_ih_er = ( unsigned long )&_binary_ih_er_wav_size;
unsigned  long * audio_buf_ih_ey = ( unsigned  long *)&_binary_ih_ey_wav_start;
unsigned long size_ih_ey = ( unsigned long )&_binary_ih_ey_wav_size;
unsigned  long * audio_buf_ih_f = ( unsigned  long *)&_binary_ih_f_wav_start;
unsigned long size_ih_f = ( unsigned long )&_binary_ih_f_wav_size;
unsigned  long * audio_buf_ih_g = ( unsigned  long *)&_binary_ih_g_wav_start;
unsigned long size_ih_g = ( unsigned long )&_binary_ih_g_wav_size;
unsigned  long * audio_buf_ih_hh = ( unsigned  long *)&_binary_ih_hh_wav_start;
unsigned long size_ih_hh = ( unsigned long )&_binary_ih_hh_wav_size;
unsigned  long * audio_buf_ih_ih = ( unsigned  long *)&_binary_ih_ih_wav_start;
unsigned long size_ih_ih = ( unsigned long )&_binary_ih_ih_wav_size;
unsigned  long * audio_buf_ih_iy = ( unsigned  long *)&_binary_ih_iy_wav_start;
unsigned long size_ih_iy = ( unsigned long )&_binary_ih_iy_wav_size;
unsigned  long * audio_buf_ih_jh = ( unsigned  long *)&_binary_ih_jh_wav_start;
unsigned long size_ih_jh = ( unsigned long )&_binary_ih_jh_wav_size;
unsigned  long * audio_buf_ih_k = ( unsigned  long *)&_binary_ih_k_wav_start;
unsigned long size_ih_k = ( unsigned long )&_binary_ih_k_wav_size;
unsigned  long * audio_buf_ih_l = ( unsigned  long *)&_binary_ih_l_wav_start;
unsigned long size_ih_l = ( unsigned long )&_binary_ih_l_wav_size;
unsigned  long * audio_buf_ih_m = ( unsigned  long *)&_binary_ih_m_wav_start;
unsigned long size_ih_m = ( unsigned long )&_binary_ih_m_wav_size;
unsigned  long * audio_buf_ih_n = ( unsigned  long *)&_binary_ih_n_wav_start;
unsigned long size_ih_n = ( unsigned long )&_binary_ih_n_wav_size;
unsigned  long * audio_buf_ih_ng = ( unsigned  long *)&_binary_ih_ng_wav_start;
unsigned long size_ih_ng = ( unsigned long )&_binary_ih_ng_wav_size;
unsigned  long * audio_buf_ih_ow = ( unsigned  long *)&_binary_ih_ow_wav_start;
unsigned long size_ih_ow = ( unsigned long )&_binary_ih_ow_wav_size;
unsigned  long * audio_buf_ih_oy = ( unsigned  long *)&_binary_ih_oy_wav_start;
unsigned long size_ih_oy = ( unsigned long )&_binary_ih_oy_wav_size;
unsigned  long * audio_buf_ih_p = ( unsigned  long *)&_binary_ih_p_wav_start;
unsigned long size_ih_p = ( unsigned long )&_binary_ih_p_wav_size;
unsigned  long * audio_buf_ih_pau = ( unsigned  long *)&_binary_ih_pau_wav_start;
unsigned long size_ih_pau = ( unsigned long )&_binary_ih_pau_wav_size;
unsigned  long * audio_buf_ih_r = ( unsigned  long *)&_binary_ih_r_wav_start;
unsigned long size_ih_r = ( unsigned long )&_binary_ih_r_wav_size;
unsigned  long * audio_buf_ih_s = ( unsigned  long *)&_binary_ih_s_wav_start;
unsigned long size_ih_s = ( unsigned long )&_binary_ih_s_wav_size;
unsigned  long * audio_buf_ih_sh = ( unsigned  long *)&_binary_ih_sh_wav_start;
unsigned long size_ih_sh = ( unsigned long )&_binary_ih_sh_wav_size;
unsigned  long * audio_buf_ih_t = ( unsigned  long *)&_binary_ih_t_wav_start;
unsigned long size_ih_t = ( unsigned long )&_binary_ih_t_wav_size;
unsigned  long * audio_buf_ih_th = ( unsigned  long *)&_binary_ih_th_wav_start;
unsigned long size_ih_th = ( unsigned long )&_binary_ih_th_wav_size;
unsigned  long * audio_buf_ih_uh = ( unsigned  long *)&_binary_ih_uh_wav_start;
unsigned long size_ih_uh = ( unsigned long )&_binary_ih_uh_wav_size;
unsigned  long * audio_buf_ih_uw = ( unsigned  long *)&_binary_ih_uw_wav_start;
unsigned long size_ih_uw = ( unsigned long )&_binary_ih_uw_wav_size;
unsigned  long * audio_buf_ih_v = ( unsigned  long *)&_binary_ih_v_wav_start;
unsigned long size_ih_v = ( unsigned long )&_binary_ih_v_wav_size;
unsigned  long * audio_buf_ih_w = ( unsigned  long *)&_binary_ih_w_wav_start;
unsigned long size_ih_w = ( unsigned long )&_binary_ih_w_wav_size;
unsigned  long * audio_buf_ih_y = ( unsigned  long *)&_binary_ih_y_wav_start;
unsigned long size_ih_y = ( unsigned long )&_binary_ih_y_wav_size;
unsigned  long * audio_buf_ih_z = ( unsigned  long *)&_binary_ih_z_wav_start;
unsigned long size_ih_z = ( unsigned long )&_binary_ih_z_wav_size;
unsigned  long * audio_buf_ih_zh = ( unsigned  long *)&_binary_ih_zh_wav_start;
unsigned long size_ih_zh = ( unsigned long )&_binary_ih_zh_wav_size;
//ih diphones
file_write("/tmp/ih-aa.wav",audio_buf_ih_aa,size_ih_aa);
file_write("/tmp/ih-ae.wav",audio_buf_ih_ae,size_ih_ae);
file_write("/tmp/ih-ah.wav",audio_buf_ih_ah,size_ih_ah);
file_write("/tmp/ih-ao.wav",audio_buf_ih_ao,size_ih_ao);
file_write("/tmp/ih-aw.wav",audio_buf_ih_aw,size_ih_aw);
file_write("/tmp/ih-ax.wav",audio_buf_ih_ax,size_ih_ax);
file_write("/tmp/ih-ay.wav",audio_buf_ih_ay,size_ih_ay);
file_write("/tmp/ih-b.wav",audio_buf_ih_b,size_ih_b);
file_write("/tmp/ih-ch.wav",audio_buf_ih_ch,size_ih_ch);
file_write("/tmp/ih-d.wav",audio_buf_ih_d,size_ih_d);
file_write("/tmp/ih-dh.wav",audio_buf_ih_dh,size_ih_dh);
file_write("/tmp/ih-eh.wav",audio_buf_ih_eh,size_ih_eh);
file_write("/tmp/ih-er.wav",audio_buf_ih_er,size_ih_er);
file_write("/tmp/ih-ey.wav",audio_buf_ih_ey,size_ih_ey);
file_write("/tmp/ih-f.wav",audio_buf_ih_f,size_ih_f);
file_write("/tmp/ih-g.wav",audio_buf_ih_g,size_ih_g);
file_write("/tmp/ih-hh.wav",audio_buf_ih_hh,size_ih_hh);
file_write("/tmp/ih-ih.wav",audio_buf_ih_ih,size_ih_ih);
file_write("/tmp/ih-iy.wav",audio_buf_ih_iy,size_ih_iy);
file_write("/tmp/ih-jh.wav",audio_buf_ih_jh,size_ih_jh);
file_write("/tmp/ih-k.wav",audio_buf_ih_k,size_ih_k);
file_write("/tmp/ih-l.wav",audio_buf_ih_l,size_ih_l);
file_write("/tmp/ih-m.wav",audio_buf_ih_m,size_ih_m);
file_write("/tmp/ih-n.wav",audio_buf_ih_n,size_ih_n);
file_write("/tmp/ih-ng.wav",audio_buf_ih_ng,size_ih_ng);
file_write("/tmp/ih-ow.wav",audio_buf_ih_ow,size_ih_ow);
file_write("/tmp/ih-oy.wav",audio_buf_ih_oy,size_ih_oy);
file_write("/tmp/ih-p.wav",audio_buf_ih_p,size_ih_p);
file_write("/tmp/ih-pau.wav",audio_buf_ih_pau,size_ih_pau);
file_write("/tmp/ih-r.wav",audio_buf_ih_r,size_ih_r);
file_write("/tmp/ih-s.wav",audio_buf_ih_s,size_ih_s);
file_write("/tmp/ih-sh.wav",audio_buf_ih_sh,size_ih_sh);
file_write("/tmp/ih-t.wav",audio_buf_ih_t,size_ih_t);
file_write("/tmp/ih-th.wav",audio_buf_ih_th,size_ih_th);
file_write("/tmp/ih-uh.wav",audio_buf_ih_uh,size_ih_uh);
file_write("/tmp/ih-uw.wav",audio_buf_ih_uw,size_ih_uw);
file_write("/tmp/ih-v.wav",audio_buf_ih_v,size_ih_v);
file_write("/tmp/ih-w.wav",audio_buf_ih_w,size_ih_w);
file_write("/tmp/ih-y.wav",audio_buf_ih_y,size_ih_y);
file_write("/tmp/ih-z.wav",audio_buf_ih_z,size_ih_z);
file_write("/tmp/ih-zh.wav",audio_buf_ih_zh,size_ih_zh);

//iy diphones  
unsigned  long * audio_buf_iy_aa = ( unsigned  long *)&_binary_iy_aa_wav_start; 
unsigned long size_iy_aa = ( unsigned long )&_binary_iy_aa_wav_size;
unsigned  long * audio_buf_iy_ae = ( unsigned  long *)&_binary_iy_ae_wav_start;
unsigned long size_iy_ae = ( unsigned long )&_binary_iy_ae_wav_size;
unsigned  long * audio_buf_iy_ah = ( unsigned  long *)&_binary_iy_ah_wav_start;
unsigned long size_iy_ah = ( unsigned long )&_binary_iy_ah_wav_size;
unsigned  long * audio_buf_iy_ao = ( unsigned  long *)&_binary_iy_ao_wav_start;
unsigned long size_iy_ao = ( unsigned long )&_binary_iy_ao_wav_size;
unsigned  long * audio_buf_iy_aw = ( unsigned  long *)&_binary_iy_aw_wav_start;
unsigned long size_iy_aw = ( unsigned long )&_binary_iy_aw_wav_size;
unsigned  long * audio_buf_iy_ax = ( unsigned  long *)&_binary_iy_ax_wav_start;
unsigned long size_iy_ax = ( unsigned long )&_binary_iy_ax_wav_size;
unsigned  long * audio_buf_iy_ay = ( unsigned  long *)&_binary_iy_ay_wav_start;
unsigned long size_iy_ay = ( unsigned long )&_binary_iy_ay_wav_size;
unsigned  long * audio_buf_iy_b = ( unsigned  long *)&_binary_iy_b_wav_start;
unsigned long size_iy_b = ( unsigned long )&_binary_iy_b_wav_size;
unsigned  long * audio_buf_iy_ch = ( unsigned  long *)&_binary_iy_ch_wav_start;
unsigned long size_iy_ch = ( unsigned long )&_binary_iy_ch_wav_size;
unsigned  long * audio_buf_iy_d = ( unsigned  long *)&_binary_iy_d_wav_start;
unsigned long size_iy_d = ( unsigned long )&_binary_iy_d_wav_size;
unsigned  long * audio_buf_iy_dh = ( unsigned  long *)&_binary_iy_dh_wav_start;
unsigned long size_iy_dh = ( unsigned long )&_binary_iy_dh_wav_size;
unsigned  long * audio_buf_iy_eh = ( unsigned  long *)&_binary_iy_eh_wav_start;
unsigned long size_iy_eh = ( unsigned long )&_binary_iy_eh_wav_size;
unsigned  long * audio_buf_iy_er = ( unsigned  long *)&_binary_iy_er_wav_start;
unsigned long size_iy_er = ( unsigned long )&_binary_iy_er_wav_size;
unsigned  long * audio_buf_iy_ey = ( unsigned  long *)&_binary_iy_ey_wav_start;
unsigned long size_iy_ey = ( unsigned long )&_binary_iy_ey_wav_size;
unsigned  long * audio_buf_iy_f = ( unsigned  long *)&_binary_iy_f_wav_start;
unsigned long size_iy_f = ( unsigned long )&_binary_iy_f_wav_size;
unsigned  long * audio_buf_iy_g = ( unsigned  long *)&_binary_iy_g_wav_start;
unsigned long size_iy_g = ( unsigned long )&_binary_iy_g_wav_size;
unsigned  long * audio_buf_iy_hh = ( unsigned  long *)&_binary_iy_hh_wav_start;
unsigned long size_iy_hh = ( unsigned long )&_binary_iy_hh_wav_size;
unsigned  long * audio_buf_iy_ih = ( unsigned  long *)&_binary_iy_ih_wav_start;
unsigned long size_iy_ih = ( unsigned long )&_binary_iy_ih_wav_size;
unsigned  long * audio_buf_iy_iy = ( unsigned  long *)&_binary_iy_iy_wav_start;
unsigned long size_iy_iy = ( unsigned long )&_binary_iy_iy_wav_size;
unsigned  long * audio_buf_iy_jh = ( unsigned  long *)&_binary_iy_jh_wav_start;
unsigned long size_iy_jh = ( unsigned long )&_binary_iy_jh_wav_size;
unsigned  long * audio_buf_iy_k = ( unsigned  long *)&_binary_iy_k_wav_start;
unsigned long size_iy_k = ( unsigned long )&_binary_iy_k_wav_size;
unsigned  long * audio_buf_iy_l = ( unsigned  long *)&_binary_iy_l_wav_start;
unsigned long size_iy_l = ( unsigned long )&_binary_iy_l_wav_size;
unsigned  long * audio_buf_iy_m = ( unsigned  long *)&_binary_iy_m_wav_start;
unsigned long size_iy_m = ( unsigned long )&_binary_iy_m_wav_size;
unsigned  long * audio_buf_iy_n = ( unsigned  long *)&_binary_iy_n_wav_start;
unsigned long size_iy_n = ( unsigned long )&_binary_iy_n_wav_size;
unsigned  long * audio_buf_iy_ng = ( unsigned  long *)&_binary_iy_ng_wav_start;
unsigned long size_iy_ng = ( unsigned long )&_binary_iy_ng_wav_size;
unsigned  long * audio_buf_iy_ow = ( unsigned  long *)&_binary_iy_ow_wav_start;
unsigned long size_iy_ow = ( unsigned long )&_binary_iy_ow_wav_size;
unsigned  long * audio_buf_iy_oy = ( unsigned  long *)&_binary_iy_oy_wav_start;
unsigned long size_iy_oy = ( unsigned long )&_binary_iy_oy_wav_size;
unsigned  long * audio_buf_iy_p = ( unsigned  long *)&_binary_iy_p_wav_start;
unsigned long size_iy_p = ( unsigned long )&_binary_iy_p_wav_size;
unsigned  long * audio_buf_iy_pau = ( unsigned  long *)&_binary_iy_pau_wav_start;
unsigned long size_iy_pau = ( unsigned long )&_binary_iy_pau_wav_size;
unsigned  long * audio_buf_iy_r = ( unsigned  long *)&_binary_iy_r_wav_start;
unsigned long size_iy_r = ( unsigned long )&_binary_iy_r_wav_size;
unsigned  long * audio_buf_iy_s = ( unsigned  long *)&_binary_iy_s_wav_start;
unsigned long size_iy_s = ( unsigned long )&_binary_iy_s_wav_size;
unsigned  long * audio_buf_iy_sh = ( unsigned  long *)&_binary_iy_sh_wav_start;
unsigned long size_iy_sh = ( unsigned long )&_binary_iy_sh_wav_size;
unsigned  long * audio_buf_iy_t = ( unsigned  long *)&_binary_iy_t_wav_start;
unsigned long size_iy_t = ( unsigned long )&_binary_iy_t_wav_size;
unsigned  long * audio_buf_iy_th = ( unsigned  long *)&_binary_iy_th_wav_start;
unsigned long size_iy_th = ( unsigned long )&_binary_iy_th_wav_size;
unsigned  long * audio_buf_iy_uh = ( unsigned  long *)&_binary_iy_uh_wav_start;
unsigned long size_iy_uh = ( unsigned long )&_binary_iy_uh_wav_size;
unsigned  long * audio_buf_iy_uw = ( unsigned  long *)&_binary_iy_uw_wav_start;
unsigned long size_iy_uw = ( unsigned long )&_binary_iy_uw_wav_size;
unsigned  long * audio_buf_iy_v = ( unsigned  long *)&_binary_iy_v_wav_start;
unsigned long size_iy_v = ( unsigned long )&_binary_iy_v_wav_size;
unsigned  long * audio_buf_iy_w = ( unsigned  long *)&_binary_iy_w_wav_start;
unsigned long size_iy_w = ( unsigned long )&_binary_iy_w_wav_size;
unsigned  long * audio_buf_iy_y = ( unsigned  long *)&_binary_iy_y_wav_start;
unsigned long size_iy_y = ( unsigned long )&_binary_iy_y_wav_size;
unsigned  long * audio_buf_iy_z = ( unsigned  long *)&_binary_iy_z_wav_start;
unsigned long size_iy_z = ( unsigned long )&_binary_iy_z_wav_size;
unsigned  long * audio_buf_iy_zh = ( unsigned  long *)&_binary_iy_zh_wav_start;
unsigned long size_iy_zh = ( unsigned long )&_binary_iy_zh_wav_size;
//iy diphones
file_write("/tmp/iy-aa.wav",audio_buf_iy_aa,size_iy_aa);
file_write("/tmp/iy-ae.wav",audio_buf_iy_ae,size_iy_ae);
file_write("/tmp/iy-ah.wav",audio_buf_iy_ah,size_iy_ah);
file_write("/tmp/iy-ao.wav",audio_buf_iy_ao,size_iy_ao);
file_write("/tmp/iy-aw.wav",audio_buf_iy_aw,size_iy_aw);
file_write("/tmp/iy-ax.wav",audio_buf_iy_ax,size_iy_ax);
file_write("/tmp/iy-ay.wav",audio_buf_iy_ay,size_iy_ay);
file_write("/tmp/iy-b.wav",audio_buf_iy_b,size_iy_b);
file_write("/tmp/iy-ch.wav",audio_buf_iy_ch,size_iy_ch);
file_write("/tmp/iy-d.wav",audio_buf_iy_d,size_iy_d);
file_write("/tmp/iy-dh.wav",audio_buf_iy_dh,size_iy_dh);
file_write("/tmp/iy-eh.wav",audio_buf_iy_eh,size_iy_eh);
file_write("/tmp/iy-er.wav",audio_buf_iy_er,size_iy_er);
file_write("/tmp/iy-ey.wav",audio_buf_iy_ey,size_iy_ey);
file_write("/tmp/iy-f.wav",audio_buf_iy_f,size_iy_f);
file_write("/tmp/iy-g.wav",audio_buf_iy_g,size_iy_g);
file_write("/tmp/iy-hh.wav",audio_buf_iy_hh,size_iy_hh);
file_write("/tmp/iy-ih.wav",audio_buf_iy_ih,size_iy_ih);
file_write("/tmp/iy-iy.wav",audio_buf_iy_iy,size_iy_iy);
file_write("/tmp/iy-jh.wav",audio_buf_iy_jh,size_iy_jh);
file_write("/tmp/iy-k.wav",audio_buf_iy_k,size_iy_k);
file_write("/tmp/iy-l.wav",audio_buf_iy_l,size_iy_l);
file_write("/tmp/iy-m.wav",audio_buf_iy_m,size_iy_m);
file_write("/tmp/iy-n.wav",audio_buf_iy_n,size_iy_n);
file_write("/tmp/iy-ng.wav",audio_buf_iy_ng,size_iy_ng);
file_write("/tmp/iy-ow.wav",audio_buf_iy_ow,size_iy_ow);
file_write("/tmp/iy-oy.wav",audio_buf_iy_oy,size_iy_oy);
file_write("/tmp/iy-p.wav",audio_buf_iy_p,size_iy_p);
file_write("/tmp/iy-pau.wav",audio_buf_iy_pau,size_iy_pau);
file_write("/tmp/iy-r.wav",audio_buf_iy_r,size_iy_r);
file_write("/tmp/iy-s.wav",audio_buf_iy_s,size_iy_s);
file_write("/tmp/iy-sh.wav",audio_buf_iy_sh,size_iy_sh);
file_write("/tmp/iy-t.wav",audio_buf_iy_t,size_iy_t);
file_write("/tmp/iy-th.wav",audio_buf_iy_th,size_iy_th);
file_write("/tmp/iy-uh.wav",audio_buf_iy_uh,size_iy_uh);
file_write("/tmp/iy-uw.wav",audio_buf_iy_uw,size_iy_uw);
file_write("/tmp/iy-v.wav",audio_buf_iy_v,size_iy_v);
file_write("/tmp/iy-w.wav",audio_buf_iy_w,size_iy_w);
file_write("/tmp/iy-y.wav",audio_buf_iy_y,size_iy_y);
file_write("/tmp/iy-z.wav",audio_buf_iy_z,size_iy_z);
file_write("/tmp/iy-zh.wav",audio_buf_iy_zh,size_iy_zh);

//jh diphones  
unsigned  long * audio_buf_jh_aa = ( unsigned  long *)&_binary_jh_aa_wav_start; 
unsigned long size_jh_aa = ( unsigned long )&_binary_jh_aa_wav_size;
unsigned  long * audio_buf_jh_ae = ( unsigned  long *)&_binary_jh_ae_wav_start;
unsigned long size_jh_ae = ( unsigned long )&_binary_jh_ae_wav_size;
unsigned  long * audio_buf_jh_ah = ( unsigned  long *)&_binary_jh_ah_wav_start;
unsigned long size_jh_ah = ( unsigned long )&_binary_jh_ah_wav_size;
unsigned  long * audio_buf_jh_ao = ( unsigned  long *)&_binary_jh_ao_wav_start;
unsigned long size_jh_ao = ( unsigned long )&_binary_jh_ao_wav_size;
unsigned  long * audio_buf_jh_aw = ( unsigned  long *)&_binary_jh_aw_wav_start;
unsigned long size_jh_aw = ( unsigned long )&_binary_jh_aw_wav_size;
unsigned  long * audio_buf_jh_ax = ( unsigned  long *)&_binary_jh_ax_wav_start;
unsigned long size_jh_ax = ( unsigned long )&_binary_jh_ax_wav_size;
unsigned  long * audio_buf_jh_ay = ( unsigned  long *)&_binary_jh_ay_wav_start;
unsigned long size_jh_ay = ( unsigned long )&_binary_jh_ay_wav_size;
unsigned  long * audio_buf_jh_b = ( unsigned  long *)&_binary_jh_b_wav_start;
unsigned long size_jh_b = ( unsigned long )&_binary_jh_b_wav_size;
unsigned  long * audio_buf_jh_ch = ( unsigned  long *)&_binary_jh_ch_wav_start;
unsigned long size_jh_ch = ( unsigned long )&_binary_jh_ch_wav_size;
unsigned  long * audio_buf_jh_d = ( unsigned  long *)&_binary_jh_d_wav_start;
unsigned long size_jh_d = ( unsigned long )&_binary_jh_d_wav_size;
unsigned  long * audio_buf_jh_dh = ( unsigned  long *)&_binary_jh_dh_wav_start;
unsigned long size_jh_dh = ( unsigned long )&_binary_jh_dh_wav_size;
unsigned  long * audio_buf_jh_eh = ( unsigned  long *)&_binary_jh_eh_wav_start;
unsigned long size_jh_eh = ( unsigned long )&_binary_jh_eh_wav_size;
unsigned  long * audio_buf_jh_er = ( unsigned  long *)&_binary_jh_er_wav_start;
unsigned long size_jh_er = ( unsigned long )&_binary_jh_er_wav_size;
unsigned  long * audio_buf_jh_ey = ( unsigned  long *)&_binary_jh_ey_wav_start;
unsigned long size_jh_ey = ( unsigned long )&_binary_jh_ey_wav_size;
unsigned  long * audio_buf_jh_f = ( unsigned  long *)&_binary_jh_f_wav_start;
unsigned long size_jh_f = ( unsigned long )&_binary_jh_f_wav_size;
unsigned  long * audio_buf_jh_g = ( unsigned  long *)&_binary_jh_g_wav_start;
unsigned long size_jh_g = ( unsigned long )&_binary_jh_g_wav_size;
unsigned  long * audio_buf_jh_hh = ( unsigned  long *)&_binary_jh_hh_wav_start;
unsigned long size_jh_hh = ( unsigned long )&_binary_jh_hh_wav_size;
unsigned  long * audio_buf_jh_ih = ( unsigned  long *)&_binary_jh_ih_wav_start;
unsigned long size_jh_ih = ( unsigned long )&_binary_jh_ih_wav_size;
unsigned  long * audio_buf_jh_iy = ( unsigned  long *)&_binary_jh_iy_wav_start;
unsigned long size_jh_iy = ( unsigned long )&_binary_jh_iy_wav_size;
unsigned  long * audio_buf_jh_jh = ( unsigned  long *)&_binary_jh_jh_wav_start;
unsigned long size_jh_jh = ( unsigned long )&_binary_jh_jh_wav_size;
unsigned  long * audio_buf_jh_k = ( unsigned  long *)&_binary_jh_k_wav_start;
unsigned long size_jh_k = ( unsigned long )&_binary_jh_k_wav_size;
unsigned  long * audio_buf_jh_l = ( unsigned  long *)&_binary_jh_l_wav_start;
unsigned long size_jh_l = ( unsigned long )&_binary_jh_l_wav_size;
unsigned  long * audio_buf_jh_m = ( unsigned  long *)&_binary_jh_m_wav_start;
unsigned long size_jh_m = ( unsigned long )&_binary_jh_m_wav_size;
unsigned  long * audio_buf_jh_n = ( unsigned  long *)&_binary_jh_n_wav_start;
unsigned long size_jh_n = ( unsigned long )&_binary_jh_n_wav_size;
unsigned  long * audio_buf_jh_ow = ( unsigned  long *)&_binary_jh_ow_wav_start;
unsigned long size_jh_ow = ( unsigned long )&_binary_jh_ow_wav_size;
unsigned  long * audio_buf_jh_oy = ( unsigned  long *)&_binary_jh_oy_wav_start;
unsigned long size_jh_oy = ( unsigned long )&_binary_jh_oy_wav_size;
unsigned  long * audio_buf_jh_p = ( unsigned  long *)&_binary_jh_p_wav_start;
unsigned long size_jh_p = ( unsigned long )&_binary_jh_p_wav_size;
unsigned  long * audio_buf_jh_pau = ( unsigned  long *)&_binary_jh_pau_wav_start;
unsigned long size_jh_pau = ( unsigned long )&_binary_jh_pau_wav_size;
unsigned  long * audio_buf_jh_r = ( unsigned  long *)&_binary_jh_r_wav_start;
unsigned long size_jh_r = ( unsigned long )&_binary_jh_r_wav_size;
unsigned  long * audio_buf_jh_s = ( unsigned  long *)&_binary_jh_s_wav_start;
unsigned long size_jh_s = ( unsigned long )&_binary_jh_s_wav_size;
unsigned  long * audio_buf_jh_sh = ( unsigned  long *)&_binary_jh_sh_wav_start;
unsigned long size_jh_sh = ( unsigned long )&_binary_jh_sh_wav_size;
unsigned  long * audio_buf_jh_t = ( unsigned  long *)&_binary_jh_t_wav_start;
unsigned long size_jh_t = ( unsigned long )&_binary_jh_t_wav_size;
unsigned  long * audio_buf_jh_th = ( unsigned  long *)&_binary_jh_th_wav_start;
unsigned long size_jh_th = ( unsigned long )&_binary_jh_th_wav_size;
unsigned  long * audio_buf_jh_uh = ( unsigned  long *)&_binary_jh_uh_wav_start;
unsigned long size_jh_uh = ( unsigned long )&_binary_jh_uh_wav_size;
unsigned  long * audio_buf_jh_uw = ( unsigned  long *)&_binary_jh_uw_wav_start;
unsigned long size_jh_uw = ( unsigned long )&_binary_jh_uw_wav_size;
unsigned  long * audio_buf_jh_v = ( unsigned  long *)&_binary_jh_v_wav_start;
unsigned long size_jh_v = ( unsigned long )&_binary_jh_v_wav_size;
unsigned  long * audio_buf_jh_w = ( unsigned  long *)&_binary_jh_w_wav_start;
unsigned long size_jh_w = ( unsigned long )&_binary_jh_w_wav_size;
unsigned  long * audio_buf_jh_y = ( unsigned  long *)&_binary_jh_y_wav_start;
unsigned long size_jh_y = ( unsigned long )&_binary_jh_y_wav_size;
unsigned  long * audio_buf_jh_z = ( unsigned  long *)&_binary_jh_z_wav_start;
unsigned long size_jh_z = ( unsigned long )&_binary_jh_z_wav_size;
unsigned  long * audio_buf_jh_zh = ( unsigned  long *)&_binary_jh_zh_wav_start;
unsigned long size_jh_zh = ( unsigned long )&_binary_jh_zh_wav_size;
//jh diphones
file_write("/tmp/jh-aa.wav",audio_buf_jh_aa,size_jh_aa);
file_write("/tmp/jh-ae.wav",audio_buf_jh_ae,size_jh_ae);
file_write("/tmp/jh-ah.wav",audio_buf_jh_ah,size_jh_ah);
file_write("/tmp/jh-ao.wav",audio_buf_jh_ao,size_jh_ao);
file_write("/tmp/jh-aw.wav",audio_buf_jh_aw,size_jh_aw);
file_write("/tmp/jh-ax.wav",audio_buf_jh_ax,size_jh_ax);
file_write("/tmp/jh-ay.wav",audio_buf_jh_ay,size_jh_ay);
file_write("/tmp/jh-b.wav",audio_buf_jh_b,size_jh_b);
file_write("/tmp/jh-ch.wav",audio_buf_jh_ch,size_jh_ch);
file_write("/tmp/jh-d.wav",audio_buf_jh_d,size_jh_d);
file_write("/tmp/jh-dh.wav",audio_buf_jh_dh,size_jh_dh);
file_write("/tmp/jh-eh.wav",audio_buf_jh_eh,size_jh_eh);
file_write("/tmp/jh-er.wav",audio_buf_jh_er,size_jh_er);
file_write("/tmp/jh-ey.wav",audio_buf_jh_ey,size_jh_ey);
file_write("/tmp/jh-f.wav",audio_buf_jh_f,size_jh_f);
file_write("/tmp/jh-g.wav",audio_buf_jh_g,size_jh_g);
file_write("/tmp/jh-hh.wav",audio_buf_jh_hh,size_jh_hh);
file_write("/tmp/jh-ih.wav",audio_buf_jh_ih,size_jh_ih);
file_write("/tmp/jh-iy.wav",audio_buf_jh_iy,size_jh_iy);
file_write("/tmp/jh-jh.wav",audio_buf_jh_jh,size_jh_jh);
file_write("/tmp/jh-k.wav",audio_buf_jh_k,size_jh_k);
file_write("/tmp/jh-l.wav",audio_buf_jh_l,size_jh_l);
file_write("/tmp/jh-m.wav",audio_buf_jh_m,size_jh_m);
file_write("/tmp/jh-n.wav",audio_buf_jh_n,size_jh_n);
file_write("/tmp/jh-ow.wav",audio_buf_jh_ow,size_jh_ow);
file_write("/tmp/jh-oy.wav",audio_buf_jh_oy,size_jh_oy);
file_write("/tmp/jh-p.wav",audio_buf_jh_p,size_jh_p);
file_write("/tmp/jh-pau.wav",audio_buf_jh_pau,size_jh_pau);
file_write("/tmp/jh-r.wav",audio_buf_jh_r,size_jh_r);
file_write("/tmp/jh-s.wav",audio_buf_jh_s,size_jh_s);
file_write("/tmp/jh-sh.wav",audio_buf_jh_sh,size_jh_sh);
file_write("/tmp/jh-t.wav",audio_buf_jh_t,size_jh_t);
file_write("/tmp/jh-th.wav",audio_buf_jh_th,size_jh_th);
file_write("/tmp/jh-uh.wav",audio_buf_jh_uh,size_jh_uh);
file_write("/tmp/jh-uw.wav",audio_buf_jh_uw,size_jh_uw);
file_write("/tmp/jh-v.wav",audio_buf_jh_v,size_jh_v);
file_write("/tmp/jh-w.wav",audio_buf_jh_w,size_jh_w);
file_write("/tmp/jh-y.wav",audio_buf_jh_y,size_jh_y);
file_write("/tmp/jh-z.wav",audio_buf_jh_z,size_jh_z);
file_write("/tmp/jh-zh.wav",audio_buf_jh_zh,size_jh_zh);

//k diphones  
unsigned  long * audio_buf_k_aa = ( unsigned  long *)&_binary_k_aa_wav_start; 
unsigned long size_k_aa = ( unsigned long )&_binary_k_aa_wav_size;
unsigned  long * audio_buf_k_ae = ( unsigned  long *)&_binary_k_ae_wav_start;
unsigned long size_k_ae = ( unsigned long )&_binary_k_ae_wav_size;
unsigned  long * audio_buf_k_ah = ( unsigned  long *)&_binary_k_ah_wav_start;
unsigned long size_k_ah = ( unsigned long )&_binary_k_ah_wav_size;
unsigned  long * audio_buf_k_ao = ( unsigned  long *)&_binary_k_ao_wav_start;
unsigned long size_k_ao = ( unsigned long )&_binary_k_ao_wav_size;
unsigned  long * audio_buf_k_aw = ( unsigned  long *)&_binary_k_aw_wav_start;
unsigned long size_k_aw = ( unsigned long )&_binary_k_aw_wav_size;
unsigned  long * audio_buf_k_ax = ( unsigned  long *)&_binary_k_ax_wav_start;
unsigned long size_k_ax = ( unsigned long )&_binary_k_ax_wav_size;
unsigned  long * audio_buf_k_ay = ( unsigned  long *)&_binary_k_ay_wav_start;
unsigned long size_k_ay = ( unsigned long )&_binary_k_ay_wav_size;
unsigned  long * audio_buf_k_b = ( unsigned  long *)&_binary_k_b_wav_start;
unsigned long size_k_b = ( unsigned long )&_binary_k_b_wav_size;
unsigned  long * audio_buf_k_ch = ( unsigned  long *)&_binary_k_ch_wav_start;
unsigned long size_k_ch = ( unsigned long )&_binary_k_ch_wav_size;
unsigned  long * audio_buf_k_d = ( unsigned  long *)&_binary_k_d_wav_start;
unsigned long size_k_d = ( unsigned long )&_binary_k_d_wav_size;
unsigned  long * audio_buf_k_dh = ( unsigned  long *)&_binary_k_dh_wav_start;
unsigned long size_k_dh = ( unsigned long )&_binary_k_dh_wav_size;
unsigned  long * audio_buf_k_eh = ( unsigned  long *)&_binary_k_eh_wav_start;
unsigned long size_k_eh = ( unsigned long )&_binary_k_eh_wav_size;
unsigned  long * audio_buf_k_er = ( unsigned  long *)&_binary_k_er_wav_start;
unsigned long size_k_er = ( unsigned long )&_binary_k_er_wav_size;
unsigned  long * audio_buf_k_ey = ( unsigned  long *)&_binary_k_ey_wav_start;
unsigned long size_k_ey = ( unsigned long )&_binary_k_ey_wav_size;
unsigned  long * audio_buf_k_f = ( unsigned  long *)&_binary_k_f_wav_start;
unsigned long size_k_f = ( unsigned long )&_binary_k_f_wav_size;
unsigned  long * audio_buf_k_g = ( unsigned  long *)&_binary_k_g_wav_start;
unsigned long size_k_g = ( unsigned long )&_binary_k_g_wav_size;
unsigned  long * audio_buf_k_hh = ( unsigned  long *)&_binary_k_hh_wav_start;
unsigned long size_k_hh = ( unsigned long )&_binary_k_hh_wav_size;
unsigned  long * audio_buf_k_ih = ( unsigned  long *)&_binary_k_ih_wav_start;
unsigned long size_k_ih = ( unsigned long )&_binary_k_ih_wav_size;
unsigned  long * audio_buf_k_iy = ( unsigned  long *)&_binary_k_iy_wav_start;
unsigned long size_k_iy = ( unsigned long )&_binary_k_iy_wav_size;
unsigned  long * audio_buf_k_jh = ( unsigned  long *)&_binary_k_jh_wav_start;
unsigned long size_k_jh = ( unsigned long )&_binary_k_jh_wav_size;
unsigned  long * audio_buf_k_k = ( unsigned  long *)&_binary_k_k_wav_start;
unsigned long size_k_k = ( unsigned long )&_binary_k_k_wav_size;
unsigned  long * audio_buf_k_l = ( unsigned  long *)&_binary_k_l_wav_start;
unsigned long size_k_l = ( unsigned long )&_binary_k_l_wav_size;
unsigned  long * audio_buf_k_m = ( unsigned  long *)&_binary_k_m_wav_start;
unsigned long size_k_m = ( unsigned long )&_binary_k_m_wav_size;
unsigned  long * audio_buf_k_n = ( unsigned  long *)&_binary_k_n_wav_start;
unsigned long size_k_n = ( unsigned long )&_binary_k_n_wav_size;
unsigned  long * audio_buf_k_ow = ( unsigned  long *)&_binary_k_ow_wav_start;
unsigned long size_k_ow = ( unsigned long )&_binary_k_ow_wav_size;
unsigned  long * audio_buf_k_oy = ( unsigned  long *)&_binary_k_oy_wav_start;
unsigned long size_k_oy = ( unsigned long )&_binary_k_oy_wav_size;
unsigned  long * audio_buf_k_p = ( unsigned  long *)&_binary_k_p_wav_start;
unsigned long size_k_p = ( unsigned long )&_binary_k_p_wav_size;
unsigned  long * audio_buf_k_pau = ( unsigned  long *)&_binary_k_pau_wav_start;
unsigned long size_k_pau = ( unsigned long )&_binary_k_pau_wav_size;
unsigned  long * audio_buf_k_r = ( unsigned  long *)&_binary_k_r_wav_start;
unsigned long size_k_r = ( unsigned long )&_binary_k_r_wav_size;
unsigned  long * audio_buf_k_s = ( unsigned  long *)&_binary_k_s_wav_start;
unsigned long size_k_s = ( unsigned long )&_binary_k_s_wav_size;
unsigned  long * audio_buf_k_sh = ( unsigned  long *)&_binary_k_sh_wav_start;
unsigned long size_k_sh = ( unsigned long )&_binary_k_sh_wav_size;
unsigned  long * audio_buf_k_t = ( unsigned  long *)&_binary_k_t_wav_start;
unsigned long size_k_t = ( unsigned long )&_binary_k_t_wav_size;
unsigned  long * audio_buf_k_th = ( unsigned  long *)&_binary_k_th_wav_start;
unsigned long size_k_th = ( unsigned long )&_binary_k_th_wav_size;
unsigned  long * audio_buf_k_uh = ( unsigned  long *)&_binary_k_uh_wav_start;
unsigned long size_k_uh = ( unsigned long )&_binary_k_uh_wav_size;
unsigned  long * audio_buf_k_uw = ( unsigned  long *)&_binary_k_uw_wav_start;
unsigned long size_k_uw = ( unsigned long )&_binary_k_uw_wav_size;
unsigned  long * audio_buf_k_v = ( unsigned  long *)&_binary_k_v_wav_start;
unsigned long size_k_v = ( unsigned long )&_binary_k_v_wav_size;
unsigned  long * audio_buf_k_w = ( unsigned  long *)&_binary_k_w_wav_start;
unsigned long size_k_w = ( unsigned long )&_binary_k_w_wav_size;
unsigned  long * audio_buf_k_y = ( unsigned  long *)&_binary_k_y_wav_start;
unsigned long size_k_y = ( unsigned long )&_binary_k_y_wav_size;
unsigned  long * audio_buf_k_z = ( unsigned  long *)&_binary_k_z_wav_start;
unsigned long size_k_z = ( unsigned long )&_binary_k_z_wav_size;
unsigned  long * audio_buf_k_zh = ( unsigned  long *)&_binary_k_zh_wav_start;
unsigned long size_k_zh = ( unsigned long )&_binary_k_zh_wav_size;
//k diphones
file_write("/tmp/k-aa.wav",audio_buf_k_aa,size_k_aa);
file_write("/tmp/k-ae.wav",audio_buf_k_ae,size_k_ae);
file_write("/tmp/k-ah.wav",audio_buf_k_ah,size_k_ah);
file_write("/tmp/k-ao.wav",audio_buf_k_ao,size_k_ao);
file_write("/tmp/k-aw.wav",audio_buf_k_aw,size_k_aw);
file_write("/tmp/k-ax.wav",audio_buf_k_ax,size_k_ax);
file_write("/tmp/k-ay.wav",audio_buf_k_ay,size_k_ay);
file_write("/tmp/k-b.wav",audio_buf_k_b,size_k_b);
file_write("/tmp/k-ch.wav",audio_buf_k_ch,size_k_ch);
file_write("/tmp/k-d.wav",audio_buf_k_d,size_k_d);
file_write("/tmp/k-dh.wav",audio_buf_k_dh,size_k_dh);
file_write("/tmp/k-eh.wav",audio_buf_k_eh,size_k_eh);
file_write("/tmp/k-er.wav",audio_buf_k_er,size_k_er);
file_write("/tmp/k-ey.wav",audio_buf_k_ey,size_k_ey);
file_write("/tmp/k-f.wav",audio_buf_k_f,size_k_f);
file_write("/tmp/k-g.wav",audio_buf_k_g,size_k_g);
file_write("/tmp/k-hh.wav",audio_buf_k_hh,size_k_hh);
file_write("/tmp/k-ih.wav",audio_buf_k_ih,size_k_ih);
file_write("/tmp/k-iy.wav",audio_buf_k_iy,size_k_iy);
file_write("/tmp/k-jh.wav",audio_buf_k_jh,size_k_jh);
file_write("/tmp/k-k.wav",audio_buf_k_k,size_k_k);
file_write("/tmp/k-l.wav",audio_buf_k_l,size_k_l);
file_write("/tmp/k-m.wav",audio_buf_k_m,size_k_m);
file_write("/tmp/k-n.wav",audio_buf_k_n,size_k_n);
file_write("/tmp/k-ow.wav",audio_buf_k_ow,size_k_ow);
file_write("/tmp/k-oy.wav",audio_buf_k_oy,size_k_oy);
file_write("/tmp/k-p.wav",audio_buf_k_p,size_k_p);
file_write("/tmp/k-pau.wav",audio_buf_k_pau,size_k_pau);
file_write("/tmp/k-r.wav",audio_buf_k_r,size_k_r);
file_write("/tmp/k-s.wav",audio_buf_k_s,size_k_s);
file_write("/tmp/k-sh.wav",audio_buf_k_sh,size_k_sh);
file_write("/tmp/k-t.wav",audio_buf_k_t,size_k_t);
file_write("/tmp/k-th.wav",audio_buf_k_th,size_k_th);
file_write("/tmp/k-uh.wav",audio_buf_k_uh,size_k_uh);
file_write("/tmp/k-uw.wav",audio_buf_k_uw,size_k_uw);
file_write("/tmp/k-v.wav",audio_buf_k_v,size_k_v);
file_write("/tmp/k-w.wav",audio_buf_k_w,size_k_w);
file_write("/tmp/k-y.wav",audio_buf_k_y,size_k_y);
file_write("/tmp/k-z.wav",audio_buf_k_z,size_k_z);
file_write("/tmp/k-zh.wav",audio_buf_k_zh,size_k_zh);

//l diphones  
unsigned  long * audio_buf_l_aa = ( unsigned  long *)&_binary_l_aa_wav_start; 
unsigned long size_l_aa = ( unsigned long )&_binary_l_aa_wav_size;
unsigned  long * audio_buf_l_ae = ( unsigned  long *)&_binary_l_ae_wav_start;
unsigned long size_l_ae = ( unsigned long )&_binary_l_ae_wav_size;
unsigned  long * audio_buf_l_ah = ( unsigned  long *)&_binary_l_ah_wav_start;
unsigned long size_l_ah = ( unsigned long )&_binary_l_ah_wav_size;
unsigned  long * audio_buf_l_ao = ( unsigned  long *)&_binary_l_ao_wav_start;
unsigned long size_l_ao = ( unsigned long )&_binary_l_ao_wav_size;
unsigned  long * audio_buf_l_aw = ( unsigned  long *)&_binary_l_aw_wav_start;
unsigned long size_l_aw = ( unsigned long )&_binary_l_aw_wav_size;
unsigned  long * audio_buf_l_ax = ( unsigned  long *)&_binary_l_ax_wav_start;
unsigned long size_l_ax = ( unsigned long )&_binary_l_ax_wav_size;
unsigned  long * audio_buf_l_ay = ( unsigned  long *)&_binary_l_ay_wav_start;
unsigned long size_l_ay = ( unsigned long )&_binary_l_ay_wav_size;
unsigned  long * audio_buf_l_b = ( unsigned  long *)&_binary_l_b_wav_start;
unsigned long size_l_b = ( unsigned long )&_binary_l_b_wav_size;
unsigned  long * audio_buf_l_ch = ( unsigned  long *)&_binary_l_ch_wav_start;
unsigned long size_l_ch = ( unsigned long )&_binary_l_ch_wav_size;
unsigned  long * audio_buf_l_d = ( unsigned  long *)&_binary_l_d_wav_start;
unsigned long size_l_d = ( unsigned long )&_binary_l_d_wav_size;
unsigned  long * audio_buf_l_dh = ( unsigned  long *)&_binary_l_dh_wav_start;
unsigned long size_l_dh = ( unsigned long )&_binary_l_dh_wav_size;
unsigned  long * audio_buf_l_eh = ( unsigned  long *)&_binary_l_eh_wav_start;
unsigned long size_l_eh = ( unsigned long )&_binary_l_eh_wav_size;
unsigned  long * audio_buf_l_er = ( unsigned  long *)&_binary_l_er_wav_start;
unsigned long size_l_er = ( unsigned long )&_binary_l_er_wav_size;
unsigned  long * audio_buf_l_ey = ( unsigned  long *)&_binary_l_ey_wav_start;
unsigned long size_l_ey = ( unsigned long )&_binary_l_ey_wav_size;
unsigned  long * audio_buf_l_f = ( unsigned  long *)&_binary_l_f_wav_start;
unsigned long size_l_f = ( unsigned long )&_binary_l_f_wav_size;
unsigned  long * audio_buf_l_g = ( unsigned  long *)&_binary_l_g_wav_start;
unsigned long size_l_g = ( unsigned long )&_binary_l_g_wav_size;
unsigned  long * audio_buf_l_hh = ( unsigned  long *)&_binary_l_hh_wav_start;
unsigned long size_l_hh = ( unsigned long )&_binary_l_hh_wav_size;
unsigned  long * audio_buf_l_ih = ( unsigned  long *)&_binary_l_ih_wav_start;
unsigned long size_l_ih = ( unsigned long )&_binary_l_ih_wav_size;
unsigned  long * audio_buf_l_iy = ( unsigned  long *)&_binary_l_iy_wav_start;
unsigned long size_l_iy = ( unsigned long )&_binary_l_iy_wav_size;
unsigned  long * audio_buf_l_jh = ( unsigned  long *)&_binary_l_jh_wav_start;
unsigned long size_l_jh = ( unsigned long )&_binary_l_jh_wav_size;
unsigned  long * audio_buf_l_k = ( unsigned  long *)&_binary_l_k_wav_start;
unsigned long size_l_k = ( unsigned long )&_binary_l_k_wav_size;
unsigned  long * audio_buf_l_l = ( unsigned  long *)&_binary_l_l_wav_start;
unsigned long size_l_l = ( unsigned long )&_binary_l_l_wav_size;
unsigned  long * audio_buf_l_m = ( unsigned  long *)&_binary_l_m_wav_start;
unsigned long size_l_m = ( unsigned long )&_binary_l_m_wav_size;
unsigned  long * audio_buf_l_n = ( unsigned  long *)&_binary_l_n_wav_start;
unsigned long size_l_n = ( unsigned long )&_binary_l_n_wav_size;
unsigned  long * audio_buf_l_ow = ( unsigned  long *)&_binary_l_ow_wav_start;
unsigned long size_l_ow = ( unsigned long )&_binary_l_ow_wav_size;
unsigned  long * audio_buf_l_oy = ( unsigned  long *)&_binary_l_oy_wav_start;
unsigned long size_l_oy = ( unsigned long )&_binary_l_oy_wav_size;
unsigned  long * audio_buf_l_p = ( unsigned  long *)&_binary_l_p_wav_start;
unsigned long size_l_p = ( unsigned long )&_binary_l_p_wav_size;
unsigned  long * audio_buf_l_pau = ( unsigned  long *)&_binary_l_pau_wav_start;
unsigned long size_l_pau = ( unsigned long )&_binary_l_pau_wav_size;
unsigned  long * audio_buf_l_r = ( unsigned  long *)&_binary_l_r_wav_start;
unsigned long size_l_r = ( unsigned long )&_binary_l_r_wav_size;
unsigned  long * audio_buf_l_s = ( unsigned  long *)&_binary_l_s_wav_start;
unsigned long size_l_s = ( unsigned long )&_binary_l_s_wav_size;
unsigned  long * audio_buf_l_sh = ( unsigned  long *)&_binary_l_sh_wav_start;
unsigned long size_l_sh = ( unsigned long )&_binary_l_sh_wav_size;
unsigned  long * audio_buf_l_t = ( unsigned  long *)&_binary_l_t_wav_start;
unsigned long size_l_t = ( unsigned long )&_binary_l_t_wav_size;
unsigned  long * audio_buf_l_th = ( unsigned  long *)&_binary_l_th_wav_start;
unsigned long size_l_th = ( unsigned long )&_binary_l_th_wav_size;
unsigned  long * audio_buf_l_uh = ( unsigned  long *)&_binary_l_uh_wav_start;
unsigned long size_l_uh = ( unsigned long )&_binary_l_uh_wav_size;
unsigned  long * audio_buf_l_uw = ( unsigned  long *)&_binary_l_uw_wav_start;
unsigned long size_l_uw = ( unsigned long )&_binary_l_uw_wav_size;
unsigned  long * audio_buf_l_v = ( unsigned  long *)&_binary_l_v_wav_start;
unsigned long size_l_v = ( unsigned long )&_binary_l_v_wav_size;
unsigned  long * audio_buf_l_w = ( unsigned  long *)&_binary_l_w_wav_start;
unsigned long size_l_w = ( unsigned long )&_binary_l_w_wav_size;
unsigned  long * audio_buf_l_y = ( unsigned  long *)&_binary_l_y_wav_start;
unsigned long size_l_y = ( unsigned long )&_binary_l_y_wav_size;
unsigned  long * audio_buf_l_z = ( unsigned  long *)&_binary_l_z_wav_start;
unsigned long size_l_z = ( unsigned long )&_binary_l_z_wav_size;
unsigned  long * audio_buf_l_zh = ( unsigned  long *)&_binary_l_zh_wav_start;
unsigned long size_l_zh = ( unsigned long )&_binary_l_zh_wav_size;
//l diphones
file_write("/tmp/l-aa.wav",audio_buf_l_aa,size_l_aa);
file_write("/tmp/l-ae.wav",audio_buf_l_ae,size_l_ae);
file_write("/tmp/l-ah.wav",audio_buf_l_ah,size_l_ah);
file_write("/tmp/l-ao.wav",audio_buf_l_ao,size_l_ao);
file_write("/tmp/l-aw.wav",audio_buf_l_aw,size_l_aw);
file_write("/tmp/l-ax.wav",audio_buf_l_ax,size_l_ax);
file_write("/tmp/l-ay.wav",audio_buf_l_ay,size_l_ay);
file_write("/tmp/l-b.wav",audio_buf_l_b,size_l_b);
file_write("/tmp/l-ch.wav",audio_buf_l_ch,size_l_ch);
file_write("/tmp/l-d.wav",audio_buf_l_d,size_l_d);
file_write("/tmp/l-dh.wav",audio_buf_l_dh,size_l_dh);
file_write("/tmp/l-eh.wav",audio_buf_l_eh,size_l_eh);
file_write("/tmp/l-er.wav",audio_buf_l_er,size_l_er);
file_write("/tmp/l-ey.wav",audio_buf_l_ey,size_l_ey);
file_write("/tmp/l-f.wav",audio_buf_l_f,size_l_f);
file_write("/tmp/l-g.wav",audio_buf_l_g,size_l_g);
file_write("/tmp/l-hh.wav",audio_buf_l_hh,size_l_hh);
file_write("/tmp/l-ih.wav",audio_buf_l_ih,size_l_ih);
file_write("/tmp/l-iy.wav",audio_buf_l_iy,size_l_iy);
file_write("/tmp/l-jh.wav",audio_buf_l_jh,size_l_jh);
file_write("/tmp/l-k.wav",audio_buf_l_k,size_l_k);
file_write("/tmp/l-l.wav",audio_buf_l_l,size_l_l);
file_write("/tmp/l-m.wav",audio_buf_l_m,size_l_m);
file_write("/tmp/l-n.wav",audio_buf_l_n,size_l_n);
file_write("/tmp/l-ow.wav",audio_buf_l_ow,size_l_ow);
file_write("/tmp/l-oy.wav",audio_buf_l_oy,size_l_oy);
file_write("/tmp/l-p.wav",audio_buf_l_p,size_l_p);
file_write("/tmp/l-pau.wav",audio_buf_l_pau,size_l_pau);
file_write("/tmp/l-r.wav",audio_buf_l_r,size_l_r);
file_write("/tmp/l-s.wav",audio_buf_l_s,size_l_s);
file_write("/tmp/l-sh.wav",audio_buf_l_sh,size_l_sh);
file_write("/tmp/l-t.wav",audio_buf_l_t,size_l_t);
file_write("/tmp/l-th.wav",audio_buf_l_th,size_l_th);
file_write("/tmp/l-uh.wav",audio_buf_l_uh,size_l_uh);
file_write("/tmp/l-uw.wav",audio_buf_l_uw,size_l_uw);
file_write("/tmp/l-v.wav",audio_buf_l_v,size_l_v);
file_write("/tmp/l-w.wav",audio_buf_l_w,size_l_w);
file_write("/tmp/l-y.wav",audio_buf_l_y,size_l_y);
file_write("/tmp/l-z.wav",audio_buf_l_z,size_l_z);
file_write("/tmp/l-zh.wav",audio_buf_l_zh,size_l_zh);

//m diphones  
unsigned  long * audio_buf_m_aa = ( unsigned  long *)&_binary_m_aa_wav_start; 
unsigned long size_m_aa = ( unsigned long )&_binary_m_aa_wav_size;
unsigned  long * audio_buf_m_ae = ( unsigned  long *)&_binary_m_ae_wav_start;
unsigned long size_m_ae = ( unsigned long )&_binary_m_ae_wav_size;
unsigned  long * audio_buf_m_ah = ( unsigned  long *)&_binary_m_ah_wav_start;
unsigned long size_m_ah = ( unsigned long )&_binary_m_ah_wav_size;
unsigned  long * audio_buf_m_ao = ( unsigned  long *)&_binary_m_ao_wav_start;
unsigned long size_m_ao = ( unsigned long )&_binary_m_ao_wav_size;
unsigned  long * audio_buf_m_aw = ( unsigned  long *)&_binary_m_aw_wav_start;
unsigned long size_m_aw = ( unsigned long )&_binary_m_aw_wav_size;
unsigned  long * audio_buf_m_ax = ( unsigned  long *)&_binary_m_ax_wav_start;
unsigned long size_m_ax = ( unsigned long )&_binary_m_ax_wav_size;
unsigned  long * audio_buf_m_ay = ( unsigned  long *)&_binary_m_ay_wav_start;
unsigned long size_m_ay = ( unsigned long )&_binary_m_ay_wav_size;
unsigned  long * audio_buf_m_b = ( unsigned  long *)&_binary_m_b_wav_start;
unsigned long size_m_b = ( unsigned long )&_binary_m_b_wav_size;
unsigned  long * audio_buf_m_ch = ( unsigned  long *)&_binary_m_ch_wav_start;
unsigned long size_m_ch = ( unsigned long )&_binary_m_ch_wav_size;
unsigned  long * audio_buf_m_d = ( unsigned  long *)&_binary_m_d_wav_start;
unsigned long size_m_d = ( unsigned long )&_binary_m_d_wav_size;
unsigned  long * audio_buf_m_dh = ( unsigned  long *)&_binary_m_dh_wav_start;
unsigned long size_m_dh = ( unsigned long )&_binary_m_dh_wav_size;
unsigned  long * audio_buf_m_eh = ( unsigned  long *)&_binary_m_eh_wav_start;
unsigned long size_m_eh = ( unsigned long )&_binary_m_eh_wav_size;
unsigned  long * audio_buf_m_er = ( unsigned  long *)&_binary_m_er_wav_start;
unsigned long size_m_er = ( unsigned long )&_binary_m_er_wav_size;
unsigned  long * audio_buf_m_ey = ( unsigned  long *)&_binary_m_ey_wav_start;
unsigned long size_m_ey = ( unsigned long )&_binary_m_ey_wav_size;
unsigned  long * audio_buf_m_f = ( unsigned  long *)&_binary_m_f_wav_start;
unsigned long size_m_f = ( unsigned long )&_binary_m_f_wav_size;
unsigned  long * audio_buf_m_g = ( unsigned  long *)&_binary_m_g_wav_start;
unsigned long size_m_g = ( unsigned long )&_binary_m_g_wav_size;
unsigned  long * audio_buf_m_hh = ( unsigned  long *)&_binary_m_hh_wav_start;
unsigned long size_m_hh = ( unsigned long )&_binary_m_hh_wav_size;
unsigned  long * audio_buf_m_ih = ( unsigned  long *)&_binary_m_ih_wav_start;
unsigned long size_m_ih = ( unsigned long )&_binary_m_ih_wav_size;
unsigned  long * audio_buf_m_iy = ( unsigned  long *)&_binary_m_iy_wav_start;
unsigned long size_m_iy = ( unsigned long )&_binary_m_iy_wav_size;
unsigned  long * audio_buf_m_jh = ( unsigned  long *)&_binary_m_jh_wav_start;
unsigned long size_m_jh = ( unsigned long )&_binary_m_jh_wav_size;
unsigned  long * audio_buf_m_k = ( unsigned  long *)&_binary_m_k_wav_start;
unsigned long size_m_k = ( unsigned long )&_binary_m_k_wav_size;
unsigned  long * audio_buf_m_l = ( unsigned  long *)&_binary_m_l_wav_start;
unsigned long size_m_l = ( unsigned long )&_binary_m_l_wav_size;
unsigned  long * audio_buf_m_m = ( unsigned  long *)&_binary_m_m_wav_start;
unsigned long size_m_m = ( unsigned long )&_binary_m_m_wav_size;
unsigned  long * audio_buf_m_n = ( unsigned  long *)&_binary_m_n_wav_start;
unsigned long size_m_n = ( unsigned long )&_binary_m_n_wav_size;
unsigned  long * audio_buf_m_ow = ( unsigned  long *)&_binary_m_ow_wav_start;
unsigned long size_m_ow = ( unsigned long )&_binary_m_ow_wav_size;
unsigned  long * audio_buf_m_oy = ( unsigned  long *)&_binary_m_oy_wav_start;
unsigned long size_m_oy = ( unsigned long )&_binary_m_oy_wav_size;
unsigned  long * audio_buf_m_p = ( unsigned  long *)&_binary_m_p_wav_start;
unsigned long size_m_p = ( unsigned long )&_binary_m_p_wav_size;
unsigned  long * audio_buf_m_pau = ( unsigned  long *)&_binary_m_pau_wav_start;
unsigned long size_m_pau = ( unsigned long )&_binary_m_pau_wav_size;
unsigned  long * audio_buf_m_r = ( unsigned  long *)&_binary_m_r_wav_start;
unsigned long size_m_r = ( unsigned long )&_binary_m_r_wav_size;
unsigned  long * audio_buf_m_s = ( unsigned  long *)&_binary_m_s_wav_start;
unsigned long size_m_s = ( unsigned long )&_binary_m_s_wav_size;
unsigned  long * audio_buf_m_sh = ( unsigned  long *)&_binary_m_sh_wav_start;
unsigned long size_m_sh = ( unsigned long )&_binary_m_sh_wav_size;
unsigned  long * audio_buf_m_t = ( unsigned  long *)&_binary_m_t_wav_start;
unsigned long size_m_t = ( unsigned long )&_binary_m_t_wav_size;
unsigned  long * audio_buf_m_th = ( unsigned  long *)&_binary_m_th_wav_start;
unsigned long size_m_th = ( unsigned long )&_binary_m_th_wav_size;
unsigned  long * audio_buf_m_uh = ( unsigned  long *)&_binary_m_uh_wav_start;
unsigned long size_m_uh = ( unsigned long )&_binary_m_uh_wav_size;
unsigned  long * audio_buf_m_uw = ( unsigned  long *)&_binary_m_uw_wav_start;
unsigned long size_m_uw = ( unsigned long )&_binary_m_uw_wav_size;
unsigned  long * audio_buf_m_v = ( unsigned  long *)&_binary_m_v_wav_start;
unsigned long size_m_v = ( unsigned long )&_binary_m_v_wav_size;
unsigned  long * audio_buf_m_w = ( unsigned  long *)&_binary_m_w_wav_start;
unsigned long size_m_w = ( unsigned long )&_binary_m_w_wav_size;
unsigned  long * audio_buf_m_y = ( unsigned  long *)&_binary_m_y_wav_start;
unsigned long size_m_y = ( unsigned long )&_binary_m_y_wav_size;
unsigned  long * audio_buf_m_z = ( unsigned  long *)&_binary_m_z_wav_start;
unsigned long size_m_z = ( unsigned long )&_binary_m_z_wav_size;
unsigned  long * audio_buf_m_zh = ( unsigned  long *)&_binary_m_zh_wav_start;
unsigned long size_m_zh = ( unsigned long )&_binary_m_zh_wav_size;
//m diphones
file_write("/tmp/m-aa.wav",audio_buf_m_aa,size_m_aa);
file_write("/tmp/m-ae.wav",audio_buf_m_ae,size_m_ae);
file_write("/tmp/m-ah.wav",audio_buf_m_ah,size_m_ah);
file_write("/tmp/m-ao.wav",audio_buf_m_ao,size_m_ao);
file_write("/tmp/m-aw.wav",audio_buf_m_aw,size_m_aw);
file_write("/tmp/m-ax.wav",audio_buf_m_ax,size_m_ax);
file_write("/tmp/m-ay.wav",audio_buf_m_ay,size_m_ay);
file_write("/tmp/m-b.wav",audio_buf_m_b,size_m_b);
file_write("/tmp/m-ch.wav",audio_buf_m_ch,size_m_ch);
file_write("/tmp/m-d.wav",audio_buf_m_d,size_m_d);
file_write("/tmp/m-dh.wav",audio_buf_m_dh,size_m_dh);
file_write("/tmp/m-eh.wav",audio_buf_m_eh,size_m_eh);
file_write("/tmp/m-er.wav",audio_buf_m_er,size_m_er);
file_write("/tmp/m-ey.wav",audio_buf_m_ey,size_m_ey);
file_write("/tmp/m-f.wav",audio_buf_m_f,size_m_f);
file_write("/tmp/m-g.wav",audio_buf_m_g,size_m_g);
file_write("/tmp/m-hh.wav",audio_buf_m_hh,size_m_hh);
file_write("/tmp/m-ih.wav",audio_buf_m_ih,size_m_ih);
file_write("/tmp/m-iy.wav",audio_buf_m_iy,size_m_iy);
file_write("/tmp/m-jh.wav",audio_buf_m_jh,size_m_jh);
file_write("/tmp/m-k.wav",audio_buf_m_k,size_m_k);
file_write("/tmp/m-l.wav",audio_buf_m_l,size_m_l);
file_write("/tmp/m-m.wav",audio_buf_m_m,size_m_m);
file_write("/tmp/m-n.wav",audio_buf_m_n,size_m_n);
file_write("/tmp/m-ow.wav",audio_buf_m_ow,size_m_ow);
file_write("/tmp/m-oy.wav",audio_buf_m_oy,size_m_oy);
file_write("/tmp/m-p.wav",audio_buf_m_p,size_m_p);
file_write("/tmp/m-pau.wav",audio_buf_m_pau,size_m_pau);
file_write("/tmp/m-r.wav",audio_buf_m_r,size_m_r);
file_write("/tmp/m-s.wav",audio_buf_m_s,size_m_s);
file_write("/tmp/m-sh.wav",audio_buf_m_sh,size_m_sh);
file_write("/tmp/m-t.wav",audio_buf_m_t,size_m_t);
file_write("/tmp/m-th.wav",audio_buf_m_th,size_m_th);
file_write("/tmp/m-uh.wav",audio_buf_m_uh,size_m_uh);
file_write("/tmp/m-uw.wav",audio_buf_m_uw,size_m_uw);
file_write("/tmp/m-v.wav",audio_buf_m_v,size_m_v);
file_write("/tmp/m-w.wav",audio_buf_m_w,size_m_w);
file_write("/tmp/m-y.wav",audio_buf_m_y,size_m_y);
file_write("/tmp/m-z.wav",audio_buf_m_z,size_m_z);
file_write("/tmp/m-zh.wav",audio_buf_m_zh,size_m_zh);

//n diphones  
unsigned  long * audio_buf_n_aa = ( unsigned  long *)&_binary_n_aa_wav_start; 
unsigned long size_n_aa = ( unsigned long )&_binary_n_aa_wav_size;
unsigned  long * audio_buf_n_ae = ( unsigned  long *)&_binary_n_ae_wav_start;
unsigned long size_n_ae = ( unsigned long )&_binary_n_ae_wav_size;
unsigned  long * audio_buf_n_ah = ( unsigned  long *)&_binary_n_ah_wav_start;
unsigned long size_n_ah = ( unsigned long )&_binary_n_ah_wav_size;
unsigned  long * audio_buf_n_ao = ( unsigned  long *)&_binary_n_ao_wav_start;
unsigned long size_n_ao = ( unsigned long )&_binary_n_ao_wav_size;
unsigned  long * audio_buf_n_aw = ( unsigned  long *)&_binary_n_aw_wav_start;
unsigned long size_n_aw = ( unsigned long )&_binary_n_aw_wav_size;
unsigned  long * audio_buf_n_ax = ( unsigned  long *)&_binary_n_ax_wav_start;
unsigned long size_n_ax = ( unsigned long )&_binary_n_ax_wav_size;
unsigned  long * audio_buf_n_ay = ( unsigned  long *)&_binary_n_ay_wav_start;
unsigned long size_n_ay = ( unsigned long )&_binary_n_ay_wav_size;
unsigned  long * audio_buf_n_b = ( unsigned  long *)&_binary_n_b_wav_start;
unsigned long size_n_b = ( unsigned long )&_binary_n_b_wav_size;
unsigned  long * audio_buf_n_ch = ( unsigned  long *)&_binary_n_ch_wav_start;
unsigned long size_n_ch = ( unsigned long )&_binary_n_ch_wav_size;
unsigned  long * audio_buf_n_d = ( unsigned  long *)&_binary_n_d_wav_start;
unsigned long size_n_d = ( unsigned long )&_binary_n_d_wav_size;
unsigned  long * audio_buf_n_dh = ( unsigned  long *)&_binary_n_dh_wav_start;
unsigned long size_n_dh = ( unsigned long )&_binary_n_dh_wav_size;
unsigned  long * audio_buf_n_eh = ( unsigned  long *)&_binary_n_eh_wav_start;
unsigned long size_n_eh = ( unsigned long )&_binary_n_eh_wav_size;
unsigned  long * audio_buf_n_er = ( unsigned  long *)&_binary_n_er_wav_start;
unsigned long size_n_er = ( unsigned long )&_binary_n_er_wav_size;
unsigned  long * audio_buf_n_ey = ( unsigned  long *)&_binary_n_ey_wav_start;
unsigned long size_n_ey = ( unsigned long )&_binary_n_ey_wav_size;
unsigned  long * audio_buf_n_f = ( unsigned  long *)&_binary_n_f_wav_start;
unsigned long size_n_f = ( unsigned long )&_binary_n_f_wav_size;
unsigned  long * audio_buf_n_g = ( unsigned  long *)&_binary_n_g_wav_start;
unsigned long size_n_g = ( unsigned long )&_binary_n_g_wav_size;
unsigned  long * audio_buf_n_hh = ( unsigned  long *)&_binary_n_hh_wav_start;
unsigned long size_n_hh = ( unsigned long )&_binary_n_hh_wav_size;
unsigned  long * audio_buf_n_ih = ( unsigned  long *)&_binary_n_ih_wav_start;
unsigned long size_n_ih = ( unsigned long )&_binary_n_ih_wav_size;
unsigned  long * audio_buf_n_iy = ( unsigned  long *)&_binary_n_iy_wav_start;
unsigned long size_n_iy = ( unsigned long )&_binary_n_iy_wav_size;
unsigned  long * audio_buf_n_jh = ( unsigned  long *)&_binary_n_jh_wav_start;
unsigned long size_n_jh = ( unsigned long )&_binary_n_jh_wav_size;
unsigned  long * audio_buf_n_k = ( unsigned  long *)&_binary_n_k_wav_start;
unsigned long size_n_k = ( unsigned long )&_binary_n_k_wav_size;
unsigned  long * audio_buf_n_l = ( unsigned  long *)&_binary_n_l_wav_start;
unsigned long size_n_l = ( unsigned long )&_binary_n_l_wav_size;
unsigned  long * audio_buf_n_m = ( unsigned  long *)&_binary_n_m_wav_start;
unsigned long size_n_m = ( unsigned long )&_binary_n_m_wav_size;
unsigned  long * audio_buf_n_n = ( unsigned  long *)&_binary_n_n_wav_start;
unsigned long size_n_n = ( unsigned long )&_binary_n_n_wav_size;
unsigned  long * audio_buf_n_ow = ( unsigned  long *)&_binary_n_ow_wav_start;
unsigned long size_n_ow = ( unsigned long )&_binary_n_ow_wav_size;
unsigned  long * audio_buf_n_oy = ( unsigned  long *)&_binary_n_oy_wav_start;
unsigned long size_n_oy = ( unsigned long )&_binary_n_oy_wav_size;
unsigned  long * audio_buf_n_p = ( unsigned  long *)&_binary_n_p_wav_start;
unsigned long size_n_p = ( unsigned long )&_binary_n_p_wav_size;
unsigned  long * audio_buf_n_pau = ( unsigned  long *)&_binary_n_pau_wav_start;
unsigned long size_n_pau = ( unsigned long )&_binary_n_pau_wav_size;
unsigned  long * audio_buf_n_r = ( unsigned  long *)&_binary_n_r_wav_start;
unsigned long size_n_r = ( unsigned long )&_binary_n_r_wav_size;
unsigned  long * audio_buf_n_s = ( unsigned  long *)&_binary_n_s_wav_start;
unsigned long size_n_s = ( unsigned long )&_binary_n_s_wav_size;
unsigned  long * audio_buf_n_sh = ( unsigned  long *)&_binary_n_sh_wav_start;
unsigned long size_n_sh = ( unsigned long )&_binary_n_sh_wav_size;
unsigned  long * audio_buf_n_t = ( unsigned  long *)&_binary_n_t_wav_start;
unsigned long size_n_t = ( unsigned long )&_binary_n_t_wav_size;
unsigned  long * audio_buf_n_th = ( unsigned  long *)&_binary_n_th_wav_start;
unsigned long size_n_th = ( unsigned long )&_binary_n_th_wav_size;
unsigned  long * audio_buf_n_uh = ( unsigned  long *)&_binary_n_uh_wav_start;
unsigned long size_n_uh = ( unsigned long )&_binary_n_uh_wav_size;
unsigned  long * audio_buf_n_uw = ( unsigned  long *)&_binary_n_uw_wav_start;
unsigned long size_n_uw = ( unsigned long )&_binary_n_uw_wav_size;
unsigned  long * audio_buf_n_v = ( unsigned  long *)&_binary_n_v_wav_start;
unsigned long size_n_v = ( unsigned long )&_binary_n_v_wav_size;
unsigned  long * audio_buf_n_w = ( unsigned  long *)&_binary_n_w_wav_start;
unsigned long size_n_w = ( unsigned long )&_binary_n_w_wav_size;
unsigned  long * audio_buf_n_y = ( unsigned  long *)&_binary_n_y_wav_start;
unsigned long size_n_y = ( unsigned long )&_binary_n_y_wav_size;
unsigned  long * audio_buf_n_z = ( unsigned  long *)&_binary_n_z_wav_start;
unsigned long size_n_z = ( unsigned long )&_binary_n_z_wav_size;
unsigned  long * audio_buf_n_zh = ( unsigned  long *)&_binary_n_zh_wav_start;
unsigned long size_n_zh = ( unsigned long )&_binary_n_zh_wav_size;
//n diphones
file_write("/tmp/n-aa.wav",audio_buf_n_aa,size_n_aa);
file_write("/tmp/n-ae.wav",audio_buf_n_ae,size_n_ae);
file_write("/tmp/n-ah.wav",audio_buf_n_ah,size_n_ah);
file_write("/tmp/n-ao.wav",audio_buf_n_ao,size_n_ao);
file_write("/tmp/n-aw.wav",audio_buf_n_aw,size_n_aw);
file_write("/tmp/n-ax.wav",audio_buf_n_ax,size_n_ax);
file_write("/tmp/n-ay.wav",audio_buf_n_ay,size_n_ay);
file_write("/tmp/n-b.wav",audio_buf_n_b,size_n_b);
file_write("/tmp/n-ch.wav",audio_buf_n_ch,size_n_ch);
file_write("/tmp/n-d.wav",audio_buf_n_d,size_n_d);
file_write("/tmp/n-dh.wav",audio_buf_n_dh,size_n_dh);
file_write("/tmp/n-eh.wav",audio_buf_n_eh,size_n_eh);
file_write("/tmp/n-er.wav",audio_buf_n_er,size_n_er);
file_write("/tmp/n-ey.wav",audio_buf_n_ey,size_n_ey);
file_write("/tmp/n-f.wav",audio_buf_n_f,size_n_f);
file_write("/tmp/n-g.wav",audio_buf_n_g,size_n_g);
file_write("/tmp/n-hh.wav",audio_buf_n_hh,size_n_hh);
file_write("/tmp/n-ih.wav",audio_buf_n_ih,size_n_ih);
file_write("/tmp/n-iy.wav",audio_buf_n_iy,size_n_iy);
file_write("/tmp/n-jh.wav",audio_buf_n_jh,size_n_jh);
file_write("/tmp/n-k.wav",audio_buf_n_k,size_n_k);
file_write("/tmp/n-l.wav",audio_buf_n_l,size_n_l);
file_write("/tmp/n-m.wav",audio_buf_n_m,size_n_m);
file_write("/tmp/n-n.wav",audio_buf_n_n,size_n_n);
file_write("/tmp/n-ow.wav",audio_buf_n_ow,size_n_ow);
file_write("/tmp/n-oy.wav",audio_buf_n_oy,size_n_oy);
file_write("/tmp/n-p.wav",audio_buf_n_p,size_n_p);
file_write("/tmp/n-pau.wav",audio_buf_n_pau,size_n_pau);
file_write("/tmp/n-r.wav",audio_buf_n_r,size_n_r);
file_write("/tmp/n-s.wav",audio_buf_n_s,size_n_s);
file_write("/tmp/n-sh.wav",audio_buf_n_sh,size_n_sh);
file_write("/tmp/n-t.wav",audio_buf_n_t,size_n_t);
file_write("/tmp/n-th.wav",audio_buf_n_th,size_n_th);
file_write("/tmp/n-uh.wav",audio_buf_n_uh,size_n_uh);
file_write("/tmp/n-uw.wav",audio_buf_n_uw,size_n_uw);
file_write("/tmp/n-v.wav",audio_buf_n_v,size_n_v);
file_write("/tmp/n-w.wav",audio_buf_n_w,size_n_w);
file_write("/tmp/n-y.wav",audio_buf_n_y,size_n_y);
file_write("/tmp/n-z.wav",audio_buf_n_z,size_n_z);
file_write("/tmp/n-zh.wav",audio_buf_n_zh,size_n_zh);

//ng diphones  
unsigned  long * audio_buf_ng_aa = ( unsigned  long *)&_binary_ng_aa_wav_start; 
unsigned long size_ng_aa = ( unsigned long )&_binary_ng_aa_wav_size;
unsigned  long * audio_buf_ng_ae = ( unsigned  long *)&_binary_ng_ae_wav_start;
unsigned long size_ng_ae = ( unsigned long )&_binary_ng_ae_wav_size;
unsigned  long * audio_buf_ng_ah = ( unsigned  long *)&_binary_ng_ah_wav_start;
unsigned long size_ng_ah = ( unsigned long )&_binary_ng_ah_wav_size;
unsigned  long * audio_buf_ng_ao = ( unsigned  long *)&_binary_ng_ao_wav_start;
unsigned long size_ng_ao = ( unsigned long )&_binary_ng_ao_wav_size;
unsigned  long * audio_buf_ng_aw = ( unsigned  long *)&_binary_ng_aw_wav_start;
unsigned long size_ng_aw = ( unsigned long )&_binary_ng_aw_wav_size;
unsigned  long * audio_buf_ng_ax = ( unsigned  long *)&_binary_ng_ax_wav_start;
unsigned long size_ng_ax = ( unsigned long )&_binary_ng_ax_wav_size;
unsigned  long * audio_buf_ng_ay = ( unsigned  long *)&_binary_ng_ay_wav_start;
unsigned long size_ng_ay = ( unsigned long )&_binary_ng_ay_wav_size;
unsigned  long * audio_buf_ng_b = ( unsigned  long *)&_binary_ng_b_wav_start;
unsigned long size_ng_b = ( unsigned long )&_binary_ng_b_wav_size;
unsigned  long * audio_buf_ng_ch = ( unsigned  long *)&_binary_ng_ch_wav_start;
unsigned long size_ng_ch = ( unsigned long )&_binary_ng_ch_wav_size;
unsigned  long * audio_buf_ng_d = ( unsigned  long *)&_binary_ng_d_wav_start;
unsigned long size_ng_d = ( unsigned long )&_binary_ng_d_wav_size;
unsigned  long * audio_buf_ng_dh = ( unsigned  long *)&_binary_ng_dh_wav_start;
unsigned long size_ng_dh = ( unsigned long )&_binary_ng_dh_wav_size;
unsigned  long * audio_buf_ng_eh = ( unsigned  long *)&_binary_ng_eh_wav_start;
unsigned long size_ng_eh = ( unsigned long )&_binary_ng_eh_wav_size;
unsigned  long * audio_buf_ng_er = ( unsigned  long *)&_binary_ng_er_wav_start;
unsigned long size_ng_er = ( unsigned long )&_binary_ng_er_wav_size;
unsigned  long * audio_buf_ng_ey = ( unsigned  long *)&_binary_ng_ey_wav_start;
unsigned long size_ng_ey = ( unsigned long )&_binary_ng_ey_wav_size;
unsigned  long * audio_buf_ng_f = ( unsigned  long *)&_binary_ng_f_wav_start;
unsigned long size_ng_f = ( unsigned long )&_binary_ng_f_wav_size;
unsigned  long * audio_buf_ng_g = ( unsigned  long *)&_binary_ng_g_wav_start;
unsigned long size_ng_g = ( unsigned long )&_binary_ng_g_wav_size;
unsigned  long * audio_buf_ng_hh = ( unsigned  long *)&_binary_ng_hh_wav_start;
unsigned long size_ng_hh = ( unsigned long )&_binary_ng_hh_wav_size;
unsigned  long * audio_buf_ng_ih = ( unsigned  long *)&_binary_ng_ih_wav_start;
unsigned long size_ng_ih = ( unsigned long )&_binary_ng_ih_wav_size;
unsigned  long * audio_buf_ng_iy = ( unsigned  long *)&_binary_ng_iy_wav_start;
unsigned long size_ng_iy = ( unsigned long )&_binary_ng_iy_wav_size;
unsigned  long * audio_buf_ng_jh = ( unsigned  long *)&_binary_ng_jh_wav_start;
unsigned long size_ng_jh = ( unsigned long )&_binary_ng_jh_wav_size;
unsigned  long * audio_buf_ng_k = ( unsigned  long *)&_binary_ng_k_wav_start;
unsigned long size_ng_k = ( unsigned long )&_binary_ng_k_wav_size;
unsigned  long * audio_buf_ng_l = ( unsigned  long *)&_binary_ng_l_wav_start;
unsigned long size_ng_l = ( unsigned long )&_binary_ng_l_wav_size;
unsigned  long * audio_buf_ng_m = ( unsigned  long *)&_binary_ng_m_wav_start;
unsigned long size_ng_m = ( unsigned long )&_binary_ng_m_wav_size;
unsigned  long * audio_buf_ng_n = ( unsigned  long *)&_binary_ng_n_wav_start;
unsigned long size_ng_n = ( unsigned long )&_binary_ng_n_wav_size;
unsigned  long * audio_buf_ng_ow = ( unsigned  long *)&_binary_ng_ow_wav_start;
unsigned long size_ng_ow = ( unsigned long )&_binary_ng_ow_wav_size;
unsigned  long * audio_buf_ng_oy = ( unsigned  long *)&_binary_ng_oy_wav_start;
unsigned long size_ng_oy = ( unsigned long )&_binary_ng_oy_wav_size;
unsigned  long * audio_buf_ng_p = ( unsigned  long *)&_binary_ng_p_wav_start;
unsigned long size_ng_p = ( unsigned long )&_binary_ng_p_wav_size;
unsigned  long * audio_buf_ng_pau = ( unsigned  long *)&_binary_ng_pau_wav_start;
unsigned long size_ng_pau = ( unsigned long )&_binary_ng_pau_wav_size;
unsigned  long * audio_buf_ng_r = ( unsigned  long *)&_binary_ng_r_wav_start;
unsigned long size_ng_r = ( unsigned long )&_binary_ng_r_wav_size;
unsigned  long * audio_buf_ng_s = ( unsigned  long *)&_binary_ng_s_wav_start;
unsigned long size_ng_s = ( unsigned long )&_binary_ng_s_wav_size;
unsigned  long * audio_buf_ng_sh = ( unsigned  long *)&_binary_ng_sh_wav_start;
unsigned long size_ng_sh = ( unsigned long )&_binary_ng_sh_wav_size;
unsigned  long * audio_buf_ng_t = ( unsigned  long *)&_binary_ng_t_wav_start;
unsigned long size_ng_t = ( unsigned long )&_binary_ng_t_wav_size;
unsigned  long * audio_buf_ng_th = ( unsigned  long *)&_binary_ng_th_wav_start;
unsigned long size_ng_th = ( unsigned long )&_binary_ng_th_wav_size;
unsigned  long * audio_buf_ng_uh = ( unsigned  long *)&_binary_ng_uh_wav_start;
unsigned long size_ng_uh = ( unsigned long )&_binary_ng_uh_wav_size;
unsigned  long * audio_buf_ng_uw = ( unsigned  long *)&_binary_ng_uw_wav_start;
unsigned long size_ng_uw = ( unsigned long )&_binary_ng_uw_wav_size;
unsigned  long * audio_buf_ng_v = ( unsigned  long *)&_binary_ng_v_wav_start;
unsigned long size_ng_v = ( unsigned long )&_binary_ng_v_wav_size;
unsigned  long * audio_buf_ng_w = ( unsigned  long *)&_binary_ng_w_wav_start;
unsigned long size_ng_w = ( unsigned long )&_binary_ng_w_wav_size;
unsigned  long * audio_buf_ng_y = ( unsigned  long *)&_binary_ng_y_wav_start;
unsigned long size_ng_y = ( unsigned long )&_binary_ng_y_wav_size;
unsigned  long * audio_buf_ng_z = ( unsigned  long *)&_binary_ng_z_wav_start;
unsigned long size_ng_z = ( unsigned long )&_binary_ng_z_wav_size;
unsigned  long * audio_buf_ng_zh = ( unsigned  long *)&_binary_ng_zh_wav_start;
unsigned long size_ng_zh = ( unsigned long )&_binary_ng_zh_wav_size;
//ng diphones
file_write("/tmp/ng-aa.wav",audio_buf_ng_aa,size_ng_aa);
file_write("/tmp/ng-ae.wav",audio_buf_ng_ae,size_ng_ae);
file_write("/tmp/ng-ah.wav",audio_buf_ng_ah,size_ng_ah);
file_write("/tmp/ng-ao.wav",audio_buf_ng_ao,size_ng_ao);
file_write("/tmp/ng-aw.wav",audio_buf_ng_aw,size_ng_aw);
file_write("/tmp/ng-ax.wav",audio_buf_ng_ax,size_ng_ax);
file_write("/tmp/ng-ay.wav",audio_buf_ng_ay,size_ng_ay);
file_write("/tmp/ng-b.wav",audio_buf_ng_b,size_ng_b);
file_write("/tmp/ng-ch.wav",audio_buf_ng_ch,size_ng_ch);
file_write("/tmp/ng-d.wav",audio_buf_ng_d,size_ng_d);
file_write("/tmp/ng-dh.wav",audio_buf_ng_dh,size_ng_dh);
file_write("/tmp/ng-eh.wav",audio_buf_ng_eh,size_ng_eh);
file_write("/tmp/ng-er.wav",audio_buf_ng_er,size_ng_er);
file_write("/tmp/ng-ey.wav",audio_buf_ng_ey,size_ng_ey);
file_write("/tmp/ng-f.wav",audio_buf_ng_f,size_ng_f);
file_write("/tmp/ng-g.wav",audio_buf_ng_g,size_ng_g);
file_write("/tmp/ng-hh.wav",audio_buf_ng_hh,size_ng_hh);
file_write("/tmp/ng-ih.wav",audio_buf_ng_ih,size_ng_ih);
file_write("/tmp/ng-iy.wav",audio_buf_ng_iy,size_ng_iy);
file_write("/tmp/ng-jh.wav",audio_buf_ng_jh,size_ng_jh);
file_write("/tmp/ng-k.wav",audio_buf_ng_k,size_ng_k);
file_write("/tmp/ng-l.wav",audio_buf_ng_l,size_ng_l);
file_write("/tmp/ng-m.wav",audio_buf_ng_m,size_ng_m);
file_write("/tmp/ng-n.wav",audio_buf_ng_n,size_ng_n);
file_write("/tmp/ng-ow.wav",audio_buf_ng_ow,size_ng_ow);
file_write("/tmp/ng-oy.wav",audio_buf_ng_oy,size_ng_oy);
file_write("/tmp/ng-p.wav",audio_buf_ng_p,size_ng_p);
file_write("/tmp/ng-pau.wav",audio_buf_ng_pau,size_ng_pau);
file_write("/tmp/ng-r.wav",audio_buf_ng_r,size_ng_r);
file_write("/tmp/ng-s.wav",audio_buf_ng_s,size_ng_s);
file_write("/tmp/ng-sh.wav",audio_buf_ng_sh,size_ng_sh);
file_write("/tmp/ng-t.wav",audio_buf_ng_t,size_ng_t);
file_write("/tmp/ng-th.wav",audio_buf_ng_th,size_ng_th);
file_write("/tmp/ng-uh.wav",audio_buf_ng_uh,size_ng_uh);
file_write("/tmp/ng-uw.wav",audio_buf_ng_uw,size_ng_uw);
file_write("/tmp/ng-v.wav",audio_buf_ng_v,size_ng_v);
file_write("/tmp/ng-w.wav",audio_buf_ng_w,size_ng_w);
file_write("/tmp/ng-y.wav",audio_buf_ng_y,size_ng_y);
file_write("/tmp/ng-z.wav",audio_buf_ng_z,size_ng_z);
file_write("/tmp/ng-zh.wav",audio_buf_ng_zh,size_ng_zh);

//ow diphones  
unsigned  long * audio_buf_ow_aa = ( unsigned  long *)&_binary_ow_aa_wav_start; 
unsigned long size_ow_aa = ( unsigned long )&_binary_ow_aa_wav_size;
unsigned  long * audio_buf_ow_ae = ( unsigned  long *)&_binary_ow_ae_wav_start;
unsigned long size_ow_ae = ( unsigned long )&_binary_ow_ae_wav_size;
unsigned  long * audio_buf_ow_ah = ( unsigned  long *)&_binary_ow_ah_wav_start;
unsigned long size_ow_ah = ( unsigned long )&_binary_ow_ah_wav_size;
unsigned  long * audio_buf_ow_ao = ( unsigned  long *)&_binary_ow_ao_wav_start;
unsigned long size_ow_ao = ( unsigned long )&_binary_ow_ao_wav_size;
unsigned  long * audio_buf_ow_aw = ( unsigned  long *)&_binary_ow_aw_wav_start;
unsigned long size_ow_aw = ( unsigned long )&_binary_ow_aw_wav_size;
unsigned  long * audio_buf_ow_ax = ( unsigned  long *)&_binary_ow_ax_wav_start;
unsigned long size_ow_ax = ( unsigned long )&_binary_ow_ax_wav_size;
unsigned  long * audio_buf_ow_ay = ( unsigned  long *)&_binary_ow_ay_wav_start;
unsigned long size_ow_ay = ( unsigned long )&_binary_ow_ay_wav_size;
unsigned  long * audio_buf_ow_b = ( unsigned  long *)&_binary_ow_b_wav_start;
unsigned long size_ow_b = ( unsigned long )&_binary_ow_b_wav_size;
unsigned  long * audio_buf_ow_ch = ( unsigned  long *)&_binary_ow_ch_wav_start;
unsigned long size_ow_ch = ( unsigned long )&_binary_ow_ch_wav_size;
unsigned  long * audio_buf_ow_d = ( unsigned  long *)&_binary_ow_d_wav_start;
unsigned long size_ow_d = ( unsigned long )&_binary_ow_d_wav_size;
unsigned  long * audio_buf_ow_dh = ( unsigned  long *)&_binary_ow_dh_wav_start;
unsigned long size_ow_dh = ( unsigned long )&_binary_ow_dh_wav_size;
unsigned  long * audio_buf_ow_eh = ( unsigned  long *)&_binary_ow_eh_wav_start;
unsigned long size_ow_eh = ( unsigned long )&_binary_ow_eh_wav_size;
unsigned  long * audio_buf_ow_er = ( unsigned  long *)&_binary_ow_er_wav_start;
unsigned long size_ow_er = ( unsigned long )&_binary_ow_er_wav_size;
unsigned  long * audio_buf_ow_ey = ( unsigned  long *)&_binary_ow_ey_wav_start;
unsigned long size_ow_ey = ( unsigned long )&_binary_ow_ey_wav_size;
unsigned  long * audio_buf_ow_f = ( unsigned  long *)&_binary_ow_f_wav_start;
unsigned long size_ow_f = ( unsigned long )&_binary_ow_f_wav_size;
unsigned  long * audio_buf_ow_g = ( unsigned  long *)&_binary_ow_g_wav_start;
unsigned long size_ow_g = ( unsigned long )&_binary_ow_g_wav_size;
unsigned  long * audio_buf_ow_hh = ( unsigned  long *)&_binary_ow_hh_wav_start;
unsigned long size_ow_hh = ( unsigned long )&_binary_ow_hh_wav_size;
unsigned  long * audio_buf_ow_ih = ( unsigned  long *)&_binary_ow_ih_wav_start;
unsigned long size_ow_ih = ( unsigned long )&_binary_ow_ih_wav_size;
unsigned  long * audio_buf_ow_iy = ( unsigned  long *)&_binary_ow_iy_wav_start;
unsigned long size_ow_iy = ( unsigned long )&_binary_ow_iy_wav_size;
unsigned  long * audio_buf_ow_jh = ( unsigned  long *)&_binary_ow_jh_wav_start;
unsigned long size_ow_jh = ( unsigned long )&_binary_ow_jh_wav_size;
unsigned  long * audio_buf_ow_k = ( unsigned  long *)&_binary_ow_k_wav_start;
unsigned long size_ow_k = ( unsigned long )&_binary_ow_k_wav_size;
unsigned  long * audio_buf_ow_l = ( unsigned  long *)&_binary_ow_l_wav_start;
unsigned long size_ow_l = ( unsigned long )&_binary_ow_l_wav_size;
unsigned  long * audio_buf_ow_m = ( unsigned  long *)&_binary_ow_m_wav_start;
unsigned long size_ow_m = ( unsigned long )&_binary_ow_m_wav_size;
unsigned  long * audio_buf_ow_n = ( unsigned  long *)&_binary_ow_n_wav_start;
unsigned long size_ow_n = ( unsigned long )&_binary_ow_n_wav_size;
unsigned  long * audio_buf_ow_ng = ( unsigned  long *)&_binary_ow_ng_wav_start;
unsigned long size_ow_ng = ( unsigned long )&_binary_ow_ng_wav_size;
unsigned  long * audio_buf_ow_ow = ( unsigned  long *)&_binary_ow_ow_wav_start;
unsigned long size_ow_ow = ( unsigned long )&_binary_ow_ow_wav_size;
unsigned  long * audio_buf_ow_oy = ( unsigned  long *)&_binary_ow_oy_wav_start;
unsigned long size_ow_oy = ( unsigned long )&_binary_ow_oy_wav_size;
unsigned  long * audio_buf_ow_p = ( unsigned  long *)&_binary_ow_p_wav_start;
unsigned long size_ow_p = ( unsigned long )&_binary_ow_p_wav_size;
unsigned  long * audio_buf_ow_pau = ( unsigned  long *)&_binary_ow_pau_wav_start;
unsigned long size_ow_pau = ( unsigned long )&_binary_ow_pau_wav_size;
unsigned  long * audio_buf_ow_r = ( unsigned  long *)&_binary_ow_r_wav_start;
unsigned long size_ow_r = ( unsigned long )&_binary_ow_r_wav_size;
unsigned  long * audio_buf_ow_s = ( unsigned  long *)&_binary_ow_s_wav_start;
unsigned long size_ow_s = ( unsigned long )&_binary_ow_s_wav_size;
unsigned  long * audio_buf_ow_sh = ( unsigned  long *)&_binary_ow_sh_wav_start;
unsigned long size_ow_sh = ( unsigned long )&_binary_ow_sh_wav_size;
unsigned  long * audio_buf_ow_t = ( unsigned  long *)&_binary_ow_t_wav_start;
unsigned long size_ow_t = ( unsigned long )&_binary_ow_t_wav_size;
unsigned  long * audio_buf_ow_th = ( unsigned  long *)&_binary_ow_th_wav_start;
unsigned long size_ow_th = ( unsigned long )&_binary_ow_th_wav_size;
unsigned  long * audio_buf_ow_uh = ( unsigned  long *)&_binary_ow_uh_wav_start;
unsigned long size_ow_uh = ( unsigned long )&_binary_ow_uh_wav_size;
unsigned  long * audio_buf_ow_uw = ( unsigned  long *)&_binary_ow_uw_wav_start;
unsigned long size_ow_uw = ( unsigned long )&_binary_ow_uw_wav_size;
unsigned  long * audio_buf_ow_v = ( unsigned  long *)&_binary_ow_v_wav_start;
unsigned long size_ow_v = ( unsigned long )&_binary_ow_v_wav_size;
unsigned  long * audio_buf_ow_w = ( unsigned  long *)&_binary_ow_w_wav_start;
unsigned long size_ow_w = ( unsigned long )&_binary_ow_w_wav_size;
unsigned  long * audio_buf_ow_y = ( unsigned  long *)&_binary_ow_y_wav_start;
unsigned long size_ow_y = ( unsigned long )&_binary_ow_y_wav_size;
unsigned  long * audio_buf_ow_z = ( unsigned  long *)&_binary_ow_z_wav_start;
unsigned long size_ow_z = ( unsigned long )&_binary_ow_z_wav_size;
unsigned  long * audio_buf_ow_zh = ( unsigned  long *)&_binary_ow_zh_wav_start;
unsigned long size_ow_zh = ( unsigned long )&_binary_ow_zh_wav_size;
//ow diphones
file_write("/tmp/ow-aa.wav",audio_buf_ow_aa,size_ow_aa);
file_write("/tmp/ow-ae.wav",audio_buf_ow_ae,size_ow_ae);
file_write("/tmp/ow-ah.wav",audio_buf_ow_ah,size_ow_ah);
file_write("/tmp/ow-ao.wav",audio_buf_ow_ao,size_ow_ao);
file_write("/tmp/ow-aw.wav",audio_buf_ow_aw,size_ow_aw);
file_write("/tmp/ow-ax.wav",audio_buf_ow_ax,size_ow_ax);
file_write("/tmp/ow-ay.wav",audio_buf_ow_ay,size_ow_ay);
file_write("/tmp/ow-b.wav",audio_buf_ow_b,size_ow_b);
file_write("/tmp/ow-ch.wav",audio_buf_ow_ch,size_ow_ch);
file_write("/tmp/ow-d.wav",audio_buf_ow_d,size_ow_d);
file_write("/tmp/ow-dh.wav",audio_buf_ow_dh,size_ow_dh);
file_write("/tmp/ow-eh.wav",audio_buf_ow_eh,size_ow_eh);
file_write("/tmp/ow-er.wav",audio_buf_ow_er,size_ow_er);
file_write("/tmp/ow-ey.wav",audio_buf_ow_ey,size_ow_ey);
file_write("/tmp/ow-f.wav",audio_buf_ow_f,size_ow_f);
file_write("/tmp/ow-g.wav",audio_buf_ow_g,size_ow_g);
file_write("/tmp/ow-hh.wav",audio_buf_ow_hh,size_ow_hh);
file_write("/tmp/ow-ih.wav",audio_buf_ow_ih,size_ow_ih);
file_write("/tmp/ow-iy.wav",audio_buf_ow_iy,size_ow_iy);
file_write("/tmp/ow-jh.wav",audio_buf_ow_jh,size_ow_jh);
file_write("/tmp/ow-k.wav",audio_buf_ow_k,size_ow_k);
file_write("/tmp/ow-l.wav",audio_buf_ow_l,size_ow_l);
file_write("/tmp/ow-m.wav",audio_buf_ow_m,size_ow_m);
file_write("/tmp/ow-n.wav",audio_buf_ow_n,size_ow_n);
file_write("/tmp/ow-ng.wav",audio_buf_ow_ng,size_ow_ng);
file_write("/tmp/ow-ow.wav",audio_buf_ow_ow,size_ow_ow);
file_write("/tmp/ow-oy.wav",audio_buf_ow_oy,size_ow_oy);
file_write("/tmp/ow-p.wav",audio_buf_ow_p,size_ow_p);
file_write("/tmp/ow-pau.wav",audio_buf_ow_pau,size_ow_pau);
file_write("/tmp/ow-r.wav",audio_buf_ow_r,size_ow_r);
file_write("/tmp/ow-s.wav",audio_buf_ow_s,size_ow_s);
file_write("/tmp/ow-sh.wav",audio_buf_ow_sh,size_ow_sh);
file_write("/tmp/ow-t.wav",audio_buf_ow_t,size_ow_t);
file_write("/tmp/ow-th.wav",audio_buf_ow_th,size_ow_th);
file_write("/tmp/ow-uh.wav",audio_buf_ow_uh,size_ow_uh);
file_write("/tmp/ow-uw.wav",audio_buf_ow_uw,size_ow_uw);
file_write("/tmp/ow-v.wav",audio_buf_ow_v,size_ow_v);
file_write("/tmp/ow-w.wav",audio_buf_ow_w,size_ow_w);
file_write("/tmp/ow-y.wav",audio_buf_ow_y,size_ow_y);
file_write("/tmp/ow-z.wav",audio_buf_ow_z,size_ow_z);
file_write("/tmp/ow-zh.wav",audio_buf_ow_zh,size_ow_zh);

//oy diphones  
unsigned  long * audio_buf_oy_aa = ( unsigned  long *)&_binary_oy_aa_wav_start; 
unsigned long size_oy_aa = ( unsigned long )&_binary_oy_aa_wav_size;
unsigned  long * audio_buf_oy_ae = ( unsigned  long *)&_binary_oy_ae_wav_start;
unsigned long size_oy_ae = ( unsigned long )&_binary_oy_ae_wav_size;
unsigned  long * audio_buf_oy_ah = ( unsigned  long *)&_binary_oy_ah_wav_start;
unsigned long size_oy_ah = ( unsigned long )&_binary_oy_ah_wav_size;
unsigned  long * audio_buf_oy_ao = ( unsigned  long *)&_binary_oy_ao_wav_start;
unsigned long size_oy_ao = ( unsigned long )&_binary_oy_ao_wav_size;
unsigned  long * audio_buf_oy_aw = ( unsigned  long *)&_binary_oy_aw_wav_start;
unsigned long size_oy_aw = ( unsigned long )&_binary_oy_aw_wav_size;
unsigned  long * audio_buf_oy_ax = ( unsigned  long *)&_binary_oy_ax_wav_start;
unsigned long size_oy_ax = ( unsigned long )&_binary_oy_ax_wav_size;
unsigned  long * audio_buf_oy_ay = ( unsigned  long *)&_binary_oy_ay_wav_start;
unsigned long size_oy_ay = ( unsigned long )&_binary_oy_ay_wav_size;
unsigned  long * audio_buf_oy_b = ( unsigned  long *)&_binary_oy_b_wav_start;
unsigned long size_oy_b = ( unsigned long )&_binary_oy_b_wav_size;
unsigned  long * audio_buf_oy_ch = ( unsigned  long *)&_binary_oy_ch_wav_start;
unsigned long size_oy_ch = ( unsigned long )&_binary_oy_ch_wav_size;
unsigned  long * audio_buf_oy_d = ( unsigned  long *)&_binary_oy_d_wav_start;
unsigned long size_oy_d = ( unsigned long )&_binary_oy_d_wav_size;
unsigned  long * audio_buf_oy_dh = ( unsigned  long *)&_binary_oy_dh_wav_start;
unsigned long size_oy_dh = ( unsigned long )&_binary_oy_dh_wav_size;
unsigned  long * audio_buf_oy_eh = ( unsigned  long *)&_binary_oy_eh_wav_start;
unsigned long size_oy_eh = ( unsigned long )&_binary_oy_eh_wav_size;
unsigned  long * audio_buf_oy_er = ( unsigned  long *)&_binary_oy_er_wav_start;
unsigned long size_oy_er = ( unsigned long )&_binary_oy_er_wav_size;
unsigned  long * audio_buf_oy_ey = ( unsigned  long *)&_binary_oy_ey_wav_start;
unsigned long size_oy_ey = ( unsigned long )&_binary_oy_ey_wav_size;
unsigned  long * audio_buf_oy_f = ( unsigned  long *)&_binary_oy_f_wav_start;
unsigned long size_oy_f = ( unsigned long )&_binary_oy_f_wav_size;
unsigned  long * audio_buf_oy_g = ( unsigned  long *)&_binary_oy_g_wav_start;
unsigned long size_oy_g = ( unsigned long )&_binary_oy_g_wav_size;
unsigned  long * audio_buf_oy_hh = ( unsigned  long *)&_binary_oy_hh_wav_start;
unsigned long size_oy_hh = ( unsigned long )&_binary_oy_hh_wav_size;
unsigned  long * audio_buf_oy_ih = ( unsigned  long *)&_binary_oy_ih_wav_start;
unsigned long size_oy_ih = ( unsigned long )&_binary_oy_ih_wav_size;
unsigned  long * audio_buf_oy_iy = ( unsigned  long *)&_binary_oy_iy_wav_start;
unsigned long size_oy_iy = ( unsigned long )&_binary_oy_iy_wav_size;
unsigned  long * audio_buf_oy_jh = ( unsigned  long *)&_binary_oy_jh_wav_start;
unsigned long size_oy_jh = ( unsigned long )&_binary_oy_jh_wav_size;
unsigned  long * audio_buf_oy_k = ( unsigned  long *)&_binary_oy_k_wav_start;
unsigned long size_oy_k = ( unsigned long )&_binary_oy_k_wav_size;
unsigned  long * audio_buf_oy_l = ( unsigned  long *)&_binary_oy_l_wav_start;
unsigned long size_oy_l = ( unsigned long )&_binary_oy_l_wav_size;
unsigned  long * audio_buf_oy_m = ( unsigned  long *)&_binary_oy_m_wav_start;
unsigned long size_oy_m = ( unsigned long )&_binary_oy_m_wav_size;
unsigned  long * audio_buf_oy_n = ( unsigned  long *)&_binary_oy_n_wav_start;
unsigned long size_oy_n = ( unsigned long )&_binary_oy_n_wav_size;
unsigned  long * audio_buf_oy_ng = ( unsigned  long *)&_binary_oy_ng_wav_start;
unsigned long size_oy_ng = ( unsigned long )&_binary_oy_ng_wav_size;
unsigned  long * audio_buf_oy_ow = ( unsigned  long *)&_binary_oy_ow_wav_start;
unsigned long size_oy_ow = ( unsigned long )&_binary_oy_ow_wav_size;
unsigned  long * audio_buf_oy_oy = ( unsigned  long *)&_binary_oy_oy_wav_start;
unsigned long size_oy_oy = ( unsigned long )&_binary_oy_oy_wav_size;
unsigned  long * audio_buf_oy_p = ( unsigned  long *)&_binary_oy_p_wav_start;
unsigned long size_oy_p = ( unsigned long )&_binary_oy_p_wav_size;
unsigned  long * audio_buf_oy_pau = ( unsigned  long *)&_binary_oy_pau_wav_start;
unsigned long size_oy_pau = ( unsigned long )&_binary_oy_pau_wav_size;
unsigned  long * audio_buf_oy_r = ( unsigned  long *)&_binary_oy_r_wav_start;
unsigned long size_oy_r = ( unsigned long )&_binary_oy_r_wav_size;
unsigned  long * audio_buf_oy_s = ( unsigned  long *)&_binary_oy_s_wav_start;
unsigned long size_oy_s = ( unsigned long )&_binary_oy_s_wav_size;
unsigned  long * audio_buf_oy_sh = ( unsigned  long *)&_binary_oy_sh_wav_start;
unsigned long size_oy_sh = ( unsigned long )&_binary_oy_sh_wav_size;
unsigned  long * audio_buf_oy_t = ( unsigned  long *)&_binary_oy_t_wav_start;
unsigned long size_oy_t = ( unsigned long )&_binary_oy_t_wav_size;
unsigned  long * audio_buf_oy_th = ( unsigned  long *)&_binary_oy_th_wav_start;
unsigned long size_oy_th = ( unsigned long )&_binary_oy_th_wav_size;
unsigned  long * audio_buf_oy_uh = ( unsigned  long *)&_binary_oy_uh_wav_start;
unsigned long size_oy_uh = ( unsigned long )&_binary_oy_uh_wav_size;
unsigned  long * audio_buf_oy_uw = ( unsigned  long *)&_binary_oy_uw_wav_start;
unsigned long size_oy_uw = ( unsigned long )&_binary_oy_uw_wav_size;
unsigned  long * audio_buf_oy_v = ( unsigned  long *)&_binary_oy_v_wav_start;
unsigned long size_oy_v = ( unsigned long )&_binary_oy_v_wav_size;
unsigned  long * audio_buf_oy_w = ( unsigned  long *)&_binary_oy_w_wav_start;
unsigned long size_oy_w = ( unsigned long )&_binary_oy_w_wav_size;
unsigned  long * audio_buf_oy_y = ( unsigned  long *)&_binary_oy_y_wav_start;
unsigned long size_oy_y = ( unsigned long )&_binary_oy_y_wav_size;
unsigned  long * audio_buf_oy_z = ( unsigned  long *)&_binary_oy_z_wav_start;
unsigned long size_oy_z = ( unsigned long )&_binary_oy_z_wav_size;
unsigned  long * audio_buf_oy_zh = ( unsigned  long *)&_binary_oy_zh_wav_start;
unsigned long size_oy_zh = ( unsigned long )&_binary_oy_zh_wav_size;
//oy diphones
file_write("/tmp/oy-aa.wav",audio_buf_oy_aa,size_oy_aa);
file_write("/tmp/oy-ae.wav",audio_buf_oy_ae,size_oy_ae);
file_write("/tmp/oy-ah.wav",audio_buf_oy_ah,size_oy_ah);
file_write("/tmp/oy-ao.wav",audio_buf_oy_ao,size_oy_ao);
file_write("/tmp/oy-aw.wav",audio_buf_oy_aw,size_oy_aw);
file_write("/tmp/oy-ax.wav",audio_buf_oy_ax,size_oy_ax);
file_write("/tmp/oy-ay.wav",audio_buf_oy_ay,size_oy_ay);
file_write("/tmp/oy-b.wav",audio_buf_oy_b,size_oy_b);
file_write("/tmp/oy-ch.wav",audio_buf_oy_ch,size_oy_ch);
file_write("/tmp/oy-d.wav",audio_buf_oy_d,size_oy_d);
file_write("/tmp/oy-dh.wav",audio_buf_oy_dh,size_oy_dh);
file_write("/tmp/oy-eh.wav",audio_buf_oy_eh,size_oy_eh);
file_write("/tmp/oy-er.wav",audio_buf_oy_er,size_oy_er);
file_write("/tmp/oy-ey.wav",audio_buf_oy_ey,size_oy_ey);
file_write("/tmp/oy-f.wav",audio_buf_oy_f,size_oy_f);
file_write("/tmp/oy-g.wav",audio_buf_oy_g,size_oy_g);
file_write("/tmp/oy-hh.wav",audio_buf_oy_hh,size_oy_hh);
file_write("/tmp/oy-ih.wav",audio_buf_oy_ih,size_oy_ih);
file_write("/tmp/oy-iy.wav",audio_buf_oy_iy,size_oy_iy);
file_write("/tmp/oy-jh.wav",audio_buf_oy_jh,size_oy_jh);
file_write("/tmp/oy-k.wav",audio_buf_oy_k,size_oy_k);
file_write("/tmp/oy-l.wav",audio_buf_oy_l,size_oy_l);
file_write("/tmp/oy-m.wav",audio_buf_oy_m,size_oy_m);
file_write("/tmp/oy-n.wav",audio_buf_oy_n,size_oy_n);
file_write("/tmp/oy-ng.wav",audio_buf_oy_ng,size_oy_ng);
file_write("/tmp/oy-ow.wav",audio_buf_oy_ow,size_oy_ow);
file_write("/tmp/oy-oy.wav",audio_buf_oy_oy,size_oy_oy);
file_write("/tmp/oy-p.wav",audio_buf_oy_p,size_oy_p);
file_write("/tmp/oy-pau.wav",audio_buf_oy_pau,size_oy_pau);
file_write("/tmp/oy-r.wav",audio_buf_oy_r,size_oy_r);
file_write("/tmp/oy-s.wav",audio_buf_oy_s,size_oy_s);
file_write("/tmp/oy-sh.wav",audio_buf_oy_sh,size_oy_sh);
file_write("/tmp/oy-t.wav",audio_buf_oy_t,size_oy_t);
file_write("/tmp/oy-th.wav",audio_buf_oy_th,size_oy_th);
file_write("/tmp/oy-uh.wav",audio_buf_oy_uh,size_oy_uh);
file_write("/tmp/oy-uw.wav",audio_buf_oy_uw,size_oy_uw);
file_write("/tmp/oy-v.wav",audio_buf_oy_v,size_oy_v);
file_write("/tmp/oy-w.wav",audio_buf_oy_w,size_oy_w);
file_write("/tmp/oy-y.wav",audio_buf_oy_y,size_oy_y);
file_write("/tmp/oy-z.wav",audio_buf_oy_z,size_oy_z);
file_write("/tmp/oy-zh.wav",audio_buf_oy_zh,size_oy_zh);

//p diphones  
unsigned  long * audio_buf_p_aa = ( unsigned  long *)&_binary_p_aa_wav_start; 
unsigned long size_p_aa = ( unsigned long )&_binary_p_aa_wav_size;
unsigned  long * audio_buf_p_ae = ( unsigned  long *)&_binary_p_ae_wav_start;
unsigned long size_p_ae = ( unsigned long )&_binary_p_ae_wav_size;
unsigned  long * audio_buf_p_ah = ( unsigned  long *)&_binary_p_ah_wav_start;
unsigned long size_p_ah = ( unsigned long )&_binary_p_ah_wav_size;
unsigned  long * audio_buf_p_ao = ( unsigned  long *)&_binary_p_ao_wav_start;
unsigned long size_p_ao = ( unsigned long )&_binary_p_ao_wav_size;
unsigned  long * audio_buf_p_aw = ( unsigned  long *)&_binary_p_aw_wav_start;
unsigned long size_p_aw = ( unsigned long )&_binary_p_aw_wav_size;
unsigned  long * audio_buf_p_ax = ( unsigned  long *)&_binary_p_ax_wav_start;
unsigned long size_p_ax = ( unsigned long )&_binary_p_ax_wav_size;
unsigned  long * audio_buf_p_ay = ( unsigned  long *)&_binary_p_ay_wav_start;
unsigned long size_p_ay = ( unsigned long )&_binary_p_ay_wav_size;
unsigned  long * audio_buf_p_b = ( unsigned  long *)&_binary_p_b_wav_start;
unsigned long size_p_b = ( unsigned long )&_binary_p_b_wav_size;
unsigned  long * audio_buf_p_ch = ( unsigned  long *)&_binary_p_ch_wav_start;
unsigned long size_p_ch = ( unsigned long )&_binary_p_ch_wav_size;
unsigned  long * audio_buf_p_d = ( unsigned  long *)&_binary_p_d_wav_start;
unsigned long size_p_d = ( unsigned long )&_binary_p_d_wav_size;
unsigned  long * audio_buf_p_dh = ( unsigned  long *)&_binary_p_dh_wav_start;
unsigned long size_p_dh = ( unsigned long )&_binary_p_dh_wav_size;
unsigned  long * audio_buf_p_eh = ( unsigned  long *)&_binary_p_eh_wav_start;
unsigned long size_p_eh = ( unsigned long )&_binary_p_eh_wav_size;
unsigned  long * audio_buf_p_er = ( unsigned  long *)&_binary_p_er_wav_start;
unsigned long size_p_er = ( unsigned long )&_binary_p_er_wav_size;
unsigned  long * audio_buf_p_ey = ( unsigned  long *)&_binary_p_ey_wav_start;
unsigned long size_p_ey = ( unsigned long )&_binary_p_ey_wav_size;
unsigned  long * audio_buf_p_f = ( unsigned  long *)&_binary_p_f_wav_start;
unsigned long size_p_f = ( unsigned long )&_binary_p_f_wav_size;
unsigned  long * audio_buf_p_g = ( unsigned  long *)&_binary_p_g_wav_start;
unsigned long size_p_g = ( unsigned long )&_binary_p_g_wav_size;
unsigned  long * audio_buf_p_hh = ( unsigned  long *)&_binary_p_hh_wav_start;
unsigned long size_p_hh = ( unsigned long )&_binary_p_hh_wav_size;
unsigned  long * audio_buf_p_ih = ( unsigned  long *)&_binary_p_ih_wav_start;
unsigned long size_p_ih = ( unsigned long )&_binary_p_ih_wav_size;
unsigned  long * audio_buf_p_iy = ( unsigned  long *)&_binary_p_iy_wav_start;
unsigned long size_p_iy = ( unsigned long )&_binary_p_iy_wav_size;
unsigned  long * audio_buf_p_jh = ( unsigned  long *)&_binary_p_jh_wav_start;
unsigned long size_p_jh = ( unsigned long )&_binary_p_jh_wav_size;
unsigned  long * audio_buf_p_k = ( unsigned  long *)&_binary_p_k_wav_start;
unsigned long size_p_k = ( unsigned long )&_binary_p_k_wav_size;
unsigned  long * audio_buf_p_l = ( unsigned  long *)&_binary_p_l_wav_start;
unsigned long size_p_l = ( unsigned long )&_binary_p_l_wav_size;
unsigned  long * audio_buf_p_m = ( unsigned  long *)&_binary_p_m_wav_start;
unsigned long size_p_m = ( unsigned long )&_binary_p_m_wav_size;
unsigned  long * audio_buf_p_n = ( unsigned  long *)&_binary_p_n_wav_start;
unsigned long size_p_n = ( unsigned long )&_binary_p_n_wav_size;
unsigned  long * audio_buf_p_ow = ( unsigned  long *)&_binary_p_ow_wav_start;
unsigned long size_p_ow = ( unsigned long )&_binary_p_ow_wav_size;
unsigned  long * audio_buf_p_oy = ( unsigned  long *)&_binary_p_oy_wav_start;
unsigned long size_p_oy = ( unsigned long )&_binary_p_oy_wav_size;
unsigned  long * audio_buf_p_p = ( unsigned  long *)&_binary_p_p_wav_start;
unsigned long size_p_p = ( unsigned long )&_binary_p_p_wav_size;
unsigned  long * audio_buf_p_pau = ( unsigned  long *)&_binary_p_pau_wav_start;
unsigned long size_p_pau = ( unsigned long )&_binary_p_pau_wav_size;
unsigned  long * audio_buf_p_r = ( unsigned  long *)&_binary_p_r_wav_start;
unsigned long size_p_r = ( unsigned long )&_binary_p_r_wav_size;
unsigned  long * audio_buf_p_s = ( unsigned  long *)&_binary_p_s_wav_start;
unsigned long size_p_s = ( unsigned long )&_binary_p_s_wav_size;
unsigned  long * audio_buf_p_sh = ( unsigned  long *)&_binary_p_sh_wav_start;
unsigned long size_p_sh = ( unsigned long )&_binary_p_sh_wav_size;
unsigned  long * audio_buf_p_t = ( unsigned  long *)&_binary_p_t_wav_start;
unsigned long size_p_t = ( unsigned long )&_binary_p_t_wav_size;
unsigned  long * audio_buf_p_th = ( unsigned  long *)&_binary_p_th_wav_start;
unsigned long size_p_th = ( unsigned long )&_binary_p_th_wav_size;
unsigned  long * audio_buf_p_uh = ( unsigned  long *)&_binary_p_uh_wav_start;
unsigned long size_p_uh = ( unsigned long )&_binary_p_uh_wav_size;
unsigned  long * audio_buf_p_uw = ( unsigned  long *)&_binary_p_uw_wav_start;
unsigned long size_p_uw = ( unsigned long )&_binary_p_uw_wav_size;
unsigned  long * audio_buf_p_v = ( unsigned  long *)&_binary_p_v_wav_start;
unsigned long size_p_v = ( unsigned long )&_binary_p_v_wav_size;
unsigned  long * audio_buf_p_w = ( unsigned  long *)&_binary_p_w_wav_start;
unsigned long size_p_w = ( unsigned long )&_binary_p_w_wav_size;
unsigned  long * audio_buf_p_y = ( unsigned  long *)&_binary_p_y_wav_start;
unsigned long size_p_y = ( unsigned long )&_binary_p_y_wav_size;
unsigned  long * audio_buf_p_z = ( unsigned  long *)&_binary_p_z_wav_start;
unsigned long size_p_z = ( unsigned long )&_binary_p_z_wav_size;
unsigned  long * audio_buf_p_zh = ( unsigned  long *)&_binary_p_zh_wav_start;
unsigned long size_p_zh = ( unsigned long )&_binary_p_zh_wav_size;
//p diphones
file_write("/tmp/p-aa.wav",audio_buf_p_aa,size_p_aa);
file_write("/tmp/p-ae.wav",audio_buf_p_ae,size_p_ae);
file_write("/tmp/p-ah.wav",audio_buf_p_ah,size_p_ah);
file_write("/tmp/p-ao.wav",audio_buf_p_ao,size_p_ao);
file_write("/tmp/p-aw.wav",audio_buf_p_aw,size_p_aw);
file_write("/tmp/p-ax.wav",audio_buf_p_ax,size_p_ax);
file_write("/tmp/p-ay.wav",audio_buf_p_ay,size_p_ay);
file_write("/tmp/p-b.wav",audio_buf_p_b,size_p_b);
file_write("/tmp/p-ch.wav",audio_buf_p_ch,size_p_ch);
file_write("/tmp/p-d.wav",audio_buf_p_d,size_p_d);
file_write("/tmp/p-dh.wav",audio_buf_p_dh,size_p_dh);
file_write("/tmp/p-eh.wav",audio_buf_p_eh,size_p_eh);
file_write("/tmp/p-er.wav",audio_buf_p_er,size_p_er);
file_write("/tmp/p-ey.wav",audio_buf_p_ey,size_p_ey);
file_write("/tmp/p-f.wav",audio_buf_p_f,size_p_f);
file_write("/tmp/p-g.wav",audio_buf_p_g,size_p_g);
file_write("/tmp/p-hh.wav",audio_buf_p_hh,size_p_hh);
file_write("/tmp/p-ih.wav",audio_buf_p_ih,size_p_ih);
file_write("/tmp/p-iy.wav",audio_buf_p_iy,size_p_iy);
file_write("/tmp/p-jh.wav",audio_buf_p_jh,size_p_jh);
file_write("/tmp/p-k.wav",audio_buf_p_k,size_p_k);
file_write("/tmp/p-l.wav",audio_buf_p_l,size_p_l);
file_write("/tmp/p-m.wav",audio_buf_p_m,size_p_m);
file_write("/tmp/p-n.wav",audio_buf_p_n,size_p_n);
file_write("/tmp/p-ow.wav",audio_buf_p_ow,size_p_ow);
file_write("/tmp/p-oy.wav",audio_buf_p_oy,size_p_oy);
file_write("/tmp/p-p.wav",audio_buf_p_p,size_p_p);
file_write("/tmp/p-pau.wav",audio_buf_p_pau,size_p_pau);
file_write("/tmp/p-r.wav",audio_buf_p_r,size_p_r);
file_write("/tmp/p-s.wav",audio_buf_p_s,size_p_s);
file_write("/tmp/p-sh.wav",audio_buf_p_sh,size_p_sh);
file_write("/tmp/p-t.wav",audio_buf_p_t,size_p_t);
file_write("/tmp/p-th.wav",audio_buf_p_th,size_p_th);
file_write("/tmp/p-uh.wav",audio_buf_p_uh,size_p_uh);
file_write("/tmp/p-uw.wav",audio_buf_p_uw,size_p_uw);
file_write("/tmp/p-v.wav",audio_buf_p_v,size_p_v);
file_write("/tmp/p-w.wav",audio_buf_p_w,size_p_w);
file_write("/tmp/p-y.wav",audio_buf_p_y,size_p_y);
file_write("/tmp/p-z.wav",audio_buf_p_z,size_p_z);
file_write("/tmp/p-zh.wav",audio_buf_p_zh,size_p_zh);

//pau diphones  
unsigned  long * audio_buf_pau_aa = ( unsigned  long *)&_binary_pau_aa_wav_start; 
unsigned long size_pau_aa = ( unsigned long )&_binary_pau_aa_wav_size;
unsigned  long * audio_buf_pau_ae = ( unsigned  long *)&_binary_pau_ae_wav_start;
unsigned long size_pau_ae = ( unsigned long )&_binary_pau_ae_wav_size;
unsigned  long * audio_buf_pau_ah = ( unsigned  long *)&_binary_pau_ah_wav_start;
unsigned long size_pau_ah = ( unsigned long )&_binary_pau_ah_wav_size;
unsigned  long * audio_buf_pau_ao = ( unsigned  long *)&_binary_pau_ao_wav_start;
unsigned long size_pau_ao = ( unsigned long )&_binary_pau_ao_wav_size;
unsigned  long * audio_buf_pau_aw = ( unsigned  long *)&_binary_pau_aw_wav_start;
unsigned long size_pau_aw = ( unsigned long )&_binary_pau_aw_wav_size;
unsigned  long * audio_buf_pau_ax = ( unsigned  long *)&_binary_pau_ax_wav_start;
unsigned long size_pau_ax = ( unsigned long )&_binary_pau_ax_wav_size;
unsigned  long * audio_buf_pau_ay = ( unsigned  long *)&_binary_pau_ay_wav_start;
unsigned long size_pau_ay = ( unsigned long )&_binary_pau_ay_wav_size;
unsigned  long * audio_buf_pau_b = ( unsigned  long *)&_binary_pau_b_wav_start;
unsigned long size_pau_b = ( unsigned long )&_binary_pau_b_wav_size;
unsigned  long * audio_buf_pau_ch = ( unsigned  long *)&_binary_pau_ch_wav_start;
unsigned long size_pau_ch = ( unsigned long )&_binary_pau_ch_wav_size;
unsigned  long * audio_buf_pau_d = ( unsigned  long *)&_binary_pau_d_wav_start;
unsigned long size_pau_d = ( unsigned long )&_binary_pau_d_wav_size;
unsigned  long * audio_buf_pau_dh = ( unsigned  long *)&_binary_pau_dh_wav_start;
unsigned long size_pau_dh = ( unsigned long )&_binary_pau_dh_wav_size;
unsigned  long * audio_buf_pau_eh = ( unsigned  long *)&_binary_pau_eh_wav_start;
unsigned long size_pau_eh = ( unsigned long )&_binary_pau_eh_wav_size;
unsigned  long * audio_buf_pau_er = ( unsigned  long *)&_binary_pau_er_wav_start;
unsigned long size_pau_er = ( unsigned long )&_binary_pau_er_wav_size;
unsigned  long * audio_buf_pau_ey = ( unsigned  long *)&_binary_pau_ey_wav_start;
unsigned long size_pau_ey = ( unsigned long )&_binary_pau_ey_wav_size;
unsigned  long * audio_buf_pau_f = ( unsigned  long *)&_binary_pau_f_wav_start;
unsigned long size_pau_f = ( unsigned long )&_binary_pau_f_wav_size;
unsigned  long * audio_buf_pau_g = ( unsigned  long *)&_binary_pau_g_wav_start;
unsigned long size_pau_g = ( unsigned long )&_binary_pau_g_wav_size;
unsigned  long * audio_buf_pau_hh = ( unsigned  long *)&_binary_pau_hh_wav_start;
unsigned long size_pau_hh = ( unsigned long )&_binary_pau_hh_wav_size;
unsigned  long * audio_buf_pau_ih = ( unsigned  long *)&_binary_pau_ih_wav_start;
unsigned long size_pau_ih = ( unsigned long )&_binary_pau_ih_wav_size;
unsigned  long * audio_buf_pau_iy = ( unsigned  long *)&_binary_pau_iy_wav_start;
unsigned long size_pau_iy = ( unsigned long )&_binary_pau_iy_wav_size;
unsigned  long * audio_buf_pau_jh = ( unsigned  long *)&_binary_pau_jh_wav_start;
unsigned long size_pau_jh = ( unsigned long )&_binary_pau_jh_wav_size;
unsigned  long * audio_buf_pau_k = ( unsigned  long *)&_binary_pau_k_wav_start;
unsigned long size_pau_k = ( unsigned long )&_binary_pau_k_wav_size;
unsigned  long * audio_buf_pau_l = ( unsigned  long *)&_binary_pau_l_wav_start;
unsigned long size_pau_l = ( unsigned long )&_binary_pau_l_wav_size;
unsigned  long * audio_buf_pau_m = ( unsigned  long *)&_binary_pau_m_wav_start;
unsigned long size_pau_m = ( unsigned long )&_binary_pau_m_wav_size;
unsigned  long * audio_buf_pau_n = ( unsigned  long *)&_binary_pau_n_wav_start;
unsigned long size_pau_n = ( unsigned long )&_binary_pau_n_wav_size;
unsigned  long * audio_buf_pau_ow = ( unsigned  long *)&_binary_pau_ow_wav_start;
unsigned long size_pau_ow = ( unsigned long )&_binary_pau_ow_wav_size;
unsigned  long * audio_buf_pau_oy = ( unsigned  long *)&_binary_pau_oy_wav_start;
unsigned long size_pau_oy = ( unsigned long )&_binary_pau_oy_wav_size;
unsigned  long * audio_buf_pau_p = ( unsigned  long *)&_binary_pau_p_wav_start;
unsigned long size_pau_p = ( unsigned long )&_binary_pau_p_wav_size;
unsigned  long * audio_buf_pau_pau = ( unsigned  long *)&_binary_pau_pau_wav_start;
unsigned long size_pau_pau = ( unsigned long )&_binary_pau_pau_wav_size;
unsigned  long * audio_buf_pau_r = ( unsigned  long *)&_binary_pau_r_wav_start;
unsigned long size_pau_r = ( unsigned long )&_binary_pau_r_wav_size;
unsigned  long * audio_buf_pau_s = ( unsigned  long *)&_binary_pau_s_wav_start;
unsigned long size_pau_s = ( unsigned long )&_binary_pau_s_wav_size;
unsigned  long * audio_buf_pau_sh = ( unsigned  long *)&_binary_pau_sh_wav_start;
unsigned long size_pau_sh = ( unsigned long )&_binary_pau_sh_wav_size;
unsigned  long * audio_buf_pau_t = ( unsigned  long *)&_binary_pau_t_wav_start;
unsigned long size_pau_t = ( unsigned long )&_binary_pau_t_wav_size;
unsigned  long * audio_buf_pau_th = ( unsigned  long *)&_binary_pau_th_wav_start;
unsigned long size_pau_th = ( unsigned long )&_binary_pau_th_wav_size;
unsigned  long * audio_buf_pau_uh = ( unsigned  long *)&_binary_pau_uh_wav_start;
unsigned long size_pau_uh = ( unsigned long )&_binary_pau_uh_wav_size;
unsigned  long * audio_buf_pau_uw = ( unsigned  long *)&_binary_pau_uw_wav_start;
unsigned long size_pau_uw = ( unsigned long )&_binary_pau_uw_wav_size;
unsigned  long * audio_buf_pau_v = ( unsigned  long *)&_binary_pau_v_wav_start;
unsigned long size_pau_v = ( unsigned long )&_binary_pau_v_wav_size;
unsigned  long * audio_buf_pau_w = ( unsigned  long *)&_binary_pau_w_wav_start;
unsigned long size_pau_w = ( unsigned long )&_binary_pau_w_wav_size;
unsigned  long * audio_buf_pau_y = ( unsigned  long *)&_binary_pau_y_wav_start;
unsigned long size_pau_y = ( unsigned long )&_binary_pau_y_wav_size;
unsigned  long * audio_buf_pau_z = ( unsigned  long *)&_binary_pau_z_wav_start;
unsigned long size_pau_z = ( unsigned long )&_binary_pau_z_wav_size;
unsigned  long * audio_buf_pau_zh = ( unsigned  long *)&_binary_pau_zh_wav_start;
unsigned long size_pau_zh = ( unsigned long )&_binary_pau_zh_wav_size;
//pau diphones
file_write("/tmp/pau-aa.wav",audio_buf_pau_aa,size_pau_aa);
file_write("/tmp/pau-ae.wav",audio_buf_pau_ae,size_pau_ae);
file_write("/tmp/pau-ah.wav",audio_buf_pau_ah,size_pau_ah);
file_write("/tmp/pau-ao.wav",audio_buf_pau_ao,size_pau_ao);
file_write("/tmp/pau-aw.wav",audio_buf_pau_aw,size_pau_aw);
file_write("/tmp/pau-ax.wav",audio_buf_pau_ax,size_pau_ax);
file_write("/tmp/pau-ay.wav",audio_buf_pau_ay,size_pau_ay);
file_write("/tmp/pau-b.wav",audio_buf_pau_b,size_pau_b);
file_write("/tmp/pau-ch.wav",audio_buf_pau_ch,size_pau_ch);
file_write("/tmp/pau-d.wav",audio_buf_pau_d,size_pau_d);
file_write("/tmp/pau-dh.wav",audio_buf_pau_dh,size_pau_dh);
file_write("/tmp/pau-eh.wav",audio_buf_pau_eh,size_pau_eh);
file_write("/tmp/pau-er.wav",audio_buf_pau_er,size_pau_er);
file_write("/tmp/pau-ey.wav",audio_buf_pau_ey,size_pau_ey);
file_write("/tmp/pau-f.wav",audio_buf_pau_f,size_pau_f);
file_write("/tmp/pau-g.wav",audio_buf_pau_g,size_pau_g);
file_write("/tmp/pau-hh.wav",audio_buf_pau_hh,size_pau_hh);
file_write("/tmp/pau-ih.wav",audio_buf_pau_ih,size_pau_ih);
file_write("/tmp/pau-iy.wav",audio_buf_pau_iy,size_pau_iy);
file_write("/tmp/pau-jh.wav",audio_buf_pau_jh,size_pau_jh);
file_write("/tmp/pau-k.wav",audio_buf_pau_k,size_pau_k);
file_write("/tmp/pau-l.wav",audio_buf_pau_l,size_pau_l);
file_write("/tmp/pau-m.wav",audio_buf_pau_m,size_pau_m);
file_write("/tmp/pau-n.wav",audio_buf_pau_n,size_pau_n);
file_write("/tmp/pau-ow.wav",audio_buf_pau_ow,size_pau_ow);
file_write("/tmp/pau-oy.wav",audio_buf_pau_oy,size_pau_oy);
file_write("/tmp/pau-p.wav",audio_buf_pau_p,size_pau_p);
file_write("/tmp/pau-pau.wav",audio_buf_pau_pau,size_pau_pau);
file_write("/tmp/pau-r.wav",audio_buf_pau_r,size_pau_r);
file_write("/tmp/pau-s.wav",audio_buf_pau_s,size_pau_s);
file_write("/tmp/pau-sh.wav",audio_buf_pau_sh,size_pau_sh);
file_write("/tmp/pau-t.wav",audio_buf_pau_t,size_pau_t);
file_write("/tmp/pau-th.wav",audio_buf_pau_th,size_pau_th);
file_write("/tmp/pau-uh.wav",audio_buf_pau_uh,size_pau_uh);
file_write("/tmp/pau-uw.wav",audio_buf_pau_uw,size_pau_uw);
file_write("/tmp/pau-v.wav",audio_buf_pau_v,size_pau_v);
file_write("/tmp/pau-w.wav",audio_buf_pau_w,size_pau_w);
file_write("/tmp/pau-y.wav",audio_buf_pau_y,size_pau_y);
file_write("/tmp/pau-z.wav",audio_buf_pau_z,size_pau_z);
file_write("/tmp/pau-zh.wav",audio_buf_pau_zh,size_pau_zh);

//r diphones  
unsigned  long * audio_buf_r_aa = ( unsigned  long *)&_binary_r_r_wav_start; 
unsigned long size_r_aa = ( unsigned long )&_binary_r_r_wav_size;
unsigned  long * audio_buf_r_ae = ( unsigned  long *)&_binary_r_ae_wav_start;
unsigned long size_r_ae = ( unsigned long )&_binary_r_ae_wav_size;
unsigned  long * audio_buf_r_ah = ( unsigned  long *)&_binary_r_ah_wav_start;
unsigned long size_r_ah = ( unsigned long )&_binary_r_ah_wav_size;
unsigned  long * audio_buf_r_ao = ( unsigned  long *)&_binary_r_ao_wav_start;
unsigned long size_r_ao = ( unsigned long )&_binary_r_ao_wav_size;
unsigned  long * audio_buf_r_aw = ( unsigned  long *)&_binary_r_aw_wav_start;
unsigned long size_r_aw = ( unsigned long )&_binary_r_aw_wav_size;
unsigned  long * audio_buf_r_ax = ( unsigned  long *)&_binary_r_ax_wav_start;
unsigned long size_r_ax = ( unsigned long )&_binary_r_ax_wav_size;
unsigned  long * audio_buf_r_ay = ( unsigned  long *)&_binary_r_ay_wav_start;
unsigned long size_r_ay = ( unsigned long )&_binary_r_ay_wav_size;
unsigned  long * audio_buf_r_b = ( unsigned  long *)&_binary_r_b_wav_start;
unsigned long size_r_b = ( unsigned long )&_binary_r_b_wav_size;
unsigned  long * audio_buf_r_ch = ( unsigned  long *)&_binary_r_ch_wav_start;
unsigned long size_r_ch = ( unsigned long )&_binary_r_ch_wav_size;
unsigned  long * audio_buf_r_d = ( unsigned  long *)&_binary_r_d_wav_start;
unsigned long size_r_d = ( unsigned long )&_binary_r_d_wav_size;
unsigned  long * audio_buf_r_dh = ( unsigned  long *)&_binary_r_dh_wav_start;
unsigned long size_r_dh = ( unsigned long )&_binary_r_dh_wav_size;
unsigned  long * audio_buf_r_eh = ( unsigned  long *)&_binary_r_eh_wav_start;
unsigned long size_r_eh = ( unsigned long )&_binary_r_eh_wav_size;
unsigned  long * audio_buf_r_er = ( unsigned  long *)&_binary_r_er_wav_start;
unsigned long size_r_er = ( unsigned long )&_binary_r_er_wav_size;
unsigned  long * audio_buf_r_ey = ( unsigned  long *)&_binary_r_ey_wav_start;
unsigned long size_r_ey = ( unsigned long )&_binary_r_ey_wav_size;
unsigned  long * audio_buf_r_f = ( unsigned  long *)&_binary_r_f_wav_start;
unsigned long size_r_f = ( unsigned long )&_binary_r_f_wav_size;
unsigned  long * audio_buf_r_g = ( unsigned  long *)&_binary_r_g_wav_start;
unsigned long size_r_g = ( unsigned long )&_binary_r_g_wav_size;
unsigned  long * audio_buf_r_hh = ( unsigned  long *)&_binary_r_hh_wav_start;
unsigned long size_r_hh = ( unsigned long )&_binary_r_hh_wav_size;
unsigned  long * audio_buf_r_ih = ( unsigned  long *)&_binary_r_ih_wav_start;
unsigned long size_r_ih = ( unsigned long )&_binary_r_ih_wav_size;
unsigned  long * audio_buf_r_iy = ( unsigned  long *)&_binary_r_iy_wav_start;
unsigned long size_r_iy = ( unsigned long )&_binary_r_iy_wav_size;
unsigned  long * audio_buf_r_jh = ( unsigned  long *)&_binary_r_jh_wav_start;
unsigned long size_r_jh = ( unsigned long )&_binary_r_jh_wav_size;
unsigned  long * audio_buf_r_k = ( unsigned  long *)&_binary_r_k_wav_start;
unsigned long size_r_k = ( unsigned long )&_binary_r_k_wav_size;
unsigned  long * audio_buf_r_l = ( unsigned  long *)&_binary_r_l_wav_start;
unsigned long size_r_l = ( unsigned long )&_binary_r_l_wav_size;
unsigned  long * audio_buf_r_m = ( unsigned  long *)&_binary_r_m_wav_start;
unsigned long size_r_m = ( unsigned long )&_binary_r_m_wav_size;
unsigned  long * audio_buf_r_n = ( unsigned  long *)&_binary_r_n_wav_start;
unsigned long size_r_n = ( unsigned long )&_binary_r_n_wav_size;
unsigned  long * audio_buf_r_ow = ( unsigned  long *)&_binary_r_ow_wav_start;
unsigned long size_r_ow = ( unsigned long )&_binary_r_ow_wav_size;
unsigned  long * audio_buf_r_oy = ( unsigned  long *)&_binary_r_oy_wav_start;
unsigned long size_r_oy = ( unsigned long )&_binary_r_oy_wav_size;
unsigned  long * audio_buf_r_p = ( unsigned  long *)&_binary_r_p_wav_start;
unsigned long size_r_p = ( unsigned long )&_binary_r_p_wav_size;
unsigned  long * audio_buf_r_pau = ( unsigned  long *)&_binary_r_pau_wav_start;
unsigned long size_r_pau = ( unsigned long )&_binary_r_pau_wav_size;
unsigned  long * audio_buf_r_r = ( unsigned  long *)&_binary_r_r_wav_start;
unsigned long size_r_r = ( unsigned long )&_binary_r_r_wav_size;
unsigned  long * audio_buf_r_s = ( unsigned  long *)&_binary_r_s_wav_start;
unsigned long size_r_s = ( unsigned long )&_binary_r_s_wav_size;
unsigned  long * audio_buf_r_sh = ( unsigned  long *)&_binary_r_sh_wav_start;
unsigned long size_r_sh = ( unsigned long )&_binary_r_sh_wav_size;
unsigned  long * audio_buf_r_t = ( unsigned  long *)&_binary_r_t_wav_start;
unsigned long size_r_t = ( unsigned long )&_binary_r_t_wav_size;
unsigned  long * audio_buf_r_th = ( unsigned  long *)&_binary_r_th_wav_start;
unsigned long size_r_th = ( unsigned long )&_binary_r_th_wav_size;
unsigned  long * audio_buf_r_uh = ( unsigned  long *)&_binary_r_uh_wav_start;
unsigned long size_r_uh = ( unsigned long )&_binary_r_uh_wav_size;
unsigned  long * audio_buf_r_uw = ( unsigned  long *)&_binary_r_uw_wav_start;
unsigned long size_r_uw = ( unsigned long )&_binary_r_uw_wav_size;
unsigned  long * audio_buf_r_v = ( unsigned  long *)&_binary_r_v_wav_start;
unsigned long size_r_v = ( unsigned long )&_binary_r_v_wav_size;
unsigned  long * audio_buf_r_w = ( unsigned  long *)&_binary_r_w_wav_start;
unsigned long size_r_w = ( unsigned long )&_binary_r_w_wav_size;
unsigned  long * audio_buf_r_y = ( unsigned  long *)&_binary_r_y_wav_start;
unsigned long size_r_y = ( unsigned long )&_binary_r_y_wav_size;
unsigned  long * audio_buf_r_z = ( unsigned  long *)&_binary_r_z_wav_start;
unsigned long size_r_z = ( unsigned long )&_binary_r_z_wav_size;
unsigned  long * audio_buf_r_zh = ( unsigned  long *)&_binary_r_zh_wav_start;
unsigned long size_r_zh = ( unsigned long )&_binary_r_zh_wav_size;
//r diphones
file_write("/tmp/r-aa.wav",audio_buf_r_aa,size_r_aa);
file_write("/tmp/r-ae.wav",audio_buf_r_ae,size_r_ae);
file_write("/tmp/r-ah.wav",audio_buf_r_ah,size_r_ah);
file_write("/tmp/r-ao.wav",audio_buf_r_ao,size_r_ao);
file_write("/tmp/r-aw.wav",audio_buf_r_aw,size_r_aw);
file_write("/tmp/r-ax.wav",audio_buf_r_ax,size_r_ax);
file_write("/tmp/r-ay.wav",audio_buf_r_ay,size_r_ay);
file_write("/tmp/r-b.wav",audio_buf_r_b,size_r_b);
file_write("/tmp/r-ch.wav",audio_buf_r_ch,size_r_ch);
file_write("/tmp/r-d.wav",audio_buf_r_d,size_r_d);
file_write("/tmp/r-dh.wav",audio_buf_r_dh,size_r_dh);
file_write("/tmp/r-eh.wav",audio_buf_r_eh,size_r_eh);
file_write("/tmp/r-er.wav",audio_buf_r_er,size_r_er);
file_write("/tmp/r-ey.wav",audio_buf_r_ey,size_r_ey);
file_write("/tmp/r-f.wav",audio_buf_r_f,size_r_f);
file_write("/tmp/r-g.wav",audio_buf_r_g,size_r_g);
file_write("/tmp/r-hh.wav",audio_buf_r_hh,size_r_hh);
file_write("/tmp/r-ih.wav",audio_buf_r_ih,size_r_ih);
file_write("/tmp/r-iy.wav",audio_buf_r_iy,size_r_iy);
file_write("/tmp/r-jh.wav",audio_buf_r_jh,size_r_jh);
file_write("/tmp/r-k.wav",audio_buf_r_k,size_r_k);
file_write("/tmp/r-l.wav",audio_buf_r_l,size_r_l);
file_write("/tmp/r-m.wav",audio_buf_r_m,size_r_m);
file_write("/tmp/r-n.wav",audio_buf_r_n,size_r_n);
file_write("/tmp/r-ow.wav",audio_buf_r_ow,size_r_ow);
file_write("/tmp/r-oy.wav",audio_buf_r_oy,size_r_oy);
file_write("/tmp/r-p.wav",audio_buf_r_p,size_r_p);
file_write("/tmp/r-pau.wav",audio_buf_r_pau,size_r_pau);
file_write("/tmp/r-r.wav",audio_buf_r_r,size_r_r);
file_write("/tmp/r-s.wav",audio_buf_r_s,size_r_s);
file_write("/tmp/r-sh.wav",audio_buf_r_sh,size_r_sh);
file_write("/tmp/r-t.wav",audio_buf_r_t,size_r_t);
file_write("/tmp/r-th.wav",audio_buf_r_th,size_r_th);
file_write("/tmp/r-uh.wav",audio_buf_r_uh,size_r_uh);
file_write("/tmp/r-uw.wav",audio_buf_r_uw,size_r_uw);
file_write("/tmp/r-v.wav",audio_buf_r_v,size_r_v);
file_write("/tmp/r-w.wav",audio_buf_r_w,size_r_w);
file_write("/tmp/r-y.wav",audio_buf_r_y,size_r_y);
file_write("/tmp/r-z.wav",audio_buf_r_z,size_r_z);
file_write("/tmp/r-zh.wav",audio_buf_r_zh,size_r_zh);

//s diphones  
unsigned  long * audio_buf_s_aa = ( unsigned  long *)&_binary_s_aa_wav_start; 
unsigned long size_s_aa = ( unsigned long )&_binary_s_aa_wav_size;
unsigned  long * audio_buf_s_ae = ( unsigned  long *)&_binary_s_ae_wav_start;
unsigned long size_s_ae = ( unsigned long )&_binary_s_ae_wav_size;
unsigned  long * audio_buf_s_ah = ( unsigned  long *)&_binary_s_ah_wav_start;
unsigned long size_s_ah = ( unsigned long )&_binary_s_ah_wav_size;
unsigned  long * audio_buf_s_ao = ( unsigned  long *)&_binary_s_ao_wav_start;
unsigned long size_s_ao = ( unsigned long )&_binary_s_ao_wav_size;
unsigned  long * audio_buf_s_aw = ( unsigned  long *)&_binary_s_aw_wav_start;
unsigned long size_s_aw = ( unsigned long )&_binary_s_aw_wav_size;
unsigned  long * audio_buf_s_ax = ( unsigned  long *)&_binary_s_ax_wav_start;
unsigned long size_s_ax = ( unsigned long )&_binary_s_ax_wav_size;
unsigned  long * audio_buf_s_ay = ( unsigned  long *)&_binary_s_ay_wav_start;
unsigned long size_s_ay = ( unsigned long )&_binary_s_ay_wav_size;
unsigned  long * audio_buf_s_b = ( unsigned  long *)&_binary_s_b_wav_start;
unsigned long size_s_b = ( unsigned long )&_binary_s_b_wav_size;
unsigned  long * audio_buf_s_ch = ( unsigned  long *)&_binary_s_ch_wav_start;
unsigned long size_s_ch = ( unsigned long )&_binary_s_ch_wav_size;
unsigned  long * audio_buf_s_d = ( unsigned  long *)&_binary_s_d_wav_start;
unsigned long size_s_d = ( unsigned long )&_binary_s_d_wav_size;
unsigned  long * audio_buf_s_dh = ( unsigned  long *)&_binary_s_dh_wav_start;
unsigned long size_s_dh = ( unsigned long )&_binary_s_dh_wav_size;
unsigned  long * audio_buf_s_eh = ( unsigned  long *)&_binary_s_eh_wav_start;
unsigned long size_s_eh = ( unsigned long )&_binary_s_eh_wav_size;
unsigned  long * audio_buf_s_er = ( unsigned  long *)&_binary_s_er_wav_start;
unsigned long size_s_er = ( unsigned long )&_binary_s_er_wav_size;
unsigned  long * audio_buf_s_ey = ( unsigned  long *)&_binary_s_ey_wav_start;
unsigned long size_s_ey = ( unsigned long )&_binary_s_ey_wav_size;
unsigned  long * audio_buf_s_f = ( unsigned  long *)&_binary_s_f_wav_start;
unsigned long size_s_f = ( unsigned long )&_binary_s_f_wav_size;
unsigned  long * audio_buf_s_g = ( unsigned  long *)&_binary_s_g_wav_start;
unsigned long size_s_g = ( unsigned long )&_binary_s_g_wav_size;
unsigned  long * audio_buf_s_hh = ( unsigned  long *)&_binary_s_hh_wav_start;
unsigned long size_s_hh = ( unsigned long )&_binary_s_hh_wav_size;
unsigned  long * audio_buf_s_ih = ( unsigned  long *)&_binary_s_ih_wav_start;
unsigned long size_s_ih = ( unsigned long )&_binary_s_ih_wav_size;
unsigned  long * audio_buf_s_iy = ( unsigned  long *)&_binary_s_iy_wav_start;
unsigned long size_s_iy = ( unsigned long )&_binary_s_iy_wav_size;
unsigned  long * audio_buf_s_jh = ( unsigned  long *)&_binary_s_jh_wav_start;
unsigned long size_s_jh = ( unsigned long )&_binary_s_jh_wav_size;
unsigned  long * audio_buf_s_k = ( unsigned  long *)&_binary_s_k_wav_start;
unsigned long size_s_k = ( unsigned long )&_binary_s_k_wav_size;
unsigned  long * audio_buf_s_l = ( unsigned  long *)&_binary_s_l_wav_start;
unsigned long size_s_l = ( unsigned long )&_binary_s_l_wav_size;
unsigned  long * audio_buf_s_m = ( unsigned  long *)&_binary_s_m_wav_start;
unsigned long size_s_m = ( unsigned long )&_binary_s_m_wav_size;
unsigned  long * audio_buf_s_n = ( unsigned  long *)&_binary_s_n_wav_start;
unsigned long size_s_n = ( unsigned long )&_binary_s_n_wav_size;
unsigned  long * audio_buf_s_ow = ( unsigned  long *)&_binary_s_ow_wav_start;
unsigned long size_s_ow = ( unsigned long )&_binary_s_ow_wav_size;
unsigned  long * audio_buf_s_oy = ( unsigned  long *)&_binary_s_oy_wav_start;
unsigned long size_s_oy = ( unsigned long )&_binary_s_oy_wav_size;
unsigned  long * audio_buf_s_p = ( unsigned  long *)&_binary_s_p_wav_start;
unsigned long size_s_p = ( unsigned long )&_binary_s_p_wav_size;
unsigned  long * audio_buf_s_pau = ( unsigned  long *)&_binary_s_pau_wav_start;
unsigned long size_s_pau = ( unsigned long )&_binary_s_pau_wav_size;
unsigned  long * audio_buf_s_r = ( unsigned  long *)&_binary_s_r_wav_start;
unsigned long size_s_r = ( unsigned long )&_binary_s_r_wav_size;
unsigned  long * audio_buf_s_s = ( unsigned  long *)&_binary_s_s_wav_start;
unsigned long size_s_s = ( unsigned long )&_binary_s_s_wav_size;
unsigned  long * audio_buf_s_sh = ( unsigned  long *)&_binary_s_sh_wav_start;
unsigned long size_s_sh = ( unsigned long )&_binary_s_sh_wav_size;
unsigned  long * audio_buf_s_t = ( unsigned  long *)&_binary_s_t_wav_start;
unsigned long size_s_t = ( unsigned long )&_binary_s_t_wav_size;
unsigned  long * audio_buf_s_th = ( unsigned  long *)&_binary_s_th_wav_start;
unsigned long size_s_th = ( unsigned long )&_binary_s_th_wav_size;
unsigned  long * audio_buf_s_uh = ( unsigned  long *)&_binary_s_uh_wav_start;
unsigned long size_s_uh = ( unsigned long )&_binary_s_uh_wav_size;
unsigned  long * audio_buf_s_uw = ( unsigned  long *)&_binary_s_uw_wav_start;
unsigned long size_s_uw = ( unsigned long )&_binary_s_uw_wav_size;
unsigned  long * audio_buf_s_v = ( unsigned  long *)&_binary_s_v_wav_start;
unsigned long size_s_v = ( unsigned long )&_binary_s_v_wav_size;
unsigned  long * audio_buf_s_w = ( unsigned  long *)&_binary_s_w_wav_start;
unsigned long size_s_w = ( unsigned long )&_binary_s_w_wav_size;
unsigned  long * audio_buf_s_y = ( unsigned  long *)&_binary_s_y_wav_start;
unsigned long size_s_y = ( unsigned long )&_binary_s_y_wav_size;
unsigned  long * audio_buf_s_z = ( unsigned  long *)&_binary_s_z_wav_start;
unsigned long size_s_z = ( unsigned long )&_binary_s_z_wav_size;
unsigned  long * audio_buf_s_zh = ( unsigned  long *)&_binary_s_zh_wav_start;
unsigned long size_s_zh = ( unsigned long )&_binary_s_zh_wav_size;
//s diphones
file_write("/tmp/s-aa.wav",audio_buf_s_aa,size_s_aa);
file_write("/tmp/s-ae.wav",audio_buf_s_ae,size_s_ae);
file_write("/tmp/s-ah.wav",audio_buf_s_ah,size_s_ah);
file_write("/tmp/s-ao.wav",audio_buf_s_ao,size_s_ao);
file_write("/tmp/s-aw.wav",audio_buf_s_aw,size_s_aw);
file_write("/tmp/s-ax.wav",audio_buf_s_ax,size_s_ax);
file_write("/tmp/s-ay.wav",audio_buf_s_ay,size_s_ay);
file_write("/tmp/s-b.wav",audio_buf_s_b,size_s_b);
file_write("/tmp/s-ch.wav",audio_buf_s_ch,size_s_ch);
file_write("/tmp/s-d.wav",audio_buf_s_d,size_s_d);
file_write("/tmp/s-dh.wav",audio_buf_s_dh,size_s_dh);
file_write("/tmp/s-eh.wav",audio_buf_s_eh,size_s_eh);
file_write("/tmp/s-er.wav",audio_buf_s_er,size_s_er);
file_write("/tmp/s-ey.wav",audio_buf_s_ey,size_s_ey);
file_write("/tmp/s-f.wav",audio_buf_s_f,size_s_f);
file_write("/tmp/s-g.wav",audio_buf_s_g,size_s_g);
file_write("/tmp/s-hh.wav",audio_buf_s_hh,size_s_hh);
file_write("/tmp/s-ih.wav",audio_buf_s_ih,size_s_ih);
file_write("/tmp/s-iy.wav",audio_buf_s_iy,size_s_iy);
file_write("/tmp/s-jh.wav",audio_buf_s_jh,size_s_jh);
file_write("/tmp/s-k.wav",audio_buf_s_k,size_s_k);
file_write("/tmp/s-l.wav",audio_buf_s_l,size_s_l);
file_write("/tmp/s-m.wav",audio_buf_s_m,size_s_m);
file_write("/tmp/s-n.wav",audio_buf_s_n,size_s_n);
file_write("/tmp/s-ow.wav",audio_buf_s_ow,size_s_ow);
file_write("/tmp/s-oy.wav",audio_buf_s_oy,size_s_oy);
file_write("/tmp/s-p.wav",audio_buf_s_p,size_s_p);
file_write("/tmp/s-pau.wav",audio_buf_s_pau,size_s_pau);
file_write("/tmp/s-r.wav",audio_buf_s_r,size_s_r);
file_write("/tmp/s-s.wav",audio_buf_s_s,size_s_s);
file_write("/tmp/s-sh.wav",audio_buf_s_sh,size_s_sh);
file_write("/tmp/s-t.wav",audio_buf_s_t,size_s_t);
file_write("/tmp/s-th.wav",audio_buf_s_th,size_s_th);
file_write("/tmp/s-uh.wav",audio_buf_s_uh,size_s_uh);
file_write("/tmp/s-uw.wav",audio_buf_s_uw,size_s_uw);
file_write("/tmp/s-v.wav",audio_buf_s_v,size_s_v);
file_write("/tmp/s-w.wav",audio_buf_s_w,size_s_w);
file_write("/tmp/s-y.wav",audio_buf_s_y,size_s_y);
file_write("/tmp/s-z.wav",audio_buf_s_z,size_s_z);
file_write("/tmp/s-zh.wav",audio_buf_s_zh,size_s_zh);

//sh diphones  
unsigned  long * audio_buf_sh_aa = ( unsigned  long *)&_binary_sh_aa_wav_start; 
unsigned long size_sh_aa = ( unsigned long )&_binary_sh_aa_wav_size;
unsigned  long * audio_buf_sh_ae = ( unsigned  long *)&_binary_sh_ae_wav_start;
unsigned long size_sh_ae = ( unsigned long )&_binary_sh_ae_wav_size;
unsigned  long * audio_buf_sh_ah = ( unsigned  long *)&_binary_sh_ah_wav_start;
unsigned long size_sh_ah = ( unsigned long )&_binary_sh_ah_wav_size;
unsigned  long * audio_buf_sh_ao = ( unsigned  long *)&_binary_sh_ao_wav_start;
unsigned long size_sh_ao = ( unsigned long )&_binary_sh_ao_wav_size;
unsigned  long * audio_buf_sh_aw = ( unsigned  long *)&_binary_sh_aw_wav_start;
unsigned long size_sh_aw = ( unsigned long )&_binary_sh_aw_wav_size;
unsigned  long * audio_buf_sh_ax = ( unsigned  long *)&_binary_sh_ax_wav_start;
unsigned long size_sh_ax = ( unsigned long )&_binary_sh_ax_wav_size;
unsigned  long * audio_buf_sh_ay = ( unsigned  long *)&_binary_sh_ay_wav_start;
unsigned long size_sh_ay = ( unsigned long )&_binary_sh_ay_wav_size;
unsigned  long * audio_buf_sh_b = ( unsigned  long *)&_binary_sh_b_wav_start;
unsigned long size_sh_b = ( unsigned long )&_binary_sh_b_wav_size;
unsigned  long * audio_buf_sh_ch = ( unsigned  long *)&_binary_sh_ch_wav_start;
unsigned long size_sh_ch = ( unsigned long )&_binary_sh_ch_wav_size;
unsigned  long * audio_buf_sh_d = ( unsigned  long *)&_binary_sh_d_wav_start;
unsigned long size_sh_d = ( unsigned long )&_binary_sh_d_wav_size;
unsigned  long * audio_buf_sh_dh = ( unsigned  long *)&_binary_sh_dh_wav_start;
unsigned long size_sh_dh = ( unsigned long )&_binary_sh_dh_wav_size;
unsigned  long * audio_buf_sh_eh = ( unsigned  long *)&_binary_sh_eh_wav_start;
unsigned long size_sh_eh = ( unsigned long )&_binary_sh_eh_wav_size;
unsigned  long * audio_buf_sh_er = ( unsigned  long *)&_binary_sh_er_wav_start;
unsigned long size_sh_er = ( unsigned long )&_binary_sh_er_wav_size;
unsigned  long * audio_buf_sh_ey = ( unsigned  long *)&_binary_sh_ey_wav_start;
unsigned long size_sh_ey = ( unsigned long )&_binary_sh_ey_wav_size;
unsigned  long * audio_buf_sh_f = ( unsigned  long *)&_binary_sh_f_wav_start;
unsigned long size_sh_f = ( unsigned long )&_binary_sh_f_wav_size;
unsigned  long * audio_buf_sh_g = ( unsigned  long *)&_binary_sh_g_wav_start;
unsigned long size_sh_g = ( unsigned long )&_binary_sh_g_wav_size;
unsigned  long * audio_buf_sh_hh = ( unsigned  long *)&_binary_sh_hh_wav_start;
unsigned long size_sh_hh = ( unsigned long )&_binary_sh_hh_wav_size;
unsigned  long * audio_buf_sh_ih = ( unsigned  long *)&_binary_sh_ih_wav_start;
unsigned long size_sh_ih = ( unsigned long )&_binary_sh_ih_wav_size;
unsigned  long * audio_buf_sh_iy = ( unsigned  long *)&_binary_sh_iy_wav_start;
unsigned long size_sh_iy = ( unsigned long )&_binary_sh_iy_wav_size;
unsigned  long * audio_buf_sh_jh = ( unsigned  long *)&_binary_sh_jh_wav_start;
unsigned long size_sh_jh = ( unsigned long )&_binary_sh_jh_wav_size;
unsigned  long * audio_buf_sh_k = ( unsigned  long *)&_binary_sh_k_wav_start;
unsigned long size_sh_k = ( unsigned long )&_binary_sh_k_wav_size;
unsigned  long * audio_buf_sh_l = ( unsigned  long *)&_binary_sh_l_wav_start;
unsigned long size_sh_l = ( unsigned long )&_binary_sh_l_wav_size;
unsigned  long * audio_buf_sh_m = ( unsigned  long *)&_binary_sh_m_wav_start;
unsigned long size_sh_m = ( unsigned long )&_binary_sh_m_wav_size;
unsigned  long * audio_buf_sh_n = ( unsigned  long *)&_binary_sh_n_wav_start;
unsigned long size_sh_n = ( unsigned long )&_binary_sh_n_wav_size;
unsigned  long * audio_buf_sh_ow = ( unsigned  long *)&_binary_sh_ow_wav_start;
unsigned long size_sh_ow = ( unsigned long )&_binary_sh_ow_wav_size;
unsigned  long * audio_buf_sh_oy = ( unsigned  long *)&_binary_sh_oy_wav_start;
unsigned long size_sh_oy = ( unsigned long )&_binary_sh_oy_wav_size;
unsigned  long * audio_buf_sh_p = ( unsigned  long *)&_binary_sh_p_wav_start;
unsigned long size_sh_p = ( unsigned long )&_binary_sh_p_wav_size;
unsigned  long * audio_buf_sh_pau = ( unsigned  long *)&_binary_sh_pau_wav_start;
unsigned long size_sh_pau = ( unsigned long )&_binary_sh_pau_wav_size;
unsigned  long * audio_buf_sh_r = ( unsigned  long *)&_binary_sh_r_wav_start;
unsigned long size_sh_r = ( unsigned long )&_binary_sh_r_wav_size;
unsigned  long * audio_buf_sh_s = ( unsigned  long *)&_binary_sh_s_wav_start;
unsigned long size_sh_s = ( unsigned long )&_binary_sh_s_wav_size;
unsigned  long * audio_buf_sh_sh = ( unsigned  long *)&_binary_sh_sh_wav_start;
unsigned long size_sh_sh = ( unsigned long )&_binary_sh_sh_wav_size;
unsigned  long * audio_buf_sh_t = ( unsigned  long *)&_binary_sh_t_wav_start;
unsigned long size_sh_t = ( unsigned long )&_binary_sh_t_wav_size;
unsigned  long * audio_buf_sh_th = ( unsigned  long *)&_binary_sh_th_wav_start;
unsigned long size_sh_th = ( unsigned long )&_binary_sh_th_wav_size;
unsigned  long * audio_buf_sh_uh = ( unsigned  long *)&_binary_sh_uh_wav_start;
unsigned long size_sh_uh = ( unsigned long )&_binary_sh_uh_wav_size;
unsigned  long * audio_buf_sh_uw = ( unsigned  long *)&_binary_sh_uw_wav_start;
unsigned long size_sh_uw = ( unsigned long )&_binary_sh_uw_wav_size;
unsigned  long * audio_buf_sh_v = ( unsigned  long *)&_binary_sh_v_wav_start;
unsigned long size_sh_v = ( unsigned long )&_binary_sh_v_wav_size;
unsigned  long * audio_buf_sh_w = ( unsigned  long *)&_binary_sh_w_wav_start;
unsigned long size_sh_w = ( unsigned long )&_binary_sh_w_wav_size;
unsigned  long * audio_buf_sh_y = ( unsigned  long *)&_binary_sh_y_wav_start;
unsigned long size_sh_y = ( unsigned long )&_binary_sh_y_wav_size;
unsigned  long * audio_buf_sh_z = ( unsigned  long *)&_binary_sh_z_wav_start;
unsigned long size_sh_z = ( unsigned long )&_binary_sh_z_wav_size;
unsigned  long * audio_buf_sh_zh = ( unsigned  long *)&_binary_sh_zh_wav_start;
unsigned long size_sh_zh = ( unsigned long )&_binary_sh_zh_wav_size;
//sh diphones
file_write("/tmp/sh-aa.wav",audio_buf_sh_aa,size_sh_aa);
file_write("/tmp/sh-ae.wav",audio_buf_sh_ae,size_sh_ae);
file_write("/tmp/sh-ah.wav",audio_buf_sh_ah,size_sh_ah);
file_write("/tmp/sh-ao.wav",audio_buf_sh_ao,size_sh_ao);
file_write("/tmp/sh-aw.wav",audio_buf_sh_aw,size_sh_aw);
file_write("/tmp/sh-ax.wav",audio_buf_sh_ax,size_sh_ax);
file_write("/tmp/sh-ay.wav",audio_buf_sh_ay,size_sh_ay);
file_write("/tmp/sh-b.wav",audio_buf_sh_b,size_sh_b);
file_write("/tmp/sh-ch.wav",audio_buf_sh_ch,size_sh_ch);
file_write("/tmp/sh-d.wav",audio_buf_sh_d,size_sh_d);
file_write("/tmp/sh-dh.wav",audio_buf_sh_dh,size_sh_dh);
file_write("/tmp/sh-eh.wav",audio_buf_sh_eh,size_sh_eh);
file_write("/tmp/sh-er.wav",audio_buf_sh_er,size_sh_er);
file_write("/tmp/sh-ey.wav",audio_buf_sh_ey,size_sh_ey);
file_write("/tmp/sh-f.wav",audio_buf_sh_f,size_sh_f);
file_write("/tmp/sh-g.wav",audio_buf_sh_g,size_sh_g);
file_write("/tmp/sh-hh.wav",audio_buf_sh_hh,size_sh_hh);
file_write("/tmp/sh-ih.wav",audio_buf_sh_ih,size_sh_ih);
file_write("/tmp/sh-iy.wav",audio_buf_sh_iy,size_sh_iy);
file_write("/tmp/sh-jh.wav",audio_buf_sh_jh,size_sh_jh);
file_write("/tmp/sh-k.wav",audio_buf_sh_k,size_sh_k);
file_write("/tmp/sh-l.wav",audio_buf_sh_l,size_sh_l);
file_write("/tmp/sh-m.wav",audio_buf_sh_m,size_sh_m);
file_write("/tmp/sh-n.wav",audio_buf_sh_n,size_sh_n);
file_write("/tmp/sh-ow.wav",audio_buf_sh_ow,size_sh_ow);
file_write("/tmp/sh-oy.wav",audio_buf_sh_oy,size_sh_oy);
file_write("/tmp/sh-p.wav",audio_buf_sh_p,size_sh_p);
file_write("/tmp/sh-pau.wav",audio_buf_sh_pau,size_sh_pau);
file_write("/tmp/sh-r.wav",audio_buf_sh_r,size_sh_r);
file_write("/tmp/sh-s.wav",audio_buf_sh_s,size_sh_s);
file_write("/tmp/sh-sh.wav",audio_buf_sh_sh,size_sh_sh);
file_write("/tmp/sh-t.wav",audio_buf_sh_t,size_sh_t);
file_write("/tmp/sh-th.wav",audio_buf_sh_th,size_sh_th);
file_write("/tmp/sh-uh.wav",audio_buf_sh_uh,size_sh_uh);
file_write("/tmp/sh-uw.wav",audio_buf_sh_uw,size_sh_uw);
file_write("/tmp/sh-v.wav",audio_buf_sh_v,size_sh_v);
file_write("/tmp/sh-w.wav",audio_buf_sh_w,size_sh_w);
file_write("/tmp/sh-y.wav",audio_buf_sh_y,size_sh_y);
file_write("/tmp/sh-z.wav",audio_buf_sh_z,size_sh_z);
file_write("/tmp/sh-zh.wav",audio_buf_sh_zh,size_sh_zh);


//t diphones  
unsigned  long * audio_buf_t_aa = ( unsigned  long *)&_binary_t_aa_wav_start; 
unsigned long size_t_aa = ( unsigned long )&_binary_t_aa_wav_size;
unsigned  long * audio_buf_t_ae = ( unsigned  long *)&_binary_t_ae_wav_start;
unsigned long size_t_ae = ( unsigned long )&_binary_t_ae_wav_size;
unsigned  long * audio_buf_t_ah = ( unsigned  long *)&_binary_t_ah_wav_start;
unsigned long size_t_ah = ( unsigned long )&_binary_t_ah_wav_size;
unsigned  long * audio_buf_t_ao = ( unsigned  long *)&_binary_t_ao_wav_start;
unsigned long size_t_ao = ( unsigned long )&_binary_t_ao_wav_size;
unsigned  long * audio_buf_t_aw = ( unsigned  long *)&_binary_t_aw_wav_start;
unsigned long size_t_aw = ( unsigned long )&_binary_t_aw_wav_size;
unsigned  long * audio_buf_t_ax = ( unsigned  long *)&_binary_t_ax_wav_start;
unsigned long size_t_ax = ( unsigned long )&_binary_t_ax_wav_size;
unsigned  long * audio_buf_t_ay = ( unsigned  long *)&_binary_t_ay_wav_start;
unsigned long size_t_ay = ( unsigned long )&_binary_t_ay_wav_size;
unsigned  long * audio_buf_t_b = ( unsigned  long *)&_binary_t_b_wav_start;
unsigned long size_t_b = ( unsigned long )&_binary_t_b_wav_size;
unsigned  long * audio_buf_t_ch = ( unsigned  long *)&_binary_t_ch_wav_start;
unsigned long size_t_ch = ( unsigned long )&_binary_t_ch_wav_size;
unsigned  long * audio_buf_t_d = ( unsigned  long *)&_binary_t_d_wav_start;
unsigned long size_t_d = ( unsigned long )&_binary_t_d_wav_size;
unsigned  long * audio_buf_t_dh = ( unsigned  long *)&_binary_t_dh_wav_start;
unsigned long size_t_dh = ( unsigned long )&_binary_t_dh_wav_size;
unsigned  long * audio_buf_t_eh = ( unsigned  long *)&_binary_t_eh_wav_start;
unsigned long size_t_eh = ( unsigned long )&_binary_t_eh_wav_size;
unsigned  long * audio_buf_t_er = ( unsigned  long *)&_binary_t_er_wav_start;
unsigned long size_t_er = ( unsigned long )&_binary_t_er_wav_size;
unsigned  long * audio_buf_t_ey = ( unsigned  long *)&_binary_t_ey_wav_start;
unsigned long size_t_ey = ( unsigned long )&_binary_t_ey_wav_size;
unsigned  long * audio_buf_t_f = ( unsigned  long *)&_binary_t_f_wav_start;
unsigned long size_t_f = ( unsigned long )&_binary_t_f_wav_size;
unsigned  long * audio_buf_t_g = ( unsigned  long *)&_binary_t_g_wav_start;
unsigned long size_t_g = ( unsigned long )&_binary_t_g_wav_size;
unsigned  long * audio_buf_t_hh = ( unsigned  long *)&_binary_t_hh_wav_start;
unsigned long size_t_hh = ( unsigned long )&_binary_t_hh_wav_size;
unsigned  long * audio_buf_t_ih = ( unsigned  long *)&_binary_t_ih_wav_start;
unsigned long size_t_ih = ( unsigned long )&_binary_t_ih_wav_size;
unsigned  long * audio_buf_t_iy = ( unsigned  long *)&_binary_t_iy_wav_start;
unsigned long size_t_iy = ( unsigned long )&_binary_t_iy_wav_size;
unsigned  long * audio_buf_t_jh = ( unsigned  long *)&_binary_t_jh_wav_start;
unsigned long size_t_jh = ( unsigned long )&_binary_t_jh_wav_size;
unsigned  long * audio_buf_t_k = ( unsigned  long *)&_binary_t_k_wav_start;
unsigned long size_t_k = ( unsigned long )&_binary_t_k_wav_size;
unsigned  long * audio_buf_t_l = ( unsigned  long *)&_binary_t_l_wav_start;
unsigned long size_t_l = ( unsigned long )&_binary_t_l_wav_size;
unsigned  long * audio_buf_t_m = ( unsigned  long *)&_binary_t_m_wav_start;
unsigned long size_t_m = ( unsigned long )&_binary_t_m_wav_size;
unsigned  long * audio_buf_t_n = ( unsigned  long *)&_binary_t_n_wav_start;
unsigned long size_t_n = ( unsigned long )&_binary_t_n_wav_size;
unsigned  long * audio_buf_t_ow = ( unsigned  long *)&_binary_t_ow_wav_start;
unsigned long size_t_ow = ( unsigned long )&_binary_t_ow_wav_size;
unsigned  long * audio_buf_t_oy = ( unsigned  long *)&_binary_t_oy_wav_start;
unsigned long size_t_oy = ( unsigned long )&_binary_t_oy_wav_size;
unsigned  long * audio_buf_t_p = ( unsigned  long *)&_binary_t_p_wav_start;
unsigned long size_t_p = ( unsigned long )&_binary_t_p_wav_size;
unsigned  long * audio_buf_t_pau = ( unsigned  long *)&_binary_t_pau_wav_start;
unsigned long size_t_pau = ( unsigned long )&_binary_t_pau_wav_size;
unsigned  long * audio_buf_t_r = ( unsigned  long *)&_binary_t_r_wav_start;
unsigned long size_t_r = ( unsigned long )&_binary_t_r_wav_size;
unsigned  long * audio_buf_t_s = ( unsigned  long *)&_binary_t_s_wav_start;
unsigned long size_t_s = ( unsigned long )&_binary_t_s_wav_size;
unsigned  long * audio_buf_t_sh = ( unsigned  long *)&_binary_t_sh_wav_start;
unsigned long size_t_sh = ( unsigned long )&_binary_t_sh_wav_size;
unsigned  long * audio_buf_t_t = ( unsigned  long *)&_binary_t_t_wav_start;
unsigned long size_t_t = ( unsigned long )&_binary_t_t_wav_size;
unsigned  long * audio_buf_t_th = ( unsigned  long *)&_binary_t_th_wav_start;
unsigned long size_t_th = ( unsigned long )&_binary_t_th_wav_size;
unsigned  long * audio_buf_t_uh = ( unsigned  long *)&_binary_t_uh_wav_start;
unsigned long size_t_uh = ( unsigned long )&_binary_t_uh_wav_size;
unsigned  long * audio_buf_t_uw = ( unsigned  long *)&_binary_t_uw_wav_start;
unsigned long size_t_uw = ( unsigned long )&_binary_t_uw_wav_size;
unsigned  long * audio_buf_t_v = ( unsigned  long *)&_binary_t_v_wav_start;
unsigned long size_t_v = ( unsigned long )&_binary_t_v_wav_size;
unsigned  long * audio_buf_t_w = ( unsigned  long *)&_binary_t_w_wav_start;
unsigned long size_t_w = ( unsigned long )&_binary_t_w_wav_size;
unsigned  long * audio_buf_t_y = ( unsigned  long *)&_binary_t_y_wav_start;
unsigned long size_t_y = ( unsigned long )&_binary_t_y_wav_size;
unsigned  long * audio_buf_t_z = ( unsigned  long *)&_binary_t_z_wav_start;
unsigned long size_t_z = ( unsigned long )&_binary_t_z_wav_size;
unsigned  long * audio_buf_t_zh = ( unsigned  long *)&_binary_t_zh_wav_start;
unsigned long size_t_zh = ( unsigned long )&_binary_t_zh_wav_size;
//t diphones
file_write("/tmp/t-aa.wav",audio_buf_t_aa,size_t_aa);
file_write("/tmp/t-ae.wav",audio_buf_t_ae,size_t_ae);
file_write("/tmp/t-ah.wav",audio_buf_t_ah,size_t_ah);
file_write("/tmp/t-ao.wav",audio_buf_t_ao,size_t_ao);
file_write("/tmp/t-aw.wav",audio_buf_t_aw,size_t_aw);
file_write("/tmp/t-ax.wav",audio_buf_t_ax,size_t_ax);
file_write("/tmp/t-ay.wav",audio_buf_t_ay,size_t_ay);
file_write("/tmp/t-b.wav",audio_buf_t_b,size_t_b);
file_write("/tmp/t-ch.wav",audio_buf_t_ch,size_t_ch);
file_write("/tmp/t-d.wav",audio_buf_t_d,size_t_d);
file_write("/tmp/t-dh.wav",audio_buf_t_dh,size_t_dh);
file_write("/tmp/t-eh.wav",audio_buf_t_eh,size_t_eh);
file_write("/tmp/t-er.wav",audio_buf_t_er,size_t_er);
file_write("/tmp/t-ey.wav",audio_buf_t_ey,size_t_ey);
file_write("/tmp/t-f.wav",audio_buf_t_f,size_t_f);
file_write("/tmp/t-g.wav",audio_buf_t_g,size_t_g);
file_write("/tmp/t-hh.wav",audio_buf_t_hh,size_t_hh);
file_write("/tmp/t-ih.wav",audio_buf_t_ih,size_t_ih);
file_write("/tmp/t-iy.wav",audio_buf_t_iy,size_t_iy);
file_write("/tmp/t-jh.wav",audio_buf_t_jh,size_t_jh);
file_write("/tmp/t-k.wav",audio_buf_t_k,size_t_k);
file_write("/tmp/t-l.wav",audio_buf_t_l,size_t_l);
file_write("/tmp/t-m.wav",audio_buf_t_m,size_t_m);
file_write("/tmp/t-n.wav",audio_buf_t_n,size_t_n);
file_write("/tmp/t-ow.wav",audio_buf_t_ow,size_t_ow);
file_write("/tmp/t-oy.wav",audio_buf_t_oy,size_t_oy);
file_write("/tmp/t-p.wav",audio_buf_t_p,size_t_p);
file_write("/tmp/t-pau.wav",audio_buf_t_pau,size_t_pau);
file_write("/tmp/t-r.wav",audio_buf_t_r,size_t_r);
file_write("/tmp/t-s.wav",audio_buf_t_s,size_t_s);
file_write("/tmp/t-sh.wav",audio_buf_t_sh,size_t_sh);
file_write("/tmp/t-t.wav",audio_buf_t_t,size_t_t);
file_write("/tmp/t-th.wav",audio_buf_t_th,size_t_th);
file_write("/tmp/t-uh.wav",audio_buf_t_uh,size_t_uh);
file_write("/tmp/t-uw.wav",audio_buf_t_uw,size_t_uw);
file_write("/tmp/t-v.wav",audio_buf_t_v,size_t_v);
file_write("/tmp/t-w.wav",audio_buf_t_w,size_t_w);
file_write("/tmp/t-y.wav",audio_buf_t_y,size_t_y);
file_write("/tmp/t-z.wav",audio_buf_t_z,size_t_z);
file_write("/tmp/t-zh.wav",audio_buf_t_zh,size_t_zh);

//th diphones  
unsigned  long * audio_buf_th_aa = ( unsigned  long *)&_binary_th_aa_wav_start; 
unsigned long size_th_aa = ( unsigned long )&_binary_th_aa_wav_size;
unsigned  long * audio_buf_th_ae = ( unsigned  long *)&_binary_th_ae_wav_start;
unsigned long size_th_ae = ( unsigned long )&_binary_th_ae_wav_size;
unsigned  long * audio_buf_th_ah = ( unsigned  long *)&_binary_th_ah_wav_start;
unsigned long size_th_ah = ( unsigned long )&_binary_th_ah_wav_size;
unsigned  long * audio_buf_th_ao = ( unsigned  long *)&_binary_th_ao_wav_start;
unsigned long size_th_ao = ( unsigned long )&_binary_th_ao_wav_size;
unsigned  long * audio_buf_th_aw = ( unsigned  long *)&_binary_th_aw_wav_start;
unsigned long size_th_aw = ( unsigned long )&_binary_th_aw_wav_size;
unsigned  long * audio_buf_th_ax = ( unsigned  long *)&_binary_th_ax_wav_start;
unsigned long size_th_ax = ( unsigned long )&_binary_th_ax_wav_size;
unsigned  long * audio_buf_th_ay = ( unsigned  long *)&_binary_th_ay_wav_start;
unsigned long size_th_ay = ( unsigned long )&_binary_th_ay_wav_size;
unsigned  long * audio_buf_th_b = ( unsigned  long *)&_binary_th_b_wav_start;
unsigned long size_th_b = ( unsigned long )&_binary_th_b_wav_size;
unsigned  long * audio_buf_th_ch = ( unsigned  long *)&_binary_th_ch_wav_start;
unsigned long size_th_ch = ( unsigned long )&_binary_th_ch_wav_size;
unsigned  long * audio_buf_th_d = ( unsigned  long *)&_binary_th_d_wav_start;
unsigned long size_th_d = ( unsigned long )&_binary_th_d_wav_size;
unsigned  long * audio_buf_th_dh = ( unsigned  long *)&_binary_th_dh_wav_start;
unsigned long size_th_dh = ( unsigned long )&_binary_th_dh_wav_size;
unsigned  long * audio_buf_th_eh = ( unsigned  long *)&_binary_th_eh_wav_start;
unsigned long size_th_eh = ( unsigned long )&_binary_th_eh_wav_size;
unsigned  long * audio_buf_th_er = ( unsigned  long *)&_binary_th_er_wav_start;
unsigned long size_th_er = ( unsigned long )&_binary_th_er_wav_size;
unsigned  long * audio_buf_th_ey = ( unsigned  long *)&_binary_th_ey_wav_start;
unsigned long size_th_ey = ( unsigned long )&_binary_th_ey_wav_size;
unsigned  long * audio_buf_th_f = ( unsigned  long *)&_binary_th_f_wav_start;
unsigned long size_th_f = ( unsigned long )&_binary_th_f_wav_size;
unsigned  long * audio_buf_th_g = ( unsigned  long *)&_binary_th_g_wav_start;
unsigned long size_th_g = ( unsigned long )&_binary_th_g_wav_size;
unsigned  long * audio_buf_th_hh = ( unsigned  long *)&_binary_th_hh_wav_start;
unsigned long size_th_hh = ( unsigned long )&_binary_th_hh_wav_size;
unsigned  long * audio_buf_th_ih = ( unsigned  long *)&_binary_th_ih_wav_start;
unsigned long size_th_ih = ( unsigned long )&_binary_th_ih_wav_size;
unsigned  long * audio_buf_th_iy = ( unsigned  long *)&_binary_th_iy_wav_start;
unsigned long size_th_iy = ( unsigned long )&_binary_th_iy_wav_size;
unsigned  long * audio_buf_th_jh = ( unsigned  long *)&_binary_th_jh_wav_start;
unsigned long size_th_jh = ( unsigned long )&_binary_th_jh_wav_size;
unsigned  long * audio_buf_th_k = ( unsigned  long *)&_binary_th_k_wav_start;
unsigned long size_th_k = ( unsigned long )&_binary_th_k_wav_size;
unsigned  long * audio_buf_th_l = ( unsigned  long *)&_binary_th_l_wav_start;
unsigned long size_th_l = ( unsigned long )&_binary_th_l_wav_size;
unsigned  long * audio_buf_th_m = ( unsigned  long *)&_binary_th_m_wav_start;
unsigned long size_th_m = ( unsigned long )&_binary_th_m_wav_size;
unsigned  long * audio_buf_th_n = ( unsigned  long *)&_binary_th_n_wav_start;
unsigned long size_th_n = ( unsigned long )&_binary_th_n_wav_size;
unsigned  long * audio_buf_th_ow = ( unsigned  long *)&_binary_th_ow_wav_start;
unsigned long size_th_ow = ( unsigned long )&_binary_th_ow_wav_size;
unsigned  long * audio_buf_th_oy = ( unsigned  long *)&_binary_th_oy_wav_start;
unsigned long size_th_oy = ( unsigned long )&_binary_th_oy_wav_size;
unsigned  long * audio_buf_th_p = ( unsigned  long *)&_binary_th_p_wav_start;
unsigned long size_th_p = ( unsigned long )&_binary_th_p_wav_size;
unsigned  long * audio_buf_th_pau = ( unsigned  long *)&_binary_th_pau_wav_start;
unsigned long size_th_pau = ( unsigned long )&_binary_th_pau_wav_size;
unsigned  long * audio_buf_th_r = ( unsigned  long *)&_binary_th_r_wav_start;
unsigned long size_th_r = ( unsigned long )&_binary_th_r_wav_size;
unsigned  long * audio_buf_th_s = ( unsigned  long *)&_binary_th_s_wav_start;
unsigned long size_th_s = ( unsigned long )&_binary_th_s_wav_size;
unsigned  long * audio_buf_th_sh = ( unsigned  long *)&_binary_th_sh_wav_start;
unsigned long size_th_sh = ( unsigned long )&_binary_th_sh_wav_size;
unsigned  long * audio_buf_th_t = ( unsigned  long *)&_binary_th_t_wav_start;
unsigned long size_th_t = ( unsigned long )&_binary_th_t_wav_size;
unsigned  long * audio_buf_th_th = ( unsigned  long *)&_binary_th_th_wav_start;
unsigned long size_th_th = ( unsigned long )&_binary_th_th_wav_size;
unsigned  long * audio_buf_th_uh = ( unsigned  long *)&_binary_th_uh_wav_start;
unsigned long size_th_uh = ( unsigned long )&_binary_th_uh_wav_size;
unsigned  long * audio_buf_th_uw = ( unsigned  long *)&_binary_th_uw_wav_start;
unsigned long size_th_uw = ( unsigned long )&_binary_th_uw_wav_size;
unsigned  long * audio_buf_th_v = ( unsigned  long *)&_binary_th_v_wav_start;
unsigned long size_th_v = ( unsigned long )&_binary_th_v_wav_size;
unsigned  long * audio_buf_th_w = ( unsigned  long *)&_binary_th_w_wav_start;
unsigned long size_th_w = ( unsigned long )&_binary_th_w_wav_size;
unsigned  long * audio_buf_th_y = ( unsigned  long *)&_binary_th_y_wav_start;
unsigned long size_th_y = ( unsigned long )&_binary_th_y_wav_size;
unsigned  long * audio_buf_th_z = ( unsigned  long *)&_binary_th_z_wav_start;
unsigned long size_th_z = ( unsigned long )&_binary_th_z_wav_size;
unsigned  long * audio_buf_th_zh = ( unsigned  long *)&_binary_th_zh_wav_start;
unsigned long size_th_zh = ( unsigned long )&_binary_th_zh_wav_size;
//th diphones
file_write("/tmp/th-aa.wav",audio_buf_th_aa,size_th_aa);
file_write("/tmp/th-ae.wav",audio_buf_th_ae,size_th_ae);
file_write("/tmp/th-ah.wav",audio_buf_th_ah,size_th_ah);
file_write("/tmp/th-ao.wav",audio_buf_th_ao,size_th_ao);
file_write("/tmp/th-aw.wav",audio_buf_th_aw,size_th_aw);
file_write("/tmp/th-ax.wav",audio_buf_th_ax,size_th_ax);
file_write("/tmp/th-ay.wav",audio_buf_th_ay,size_th_ay);
file_write("/tmp/th-b.wav",audio_buf_th_b,size_th_b);
file_write("/tmp/th-ch.wav",audio_buf_th_ch,size_th_ch);
file_write("/tmp/th-d.wav",audio_buf_th_d,size_th_d);
file_write("/tmp/th-dh.wav",audio_buf_th_dh,size_th_dh);
file_write("/tmp/th-eh.wav",audio_buf_th_eh,size_th_eh);
file_write("/tmp/th-er.wav",audio_buf_th_er,size_th_er);
file_write("/tmp/th-ey.wav",audio_buf_th_ey,size_th_ey);
file_write("/tmp/th-f.wav",audio_buf_th_f,size_th_f);
file_write("/tmp/th-g.wav",audio_buf_th_g,size_th_g);
file_write("/tmp/th-hh.wav",audio_buf_th_hh,size_th_hh);
file_write("/tmp/th-ih.wav",audio_buf_th_ih,size_th_ih);
file_write("/tmp/th-iy.wav",audio_buf_th_iy,size_th_iy);
file_write("/tmp/th-jh.wav",audio_buf_th_jh,size_th_jh);
file_write("/tmp/th-k.wav",audio_buf_th_k,size_th_k);
file_write("/tmp/th-l.wav",audio_buf_th_l,size_th_l);
file_write("/tmp/th-m.wav",audio_buf_th_m,size_th_m);
file_write("/tmp/th-n.wav",audio_buf_th_n,size_th_n);
file_write("/tmp/th-ow.wav",audio_buf_th_ow,size_th_ow);
file_write("/tmp/th-oy.wav",audio_buf_th_oy,size_th_oy);
file_write("/tmp/th-p.wav",audio_buf_th_p,size_th_p);
file_write("/tmp/th-pau.wav",audio_buf_th_pau,size_th_pau);
file_write("/tmp/th-r.wav",audio_buf_th_r,size_th_r);
file_write("/tmp/th-s.wav",audio_buf_th_s,size_th_s);
file_write("/tmp/th-sh.wav",audio_buf_th_sh,size_th_sh);
file_write("/tmp/th-t.wav",audio_buf_th_t,size_th_t);
file_write("/tmp/th-th.wav",audio_buf_th_th,size_th_th);
file_write("/tmp/th-uh.wav",audio_buf_th_uh,size_th_uh);
file_write("/tmp/th-uw.wav",audio_buf_th_uw,size_th_uw);
file_write("/tmp/th-v.wav",audio_buf_th_v,size_th_v);
file_write("/tmp/th-w.wav",audio_buf_th_w,size_th_w);
file_write("/tmp/th-y.wav",audio_buf_th_y,size_th_y);
file_write("/tmp/th-z.wav",audio_buf_th_z,size_th_z);
file_write("/tmp/th-zh.wav",audio_buf_th_zh,size_th_zh);

//uh diphones  
unsigned  long * audio_buf_uh_aa = ( unsigned  long *)&_binary_uh_aa_wav_start; 
unsigned long size_uh_aa = ( unsigned long )&_binary_uh_aa_wav_size;
unsigned  long * audio_buf_uh_ae = ( unsigned  long *)&_binary_uh_ae_wav_start;
unsigned long size_uh_ae = ( unsigned long )&_binary_uh_ae_wav_size;
unsigned  long * audio_buf_uh_ah = ( unsigned  long *)&_binary_uh_ah_wav_start;
unsigned long size_uh_ah = ( unsigned long )&_binary_uh_ah_wav_size;
unsigned  long * audio_buf_uh_ao = ( unsigned  long *)&_binary_uh_ao_wav_start;
unsigned long size_uh_ao = ( unsigned long )&_binary_uh_ao_wav_size;
unsigned  long * audio_buf_uh_aw = ( unsigned  long *)&_binary_uh_aw_wav_start;
unsigned long size_uh_aw = ( unsigned long )&_binary_uh_aw_wav_size;
unsigned  long * audio_buf_uh_ax = ( unsigned  long *)&_binary_uh_ax_wav_start;
unsigned long size_uh_ax = ( unsigned long )&_binary_uh_ax_wav_size;
unsigned  long * audio_buf_uh_ay = ( unsigned  long *)&_binary_uh_ay_wav_start;
unsigned long size_uh_ay = ( unsigned long )&_binary_uh_ay_wav_size;
unsigned  long * audio_buf_uh_b = ( unsigned  long *)&_binary_uh_b_wav_start;
unsigned long size_uh_b = ( unsigned long )&_binary_uh_b_wav_size;
unsigned  long * audio_buf_uh_ch = ( unsigned  long *)&_binary_uh_ch_wav_start;
unsigned long size_uh_ch = ( unsigned long )&_binary_uh_ch_wav_size;
unsigned  long * audio_buf_uh_d = ( unsigned  long *)&_binary_uh_d_wav_start;
unsigned long size_uh_d = ( unsigned long )&_binary_uh_d_wav_size;
unsigned  long * audio_buf_uh_dh = ( unsigned  long *)&_binary_uh_dh_wav_start;
unsigned long size_uh_dh = ( unsigned long )&_binary_uh_dh_wav_size;
unsigned  long * audio_buf_uh_eh = ( unsigned  long *)&_binary_uh_eh_wav_start;
unsigned long size_uh_eh = ( unsigned long )&_binary_uh_eh_wav_size;
unsigned  long * audio_buf_uh_er = ( unsigned  long *)&_binary_uh_er_wav_start;
unsigned long size_uh_er = ( unsigned long )&_binary_uh_er_wav_size;
unsigned  long * audio_buf_uh_ey = ( unsigned  long *)&_binary_uh_ey_wav_start;
unsigned long size_uh_ey = ( unsigned long )&_binary_uh_ey_wav_size;
unsigned  long * audio_buf_uh_f = ( unsigned  long *)&_binary_uh_f_wav_start;
unsigned long size_uh_f = ( unsigned long )&_binary_uh_f_wav_size;
unsigned  long * audio_buf_uh_g = ( unsigned  long *)&_binary_uh_g_wav_start;
unsigned long size_uh_g = ( unsigned long )&_binary_uh_g_wav_size;
unsigned  long * audio_buf_uh_hh = ( unsigned  long *)&_binary_uh_hh_wav_start;
unsigned long size_uh_hh = ( unsigned long )&_binary_uh_hh_wav_size;
unsigned  long * audio_buf_uh_ih = ( unsigned  long *)&_binary_uh_ih_wav_start;
unsigned long size_uh_ih = ( unsigned long )&_binary_uh_ih_wav_size;
unsigned  long * audio_buf_uh_iy = ( unsigned  long *)&_binary_uh_iy_wav_start;
unsigned long size_uh_iy = ( unsigned long )&_binary_uh_iy_wav_size;
unsigned  long * audio_buf_uh_jh = ( unsigned  long *)&_binary_uh_jh_wav_start;
unsigned long size_uh_jh = ( unsigned long )&_binary_uh_jh_wav_size;
unsigned  long * audio_buf_uh_k = ( unsigned  long *)&_binary_uh_k_wav_start;
unsigned long size_uh_k = ( unsigned long )&_binary_uh_k_wav_size;
unsigned  long * audio_buf_uh_l = ( unsigned  long *)&_binary_uh_l_wav_start;
unsigned long size_uh_l = ( unsigned long )&_binary_uh_l_wav_size;
unsigned  long * audio_buf_uh_m = ( unsigned  long *)&_binary_uh_m_wav_start;
unsigned long size_uh_m = ( unsigned long )&_binary_uh_m_wav_size;
unsigned  long * audio_buf_uh_n = ( unsigned  long *)&_binary_uh_n_wav_start;
unsigned long size_uh_n = ( unsigned long )&_binary_uh_n_wav_size;
unsigned  long * audio_buf_uh_ng = ( unsigned  long *)&_binary_uh_ng_wav_start;
unsigned long size_uh_ng = ( unsigned long )&_binary_uh_ng_wav_size;
unsigned  long * audio_buf_uh_ow = ( unsigned  long *)&_binary_uh_ow_wav_start;
unsigned long size_uh_ow = ( unsigned long )&_binary_uh_ow_wav_size;
unsigned  long * audio_buf_uh_oy = ( unsigned  long *)&_binary_uh_oy_wav_start;
unsigned long size_uh_oy = ( unsigned long )&_binary_uh_oy_wav_size;
unsigned  long * audio_buf_uh_p = ( unsigned  long *)&_binary_uh_p_wav_start;
unsigned long size_uh_p = ( unsigned long )&_binary_uh_p_wav_size;
unsigned  long * audio_buf_uh_pau = ( unsigned  long *)&_binary_uh_pau_wav_start;
unsigned long size_uh_pau = ( unsigned long )&_binary_uh_pau_wav_size;
unsigned  long * audio_buf_uh_r = ( unsigned  long *)&_binary_uh_r_wav_start;
unsigned long size_uh_r = ( unsigned long )&_binary_uh_r_wav_size;
unsigned  long * audio_buf_uh_s = ( unsigned  long *)&_binary_uh_s_wav_start;
unsigned long size_uh_s = ( unsigned long )&_binary_uh_s_wav_size;
unsigned  long * audio_buf_uh_sh = ( unsigned  long *)&_binary_uh_sh_wav_start;
unsigned long size_uh_sh = ( unsigned long )&_binary_uh_sh_wav_size;
unsigned  long * audio_buf_uh_t = ( unsigned  long *)&_binary_uh_t_wav_start;
unsigned long size_uh_t = ( unsigned long )&_binary_uh_t_wav_size;
unsigned  long * audio_buf_uh_th = ( unsigned  long *)&_binary_uh_th_wav_start;
unsigned long size_uh_th = ( unsigned long )&_binary_uh_th_wav_size;
unsigned  long * audio_buf_uh_uh = ( unsigned  long *)&_binary_uh_uh_wav_start;
unsigned long size_uh_uh = ( unsigned long )&_binary_uh_uh_wav_size;
unsigned  long * audio_buf_uh_uw = ( unsigned  long *)&_binary_uh_uw_wav_start;
unsigned long size_uh_uw = ( unsigned long )&_binary_uh_uw_wav_size;
unsigned  long * audio_buf_uh_v = ( unsigned  long *)&_binary_uh_v_wav_start;
unsigned long size_uh_v = ( unsigned long )&_binary_uh_v_wav_size;
unsigned  long * audio_buf_uh_w = ( unsigned  long *)&_binary_uh_w_wav_start;
unsigned long size_uh_w = ( unsigned long )&_binary_uh_w_wav_size;
unsigned  long * audio_buf_uh_y = ( unsigned  long *)&_binary_uh_y_wav_start;
unsigned long size_uh_y = ( unsigned long )&_binary_uh_y_wav_size;
unsigned  long * audio_buf_uh_z = ( unsigned  long *)&_binary_uh_z_wav_start;
unsigned long size_uh_z = ( unsigned long )&_binary_uh_z_wav_size;
unsigned  long * audio_buf_uh_zh = ( unsigned  long *)&_binary_uh_zh_wav_start;
unsigned long size_uh_zh = ( unsigned long )&_binary_uh_zh_wav_size;
//uh diphones
file_write("/tmp/uh-aa.wav",audio_buf_uh_aa,size_uh_aa);
file_write("/tmp/uh-ae.wav",audio_buf_uh_ae,size_uh_ae);
file_write("/tmp/uh-ah.wav",audio_buf_uh_ah,size_uh_ah);
file_write("/tmp/uh-ao.wav",audio_buf_uh_ao,size_uh_ao);
file_write("/tmp/uh-aw.wav",audio_buf_uh_aw,size_uh_aw);
file_write("/tmp/uh-ax.wav",audio_buf_uh_ax,size_uh_ax);
file_write("/tmp/uh-ay.wav",audio_buf_uh_ay,size_uh_ay);
file_write("/tmp/uh-b.wav",audio_buf_uh_b,size_uh_b);
file_write("/tmp/uh-ch.wav",audio_buf_uh_ch,size_uh_ch);
file_write("/tmp/uh-d.wav",audio_buf_uh_d,size_uh_d);
file_write("/tmp/uh-dh.wav",audio_buf_uh_dh,size_uh_dh);
file_write("/tmp/uh-eh.wav",audio_buf_uh_eh,size_uh_eh);
file_write("/tmp/uh-er.wav",audio_buf_uh_er,size_uh_er);
file_write("/tmp/uh-ey.wav",audio_buf_uh_ey,size_uh_ey);
file_write("/tmp/uh-f.wav",audio_buf_uh_f,size_uh_f);
file_write("/tmp/uh-g.wav",audio_buf_uh_g,size_uh_g);
file_write("/tmp/uh-hh.wav",audio_buf_uh_hh,size_uh_hh);
file_write("/tmp/uh-ih.wav",audio_buf_uh_ih,size_uh_ih);
file_write("/tmp/uh-iy.wav",audio_buf_uh_iy,size_uh_iy);
file_write("/tmp/uh-jh.wav",audio_buf_uh_jh,size_uh_jh);
file_write("/tmp/uh-k.wav",audio_buf_uh_k,size_uh_k);
file_write("/tmp/uh-l.wav",audio_buf_uh_l,size_uh_l);
file_write("/tmp/uh-m.wav",audio_buf_uh_m,size_uh_m);
file_write("/tmp/uh-n.wav",audio_buf_uh_n,size_uh_n);
file_write("/tmp/uh-ng.wav",audio_buf_uh_ng,size_uh_ng);
file_write("/tmp/uh-ow.wav",audio_buf_uh_ow,size_uh_ow);
file_write("/tmp/uh-oy.wav",audio_buf_uh_oy,size_uh_oy);
file_write("/tmp/uh-p.wav",audio_buf_uh_p,size_uh_p);
file_write("/tmp/uh-pau.wav",audio_buf_uh_pau,size_uh_pau);
file_write("/tmp/uh-r.wav",audio_buf_uh_r,size_uh_r);
file_write("/tmp/uh-s.wav",audio_buf_uh_s,size_uh_s);
file_write("/tmp/uh-sh.wav",audio_buf_uh_sh,size_uh_sh);
file_write("/tmp/uh-t.wav",audio_buf_uh_t,size_uh_t);
file_write("/tmp/uh-th.wav",audio_buf_uh_th,size_uh_th);
file_write("/tmp/uh-uh.wav",audio_buf_uh_uh,size_uh_uh);
file_write("/tmp/uh-uw.wav",audio_buf_uh_uw,size_uh_uw);
file_write("/tmp/uh-v.wav",audio_buf_uh_v,size_uh_v);
file_write("/tmp/uh-w.wav",audio_buf_uh_w,size_uh_w);
file_write("/tmp/uh-y.wav",audio_buf_uh_y,size_uh_y);
file_write("/tmp/uh-z.wav",audio_buf_uh_z,size_uh_z);
file_write("/tmp/uh-zh.wav",audio_buf_uh_zh,size_uh_zh);

//uw diphones  
unsigned  long * audio_buf_uw_aa = ( unsigned  long *)&_binary_uw_aa_wav_start; 
unsigned long size_uw_aa = ( unsigned long )&_binary_uw_aa_wav_size;
unsigned  long * audio_buf_uw_ae = ( unsigned  long *)&_binary_uw_ae_wav_start;
unsigned long size_uw_ae = ( unsigned long )&_binary_uw_ae_wav_size;
unsigned  long * audio_buf_uw_ah = ( unsigned  long *)&_binary_uw_ah_wav_start;
unsigned long size_uw_ah = ( unsigned long )&_binary_uw_ah_wav_size;
unsigned  long * audio_buf_uw_ao = ( unsigned  long *)&_binary_uw_ao_wav_start;
unsigned long size_uw_ao = ( unsigned long )&_binary_uw_ao_wav_size;
unsigned  long * audio_buf_uw_aw = ( unsigned  long *)&_binary_uw_aw_wav_start;
unsigned long size_uw_aw = ( unsigned long )&_binary_uw_aw_wav_size;
unsigned  long * audio_buf_uw_ax = ( unsigned  long *)&_binary_uw_ax_wav_start;
unsigned long size_uw_ax = ( unsigned long )&_binary_uw_ax_wav_size;
unsigned  long * audio_buf_uw_ay = ( unsigned  long *)&_binary_uw_ay_wav_start;
unsigned long size_uw_ay = ( unsigned long )&_binary_uw_ay_wav_size;
unsigned  long * audio_buf_uw_b = ( unsigned  long *)&_binary_uw_b_wav_start;
unsigned long size_uw_b = ( unsigned long )&_binary_uw_b_wav_size;
unsigned  long * audio_buf_uw_ch = ( unsigned  long *)&_binary_uw_ch_wav_start;
unsigned long size_uw_ch = ( unsigned long )&_binary_uw_ch_wav_size;
unsigned  long * audio_buf_uw_d = ( unsigned  long *)&_binary_uw_d_wav_start;
unsigned long size_uw_d = ( unsigned long )&_binary_uw_d_wav_size;
unsigned  long * audio_buf_uw_dh = ( unsigned  long *)&_binary_uw_dh_wav_start;
unsigned long size_uw_dh = ( unsigned long )&_binary_uw_dh_wav_size;
unsigned  long * audio_buf_uw_eh = ( unsigned  long *)&_binary_uw_eh_wav_start;
unsigned long size_uw_eh = ( unsigned long )&_binary_uw_eh_wav_size;
unsigned  long * audio_buf_uw_er = ( unsigned  long *)&_binary_uw_er_wav_start;
unsigned long size_uw_er = ( unsigned long )&_binary_uw_er_wav_size;
unsigned  long * audio_buf_uw_ey = ( unsigned  long *)&_binary_uw_ey_wav_start;
unsigned long size_uw_ey = ( unsigned long )&_binary_uw_ey_wav_size;
unsigned  long * audio_buf_uw_f = ( unsigned  long *)&_binary_uw_f_wav_start;
unsigned long size_uw_f = ( unsigned long )&_binary_uw_f_wav_size;
unsigned  long * audio_buf_uw_g = ( unsigned  long *)&_binary_uw_g_wav_start;
unsigned long size_uw_g = ( unsigned long )&_binary_uw_g_wav_size;
unsigned  long * audio_buf_uw_hh = ( unsigned  long *)&_binary_uw_hh_wav_start;
unsigned long size_uw_hh = ( unsigned long )&_binary_uw_hh_wav_size;
unsigned  long * audio_buf_uw_ih = ( unsigned  long *)&_binary_uw_ih_wav_start;
unsigned long size_uw_ih = ( unsigned long )&_binary_uw_ih_wav_size;
unsigned  long * audio_buf_uw_iy = ( unsigned  long *)&_binary_uw_iy_wav_start;
unsigned long size_uw_iy = ( unsigned long )&_binary_uw_iy_wav_size;
unsigned  long * audio_buf_uw_jh = ( unsigned  long *)&_binary_uw_jh_wav_start;
unsigned long size_uw_jh = ( unsigned long )&_binary_uw_jh_wav_size;
unsigned  long * audio_buf_uw_k = ( unsigned  long *)&_binary_uw_k_wav_start;
unsigned long size_uw_k = ( unsigned long )&_binary_uw_k_wav_size;
unsigned  long * audio_buf_uw_l = ( unsigned  long *)&_binary_uw_l_wav_start;
unsigned long size_uw_l = ( unsigned long )&_binary_uw_l_wav_size;
unsigned  long * audio_buf_uw_m = ( unsigned  long *)&_binary_uw_m_wav_start;
unsigned long size_uw_m = ( unsigned long )&_binary_uw_m_wav_size;
unsigned  long * audio_buf_uw_n = ( unsigned  long *)&_binary_uw_n_wav_start;
unsigned long size_uw_n = ( unsigned long )&_binary_uw_n_wav_size;
unsigned  long * audio_buf_uw_ng = ( unsigned  long *)&_binary_uw_ng_wav_start;
unsigned long size_uw_ng = ( unsigned long )&_binary_uw_ng_wav_size;
unsigned  long * audio_buf_uw_ow = ( unsigned  long *)&_binary_uw_ow_wav_start;
unsigned long size_uw_ow = ( unsigned long )&_binary_uw_ow_wav_size;
unsigned  long * audio_buf_uw_oy = ( unsigned  long *)&_binary_uw_oy_wav_start;
unsigned long size_uw_oy = ( unsigned long )&_binary_uw_oy_wav_size;
unsigned  long * audio_buf_uw_p = ( unsigned  long *)&_binary_uw_p_wav_start;
unsigned long size_uw_p = ( unsigned long )&_binary_uw_p_wav_size;
unsigned  long * audio_buf_uw_pau = ( unsigned  long *)&_binary_uw_pau_wav_start;
unsigned long size_uw_pau = ( unsigned long )&_binary_uw_pau_wav_size;
unsigned  long * audio_buf_uw_r = ( unsigned  long *)&_binary_uw_r_wav_start;
unsigned long size_uw_r = ( unsigned long )&_binary_uw_r_wav_size;
unsigned  long * audio_buf_uw_s = ( unsigned  long *)&_binary_uw_s_wav_start;
unsigned long size_uw_s = ( unsigned long )&_binary_uw_s_wav_size;
unsigned  long * audio_buf_uw_sh = ( unsigned  long *)&_binary_uw_sh_wav_start;
unsigned long size_uw_sh = ( unsigned long )&_binary_uw_sh_wav_size;
unsigned  long * audio_buf_uw_t = ( unsigned  long *)&_binary_uw_t_wav_start;
unsigned long size_uw_t = ( unsigned long )&_binary_uw_t_wav_size;
unsigned  long * audio_buf_uw_th = ( unsigned  long *)&_binary_uw_th_wav_start;
unsigned long size_uw_th = ( unsigned long )&_binary_uw_th_wav_size;
unsigned  long * audio_buf_uw_uh = ( unsigned  long *)&_binary_uw_uh_wav_start;
unsigned long size_uw_uh = ( unsigned long )&_binary_uw_uh_wav_size;
unsigned  long * audio_buf_uw_uw = ( unsigned  long *)&_binary_uw_uw_wav_start;
unsigned long size_uw_uw = ( unsigned long )&_binary_uw_uw_wav_size;
unsigned  long * audio_buf_uw_v = ( unsigned  long *)&_binary_uw_v_wav_start;
unsigned long size_uw_v = ( unsigned long )&_binary_uw_v_wav_size;
unsigned  long * audio_buf_uw_w = ( unsigned  long *)&_binary_uw_w_wav_start;
unsigned long size_uw_w = ( unsigned long )&_binary_uw_w_wav_size;
unsigned  long * audio_buf_uw_y = ( unsigned  long *)&_binary_uw_y_wav_start;
unsigned long size_uw_y = ( unsigned long )&_binary_uw_y_wav_size;
unsigned  long * audio_buf_uw_z = ( unsigned  long *)&_binary_uw_z_wav_start;
unsigned long size_uw_z = ( unsigned long )&_binary_uw_z_wav_size;
unsigned  long * audio_buf_uw_zh = ( unsigned  long *)&_binary_uw_zh_wav_start;
unsigned long size_uw_zh = ( unsigned long )&_binary_uw_zh_wav_size;
//uw diphones
file_write("/tmp/uw-aa.wav",audio_buf_uw_aa,size_uw_aa);
file_write("/tmp/uw-ae.wav",audio_buf_uw_ae,size_uw_ae);
file_write("/tmp/uw-ah.wav",audio_buf_uw_ah,size_uw_ah);
file_write("/tmp/uw-ao.wav",audio_buf_uw_ao,size_uw_ao);
file_write("/tmp/uw-aw.wav",audio_buf_uw_aw,size_uw_aw);
file_write("/tmp/uw-ax.wav",audio_buf_uw_ax,size_uw_ax);
file_write("/tmp/uw-ay.wav",audio_buf_uw_ay,size_uw_ay);
file_write("/tmp/uw-b.wav",audio_buf_uw_b,size_uw_b);
file_write("/tmp/uw-ch.wav",audio_buf_uw_ch,size_uw_ch);
file_write("/tmp/uw-d.wav",audio_buf_uw_d,size_uw_d);
file_write("/tmp/uw-dh.wav",audio_buf_uw_dh,size_uw_dh);
file_write("/tmp/uw-eh.wav",audio_buf_uw_eh,size_uw_eh);
file_write("/tmp/uw-er.wav",audio_buf_uw_er,size_uw_er);
file_write("/tmp/uw-ey.wav",audio_buf_uw_ey,size_uw_ey);
file_write("/tmp/uw-f.wav",audio_buf_uw_f,size_uw_f);
file_write("/tmp/uw-g.wav",audio_buf_uw_g,size_uw_g);
file_write("/tmp/uw-hh.wav",audio_buf_uw_hh,size_uw_hh);
file_write("/tmp/uw-ih.wav",audio_buf_uw_ih,size_uw_ih);
file_write("/tmp/uw-iy.wav",audio_buf_uw_iy,size_uw_iy);
file_write("/tmp/uw-jh.wav",audio_buf_uw_jh,size_uw_jh);
file_write("/tmp/uw-k.wav",audio_buf_uw_k,size_uw_k);
file_write("/tmp/uw-l.wav",audio_buf_uw_l,size_uw_l);
file_write("/tmp/uw-m.wav",audio_buf_uw_m,size_uw_m);
file_write("/tmp/uw-n.wav",audio_buf_uw_n,size_uw_n);
file_write("/tmp/uw-ng.wav",audio_buf_uw_ng,size_uw_ng);
file_write("/tmp/uw-ow.wav",audio_buf_uw_ow,size_uw_ow);
file_write("/tmp/uw-oy.wav",audio_buf_uw_oy,size_uw_oy);
file_write("/tmp/uw-p.wav",audio_buf_uw_p,size_uw_p);
file_write("/tmp/uw-pau.wav",audio_buf_uw_pau,size_uw_pau);
file_write("/tmp/uw-r.wav",audio_buf_uw_r,size_uw_r);
file_write("/tmp/uw-s.wav",audio_buf_uw_s,size_uw_s);
file_write("/tmp/uw-sh.wav",audio_buf_uw_sh,size_uw_sh);
file_write("/tmp/uw-t.wav",audio_buf_uw_t,size_uw_t);
file_write("/tmp/uw-th.wav",audio_buf_uw_th,size_uw_th);
file_write("/tmp/uw-uh.wav",audio_buf_uw_uh,size_uw_uh);
file_write("/tmp/uw-uw.wav",audio_buf_uw_uw,size_uw_uw);
file_write("/tmp/uw-v.wav",audio_buf_uw_v,size_uw_v);
file_write("/tmp/uw-w.wav",audio_buf_uw_w,size_uw_w);
file_write("/tmp/uw-y.wav",audio_buf_uw_y,size_uw_y);
file_write("/tmp/uw-z.wav",audio_buf_uw_z,size_uw_z);
file_write("/tmp/uw-zh.wav",audio_buf_uw_zh,size_uw_zh);

//v diphones  
unsigned  long * audio_buf_v_aa = ( unsigned  long *)&_binary_v_aa_wav_start; 
unsigned long size_v_aa = ( unsigned long )&_binary_v_aa_wav_size;
unsigned  long * audio_buf_v_ae = ( unsigned  long *)&_binary_v_ae_wav_start;
unsigned long size_v_ae = ( unsigned long )&_binary_v_ae_wav_size;
unsigned  long * audio_buf_v_ah = ( unsigned  long *)&_binary_v_ah_wav_start;
unsigned long size_v_ah = ( unsigned long )&_binary_v_ah_wav_size;
unsigned  long * audio_buf_v_ao = ( unsigned  long *)&_binary_v_ao_wav_start;
unsigned long size_v_ao = ( unsigned long )&_binary_v_ao_wav_size;
unsigned  long * audio_buf_v_aw = ( unsigned  long *)&_binary_v_aw_wav_start;
unsigned long size_v_aw = ( unsigned long )&_binary_v_aw_wav_size;
unsigned  long * audio_buf_v_ax = ( unsigned  long *)&_binary_v_ax_wav_start;
unsigned long size_v_ax = ( unsigned long )&_binary_v_ax_wav_size;
unsigned  long * audio_buf_v_ay = ( unsigned  long *)&_binary_v_ay_wav_start;
unsigned long size_v_ay = ( unsigned long )&_binary_v_ay_wav_size;
unsigned  long * audio_buf_v_b = ( unsigned  long *)&_binary_v_b_wav_start;
unsigned long size_v_b = ( unsigned long )&_binary_v_b_wav_size;
unsigned  long * audio_buf_v_ch = ( unsigned  long *)&_binary_v_ch_wav_start;
unsigned long size_v_ch = ( unsigned long )&_binary_v_ch_wav_size;
unsigned  long * audio_buf_v_d = ( unsigned  long *)&_binary_v_d_wav_start;
unsigned long size_v_d = ( unsigned long )&_binary_v_d_wav_size;
unsigned  long * audio_buf_v_dh = ( unsigned  long *)&_binary_v_dh_wav_start;
unsigned long size_v_dh = ( unsigned long )&_binary_v_dh_wav_size;
unsigned  long * audio_buf_v_eh = ( unsigned  long *)&_binary_v_eh_wav_start;
unsigned long size_v_eh = ( unsigned long )&_binary_v_eh_wav_size;
unsigned  long * audio_buf_v_er = ( unsigned  long *)&_binary_v_er_wav_start;
unsigned long size_v_er = ( unsigned long )&_binary_v_er_wav_size;
unsigned  long * audio_buf_v_ey = ( unsigned  long *)&_binary_v_ey_wav_start;
unsigned long size_v_ey = ( unsigned long )&_binary_v_ey_wav_size;
unsigned  long * audio_buf_v_f = ( unsigned  long *)&_binary_v_f_wav_start;
unsigned long size_v_f = ( unsigned long )&_binary_v_f_wav_size;
unsigned  long * audio_buf_v_g = ( unsigned  long *)&_binary_v_g_wav_start;
unsigned long size_v_g = ( unsigned long )&_binary_v_g_wav_size;
unsigned  long * audio_buf_v_hh = ( unsigned  long *)&_binary_v_hh_wav_start;
unsigned long size_v_hh = ( unsigned long )&_binary_v_hh_wav_size;
unsigned  long * audio_buf_v_ih = ( unsigned  long *)&_binary_v_ih_wav_start;
unsigned long size_v_ih = ( unsigned long )&_binary_v_ih_wav_size;
unsigned  long * audio_buf_v_iy = ( unsigned  long *)&_binary_v_iy_wav_start;
unsigned long size_v_iy = ( unsigned long )&_binary_v_iy_wav_size;
unsigned  long * audio_buf_v_jh = ( unsigned  long *)&_binary_v_jh_wav_start;
unsigned long size_v_jh = ( unsigned long )&_binary_v_jh_wav_size;
unsigned  long * audio_buf_v_k = ( unsigned  long *)&_binary_v_k_wav_start;
unsigned long size_v_k = ( unsigned long )&_binary_v_k_wav_size;
unsigned  long * audio_buf_v_l = ( unsigned  long *)&_binary_v_l_wav_start;
unsigned long size_v_l = ( unsigned long )&_binary_v_l_wav_size;
unsigned  long * audio_buf_v_m = ( unsigned  long *)&_binary_v_m_wav_start;
unsigned long size_v_m = ( unsigned long )&_binary_v_m_wav_size;
unsigned  long * audio_buf_v_n = ( unsigned  long *)&_binary_v_n_wav_start;
unsigned long size_v_n = ( unsigned long )&_binary_v_n_wav_size;
unsigned  long * audio_buf_v_ow = ( unsigned  long *)&_binary_v_ow_wav_start;
unsigned long size_v_ow = ( unsigned long )&_binary_v_ow_wav_size;
unsigned  long * audio_buf_v_oy = ( unsigned  long *)&_binary_v_oy_wav_start;
unsigned long size_v_oy = ( unsigned long )&_binary_v_oy_wav_size;
unsigned  long * audio_buf_v_p = ( unsigned  long *)&_binary_v_p_wav_start;
unsigned long size_v_p = ( unsigned long )&_binary_v_p_wav_size;
unsigned  long * audio_buf_v_pau = ( unsigned  long *)&_binary_v_pau_wav_start;
unsigned long size_v_pau = ( unsigned long )&_binary_v_pau_wav_size;
unsigned  long * audio_buf_v_r = ( unsigned  long *)&_binary_v_r_wav_start;
unsigned long size_v_r = ( unsigned long )&_binary_v_r_wav_size;
unsigned  long * audio_buf_v_s = ( unsigned  long *)&_binary_v_s_wav_start;
unsigned long size_v_s = ( unsigned long )&_binary_v_s_wav_size;
unsigned  long * audio_buf_v_sh = ( unsigned  long *)&_binary_v_sh_wav_start;
unsigned long size_v_sh = ( unsigned long )&_binary_v_sh_wav_size;
unsigned  long * audio_buf_v_t = ( unsigned  long *)&_binary_v_t_wav_start;
unsigned long size_v_t = ( unsigned long )&_binary_v_t_wav_size;
unsigned  long * audio_buf_v_th = ( unsigned  long *)&_binary_v_th_wav_start;
unsigned long size_v_th = ( unsigned long )&_binary_v_th_wav_size;
unsigned  long * audio_buf_v_uh = ( unsigned  long *)&_binary_v_uh_wav_start;
unsigned long size_v_uh = ( unsigned long )&_binary_v_uh_wav_size;
unsigned  long * audio_buf_v_uw = ( unsigned  long *)&_binary_v_uw_wav_start;
unsigned long size_v_uw = ( unsigned long )&_binary_v_uw_wav_size;
unsigned  long * audio_buf_v_v = ( unsigned  long *)&_binary_v_v_wav_start;
unsigned long size_v_v = ( unsigned long )&_binary_v_v_wav_size;
unsigned  long * audio_buf_v_w = ( unsigned  long *)&_binary_v_w_wav_start;
unsigned long size_v_w = ( unsigned long )&_binary_v_w_wav_size;
unsigned  long * audio_buf_v_y = ( unsigned  long *)&_binary_v_y_wav_start;
unsigned long size_v_y = ( unsigned long )&_binary_v_y_wav_size;
unsigned  long * audio_buf_v_z = ( unsigned  long *)&_binary_v_z_wav_start;
unsigned long size_v_z = ( unsigned long )&_binary_v_z_wav_size;
unsigned  long * audio_buf_v_zh = ( unsigned  long *)&_binary_v_zh_wav_start;
unsigned long size_v_zh = ( unsigned long )&_binary_v_zh_wav_size;
//v diphones
file_write("/tmp/v-aa.wav",audio_buf_v_aa,size_v_aa);
file_write("/tmp/v-ae.wav",audio_buf_v_ae,size_v_ae);
file_write("/tmp/v-ah.wav",audio_buf_v_ah,size_v_ah);
file_write("/tmp/v-ao.wav",audio_buf_v_ao,size_v_ao);
file_write("/tmp/v-aw.wav",audio_buf_v_aw,size_v_aw);
file_write("/tmp/v-ax.wav",audio_buf_v_ax,size_v_ax);
file_write("/tmp/v-ay.wav",audio_buf_v_ay,size_v_ay);
file_write("/tmp/v-b.wav",audio_buf_v_b,size_v_b);
file_write("/tmp/v-ch.wav",audio_buf_v_ch,size_v_ch);
file_write("/tmp/v-d.wav",audio_buf_v_d,size_v_d);
file_write("/tmp/v-dh.wav",audio_buf_v_dh,size_v_dh);
file_write("/tmp/v-eh.wav",audio_buf_v_eh,size_v_eh);
file_write("/tmp/v-er.wav",audio_buf_v_er,size_v_er);
file_write("/tmp/v-ey.wav",audio_buf_v_ey,size_v_ey);
file_write("/tmp/v-f.wav",audio_buf_v_f,size_v_f);
file_write("/tmp/v-g.wav",audio_buf_v_g,size_v_g);
file_write("/tmp/v-hh.wav",audio_buf_v_hh,size_v_hh);
file_write("/tmp/v-ih.wav",audio_buf_v_ih,size_v_ih);
file_write("/tmp/v-iy.wav",audio_buf_v_iy,size_v_iy);
file_write("/tmp/v-jh.wav",audio_buf_v_jh,size_v_jh);
file_write("/tmp/v-k.wav",audio_buf_v_k,size_v_k);
file_write("/tmp/v-l.wav",audio_buf_v_l,size_v_l);
file_write("/tmp/v-m.wav",audio_buf_v_m,size_v_m);
file_write("/tmp/v-n.wav",audio_buf_v_n,size_v_n);
file_write("/tmp/v-ow.wav",audio_buf_v_ow,size_v_ow);
file_write("/tmp/v-oy.wav",audio_buf_v_oy,size_v_oy);
file_write("/tmp/v-p.wav",audio_buf_v_p,size_v_p);
file_write("/tmp/v-pau.wav",audio_buf_v_pau,size_v_pau);
file_write("/tmp/v-r.wav",audio_buf_v_r,size_v_r);
file_write("/tmp/v-s.wav",audio_buf_v_s,size_v_s);
file_write("/tmp/v-sh.wav",audio_buf_v_sh,size_v_sh);
file_write("/tmp/v-t.wav",audio_buf_v_t,size_v_t);
file_write("/tmp/v-th.wav",audio_buf_v_th,size_v_th);
file_write("/tmp/v-uh.wav",audio_buf_v_uh,size_v_uh);
file_write("/tmp/v-uw.wav",audio_buf_v_uw,size_v_uw);
file_write("/tmp/v-v.wav",audio_buf_v_v,size_v_v);
file_write("/tmp/v-w.wav",audio_buf_v_w,size_v_w);
file_write("/tmp/v-y.wav",audio_buf_v_y,size_v_y);
file_write("/tmp/v-z.wav",audio_buf_v_z,size_v_z);
file_write("/tmp/v-zh.wav",audio_buf_v_zh,size_v_zh);

//w diphones  
unsigned  long * audio_buf_w_aa = ( unsigned  long *)&_binary_w_aa_wav_start; 
unsigned long size_w_aa = ( unsigned long )&_binary_w_aa_wav_size;
unsigned  long * audio_buf_w_ae = ( unsigned  long *)&_binary_w_ae_wav_start;
unsigned long size_w_ae = ( unsigned long )&_binary_w_ae_wav_size;
unsigned  long * audio_buf_w_ah = ( unsigned  long *)&_binary_w_ah_wav_start;
unsigned long size_w_ah = ( unsigned long )&_binary_w_ah_wav_size;
unsigned  long * audio_buf_w_ao = ( unsigned  long *)&_binary_w_ao_wav_start;
unsigned long size_w_ao = ( unsigned long )&_binary_w_ao_wav_size;
unsigned  long * audio_buf_w_aw = ( unsigned  long *)&_binary_w_aw_wav_start;
unsigned long size_w_aw = ( unsigned long )&_binary_w_aw_wav_size;
unsigned  long * audio_buf_w_ax = ( unsigned  long *)&_binary_w_ax_wav_start;
unsigned long size_w_ax = ( unsigned long )&_binary_w_ax_wav_size;
unsigned  long * audio_buf_w_ay = ( unsigned  long *)&_binary_w_ay_wav_start;
unsigned long size_w_ay = ( unsigned long )&_binary_w_ay_wav_size;
unsigned  long * audio_buf_w_eh = ( unsigned  long *)&_binary_w_eh_wav_start;
unsigned long size_w_eh = ( unsigned long )&_binary_w_eh_wav_size;
unsigned  long * audio_buf_w_ih = ( unsigned  long *)&_binary_w_ih_wav_start;
unsigned long size_w_ih = ( unsigned long )&_binary_w_ih_wav_size;
unsigned  long * audio_buf_w_iy = ( unsigned  long *)&_binary_w_iy_wav_start;
unsigned long size_w_iy = ( unsigned long )&_binary_w_iy_wav_size;
unsigned  long * audio_buf_w_uh = ( unsigned  long *)&_binary_w_uh_wav_start;
unsigned long size_w_uh = ( unsigned long )&_binary_w_uh_wav_size;
unsigned  long * audio_buf_w_uw = ( unsigned  long *)&_binary_w_uw_wav_start;
unsigned long size_w_uw = ( unsigned long )&_binary_w_uw_wav_size;
//w diphones
file_write("/tmp/w-aa.wav",audio_buf_w_aa,size_w_aa);
file_write("/tmp/w-ae.wav",audio_buf_w_ae,size_w_ae);
file_write("/tmp/w-ah.wav",audio_buf_w_ah,size_w_ah);
file_write("/tmp/w-ao.wav",audio_buf_w_ao,size_w_ao);
file_write("/tmp/w-aw.wav",audio_buf_w_aw,size_w_aw);
file_write("/tmp/w-ax.wav",audio_buf_w_ax,size_w_ax);
file_write("/tmp/w-ay.wav",audio_buf_w_ay,size_w_ay);
file_write("/tmp/w-eh.wav",audio_buf_w_eh,size_w_eh);
file_write("/tmp/w-ih.wav",audio_buf_w_ih,size_w_ih);
file_write("/tmp/w-iy.wav",audio_buf_w_iy,size_w_iy);
file_write("/tmp/w-uh.wav",audio_buf_w_uh,size_w_uh);
file_write("/tmp/w-uw.wav",audio_buf_w_uw,size_w_uw);

//y diphones  
unsigned  long * audio_buf_y_aa = ( unsigned  long *)&_binary_y_aa_wav_start; 
unsigned long size_y_aa = ( unsigned long )&_binary_y_aa_wav_size;
unsigned  long * audio_buf_y_ae = ( unsigned  long *)&_binary_y_ae_wav_start;
unsigned long size_y_ae = ( unsigned long )&_binary_y_ae_wav_size;
unsigned  long * audio_buf_y_ah = ( unsigned  long *)&_binary_y_ah_wav_start;
unsigned long size_y_ah = ( unsigned long )&_binary_y_ah_wav_size;
unsigned  long * audio_buf_y_ao = ( unsigned  long *)&_binary_y_ao_wav_start;
unsigned long size_y_ao = ( unsigned long )&_binary_y_ao_wav_size;
unsigned  long * audio_buf_y_aw = ( unsigned  long *)&_binary_y_aw_wav_start;
unsigned long size_y_aw = ( unsigned long )&_binary_y_aw_wav_size;
unsigned  long * audio_buf_y_ax = ( unsigned  long *)&_binary_y_ax_wav_start;
unsigned long size_y_ax = ( unsigned long )&_binary_y_ax_wav_size;
unsigned  long * audio_buf_y_ay = ( unsigned  long *)&_binary_y_ay_wav_start;
unsigned long size_y_ay = ( unsigned long )&_binary_y_ay_wav_size;
unsigned  long * audio_buf_y_eh = ( unsigned  long *)&_binary_y_eh_wav_start;
unsigned long size_y_eh = ( unsigned long )&_binary_y_eh_wav_size;
unsigned  long * audio_buf_y_ey = ( unsigned  long *)&_binary_y_ey_wav_start;
unsigned long size_y_ey = ( unsigned long )&_binary_y_ey_wav_size;
unsigned  long * audio_buf_y_ih = ( unsigned  long *)&_binary_y_ih_wav_start;
unsigned long size_y_ih = ( unsigned long )&_binary_y_ih_wav_size;
unsigned  long * audio_buf_y_iy = ( unsigned  long *)&_binary_y_iy_wav_start;
unsigned long size_y_iy = ( unsigned long )&_binary_y_iy_wav_size;
unsigned  long * audio_buf_y_ow = ( unsigned  long *)&_binary_y_ow_wav_start;
unsigned long size_y_ow = ( unsigned long )&_binary_y_ow_wav_size;
unsigned  long * audio_buf_y_oy = ( unsigned  long *)&_binary_y_oy_wav_start;
unsigned long size_y_oy = ( unsigned long )&_binary_y_oy_wav_size;
unsigned  long * audio_buf_y_uh = ( unsigned  long *)&_binary_y_uh_wav_start;
unsigned long size_y_uh = ( unsigned long )&_binary_y_uh_wav_size;
unsigned  long * audio_buf_y_uw = ( unsigned  long *)&_binary_y_uw_wav_start;
unsigned long size_y_uw = ( unsigned long )&_binary_y_uw_wav_size;
//y diphones
file_write("/tmp/y-aa.wav",audio_buf_y_aa,size_y_aa);
file_write("/tmp/y-ae.wav",audio_buf_y_ae,size_y_ae);
file_write("/tmp/y-ah.wav",audio_buf_y_ah,size_y_ah);
file_write("/tmp/y-ao.wav",audio_buf_y_ao,size_y_ao);
file_write("/tmp/y-aw.wav",audio_buf_y_aw,size_y_aw);
file_write("/tmp/y-ax.wav",audio_buf_y_ax,size_y_ax);
file_write("/tmp/y-ay.wav",audio_buf_y_ay,size_y_ay);
file_write("/tmp/y-eh.wav",audio_buf_y_eh,size_y_eh);
file_write("/tmp/y-ey.wav",audio_buf_y_ey,size_y_ey);
file_write("/tmp/y-ih.wav",audio_buf_y_ih,size_y_ih);
file_write("/tmp/y-iy.wav",audio_buf_y_iy,size_y_iy);
file_write("/tmp/y-ow.wav",audio_buf_y_ow,size_y_ow);
file_write("/tmp/y-oy.wav",audio_buf_y_oy,size_y_oy);
file_write("/tmp/y-uh.wav",audio_buf_y_uh,size_y_uh);
file_write("/tmp/y-uw.wav",audio_buf_y_uw,size_y_uw);

//z diphones  
unsigned  long * audio_buf_z_aa = ( unsigned  long *)&_binary_z_aa_wav_start; 
unsigned long size_z_aa = ( unsigned long )&_binary_z_aa_wav_size;
unsigned  long * audio_buf_z_ae = ( unsigned  long *)&_binary_z_ae_wav_start;
unsigned long size_z_ae = ( unsigned long )&_binary_z_ae_wav_size;
unsigned  long * audio_buf_z_ah = ( unsigned  long *)&_binary_z_ah_wav_start;
unsigned long size_z_ah = ( unsigned long )&_binary_z_ah_wav_size;
unsigned  long * audio_buf_z_ao = ( unsigned  long *)&_binary_z_ao_wav_start;
unsigned long size_z_ao = ( unsigned long )&_binary_z_ao_wav_size;
unsigned  long * audio_buf_z_aw = ( unsigned  long *)&_binary_z_aw_wav_start;
unsigned long size_z_aw = ( unsigned long )&_binary_z_aw_wav_size;
unsigned  long * audio_buf_z_ax = ( unsigned  long *)&_binary_z_ax_wav_start;
unsigned long size_z_ax = ( unsigned long )&_binary_z_ax_wav_size;
unsigned  long * audio_buf_z_ay = ( unsigned  long *)&_binary_z_ay_wav_start;
unsigned long size_z_ay = ( unsigned long )&_binary_z_ay_wav_size;
unsigned  long * audio_buf_z_b = ( unsigned  long *)&_binary_z_b_wav_start;
unsigned long size_z_b = ( unsigned long )&_binary_z_b_wav_size;
unsigned  long * audio_buf_z_ch = ( unsigned  long *)&_binary_z_ch_wav_start;
unsigned long size_z_ch = ( unsigned long )&_binary_z_ch_wav_size;
unsigned  long * audio_buf_z_d = ( unsigned  long *)&_binary_z_d_wav_start;
unsigned long size_z_d = ( unsigned long )&_binary_z_d_wav_size;
unsigned  long * audio_buf_z_dh = ( unsigned  long *)&_binary_z_dh_wav_start;
unsigned long size_z_dh = ( unsigned long )&_binary_z_dh_wav_size;
unsigned  long * audio_buf_z_eh = ( unsigned  long *)&_binary_z_eh_wav_start;
unsigned long size_z_eh = ( unsigned long )&_binary_z_eh_wav_size;
unsigned  long * audio_buf_z_er = ( unsigned  long *)&_binary_z_er_wav_start;
unsigned long size_z_er = ( unsigned long )&_binary_z_er_wav_size;
unsigned  long * audio_buf_z_ey = ( unsigned  long *)&_binary_z_ey_wav_start;
unsigned long size_z_ey = ( unsigned long )&_binary_z_ey_wav_size;
unsigned  long * audio_buf_z_f = ( unsigned  long *)&_binary_z_f_wav_start;
unsigned long size_z_f = ( unsigned long )&_binary_z_f_wav_size;
unsigned  long * audio_buf_z_g = ( unsigned  long *)&_binary_z_g_wav_start;
unsigned long size_z_g = ( unsigned long )&_binary_z_g_wav_size;
unsigned  long * audio_buf_z_hh = ( unsigned  long *)&_binary_z_hh_wav_start;
unsigned long size_z_hh = ( unsigned long )&_binary_z_hh_wav_size;
unsigned  long * audio_buf_z_ih = ( unsigned  long *)&_binary_z_ih_wav_start;
unsigned long size_z_ih = ( unsigned long )&_binary_z_ih_wav_size;
unsigned  long * audio_buf_z_iy = ( unsigned  long *)&_binary_z_iy_wav_start;
unsigned long size_z_iy = ( unsigned long )&_binary_z_iy_wav_size;
unsigned  long * audio_buf_z_jh = ( unsigned  long *)&_binary_z_jh_wav_start;
unsigned long size_z_jh = ( unsigned long )&_binary_z_jh_wav_size;
unsigned  long * audio_buf_z_k = ( unsigned  long *)&_binary_z_k_wav_start;
unsigned long size_z_k = ( unsigned long )&_binary_z_k_wav_size;
unsigned  long * audio_buf_z_l = ( unsigned  long *)&_binary_z_l_wav_start;
unsigned long size_z_l = ( unsigned long )&_binary_z_l_wav_size;
unsigned  long * audio_buf_z_m = ( unsigned  long *)&_binary_z_m_wav_start;
unsigned long size_z_m = ( unsigned long )&_binary_z_m_wav_size;
unsigned  long * audio_buf_z_n = ( unsigned  long *)&_binary_z_n_wav_start;
unsigned long size_z_n = ( unsigned long )&_binary_z_n_wav_size;
unsigned  long * audio_buf_z_ow = ( unsigned  long *)&_binary_z_ow_wav_start;
unsigned long size_z_ow = ( unsigned long )&_binary_z_ow_wav_size;
unsigned  long * audio_buf_z_oy = ( unsigned  long *)&_binary_z_oy_wav_start;
unsigned long size_z_oy = ( unsigned long )&_binary_z_oy_wav_size;
unsigned  long * audio_buf_z_p = ( unsigned  long *)&_binary_z_p_wav_start;
unsigned long size_z_p = ( unsigned long )&_binary_z_p_wav_size;
unsigned  long * audio_buf_z_pau = ( unsigned  long *)&_binary_z_pau_wav_start;
unsigned long size_z_pau = ( unsigned long )&_binary_z_pau_wav_size;
unsigned  long * audio_buf_z_r = ( unsigned  long *)&_binary_z_r_wav_start;
unsigned long size_z_r = ( unsigned long )&_binary_z_r_wav_size;
unsigned  long * audio_buf_z_s = ( unsigned  long *)&_binary_z_s_wav_start;
unsigned long size_z_s = ( unsigned long )&_binary_z_s_wav_size;
unsigned  long * audio_buf_z_sh = ( unsigned  long *)&_binary_z_sh_wav_start;
unsigned long size_z_sh = ( unsigned long )&_binary_z_sh_wav_size;
unsigned  long * audio_buf_z_t = ( unsigned  long *)&_binary_z_t_wav_start;
unsigned long size_z_t = ( unsigned long )&_binary_z_t_wav_size;
unsigned  long * audio_buf_z_th = ( unsigned  long *)&_binary_z_th_wav_start;
unsigned long size_z_th = ( unsigned long )&_binary_z_th_wav_size;
unsigned  long * audio_buf_z_uh = ( unsigned  long *)&_binary_z_uh_wav_start;
unsigned long size_z_uh = ( unsigned long )&_binary_z_uh_wav_size;
unsigned  long * audio_buf_z_uw = ( unsigned  long *)&_binary_z_uw_wav_start;
unsigned long size_z_uw = ( unsigned long )&_binary_z_uw_wav_size;
unsigned  long * audio_buf_z_v = ( unsigned  long *)&_binary_z_v_wav_start;
unsigned long size_z_v = ( unsigned long )&_binary_z_v_wav_size;
unsigned  long * audio_buf_z_w = ( unsigned  long *)&_binary_z_w_wav_start;
unsigned long size_z_w = ( unsigned long )&_binary_z_w_wav_size;
unsigned  long * audio_buf_z_y = ( unsigned  long *)&_binary_z_y_wav_start;
unsigned long size_z_y = ( unsigned long )&_binary_z_y_wav_size;
unsigned  long * audio_buf_z_z = ( unsigned  long *)&_binary_z_z_wav_start;
unsigned long size_z_z = ( unsigned long )&_binary_z_z_wav_size;
unsigned  long * audio_buf_z_zh = ( unsigned  long *)&_binary_z_zh_wav_start;
unsigned long size_z_zh = ( unsigned long )&_binary_z_zh_wav_size;
//z diphones
file_write("/tmp/z-aa.wav",audio_buf_z_aa,size_z_aa);
file_write("/tmp/z-ae.wav",audio_buf_z_ae,size_z_ae);
file_write("/tmp/z-ah.wav",audio_buf_z_ah,size_z_ah);
file_write("/tmp/z-ao.wav",audio_buf_z_ao,size_z_ao);
file_write("/tmp/z-aw.wav",audio_buf_z_aw,size_z_aw);
file_write("/tmp/z-ax.wav",audio_buf_z_ax,size_z_ax);
file_write("/tmp/z-ay.wav",audio_buf_z_ay,size_z_ay);
file_write("/tmp/z-b.wav",audio_buf_z_b,size_z_b);
file_write("/tmp/z-ch.wav",audio_buf_z_ch,size_z_ch);
file_write("/tmp/z-d.wav",audio_buf_z_d,size_z_d);
file_write("/tmp/z-dh.wav",audio_buf_z_dh,size_z_dh);
file_write("/tmp/z-eh.wav",audio_buf_z_eh,size_z_eh);
file_write("/tmp/z-er.wav",audio_buf_z_er,size_z_er);
file_write("/tmp/z-ey.wav",audio_buf_z_ey,size_z_ey);
file_write("/tmp/z-f.wav",audio_buf_z_f,size_z_f);
file_write("/tmp/z-g.wav",audio_buf_z_g,size_z_g);
file_write("/tmp/z-hh.wav",audio_buf_z_hh,size_z_hh);
file_write("/tmp/z-ih.wav",audio_buf_z_ih,size_z_ih);
file_write("/tmp/z-iy.wav",audio_buf_z_iy,size_z_iy);
file_write("/tmp/z-jh.wav",audio_buf_z_jh,size_z_jh);
file_write("/tmp/z-k.wav",audio_buf_z_k,size_z_k);
file_write("/tmp/z-l.wav",audio_buf_z_l,size_z_l);
file_write("/tmp/z-m.wav",audio_buf_z_m,size_z_m);
file_write("/tmp/z-n.wav",audio_buf_z_n,size_z_n);
file_write("/tmp/z-ow.wav",audio_buf_z_ow,size_z_ow);
file_write("/tmp/z-oy.wav",audio_buf_z_oy,size_z_oy);
file_write("/tmp/z-p.wav",audio_buf_z_p,size_z_p);
file_write("/tmp/z-pau.wav",audio_buf_z_pau,size_z_pau);
file_write("/tmp/z-r.wav",audio_buf_z_r,size_z_r);
file_write("/tmp/z-s.wav",audio_buf_z_s,size_z_s);
file_write("/tmp/z-sh.wav",audio_buf_z_sh,size_z_sh);
file_write("/tmp/z-t.wav",audio_buf_z_t,size_z_t);
file_write("/tmp/z-th.wav",audio_buf_z_th,size_z_th);
file_write("/tmp/z-uh.wav",audio_buf_z_uh,size_z_uh);
file_write("/tmp/z-uw.wav",audio_buf_z_uw,size_z_uw);
file_write("/tmp/z-v.wav",audio_buf_z_v,size_z_v);
file_write("/tmp/z-w.wav",audio_buf_z_w,size_z_w);
file_write("/tmp/z-y.wav",audio_buf_z_y,size_z_y);
file_write("/tmp/z-z.wav",audio_buf_z_z,size_z_z);
file_write("/tmp/z-zh.wav",audio_buf_z_zh,size_z_zh);

//zh diphones  
unsigned  long * audio_buf_zh_aa = ( unsigned  long *)&_binary_zh_aa_wav_start; 
unsigned long size_zh_aa = ( unsigned long )&_binary_zh_aa_wav_size;
unsigned  long * audio_buf_zh_ae = ( unsigned  long *)&_binary_zh_ae_wav_start;
unsigned long size_zh_ae = ( unsigned long )&_binary_zh_ae_wav_size;
unsigned  long * audio_buf_zh_ah = ( unsigned  long *)&_binary_zh_ah_wav_start;
unsigned long size_zh_ah = ( unsigned long )&_binary_zh_ah_wav_size;
unsigned  long * audio_buf_zh_ao = ( unsigned  long *)&_binary_zh_ao_wav_start;
unsigned long size_zh_ao = ( unsigned long )&_binary_zh_ao_wav_size;
unsigned  long * audio_buf_zh_aw = ( unsigned  long *)&_binary_zh_aw_wav_start;
unsigned long size_zh_aw = ( unsigned long )&_binary_zh_aw_wav_size;
unsigned  long * audio_buf_zh_ax = ( unsigned  long *)&_binary_zh_ax_wav_start;
unsigned long size_zh_ax = ( unsigned long )&_binary_zh_ax_wav_size;
unsigned  long * audio_buf_zh_ay = ( unsigned  long *)&_binary_zh_ay_wav_start;
unsigned long size_zh_ay = ( unsigned long )&_binary_zh_ay_wav_size;
unsigned  long * audio_buf_zh_b = ( unsigned  long *)&_binary_zh_b_wav_start;
unsigned long size_zh_b = ( unsigned long )&_binary_zh_b_wav_size;
unsigned  long * audio_buf_zh_ch = ( unsigned  long *)&_binary_zh_ch_wav_start;
unsigned long size_zh_ch = ( unsigned long )&_binary_zh_ch_wav_size;
unsigned  long * audio_buf_zh_d = ( unsigned  long *)&_binary_zh_d_wav_start;
unsigned long size_zh_d = ( unsigned long )&_binary_zh_d_wav_size;
unsigned  long * audio_buf_zh_dh = ( unsigned  long *)&_binary_zh_dh_wav_start;
unsigned long size_zh_dh = ( unsigned long )&_binary_zh_dh_wav_size;
unsigned  long * audio_buf_zh_eh = ( unsigned  long *)&_binary_zh_eh_wav_start;
unsigned long size_zh_eh = ( unsigned long )&_binary_zh_eh_wav_size;
unsigned  long * audio_buf_zh_er = ( unsigned  long *)&_binary_zh_er_wav_start;
unsigned long size_zh_er = ( unsigned long )&_binary_zh_er_wav_size;
unsigned  long * audio_buf_zh_ey = ( unsigned  long *)&_binary_zh_ey_wav_start;
unsigned long size_zh_ey = ( unsigned long )&_binary_zh_ey_wav_size;
unsigned  long * audio_buf_zh_f = ( unsigned  long *)&_binary_zh_f_wav_start;
unsigned long size_zh_f = ( unsigned long )&_binary_zh_f_wav_size;
unsigned  long * audio_buf_zh_g = ( unsigned  long *)&_binary_zh_g_wav_start;
unsigned long size_zh_g = ( unsigned long )&_binary_zh_g_wav_size;
unsigned  long * audio_buf_zh_hh = ( unsigned  long *)&_binary_zh_hh_wav_start;
unsigned long size_zh_hh = ( unsigned long )&_binary_zh_hh_wav_size;
unsigned  long * audio_buf_zh_ih = ( unsigned  long *)&_binary_zh_ih_wav_start;
unsigned long size_zh_ih = ( unsigned long )&_binary_zh_ih_wav_size;
unsigned  long * audio_buf_zh_iy = ( unsigned  long *)&_binary_zh_iy_wav_start;
unsigned long size_zh_iy = ( unsigned long )&_binary_zh_iy_wav_size;
unsigned  long * audio_buf_zh_jh = ( unsigned  long *)&_binary_zh_jh_wav_start;
unsigned long size_zh_jh = ( unsigned long )&_binary_zh_jh_wav_size;
unsigned  long * audio_buf_zh_k = ( unsigned  long *)&_binary_zh_k_wav_start;
unsigned long size_zh_k = ( unsigned long )&_binary_zh_k_wav_size;
unsigned  long * audio_buf_zh_l = ( unsigned  long *)&_binary_zh_l_wav_start;
unsigned long size_zh_l = ( unsigned long )&_binary_zh_l_wav_size;
unsigned  long * audio_buf_zh_m = ( unsigned  long *)&_binary_zh_m_wav_start;
unsigned long size_zh_m = ( unsigned long )&_binary_zh_m_wav_size;
unsigned  long * audio_buf_zh_n = ( unsigned  long *)&_binary_zh_n_wav_start;
unsigned long size_zh_n = ( unsigned long )&_binary_zh_n_wav_size;
unsigned  long * audio_buf_zh_ow = ( unsigned  long *)&_binary_zh_ow_wav_start;
unsigned long size_zh_ow = ( unsigned long )&_binary_zh_ow_wav_size;
unsigned  long * audio_buf_zh_oy = ( unsigned  long *)&_binary_zh_oy_wav_start;
unsigned long size_zh_oy = ( unsigned long )&_binary_zh_oy_wav_size;
unsigned  long * audio_buf_zh_p = ( unsigned  long *)&_binary_zh_p_wav_start;
unsigned long size_zh_p = ( unsigned long )&_binary_zh_p_wav_size;
unsigned  long * audio_buf_zh_pau = ( unsigned  long *)&_binary_zh_pau_wav_start;
unsigned long size_zh_pau = ( unsigned long )&_binary_zh_pau_wav_size;
unsigned  long * audio_buf_zh_r = ( unsigned  long *)&_binary_zh_r_wav_start;
unsigned long size_zh_r = ( unsigned long )&_binary_zh_r_wav_size;
unsigned  long * audio_buf_zh_s = ( unsigned  long *)&_binary_zh_s_wav_start;
unsigned long size_zh_s = ( unsigned long )&_binary_zh_s_wav_size;
unsigned  long * audio_buf_zh_sh = ( unsigned  long *)&_binary_zh_sh_wav_start;
unsigned long size_zh_sh = ( unsigned long )&_binary_zh_sh_wav_size;
unsigned  long * audio_buf_zh_t = ( unsigned  long *)&_binary_zh_t_wav_start;
unsigned long size_zh_t = ( unsigned long )&_binary_zh_t_wav_size;
unsigned  long * audio_buf_zh_th = ( unsigned  long *)&_binary_zh_th_wav_start;
unsigned long size_zh_th = ( unsigned long )&_binary_zh_th_wav_size;
unsigned  long * audio_buf_zh_uh = ( unsigned  long *)&_binary_zh_uh_wav_start;
unsigned long size_zh_uh = ( unsigned long )&_binary_zh_uh_wav_size;
unsigned  long * audio_buf_zh_uw = ( unsigned  long *)&_binary_zh_uw_wav_start;
unsigned long size_zh_uw = ( unsigned long )&_binary_zh_uw_wav_size;
unsigned  long * audio_buf_zh_v = ( unsigned  long *)&_binary_zh_v_wav_start;
unsigned long size_zh_v = ( unsigned long )&_binary_zh_v_wav_size;
unsigned  long * audio_buf_zh_w = ( unsigned  long *)&_binary_zh_w_wav_start;
unsigned long size_zh_w = ( unsigned long )&_binary_zh_w_wav_size;
unsigned  long * audio_buf_zh_y = ( unsigned  long *)&_binary_zh_y_wav_start;
unsigned long size_zh_y = ( unsigned long )&_binary_zh_y_wav_size;
unsigned  long * audio_buf_zh_z = ( unsigned  long *)&_binary_zh_z_wav_start;
unsigned long size_zh_z = ( unsigned long )&_binary_zh_z_wav_size;
unsigned  long * audio_buf_zh_zh = ( unsigned  long *)&_binary_zh_zh_wav_start;
unsigned long size_zh_zh = ( unsigned long )&_binary_zh_zh_wav_size;
//zh diphones
file_write("/tmp/zh-aa.wav",audio_buf_zh_aa,size_zh_aa);
file_write("/tmp/zh-ae.wav",audio_buf_zh_ae,size_zh_ae);
file_write("/tmp/zh-ah.wav",audio_buf_zh_ah,size_zh_ah);
file_write("/tmp/zh-ao.wav",audio_buf_zh_ao,size_zh_ao);
file_write("/tmp/zh-aw.wav",audio_buf_zh_aw,size_zh_aw);
file_write("/tmp/zh-ax.wav",audio_buf_zh_ax,size_zh_ax);
file_write("/tmp/zh-ay.wav",audio_buf_zh_ay,size_zh_ay);
file_write("/tmp/zh-b.wav",audio_buf_zh_b,size_zh_b);
file_write("/tmp/zh-ch.wav",audio_buf_zh_ch,size_zh_ch);
file_write("/tmp/zh-d.wav",audio_buf_zh_d,size_zh_d);
file_write("/tmp/zh-dh.wav",audio_buf_zh_dh,size_zh_dh);
file_write("/tmp/zh-eh.wav",audio_buf_zh_eh,size_zh_eh);
file_write("/tmp/zh-er.wav",audio_buf_zh_er,size_zh_er);
file_write("/tmp/zh-ey.wav",audio_buf_zh_ey,size_zh_ey);
file_write("/tmp/zh-f.wav",audio_buf_zh_f,size_zh_f);
file_write("/tmp/zh-g.wav",audio_buf_zh_g,size_zh_g);
file_write("/tmp/zh-hh.wav",audio_buf_zh_hh,size_zh_hh);
file_write("/tmp/zh-ih.wav",audio_buf_zh_ih,size_zh_ih);
file_write("/tmp/zh-iy.wav",audio_buf_zh_iy,size_zh_iy);
file_write("/tmp/zh-jh.wav",audio_buf_zh_jh,size_zh_jh);
file_write("/tmp/zh-k.wav",audio_buf_zh_k,size_zh_k);
file_write("/tmp/zh-l.wav",audio_buf_zh_l,size_zh_l);
file_write("/tmp/zh-m.wav",audio_buf_zh_m,size_zh_m);
file_write("/tmp/zh-n.wav",audio_buf_zh_n,size_zh_n);
file_write("/tmp/zh-ow.wav",audio_buf_zh_ow,size_zh_ow);
file_write("/tmp/zh-oy.wav",audio_buf_zh_oy,size_zh_oy);
file_write("/tmp/zh-p.wav",audio_buf_zh_p,size_zh_p);
file_write("/tmp/zh-pau.wav",audio_buf_zh_pau,size_zh_pau);
file_write("/tmp/zh-r.wav",audio_buf_zh_r,size_zh_r);
file_write("/tmp/zh-s.wav",audio_buf_zh_s,size_zh_s);
file_write("/tmp/zh-sh.wav",audio_buf_zh_sh,size_zh_sh);
file_write("/tmp/zh-t.wav",audio_buf_zh_t,size_zh_t);
file_write("/tmp/zh-th.wav",audio_buf_zh_th,size_zh_th);
file_write("/tmp/zh-uh.wav",audio_buf_zh_uh,size_zh_uh);
file_write("/tmp/zh-uw.wav",audio_buf_zh_uw,size_zh_uw);
file_write("/tmp/zh-v.wav",audio_buf_zh_v,size_zh_v);
file_write("/tmp/zh-w.wav",audio_buf_zh_w,size_zh_w);
file_write("/tmp/zh-y.wav",audio_buf_zh_y,size_zh_y);
file_write("/tmp/zh-z.wav",audio_buf_zh_z,size_zh_z);
file_write("/tmp/zh-zh.wav",audio_buf_zh_zh,size_zh_zh);
	
}

























//---------------------------------------------------------------------
// get diphone wav path
//---------------------------------------------------------------------
char* get_diphone_wav_path(char* dp_str) {

	char* diphone_str = g_ascii_strdown(dp_str, -1); //convert to lower case	
	
	char* result="";
	
	//aa diphones	
	if (g_strcmp0(diphone_str,"aa-aa")==0) {
	result ="/tmp/aa_aa.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ae")==0) {
	result ="/tmp/aa_ae.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ah")==0) {
	result ="/tmp/aa-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ao")==0) {
	result ="/tmp/aa-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-aw")==0) {
	result ="/tmp/aa-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ax")==0) {
	result ="/tmp/aa-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ay")==0) {
	result ="/tmp/aa-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-b")==0) {
	result ="/tmp/aa-b.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ch")==0) {
	result ="/tmp/aa-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-d")==0) {
	result ="/tmp/aa-d.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-dh")==0) {
	result ="/tmp/aa-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-eh")==0) {
	result ="/tmp/aa-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-er")==0) {
	result ="/tmp/aa-er.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ey")==0) {
	result ="/tmp/aa-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-f")==0) {
	result ="/tmp/aa-f.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-g")==0) {
	result ="/tmp/aa-g.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-hh")==0) {
	result ="/tmp/aa-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ih")==0) {
	result ="/tmp/aa-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-iy")==0) {
	result ="/tmp/aa-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-jh")==0) {
	result ="/tmp/aa-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-k")==0) {
	result ="/tmp/aa-k.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-l")==0) {
	result ="/tmp/aa-l.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-m")==0) {
	result ="/tmp/aa-m.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-n")==0) {
	result ="/tmp/aa-n.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ng")==0) {
	result ="/tmp/aa-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-ow")==0) {
	result ="/tmp/aa-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-oy")==0) {
	result ="/tmp/aa-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-p")==0) {
	result ="/tmp/aa-p.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-pau")==0) {
	result ="/tmp/aa-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-r")==0) {
	result ="/tmp/aa-r.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-s")==0) {
	result ="/tmp/aa-s.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-sh")==0) {
	result ="/tmp/aa-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-t")==0) {
	result ="/tmp/aa-t.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-th")==0) {
	result ="/tmp/aa-th.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-uh")==0) {
	result ="/tmp/aa-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-uw")==0) {
	result ="/tmp/aa-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-v")==0) {
	result ="/tmp/aa-v.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-w")==0) {
	result ="/tmp/aa-w.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-y")==0) {
	result ="/tmp/aa-y.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-z")==0) {
	result ="/tmp/aa-z.wav";	
	}
	if (g_strcmp0(diphone_str,"aa-zh")==0) {
	result ="/tmp/aa-zh.wav";	
	}
	
	//ae diphones
	if (g_strcmp0(diphone_str,"ae-aa")==0) {
	result ="/tmp/ae-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ae")==0) {
	result ="/tmp/ae-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ah")==0) {
	result ="/tmp/ae-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ao")==0) {
	result ="/tmp/ae-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-aw")==0) {
	result ="/tmp/ae-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ax")==0) {
	result ="/tmp/ae-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ay")==0) {
	result ="/tmp/ae-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-b")==0) {
	result ="/tmp/ae-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ch")==0) {
	result ="/tmp/ae-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-d")==0) {
	result ="/tmp/ae-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-dh")==0) {
	result ="/tmp/ae-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-eh")==0) {
	result ="/tmp/ae-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-er")==0) {
	result ="/tmp/ae-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ey")==0) {
	result ="/tmp/ae-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-f")==0) {
	result ="/tmp/ae-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-g")==0) {
	result ="/tmp/ae-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-hh")==0) {
	result ="/tmp/ae-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ih")==0) {
	result ="/tmp/ae-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-iy")==0) {
	result ="/tmp/ae-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-jh")==0) {
	result ="/tmp/ae-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-k")==0) {
	result ="/tmp/ae-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-l")==0) {
	result ="/tmp/ae-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-m")==0) {
	result ="/tmp/ae-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-n")==0) {
	result ="/tmp/ae-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ng")==0) {
	result ="/tmp/ae-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-ow")==0) {
	result ="/tmp/ae-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-oy")==0) {
	result ="/tmp/ae-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-p")==0) {
	result ="/tmp/ae-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-pau")==0) {
	result ="/tmp/ae-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-r")==0) {
	result ="/tmp/ae-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-s")==0) {
	result ="/tmp/ae-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-sh")==0) {
	result ="/tmp/ae-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-t")==0) {
	result ="/tmp/ae-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-th")==0) {
	result ="/tmp/ae-th.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-uh")==0) {
	result ="/tmp/ae-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-uw")==0) {
	result ="/tmp/ae-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-v")==0) {
	result ="/tmp/ae-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-e")==0) {
	result ="/tmp/ae-e.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-y")==0) {
	result ="/tmp/ae-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-z")==0) {
	result ="/tmp/ae-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ae-zh")==0) {
	result ="/tmp/ae-zh.wav";	
	}
	
	
	//ah diphones
	if (g_strcmp0(diphone_str,"ah-aa")==0) {
	result ="/tmp/ah-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ae")==0) {
	result ="/tmp/ah-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ah")==0) {
	result ="/tmp/ah-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ao")==0) {
	result ="/tmp/ah-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-aw")==0) {
	result ="/tmp/ah-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ax")==0) {
	result ="/tmp/ah-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ay")==0) {
	result ="/tmp/ah-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-b")==0) {
	result ="/tmp/ah-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ch")==0) {
	result ="/tmp/ah-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-d")==0) {
	result ="/tmp/ah-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-dh")==0) {
	result ="/tmp/ah-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-eh")==0) {
	result ="/tmp/ah-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-er")==0) {
	result ="/tmp/ah-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ey")==0) {
	result ="/tmp/ah-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-f")==0) {
	result ="/tmp/ah-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-g")==0) {
	result ="/tmp/ah-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-hh")==0) {
	result ="/tmp/ah-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ih")==0) {
	result ="/tmp/ah-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-iy")==0) {
	result ="/tmp/ah-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-jh")==0) {
	result ="/tmp/ah-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-k")==0) {
	result ="/tmp/ah-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-l")==0) {
	result ="/tmp/ah-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-m")==0) {
	result ="/tmp/ah-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-n")==0) {
	result ="/tmp/ah-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ng")==0) {
	result ="/tmp/ah-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-ow")==0) {
	result ="/tmp/ah-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-oy")==0) {
	result ="/tmp/ah-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-p")==0) {
	result ="/tmp/ah-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-pau")==0) {
	result ="/tmp/ah-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-r")==0) {
	result ="/tmp/ah-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-s")==0) {
	result ="/tmp/ah-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-sh")==0) {
	result ="/tmp/ah-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-t")==0) {
	result ="/tmp/ah-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-th")==0) {
	result ="/tmp/ah-th.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-uh")==0) {
	result ="/tmp/ah-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-uw")==0) {
	result ="/tmp/ah-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-v")==0) {
	result ="/tmp/ah-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-w")==0) {
	result ="/tmp/ah-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-y")==0) {
	result ="/tmp/ah-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-z")==0) {
	result ="/tmp/ah-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ah-zh")==0) {
	result ="/tmp/ah-zh.wav";	
	}
	
	//ao diphones	
	if (g_strcmp0(diphone_str,"ao-aa")==0) {
	result ="/tmp/ao-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ae")==0) {
	result ="/tmp/ao-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ah")==0) {
	result ="/tmp/ao-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ao")==0) {
	result ="/tmp/ao-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-aw")==0) {
	result ="/tmp/ao-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ax")==0) {
	result ="/tmp/ao-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ay")==0) {
	result ="/tmp/ao-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-b")==0) {
	result ="/tmp/ao-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ch")==0) {
	result ="/tmp/ao-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-d")==0) {
	result ="/tmp/ao-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-dh")==0) {
	result ="/tmp/ao-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-eh")==0) {
	result ="/tmp/ao-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-er")==0) {
	result ="/tmp/ao-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ey")==0) {
	result ="/tmp/ao-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-f")==0) {
	result ="/tmp/ao-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-g")==0) {
	result ="/tmp/ao-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-hh")==0) {
	result ="/tmp/ao-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ih")==0) {
	result ="/tmp/ao-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-iy")==0) {
	result ="/tmp/ao-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-jh")==0) {
	result ="/tmp/ao-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-k")==0) {
	result ="/tmp/ao-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-l")==0) {
	result ="/tmp/ao-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-m")==0) {
	result ="/tmp/ao-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-n")==0) {
	result ="/tmp/ao-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ng")==0) {
	result ="/tmp/ao-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-ow")==0) {
	result ="/tmp/ao-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-oy")==0) {
	result ="/tmp/ao-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-p")==0) {
	result ="/tmp/ao-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-pau")==0) {
	result ="/tmp/ao-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-r")==0) {
	result ="/tmp/ao-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-s")==0) {
	result ="/tmp/ao-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-sh")==0) {
	result ="/tmp/ao-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-t")==0) {
	result ="/tmp/ao-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-th")==0) {
	result ="/tmp/ao-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ao-uh")==0) {
	result ="/tmp/ao-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-uw")==0) {
	result ="/tmp/ao-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-v")==0) {
	result ="/tmp/ao-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-w")==0) {
	result ="/tmp/ao-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-y")==0) {
	result ="/tmp/ao-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-z")==0) {
	result ="/tmp/ao-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ao-zh")==0) {
	result ="/tmp/ao-zh.wav";	
	}
	
	//aw diphones
	if (g_strcmp0(diphone_str,"aw-aa")==0) {
	result ="/tmp/aw-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ae")==0) {
	result ="/tmp/aw-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ah")==0) {
	result ="/tmp/aw-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ao")==0) {
	result ="/tmp/aw-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-aw")==0) {
	result ="/tmp/aw-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ax")==0) {
	result ="/tmp/aw-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ay")==0) {
	result ="/tmp/aw-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-b")==0) {
	result ="/tmp/aw-b.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ch")==0) {
	result ="/tmp/aw-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-d")==0) {
	result ="/tmp/aw-d.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-dh")==0) {
	result ="/tmp/aw-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-eh")==0) {
	result ="/tmp/aw-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-er")==0) {
	result ="/tmp/aw-er.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ey")==0) {
	result ="/tmp/aw-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-f")==0) {
	result ="/tmp/aw-f.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-g")==0) {
	result ="/tmp/aw-g.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-hh")==0) {
	result ="/tmp/aw-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ih")==0) {
	result ="/tmp/aw-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-iy")==0) {
	result ="/tmp/aw-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-jh")==0) {
	result ="/tmp/aw-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-k")==0) {
	result ="/tmp/aw-k.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-l")==0) {
	result ="/tmp/aw-l.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-m")==0) {
	result ="/tmp/aw-m.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-n")==0) {
	result ="/tmp/aw-n.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ng")==0) {
	result ="/tmp/aw-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-ow")==0) {
	result ="/tmp/aw-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-oy")==0) {
	result ="/tmp/aw-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-p")==0) {
	result ="/tmp/aw-p.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-pau")==0) {
	result ="/tmp/aw-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-r")==0) {
	result ="/tmp/aw-r.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-s")==0) {
	result ="/tmp/aw-s.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-sh")==0) {
	result ="/tmp/aw-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-t")==0) {
	result ="/tmp/aw-t.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-th")==0) {
	result ="/tmp/aw-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"aw-uh")==0) {
	result ="/tmp/aw-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-uw")==0) {
	result ="/tmp/aw-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-v")==0) {
	result ="/tmp/aw-v.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-w")==0) {
	result ="/tmp/aw-w.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-y")==0) {
	result ="/tmp/aw-y.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-z")==0) {
	result ="/tmp/aw-z.wav";	
	}
	if (g_strcmp0(diphone_str,"aw-zh")==0) {
	result ="/tmp/aw-zh.wav";	
	}
	
	//ax diphones
	if (g_strcmp0(diphone_str,"ax-aa")==0) {
	result ="/tmp/ax-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ae")==0) {
	result ="/tmp/ax-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ah")==0) {
	result ="/tmp/ax-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ao")==0) {
	result ="/tmp/ax-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-aw")==0) {
	result ="/tmp/ax-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ax")==0) {
	result ="/tmp/ax-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ay")==0) {
	result ="/tmp/ax-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-b")==0) {
	result ="/tmp/ax-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ch")==0) {
	result ="/tmp/ax-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-d")==0) {
	result ="/tmp/ax-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-dh")==0) {
	result ="/tmp/ax-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-eh")==0) {
	result ="/tmp/ax-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-er")==0) {
	result ="/tmp/ax-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ey")==0) {
	result ="/tmp/ax-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-f")==0) {
	result ="/tmp/ax-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-g")==0) {
	result ="/tmp/ax-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-hh")==0) {
	result ="/tmp/ax-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ih")==0) {
	result ="/tmp/ax-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-iy")==0) {
	result ="/tmp/ax-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-jh")==0) {
	result ="/tmp/ax-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-k")==0) {
	result ="/tmp/ax-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-l")==0) {
	result ="/tmp/ax-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-m")==0) {
	result ="/tmp/ax-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-n")==0) {
	result ="/tmp/ax-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ng")==0) {
	result ="/tmp/ax-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-ow")==0) {
	result ="/tmp/ax-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-oy")==0) {
	result ="/tmp/ax-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-p")==0) {
	result ="/tmp/ax-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-pau")==0) {
	result ="/tmp/ax-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-r")==0) {
	result ="/tmp/ax-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-s")==0) {
	result ="/tmp/ax-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-sh")==0) {
	result ="/tmp/ax-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-t")==0) {
	result ="/tmp/ax-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-th")==0) {
	result ="/tmp/ax-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ax-uh")==0) {
	result ="/tmp/ax-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-uw")==0) {
	result ="/tmp/ax-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-v")==0) {
	result ="/tmp/ax-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-w")==0) {
	result ="/tmp/ax-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-y")==0) {
	result ="/tmp/ax-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-z")==0) {
	result ="/tmp/ax-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ax-zh")==0) {
	result ="/tmp/ax-zh.wav";	
	}
	
	//ay diphones
	if (g_strcmp0(diphone_str,"ay-aa")==0) {
	result ="/tmp/ay-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ae")==0) {
	result ="/tmp/ay-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ah")==0) {
	result ="/tmp/ay-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ao")==0) {
	result ="/tmp/ay-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-aw")==0) {
	result ="/tmp/ay-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ax")==0) {
	result ="/tmp/ay-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ay")==0) {
	result ="/tmp/ay-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-b")==0) {
	result ="/tmp/ay-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ch")==0) {
	result ="/tmp/ay-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-d")==0) {
	result ="/tmp/ay-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-dh")==0) {
	result ="/tmp/ay-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-eh")==0) {
	result ="/tmp/ay-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-er")==0) {
	result ="/tmp/ay-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ey")==0) {
	result ="/tmp/ay-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-f")==0) {
	result ="/tmp/ay-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-g")==0) {
	result ="/tmp/ay-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-hh")==0) {
	result ="/tmp/ay-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ih")==0) {
	result ="/tmp/ay-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-iy")==0) {
	result ="/tmp/ay-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-jh")==0) {
	result ="/tmp/ay-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-k")==0) {
	result ="/tmp/ay-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-l")==0) {
	result ="/tmp/ay-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-m")==0) {
	result ="/tmp/ay-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-n")==0) {
	result ="/tmp/ay-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ng")==0) {
	result ="/tmp/ay-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-ow")==0) {
	result ="/tmp/ay-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-oy")==0) {
	result ="/tmp/ay-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-p")==0) {
	result ="/tmp/ay-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-pau")==0) {
	result ="/tmp/ay-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-r")==0) {
	result ="/tmp/ay-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-s")==0) {
	result ="/tmp/ay-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-sh")==0) {
	result ="/tmp/ay-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-t")==0) {
	result ="/tmp/ay-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-th")==0) {
	result ="/tmp/ay-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ay-uh")==0) {
	result ="/tmp/ay-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-uw")==0) {
	result ="/tmp/ay-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-v")==0) {
	result ="/tmp/ay-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-w")==0) {
	result ="/tmp/ay-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-y")==0) {
	result ="/tmp/ay-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-z")==0) {
	result ="/tmp/ay-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ay-zh")==0) {
	result ="/tmp/ay-zh.wav";	
	}
	
	//b diphones
	if (g_strcmp0(diphone_str,"b-aa")==0) {
	result ="/tmp/b-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ae")==0) {
	result ="/tmp/b-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ah")==0) {
	result ="/tmp/b-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ao")==0) {
	result ="/tmp/b-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"b-aw")==0) {
	result ="/tmp/b-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ax")==0) {
	result ="/tmp/b-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ay")==0) {
	result ="/tmp/b-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"b-b")==0) {
	result ="/tmp/b-b.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ch")==0) {
	result ="/tmp/b-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"b-d")==0) {
	result ="/tmp/b-d.wav";	
	}
	if (g_strcmp0(diphone_str,"b-dh")==0) {
	result ="/tmp/b-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-eh")==0) {
	result ="/tmp/b-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-er")==0) {
	result ="/tmp/b-er.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ey")==0) {
	result ="/tmp/b-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"b-f")==0) {
	result ="/tmp/b-f.wav";	
	}
	if (g_strcmp0(diphone_str,"b-g")==0) {
	result ="/tmp/b-g.wav";	
	}
	if (g_strcmp0(diphone_str,"b-hh")==0) {
	result ="/tmp/b-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-ih")==0) {
	result ="/tmp/b-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"b-iy")==0) {
	result ="/tmp/b-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"b-jh")==0) {
	result ="/tmp/b-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-k")==0) {
	result ="/tmp/b-k.wav";	
	}
	if (g_strcmp0(diphone_str,"b-l")==0) {
	result ="/tmp/b-l.wav";	
	}
	if (g_strcmp0(diphone_str,"b-m")==0) {
	result ="/tmp/b-m.wav";	
	}
	if (g_strcmp0(diphone_str,"b-n")==0) {
	result ="/tmp/b-n.wav";	
	}
	
	if (g_strcmp0(diphone_str,"b-ow")==0) {
	result ="/tmp/b-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"b-oy")==0) {
	result ="/tmp/b-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"b-p")==0) {
	result ="/tmp/b-p.wav";	
	}
	if (g_strcmp0(diphone_str,"b-pau")==0) {
	result ="/tmp/b-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"b-r")==0) {
	result ="/tmp/b-r.wav";	
	}
	if (g_strcmp0(diphone_str,"b-s")==0) {
	result ="/tmp/b-s.wav";	
	}
	if (g_strcmp0(diphone_str,"b-sh")==0) {
	result ="/tmp/b-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-t")==0) {
	result ="/tmp/b-t.wav";	
	}
	if (g_strcmp0(diphone_str,"b-th")==0) {
	result ="/tmp/b-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"b-uh")==0) {
	result ="/tmp/b-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"b-uw")==0) {
	result ="/tmp/b-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"b-v")==0) {
	result ="/tmp/b-v.wav";	
	}
	if (g_strcmp0(diphone_str,"b-w")==0) {
	result ="/tmp/b-w.wav";	
	}
	if (g_strcmp0(diphone_str,"b-y")==0) {
	result ="/tmp/b-y.wav";	
	}	
	if (g_strcmp0(diphone_str,"b-z")==0) {
	result ="/tmp/b-z.wav";	
	}
	if (g_strcmp0(diphone_str,"b-zh")==0) {
	result ="/tmp/b-zh.wav";	
	}
	
	
	
	//ch diphones
	if (g_strcmp0(diphone_str,"ch-aa")==0) {
	result ="/tmp/ch-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ae")==0) {
	result ="/tmp/ch-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ah")==0) {
	result ="/tmp/ch-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ao")==0) {
	result ="/tmp/ch-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-aw")==0) {
	result ="/tmp/ch-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ax")==0) {
	result ="/tmp/ch-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ay")==0) {
	result ="/tmp/ch-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-b")==0) {
	result ="/tmp/ch-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ch")==0) {
	result ="/tmp/ch-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-d")==0) {
	result ="/tmp/ch-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-dh")==0) {
	result ="/tmp/ch-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-eh")==0) {
	result ="/tmp/ch-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-er")==0) {
	result ="/tmp/ch-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ey")==0) {
	result ="/tmp/ch-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-f")==0) {
	result ="/tmp/ch-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-g")==0) {
	result ="/tmp/ch-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-hh")==0) {
	result ="/tmp/ch-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ih")==0) {
	result ="/tmp/ch-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-iy")==0) {
	result ="/tmp/ch-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-jh")==0) {
	result ="/tmp/ch-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-k")==0) {
	result ="/tmp/ch-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-l")==0) {
	result ="/tmp/ch-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-m")==0) {
	result ="/tmp/ch-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-n")==0) {
	result ="/tmp/ch-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-ow")==0) {
	result ="/tmp/ch-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-oy")==0) {
	result ="/tmp/ch-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-p")==0) {
	result ="/tmp/ch-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-pau")==0) {
	result ="/tmp/ch-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-r")==0) {
	result ="/tmp/ch-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-s")==0) {
	result ="/tmp/ch-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-sh")==0) {
	result ="/tmp/ch-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-t")==0) {
	result ="/tmp/ch-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-th")==0) {
	result ="/tmp/ch-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ch-uh")==0) {
	result ="/tmp/ch-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-uw")==0) {
	result ="/tmp/ch-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-v")==0) {
	result ="/tmp/ch-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-w")==0) {
	result ="/tmp/ch-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-y")==0) {
	result ="/tmp/ch-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-z")==0) {
	result ="/tmp/ch-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ch-zh")==0) {
	result ="/tmp/ch-zh.wav";	
	}
	
	//d diphones
	if (g_strcmp0(diphone_str,"d-aa")==0) {
	result ="/tmp/d-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ae")==0) {
	result ="/tmp/d-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ah")==0) {
	result ="/tmp/d-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ao")==0) {
	result ="/tmp/d-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"d-aw")==0) {
	result ="/tmp/d-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ax")==0) {
	result ="/tmp/d-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ay")==0) {
	result ="/tmp/d-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"d-b")==0) {
	result ="/tmp/d-b.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ch")==0) {
	result ="/tmp/d-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"d-d")==0) {
	result ="/tmp/d-d.wav";	
	}
	if (g_strcmp0(diphone_str,"d-dh")==0) {
	result ="/tmp/d-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-eh")==0) {
	result ="/tmp/d-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-er")==0) {
	result ="/tmp/d-er.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ey")==0) {
	result ="/tmp/d-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"d-f")==0) {
	result ="/tmp/d-f.wav";	
	}
	if (g_strcmp0(diphone_str,"d-g")==0) {
	result ="/tmp/d-g.wav";	
	}
	if (g_strcmp0(diphone_str,"d-hh")==0) {
	result ="/tmp/d-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-ih")==0) {
	result ="/tmp/d-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"d-iy")==0) {
	result ="/tmp/d-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"d-jh")==0) {
	result ="/tmp/d-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-k")==0) {
	result ="/tmp/d-k.wav";	
	}
	if (g_strcmp0(diphone_str,"d-l")==0) {
	result ="/tmp/d-l.wav";	
	}
	if (g_strcmp0(diphone_str,"d-m")==0) {
	result ="/tmp/d-m.wav";	
	}
	if (g_strcmp0(diphone_str,"d-n")==0) {
	result ="/tmp/d-n.wav";	
	}
	//if (g_strcmp0(diphone_str,"d-ng")==0) {
	//result ="/tmp/d-ng.wav";	
	//}
	if (g_strcmp0(diphone_str,"d-ow")==0) {
	result ="/tmp/d-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"d-oy")==0) {
	result ="/tmp/d-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"d-p")==0) {
	result ="/tmp/d-p.wav";	
	}
	if (g_strcmp0(diphone_str,"d-pau")==0) {
	result ="/tmp/d-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"d-r")==0) {
	result ="/tmp/d-r.wav";	
	}
	if (g_strcmp0(diphone_str,"d-s")==0) {
	result ="/tmp/d-s.wav";	
	}
	if (g_strcmp0(diphone_str,"d-sh")==0) {
	result ="/tmp/d-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-t")==0) {
	result ="/tmp/d-t.wav";	
	}
	if (g_strcmp0(diphone_str,"d-th")==0) {
	result ="/tmp/d-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"d-uh")==0) {
	result ="/tmp/d-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"d-uw")==0) {
	result ="/tmp/d-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"d-v")==0) {
	result ="/tmp/d-v.wav";	
	}
	if (g_strcmp0(diphone_str,"d-w")==0) {
	result ="/tmp/d-w.wav";	
	}
	if (g_strcmp0(diphone_str,"d-y")==0) {
	result ="/tmp/d-y.wav";	
	}
	if (g_strcmp0(diphone_str,"d-z")==0) {
	result ="/tmp/d-z.wav";	
	}
	if (g_strcmp0(diphone_str,"d-zh")==0) {
	result ="/tmp/d-zh.wav";	
	}
	
	//dh diphones
	if (g_strcmp0(diphone_str,"dh-aa")==0) {
	result ="/tmp/dh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ae")==0) {
	result ="/tmp/dh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ah")==0) {
	result ="/tmp/dh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ao")==0) {
	result ="/tmp/dh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-aw")==0) {
	result ="/tmp/dh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ax")==0) {
	result ="/tmp/dh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ay")==0) {
	result ="/tmp/dh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-b")==0) {
	result ="/tmp/dh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ch")==0) {
	result ="/tmp/dh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-d")==0) {
	result ="/tmp/dh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-dh")==0) {
	result ="/tmp/dh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-eh")==0) {
	result ="/tmp/dh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-er")==0) {
	result ="/tmp/dh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ey")==0) {
	result ="/tmp/dh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-f")==0) {
	result ="/tmp/dh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-g")==0) {
	result ="/tmp/dh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-hh")==0) {
	result ="/tmp/dh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ih")==0) {
	result ="/tmp/dh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-iy")==0) {
	result ="/tmp/dh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-jh")==0) {
	result ="/tmp/dh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-k")==0) {
	result ="/tmp/dh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-l")==0) {
	result ="/tmp/dh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-m")==0) {
	result ="/tmp/dh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-n")==0) {
	result ="/tmp/dh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-ow")==0) {
	result ="/tmp/dh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-oy")==0) {
	result ="/tmp/dh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-p")==0) {
	result ="/tmp/dh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-pau")==0) {
	result ="/tmp/dh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-r")==0) {
	result ="/tmp/dh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-s")==0) {
	result ="/tmp/dh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-sh")==0) {
	result ="/tmp/dh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-t")==0) {
	result ="/tmp/dh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-th")==0) {
	result ="/tmp/dh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"dh-uh")==0) {
	result ="/tmp/dh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-uw")==0) {
	result ="/tmp/dh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-v")==0) {
	result ="/tmp/dh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-w")==0) {
	result ="/tmp/dh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-y")==0) {
	result ="/tmp/dh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-z")==0) {
	result ="/tmp/dh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"dh-zh")==0) {
	result ="/tmp/dh-zh.wav";	
	}
	
	//eh diphones
	if (g_strcmp0(diphone_str,"eh-aa")==0) {
	result ="/tmp/eh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ae")==0) {
	result ="/tmp/eh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ah")==0) {
	result ="/tmp/eh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ao")==0) {
	result ="/tmp/eh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-aw")==0) {
	result ="/tmp/eh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ax")==0) {
	result ="/tmp/eh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ay")==0) {
	result ="/tmp/eh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-b")==0) {
	result ="/tmp/eh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ch")==0) {
	result ="/tmp/eh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-d")==0) {
	result ="/tmp/eh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-dh")==0) {
	result ="/tmp/eh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-eh")==0) {
	result ="/tmp/eh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-er")==0) {
	result ="/tmp/eh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ey")==0) {
	result ="/tmp/eh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-f")==0) {
	result ="/tmp/eh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-g")==0) {
	result ="/tmp/eh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-hh")==0) {
	result ="/tmp/eh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ih")==0) {
	result ="/tmp/eh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-iy")==0) {
	result ="/tmp/eh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-jh")==0) {
	result ="/tmp/eh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-k")==0) {
	result ="/tmp/eh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-l")==0) {
	result ="/tmp/eh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-m")==0) {
	result ="/tmp/eh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-n")==0) {
	result ="/tmp/eh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ng")==0) {
	result ="/tmp/eh-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-ow")==0) {
	result ="/tmp/eh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-oy")==0) {
	result ="/tmp/eh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-p")==0) {
	result ="/tmp/eh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-pau")==0) {
	result ="/tmp/eh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-r")==0) {
	result ="/tmp/eh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-s")==0) {
	result ="/tmp/eh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-sh")==0) {
	result ="/tmp/eh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-t")==0) {
	result ="/tmp/eh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-th")==0) {
	result ="/tmp/eh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"eh-uh")==0) {
	result ="/tmp/eh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-uw")==0) {
	result ="/tmp/eh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-v")==0) {
	result ="/tmp/eh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-w")==0) {
	result ="/tmp/eh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-y")==0) {
	result ="/tmp/eh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-z")==0) {
	result ="/tmp/eh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"eh-zh")==0) {
	result ="/tmp/eh-zh.wav";	
	}
	
	// er diphones
	
	if (g_strcmp0(diphone_str,"er-aa")==0) {
	result ="/tmp/er-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ae")==0) {
	result ="/tmp/er-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ah")==0) {
	result ="/tmp/er-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ao")==0) {
	result ="/tmp/er-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"er-aw")==0) {
	result ="/tmp/er-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ax")==0) {
	result ="/tmp/er-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ay")==0) {
	result ="/tmp/er-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"er-b")==0) {
	result ="/tmp/er-b.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ch")==0) {
	result ="/tmp/er-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"er-d")==0) {
	result ="/tmp/er-d.wav";	
	}
	if (g_strcmp0(diphone_str,"er-dh")==0) {
	result ="/tmp/er-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-eh")==0) {
	result ="/tmp/er-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-er")==0) {
	result ="/tmp/er-er.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ey")==0) {
	result ="/tmp/er-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"er-f")==0) {
	result ="/tmp/er-f.wav";	
	}
	if (g_strcmp0(diphone_str,"er-g")==0) {
	result ="/tmp/er-g.wav";	
	}
	if (g_strcmp0(diphone_str,"er-hh")==0) {
	result ="/tmp/er-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ih")==0) {
	result ="/tmp/er-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"er-iy")==0) {
	result ="/tmp/er-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"er-jh")==0) {
	result ="/tmp/er-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-k")==0) {
	result ="/tmp/er-k.wav";	
	}
	if (g_strcmp0(diphone_str,"er-l")==0) {
	result ="/tmp/er-l.wav";	
	}
	if (g_strcmp0(diphone_str,"er-m")==0) {
	result ="/tmp/er-m.wav";	
	}
	if (g_strcmp0(diphone_str,"er-n")==0) {
	result ="/tmp/er-n.wav";	
	}
	if (g_strcmp0(diphone_str,"er-ow")==0) {
	result ="/tmp/er-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"er-oy")==0) {
	result ="/tmp/er-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"er-p")==0) {
	result ="/tmp/er-p.wav";	
	}
	if (g_strcmp0(diphone_str,"er-pau")==0) {
	result ="/tmp/er-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"er-r")==0) {
	result ="/tmp/er-r.wav";	
	}
	if (g_strcmp0(diphone_str,"er-s")==0) {
	result ="/tmp/er-s.wav";	
	}
	if (g_strcmp0(diphone_str,"er-sh")==0) {
	result ="/tmp/er-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-t")==0) {
	result ="/tmp/er-t.wav";	
	}
	if (g_strcmp0(diphone_str,"er-th")==0) {
	result ="/tmp/er-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"er-uh")==0) {
	result ="/tmp/er-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"er-uw")==0) {
	result ="/tmp/er-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"er-v")==0) {
	result ="/tmp/er-v.wav";	
	}
	if (g_strcmp0(diphone_str,"er-w")==0) {
	result ="/tmp/er-w.wav";	
	}
	if (g_strcmp0(diphone_str,"er-y")==0) {
	result ="/tmp/er-y.wav";	
	}
	if (g_strcmp0(diphone_str,"er-z")==0) {
	result ="/tmp/er-z.wav";	
	}
	if (g_strcmp0(diphone_str,"er-zh")==0) {
	result ="/tmp/er-zh.wav";	
	}
	
	//ey diphones
	if (g_strcmp0(diphone_str,"ey-aa")==0) {
	result ="/tmp/ey-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ae")==0) {
	result ="/tmp/ey-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ah")==0) {
	result ="/tmp/ey-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ao")==0) {
	result ="/tmp/ey-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-aw")==0) {
	result ="/tmp/ey-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ax")==0) {
	result ="/tmp/ey-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ay")==0) {
	result ="/tmp/ey-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-b")==0) {
	result ="/tmp/ey-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ch")==0) {
	result ="/tmp/ey-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-d")==0) {
	result ="/tmp/ey-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-dh")==0) {
	result ="/tmp/ey-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-eh")==0) {
	result ="/tmp/ey-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-er")==0) {
	result ="/tmp/ey-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ey")==0) {
	result ="/tmp/ey-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-f")==0) {
	result ="/tmp/ey-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-g")==0) {
	result ="/tmp/ey-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-hh")==0) {
	result ="/tmp/ey-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ih")==0) {
	result ="/tmp/ey-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-iy")==0) {
	result ="/tmp/ey-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-jh")==0) {
	result ="/tmp/ey-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-k")==0) {
	result ="/tmp/ey-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-l")==0) {
	result ="/tmp/ey-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-m")==0) {
	result ="/tmp/ey-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-n")==0) {
	result ="/tmp/ey-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ng")==0) {
	result ="/tmp/ey-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-ow")==0) {
	result ="/tmp/ey-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-oy")==0) {
	result ="/tmp/ey-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-p")==0) {
	result ="/tmp/ey-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-pau")==0) {
	result ="/tmp/ey-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-r")==0) {
	result ="/tmp/ey-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-s")==0) {
	result ="/tmp/ey-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-sh")==0) {
	result ="/tmp/ey-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-t")==0) {
	result ="/tmp/ey-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-th")==0) {
	result ="/tmp/ey-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ey-uh")==0) {
	result ="/tmp/ey-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-uw")==0) {
	result ="/tmp/ey-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-v")==0) {
	result ="/tmp/ey-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-w")==0) {
	result ="/tmp/ey-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-y")==0) {
	result ="/tmp/ey-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-z")==0) {
	result ="/tmp/ey-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ey-zh")==0) {
	result ="/tmp/ey-zh.wav";	
	}
	
	//f diphones
	if (g_strcmp0(diphone_str,"f-aa")==0) {
	result ="/tmp/f-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ae")==0) {
	result ="/tmp/f-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ah")==0) {
	result ="/tmp/f-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ao")==0) {
	result ="/tmp/f-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"f-aw")==0) {
	result ="/tmp/f-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ax")==0) {
	result ="/tmp/f-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ay")==0) {
	result ="/tmp/f-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"f-b")==0) {
	result ="/tmp/f-b.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ch")==0) {
	result ="/tmp/f-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"f-d")==0) {
	result ="/tmp/f-d.wav";	
	}
	if (g_strcmp0(diphone_str,"f-dh")==0) {
	result ="/tmp/f-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-eh")==0) {
	result ="/tmp/f-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-er")==0) {
	result ="/tmp/f-er.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ey")==0) {
	result ="/tmp/f-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"f-f")==0) {
	result ="/tmp/f-f.wav";	
	}
	if (g_strcmp0(diphone_str,"f-g")==0) {
	result ="/tmp/f-g.wav";	
	}
	if (g_strcmp0(diphone_str,"f-hh")==0) {
	result ="/tmp/f-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ih")==0) {
	result ="/tmp/f-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"f-iy")==0) {
	result ="/tmp/f-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"f-jh")==0) {
	result ="/tmp/f-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-k")==0) {
	result ="/tmp/f-k.wav";	
	}
	if (g_strcmp0(diphone_str,"f-l")==0) {
	result ="/tmp/f-l.wav";	
	}
	if (g_strcmp0(diphone_str,"f-m")==0) {
	result ="/tmp/f-m.wav";	
	}
	if (g_strcmp0(diphone_str,"f-n")==0) {
	result ="/tmp/f-n.wav";	
	}
	if (g_strcmp0(diphone_str,"f-ng")==0) {
	result ="/tmp/f-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"f-oy")==0) {
	result ="/tmp/f-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"f-p")==0) {
	result ="/tmp/f-p.wav";	
	}
	if (g_strcmp0(diphone_str,"f-pau")==0) {
	result ="/tmp/f-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"f-r")==0) {
	result ="/tmp/f-r.wav";	
	}
	if (g_strcmp0(diphone_str,"f-s")==0) {
	result ="/tmp/f-s.wav";	
	}
	if (g_strcmp0(diphone_str,"f-sh")==0) {
	result ="/tmp/f-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-t")==0) {
	result ="/tmp/f-t.wav";	
	}
	if (g_strcmp0(diphone_str,"f-th")==0) {
	result ="/tmp/f-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"f-uh")==0) {
	result ="/tmp/f-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"f-uw")==0) {
	result ="/tmp/f-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"f-v")==0) {
	result ="/tmp/f-v.wav";	
	}
	if (g_strcmp0(diphone_str,"f-w")==0) {
	result ="/tmp/f-w.wav";	
	}
	if (g_strcmp0(diphone_str,"f-y")==0) {
	result ="/tmp/f-y.wav";	
	}
	if (g_strcmp0(diphone_str,"f-z")==0) {
	result ="/tmp/f-z.wav";	
	}
	if (g_strcmp0(diphone_str,"f-zh")==0) {
	result ="/tmp/f-zh.wav";	
	}
	
	//g diphones
	if (g_strcmp0(diphone_str,"g-aa")==0) {
	result ="/tmp/g-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ae")==0) {
	result ="/tmp/g-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ah")==0) {
	result ="/tmp/g-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ao")==0) {
	result ="/tmp/g-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"g-aw")==0) {
	result ="/tmp/g-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ax")==0) {
	result ="/tmp/g-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ay")==0) {
	result ="/tmp/g-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"g-b")==0) {
	result ="/tmp/g-b.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ch")==0) {
	result ="/tmp/g-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"g-d")==0) {
	result ="/tmp/g-d.wav";	
	}
	if (g_strcmp0(diphone_str,"g-dh")==0) {
	result ="/tmp/g-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-eh")==0) {
	result ="/tmp/g-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-er")==0) {
	result ="/tmp/g-er.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ey")==0) {
	result ="/tmp/g-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"g-f")==0) {
	result ="/tmp/g-f.wav";	
	}
	if (g_strcmp0(diphone_str,"g-g")==0) {
	result ="/tmp/g-g.wav";	
	}
	if (g_strcmp0(diphone_str,"g-hh")==0) {
	result ="/tmp/g-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ih")==0) {
	result ="/tmp/g-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"g-iy")==0) {
	result ="/tmp/g-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"g-jh")==0) {
	result ="/tmp/g-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-k")==0) {
	result ="/tmp/g-k.wav";	
	}
	if (g_strcmp0(diphone_str,"g-l")==0) {
	result ="/tmp/g-l.wav";	
	}
	if (g_strcmp0(diphone_str,"g-m")==0) {
	result ="/tmp/g-m.wav";	
	}
	if (g_strcmp0(diphone_str,"g-n")==0) {
	result ="/tmp/g-n.wav";	
	}
	if (g_strcmp0(diphone_str,"g-ow")==0) {
	result ="/tmp/g-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"g-oy")==0) {
	result ="/tmp/-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"g-p")==0) {
	result ="/tmp/-p.wav";	
	}
	if (g_strcmp0(diphone_str,"g-pau")==0) {
	result ="/tmp/g-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"g-r")==0) {
	result ="/tmp/g-r.wav";	
	}
	if (g_strcmp0(diphone_str,"g-s")==0) {
	result ="/tmp/g-s.wav";	
	}
	if (g_strcmp0(diphone_str,"g-sh")==0) {
	result ="/tmp/g-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-t")==0) {
	result ="/tmp/g-t.wav";	
	}
	if (g_strcmp0(diphone_str,"g-th")==0) {
	result ="/tmp/g-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"g-uh")==0) {
	result ="/tmp/g-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"g-uw")==0) {
	result ="/tmp/g-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"g-v")==0) {
	result ="/tmp/g-v.wav";	
	}
	if (g_strcmp0(diphone_str,"g-w")==0) {
	result ="/tmp/g-w.wav";	
	}
	if (g_strcmp0(diphone_str,"g-y")==0) {
	result ="/tmp/g-y.wav";	
	}
	if (g_strcmp0(diphone_str,"g-z")==0) {
	result ="/tmp/g-z.wav";	
	}
	if (g_strcmp0(diphone_str,"g-zh")==0) {
	result ="/tmp/g-zh.wav";	
	}
	
	//g alternatives
	if (g_strcmp0(diphone_str,"g_-_l")==0) {
	result ="/tmp/g_-_l.wav";	
	}
	if (g_strcmp0(diphone_str,"g_-_r")==0) {
	result ="/tmp/g_-_r.wav";	
	}
	if (g_strcmp0(diphone_str,"g_-_w")==0) {
	result ="/tmp/g_-_w.wav";	
	}
	if (g_strcmp0(diphone_str,"g_-_y")==0) {
	result ="/tmp/g_-_y.wav";	
	}
	
	//hh diphones
	if (g_strcmp0(diphone_str,"hh-aa")==0) {
	result ="/tmp/hh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ae")==0) {
	result ="/tmp/hh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ah")==0) {
	result ="/tmp/hh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ao")==0) {
	result ="/tmp/hh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-aw")==0) {
	result ="/tmp/hh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ax")==0) {
	result ="/tmp/hh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ay")==0) {
	result ="/tmp/hh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-eh")==0) {
	result ="/tmp/hh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ih")==0) {
	result ="/tmp/hh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-iy")==0) {
	result ="/tmp/hh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-ow")==0) {
	result ="/tmp/hh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-oy")==0) {
	result ="/tmp/hh-oy.wav";	
	}
	
	if (g_strcmp0(diphone_str,"hh-uh")==0) {
	result ="/tmp/hh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"hh-uw")==0) {
	result ="/tmp/hh-uw.wav";	
	}
	
	
	//ih diphones
	if (g_strcmp0(diphone_str,"ih-aa")==0) {
	result ="/tmp/ih-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ae")==0) {
	result ="/tmp/ih-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ah")==0) {
	result ="/tmp/ih-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ao")==0) {
	result ="/tmp/ih-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-aw")==0) {
	result ="/tmp/ih-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ax")==0) {
	result ="/tmp/ih-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ay")==0) {
	result ="/tmp/ih-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-b")==0) {
	result ="/tmp/ih-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ch")==0) {
	result ="/tmp/ih-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-d")==0) {
	result ="/tmp/ih-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-dh")==0) {
	result ="/tmp/ih-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-eh")==0) {
	result ="/tmp/ih-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-er")==0) {
	result ="/tmp/ih-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ey")==0) {
	result ="/tmp/ih-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-f")==0) {
	result ="/tmp/ih-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-g")==0) {
	result ="/tmp/ih-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-hh")==0) {
	result ="/tmp/ih-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ih")==0) {
	result ="/tmp/ih-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-iy")==0) {
	result ="/tmp/ih-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-jh")==0) {
	result ="/tmp/ih-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-k")==0) {
	result ="/tmp/ih-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-l")==0) {
	result ="/tmp/ih-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-m")==0) {
	result ="/tmp/ih-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-n")==0) {
	result ="/tmp/ih-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ng")==0) {
	result ="/tmp/ih-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-ow")==0) {
	result ="/tmp/ih-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-oy")==0) {
	result ="/tmp/ih-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-p")==0) {
	result ="/tmp/ih-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-pau")==0) {
	result ="/tmp/ih-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-r")==0) {
	result ="/tmp/ih-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-s")==0) {
	result ="/tmp/ih-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-sh")==0) {
	result ="/tmp/ih-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-t")==0) {
	result ="/tmp/ih-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-th")==0) {
	result ="/tmp/ih-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ih-uh")==0) {
	result ="/tmp/ih-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-uw")==0) {
	result ="/tmp/ih-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-v")==0) {
	result ="/tmp/ih-v.wav";	
	}
	if (g_strcmp0(diphone_str,"-w")==0) {
	result ="/tmp/-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-y")==0) {
	result ="/tmp/ih-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-z")==0) {
	result ="/tmp/ih-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ih-zh")==0) {
	result ="/tmp/ih-zh.wav";	
	}
	
	
	//iy diphones
	if (g_strcmp0(diphone_str,"iy-aa")==0) {
	result ="/tmp/iy-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ae")==0) {
	result ="/tmp/iy-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ah")==0) {
	result ="/tmp/iy-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ao")==0) {
	result ="/tmp/iy-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-aw")==0) {
	result ="/tmp/iy-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ax")==0) {
	result ="/tmp/iy-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ay")==0) {
	result ="/tmp/iy-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-b")==0) {
	result ="/tmp/iy-b.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ch")==0) {
	result ="/tmp/iy-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-d")==0) {
	result ="/tmp/iy-d.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-dh")==0) {
	result ="/tmp/iy-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-eh")==0) {
	result ="/tmp/iy-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-er")==0) {
	result ="/tmp/iy-er.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ey")==0) {
	result ="/tmp/iy-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-f")==0) {
	result ="/tmp/iy-f.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-g")==0) {
	result ="/tmp/iy-g.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-hh")==0) {
	result ="/tmp/iy-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ih")==0) {
	result ="/tmp/iy-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-iy")==0) {
	result ="/tmp/iy-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-jh")==0) {
	result ="/tmp/iy-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-k")==0) {
	result ="/tmp/iy-k.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-l")==0) {
	result ="/tmp/iy-l.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-m")==0) {
	result ="/tmp/iy-m.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-n")==0) {
	result ="/tmp/iy-n.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ng")==0) {
	result ="/tmp/iy-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-ow")==0) {
	result ="/tmp/iy-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-oy")==0) {
	result ="/tmp/iy-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-p")==0) {
	result ="/tmp/iy-p.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-pau")==0) {
	result ="/tmp/iy-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-r")==0) {
	result ="/tmp/iy-r.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-s")==0) {
	result ="/tmp/iy-s.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-sh")==0) {
	result ="/tmp/iy-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-t")==0) {
	result ="/tmp/iy-t.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-th")==0) {
	result ="/tmp/iy-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"iy-uh")==0) {
	result ="/tmp/iy-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-uw")==0) {
	result ="/tmp/iy-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-v")==0) {
	result ="/tmp/iy-v.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-w")==0) {
	result ="/tmp/iy-w.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-y")==0) {
	result ="/tmp/iy-y.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-z")==0) {
	result ="/tmp/iy-z.wav";	
	}
	if (g_strcmp0(diphone_str,"iy-zh")==0) {
	result ="/tmp/iy-zh.wav";	
	}
	
	//jh diphones
	if (g_strcmp0(diphone_str,"jh-aa")==0) {
	result ="/tmp/jh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ae")==0) {
	result ="/tmp/jh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ah")==0) {
	result ="/tmp/jh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ao")==0) {
	result ="/tmp/jh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-aw")==0) {
	result ="/tmp/jh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ax")==0) {
	result ="/tmp/jh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ay")==0) {
	result ="/tmp/jh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-b")==0) {
	result ="/tmp/jh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ch")==0) {
	result ="/tmp/jh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-d")==0) {
	result ="/tmp/jh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-dh")==0) {
	result ="/tmp/jh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-eh")==0) {
	result ="/tmp/jh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-er")==0) {
	result ="/tmp/jh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ey")==0) {
	result ="/tmp/jh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-f")==0) {
	result ="/tmp/jh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-g")==0) {
	result ="/tmp/jh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-hh")==0) {
	result ="/tmp/jh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ih")==0) {
	result ="/tmp/jh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-iy")==0) {
	result ="/tmp/jh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-jh")==0) {
	result ="/tmp/jh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-k")==0) {
	result ="/tmp/jh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-l")==0) {
	result ="/tmp/jh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-m")==0) {
	result ="/tmp/jh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-n")==0) {
	result ="/tmp/jh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-ow")==0) {
	result ="/tmp/jh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-oy")==0) {
	result ="/tmp/jh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-p")==0) {
	result ="/tmp/jh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-pau")==0) {
	result ="/tmp/jh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-r")==0) {
	result ="/tmp/jh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-s")==0) {
	result ="/tmp/jh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-sh")==0) {
	result ="/tmp/jh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-t")==0) {
	result ="/tmp/jh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-th")==0) {
	result ="/tmp/jh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"jh-uh")==0) {
	result ="/tmp/jh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-uw")==0) {
	result ="/tmp/jh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-v")==0) {
	result ="/tmp/jh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-w")==0) {
	result ="/tmp/jh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-y")==0) {
	result ="/tmp/jh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-z")==0) {
	result ="/tmp/jh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"jh-zh")==0) {
	result ="/tmp/jh-zh.wav";	
	}
	
	//k diphones
	
	if (g_strcmp0(diphone_str,"k-aa")==0) {
	result ="/tmp/k-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ae")==0) {
	result ="/tmp/k-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ah")==0) {
	result ="/tmp/k-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ao")==0) {
	result ="/tmp/k-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"k-aw")==0) {
	result ="/tmp/k-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ax")==0) {
	result ="/tmp/k-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ay")==0) {
	result ="/tmp/k-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"k-b")==0) {
	result ="/tmp/k-b.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ch")==0) {
	result ="/tmp/k-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"k-d")==0) {
	result ="/tmp/k-d.wav";	
	}
	if (g_strcmp0(diphone_str,"k-dh")==0) {
	result ="/tmp/k-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-eh")==0) {
	result ="/tmp/k-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-er")==0) {
	result ="/tmp/k-er.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ey")==0) {
	result ="/tmp/k-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"k-f")==0) {
	result ="/tmp/k-f.wav";	
	}
	if (g_strcmp0(diphone_str,"k-g")==0) {
	result ="/tmp/k-g.wav";	
	}
	if (g_strcmp0(diphone_str,"k-hh")==0) {
	result ="/tmp/k-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ih")==0) {
	result ="/tmp/k-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"k-iy")==0) {
	result ="/tmp/k-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"k-jh")==0) {
	result ="/tmp/k-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-k")==0) {
	result ="/tmp/k-k.wav";	
	}
	if (g_strcmp0(diphone_str,"k-l")==0) {
	result ="/tmp/k-l.wav";	
	}
	if (g_strcmp0(diphone_str,"k-m")==0) {
	result ="/tmp/k-m.wav";	
	}
	if (g_strcmp0(diphone_str,"k-n")==0) {
	result ="/tmp/k-n.wav";	
	}
	if (g_strcmp0(diphone_str,"k-ow")==0) {
	result ="/tmp/k-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"k-oy")==0) {
	result ="/tmp/k-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"k-p")==0) {
	result ="/tmp/k-p.wav";	
	}
	if (g_strcmp0(diphone_str,"k-pau")==0) {
	result ="/tmp/k-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"k-r")==0) {
	result ="/tmp/k-r.wav";	
	}
	if (g_strcmp0(diphone_str,"k-s")==0) {
	result ="/tmp/k-s.wav";	
	}
	if (g_strcmp0(diphone_str,"k-sh")==0) {
	result ="/tmp/k-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-t")==0) {
	result ="/tmp/k-t.wav";	
	}
	if (g_strcmp0(diphone_str,"k-th")==0) {
	result ="/tmp/k-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"k-uh")==0) {
	result ="/tmp/k-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"k-uw")==0) {
	result ="/tmp/k-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"k-v")==0) {
	result ="/tmp/k-v.wav";	
	}
	if (g_strcmp0(diphone_str,"k-w")==0) {
	result ="/tmp/k-w.wav";	
	}
	if (g_strcmp0(diphone_str,"k-y")==0) {
	result ="/tmp/k-y.wav";	
	}
	if (g_strcmp0(diphone_str,"k-z")==0) {
	result ="/tmp/k-z.wav";	
	}
	if (g_strcmp0(diphone_str,"k-zh")==0) {
	result ="/tmp/k-zh.wav";	
	}
	
	//l diphones
	if (g_strcmp0(diphone_str,"l-aa")==0) {
	result ="/tmp/l-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ae")==0) {
	result ="/tmp/l-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ah")==0) {
	result ="/tmp/l-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ao")==0) {
	result ="/tmp/l-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"l-aw")==0) {
	result ="/tmp/l-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ax")==0) {
	result ="/tmp/l-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ay")==0) {
	result ="/tmp/l-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"l-b")==0) {
	result ="/tmp/l-b.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ch")==0) {
	result ="/tmp/l-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"l-d")==0) {
	result ="/tmp/l-d.wav";	
	}
	if (g_strcmp0(diphone_str,"l-dh")==0) {
	result ="/tmp/l-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-eh")==0) {
	result ="/tmp/l-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-er")==0) {
	result ="/tmp/l-er.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ey")==0) {
	result ="/tmp/l-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"l-f")==0) {
	result ="/tmp/l-f.wav";	
	}
	if (g_strcmp0(diphone_str,"l-g")==0) {
	result ="/tmp/l-g.wav";	
	}
	if (g_strcmp0(diphone_str,"l-hh")==0) {
	result ="/tmp/l-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ih")==0) {
	result ="/tmp/l-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"l-iy")==0) {
	result ="/tmp/l-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"l-jh")==0) {
	result ="/tmp/l-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-k")==0) {
	result ="/tmp/l-k.wav";	
	}
	if (g_strcmp0(diphone_str,"l-l")==0) {
	result ="/tmp/l-l.wav";	
	}
	if (g_strcmp0(diphone_str,"l-m")==0) {
	result ="/tmp/l-m.wav";	
	}
	if (g_strcmp0(diphone_str,"l-n")==0) {
	result ="/tmp/l-n.wav";	
	}
	if (g_strcmp0(diphone_str,"l-ow")==0) {
	result ="/tmp/l-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"l-oy")==0) {
	result ="/tmp/l-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"l-p")==0) {
	result ="/tmp/l-p.wav";	
	}
	if (g_strcmp0(diphone_str,"l-pau")==0) {
	result ="/tmp/l-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"l-r")==0) {
	result ="/tmp/l-r.wav";	
	}
	if (g_strcmp0(diphone_str,"l-s")==0) {
	result ="/tmp/l-s.wav";	
	}
	if (g_strcmp0(diphone_str,"l-sh")==0) {
	result ="/tmp/l-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-t")==0) {
	result ="/tmp/l-t.wav";	
	}
	if (g_strcmp0(diphone_str,"l-th")==0) {
	result ="/tmp/l-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"l-uh")==0) {
	result ="/tmp/l-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"l-uw")==0) {
	result ="/tmp/l-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"l-v")==0) {
	result ="/tmp/l-v.wav";	
	}
	if (g_strcmp0(diphone_str,"l-w")==0) {
	result ="/tmp/l-w.wav";	
	}
	if (g_strcmp0(diphone_str,"l-y")==0) {
	result ="/tmp/l-y.wav";	
	}
	if (g_strcmp0(diphone_str,"l-z")==0) {
	result ="/tmp/l-z.wav";	
	}
	if (g_strcmp0(diphone_str,"l-zh")==0) {
	result ="/tmp/l-zh.wav";	
	}
	
	//m diphones
	if (g_strcmp0(diphone_str,"m-aa")==0) {
	result ="/tmp/m-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ae")==0) {
	result ="/tmp/m-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ah")==0) {
	result ="/tmp/m-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ao")==0) {
	result ="/tmp/m-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"m-aw")==0) {
	result ="/tmp/m-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ax")==0) {
	result ="/tmp/m-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ay")==0) {
	result ="/tmp/m-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"m-b")==0) {
	result ="/tmp/m-b.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ch")==0) {
	result ="/tmp/m-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"m-d")==0) {
	result ="/tmp/m-d.wav";	
	}
	if (g_strcmp0(diphone_str,"m-dh")==0) {
	result ="/tmp/m-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-eh")==0) {
	result ="/tmp/m-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-er")==0) {
	result ="/tmp/m-er.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ey")==0) {
	result ="/tmp/m-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"m-f")==0) {
	result ="/tmp/m-f.wav";	
	}
	if (g_strcmp0(diphone_str,"m-g")==0) {
	result ="/tmp/m-g.wav";	
	}
	if (g_strcmp0(diphone_str,"m-hh")==0) {
	result ="/tmp/m-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ih")==0) {
	result ="/tmp/m-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"m-iy")==0) {
	result ="/tmp/m-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"m-jh")==0) {
	result ="/tmp/m-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-k")==0) {
	result ="/tmp/m-k.wav";	
	}
	if (g_strcmp0(diphone_str,"m-l")==0) {
	result ="/tmp/m-l.wav";	
	}
	if (g_strcmp0(diphone_str,"m-m")==0) {
	result ="/tmp/m-m.wav";	
	}
	if (g_strcmp0(diphone_str,"m-n")==0) {
	result ="/tmp/m-n.wav";	
	}
	if (g_strcmp0(diphone_str,"m-ow")==0) {
	result ="/tmp/m-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"m-oy")==0) {
	result ="/tmp/m-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"m-p")==0) {
	result ="/tmp/m-p.wav";	
	}
	if (g_strcmp0(diphone_str,"m-pau")==0) {
	result ="/tmp/m-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"m-r")==0) {
	result ="/tmp/m-r.wav";	
	}
	if (g_strcmp0(diphone_str,"m-s")==0) {
	result ="/tmp/m-s.wav";	
	}
	if (g_strcmp0(diphone_str,"m-sh")==0) {
	result ="/tmp/m-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-t")==0) {
	result ="/tmp/m-t.wav";	
	}
	if (g_strcmp0(diphone_str,"m-th")==0) {
	result ="/tmp/m-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"m-uh")==0) {
	result ="/tmp/m-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"m-uw")==0) {
	result ="/tmp/m-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"m-v")==0) {
	result ="/tmp/m-v.wav";	
	}
	if (g_strcmp0(diphone_str,"m-w")==0) {
	result ="/tmp/m-w.wav";	
	}
	if (g_strcmp0(diphone_str,"m-y")==0) {
	result ="/tmp/m-y.wav";	
	}
	if (g_strcmp0(diphone_str,"m-z")==0) {
	result ="/tmp/m-z.wav";	
	}
	if (g_strcmp0(diphone_str,"m-zh")==0) {
	result ="/tmp/m-zh.wav";	
	}
	
	//n diphones
	if (g_strcmp0(diphone_str,"n-aa")==0) {
	result ="/tmp/n-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ae")==0) {
	result ="/tmp/n-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ah")==0) {
	result ="/tmp/n-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ao")==0) {
	result ="/tmp/n-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"n-aw")==0) {
	result ="/tmp/n-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ax")==0) {
	result ="/tmp/n-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ay")==0) {
	result ="/tmp/n-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"n-b")==0) {
	result ="/tmp/n-b.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ch")==0) {
	result ="/tmp/n-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"n-d")==0) {
	result ="/tmp/n-d.wav";	
	}
	if (g_strcmp0(diphone_str,"n-dh")==0) {
	result ="/tmp/n-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-eh")==0) {
	result ="/tmp/n-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-er")==0) {
	result ="/tmp/n-er.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ey")==0) {
	result ="/tmp/n-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"n-f")==0) {
	result ="/tmp/n-f.wav";	
	}
	if (g_strcmp0(diphone_str,"n-g")==0) {
	result ="/tmp/n-g.wav";	
	}
	if (g_strcmp0(diphone_str,"n-hh")==0) {
	result ="/tmp/n-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ih")==0) {
	result ="/tmp/n-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"n-iy")==0) {
	result ="/tmp/n-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"n-jh")==0) {
	result ="/tmp/n-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-k")==0) {
	result ="/tmp/n-k.wav";	
	}
	if (g_strcmp0(diphone_str,"n-l")==0) {
	result ="/tmp/n-l.wav";	
	}
	if (g_strcmp0(diphone_str,"n-m")==0) {
	result ="/tmp/n-m.wav";	
	}
	if (g_strcmp0(diphone_str,"n-n")==0) {
	result ="/tmp/n-n.wav";	
	}
	if (g_strcmp0(diphone_str,"n-ow")==0) {
	result ="/tmp/n-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"n-oy")==0) {
	result ="/tmp/n-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"n-p")==0) {
	result ="/tmp/n-p.wav";	
	}
	if (g_strcmp0(diphone_str,"n-pau")==0) {
	result ="/tmp/n-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"n-r")==0) {
	result ="/tmp/n-r.wav";	
	}
	if (g_strcmp0(diphone_str,"n-s")==0) {
	result ="/tmp/n-s.wav";	
	}
	if (g_strcmp0(diphone_str,"n-sh")==0) {
	result ="/tmp/n-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-t")==0) {
	result ="/tmp/n-t.wav";	
	}
	if (g_strcmp0(diphone_str,"n-th")==0) {
	result ="/tmp/n-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"n-uh")==0) {
	result ="/tmp/n-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"n-uw")==0) {
	result ="/tmp/n-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"n-v")==0) {
	result ="/tmp/-v.wav";	
	}
	if (g_strcmp0(diphone_str,"n-w")==0) {
	result ="/tmp/n-w.wav";	
	}
	if (g_strcmp0(diphone_str,"n-y")==0) {
	result ="/tmp/n-y.wav";	
	}
	if (g_strcmp0(diphone_str,"n-z")==0) {
	result ="/tmp/n-z.wav";	
	}
	if (g_strcmp0(diphone_str,"n-zh")==0) {
	result ="/tmp/-zh.wav";	
	}
	
	//n alternatives
	if (g_strcmp0(diphone_str,"n_-_y")==0) {
	result ="/tmp/n_-_y.wav";	
	}
	

	//ng diphones
	if (g_strcmp0(diphone_str,"ng-aa")==0) {
	result ="/tmp/ng-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ae")==0) {
	result ="/tmp/ng-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ah")==0) {
	result ="/tmp/ng-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ao")==0) {
	result ="/tmp/ng-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-aw")==0) {
	result ="/tmp/ng-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ax")==0) {
	result ="/tmp/ng-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ay")==0) {
	result ="/tmp/ng-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-b")==0) {
	result ="/tmp/ng-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ch")==0) {
	result ="/tmp/ng-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-d")==0) {
	result ="/tmp/ng-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-dh")==0) {
	result ="/tmp/ng-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-eh")==0) {
	result ="/tmp/ng-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-er")==0) {
	result ="/tmp/ng-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ey")==0) {
	result ="/tmp/ng-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-f")==0) {
	result ="/tmp/ng-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-g")==0) {
	result ="/tmp/ng-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-hh")==0) {
	result ="/tmp/ng-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ih")==0) {
	result ="/tmp/ng-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-iy")==0) {
	result ="/tmp/ng-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-jh")==0) {
	result ="/tmp/ng-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-k")==0) {
	result ="/tmp/ng-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-l")==0) {
	result ="/tmp/ng-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-m")==0) {
	result ="/tmp/ng-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-n")==0) {
	result ="/tmp/-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-ow")==0) {
	result ="/tmp/ng-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-oy")==0) {
	result ="/tmp/ng-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-p")==0) {
	result ="/tmp/ng-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-pau")==0) {
	result ="/tmp/ng-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-r")==0) {
	result ="/tmp/ng-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-s")==0) {
	result ="/tmp/ng-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-sh")==0) {
	result ="/tmp/ng-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-t")==0) {
	result ="/tmp/ng-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-th")==0) {
	result ="/tmp/ng-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ng-uh")==0) {
	result ="/tmp/ng-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-uw")==0) {
	result ="/tmp/ng-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-v")==0) {
	result ="/tmp/ng-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-w")==0) {
	result ="/tmp/ng-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-y")==0) {
	result ="/tmp/ng-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-z")==0) {
	result ="/tmp/ng-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ng-zh")==0) {
	result ="/tmp/ng-zh.wav";	
	}
	
	//ow diphones
	if (g_strcmp0(diphone_str,"ow-aa")==0) {
	result ="/tmp/ow-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ae")==0) {
	result ="/tmp/ow-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ah")==0) {
	result ="/tmp/ow-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ao")==0) {
	result ="/tmp/ow-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-aw")==0) {
	result ="/tmp/ow-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ax")==0) {
	result ="/tmp/ow-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ay")==0) {
	result ="/tmp/ow-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-b")==0) {
	result ="/tmp/ow-b.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ch")==0) {
	result ="/tmp/ow-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-d")==0) {
	result ="/tmp/ow-d.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-dh")==0) {
	result ="/tmp/ow-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-eh")==0) {
	result ="/tmp/ow-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-er")==0) {
	result ="/tmp/ow-er.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ey")==0) {
	result ="/tmp/ow-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-f")==0) {
	result ="/tmp/ow-f.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-g")==0) {
	result ="/tmp/ow-g.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-hh")==0) {
	result ="/tmp/ow-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ih")==0) {
	result ="/tmp/ow-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-iy")==0) {
	result ="/tmp/ow-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-jh")==0) {
	result ="/tmp/ow-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-k")==0) {
	result ="/tmp/ow-k.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-l")==0) {
	result ="/tmp/ow-l.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-m")==0) {
	result ="/tmp/ow-m.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-n")==0) {
	result ="/tmp/ow-n.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ng")==0) {
	result ="/tmp/ow-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-ow")==0) {
	result ="/tmp/ow-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-oy")==0) {
	result ="/tmp/ow-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-p")==0) {
	result ="/tmp/ow-p.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-pau")==0) {
	result ="/tmp/ow-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-r")==0) {
	result ="/tmp/ow-r.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-s")==0) {
	result ="/tmp/ow-s.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-sh")==0) {
	result ="/tmp/ow-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-t")==0) {
	result ="/tmp/ow-t.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-th")==0) {
	result ="/tmp/ow-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"ow-uh")==0) {
	result ="/tmp/ow-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-uw")==0) {
	result ="/tmp/ow-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-v")==0) {
	result ="/tmp/ow-v.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-w")==0) {
	result ="/tmp/ow-w.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-y")==0) {
	result ="/tmp/ow-y.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-z")==0) {
	result ="/tmp/ow-z.wav";	
	}
	if (g_strcmp0(diphone_str,"ow-zh")==0) {
	result ="/tmp/ow-zh.wav";	
	}
	
	//oy diphones
	if (g_strcmp0(diphone_str,"oy-aa")==0) {
	result ="/tmp/oy-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ae")==0) {
	result ="/tmp/oy-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ah")==0) {
	result ="/tmp/oy-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ao")==0) {
	result ="/tmp/oy-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-aw")==0) {
	result ="/tmp/oy-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ax")==0) {
	result ="/tmp/oy-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ay")==0) {
	result ="/tmp/oy-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-b")==0) {
	result ="/tmp/oy-b.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ch")==0) {
	result ="/tmp/oy-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-d")==0) {
	result ="/tmp/oy-d.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-dh")==0) {
	result ="/tmp/oy-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-eh")==0) {
	result ="/tmp/oy-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-er")==0) {
	result ="/tmp/oy-er.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ey")==0) {
	result ="/tmp/oy-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-f")==0) {
	result ="/tmp/oy-f.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-g")==0) {
	result ="/tmp/oy-g.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-hh")==0) {
	result ="/tmp/oy-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ih")==0) {
	result ="/tmp/oy-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-iy")==0) {
	result ="/tmp/oy-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-jh")==0) {
	result ="/tmp/oy-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-k")==0) {
	result ="/tmp/oy-k.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-l")==0) {
	result ="/tmp/oy-l.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-m")==0) {
	result ="/tmp/oy-m.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-n")==0) {
	result ="/tmp/oy-n.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ng")==0) {
	result ="/tmp/oy-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-ow")==0) {
	result ="/tmp/oy-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-oy")==0) {
	result ="/tmp/oy-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-p")==0) {
	result ="/tmp/oy-p.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-pau")==0) {
	result ="/tmp/oy-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-r")==0) {
	result ="/tmp/oy-r.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-s")==0) {
	result ="/tmp/oy-s.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-sh")==0) {
	result ="/tmp/oy-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-t")==0) {
	result ="/tmp/oy-t.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-th")==0) {
	result ="/tmp/oy-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"oy-uh")==0) {
	result ="/tmp/oy-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-uw")==0) {
	result ="/tmp/oy-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-v")==0) {
	result ="/tmp/oy-v.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-w")==0) {
	result ="/tmp/oy-w.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-y")==0) {
	result ="/tmp/oy-y.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-z")==0) {
	result ="/tmp/oy-z.wav";	
	}
	if (g_strcmp0(diphone_str,"oy-zh")==0) {
	result ="/tmp/oy-zh.wav";	
	}
	
	//p diphones
	if (g_strcmp0(diphone_str,"p-aa")==0) {
	result ="/tmp/p-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ae")==0) {
	result ="/tmp/p-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ah")==0) {
	result ="/tmp/p-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ao")==0) {
	result ="/tmp/p-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"p-aw")==0) {
	result ="/tmp/p-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ax")==0) {
	result ="/tmp/p-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ay")==0) {
	result ="/tmp/p-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"p-b")==0) {
	result ="/tmp/p-b.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ch")==0) {
	result ="/tmp/p-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"p-d")==0) {
	result ="/tmp/p-d.wav";	
	}
	if (g_strcmp0(diphone_str,"p-dh")==0) {
	result ="/tmp/p-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-eh")==0) {
	result ="/tmp/p-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-er")==0) {
	result ="/tmp/p-er.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ey")==0) {
	result ="/tmp/p-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"p-f")==0) {
	result ="/tmp/p-f.wav";	
	}
	if (g_strcmp0(diphone_str,"p-g")==0) {
	result ="/tmp/p-g.wav";	
	}
	if (g_strcmp0(diphone_str,"p-hh")==0) {
	result ="/tmp/p-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"-ih")==0) {
	result ="/tmp/-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"p-iy")==0) {
	result ="/tmp/p-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"p-jh")==0) {
	result ="/tmp/p-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-k")==0) {
	result ="/tmp/p-k.wav";	
	}
	if (g_strcmp0(diphone_str,"p-l")==0) {
	result ="/tmp/p-l.wav";	
	}
	if (g_strcmp0(diphone_str,"p-m")==0) {
	result ="/tmp/p-m.wav";	
	}
	if (g_strcmp0(diphone_str,"p-n")==0) {
	result ="/tmp/p-n.wav";	
	}
	if (g_strcmp0(diphone_str,"p-ow")==0) {
	result ="/tmp/p-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"p-oy")==0) {
	result ="/tmp/p-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"p-p")==0) {
	result ="/tmp/p-p.wav";	
	}
	if (g_strcmp0(diphone_str,"p-pau")==0) {
	result ="/tmp/p-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"p-r")==0) {
	result ="/tmp/p-r.wav";	
	}
	if (g_strcmp0(diphone_str,"p-s")==0) {
	result ="/tmp/p-s.wav";	
	}
	if (g_strcmp0(diphone_str,"p-sh")==0) {
	result ="/tmp/p-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-t")==0) {
	result ="/tmp/p-t.wav";	
	}
	if (g_strcmp0(diphone_str,"p-th")==0) {
	result ="/tmp/p-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"p-uh")==0) {
	result ="/tmp/p-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"p-uw")==0) {
	result ="/tmp/p-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"p-v")==0) {
	result ="/tmp/p-v.wav";	
	}
	if (g_strcmp0(diphone_str,"p-w")==0) {
	result ="/tmp/p-w.wav";	
	}
	if (g_strcmp0(diphone_str,"p-y")==0) {
	result ="/tmp/p-y.wav";	
	}
	if (g_strcmp0(diphone_str,"p-z")==0) {
	result ="/tmp/p-z.wav";	
	}
	if (g_strcmp0(diphone_str,"p-zh")==0) {
	result ="/tmp/p-zh.wav";	
	}
	
	// p alternatives
	if (g_strcmp0(diphone_str,"p_-_l")==0) {
	result ="/tmp/p_-_l.wav";	
	}
	if (g_strcmp0(diphone_str,"p_-_r")==0) {
	result ="/tmp/p_-_r.wav";	
	}
	if (g_strcmp0(diphone_str,"p_-_w")==0) {
	result ="/tmp/p_-_w.wav";	
	}
	if (g_strcmp0(diphone_str,"p_-_y")==0) {
	result ="/tmp/p_-_y.wav";	
	}
	
	//pau diphones
	if (g_strcmp0(diphone_str,"pau-aa")==0) {
	result ="/tmp/pau-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ae")==0) {
	result ="/tmp/pau-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ah")==0) {
	result ="/tmp/pau-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ao")==0) {
	result ="/tmp/pau-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-aw")==0) {
	result ="/tmp/pau-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ax")==0) {
	result ="/tmp/pau-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ay")==0) {
	result ="/tmp/pau-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-b")==0) {
	result ="/tmp/pau-b.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ch")==0) {
	result ="/tmp/pau-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-d")==0) {
	result ="/tmp/pau-d.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-dh")==0) {
	result ="/tmp/pau-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-eh")==0) {
	result ="/tmp/pau-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-er")==0) {
	result ="/tmp/pau-er.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ey")==0) {
	result ="/tmp/pau-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-f")==0) {
	result ="/tmp/pau-f.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-g")==0) {
	result ="/tmp/pau-g.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-hh")==0) {
	result ="/tmp/pau-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ih")==0) {
	result ="/tmp/pau-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-iy")==0) {
	result ="/tmp/pau-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-jh")==0) {
	result ="/tmp/pau-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-k")==0) {
	result ="/tmp/pau-k.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-l")==0) {
	result ="/tmp/pau-l.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-m")==0) {
	result ="/tmp/pau-m.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-n")==0) {
	result ="/tmp/pau-n.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-ow")==0) {
	result ="/tmp/pau-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-oy")==0) {
	result ="/tmp/pau-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-p")==0) {
	result ="/tmp/pau-p.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-pau")==0) {
	result ="/tmp/pau-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-r")==0) {
	result ="/tmp/pau-r.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-s")==0) {
	result ="/tmp/pau-s.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-sh")==0) {
	result ="/tmp/pau-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-t")==0) {
	result ="/tmp/pau-t.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-th")==0) {
	result ="/tmp/pau-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"pau-uh")==0) {
	result ="/tmp/pau-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-uw")==0) {
	result ="/tmp/pau-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-v")==0) {
	result ="/tmp/pau-v.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-w")==0) {
	result ="/tmp/pau-w.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-y")==0) {
	result ="/tmp/pau-y.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-z")==0) {
	result ="/tmp/pau-z.wav";	
	}
	if (g_strcmp0(diphone_str,"pau-zh")==0) {
	result ="/tmp/pau-zh.wav";	
	}
	
	//r diphones
	
	if (g_strcmp0(diphone_str,"r-aa")==0) {
	result ="/tmp/r-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ae")==0) {
	result ="/tmp/r-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ah")==0) {
	result ="/tmp/r-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ao")==0) {
	result ="/tmp/r-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"r-aw")==0) {
	result ="/tmp/r-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ax")==0) {
	result ="/tmp/r-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ay")==0) {
	result ="/tmp/r-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"r-b")==0) {
	result ="/tmp/r-b.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ch")==0) {
	result ="/tmp/r-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"r-d")==0) {
	result ="/tmp/r-d.wav";	
	}
	if (g_strcmp0(diphone_str,"r-dh")==0) {
	result ="/tmp/r-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-eh")==0) {
	result ="/tmp/r-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-er")==0) {
	result ="/tmp/r-er.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ey")==0) {
	result ="/tmp/r-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"r-f")==0) {
	result ="/tmp/r-f.wav";	
	}
	if (g_strcmp0(diphone_str,"r-g")==0) {
	result ="/tmp/r-g.wav";	
	}
	if (g_strcmp0(diphone_str,"r-hh")==0) {
	result ="/tmp/r-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ih")==0) {
	result ="/tmp/r-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"r-iy")==0) {
	result ="/tmp/r-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"r-jh")==0) {
	result ="/tmp/r-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-k")==0) {
	result ="/tmp/r-k.wav";	
	}
	if (g_strcmp0(diphone_str,"r-l")==0) {
	result ="/tmp/r-l.wav";	
	}
	if (g_strcmp0(diphone_str,"r-m")==0) {
	result ="/tmp/r-m.wav";	
	}
	if (g_strcmp0(diphone_str,"r-n")==0) {
	result ="/tmp/r-n.wav";	
	}
	if (g_strcmp0(diphone_str,"r-ow")==0) {
	result ="/tmp/r-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"r-oy")==0) {
	result ="/tmp/r-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"r-p")==0) {
	result ="/tmp/r-p.wav";	
	}
	if (g_strcmp0(diphone_str,"r-pau")==0) {
	result ="/tmp/r-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"r-r")==0) {
	result ="/tmp/r-r.wav";	
	}
	if (g_strcmp0(diphone_str,"r-s")==0) {
	result ="/tmp/r-s.wav";	
	}
	if (g_strcmp0(diphone_str,"r-sh")==0) {
	result ="/tmp/r-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-t")==0) {
	result ="/tmp/r-t.wav";	
	}
	if (g_strcmp0(diphone_str,"r-th")==0) {
	result ="/tmp/r-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"r-uh")==0) {
	result ="/tmp/r-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"r-uw")==0) {
	result ="/tmp/r-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"r-v")==0) {
	result ="/tmp/r-v.wav";	
	}
	if (g_strcmp0(diphone_str,"r-w")==0) {
	result ="/tmp/r-w.wav";	
	}
	if (g_strcmp0(diphone_str,"r-y")==0) {
	result ="/tmp/r-y.wav";	
	}
	if (g_strcmp0(diphone_str,"r-z")==0) {
	result ="/tmp/r-z.wav";	
	}
	if (g_strcmp0(diphone_str,"r-zh")==0) {
	result ="/tmp/r-zh.wav";	
	}
	
	//s diphones
	if (g_strcmp0(diphone_str,"s-aa")==0) {
	result ="/tmp/s-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ae")==0) {
	result ="/tmp/s-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ah")==0) {
	result ="/tmp/s-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ao")==0) {
	result ="/tmp/s-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"s-aw")==0) {
	result ="/tmp/s-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ax")==0) {
	result ="/tmp/s-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ay")==0) {
	result ="/tmp/s-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"s-b")==0) {
	result ="/tmp/s-b.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ch")==0) {
	result ="/tmp/s-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"s-d")==0) {
	result ="/tmp/s-d.wav";	
	}
	if (g_strcmp0(diphone_str,"s-dh")==0) {
	result ="/tmp/s-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-eh")==0) {
	result ="/tmp/s-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-er")==0) {
	result ="/tmp/s-er.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ey")==0) {
	result ="/tmp/s-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"s-f")==0) {
	result ="/tmp/s-f.wav";	
	}
	if (g_strcmp0(diphone_str,"s-g")==0) {
	result ="/tmp/s-g.wav";	
	}
	if (g_strcmp0(diphone_str,"s-hh")==0) {
	result ="/tmp/s-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ih")==0) {
	result ="/tmp/s-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"s-iy")==0) {
	result ="/tmp/s-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"s-jh")==0) {
	result ="/tmp/s-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-k")==0) {
	result ="/tmp/s-k.wav";	
	}
	if (g_strcmp0(diphone_str,"s-l")==0) {
	result ="/tmp/s-l.wav";	
	}
	if (g_strcmp0(diphone_str,"s-m")==0) {
	result ="/tmp/s-m.wav";	
	}
	if (g_strcmp0(diphone_str,"s-n")==0) {
	result ="/tmp/s-n.wav";	
	}
	if (g_strcmp0(diphone_str,"s-ow")==0) {
	result ="/tmp/s-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"s-oy")==0) {
	result ="/tmp/s-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"s-p")==0) {
	result ="/tmp/s-p.wav";	
	}
	if (g_strcmp0(diphone_str,"s-pau")==0) {
	result ="/tmp/s-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"s-r")==0) {
	result ="/tmp/s-r.wav";	
	}
	if (g_strcmp0(diphone_str,"s-s")==0) {
	result ="/tmp/s-s.wav";	
	}
	if (g_strcmp0(diphone_str,"s-sh")==0) {
	result ="/tmp/s-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-t")==0) {
	result ="/tmp/s-t.wav";	
	}
	if (g_strcmp0(diphone_str,"s-th")==0) {
	result ="/tmp/s-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"s-uh")==0) {
	result ="/tmp/s-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"s-uw")==0) {
	result ="/tmp/s-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"s-v")==0) {
	result ="/tmp/s-v.wav";	
	}
	if (g_strcmp0(diphone_str,"s-w")==0) {
	result ="/tmp/s-w.wav";	
	}
	if (g_strcmp0(diphone_str,"s-y")==0) {
	result ="/tmp/s-y.wav";	
	}
	if (g_strcmp0(diphone_str,"s-z")==0) {
	result ="/tmp/s-z.wav";	
	}
	if (g_strcmp0(diphone_str,"s-zh")==0) {
	result ="/tmp/-zh.wav";	
	}
	
	//s alternatives
	if (g_strcmp0(diphone_str,"s_-_k")==0) {
	result ="/tmp/s_-_k.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_l")==0) {
	result ="/tmp/s_-_l.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_m")==0) {
	result ="/tmp/s_-_m.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_n")==0) {
	result ="/tmp/s_-_n.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_p")==0) {
	result ="/tmp/s_-_p.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_t")==0) {
	result ="/tmp/s_-_t.wav";	
	}
	if (g_strcmp0(diphone_str,"s_-_y")==0) {
	result ="/tmp/s_-_y.wav";	
	}
	
	//sh diphones
	if (g_strcmp0(diphone_str,"sh-aa")==0) {
	result ="/tmp/sh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ae")==0) {
	result ="/tmp/sh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ah")==0) {
	result ="/tmp/sh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ao")==0) {
	result ="/tmp/sh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-aw")==0) {
	result ="/tmp/sh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ax")==0) {
	result ="/tmp/sh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ay")==0) {
	result ="/tmp/sh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-b")==0) {
	result ="/tmp/sh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ch")==0) {
	result ="/tmp/sh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-d")==0) {
	result ="/tmp/sh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-dh")==0) {
	result ="/tmp/sh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-eh")==0) {
	result ="/tmp/sh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-er")==0) {
	result ="/tmp/sh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ey")==0) {
	result ="/tmp/sh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-f")==0) {
	result ="/tmp/sh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-g")==0) {
	result ="/tmp/sh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-hh")==0) {
	result ="/tmp/sh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ih")==0) {
	result ="/tmp/sh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-iy")==0) {
	result ="/tmp/sh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-jh")==0) {
	result ="/tmp/sh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-k")==0) {
	result ="/tmp/sh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-l")==0) {
	result ="/tmp/sh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-m")==0) {
	result ="/tmp/sh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-n")==0) {
	result ="/tmp/sh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-ow")==0) {
	result ="/tmp/sh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-oy")==0) {
	result ="/tmp/sh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-p")==0) {
	result ="/tmp/sh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-pau")==0) {
	result ="/tmp/sh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-r")==0) {
	result ="/tmp/sh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-s")==0) {
	result ="/tmp/sh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-sh")==0) {
	result ="/tmp/sh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-t")==0) {
	result ="/tmp/sh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-th")==0) {
	result ="/tmp/sh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"sh-uh")==0) {
	result ="/tmp/sh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-uw")==0) {
	result ="/tmp/sh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-v")==0) {
	result ="/tmp/sh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-w")==0) {
	result ="/tmp/sh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-y")==0) {
	result ="/tmp/sh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-z")==0) {
	result ="/tmp/sh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"sh-zh")==0) {
	result ="/tmp/sh-zh.wav";	
	}
	
	//t diphones
	if (g_strcmp0(diphone_str,"t-aa")==0) {
	result ="/tmp/t-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ae")==0) {
	result ="/tmp/t-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ah")==0) {
	result ="/tmp/t-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ao")==0) {
	result ="/tmp/t-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"t-aw")==0) {
	result ="/tmp/t-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ax")==0) {
	result ="/tmp/t-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ay")==0) {
	result ="/tmp/t-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"t-b")==0) {
	result ="/tmp/t-b.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ch")==0) {
	result ="/tmp/t-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"t-d")==0) {
	result ="/tmp/t-d.wav";	
	}
	if (g_strcmp0(diphone_str,"t-dh")==0) {
	result ="/tmp/t-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-eh")==0) {
	result ="/tmp/t-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-er")==0) {
	result ="/tmp/t-er.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ey")==0) {
	result ="/tmp/t-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"t-f")==0) {
	result ="/tmp/t-f.wav";	
	}
	if (g_strcmp0(diphone_str,"t-g")==0) {
	result ="/tmp/t-g.wav";	
	}
	if (g_strcmp0(diphone_str,"t-hh")==0) {
	result ="/tmp/t-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ih")==0) {
	result ="/tmp/t-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"t-iy")==0) {
	result ="/tmp/t-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"t-jh")==0) {
	result ="/tmp/t-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-k")==0) {
	result ="/tmp/t-k.wav";	
	}
	if (g_strcmp0(diphone_str,"t-l")==0) {
	result ="/tmp/t-l.wav";	
	}
	if (g_strcmp0(diphone_str,"t-m")==0) {
	result ="/tmp/t-m.wav";	
	}
	if (g_strcmp0(diphone_str,"t-n")==0) {
	result ="/tmp/t-n.wav";	
	}
	if (g_strcmp0(diphone_str,"t-ow")==0) {
	result ="/tmp/t-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"t-oy")==0) {
	result ="/tmp/t-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"t-p")==0) {
	result ="/tmp/t-p.wav";	
	}
	if (g_strcmp0(diphone_str,"t-pau")==0) {
	result ="/tmp/t-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"t-r")==0) {
	result ="/tmp/t-r.wav";	
	}
	if (g_strcmp0(diphone_str,"t-s")==0) {
	result ="/tmp/t-s.wav";	
	}
	if (g_strcmp0(diphone_str,"t-sh")==0) {
	result ="/tmp/t-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"-t")==0) {
	result ="/tmp/-t.wav";	
	}
	if (g_strcmp0(diphone_str,"t-th")==0) {
	result ="/tmp/t-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"t-uh")==0) {
	result ="/tmp/t-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"t-uw")==0) {
	result ="/tmp/t-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"t-v")==0) {
	result ="/tmp/t-v.wav";	
	}
	if (g_strcmp0(diphone_str,"t-w")==0) {
	result ="/tmp/t-w.wav";	
	}
	if (g_strcmp0(diphone_str,"t-y")==0) {
	result ="/tmp/t-y.wav";	
	}
	if (g_strcmp0(diphone_str,"t-z")==0) {
	result ="/tmp/t-z.wav";	
	}
	if (g_strcmp0(diphone_str,"t-zh")==0) {
	result ="/tmp/t-zh.wav";	
	}
	
	
	//th diphones
	if (g_strcmp0(diphone_str,"th-aa")==0) {
	result ="/tmp/th-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ae")==0) {
	result ="/tmp/th-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ah")==0) {
	result ="/tmp/th-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ao")==0) {
	result ="/tmp/th-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"th-aw")==0) {
	result ="/tmp/th-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ax")==0) {
	result ="/tmp/th-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ay")==0) {
	result ="/tmp/th-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"th-b")==0) {
	result ="/tmp/th-b.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ch")==0) {
	result ="/tmp/th-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"th-d")==0) {
	result ="/tmp/th-d.wav";	
	}
	if (g_strcmp0(diphone_str,"th-dh")==0) {
	result ="/tmp/th-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-eh")==0) {
	result ="/tmp/th-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-er")==0) {
	result ="/tmp/th-er.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ey")==0) {
	result ="/tmp/th-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"th-f")==0) {
	result ="/tmp/th-f.wav";	
	}
	if (g_strcmp0(diphone_str,"th-g")==0) {
	result ="/tmp/th-g.wav";	
	}
	if (g_strcmp0(diphone_str,"th-hh")==0) {
	result ="/tmp/th-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ih")==0) {
	result ="/tmp/th-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"th-iy")==0) {
	result ="/tmp/th-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"th-jh")==0) {
	result ="/tmp/th-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-k")==0) {
	result ="/tmp/th-k.wav";	
	}
	if (g_strcmp0(diphone_str,"th-l")==0) {
	result ="/tmp/th-l.wav";	
	}
	if (g_strcmp0(diphone_str,"th-m")==0) {
	result ="/tmp/th-m.wav";	
	}
	if (g_strcmp0(diphone_str,"th-n")==0) {
	result ="/tmp/th-n.wav";	
	}
	if (g_strcmp0(diphone_str,"th-ow")==0) {
	result ="/tmp/th-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"th-oy")==0) {
	result ="/tmp/th-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"th-p")==0) {
	result ="/tmp/th-p.wav";	
	}
	if (g_strcmp0(diphone_str,"th-pau")==0) {
	result ="/tmp/th-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"th-r")==0) {
	result ="/tmp/th-r.wav";	
	}
	if (g_strcmp0(diphone_str,"th-s")==0) {
	result ="/tmp/th-s.wav";	
	}
	if (g_strcmp0(diphone_str,"th-sh")==0) {
	result ="/tmp/th-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-t")==0) {
	result ="/tmp/th-t.wav";	
	}
	if (g_strcmp0(diphone_str,"th-th")==0) {
	result ="/tmp/th-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"th-uh")==0) {
	result ="/tmp/th-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"th-uw")==0) {
	result ="/tmp/th-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"th-v")==0) {
	result ="/tmp/th-v.wav";	
	}
	if (g_strcmp0(diphone_str,"th-w")==0) {
	result ="/tmp/th-w.wav";	
	}
	if (g_strcmp0(diphone_str,"th-y")==0) {
	result ="/tmp/th-y.wav";	
	}
	if (g_strcmp0(diphone_str,"th-z")==0) {
	result ="/tmp/th-z.wav";	
	}
	if (g_strcmp0(diphone_str,"th-zh")==0) {
	result ="/tmp/th-zh.wav";	
	}
	
	//uh diphones
	if (g_strcmp0(diphone_str,"uh-aa")==0) {
	result ="/tmp/uh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ae")==0) {
	result ="/tmp/uh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ah")==0) {
	result ="/tmp/uh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ao")==0) {
	result ="/tmp/uh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-aw")==0) {
	result ="/tmp/uh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ax")==0) {
	result ="/tmp/uh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ay")==0) {
	result ="/tmp/uh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-b")==0) {
	result ="/tmp/uh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ch")==0) {
	result ="/tmp/uh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-d")==0) {
	result ="/tmp/uh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-dh")==0) {
	result ="/tmp/uh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-eh")==0) {
	result ="/tmp/uh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-er")==0) {
	result ="/tmp/uh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ey")==0) {
	result ="/tmp/uh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-f")==0) {
	result ="/tmp/uh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-g")==0) {
	result ="/tmp/uh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-hh")==0) {
	result ="/tmp/uh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ih")==0) {
	result ="/tmp/uh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-iy")==0) {
	result ="/tmp/uh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-jh")==0) {
	result ="/tmp/uh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-k")==0) {
	result ="/tmp/uh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-l")==0) {
	result ="/tmp/uh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-m")==0) {
	result ="/tmp/uh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-n")==0) {
	result ="/tmp/uh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-ng")==0) {
	result ="/tmp/uh-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"-ow")==0) {
	result ="/tmp/-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-oy")==0) {
	result ="/tmp/uh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-p")==0) {
	result ="/tmp/uh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-pau")==0) {
	result ="/tmp/uh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-r")==0) {
	result ="/tmp/uh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-s")==0) {
	result ="/tmp/uh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-sh")==0) {
	result ="/tmp/uh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-t")==0) {
	result ="/tmp/uh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-th")==0) {
	result ="/tmp/uh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"uh-uh")==0) {
	result ="/tmp/uh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-uw")==0) {
	result ="/tmp/uh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-v")==0) {
	result ="/tmp/uh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-w")==0) {
	result ="/tmp/uh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-y")==0) {
	result ="/tmp/uh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-z")==0) {
	result ="/tmp/uh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"uh-zh")==0) {
	result ="/tmp/uh-zh.wav";	
	}
	
	//uw diphones
	if (g_strcmp0(diphone_str,"uw-aa")==0) {
	result ="/tmp/uw-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ae")==0) {
	result ="/tmp/uw-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ah")==0) {
	result ="/tmp/uw-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ao")==0) {
	result ="/tmp/uw-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-aw")==0) {
	result ="/tmp/uw-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ax")==0) {
	result ="/tmp/uw-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ay")==0) {
	result ="/tmp/uw-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-b")==0) {
	result ="/tmp/uw-b.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ch")==0) {
	result ="/tmp/uw-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-d")==0) {
	result ="/tmp/uw-d.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-dh")==0) {
	result ="/tmp/uw-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-eh")==0) {
	result ="/tmp/uw-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-er")==0) {
	result ="/tmp/uw-er.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ey")==0) {
	result ="/tmp/uw-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-f")==0) {
	result ="/tmp/uw-f.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-g")==0) {
	result ="/tmp/uw-g.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-hh")==0) {
	result ="/tmp/uw-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ih")==0) {
	result ="/tmp/uw-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-iy")==0) {
	result ="/tmp/uw-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-jh")==0) {
	result ="/tmp/uw-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-k")==0) {
	result ="/tmp/uw-k.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-l")==0) {
	result ="/tmp/uw-l.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-m")==0) {
	result ="/tmp/uw-m.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-n")==0) {
	result ="/tmp/uw-n.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ng")==0) {
	result ="/tmp/uw-ng.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-ow")==0) {
	result ="/tmp/uw-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-oy")==0) {
	result ="/tmp/uw-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-p")==0) {
	result ="/tmp/uw-p.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-pau")==0) {
	result ="/tmp/uw-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-r")==0) {
	result ="/tmp/uw-r.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-s")==0) {
	result ="/tmp/uw-s.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-sh")==0) {
	result ="/tmp/uw-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-t")==0) {
	result ="/tmp/uw-t.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-th")==0) {
	result ="/tmp/uw-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"uw-uh")==0) {
	result ="/tmp/uw-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-uw")==0) {
	result ="/tmp/uw-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-v")==0) {
	result ="/tmp/uw-v.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-w")==0) {
	result ="/tmp/uw-w.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-y")==0) {
	result ="/tmp/uw-y.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-z")==0) {
	result ="/tmp/uw-z.wav";	
	}
	if (g_strcmp0(diphone_str,"uw-zh")==0) {
	result ="/tmp/uw-zh.wav";	
	}
	
	//v diphones
	if (g_strcmp0(diphone_str,"v-aa")==0) {
	result ="/tmp/v-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ae")==0) {
	result ="/tmp/v-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ah")==0) {
	result ="/tmp/v-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ao")==0) {
	result ="/tmp/v-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"v-aw")==0) {
	result ="/tmp/v-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ax")==0) {
	result ="/tmp/v-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ay")==0) {
	result ="/tmp/v-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"v-b")==0) {
	result ="/tmp/v-b.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ch")==0) {
	result ="/tmp/v-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"v-d")==0) {
	result ="/tmp/v-d.wav";	
	}
	if (g_strcmp0(diphone_str,"v-dh")==0) {
	result ="/tmp/v-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-eh")==0) {
	result ="/tmp/v-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-er")==0) {
	result ="/tmp/v-er.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ey")==0) {
	result ="/tmp/v-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"v-f")==0) {
	result ="/tmp/v-f.wav";	
	}
	if (g_strcmp0(diphone_str,"v-g")==0) {
	result ="/tmp/v-g.wav";	
	}
	if (g_strcmp0(diphone_str,"v-hh")==0) {
	result ="/tmp/v-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ih")==0) {
	result ="/tmp/v-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"v-iy")==0) {
	result ="/tmp/v-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"v-jh")==0) {
	result ="/tmp/v-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-k")==0) {
	result ="/tmp/v-k.wav";	
	}
	if (g_strcmp0(diphone_str,"v-l")==0) {
	result ="/tmp/v-l.wav";	
	}
	if (g_strcmp0(diphone_str,"v-m")==0) {
	result ="/tmp/v-m.wav";	
	}
	if (g_strcmp0(diphone_str,"v-n")==0) {
	result ="/tmp/v-n.wav";	
	}
	if (g_strcmp0(diphone_str,"v-ow")==0) {
	result ="/tmp/v-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"v-oy")==0) {
	result ="/tmp/v-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"v-p")==0) {
	result ="/tmp/v-p.wav";	
	}
	if (g_strcmp0(diphone_str,"v-pau")==0) {
	result ="/tmp/v-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"v-r")==0) {
	result ="/tmp/v-r.wav";	
	}
	if (g_strcmp0(diphone_str,"v-s")==0) {
	result ="/tmp/v-s.wav";	
	}
	if (g_strcmp0(diphone_str,"v-sh")==0) {
	result ="/tmp/v-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-t")==0) {
	result ="/tmp/v-t.wav";	
	}
	if (g_strcmp0(diphone_str,"v-th")==0) {
	result ="/tmp/v-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"v-uh")==0) {
	result ="/tmp/v-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"v-uw")==0) {
	result ="/tmp/v-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"v-v")==0) {
	result ="/tmp/v-v.wav";	
	}
	if (g_strcmp0(diphone_str,"v-w")==0) {
	result ="/tmp/v-w.wav";	
	}
	if (g_strcmp0(diphone_str,"v-y")==0) {
	result ="/tmp/v-y.wav";	
	}
	if (g_strcmp0(diphone_str,"v-z")==0) {
	result ="/tmp/v-z.wav";	
	}
	if (g_strcmp0(diphone_str,"v-zh")==0) {
	result ="/tmp/v-zh.wav";	
	}
	
	//w diphones
	if (g_strcmp0(diphone_str,"w-aa")==0) {
	result ="/tmp/w-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ae")==0) {
	result ="/tmp/w-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ah")==0) {
	result ="/tmp/w-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ao")==0) {
	result ="/tmp/w-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"w-aw")==0) {
	result ="/tmp/w-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ax")==0) {
	result ="/tmp/w-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ay")==0) {
	result ="/tmp/w-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"w-eh")==0) {
	result ="/tmp/w-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"w-ih")==0) {
	result ="/tmp/w-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"w-iy")==0) {
	result ="/tmp/w-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"w-uh")==0) {
	result ="/tmp/w-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"w-uw")==0) {
	result ="/tmp/w-uw.wav";	
	}
		
	//y diphones
	
	if (g_strcmp0(diphone_str,"y-aa")==0) {
	result ="/tmp/y-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ae")==0) {
	result ="/tmp/y-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ah")==0) {
	result ="/tmp/y-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ao")==0) {
	result ="/tmp/y-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"y-aw")==0) {
	result ="/tmp/y-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ax")==0) {
	result ="/tmp/y-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ay")==0) {
	result ="/tmp/y-ay.wav";	
	}	
	if (g_strcmp0(diphone_str,"y-eh")==0) {
	result ="/tmp/y-eh.wav";	
	}	
	if (g_strcmp0(diphone_str,"y-ey")==0) {
	result ="/tmp/y-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ih")==0) {
	result ="/tmp/y-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"y-iy")==0) {
	result ="/tmp/y-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"y-ow")==0) {
	result ="/tmp/y-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"y-oy")==0) {
	result ="/tmp/y-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"y-uh")==0) {
	result ="/tmp/y-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"y-uw")==0) {
	result ="/tmp/y-uw.wav";	
	}
		
	//z diphones
	
	if (g_strcmp0(diphone_str,"z-aa")==0) {
	result ="/tmp/z-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ae")==0) {
	result ="/tmp/z-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ah")==0) {
	result ="/tmp/z-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ao")==0) {
	result ="/tmp/z-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"z-aw")==0) {
	result ="/tmp/z-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ax")==0) {
	result ="/tmp/z-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ay")==0) {
	result ="/tmp/z-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"z-b")==0) {
	result ="/tmp/z-b.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ch")==0) {
	result ="/tmp/z-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"z-d")==0) {
	result ="/tmp/z-d.wav";	
	}
	if (g_strcmp0(diphone_str,"z-dh")==0) {
	result ="/tmp/z-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-eh")==0) {
	result ="/tmp/z-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-er")==0) {
	result ="/tmp/z-er.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ey")==0) {
	result ="/tmp/z-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"z-f")==0) {
	result ="/tmp/z-f.wav";	
	}
	if (g_strcmp0(diphone_str,"z-g")==0) {
	result ="/tmp/z-g.wav";	
	}
	if (g_strcmp0(diphone_str,"z-hh")==0) {
	result ="/tmp/z-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ih")==0) {
	result ="/tmp/z-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"z-iy")==0) {
	result ="/tmp/z-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"z-jh")==0) {
	result ="/tmp/z-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-k")==0) {
	result ="/tmp/z-k.wav";	
	}
	if (g_strcmp0(diphone_str,"z-l")==0) {
	result ="/tmp/z-l.wav";	
	}
	if (g_strcmp0(diphone_str,"z-m")==0) {
	result ="/tmp/z-m.wav";	
	}
	if (g_strcmp0(diphone_str,"z-n")==0) {
	result ="/tmp/z-n.wav";	
	}
	if (g_strcmp0(diphone_str,"z-ow")==0) {
	result ="/tmp/z-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"z-oy")==0) {
	result ="/tmp/z-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"z-p")==0) {
	result ="/tmp/z-p.wav";	
	}
	if (g_strcmp0(diphone_str,"z-pau")==0) {
	result ="/tmp/z-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"z-r")==0) {
	result ="/tmp/z-r.wav";	
	}
	if (g_strcmp0(diphone_str,"z-s")==0) {
	result ="/tmp/z-s.wav";	
	}
	if (g_strcmp0(diphone_str,"z-sh")==0) {
	result ="/tmp/z-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-t")==0) {
	result ="/tmp/z-t.wav";	
	}
	if (g_strcmp0(diphone_str,"z-th")==0) {
	result ="/tmp/z-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"z-uh")==0) {
	result ="/tmp/z-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"z-uw")==0) {
	result ="/tmp/z-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"z-v")==0) {
	result ="/tmp/z-v.wav";	
	}
	if (g_strcmp0(diphone_str,"z-w")==0) {
	result ="/tmp/z-w.wav";	
	}
	if (g_strcmp0(diphone_str,"z-y")==0) {
	result ="/tmp/z-y.wav";	
	}
	if (g_strcmp0(diphone_str,"z-z")==0) {
	result ="/tmp/z-z.wav";	
	}
	if (g_strcmp0(diphone_str,"z-zh")==0) {
	result ="/tmp/-zh.wav";	
	}
	
	//zh diphones
	if (g_strcmp0(diphone_str,"zh-aa")==0) {
	result ="/tmp/zh-aa.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ae")==0) {
	result ="/tmp/zh-ae.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ah")==0) {
	result ="/tmp/zh-ah.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ao")==0) {
	result ="/tmp/zh-ao.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-aw")==0) {
	result ="/tmp/zh-aw.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ax")==0) {
	result ="/tmp/zh-ax.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ay")==0) {
	result ="/tmp/zh-ay.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-b")==0) {
	result ="/tmp/zh-b.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ch")==0) {
	result ="/tmp/zh-ch.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-d")==0) {
	result ="/tmp/zh-d.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-dh")==0) {
	result ="/tmp/zh-dh.wav";	
	}
	if (g_strcmp0(diphone_str,"-zheh")==0) {
	result ="/tmp/zh-eh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-er")==0) {
	result ="/tmp/zh-er.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ey")==0) {
	result ="/tmp/zh-ey.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-f")==0) {
	result ="/tmp/zh-f.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-g")==0) {
	result ="/tmp/zh-g.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-hh")==0) {
	result ="/tmp/zh-hh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ih")==0) {
	result ="/tmp/zh-ih.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-iy")==0) {
	result ="/tmp/zh-iy.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-jh")==0) {
	result ="/tmp/zh-jh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-k")==0) {
	result ="/tmp/zh-k.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-l")==0) {
	result ="/tmp/zh-l.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-m")==0) {
	result ="/tmp/zh-m.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-n")==0) {
	result ="/tmp/zh-n.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-ow")==0) {
	result ="/tmp/zh-ow.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-oy")==0) {
	result ="/tmp/zh-oy.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-p")==0) {
	result ="/tmp/zh-p.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-pau")==0) {
	result ="/tmp/zh-pau.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-r")==0) {
	result ="/tmp/zh-r.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-s")==0) {
	result ="/tmp/zh-s.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-sh")==0) {
	result ="/tmp/zh-sh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-t")==0) {
	result ="/tmp/zh-t.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-th")==0) {
	result ="/tmp/zh-th.wav";	
	}	
	if (g_strcmp0(diphone_str,"zh-uh")==0) {
	result ="/tmp/zh-uh.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-uw")==0) {
	result ="/tmp/zh-uw.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-v")==0) {
	result ="/tmp/zh-v.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-w")==0) {
	result ="/tmp/zh-w.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-y")==0) {
	result ="/tmp/zh-y.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-z")==0) {
	result ="/tmp/zh-z.wav";	
	}
	if (g_strcmp0(diphone_str,"zh-zh")==0) {
	result ="/tmp/zh-zh.wav";	
	}
	return result;	  
}

