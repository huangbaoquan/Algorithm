// author : bqhuang
// date   : 2015/10/26

// print 1-100 质数

#include <iostream>
#include <math.h>
using namespace std;

void printPrime()
{
	int i,j;
	bool flag = true;
	for(i = 2;i<=100;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j == 0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			printf("%d ",i);
		}
	}
}
int main()
{
	printPrime();
}
