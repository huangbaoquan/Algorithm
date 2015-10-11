#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void evenodd(int data[],int len)
{
	if(data == NULL)
	{
		throw std::runtime_error("Invaid Parameters");
	}
	int i = 0;
	int j = len -1;
	while(i < j)
	{
		while(i < j && data[i] % 2 != 0)
			i++;
		while(i < j && data[j] % 2 == 0)
			j--;
		swap(data[i++],data[j--]);
	}
}
int main()
{
	int data[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(data)/sizeof(int);
	evenodd(data,len);
	for(int i=0;i< len;i++)
		printf("%d ",data[i]);
}
