#include<stdio.h>
#include<conio.h>

int * selection_sort(int *a , int n)
{
	int temp;
	int i,j,min;
	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		{
			if(a[j]<a[min])
			{
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}

	return a;
}

void main()
{
	int i;
	int a[] = {20 , 3, 15, 1, 22, 40};
	int *b;
	int n = sizeof(a)/sizeof(a[0]);
	clrscr();
	b = selection_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	getch();
}