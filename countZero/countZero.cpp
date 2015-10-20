// author: bqhuang
// date  : 2015/10/20

/********************************************************************************** 
问题详情 
设计一个算法，计算出n阶乘中尾部零的个数

解答 
方法一: 首先求出n!，然后计算末尾0的个数。
方法二: 考虑n!的质数因子。后缀0总是由质因子2和质因子5相乘得来的。如果我们可以计数2和5的个数，问题就解决了
比如: n = 5: 5!的质因子中 包含一个5和三个2。因而后缀0的个数是1。

解法：
一个任何一个数可以是是M = 2^x,3^y,5^z,...但由于阶乘末尾要有零，
必须有2，5一对出现，才能产生10。
而2出现的次数显然比5多，所以只要看5次数就是阶乘末尾零的个数
**********************************************************************************/ 
#include <iostream>
using namespace std;

//优雅
int countZero(int num)
{
	int count;
	while(num)
	{
		count += num / 5;
		num /= 5;
	}
	printf("%d\n",count);
	return count;
}

//普通
int countZero1(int num)
{
	int count = 0;
	int j;
	for(int i=1;i<=num;i++)
	{
		j = i;
		while(0 == j%5)
		{
			count++;
			j/=5;
		}
	}
	printf("%d\n",count);
	return count;
}

int main()
{
	int num;
	scanf("%d",&num);
	countZero(num);
	countZero1(num);
}
