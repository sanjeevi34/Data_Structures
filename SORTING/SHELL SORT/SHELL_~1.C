#include<stdio.h>
#include<conio.h>

int *shell_sort(int *a, int n)
{
	int gap,i,j,key;
	for(gap = n/2 ; gap>0 ; gap = gap/2)
	{
		for(i=gap; i<n ; i++)
		{
			key = a[i];
			j = i;
			while(j>=gap && a[j-gap] > key)
			{
				a[j] = a[j-gap];
				j-=gap;
			}
			a[j] = key;
		}
	}
	return a;
}


void main()
{
	int a[]={2,19,22,1,13,20};
	int k;
	int n = sizeof(a)/sizeof(a[0]);
	int *b;
	clrscr();
	b = shell_sort(a,n);
	for (k=0; k<n; k++)
	{
		printf("%d ",b[k]);
	}
	getch();
}