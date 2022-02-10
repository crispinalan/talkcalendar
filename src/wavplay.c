/***************************************************************************
 * GPL v2.0 license (see license document distributed with this software)
 * Alsa player 
 * Author: crispinalan@gmail.com
 ***************************************************************************/
 
#include "wavplay.h"

//See: Introduction to Sound Programming with ALSA by Jeff Tranter
// https://www.linuxjournal.com/article/6735?page=0,1

void wavplay(char *file) {
	
	int rc;
	int debug_info=0;
	char * buffer;
  	int buffer_size;
  	int periods_per_buffer;

  	snd_pcm_t *handle;
  	snd_pcm_hw_params_t *params;
  	snd_pcm_uframes_t frames;

  	unsigned int channels;
  	unsigned int rate;

	wav_header * wav_header_info;

  	FILE * fp;

    // Open wav file to read
	fp = fopen(file, "rb");

	if (fp == NULL)
	{
		printf("ERROR: file does not exist, or cannot be opened.\n");
		return;
	}

	wav_header_info = malloc(44);

	fread(wav_header_info, 1, 44, fp);
    	
    // Assign wav file variables 
	channels = wav_header_info->number_of_channels;
	rate = wav_header_info->sample_rate;	
	//periods_per_buffer = 1; 
	periods_per_buffer = 2; 


  	// Open PCM device for playback
  	if ((rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0)) < 0) 
  	{
    	printf("ERROR: Cannot open pcm device. %s\n", snd_strerror(rc));
  	}

    
  	// Allocate hardware parameters
  	if ((rc = snd_pcm_hw_params_malloc(&params)) < 0)
  	{
  		printf("ERROR: Cannot allocate hardware parameters. %s\n", snd_strerror(rc));
  	}

    
  	// Initialize parameters with default values
  	if ((rc = snd_pcm_hw_params_any(handle, params)) < 0)
  	{
  		printf("ERROR: Cannot initialize hardware parameters. %s\n", snd_strerror(rc));
  	}


  	// Setting hardware parameters
  	if ((rc = snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0)
  	{
  		printf("ERROR: Cannot set interleaved mode. %s\n", snd_strerror(rc));
  	}

  	if ((rc = snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE)) < 0)
  	{
  		printf("ERROR: Cannot set PCM format. %s\n", snd_strerror(rc));
  	}

  	if ((rc = snd_pcm_hw_params_set_channels_near(handle, params, &channels)) < 0)
  	{
  		printf("ERROR: Cannot set number of channels. %s\n", snd_strerror(rc));
  	}

 	if ((rc = snd_pcm_hw_params_set_rate_near(handle, params, &rate, 0)) < 0)
 	{
 		printf("ERROR: Cannot set plyabck rate. %s\n", snd_strerror(rc));
 	}

 	if ((rc = snd_pcm_hw_params(handle, params)) < 0)
 	{
 		printf("ERROR: Cannot set hardware parameters. %s\n", snd_strerror(rc));
 	}


 	// Get hardware parameters
 	if ((rc = snd_pcm_hw_params_get_period_size(params, &frames, 0)) < 0)
	{
		printf("Playback ERROR: Can't get period size. %s\n", snd_strerror(rc));
	}
	if(debug_info) printf("Frames: %lu\n", frames);

	if ((rc = snd_pcm_hw_params_get_channels(params, &channels)) < 0)
	{
		printf("Playback ERROR: Can't get channel number. %s\n", snd_strerror(rc));
	}

	if ((rc = snd_pcm_hw_params_get_rate(params, &rate, 0)) < 0)
	{
		printf("ERROR: Cannot get rate. %s\n", snd_strerror(rc));
	}


	// Free parameters
	snd_pcm_hw_params_free(params);


	// Create buffer
  	buffer_size = frames * periods_per_buffer * channels * sizeof(int16_t); /* 2 bytes/sample, 2 channels */
  	buffer = (char *) malloc(buffer_size);

  	// Send data to ALSA
 	while (rc = fread(buffer, 1, periods_per_buffer * frames * channels * sizeof(int16_t), fp) != 0)
 	{
    	rc = snd_pcm_writei(handle, buffer, frames * periods_per_buffer);
    	if (rc == -EPIPE) 
    	{
      		fprintf(stderr, "underrun occurred\n");
      		snd_pcm_prepare(handle);
    	} 
    	else if (rc < 0) 
    	{
      		printf("ERROR: Cannot write to playback device. %s\n", strerror(rc));
    	}
  	}

  	if(debug_info) printf("Alsa device is now draining...\n");
  	snd_pcm_drain(handle);

  	if(debug_info) printf("closing connections as play done.\n");
  	snd_pcm_close(handle);

  	free(wav_header_info);
  	free(buffer);
  	fclose(fp);

	
}
