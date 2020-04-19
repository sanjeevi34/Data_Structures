#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,temp,n;
	int swapped;
	int a[] = {1,2,3,4,5};
	clrscr();
	n = sizeof(a)/sizeof(a[0]);
	for(i = 0; i < n-1 ; i++)
	{
		swapped = 0;
		for(j=0; j<n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				swapped = 1;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		if(swapped == 0)
		{
			break;
		}
	}

	for (j = 0; j<n ; j++)
	{
		printf("%d ",a[j]);
	}
	getch();
}