//author : bqhuang
//date   : 2015/10/21

/********************************************************************************** 
Given an array nums, write a function to move all 0's to the end of it while 
maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, 
nums should be [1, 3, 12, 0, 0].

Note:
1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.
**********************************************************************************/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 普通
void moveZero(vector<int>& array)
{
	int len = array.size(); 
	int position = 0;
	for(int i=0;i<len;i++)
	{
		if(array[i] == 0)
		{
			while(position < len)
			{
				if(position < i)
					position = i;
				if(array[position] != 0)
				{
					swap(array[i],array[position++]);
					break;
				}
				position++;
			}
		}
	}
}
// elegant algorithm
void moveZero1(vector<int>& array)
{
	int position = 0;
	for(int i=0;i<array.size();i++)
	{
		if(array[i] != 0)
			array[position++] = array[i];
	}
	//fill in Zero
	for(;position<array.size();position++)
	{
		array[position] = 0;
	}
}

int main()
{
	int num[] = {0,1,0,3,12};
	vector<int> array(num,num+5);
	moveZero1(array);
	for(int i = 0;i<array.size();i++)
	{
		printf("%d ",array[i]);
	}
}
