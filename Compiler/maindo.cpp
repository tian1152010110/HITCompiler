#include<stdio.h>
#include "scanner.h"
int main()
{
	FILE * file;
	file = fopen("abc.txt","r");
	if(file == NULL)
		printf("The file is note exist!");
	WORD * wPtr = wordScanner(file);
	//printf("%d---%s\n",wPtr->code,wPtr->word_meaning);
	while(1)
		getchar();
	return 0;
}