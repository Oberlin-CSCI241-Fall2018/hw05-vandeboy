#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Peng Gu, Xuran Wang
 *10/23/2018
 */

int main(){
    int pos=0;
    int input;
    int uCase=0;
    char arr[104];
    char arrN[104];
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
		if(strchr("aeiou", arr[0])){
		    if(uCase==1){
			arr[0] = arr[0] +'A' -'a';
			uCase=0;
		    }
		    printf("%syay",arr);
		}
		else{
		    pos=1;
		    while((!strchr("aeiouy", arr[pos]))||(arr[pos-1]=='q'&&arr[pos]=='u')){
			pos++;
		    }
		    strcpy(arrN, arr+pos);
	    	    strncat(arrN, arr, pos);
		    if(uCase==1){
			arrN[0]=arrN[0]-'a'+'A';
			uCase=0;
		    }
    		    printf("%say", arrN);
		    pos=0;
		    while(arrN[pos]!='\0'){
			arrN[pos]='\0';
			pos++;
		    }
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


