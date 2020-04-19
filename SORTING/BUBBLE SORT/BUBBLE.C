#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,temp,n;
	int a[] = {8, 2, 10, 1, 22, 88, 40};
	clrscr();
	n = sizeof(a)/sizeof(a[0]);
	for(i = 0; i < n-1 ; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	for (j = 0; j<n ; j++)
	{
		printf("%d ",a[j]);
	}
	getch();
}