//BaseTable.c
#define checkLimits(var, i,j) \
	if(var<i || var>j)\
		return;

int curBaseRegister=-1;
int baseTable[16] = {0};
void BTSTO(int reg){
	checkLimits(reg, 0, 15)
	baseTable[reg]=1;
	curBaseRegister = reg;
}
void BTDROP(int reg){
	checkLimits(reg, 0, 15)
	baseTable[reg]=0;
}