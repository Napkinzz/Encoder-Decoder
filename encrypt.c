/*CMPUT 201 Student Submission License Version 2.0

Copyright 2021 Lukas Waschuk, Kingsly Okeke

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the 
author and the CMPUT 201 Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology 
at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. 
The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the 
duration of the course.

Copying any part of this solution without including this copyright notice is illegal.

If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will 
be subject to the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this 
software is found in any public website or public repository, the person finding it is kindly requested to immediately report, 
including the URL or other repository locating information, to the following email addresses:

//nadi@ualberta.ca
//ildar@ualberta.ca
*/
/*********************************            *********************************
  ASSIGNMENT 1                                 ASSIGNMENT 1
  Name: encrpyt.c                              Name: encrpyt.c
  Author: Lukas Waschuk                        Author: Kingsly Okeke
  OneCard: 1660570                             OneCard: 1631514             
  CCID: lwaschuk                               CCID: nkokeke
  Instructor: Ildar Akhmetov                   Instructor: Ildar Akhmetov 
  Lecture Section: B1                          Lecture Section: B1
  Lab Section: H04                             Lab Section: H02
  01/31/2021                                   01/31/2021
**********************************             ********************************/          
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int M = 26; //constants used for 2d array length 26x2.
const int N = 2;

const char* reverse(char* str) {
/*  Purpose: To reverse a string / array of characters.

    Para: char: str: the string that will be reversed 

    Returns: char: the string that was reversed.
*/
    int len = strlen(str);

    int start = 0;
    int end = len - 1;
    char temp;
    while(start <= end){
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start+=1;
            end-=1;
    }
    return str;
}

const char* decrypt(char* str, char dict[M][N]){  
/*  Purpose: When the user entered 2 for the mode this function will be called. This takes the character to the right of the 
             comma and changes it to the character to the left of the comma in the csv dictionary.

    Para: char: str, the line of the input file to be changed (decrypted)
                dict: the 2d dictionary containing all the information to decrypt the string.

    Returns: char: str, the decrypted line from the input file
*/
        for(int i = 0; i < strlen(str); i++){ 
            for(int j = 0; j < 26; j++){
                if(str[i] == dict[j][1]){
                    str[i] = dict[j][0];
                    break;
                }
        }
    }
    return reverse(str);
}

const char* encrypt(char* str, char dict[M][N]){
/*  Purpose: When the user entered 1 for the mode this function will be called. This takes the character to the left of the 
             comma and changes it to the character to the right of the comma in the csv dictionary.

    Para: char: str, the line of the input file to be changed (encrypted)
                dict: the 2d dictionary containing all the information to encrypt the string.

    Returns: char: str, the encrypted line from the input file
*/
    for(int i = 0; i < strlen(str); i++){
        for(int j = 0; j < 26; j++){
            if(str[i] == dict[j][0]){
                str[i] = dict[j][1];
                break;
            }
        }
    }
    return reverse(str);
}

void arg_len_check(int argc){
/*  Purpose: To check if the command line inputs are equal to 7, i.e 7 arguments 

    Para: Integer: argc

    Returns: None, it will exit using error code 7 if there are not 7 arguments.
*/
    if (argc != 7) {
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>\n");
        exit(7);
    } return;
}

void mapping_file_valid(FILE *filename, char *argv[], int location){
/*  Purpose: To check if a file (.csv or .txt) exists and can be opened

    Para: FILE: the filename to be opened (checking if it equals NULL)
          char: argv[], from command line 
          int: location, where in argv[] the file is located (i.e argv[location])
    
    Returns: None, will exit on code 3 if the file cannot be opened
*/ 
    if(filename == NULL) {
        fprintf(stderr, "Error: Mapping file %s does not exist\n", argv[location]);
        exit(3); //changed exit code to 3
    } return;
}

void input_file_valid(FILE *filename, char *argv[], int location){
/*  Purpose: To check if a file (.csv or .txt) exists and can be opened

    Para: FILE: the filename to be opened (checking if it equals NULL)
          char: argv[], from command line 
          int: location, where in argv[] the file is located (i.e argv[location])
    
    Returns: None, will exit on code 3 if the file cannot be opened
*/ 
    if(filename == NULL) {
        fprintf(stderr, "Error: Input word file %s does not exist \n", argv[location]);
        exit(3); //changed exit code to 3
    } return;
}

void mapping_error_check(char dict[M][N], char *argv[], int mapping_file) {
/*  Purpose: To parse through the mapping file and check if all 26 lower case english letters are present in the plaintext and ciphertext sides 
             of the .csv file. Will throw exit(4) if the format of the mapping file is incorrect according to the assignment specs.

    Para: int:  mapping_file: the location of the mapping file from the command line used in argv[mapping_file]

          char: dict[26][2]: where we store the plaintext and ciphertest information for the csv
                argv[]: commmand line arguments

    Returns: None, will throw a exit code if the mapping_file format is incorrect according to the assignment specs.
*/
    int plaintext_check[26] = {0}; 
    int ciphertext_check[26] = {0};
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                      'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
                      'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                      'y', 'z'}; //standard alphabet with lowercase we are checking

    for (int i=0; i <= 25; i++) { // iterates through the saved "mapping file"
        for (int j=0; j <= 25; j++){ // iterates through the alpha "check"
            if (dict[i][0] == alpha[j]) { // if the letter in dict[0] matchs a letter in the alphabet will set the flag to 1 (true)
                plaintext_check[j] = 1;   // in plaintext_check
            }
            if (dict[i][1] == alpha[j]) { // if the letter in dict[1] matchs a letter in the alphabet will set the flag to 1 (true)
                ciphertext_check[j] = 1;   // in ciphertext_check
            }
        }
    }
    for (int i=0; i <= 25; i++) {
        if (plaintext_check[i] == 0) { //will exit with code 4 if there is not 26 letters or if one is a duplicate / not lowercase
            fprintf(stdout, "The format of %s is incorrect\n", argv[mapping_file]);
            exit(4);
        }else if (ciphertext_check[i] == 0) { //will exit with code 4 if there is not 26 letters or if one is a duplicate / not lowercase
            fprintf(stdout, "The format of %s is incorrect\n", argv[mapping_file]);
            exit(4);
        }
    }
    return;
}

void mode_check(int arg_check, char *argv[], int mode) {
/*  Purpose: To validate that the three flags entered from the cmd line match the expected flags. Will also make sure the mode 
             is either 1 or 2.

    Para: int:  arg_check: the counter that is used to ensure the 3 required flags were entered (-t, -i, -m)
                mode: the mode the user entered from the command line (must be 1 or 2)

          char: argv[]: commmand line arguments

    Returns: None, will throw a exit code 6 or 7 if an error is found according to the assignment specs.
*/
    if (arg_check != 3) { //every time we find a valid argument 1 is added to arg_check, we need exactly 3.
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>\n");
        exit(7);
    }
    // checks the "mode" to make sure that is it valid. if the mode isnt 1 or 2, it is invalid.
    if (((strcmp(argv[mode], "1")) != 0) && ((strcmp(argv[mode], "2")) != 0)){
        fprintf(stderr, "You entered %s. Sorry, your mode must be 1 for encryption or 2 for decryption\n", argv[mode]);
        exit(6);
    } 
    return;
}

void populate_csv(FILE *fp1, char *argv[], int mapping_file, char dict[M][N]) {
/*  Purpose: After checking that a mapping file exists and can be opened this function will open the mapping file csv and extract
             it into a 2d array for use later in the encrypt / decrypt functions. Will check that there are exactly 26 lines and 
             that there is exactly 3 characters per line, in the form <plaintext><comma><cipertext>

    Para: int:  mapping_file: the number in argv[] that the mapping file is located.
                
          char: argv[]: commmand line arguments
                dict[][]: the 2d array used to store all the .csv information

          FILE: fp1: the file pointer for the .csv file

    Returns: None, will throw a exit code 4 if an error is found according to the assignment specs. Arrays are modified within the function
             no need to return anything.
*/
    char defChar;
    char comma = ',';
    char newLine = '\n';

    for(int rows = 0; rows <= 26; rows++){
        defChar = fgetc(fp1);
        int cols = 0;
        int count = 0; 
        // if the row == 26 (27th line of the .csv) is not EOF then there is more then the 26 expected characters in the .csv
        if ((rows == 26) && defChar != EOF){ 
            fprintf(stdout, "The format of %s is incorrect\n", argv[mapping_file]);
            exit(4);
        }
        while(defChar != newLine && cols < 2){
            if(defChar != comma){
                dict[rows][cols] = defChar;
                cols++;   
                count ++;
            } else if (defChar == comma) {
                count++;
            } 
            defChar = fgetc(fp1); //advances the "pointer" (defChar)
        }

        //  if exactly 3 characters were not accounted for per iteration of while, return a error as the csv will not be in the 
        //  right format  <letter><comma><cipher>, line 26 is not checked as it is checked on above before the while statement.
        if ((count != 3) && (rows != 26)) { 
            fprintf(stdout, "The format of %s is incorrect\n", argv[mapping_file]);
            exit(4);
        }
    }
    return;
}

void print_converted_input(FILE *stream, char *argv[], char dict[M][N], int mode) {
/*  Purpose: To call upon the encrypt / decrypt functions to convert a input file into its final form and print the new text to
             stdout. Will check the mode (either 1 or 2) and call the corresponding function.

    Para: FILE: stream: the file pointer to the input.txt file
          
          char: argv[]: commmand line arguments
                dict[][]: the 2d array used to store the csv information extracted earlier

          int: mode: the mode the user entered from the command line (1-encrypt, 2- decrypt)

    Returns: None, everything done in this function will call other functions and print characters to stdout.
*/
    char line[21]; // max word length is 20 characters, added one extra to be safe
    while ((fscanf(stream, "%[^\n]", line))!= EOF){
        fgetc(stream); // Reads in '\n' character and moves file
                       // stream past delimiting character
        
        if ((strcmp(argv[mode], "1")) == 0) {  //checks if the mode if equal to 1
            encrypt(line, dict);
            fprintf(stdout, "%s\n", line); // changed to fprintf(stdout)
        } else if ((strcmp(argv[mode], "2")) == 0) { //checks if the mode is equal to 2
            decrypt(line, dict);
            fprintf(stdout, "%s\n", line); // changed to fprintf(stdout)
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    char dict[26][2] = {""}; // where the mapping data is stored
    int mapping_file, mode, input_file;

    // error checking, checking if there is the correct amount of arguments from the cmd line.
    arg_len_check(argc);

    // addressing "flag" arguments to integer variables, will be called on later... ex. the .csv will be argv[mapping_file].
    // when a flag is found its respective "argument" will be at argv[i+1]. (when -m is found the mode is at argv[i+1])
    // could not make a function for this as C cannot return multiple values from a single function, we need to assign
    // mapping_file, mode, and input_file here. 

    int arg_check = 0; // counter used to make sure we have the exact 3 flags input.
    for (int i=0; i < argc; i++) {
        if ((strcmp(argv[i], "-t")) == 0) { // output of strcmp will be 0 if they match
            mapping_file = i+1;
            arg_check++;
        } else if ((strcmp(argv[i], "-m")) == 0) {
            mode = i+1;
            arg_check++;
        } else if ((strcmp(argv[i], "-i")) == 0) {
            input_file = i+1;
            arg_check++;
        }
    }

    mode_check(arg_check, argv, mode); // checks the mode is 1 or 2 and makes sure only the accepted flags are input (-t, -i, -m)

    FILE *fp1 = fopen(argv[mapping_file], "r"); 
    mapping_file_valid(fp1, argv, mapping_file); //check if the mapping file can be opened (i.e exists)
    populate_csv(fp1, argv, mapping_file, dict);
    fclose(fp1);
    mapping_error_check(dict, argv, mapping_file); // checks validity of the mapping file

    //Read the txt file and call convert it to its respective mode (that the user entered)
    FILE *stream = fopen(argv[input_file], "r");
    input_file_valid(stream, argv, input_file); // checks if the input file exists and can be opened
    print_converted_input(stream, argv, dict, mode); //prints the encrypted / decrypted input file to stdout, depending on mode entered.
    fclose(stream);

    return 0;
}