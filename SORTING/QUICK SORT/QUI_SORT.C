#include<stdio.h>
#include<conio.h>

int *quick_sort(int *a, int low, int high)
{
	int pivot;
	if(low<high)
	{
		pivot = partition(a,low,high);
		quick_sort(a,low,pivot-1);
		quick_sort(a,pivot+1, high);
	}
	return a;
}

int partition(int *a, int low, int high)
{
	int temp;
	int left, right, pivot_item = a[low];
	left = low;
	right = high;
	while(left<right)
	{
		while(a[left] <= pivot_item)
		{
			left++;
		}
		while(a[right]>pivot_item)
			right--;
		if(left<right)
		{
			temp = a[left];	
			a[left] = a[right];
			a[right] = temp;
		}

	}
	a[low] = a[right];
	a[right] = pivot_item;
	return right;
} 

void main()
{
	int a[]={100,2, 20, 1, 90, 75, 11};
	int n=sizeof(a)/sizeof(a[0]);
	int *b;
	int j;
	clrscr();
	b = quick_sort(a,0,n-1);
	for(j=0; j<n; j++)
	{
		printf("%d ",b[j]);
	}
	getch();
}