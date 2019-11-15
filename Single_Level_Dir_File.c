// CPU-Scheduling-Algorithm-In-C 
// Single Level Directory File Organization

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct {
	char fileName[50][50];
	int fileCount;
}dir;

void main()
{
	char file[50];
	int choice, i;
	dir.fileCount = 0;

	do {
		printf("\n 1. CREATE FILE \n 2. DELETE FILE \n 3. SEARCH FILE \n 4. DISPLAY FILES \n 5. EXIT \n");
		printf("\n Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: printf("\n Enter the name of file : ");
					scanf("%s", file);

					for(i=0; i<dir.fileCount; i++)
					{
						if(strcmp(file, dir.fileName[i]) == 0)
						{
							printf("\n File %s NOT CREATED (file already EXIST)\n", file);
							break;
						}
					}
					if (i == dir.fileCount)
					{
						strcpy(dir.fileName[dir.fileCount], file);
						printf("\n File %s is CREATED\n", dir.fileName[dir.fileCount]);
						dir.fileCount++;
					}
					break;

			case 2: if(dir.fileCount == 0)
					{
						printf("\n Directory is EMPTY (no files to DELETE)\n");
						break;
					}
					printf("\n Enter the name of file : ");
					scanf("%s", file);
					for(i=0; i<dir.fileCount; i++)
					{
						if(strcmp(file, dir.fileName[i]) == 0)
						{
							printf("\n File %s is DELETED\n", file);
							strcpy(dir.fileName[i], dir.fileName[dir.fileCount-1]);
							dir.fileCount--;
							break;
						}
					}
					if (i == dir.fileCount)
					{
						printf("\n File %s NOT FOUND\n", file);
					}
					break;

			case 3: printf("\n Enter the name of file : ");
					scanf("%s", file);

					for(i=0; i<dir.fileCount; i++)
					{
						if(strcmp(file, dir.fileName[i]) == 0)
						{
							printf("\n File %s is FOUND :)\n", file);
							break;
						}	
					}
					if(i == dir.fileCount)
					{
						printf("\n File %s NOT FOUND :(\n", file);
					}
					break;

			case 4: if(dir.fileCount == 0)
					{
						printf("\n Directory is EMPTY");
					}
					for(i=0; i<dir.fileCount; i++)
					{
						printf("\n %d. %s", i+1, dir.fileName[i]);
					} 
					printf("\n");
					break;

			case 5: exit(0);
		}
		printf("\n---------------------------------------------------------------------\n");
	}while(1);
}
