#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Peng Gu, Xuran Wang
 *10/23/2018
 */

int main(int argc, char **argv){
    if(argc>1){// if unknown flag or -h or -? passed to the program
	printf("How to use pig.c:\n");
	printf("Type \"./pig < inputFile > outputFile\" \n");
	printf("\n");
	printf("pig.c uses an algorithm to alter every word in the inputFile,\n");
	printf("while making no change to non-alphabets\n");
	exit(1);
    }

    int pos=0;// the working index for the buffer arr
    int uCase=0;// 0 is not capitalized while 1 is capitalized
    char arr[104] = {[0 ... 103] = '\0'}; // the buffer string for a single word
    char arrN[104] = {[0 ... 103] = '\0'}; // another buffer to save parts of the word
    int input;
    while(EOF != (input = getchar())){
	if (input>='a' && input<='z'){// uncapitalized char
	    arr[pos] = input;
	    pos++;
	}
	else if(input >= 'A' && input<='Z'){// capitalized char
	    arr[pos] = input-'A'+'a';
	    pos++;
	    uCase = 1;
	}
	else{// if input is not a letter, then we have to deal with the word in the buffer
	    if (arr[0]!='\0'){
		if(strchr("aeiou", arr[0])){// if begin with a vowel
		    if(uCase==1){
			arr[0] = arr[0] +'A' -'a';
			uCase=0;
		    }
		    printf("%syay",arr);
		}
		else{// if not begin with a vowel
		    pos=1;
		    int vowel=1;// check if there is any vowel
		    while((!strchr("aeiouy", arr[pos]))||(arr[pos-1]=='q'&&arr[pos]=='u')){
			if(arr[pos+1]=='\0'){
			    // if there is no vowel in the word
			    vowel=0;
			}
			pos++;// skip to the 1st vowel
		    }
		    if(vowel==1){
		    strcpy(arrN, arr+pos);
	    	    strncat(arrN, arr, pos);
		    if(uCase==1){
			arrN[0]=arrN[0]-'a'+'A';
			uCase=0;
		    }
    		    printf("%say", arrN);
		    }
		    else{// if there is no vowel in the word, just print arr
			if(uCase==1){
			    arr[0]=arr[0]-'a'+'A';
			}
			printf("%s", arr);
		    }
		    pos=0;
		    while(arrN[pos]!='\0'){// set buffer arrN to empty
			arrN[pos]='\0';
			pos++;
		    }
		}
		pos=0;
		while(arr[pos]!='\0'){// set the buffer to empty
		    arr[pos]='\0';
		    pos++;
		}
		pos=0;
	    }
	    putchar(input);// print the non-letter we read
	}
    }
    return 0;
}


