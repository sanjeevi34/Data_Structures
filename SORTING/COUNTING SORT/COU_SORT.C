#include<stdio.h>
#include<conio.h>

int *counting_sort(int *a,int k, int n)
{
	int *ans;
	int count[7],i,j;
	for(i=0;i<k;i++)
		count[i]=0;

	for(j=0;j<n; j++)
	{
		count[a[j]] += 1;
	}
	for(i=1;i<k;i++)
	{
		count[i] = count[i] + count[i-1];
	}
	for(j=0;j<n;j++)
	{
		ans[count[a[j]]] = a[j];
		count[a[j]] -= 1;
	}
	return ans;
}
void main()
{
	int j;
	int *b;
	int n;
	int a[]={4,6,2,3,1};
	clrscr();
	n=sizeof(a)/sizeof(a[0]);
	b = counting_sort(a,7,n);
	for(j=0; j<n; j++)
	{
		printf("%d ",b[j]);
	}
	getch();
}