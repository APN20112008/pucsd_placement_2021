/*
Update array with values 2k+4, where k=0,1,2...n; where n is the length of our of array

example: 
n = 10 
[4, 6, 8, 10, 12, 14, 16, 18, 20, 22]

Iterate for i= 1 to n-1
evaluate left sum= sum(array[0]+...+array[i-1]
evaluate left sum= sum(array[i+1]+...+array[n-1]
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//to store current best diff and partitioning point
struct parameters
{
	unsigned long int diff;
	int index;
};
unsigned long int getSum(int start, int end, unsigned long int *a )
{
	int i;
	unsigned long int sum;
	sum=0;
	for(i=start;i<=end;i++)
	{
		sum+=a[i];
	}
	return sum;
}
int main(int argc, char *argv[])
{
	unsigned long int *arr, leftSum, rightSum;
	int n,k;
	struct parameters p;
	n= atoi(argv[1]);
	arr= (unsigned long int *)calloc(n,sizeof(unsigned long int ));
	for(k=0;k<n;k++)
	{
		arr[k]=2*k+4;
	}
	leftSum= getSum(0,0,arr);
	rightSum= getSum(2, (n-1),arr );
	p.diff=leftSum-rightSum;
	p.index=1;
	for(k=1;k<n-1;k++)
	{
		leftSum= getSum(0,k-1,arr);
		rightSum= getSum(k+1,n-1,arr);
		printf("\n%lu %lu",leftSum,rightSum);
		if(p.diff > abs(leftSum-rightSum) )
		{
			p.diff=leftSum-rightSum;
			p.index=k;	
		}
	}
	printf("\npartition at: %d", p.index+1);
	printf("\nleft Sum: %lu", getSum(0, (p.index-1),arr));
	printf("\nright Sum: %lu", getSum((p.index+1),n-1,arr));
	return 0;
}
