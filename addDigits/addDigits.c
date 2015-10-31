// author : bqhuang
// date   : 2015/10/31


/***********************************************************************************
* Given a non-negative integer num, 
* repeatedly add all its digits until the result has only one digit.
* For example:
* Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. 
* Since 2 has only one digit, return it.
* 解答：
* 观察法
* 根据提示，由于结果只有一位数，因此其可能的数字为0 - 9
* 使用方法I的代码循环输出0 - 19的运行结果：
* 
* in  out  in  out
* 0   0    10  1
* 1   1    11  2
* 2   2    12  3
* 3   3    13  4
* 4   4    14  5
* 5   5    15  6
* 6   6    16  7
* 7   7    17  8
* 8   8    18  9
* 9   9    19  1
* 可以发现输出与输入的关系为：
* out = (in - 1) % 9 + 1
*************************************************************************************/

#include <stdio.h>

int addDigits(int num)
{
	return (num - 1) % 9 + 1;
}
