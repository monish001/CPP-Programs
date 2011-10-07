void Pass2(FILE *fp){
	fseek(fp, 0, SEEK_SET);
	char c;
	while((c=fgetc(fp))!=EOF){
		putchar(c);
	}
	getch();
}
