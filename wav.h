#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long u64;
typedef signed long s64;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;

typedef struct{
    u8 fileMagic[4]; //0x0
    u32 fileSize; //0x4
    u8 typeHeader[4]; //0x8
    u8 chunkMarker[4]; //0xC
    u32 formatDataLength; //0x10
    u16 formatType; //0x14
    u16 channels; //0x16
    u32 sampleRate; //0x18
    u32 sampleProduct; //0x1C
    u16 unknownProduct; //0x20
    u16 bitsPerSample; //0x22
    u8 dataChunkHeader[4]; //0x24
    u32 dataFileSize; //0x28
    u8* data;
}WaveFile;

void setWavFile(u8 * filename);
u8* getData();
void getDataFileSize();
u32 getWavSize();
u32 getDataSize();
u16 getChannel();
u16 getSampleRate();
u16 getBits();
u16 getFormat();
