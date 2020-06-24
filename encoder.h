#include "wav.h"

typedef struct{
    char fileMagic[4]; //0x00
    u32 dataSize; //0x04
    u32 loopStart; //0x08
    u32 loopEnd; //0x0C
    u16 channels; //0x10
    u16 bits; //0x12
    u32 rate; //0x14
    u8 pad[8]; //0x18
    u8* data; //0x20
}BMPFile;

void encodeWav(char* infilename, char* outfilename);
