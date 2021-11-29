/*
Approach for MAIN problem:
->Accept the sequence length as input as a command line argument
-> Dynamically allocate memory to a pointer
-> update values for fibonacci sequence of length n using a for loop
-> print the nth element of our array

Approach for BONUS problem:
-> Accept the count of an even number in the fibonacci sequence

-> initialize a variable to keep count of even numbers that have come up in the fibonacci sequence

-> Initialize a while loop that continues while count < n
--> everytime an even number is detected, update count by +1
--> if count==n, print the number and break from loop

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{

	//MAIN PROBLEM
	//uncomment before compiling
	/*unsigned long int *f;
	int n,i;
	n=atoi(argv[1]);
	f=(unsigned long int*)calloc(n,sizeof(unsigned long int));
	f[0]=0;
	f[1]=1;
	for (i=2;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2];
		printf("%lu\n",f[i]);
	}
	printf("nth fibonacci: %lu",f[n]);
	*/
	
	
	//BONUS
	//uncomment before compiling
	/*int count,n;
	unsigned long int f1,f2,fnew;
	n=atoi(argv[1]);
	f1=0;
	f2=1;
	count=0;
	while(count<n)
	{
		fnew=f1+f2;
		if(fnew%2==0)
		{
			count+=1;
		}
		if(count==n)
		{
			printf("nth even fibonacci= %lu",fnew);
			break;
		}
		f1=f2;
		f2=fnew;
	}
	*/
	return 0;
}



