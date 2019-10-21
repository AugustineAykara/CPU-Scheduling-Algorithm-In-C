// CPU-Scheduling-Algorithm-In-C
// Simulation of Disk Scheduling Algorithm -> FCFS, SSTF, SCAN

#include<stdio.h>
#include <stdlib.h>
int seektime = 0;

void fcfs(int sequence[], int head, int n)
{				
	int temp = head;
	seektime = 0;
	printf("\n The Disk sequence is : \n");
	for(int i=0; i<n; i++)
	{
		printf(" > %d", sequence[i]);
		seektime += abs(sequence[i]-temp);
		temp = sequence[i];
	}

	printf("\n\n Seek Time = %d", seektime);
}


void sstf(int sequence[], int head, int n)
{
	seektime = 0;
	int arr[n], min, temp, i, j, x;
		
	for(i=0; i<n; i++)
	{
		arr[i] = 0;
	}
	
	while(1)
	{
		min = 999;
		for(i=0; i<n; i++)
		{
			if(arr[i] == 0)
			{
				if(min > abs(head - sequence[i]))
				{
					min = abs(head - sequence[i]);
					x = i;
				}
			}
		}
		if(min == 999)
			break;
		arr[x] = 1;
		seektime += min;
		head = sequence[x];
		printf(" > %d", sequence[x]);
	}
	printf("\n\n Seek Time = %d", seektime);
	
}

void scan(int sequence[], int head, int n, int t)
{
	int temp, i, j;
	seektime = 0;

	printf("\n The Disk sequence is : \n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sequence[i] > sequence[j])
			{
				temp = sequence[i];
				sequence[i] = sequence[j];
				sequence[j] = temp;
			}
		}

	}	
	temp = head;
	for(i=0; i<n; i++)
	{
		if(sequence[i] > head)
		{
			printf(" > %d", sequence[i]);
			seektime += abs(temp - sequence[i]);
			temp = sequence[i];
		}
	}
	
	
	seektime += abs(t-1 - sequence[i-1]);
	temp = t-1;
	for(i=n-1; i>=0; i--)
	{
		if(head > sequence[i])
		{
			printf(" > %d", sequence[i]);
			seektime += abs(temp - sequence[i]);
			temp = sequence[i];
		}
	}
    	printf("\n\n Seek Time = %d", seektime);
}


void main()
{
	int n, t, i, head, temp, choice;
	printf("\n Enter number of disk request in queue : ");
	scanf("%d", &n);
	printf(" Enter total number of tracks : ");
	scanf("%d", &t);
	int sequence[n];
	printf("\n Enter the disk request sequence for a disk with %d tracks : ", t);
	for(i=0; i<n; i++)
	{
		scanf("%d", &sequence[i]);
	}
	printf(" Enter the initial position of the R/W head : ");
	scanf("%d", &head);

		
	do {
		printf("\n-------------------------------------------------------------------------\n");
		printf("\n\n 1. FCFS \n 2. SSTF \n 3. SCAN \n 4. EXIT \n");
		printf("\n Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: fcfs(sequence, head, n);
				break;
			case 2: sstf(sequence, head, n);
				break;
			case 3: scan(sequence, head, n, t);
				break;
			case 4: exit(0);
				break;
		}
	}while(1);

	printf("\n\n");
}
