// author : bqhuang
// date   : 2015/10/29

/********************************************************************************** 
* Write a program to find the n-th ugly number.
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
* For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
* Note that 1 is typically treated as an ugly number.
*
* 解答： 如果每次判断一个数是不是丑数的话，知道找到第n个丑数。这种方式导致时间复杂度很长
* 优雅的解答是，每次取 *2，*3，*5中取出最小数。
***********************************************************************************/ 

#include <iostream>
using namespace std;

bool isUgly(int num)
{
	if(num<=0)
		return false;
	if(num == 1)
		return true;
	while(num %2 == 0)
	{
		num/=2;
	}
	while(num %3 == 0)
	{
		num/=3;
	}
	while(num %5 == 0)
	{
		num/=5;
	}
	if(num == 1)
		return true;
	else
		return false;
}
// 普通解答
int nthUglyNumber(int n) 
{
	int count = 0;
	int i = 1;
	while(true)
	{
		if(isUgly(i))
		{
			count++;
		}
		if(count == n)
		{
			return i;
		}
		i++;
	}
}

int max(int a,int b,int c)
{
	int temp;
	temp = a > b ? a : b;
	return temp > c ? temp : c;
}

//优雅解答
int nthuglyNum(int n)
{
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",nthUglyNumber(n));
}
