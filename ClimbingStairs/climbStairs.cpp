//author : bqhuang
//date   : 2015/11/2


/***********************************************************************************
 * You are climbing a stair case. 
 * It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?
************************************************************************************/

#include <iostream>
using namespace std;

int climbStairs(int n)
{
	if(n<=2)
		return n;
	int* Fibonacci = new int[n];
	Fibonacci[0] = 1;
	Fibonacci[1] = 2;
	for(int i=2;i<n;i++)
	{
		Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
	}
	return Fibonacci[n-1];
}
