/***************************************************************************
 * GPL v2.0 license (see license document distributed with this software)
 * Alsa player 
 * Author: crispinalan@gmail.com
 ***************************************************************************/

#ifndef WAVPLAY_H
#define WAVPLAY_H

#define ALSA_PCM_NEW_HW_PARAMS_API

#include <alsa/asoundlib.h>
#include <stdint.h>

// wav files
// https://wavefilegem.com/how_wave_files_work.html
// wav specification
// https://sites.google.com/site/musicgapi/technical-documents/wav-file-format
// wav header structure
typedef struct WaveHeader 
{
    char RIFF_marker[4];
    uint32_t file_size;
    char filetype_header[4];
    char format_marker[4];
    uint32_t data_header_length;
    uint16_t format_type;
    uint16_t number_of_channels;
    uint32_t sample_rate;
    uint32_t bytes_per_second;
    uint16_t bytes_per_frame;
    uint16_t bits_per_sample;
} wav_header;


void wavplay(char* file);  //char pointer type




#endif //WAVPLAY_H
