# ASSIGNMENT 1 TEAM 104
### The Information Of Both Assignment Partners:

ASSIGNMENT 1                                                           
  Author: Lukas Waschuk / Kingsly Okeke
  OneCard: 1660570 / 1631514           
  CCID: lwaschuk / nkokeke  
  Instructor: Ildar Akhmetov               
  Lecture Section: B1 / B1\
  Lab Section: H04 / H02\
  02/13/2021                             

###### The Purpose Of Your Program:
The Authors of this program created a simulation of string cipher which encrypts and decrypts a group of characters based on a particular mapping scheme. Through the result of this encryption/decryption, we output the reverse version of this result. This simulation program is very important in cases that a user wants to send a secret text or message to another person. Only the sender and receiver are able to decode this string of characters. 

###### The Exact Commands We Need To Run Your Code:
This program was written in a Linux environment using the GNU compiler collection(GCC). To run this program easily, we have a makefile which has the command(gcc -Wall -std=c99 -o encrypt encrypt.c) to compile the program into an executable(encrypt). Simply run make demo in your linux terminal and then run the command ./encrypt along with -t(flags for the mapping file) <mappingfile> -m(mode of encryption/decryption) <encryption mode> -i(flag for the input file) <inputfile>.

###### The Files Submitted In Your Assignment, How They Are Structured, And What They Do:
We have some files uploaded into our repository. The most important being the cipher program is called encrypt.c and it contains several functions which highlights the main functionality of the cipher. It also obeys the rule of modularity by separating each single task into different functions. Next, the readme file which answers basic questions about the program such as: the information of both assignment partners, the purpose of our program etc. The final file is the makefile which contains the basic target needed to run the program in a Linux shell. 

###### References (e.g., any online resources you used in accordance to the course policy):
Most of the author's references come from CMPUT 201 lecture slides and the textbook, C PROGRAMMING, A Modern Approach by K N KING. 

###### Each Partner's Role In The Assignment (i.e., which parts of the code did they work on):
The authors of this program divided the tasks involved into two equal parts. Kingsley handled the encryption/decryption program and the reverse words program. Kingsley also handled the ReadMe file needed for this program. Lukas, on the otherhand, handled all the error-checkings including making sure the user selects the right mode of operation(decryption/encryption) and made sure the right output was executed for each corresponding input. Lukas finally, handled the makefile and ensured it had a clean target. 