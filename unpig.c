#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Peng Gu, Xuran Wang
 *10/23/2018
 */

int main(int argc, char **argv){
    if(argc>1){
	printf("How to use unpig.c:\n");
	printf("Type \"./unpig < inputFile > outputFile\" \n");
	printf("\n");
	printf("unpig.c uses an algorithm opposite to pig.c to alter every word in the inputFile,\n");
	printf("while making no change to non-alphabets\n");
	exit(1);
    }
    int pos=0;
    int input;
    int uCase=0;
    char arr[104]={[0 ... 103]='\0'};
    char arrN[104]={[0 ... 103] = '\0'};
    while(EOF != (input = getchar())){
	if (input>='a' && input<='z'){
	    arr[pos] = input;
	    pos++;
	}
	else if(input >= 'A' && input<='Z'){
	    arr[pos] = input-'A'+'a';
	    pos++;
	    uCase = 1;
	}
	else{
	    if (arr[0]!='\0'){
		int length;
		for(length=0; arr[length] != '\0'; length++);
		if(arr[length-3]=='y'&&arr[0]!='y'){
		    if(uCase==1){
			arr[0] = arr[0] +'A' -'a';
			uCase=0;
		    }
		    strncpy(arrN, arr, length-3);
		    printf("%s", arrN);
		}
		else if(arr[length-3]=='y'&&arr[0]=='y'){
		    arrN[0]='y';
		    strncat(arrN, arr, length-3);
		    if(uCase==1){
			arrN[0]=arrN[0]+'A'-'a';
			uCase=0;
		    }
		    printf("%s", arrN);
		}else{
		    if(arr[length-3]!='u'){
		        arrN[0]=arr[length-3];
			strncat(arrN, arr, length-3);
		    }
		    else{
			arrN[0]='q';
			arrN[1]='u';
			strncat(arrN, arr, length-4);
		    }
		    if(uCase==1){
			arrN[0] = arrN[0] - 'a' + 'A';
			uCase=0;
		    }
		    printf("%s", arrN);
		}
		pos=0;
		while(arrN[pos]!='\0'){
		    arrN[pos]='\0';
		    pos++;
		}
		pos=0;
		while(arr[pos]!='\0'){
		    arr[pos]='\0';
		    pos++;
		}
		pos=0;
	    }
	    putchar(input);
	}
    }
    return 0;
}


