// CPU-Scheduling-Algorithm-In-C
// Pass One of Two pass Assembler

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char opcode[20], operand[20], label[20], code[20], menumonic[20];
	int locctr, start, lenght;

	FILE *f1, *f2, *f3, *f4;

	f1 = fopen("Input.txt", "r");
	f2 = fopen("Optab.txt", "r");
	f3 = fopen("Output.txt", "w");
	f4 = fopen("Symtab.txt", "w");

	fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
	if(strcmp(opcode, "START") == 0)
	{
		start = atoi(operand);
		locctr = start;
		fprintf(f3, "\t\t%s\t%s\t%s\n", label, opcode, operand);
		fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
	}
	else
	{
		locctr = 0;
	}

	while(strcmp(opcode, "END") != 0)
	{
		fprintf(f3, "%d\t", locctr);

		if(strcmp(label, "*****") != 0)
		{
			fprintf(f4, "%s\t%d\n", label, locctr);
		}
		fscanf(f2, "%s\t%s", code, menumonic);
	
		while(strcmp(code, "END") != 0)
		{
				if(strcmp(opcode, code) == 0)
				{
					locctr += 3;
					break;
				}
				fscanf(f2, "%s\t%s", code, menumonic);
		}

		if(strcmp(opcode, "RESW") == 0)
		{
			locctr += 3*(atoi(operand));
		}
		else if(strcmp(opcode, "WORD") == 0)
		{
			locctr += 3;
		}
		else if(strcmp(opcode, "BYTE") == 0)
		{
			locctr += 1;
		}
		else if(strcmp(opcode, "RESB") == 0)
		{
			locctr += atoi(operand);
		}
		fprintf(f3, "%s\t%s\t%s\n", label, opcode, operand);
		fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
	}
	fprintf(f3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
	lenght = locctr - start;
	printf("\n Length = %d \n", lenght);

	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}
