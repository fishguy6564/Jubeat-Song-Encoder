#include "encoder.h"

#define SWAP32(x) (((x) & 0xff) << 24 | ((x) & 0xff00) << 8 | ((x) & 0xff0000) >> 8 | ((x) >> 24) & 0xff)

u32 getFileSize(FILE* file){
    u32 size;
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    rewind(file);
    return size;
}

void encodeWav(char* infilename, char* outfilename){
    setWavFile(infilename);

    BMPFile output;

    char command[128];
    u32 fileSize;
    u32 size = getDataSize();
    u8* data = getData();
    output.channels = getChannel();
    output.rate = SWAP32(getSampleRate());
    output.bits = getBits();
    strcpy(output.fileMagic, "BMP");

    //Write wav data to file
    FILE *tmp;
    tmp = fopen("tmpin.bin", "wb");
    fwrite(data, size, 1, tmp);
    fclose(tmp);

    //Format command and convert wav to adpcmwav
    snprintf(command, sizeof(command), "adpcmwavetool e tmpin.bin tmpout.bin %d", output.channels);
    system(command);

    //Grabbing data and file size of generated encoded sound file
    tmp = fopen("tmpout.bin", "rb");
    fileSize = getFileSize(tmp);
    output.data = (u8*)malloc(fileSize);
    fread(output.data, fileSize, 1, tmp);
    fclose(tmp);

    //Filling up remaining information
    output.dataSize = SWAP32(fileSize);
    output.loopStart = 0;
    output.loopEnd = 0;
    memset(output.pad, 0, 8);

    //Remove temporary files
    remove("tmpin.bin");
    remove("tmpout.bin");

    //Output reformatted file
    tmp = fopen(outfilename, "wb");
    fwrite(&output, 0x20, 1, tmp);
    fwrite(output.data, fileSize, 1, tmp);
    fclose(tmp);
}
