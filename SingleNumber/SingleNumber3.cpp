//author: bqhuang
//Date: 2015/10/14

/********************************************************************************** 
* Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
* Find the two elements that appear only once.
* For example:
* Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
* Note:
* The order of the result is not important. 
* So in the above example, [5, 3] is also correct.
* Your algorithm should run in linear runtime complexity. 
* Could you implement it using only constant space complexity?
**********************************************************************************/
 
#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums)
{
	int result = 0;
	int i = 0;
	int flag = 1;
	vector<int> resultVec(2,0); 
	vector<int> resultOne;
	vector<int> resultZero;
	for(i = 0;i < nums.size();i++)
	{
		result ^= nums[i];
	}

	/* find the first bit is 1;这种写法很普通
	while(true)
	{
		if(result & flag)
			break;
		else
			flag = flag << 1;
	}
	*/
	flag = result & -result;//find the first bit is 1;这种写法很优雅

	for(i = 0;i < nums.size();i++)
	{
		if(flag & nums[i])
			resultVec[0] ^= nums[i];
		else
			resultVec[1] ^= nums[i];
	}
	printf("%d %d",resultVec[0],resultVec[1]);
	return resultVec;
}

int main()
{
	int array[] = {1, 2, 1, 3, 2, 5};
	vector<int> nums(array,array+6);
	singleNumber(nums);
}
