# -*- utf-8 -*-
'''
author: bqhuang
time : 2015.7.29
TODO : find the kth max number
'''
import random

def KMaxNumber(k,A):
    '''
    @param k & A a integer and an array
    @return ans a integer
    '''
    lenArr = len(A)
    randNum = random.randint(1,lenArr)
