// author: bqhuang
// date: 2015/10/28

/***********************************************************************************
* Write an algorithm to determine if a number is "happy".
* 
* A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
*
* Example: 19 is a happy number
* 1^2 + 9^2 = 82
* 8^2 + 2^2 = 68
* 6^2 + 8^2 = 100
* 1^2 + 0^2 + 0^2 = 1 
*************************************************************************************/

#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

bool isHappy(int n) {
	unordered_set<int> result;
	int happyresult = 0; 
	if(n<=0)
		return false;
	while(n != 1)
	{
		happyresult = 0;
		while(n)
		{
			happyresult += (n % 10) * (n % 10);
			n = n / 10;
		}
		if(happyresult == 1)
			return true;
		else if(result.find(happyresult)!=result.end())
		{
			return false;
		}
		else
		{
			result.insert(happyresult);
		}
		n = happyresult;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",isHappy(n));
}
