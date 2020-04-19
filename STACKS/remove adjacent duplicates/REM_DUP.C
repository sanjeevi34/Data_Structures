#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<string.h>
void removeAdjacentDuplicates(char *string)
{
	int top=-1,i=0;
	int len = strlen(string);
	while(i<len)
	{
		if(top==-1 || string[top]!=string[i])
		{
			top = top+1;
			string[top] = string[i];
			i++;
		}
		else
		{
			while(i<len && string[top] == string[i])
				i++;
			top = top-1;
		}
	}
	string[top+1] = '\0';
}
void main()
{
	char a[]="careermonk";
	char b[]="mississippi";
	clrscr();
	removeAdjacentDuplicates(b);
	printf("%s",b);
	getch();
}