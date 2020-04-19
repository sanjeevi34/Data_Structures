#include<stdio.h>
#include<conio.h>
int *A;
void merge(int A[], int temp[], int left, int mid, int right);
int *merge_sort(int A[], int temp[], int left, int right)
{
	int mid;
	if(right > left)
	{
		mid = (left+right)/2;
		merge_sort(A, temp, left, mid);
		merge_sort(A, temp, mid+1, right);
		merge(A, temp, left, mid+1, right);
	}
	return A;
}

void merge(int A[], int temp[], int left, int mid, int right)
{
	int temp_pos;
	int left_end = mid-1;
	int size,i;
	temp_pos = left;
	size = right - left + 1;
	while(left<=left_end && mid<= right)
	{
		if(A[left] <= A[mid])
		{
			temp[temp_pos] = A[left];
			left += 1;
			temp_pos+=1;
		}
		else
		{
			temp[temp_pos] = A[mid];
			mid += 1;
			temp_pos += 1;
		}
	}
	while(left<=left_end)
	{
		temp[temp_pos] = A[left];
		left += 1;
		temp_pos += 1;
	}
	while(mid<=right)
	{
		temp[temp_pos] = A[mid];
		mid += 1;
		temp_pos += 1;
	}
	for(i = 0; i<=size; i++)
	{
		A[right] = temp[right];
		right = right - 1;
	}
}

void main()
{
	int *C;
	int B[] = {10, 2, 1, 30, 49,0,100};
	int n = sizeof(B)/sizeof(B[0]);
	int temp[5];
	int j;
	clrscr();
	C = merge_sort(B,temp,0,n-1);
	for(j=0; j<n ; j++)
	{
		printf("%d ",C[j]);
	}
	getch();
}