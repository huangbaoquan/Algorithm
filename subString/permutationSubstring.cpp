// author: bqhuang
// date: 2015/10/18

/***********************************************************************************
 给定字符串a,b。如果字符串a的全排列属于字符串b的子集，则返回1，否则返回0.
 For Example:
 String a: qiyii 
 String b: iqiyigreat
 return : 1
 
 String a: iqiyi
 String b: greate
 return : 0 

 解题思路: 
 不通过求解字符串a的全排列,而是把字符串a按照字典排序。然后通过字符串a
 的长度为滑动窗口截取字符串b，然后对截取出来的字符串做字典排序看看是否与字符串a  的字典排序相等.
***********************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int isPermutation(string a,string b)
{
	int lena = a.length();
	int lenb = b.length();
	char cmp[lena];
	char temp[lena];
	for(int i=0;i<lena;i++)
	{
		cmp[i] = a[i];
	}
	sort(cmp,cmp+lena);
	printf("output: %s\n",cmp);
	for(int j=0;j<lenb-lena+1;j++)
	{
		for(int k=0;k<lena;k++)
		{
			temp[k] = b[j+k];
		}
		sort(temp,temp+lena);
		if(strcmp(cmp,temp) == 0)
		{
			printf("属于子字符串: 1\n");return 1;
		}
	}
	printf("不属于子字符串: 0\n");
	return 0;
}

int main()
{
	string a = "iqiyi";  
	string b = "qiyiigreat";
	isPermutation(a,b);
}
