#include "encoder.h"

int main(int argc, char **argv){
    if(argc == 3){
        encodeWav(argv[1], argv[2]);
        printf("Done!");
    }else{
        printf("Please provide input and output file names\n");
    }
    return 0;
}
