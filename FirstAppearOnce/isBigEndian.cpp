#include <iostream>
using namespace std;

int isBigEndian()
{
	int x = 0x1234;
	int b = *(char*)&x;
	if(b == 0x12)
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	if( 1 == isBigEndian())
	{
		printf("big Endian");
	}
	else
		printf("little Endian");
}
