
// CPU-Scheduling-Algorithm-In-C
// First Come First Served Scheduling Algorithm

#include<stdio.h>
#include<malloc.h>

void main() 
{
    int i, n, *bt, *wt, *tat;
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));

    printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    tat[0] = bt[0];
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];  //waiting time[p] = waiting time[p-1] + Burst Time[p-1]
        tat[i] = wt[i] + bt[i];     //Turnaround Time = Waiting Time + Burst Time
    }

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", i, bt[i], wt[i], tat[i]);
    }

    printf("\n GAANT CHART \n");
    printf("---------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], i, tat[i]);
    }
}