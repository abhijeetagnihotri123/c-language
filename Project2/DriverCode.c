#include <stdio.h>
#include <math.h>
#include <string.h>

#define SAMPLES_PER_SECONDS 441000
#define DURATION 5
#define AMPLITUDE 32767
#define FREQUENCY 1320
#define FILE_NAME "sine_wave.raw"

#include "PMC.h"

struct PCMHeader initialize_PMC_Header();

void write_to_file()
{
    int total_samples = DURATION * SAMPLES_PER_SECONDS;
    int i = 0;

    float time;

    float angular_frequency = 2 * 3.14 * FREQUENCY; 
    float angle;

    int16_t sample;

    FILE *f;
    f = fopen(FILE_NAME , "wb");

    if(f == NULL){
        printf("Cannot open the file\n");
        return;
    }

    struct PCMHeader header = initialize_PMC_Header();

    fwrite(&header , sizeof(header) , 1 , f);

    while(i < total_samples){   
        time = i * (1.0/SAMPLES_PER_SECONDS);
        angle = angular_frequency * time;
        sample = (int16_t)(AMPLITUDE * sin(angle));
        // printf("%d\n" , sample);
        fwrite(&sample , sizeof(int16_t) , 1 , f);
        i = i + 1;
    }

    fclose(f);
    printf("Audio file written successfully\n");

}

struct PCMHeader initialize_PMC_Header()
{
    struct PCMHeader header;

    memcpy(header.chunkID, "RIFF", 4);
    memcpy(header.format, "WAVE", 4);
    memcpy(header.subChunk1ID, "fmt ", 4);

    header.subChunk1Size = 16; // PCM format size
    header.audioFormat = 1;    // PCM = 1
    header.numChannels = 1;    // Mono audio
    header.sampleRate = SAMPLES_PER_SECONDS;
    header.bitsPerSample = 16;
    header.byteRate = header.sampleRate * header.numChannels * header.bitsPerSample / 8;
    header.blockAlign = header.numChannels * header.bitsPerSample / 8;
    memcpy(header.subChunk2ID, "data", 4);
    header.subChunk2Size = DURATION * SAMPLES_PER_SECONDS * header.numChannels * header.bitsPerSample / 8;
    header.chunkSize = 36 + header.subChunk2Size;

    return header;
}

int main(){
    write_to_file();
    return 0;
}