#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc, char *argv[], char *envp[]){
	char *cmd = NULL;
	printf("\n\nArgc %d\n\n",argc);
	if(argc == 3) {
		printf("argv[0] - %s\n",argv[0]);
		printf("argv[1] - %s\n",argv[1]);
		printf("argv[2] - %s\n",argv[2]);
		cmd = (char *)malloc(sizeof(char)*strlen(argv[1])+sizeof(int)+1);
		sprintf(cmd,"%s %s", argv[1], argv[2]);
		printf("\n\ncmd - %s\n",cmd);
		system(cmd);
		free(cmd);
	}
}