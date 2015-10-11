#include "string.h"
#include <iostream>
#include "stdio.h"
using namespace std;

char* revert(char* str)
{
	if(str == NULL)
	{
		throw std::runtime_error("Invaild Parameters");
	}
	int len = strlen(str);
	for(int i = 0;i < len/2; i++)
	{
		char tmp = str[i];
		str[i] = str[len -1- i];
		str[len -1 -i] = tmp;
	}
	return str;
}
int main()
{
	char str[] = "abcdef";
	revert(str);
	printf("%s\n",str);
}
