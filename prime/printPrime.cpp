// author : bqhuang
// date   : 2015/10/26

/********************************************************************************** 
 print 1-200 prime 
 intel intern interview 
***********************************************************************************/ 

#include <iostream>
#include <math.h>
using namespace std;

// 普通的解法,时间复杂度nlogn
void printPrime()
{
	int i;
	int j = 2;
	for(i=2;i<=200;i++)
	{
		for(j=2;j<sqrt(i);j++)
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(j > sqrt(i))
			printf("%-4d",i);
	}
}
// 优雅方法,此方法计算量少
void siftPrime()
{
	bool num[200]; 
	for(int i =0;i<200;i++)
	{
		num[i] = true;
	}
	// 0 , 1 is not prime
	num[0] = false;
	num[1] = false;
	for(int i=2;i<200;i++)
	{
		if(num[i])
		{
			for(int j=i+i;j<200;j+=i)
			{
				num[j] = false;
			}
		}
	}
	for(int i=0;i<200;i++)
	{
		if(num[i])
		{
			printf("%-4d",i);
		}
	}
}

int main()
{
	printPrime();
	printf("\n");
	siftPrime();
}
