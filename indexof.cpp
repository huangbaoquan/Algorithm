#include <iostream>
#include <stdio.h>
using namespace std;
/**
 * get first index what substring occur firstly in source String
 * time O(n^2)
 */
int indexof(char source[],int sourcelength,char target[],int targetlength)
{
	//judge condition
	if(targetlength > sourcelength || source == NULL || target == NULL || targetlength == 0)
		return -1;
	//found the first char in target Charactor
	char firstChar= target[0];
	for(int i = 0;i < sourcelength;i++)
	{
		//found the first charactor index in source charactor
		int j = i;
		while(firstChar != source[j])
		{
			if(j < sourcelength){j++;}
			else return -1;
		}
		//represent the gap of first charactor index int source charactor and sourcelength 
		int offset = sourcelength - j - 1; 
		int targetindex = 1;
		for(int index = j;offset > targetlength;index++)
		{
			if(target[targetindex++] != source[j])
				return -1;
		}
	return j;
	}
	return -1;
}
