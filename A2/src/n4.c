#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char word [30];
	int quit = 0;
	int readR = -10;
	int openR = -12;
	int writeR = -13;
	int accessR = -14;
	while(quit != 1)
	{
		/*accessR = access("./link3", 0777);*/
		
		while(accessR != 0)
		{
			sleep(1);
			accessR = access("./link3", 0777);
		}
		
 		openR = open("./link3", O_RDONLY);
 		
 		//printf("openNode4-Link3\n");
			
		readR = read(openR, word ,30);
		
		//printf("readNode4-Link3\n");
		
		printf("n4, message '%s' received\n", word);				
		close(openR);
		
		//printf("closeNode4-Link3\n");
		/*
		printf("Would you like to quit3?\n1 to quit, 0 to continue: ");
		scanf("%d", &quit);
		*/
		//printf("\n\n");
		
		openR = -12;
		writeR = -13;
		accessR = -14;
		
		
		//printf("openNode4-Link3\n");
		//printf("WORD: %s\n", word);
		if(strcmp(word, "no") == 0)
		{
			exit(0);
		}
		else
		{
			openR = open("./link3", O_WRONLY);
			writeR = write(openR, "Node 4 Done", 30);
			close(openR);
		}
		
		//printf("closeNode4-Link3\n");
		
	}
	
	
	exit(0);
	
	
	return 0;
}