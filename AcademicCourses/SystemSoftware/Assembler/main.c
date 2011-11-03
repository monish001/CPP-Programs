//Assumptions: 
//1. When there is no label, use tab followed by space.

//PASS 1: For each line
//			add symbol (along with LC value) into ST
//			check in POT if pseudo-op (and correcsponing action) else check in MOT
//			add literal into LT and it's value(LC) when LTORG/END is found

//EVAL() is remaining in Pass1
#include <stdio.h>

//contains logFile details and other common utility functions
#include "utility.c" 
#include "AssemblerPass2.c"
#include "AssemblerPass1.c"
int main(){
	logFile = fopen("assembler.log", "a");
	FILE *fp = fopen("Prog.asm", "r");
	FILE *out = tmpfile();//fopen("PassOneOutput.tmp", "w+");
	if(logFile == NULL)
	{ puts("LOG FILE OPEN ERROR."); getch(); exit(0); }
	if(fp == NULL)
	{ puts("FILE NOT FOUND. PROGRAM WILL ON ANY KEY PRESS."); getch(); fclose(logFile); exit(0); }
	if(out == NULL)
	{ puts("TEMPORARY FILE CANNOT BE CREATED. PROGRAM WILL ON ANY KEY PRESS."); getch(); fclose(logFile); fclose(fp); exit(0); }
	
	fprintf(stdout, "Label Opcode Operand1 Operand2\n");

	printTimeToLog();fprintf(logFile, "************** Assembler Program Started **************\n");
	initMOT();
	
	char str[MAXLINE] = {0};
	do{
		memset(str, 0, MAXLINE);
		fgets(str, MAXLINE-1, fp);
		int breakFlag=0;
		if(strstr(str, "\t end") != NULL){
			if(str[strlen(str)-2]!='\n')
				strcat(str, "\n");
			breakFlag=1;
		}
		printf("%s", str);
		tokenizeLine(str, out);
		if(breakFlag) break;
	}while(1  &&  !feof(fp) );
	printf("--------------------------\n");
	fflush(logFile);
	printST(stdout); puts("");
	printLT(stdout); puts("");
	printTimeToLog();fprintf(logFile, "************** Pass One Complete **************\n");
	fprintf(stdout, "************** Pass One Complete **************\n");
    Pass2(out);

	deleteMOT();
	deleteST();
	deleteLT();

	fclose(fp);
	fclose(logFile);
	fclose(out);

	return 0;
}



