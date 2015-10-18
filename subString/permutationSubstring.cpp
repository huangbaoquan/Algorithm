// author: bqhuang
// date: 2015/10/16

/***********************************************************************************
 给定字符串a,b。如果字符串a的全排列属于字符串b的子集，则返回1，否则返回0.
 For Example:
 String a: qiyii 
 String b: iqiyigreat
 return : 1
 
 String a: iqiyi
 String b: greate
 return : 0 
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
			printf("1\n");return 1;
		}
	}
	printf("0\n");
	return 0;
}

int main()
{
	string a = "iqiyi";  
	string b = "qiyiigreat";
	isPermutation(a,b);
}
