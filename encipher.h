// encipher a file 
void encipher(char *filename)
{
	FILE *fp,*fpn; 
	char ch;
	char new_filename[100];
	strcpy(new_filename,filename);
	strcat(new_filename,".bak");
	fp=fopen(filename,"rt");
	fpn=fopen(new_filename,"wt");
	while((ch=fgetc(fp))!=EOF)
	{
		ch^=0x6a;
		fputc(ch,fpn);
	}
	fclose(fp);
	fclose(fpn);
	fp=fopen(new_filename,"rt");
	fpn=fopen(filename,"wt");
	while((ch=fgetc(fp))!=EOF)
	{
		fputc(ch,fpn);
	}
	fclose(fp);
	fclose(fpn);
	remove(new_filename);
}

// decipher a file
void decipher(char *filename)
{
	FILE *fp,*fpn; 
	char ch;
	char new_filename[100];
	strcpy(new_filename,filename);
	strcat(new_filename,".bak");
	fp=fopen(filename,"rt");
	fpn=fopen(new_filename,"wt");
	while((ch=fgetc(fp))!=EOF)
	{
		ch^=0x6a;
		fputc(ch,fpn);
	}
	fclose(fp);
	fclose(fpn);
	fp=fopen(new_filename,"rt");
	fpn=fopen(filename,"wt");
	while((ch=fgetc(fp))!=EOF)
	{
		fputc(ch,fpn);
	}
	fclose(fp);
	fclose(fpn);
	remove(new_filename);
}

