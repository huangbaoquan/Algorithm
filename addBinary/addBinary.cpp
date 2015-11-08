// date   : 2015/11/8
// author : bqhuang

/***********************************************************************************
* Given two binary strings, return their sum (also a binary string).
* 
* For example,
* a = "11"
* b = "1"
* Return "100".
************************************************************************************/

#include <iostream>
using namespace std;
string addBinary(string a, string b) 
{
	int lena = a.size();
	int lenb = b.size();
	int carry = 0;
	string result = "";
	for(int i = lena - 1,j = lenb - 1;i>=0 || j>=0;i--,j--) 
	{
		int bita = (i >= 0 ? a[i] - '0':0);
		int bitb = (j >= 0 ? b[j] - '0':0);
		int val = (bita + bitb + carry) % 2;
		carry = (bita + bitb + carry) / 2;
		result.insert(result.begin(),val+'0');
	}
	if(carry == 1)
	{
		result.insert(result.begin(),carry+'0');
	}
	return result;
}

int main()
{
	string a =  "11";
	string b = "1";
	cout<<addBinary(a,b);
}
