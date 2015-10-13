//author: bqhuang
//Date: 2015/10/14

/********************************************************************************** 
 * Single Number: 
 * Given an array of integers, every element appears twice except for one. 
 * Find that single one.
 * Note:Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory?
***********************************************************************************/ 

#include <iostream>
using namespace std;

int singleNumber(int* nums, int numsSize) 
{
	int result;
	if(nums != NULL)
	{
		result = nums[0];
		for(int i = 1;i<numsSize;i++)
		{
			result ^= nums[i];
		}
		printf("%d\n",result);
		return result;
	}
	return -1;
}

int main()
{
	int array[] = {1,2,3,4,5,1,2,3,4};
	int len = sizeof(array)/sizeof(array[0]);
	singleNumber(array,len);
}
