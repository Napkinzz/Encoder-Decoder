#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char *argv[]) {

    int i;
    int mapping_file, mode, input;

    if (argc != 7) {
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>\n");
        exit(7);
    }

    // when a flag is found its respective "argument" will be at i+1. (when -m is found the mode(integer) is at i+1)
    for (i=0; i < argc; i++) {
        if ((strcmp(argv[i], "-t")) == 0) { // output of strcmp will be 0 if they match
            mapping_file = i+1;
        } else if ((strcmp(argv[i], "-m")) == 0) {
            mode = i+1;
        } else if ((strcmp(argv[i], "-i")) == 0) {
            input = i+1;
        }
    }

    // checks the "mode" to make sure that is it valid. 
    if (((strcmp(argv[mode], "1")) != 0) &&  ((strcmp(argv[mode], "2")) != 0)){
        fprintf(stderr, "You entered %s. Sorry, your mode must be 1 for encryption or 2 for decryption\n", argv[mode]);
        exit(6);
    }
    
    return 0;
}