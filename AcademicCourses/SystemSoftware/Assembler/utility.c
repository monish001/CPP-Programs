FILE *logFile;
void printTimeToLog(){//logFile must be initialised before call
	time_t rawtime;
	time ( &rawtime );
	char *str = (char*)ctime (&rawtime);
	str[strlen(str)-1] = '\0';
	fprintf (logFile, "%s: ",  str);
}