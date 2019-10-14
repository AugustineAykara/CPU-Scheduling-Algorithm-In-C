// CPU-Scheduling-Algorithm-In-C
// Simulation of Disk Scheduling Algorithm -> FCFS

#include<stdio.h>
#include <stdlib.h>

void main()
{
	int n, t, i, pos, temp, seektime = 0;
	printf("\n Enter number of disk request in queue : ");
	scanf("%d", &n);
	printf(" Enter total number of tracks : ");
	scanf("%d", &t);
	int process[n], sequence[n];
	printf("\n Enter the disk request sequence for a disk with %d tracks : ", t);
	for(i=0; i<n; i++)
	{
		scanf("%d", &process[i]);
		sequence[i] = process[i];
	}
	printf(" Enter the initial position of the R/W head : ");
	scanf("%d", &pos);

	temp = pos;
	printf("\n The Disk sequence is : \n");
	for(i=0; i<n; i++)
	{
		printf(" > %d", sequence[i]);
		seektime += abs(sequence[i]-temp);
		temp = sequence[i];
	}

	printf("\n\n Seek Time = %d", seektime);
	printf("\n\n");
}
