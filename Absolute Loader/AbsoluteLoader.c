// CPU-Scheduling-Algorithm-In-C
// Absolute Loader

# include<stdio.h>
# include<string.h>

void main()
{
	char input[10];
	int start, length, address;
	FILE *fp1, *fp2;
	
	fp1=fopen("Input.dat","r");
	fp2=fopen("Output.dat","w");
	
	fscanf(fp1,"%s",input);
	while(strcmp(input,"E")!=0)
	{
		if(strcmp(input,"H") == 0)
		{
			fscanf(fp1,"%d",&start);
			fscanf(fp1,"%d",&length);
		}
		else if(strcmp(input,"T") == 0)
		{
			fscanf(fp1,"%d",&address);
			fscanf(fp1,"%s",input);
			fprintf(fp2,"%d\t%c%c\n",address,input[0],input[1]);
			fprintf(fp2,"%d\t%c%c\n",(address+1),input[2],input[3]);
			fprintf(fp2,"%d\t%c%c\n",(address+2),input[4],input[5]);
			address+=2;
		}
		else
		{
			fprintf(fp2,"%d\t%c%c\n",address,input[0],input[1]);
			fprintf(fp2,"%d\t%c%c\n",(address+1),input[2],input[3]);
			fprintf(fp2,"%d\t%c%c\n",(address+2),input[4],input[5]);
			address+=2;
		}
		fscanf(fp1,"%s",input);
	}
	fclose(fp1);
	fclose(fp2);
}
