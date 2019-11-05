// CPU-Scheduling-Algorithm-In-C
// Pass One of Two pass Assembler

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char label[20], opcode[20], operand[20], code[20], length[20];
	int locctr, start, size;
	FILE *f1, *f2, *f3, *f4;

	f1 = fopen("Input.dat", "r");
	f2 = fopen("Optab.dat", "r");
	f3 = fopen("Output.dat", "w");
	f4 = fopen("Symtab.dat", "w");

	fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
	if(strcmp(opcode, "START") == 0)
	{
		locctr = atoi(operand);
		start = locctr;
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
			fprintf(f4, "%d\t%s\n", locctr, label);
		}
		fscanf(f2, "%s\t%s", code, length);
	
		while(strcmp(code, "END") != 0)
		{
				if(strcmp(opcode, code) == 0)
				{
					locctr += 3;
					rewind(f2);
					break;
				}
				fscanf(f2, "%s\t%s", code, length);
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
	
	size = locctr - start;
	printf("\n\n Length of code = %d \n\n", size);

	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}
