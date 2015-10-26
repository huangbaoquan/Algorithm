// author : bqhuang
// date   : 2015/10/26

/********************************************************************************** 
 print 1-200 prime 
 intel intern interview 
***********************************************************************************/ 

#include <iostream>
#include <math.h>
using namespace std;

void printPrime()
{
	int i;
	int j = 2;
	for(i=2;i<=100;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(j == i)
			printf("%d ",i);
	}
}
int main()
{
	printPrime();
}
