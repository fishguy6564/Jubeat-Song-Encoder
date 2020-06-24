#include "wav.h"

WaveFile sound;

void setWavFile(u8 * filename){
    FILE *infile;

    infile = fopen(filename, "rb");

    if (infile == NULL) return;

    fread(&sound, 0x2C, 1, infile);

    sound.data = (u8*)malloc(sound.dataFileSize);

    fread(sound.data, sound.dataFileSize, 1, infile);
    fclose(infile);
}

u32 getWavSize(){
    return sound.fileSize;
}

u32 getDataSize(){
    return sound.dataFileSize;
}

u16 getChannel(){
    return sound.channels;
}

u16 getSampleRate(){
    return sound.sampleRate;
}

u16 getBits(){
    return sound.bitsPerSample;
}

u16 getFormat(){
    return sound.formatType;
}

u8* getData(){
    return sound.data;
}
