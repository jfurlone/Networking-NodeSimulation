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
	int fifoR = -11;
	int openR = -12;
	int writeR = -13;
	int accessR = -14;
	
	
	while(quit != 1)
	{
		accessR = access("./link2", 0777);
		
		while(accessR != 0)
		{
			sleep(1);
			accessR = access("./link2", 0777);
		}
		
 		openR = open("./link2", O_RDONLY);
 		/*printf("openNode3-Link2\n");*/
			
		readR = read(openR, word ,30);
		/*printf("readNode3-Link2\n");*/
		
		if(word[3] == '3' || strcmp(word, "no") == 0)
		{
			printf("n3, message '%s' received\n", word);
		}		
		close(openR);
		/*printf("closeNode3-Link2\n");*/
		
		/*
		printf("Would you like to quit3?\n1 to quit, 0 to continue: ");
		scanf("%d", &quit);
		*/
		//printf("\n\n");
		
		if(word[3] == '5' || strcmp(word, "no") == 0)
		{
			/*NODE 5 ACCESS*/
		
			fifoR = -11;
			openR = -12;
			writeR = -13;
			accessR = -14;
			
			fifoR = mkfifo("./link4", 0777);
			/*printf("makeNode3-Link4\n");*/
			
			openR = open("./link4", O_WRONLY);
			/*printf("openNode3-Link4\n");*/
			
			
			writeR = write(openR, word, 30);
			/*printf("writeNode3-Link4\n");*/
					
			close(openR);
			
			/*printf("closeNode3-Link4\n");*/
			
			if(strcmp(word, "no") != 0)
			{
				/*NODE 5 Return*/
				openR = -12;
				writeR = -13;
				accessR = -14;
				
				openR = open("./link4", O_RDONLY);
				
				//printf("openNode3-Link4\n");
					
				while(accessR != 0)
				{
					sleep(1);
					accessR = access("./link4", 0777);
				}
					
				readR = read(openR, word ,30);
				
				//printf("readNode3-Link4\n");
						
				close(openR);
				//printf("closeNode3-Link4\n");
			}
			
			
		}
		
		if(word[3] == '6' || strcmp(word, "no") == 0)
		{
			/*NODE 6 ACCESS*/
		
			fifoR = -11;
			openR = -12;
			writeR = -13;
			accessR = -14;
			
			fifoR = mkfifo("./link5", 0777);
			/*printf("makeNode3-Link5\n");*/
			
			openR = open("./link5", O_WRONLY);
			/*printf("openNode3-Link5\n");*/
			
			
			writeR = write(openR, word, 30);
			/*printf("writeNode3-Link5\n");*/
					
			close(openR);
			
			/*printf("closeNode3-Link5\n");*/
			
			if(strcmp(word, "no") != 0)
			{
				/*NODE 6 Return*/
		
				openR = -12;
				writeR = -13;
				accessR = -14;
				
				openR = open("./link5", O_RDONLY);
				
				//printf("openNode3-Link5\n");
					
				while(accessR != 0)
				{
					sleep(1);
					accessR = access("./link5", 0777);
				}
					
				readR = read(openR, word ,30);
				
				//printf("readNode3-Link5\n");
				
						
				close(openR);
				//printf("closeNode3-Link5\n");	
			}
		}
		
		if(word[3] == '7' || strcmp(word, "no") == 0)
		{
			/*NODE 7 ACCESS*/
		
			fifoR = -11;
			openR = -12;
			writeR = -13;
			accessR = -14;
			
			fifoR = mkfifo("./link6", 0777);
			//printf("makeNode3-Link6\n");
			
			openR = open("./link6", O_WRONLY);
			//printf("openNode3-Link6\n");
			
			
			writeR = write(openR, word, 30);
			//printf("writeNode3-Link6\n");
					
			close(openR);
			
			//printf("closeNode3-Link6\n");
			if(strcmp(word, "no") != 0)
			{
				/*NODE 7 Return*/
			
				openR = -12;
				writeR = -13;
				accessR = -14;
				
				openR = open("./link6", O_RDONLY);
				
				//printf("openNode3-Link6\n");
					
				while(accessR != 0)
				{
					sleep(1);
					accessR = access("./link6", 0777);
				}
					
				readR = read(openR, word ,30);
				
				//printf("readNode3-Link6\n");
				
	/*			if(strcmp(word,"Node 7 Done") == 0)
				{
					sum = sum + 1;
				}
	*/							
				close(openR);
				//printf("closeNode3-Link6\n");
				
			}
		}
		
				
		
		/*NODE 3 Return to NODE 1*/
		
		openR = -12;
		writeR = -13;
		accessR = -14;
		
		if(strcmp(word, "no") == 0)
		{
			exit(0);
		}
		else
		{
			openR = open("./link2", O_WRONLY);
			writeR = write(openR, "Node 3 Done", 30);		
			close(openR);
		}
		
		
	}
	
	exit(0);
	
	
	
	return 0;
}