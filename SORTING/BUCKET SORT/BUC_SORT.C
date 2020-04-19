#include<stdio.h>
#include<conio.h>
#define BUCKETS 10
int *bucket_sort(int *a, int n)
{
	int buckets[BUCKETS];
	int i,j,k;
	for(i=0;i<BUCKETS;i++)
		buckets[i]=0;
	for(j=0; j<n; j++)
	{
		buckets[a[j]] += 1;
	}
	for(i=0,j=0; j<BUCKETS; j++)
		for(k = buckets[j]; k>0; k--)
			a[i++] = j;
		
	return a;
}
void main()
{
	int a[]={2,3,1,5,7,6};
	int *b;
	int j;
	int n=sizeof(a)/sizeof(a[0]);
	clrscr();
	b = bucket_sort(a,n);
	for(j=0;j<n;j++)
	{
		printf("%d ",b[j]);
	}
	getch();
}