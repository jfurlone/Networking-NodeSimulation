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
		/*accessR = access("./Link5", 0777);*/
		
		while(accessR != 0)
		{
			sleep(1);
			accessR = access("./Link5", 0777);
		}
		
 		openR = open("./Link5", O_RDONLY);
 		
 		//printf("openNode6-Link5\n");
			
		readR = read(openR, word ,30);
		
		//printf("readNode6-Link5\n");
		
		printf("n6, message '%s' received\n", word);
				
		close(openR);
		
		//printf("closeNode6-Link5\n");
		/*
		printf("Would you like to quit3?\n1 to quit, 0 to continue: ");
		scanf("%d", &quit);
		*/
		//printf("\n\n");
		
		openR = -12;
		writeR = -13;
		accessR = -14;
		
		
		//printf("openNode6-Link5\n");
		
		if(strcmp(word, "no") == 0)
		{
			exit(0);
		}
		else
		{
			openR = open("./Link5", O_WRONLY);
			writeR = write(openR, "Node 6 Done", 30);
			close(openR);
		}
		
	}
	
	exit(0);
	
	
	
	return 0;
}