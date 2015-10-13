//author: bqhuang
//Date: 2015/10/13

#include <iostream>
#include <stdlib.h>
using namespace std;

void FirstAppearOnce(int array[],int len)
{
	int hash[256] = {0};
	for(int i = 0;i<len;i++)
	{
		hash[array[i]]++;
	}
	for(int i = 0;i<len;i++)
	{
		if(hash[array[i]] == 1)
		{
			printf("%d\n",array[i]);
			return;
		}
	}
}

int main()
{
	int array[] = {1,1,3,4,6,2,3,4,5};
	int len = sizeof(array)/sizeof(array[0]);
	FirstAppearOnce(array,len);
}
