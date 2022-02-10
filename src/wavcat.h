/***************************************************************************
 * GPL v2.0 license (see license document distributed with this software)
 * wav concatenation
 * Author: crispinalan@gmail.com
 ***************************************************************************/
#ifndef WAVCAT_H
#define WAVCAT_H

/*
 * Talk Calendar wav file concatenation
 * Assumes talk wav files have the format:
 * 
 * Number of channels: 1 (mono)
 * Sample rate: 8000
 * Bits per sample: 16
 * 
 * Uses malloc to dynamically allocate data array on heap
 * 
*/

#include <stdio.h>
#include <stdint.h>  //integer bit types int16_t int32_t etc.
#include <stdlib.h> //for malloc
#include <string.h> //for strlen strncpy etc.



typedef struct _WaveHeader_t {
    char chunkID[4];            // 1-4      RIFF
    int32_t chunkSize;          // 5-8
    char format[4];             // 9-12     WAVE
    char subchunkID[4];         // 13-16    fmt
    int32_t subchunkSize;       // 17-20
    uint16_t audioFormat;       // 21-22    PCM = 1
    uint16_t numChannels;       // 23-24
    int32_t sampleRate;         // 25-28
    int32_t bytesPerSecond;     // 29-32
    uint16_t blockAlign;        // 33-34
    uint16_t bitDepth;          // 35-36    16bit support only
    char dataID[4];             // 37-40    data
    int32_t dataSize;           // 41-44
} WaveHeader_t;

typedef struct _WaveData_t {
    int16_t *samples;
    int32_t size;
    int32_t sampleRate;
    uint16_t bitDepth;
} WaveData_t;


WaveData_t* read_wav(char[],size_t);
void write_wav(char * filename, uint32_t num_samples, int16_t * data, uint32_t s_rate);
void write_little_endian(uint32_t word, uint32_t num_bytes, FILE *wav_file);
int32_t get_merge_data_size(int num_files, char *filenames[]);
void merge_wav_files(char *merge_filename, int num_files, char *filenames[]);
void merge_wav_files2(char *merge_filename, int num_files, char *filenames[],int32_t sample_rate);



#endif//WAVCAT_H
