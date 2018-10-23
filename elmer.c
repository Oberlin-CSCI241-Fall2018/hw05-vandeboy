#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Peng Gu, Xuran Wang
 *10/23/2018
 *elmer.c
 *This program reads a text file and alters letters following three rules:
 1. 'r' and 'l' are changed to 'w'
 2. 'th' are changed to 'd'
 3. "Uh-hah-ha-ha" is added to the end of output
 Their is no unelmer.c program because the elmer.c algorithm will cause a lot of confusions for unelmer.c.
 */

int main(int argc, char **argv){
    if(argc>1){
	printf("How to use elmer.c:\n");
	printf("Type \"./elmer < inputFile > outputFile\" \n");
	printf("\n");
	printf("elmer.c alters certain letters in the inputFile like Elmer Fudd would do,\n");
	exit(1);
    }
    int input;
    int t=0;
    int uCase=0;
    while(EOF != (input = getchar())){
	if (input>='A'&&input<='Z'){
	    uCase=1;
	    input=input-'A'+'a';
	}
	if (input=='h'){
	    if(t==1){
		input='d';
		t=0;
	    }
    	}
	else{
	    if(t==1){
		if(uCase==1){
		    printf("T");
		    uCase=0;
		}else{
		    printf("t");
		}
		t=0;
	    }
	    if(input=='t'){
	        t=1;
		continue;
	    }
	    else if(input=='l'||input=='r'){
		input='w';
	    }
    	}
	if(uCase==1){
	    input=input-'a'+'A';
	    uCase=0;
	}
	putchar(input);
    }
    printf("Uh-hah-ha-ha\n");
    return 0;
}


