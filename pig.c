#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Peng Gu
 *10/22/2018
 */

void pig();

int main(){
    int input;
    while(EOF != (input = getchar())){
	pig();
    }
    return 0;
}

void pig(){
    int pos=0;
    int input;
    int uCase=0;
    int posN=0;
    while(EOF != (input = getchar())){
	char arr[101];
	char arrN[101];
	uCase=0;
	pos=0;
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
	    ungetc(input, stdin);
	    if (arr[0]!='\0'){
		if(strchr("aeiou", (char)arr[0])){
		    if(uCase==1){
			arr[0] = arr[0] +'A' -'a';
		    }
		    printf("%syay\n",arr);
		}
		else{
		    arrN[0]=arr[0];
		    arr[0]='\0';
		    posN=1;
		    pos=1;
		    while((!strchr("aeiouy", (char)arr[pos]))||(arr[pos-1]=='q'&&arr[pos]=='u')){
			arrN[posN]=arr[pos];
			pos++;
		    }
		    if(uCase==1){
			arr[pos]=arr[pos]-'a'+'A';
		    }
		    printf("%s%say\n", arr, arrN);
		}
	    }
	    putchar(stdin);
	}
    }
}


