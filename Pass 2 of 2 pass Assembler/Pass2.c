// CPU-Scheduling-Algorithm-In-C
// Pass Two of Two pass Assembler

#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
    FILE *f1, *f3, *f2, *f4, *f5;
    int op1[10], txtlen, txtlen1, i, j=0, len;
    char addr[5], symaddr[5], op[5], start[10], temp[30], line[20], label[20], mne[10], operand[10], symtab[10], opmne[10];
  
    f1=fopen("Input.dat","r");
    f2=fopen("Length.dat","r");
    f3=fopen("Optab.dat","r");
    f4=fopen("Symbol.dat","r");
    f5=fopen("Output.dat","w");

    fscanf(f1,"%s%s%s%s", addr, label, mne, operand);
    if(strcmp(mne,"START") == 0)
    {
        strcpy(start, operand);
        fscanf(f2,"%d", &len);
    }
    fprintf(f5,"H^%s^%s^%d\nT^00%s^", label, start, len, start);
    fscanf(f1,"%s%s%s%s", addr, label, mne, operand);
    while(strcmp(mne,"END") != 0)
    {
        fscanf(f3,"%s%s", opmne, op);
        while(!feof(f3))
        {
            if(strcmp(mne,opmne) == 0)
            {
                fclose(f3);
                fscanf(f4,"%s%s", symaddr, symtab);
                while(!feof(f4))
                {
                    if(strcmp(operand, symtab) == 0)
                    {
                        fprintf(f5,"%s%s^",op, symaddr);
                        break;
                    }
                    else
                        fscanf(f4,"%s%s", symaddr, symtab);
                }
                break;
            }
            else
                fscanf(f3,"%s%s", opmne, op);
        }
        if((strcmp(mne,"BYTE") == 0)||(strcmp(mne,"WORD") == 0))
        {
            if(strcmp(mne,"WORD") == 0){
                fprintf(f5,"0000%s^", operand);
            }
            else
            {
                len=strlen(operand);
                for(i=2;i<len;i++)
                {
                    fprintf(f5,"%d", operand[i]);
                }
                fprintf(f5,"^");
            }
        }
        fscanf(f1,"%s%s%s%s", addr, label, mne, operand);
        f3=fopen("Optab.dat","r");
        fseek(f3, SEEK_SET, 0);
    }
    fprintf(f5,"\nE^00%s\n", start);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
}
