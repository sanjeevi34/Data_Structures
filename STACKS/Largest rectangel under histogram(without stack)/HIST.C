#include<stdio.h>
#include<conio.h>

int min(int a, int b)
{
  if(a>b)
	return b;
  else
	return a;
}
int max(int a, int b)
{
  if(a>b)
	return a;
  else
	return b;
}
int larg_hist(int *histo)
{
	int i,min_hei,j,max_area=0;
	for(i=0;i<7;i++)
	{
		for(j=i, min_hei = histo[i]; j<7;j++)
		{
			min_hei = min(min_hei,histo[j]);
			max_area = max(max_area,min_hei*(j-i+1));
		}
	}
	return max_area;
}


void main()
{
	int hist[]={3,2,5,6,1,4,4};
	clrscr();
	printf("\nLargest rectangle area under histogram :  %d",larg_hist(hist));
	getch();
}