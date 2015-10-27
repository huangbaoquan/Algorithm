// author : bqhuang
// date   : 2015/10/26

/********************************************************************************** 
 print 1-200 prime 
 intel intern interview 
***********************************************************************************/ 

#include <iostream>
using namespace std;

int countPrimes(int n)
{
	int count = 0;
	bool num[n];
	//init 
	for(int i=0;i<n;i++)
	{
		num[i] = true;
	}
	num[0] = false;
	num[1] = false;
	for(int i=2;i<n;i++)
	{
		// 找到并剔除能够被2,3...整除的数
		if(num[i])
		{
			for(int j=i+i;j<n;j+=i)
			{
				num[j] = false;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(num[i])
		{
			printf("%-4d",i);
			count++;
		}
	}
	printf("\n%d",count);
	return count;
}

int main()
{
	int n;
	scanf("%d",&n);
	countPrimes(n);
}
