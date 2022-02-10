/***************************************************************************
 * GPL v2.0 license (see license document distributed with this software)
 * wav concatenation
 * Author: crispinalan@gmail.com
 ***************************************************************************/
#include "wavcat.h"


WaveData_t* read_wav(char fileName[],size_t fileNameSize) {
        
    if (fileName[fileNameSize] != '\0') {       
        printf("wavcat: read_wave: Invalid string format.\n");
    } else {
        FILE* filePtr = fopen(fileName, "r");
        if (filePtr == NULL) {
			printf("wavcat: unable to open file %s\n",fileName);          
            return NULL;
        } else {
			// Read header
            WaveHeader_t header;
            fread(&header, sizeof(header), 1, filePtr);
            // Check if the file is of supported format            
            if (strncmp(header.chunkID,"RIFF", 4)  ||
            strncmp(header.format,"WAVE", 4)  ||
            strncmp(header.subchunkID,"fmt", 3)   ||
            strncmp(header.dataID, "data", 4)  ||
            header.audioFormat != 1 || //PCM=1
            header.bitDepth != 16)             
            {
				printf("unsupported file type -16 bit only\n");
            }             
            else {
                // initialize the data struct called data using malloc               
                WaveData_t *data = (WaveData_t*) malloc(sizeof(WaveData_t));
                data->sampleRate = header.sampleRate;
                data->bitDepth  = header.bitDepth;
                data->size      = header.dataSize;	
                // initialize the data samples array using malloc 			
                data->samples = (int16_t*) malloc(header.dataSize * sizeof(int16_t));
                //read the data into memory               
                fread(data->samples, sizeof(float), header.dataSize, filePtr);
                fclose(filePtr);
                return data;
            }
        }
    }
    return NULL;
}

void write_little_endian(uint32_t word, uint32_t num_bytes, FILE *wav_file)
{
	unsigned buf;
	while(num_bytes>0)
	{   buf = word & 0xff;
		fwrite(&buf, 1,1, wav_file);
		num_bytes--;
	word >>= 8;
	}
}
 
void write_wav(char * filename, uint32_t num_samples, int16_t * data, uint32_t s_rate)
{
	FILE* wav_file;
	uint32_t sample_rate;
	uint32_t num_channels;
	uint32_t bytes_per_sample;
	uint32_t byte_rate;
	 
	num_channels = 1;   // hard wire mono 
	bytes_per_sample = 2; //16 bits
 
	if (s_rate<=0) sample_rate = 8000;
	else sample_rate = (uint32_t) s_rate;
 
	byte_rate = sample_rate*num_channels*bytes_per_sample; 
	wav_file = fopen(filename, "w");
 
	// write RIFF header 
	fwrite("RIFF", 1, 4, wav_file);
	write_little_endian(36 + bytes_per_sample* num_samples*num_channels, 4, wav_file);
	fwrite("WAVE", 1, 4, wav_file);
 
 	// write fmt 
	fwrite("fmt ", 1, 4, wav_file);
	write_little_endian(16, 4, wav_file);   /* SubChunk1Size is 16 */
	write_little_endian(1, 2, wav_file);    /* PCM is format 1 */
	write_little_endian(num_channels, 2, wav_file);
	write_little_endian(sample_rate, 4, wav_file);
	write_little_endian(byte_rate, 4, wav_file);
	write_little_endian(num_channels*bytes_per_sample, 2, wav_file);  /* block align */
	write_little_endian(8*bytes_per_sample, 2, wav_file);  /* bits/sample */
 
	fwrite("data", 1, 4, wav_file);
	write_little_endian(bytes_per_sample* num_samples*num_channels, 4, wav_file);
	
	uint32_t n_samples; 
	if(num_channels ==1)  n_samples =num_samples/2;   //divide by 2 for mono 
	else n_samples =num_samples; //for future changes
	
	for (uint64_t i=0; i< n_samples; i++)
	
	{   write_little_endian((uint32_t)(data[i]),bytes_per_sample, wav_file);
	}
 
	fclose(wav_file);
}
 
int32_t get_merge_data_size(int num_files, char *filenames[])
{	
	int32_t merge_size =0;
	WaveData_t* data;	  
    for (int i = 0; i < num_files; i++) {    
    char* file_name =filenames[i];  
    data = read_wav(file_name,strlen(file_name));    
    merge_size =merge_size+data->size;    
    }    
	return merge_size;
} 


void merge_wav_files(char *merge_filename, int num_files, char *filenames[])
{	
	WaveData_t* data;	 //data pointer
	int32_t merge_size;	// merge size	
	merge_size = get_merge_data_size(num_files, filenames);		
	
	//create data array using malloc and merge_size	
	int16_t* data_store = NULL;
	// allocate enough memory for merge_size integers
	data_store = malloc(merge_size * sizeof(int16_t));
	// if the return from malloc is NULL, an error occurred
	// and so print an error message and exit (clean up)
	if(data_store == NULL) {
		fprintf(stderr,"Error allocating memory!\n");
		exit(1); //clean up
	}
  
	//Fill data_store with merge data
	int count=0;  //data_store count  
    for (int i = 0; i < num_files; i++) {  
    char* file_name =filenames[i];	   
    data = read_wav(file_name,strlen(file_name)); //get data samples for each file  
    //capture mono samples only i.e. data->size /2
	for (int k = 0; k < data->size/2; ++k) {     
    data_store[count] = data->samples[k];
    count =count+1; 
		if(count>merge_size)
		{
		printf("fatal error: malloc over run\n");
		break;
		}
    }	
	}		
	uint32_t s_rate=8000; //fix sample rate to talk calendar audio format
	//uint32_t s_rate=16000;		
	write_wav(merge_filename, merge_size, data_store, s_rate);
	free(data_store);
	return;	
}	


void merge_wav_files2(char *merge_filename, int num_files, char *filenames[],int32_t sample_rate)
{	
	WaveData_t* data;	 //data pointer
	int32_t merge_size;	// merge size	
	merge_size = get_merge_data_size(num_files, filenames);		
	
	//create data array using malloc and merge_size	
	int16_t* data_store = NULL;
	// allocate enough memory for merge_size integers
	data_store = malloc(merge_size * sizeof(int16_t));
	// if the return from malloc is NULL, an error occurred
	// and so print an error message and exit (clean up)
	if(data_store == NULL) {
		fprintf(stderr,"Error allocating memory!\n");
		exit(1); //clean up
	}
  
	//Fill data_store with merge data
	int count=0;  //data_store count  
    for (int i = 0; i < num_files; i++) {  
    char* file_name =filenames[i];	   
    data = read_wav(file_name,strlen(file_name)); //get data samples for each file  
    //capture mono samples only i.e. data->size /2
	for (int k = 0; k < data->size/2; ++k) {     
    data_store[count] = data->samples[k];
    count =count+1; 
		if(count>merge_size)
		{
		printf("fatal error: malloc over run\n");
		break;
		}
    }	
	}		
	//uint32_t s_rate=8000; //fix sample rate to talk calendar audio format
			
	write_wav(merge_filename, merge_size, data_store, sample_rate);
	free(data_store);
	return;	
}	

