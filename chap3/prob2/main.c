#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE]; // 입력 줄
int llen[5];
main(){
	int len;
	int max;
	max = 0;
	cnt=0;
	int temp;
	while(cnt<5) {
		gets(line); //문자열 입력
    		len = strlen(line); //문자열의 길이
		llen[cnt]=len;
		cnt++;
	}
	for(i=0;i<5;i++){
		for(j=o;j<5;j++){
			if(llen[i]>llen[j]){
				temp=line[i];
				line[i]=line[j];
				line[j]=temp;
			}
		}
	}
				
	/*if(max > 0) // 입력 줄이 있었다면
		printf("%s \n", longest);
	return 0;*/
	for(i=0;i<5;i++){
	printf("%c\n",line[i]);
	}
}
