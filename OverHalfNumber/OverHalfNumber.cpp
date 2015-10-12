//author: bqhuang
//Date: 2015/10/12

/********************************************************************************** 
初阶：有N个数，其中一个数的出现次数严格超过了一半。求这个数。
以上两问均要求O(n)的时间复杂度和O(1)的额外空间复杂度。
***********************************************************************************/ 

#include <iostream>
using namespace std;

void OverHalfNumber(int array[],int len)
{
	int result,count;
	result = array[0];
	count = 1;
	for(int i=1;i<len;i++)
	{
		if(result != array[i] && count != 0)
		{
			count--;
		}
		else if(result == array[i])
		{
			count++;
		}
		else if(result != array[i] && count == 0)
		{
			result = array[i];
			count = 1;
		}
	}
	printf("%d",result);
}
int main()
{
	int array[] = {1,2,3,4,5,5,5,5,5,5};
	int len = sizeof(array)/sizeof(array[0]);
	OverHalfNumber(array,len);
}
