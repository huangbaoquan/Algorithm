# -*- coding: UTF-8 -*- 
# 不用使用加减乘除，实现乘以3
# 左移一位可以是实现乘以2，关键在于如何实现加操作
# a*3 = a << 1 + a
# 两个数相加核心处理进位操作,那么我们最终使得两个二进制数相加不产生进位
# 首先我们要找到会产生进位位置，在二进制中产生进位就是相同位置是1，否则不会产生进位.使用与操作
# 找完进位位置，我们再找出不会产生进位操作的位置.使用异或操作
# 所以我们的判断条件就是：两个二进制与(&)操作为零
def bitadd(a,b):
    result = a ^ b
    carry = a & b
    while carry !=0:
        temp = result
        carry = carry << 1
        result = carry ^ temp
        carry = temp & carry
    print(result)

def bitMulti3(a):
    return bitadd(a<<1,a)

if __name__ == "__main__":
    a = int(raw_input("please enter:\n"))
    bitMulti3(a)
