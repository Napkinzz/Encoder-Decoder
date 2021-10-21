#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    FILE * fp1; // for mapping 
    FILE * fp2; // for words to be changed
    int i, j;

    char mapping[26][3] = {" "};
    char original[BUFFER_SIZE] = {" "};

    char temp;
    char temp2;
    char encrypted[BUFFER_SIZE] = {" "};


    //attempts to open the file's entered in the cmd line and assigns it to variables
    
    if (!(fp1 = fopen(argv[1], "r"))) {
        printf("File does not exist!\n");
        exit(2); //will exit if the file cannot be opened
    }
    if (!(fp2 = fopen(argv[2], "r"))) {
        printf("File does not exist!\n");
        exit(2); //will exit if the file cannot be opened
    }

    // puts the mapping data in a array
    for (i=0; i <= 25; i++) {
        for (j=0; j<=3; j++) {
            mapping[i][j] = fgetc(fp1); //mapping[location in alphabet][0: origional, 2:encrypted]
        }
    } fclose(fp1);

    // puts the input data in a char array 
    i = 0;
    do {
        original[i] = fgetc(fp2);
        i++;
    } while (original[i] != EOF);
    fclose(fp2);

    // checks i-th character in the string and finds its location in the mapping array
    // then grabs the swap character and saved it to encrypted[i].
    i = 0;
    do {
        temp = original[i];
        for (j=0; j <= 25; j++) {
            temp2 = mapping[j][0];
            if (temp == temp2) {
                encrypted[i] = mapping[j][2];
            }
        } i++;
    } while (original[i] != EOF);


    // testing things (DELETE AFTER)

    //printf("Origional %c, Encrypted, %c\n", original[1], encrypted[1]);
    printf("The encryped version of the word is: ");
    for (i=7; i >= 0; i--) {
        printf("%c", encrypted[i]);
    }
    printf("\n");

    /*
    printf("current character is : %c, encrypted character is %c\n", mapping[25][0], mapping[25][2]);
    printf("The current character from the input is %c\n", original[0]);
    printf("The current character from the input is %c\n", original[1]);
    printf("The current character from the input is %c\n", original[2]);
    printf("The current character from the input is %c\n", original[3]);
    printf("The current character from the input is %c\n", original[4]);
    printf("The current character from the input is %c\n", original[5]);
    printf("The current character from the input is %c\n", original[6]);
    printf("The current character from the input is %c\n", original[7]);
    printf("The current character from the input is %c\n", original[8]);
    printf("The current character from the input is %c\n", original[9]);
    printf("The current character from the input is %c\n", original[10]);
    printf("The current character from the input is %c\n", original[11]);
    printf("The current character from the input is %c\n", original[12]);
    printf("The current character from the input is %c\n", original[13]);
    printf("The current character from the input is %c\n", original[14]);
    */

    return 0;
}