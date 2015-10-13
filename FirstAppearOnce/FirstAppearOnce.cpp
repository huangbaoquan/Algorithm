//author: bqhuang
//Date: 2015/10/13


/********************************************************************************** 
 * 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次，
 * 请写程序找出这两个只出现一次的数字。要求时间复杂度是 O(n)，空间复杂度是 O(1)。
 ***********************************************************************************/ 

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
