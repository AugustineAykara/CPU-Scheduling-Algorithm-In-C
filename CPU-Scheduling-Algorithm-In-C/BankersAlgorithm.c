// CPU-Scheduling-Algorithm-In-C
// Bankers Algorithm

#include<stdio.h>

void main()
{
  int process, resource, i, j, instance, k=0, count=0, temp=0;
  printf("\n Enter No. of Process : ");
  scanf("%d", &process);
  printf(" Enter No. of Resources : ");
  scanf("%d",&resource);
  int available[resource], max[process][resource], allocated[process][resource], need[process][resource], completed[process];

  for(i=0; i<process; i++)
    completed[i] = 0;

  printf("\n Enter No. of AVAILABLE Instances for each resource\n\n");
  for(i=0; i<resource;i++)
  {  
    printf(" Resources[%d] : ", i);
    scanf("%d", &instance);
    available[i] = instance;
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\n Enter MAXIMUM No. of instances, a Process need for each resource :\n");
  for(i=0; i<process; i++)
  {
    printf("\n For Process[%d] \n", i);
    for(j=0; j<resource; j++)
    {
        printf(" Resource[%d] : ", i);
        scanf("%d", &instance);
        max[i][j] = instance;
    }
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\n Enter No. of instances ALLOCATED for a Process & corresponding resource:\n");
  for(i=0; i<process; i++)
  {
    printf("\n For Process[%d] \n", i);
    for(j=0; j<resource; j++)
    {
      printf(" Resource[%d] : ", i);
      scanf("%d", &instance);
      allocated[i][j] = instance;
      need[i][j] = max[i][j] - allocated[i][j];
    }
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\nSafe Sequence is : ");
  while(count != process)
  {
    count = temp;
    for(i=0; i<process; i++)
    {
      for(j=0; j<resource; j++)
      {
        if(need[i][j] <= available[j])
        {
          k++;
        }
      }
      if(k == resource && completed[i] == 0 )
      {
        printf(" > P[%d] ", i);
        completed[i] = 1;
        for(j=0; j<resource; j++)
        {
          available[j] = available[j] + allocated[i][j];
        }      
        count++;
      }
      k=0;
    }

    if(count == temp)
    {
      break;
    }
  }

  for(i=0; i<process; i++)
  {
    if(completed[i] != 1)
    {
      printf("\n\n P[%d] not able to allocate", i);
    }
  }
  printf("\n");
}
