#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Peng Gu, Xuran Wang
 *10/23/2018
 *izzle.c
 *This program takes every word, truncates after the last consonant followed by a vowel, and adds "izzle" to its tail.
 */

int main(int argc, char **argv){
    if(argc>1){// if unknown flag or -h or -? passed to the program
	printf("How to use izzle.c:\n");
	printf("Type \"./izzle < inputFile > outputFile\" \n");
	printf("\n");
	printf("izzle.c uses an algorithm to alter every word in the inputFile,\n");
	printf("while making no change to non-alphabets\n");
	exit(1);
    }

    int pos=0;// the working index for the buffer arr
    char arr[104] = {[0 ... 103] = '\0'}; // the buffer string for a single word
    char arrN[104] = {[0 ... 103] = '\0'}; // another buffer to save parts of the word
    int input;
    int lastVowel=-1;
    while(EOF != (input = getchar())){
	if ((input>='a' && input<='z')||(input>='A'&&input<='Z')){// uncapitalized and capitalized char
	    arr[pos] = input;
	    pos++;
	}
    	else{// if input is not a letter, then we have to deal with the word in the buffer
	    if (arr[0]!='\0'){
		pos=0;
		while(arr[pos]!='\0'){
		    if(strchr("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ",arr[pos])&&strchr("aeiou",arr[pos+1])&&arr[pos+1]!='\0'){
			lastVowel=pos+1;
		    }
		    pos++;
		}
		if(lastVowel==-1){
		    printf("%s",arr);
		    continue;
		}
		strncpy(arrN,arr,lastVowel);
		strcat(arrN,"izzle");
		printf("%s",arrN);
		pos=0;
		while(arrN[pos]!='\0'){// set buffer arrN to empty
		    arrN[pos]='\0';
		    pos++;
		}
		pos=0;
		while(arr[pos]!='\0'){// set the buffer to empty
		    arr[pos]='\0';
		    pos++;
		}
		pos=0;
		lastVowel=-1;
	    }
	    putchar(input);// print the non-letter we read
	}
    }
    return 0;
}


