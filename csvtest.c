#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp1 = fopen(argv[1], "r");

    int plaintext_check[26] = {0}; 
    int ciphertext_check[26] = {0};
    int i, j;

    char dict[26][2]; // where the mapping data is stored
    char comma = ',';
    char newLine = '\n';
    char defChar;
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                      'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
                      'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                      'y', 'z'}; //standard alphabet with lowercase we are checking

    //check if the file can be opened
    if(fp1 == NULL) {
        printf("%s can't be opened \n", argv[1]);
        exit(3); //changed exit code to 3
    }   

    //Read the csv file into the 2-d dictionary
    for(int rows = 0; rows < 26; rows++){
        defChar = fgetc(fp1);
        int cols = 0;
        while(defChar != newLine && cols < 2){
            if(defChar != comma){
                dict[rows][cols] = defChar;
                cols++;   
            }
            defChar = fgetc(fp1);
        }
    }

    for (i=0; i <= 25; i++) { // iterates through the saved "mapping file"
        for (j=0; j <= 25; j++){ // iterates through the alpha "check"
            if (dict[i][0] == alpha[j]) { // if the letter in dict[0] matchs a letter in the alphabet will set the flag to 1 (true)
                plaintext_check[j] = 1;   // in plaintext_check
            }
            if (dict[i][1] == alpha[j]) { // if the letter in dict[1] matchs a letter in the alphabet will set the flag to 1 (true)
                ciphertext_check[j] = 1;   // in ciphertext_check
            }
        }
    }

    for (i=0; i <= 25; i++) {
        if (plaintext_check[i] == 0) { //will exit with code 4 if there is not 26 letters or if one is a duplicate / not lowercase
            printf("The format of %s is incorrect @ pos %d \n", argv[1], i);
            exit(4);
        }else if (ciphertext_check[i] == 0) { //will exit with code 4 if there is not 26 letters or if one is a duplicate / not lowercase
            printf("The format of %s is incorrect @ pos %d \n", argv[1], i);
            exit(4);
        }
    }
    

    return 0;
}