#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char word [30] = "Seven";
	char dest [4] = "n0";
	char packet [10] = ".........";
	
	
	int readR = -10;
	int fifoR = -11;
	int openR = -12;
	int writeR = -13;
	int accessR = -14;
	int sum = 0;
	
	char c;
	
	FILE * fileptr;
	
/*	int n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0;	
*/	
	
	printf("Hi, enter the filename: ");
	fgets(word, 30, stdin);
	word[strlen(word)-1] = '\0';
	
	printf("Enter the location: ");
	fgets(dest, 4, stdin);
	dest[strlen(dest)-1] = '\0';
	
	fileptr = fopen(word,"r");
	
	while(strcmp(word, "no") != 0)
	{
		if(strcmp(word,"yes") == 0)
		{
			printf("Enter the filename: ");
			fgets(word, 30, stdin);
			word[strlen(word)-1] = '\0';
			
			printf("Enter the location: ");
			fgets(dest, 4, stdin);
			dest[strlen(dest)-1] = '\0';
			
			fileptr = fopen(word,"r");
		}
		
		
		while((c = fgetc(fileptr)) != EOF)
		{
			//printf("C value: %c\n", c);
			packet [0] = c;
			packet [1] = ' ';
			packet [2] = dest[0];
			packet [3] = dest[1];
			packet [4] = dest[2];
			printf("n1's current packet is now: ~%s~\n", packet);
			/*accessR = access("./link1", 0777);*/
			
			if(strcmp(dest,"n2") == 0 || strcmp(dest,"n4") == 0)
			{
				fifoR = mkfifo("./link1", 0777);
				//printf("makeLink1\n");
						
				openR = open("./link1", O_WRONLY);
				//printf("openNode1-Link1\n");
						
				writeR = write(openR, packet, 30);
				//printf("writeNode1-Link1\n");
						
				close(openR);
				//printf("closeNode1-Link1\n");	
			}
			
			readR = -10;
			fifoR = -11;
			openR = -12;
			writeR = -13;
			accessR = -14;
	
			/*accessR = access("./link2", 0777);*/
			
			if(strcmp(dest,"n3") == 0 || strcmp(dest,"n5") == 0 || strcmp(dest,"n6") == 0 || strcmp(dest,"n7") == 0)
			{
				fifoR = mkfifo("./link2", 0777);
				//printf("makeNode1-Link2\n");
				
				
				openR = open("./link2", O_WRONLY);
				//printf("openNode1-Link2\n");
				
				writeR = write(openR, packet, 30);
				//printf("writeNode1-Link2\n");
				
				close(openR);
				//printf("closeNode1-Link2\n");
				
			}		
			
			
			//printf("\n\n");
			
			/*NODE 2 Return*/
			readR = -10;
			openR = -12;
			accessR = -14;
			
			if(strcmp(dest,"n2") == 0 || strcmp(dest,"n4") == 0)
			{
				while(accessR != 0)
				{
					sleep(1);
					accessR = access("./link1", 0777);
				}
				
				openR = open("./link1", O_RDONLY);
				//printf("openNode4-Link3\n");
				
				readR = read(openR, word, 30);
				//printf("writeNode4-Link3\n");
				
			/*	if(strcmp(word,"Node 2 Done") == 0)
				{
					sum = sum + 1;
				}*/
				
				close(openR);
					
			}
			
			/*NODE 3 Return*/
			readR = -10;
			openR = -12;
			accessR = -14;
			
			if(strcmp(dest,"n3") == 0 || strcmp(dest,"n5") == 0 || strcmp(dest,"n6") == 0 || strcmp(dest,"n7") == 0)
			{
				while(accessR != 0)
				{
					sleep(1);
					accessR = access("./link2", 0777);
				}
				
				openR = open("./link2", O_RDONLY);
				//printf("openNode4-Link3\n");
				
				readR = read(openR, word, 30);
				//printf("writeNode4-Link3\n");
				
		/*		if(strcmp(word,"Node 3 Done") == 0)
				{
					sum = sum + 1;
				}*/
				close(openR);	
			}
		}
		
		printf("NODE 1 is Done. Message sent and received.\nContinue: yes/no?");
		fgets(word, 30, stdin);
		word[strlen(word)-1] = '\0';
		fclose(fileptr);
		fileptr = NULL;
		sum = 0;		
	}
	printf("Final WORD: %s \n\n\n",word);
	
	fifoR = mkfifo("./link1", 0777);
	//printf("makeLink1\n");
			
	openR = open("./link1", O_WRONLY);
	//printf("openNode1-Link1\n");
			
	writeR = write(openR, word, 30);
	//printf("writeNode1-Link1\n");
			
	close(openR);
	//printf("closeNode1-Link1\n");	
	
	fifoR = mkfifo("./link2", 0777);
	//printf("makeNode1-Link2\n");
	
	openR = open("./link2", O_WRONLY);
	//printf("openNode1-Link2\n");
	
	writeR = write(openR, word, 30);
	//printf("writeNode1-Link2\n");
	
	close(openR);
	//printf("closeNode1-Link2\n");
	
	return 0;
}
