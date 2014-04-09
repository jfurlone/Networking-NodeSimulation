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
		accessR = access("./link1", 0777);
		
		while(accessR != 0)
		{
			sleep(1);
			accessR = access("./link1", 0777);
		}
		
		openR = open("./link1", O_RDONLY);
		
		//printf("openNode2-Link1\n");
		
		readR = read(openR, word ,30);
		
		//printf("readNode2-Link1\n");
		
		if(word[3] == '2' || strcmp(word, "no") == 0)
		{
			printf("n2, message '%s' received\n", word);
		}
		close(openR);
		
		//printf("closeNode2-Link1\n");
		
		fifoR = -11;
		openR = -12;
		writeR = -13;
		accessR = -14;
		//printf("num: %c\n", word[3]);
		if(word[3] == '4' || strcmp(word, "no") == 0)
		{
			/*NODE 4 ACCESS*/
			/*accessR = access("./link3", 0777);*/
			
			fifoR = mkfifo("./link3", 0777);
			//printf("makeNode2-Link3\n");
			
			
			openR = open("./link3", O_WRONLY);
			//printf("openNode2-Link3\n");
			
			writeR = write(openR, word, 30);
			//printf("writeNode2-Link3\n");
			
			
			close(openR);
			
			//printf("closeNode2-Link3\n");
		
		
			//printf("\n\n");
			if(strcmp(word, "no") == 0)
			{
				exit(0);
			}
			
			/*NODE4 Return*/
			
			openR = -12;
			writeR = -13;
			accessR = -14;
			
			openR = open("./link3", O_RDONLY);
			
			//printf("openNode2-Link3\n");
				
			while(accessR != 0)
			{
				sleep(1);
				accessR = access("./link3", 0777);
			}
				
			readR = read(openR, word ,30);
			//printf("readNode2-Link3\n");
			
			close(openR);
			//printf("closeNode2-Link3\n");
		}
		
		/*NODE 2 Return to Node 1*/
		
		openR = -12;
		writeR = -13;
		accessR = -14;
		
		openR = open("./link1", O_WRONLY);
		writeR = write(openR, "Node 2 Done", 30);
		close(openR);
		
				
		//printf("closeNode4-Link3\n");
		
		
	}
	
	exit(0);
	
	return 0;
}