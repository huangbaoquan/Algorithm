// author : bqhuang
// date   : 2015/10/21

/********************************************************************************** 
1. Given an array and a value, remove all instances of that value 
   in place and return the new length.
2. The order of elements can be changed. 
   It doesn't matter what you leave beyond the new length.
**********************************************************************************/

#include <stdio.h>

int removeElement(int* num,int value,int len)
{
	int pos = 0;
	for(int i=0;i<len;i++)
	{
		if(num[i] != value)
		{
			num[pos++] = num[i];
		}
	}
	return pos;
}
