# author:bqhuang
# date: 2015/10/15
#!bin/bash
#**********************************************************************************************
#Write a bash script to calculate the frequency of each word in a text file words.txt.
#
#For simplicity sake, you may assume:
#
#words.txt contains only lowercase characters and space ' ' characters.
#Each word must consist of lowercase characters only.
#Words are separated by one or more whitespace characters.
#For example, assume that words.txt has the following content:
#
#the day is sunny the the
#the sunny is is
#Your script should output the following, sorted by descending frequency:
#the 4
#is 3
#sunny 2
#day 1
#Note:
#Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
#Write a bash script to calculate the frequency of each word in a text file words.txt.
#**********************************************************************************************
# tr -s 压缩过滤重复的字符,-s 把重复出现的字符替换成指定字符,这里是把空格替换成换行符
# uniq 是把重复行给去掉，-c 是计数重复出现的行数
# sort 排序。-r 是按照倒序排列 -n 按照字母大小排序

cat ./words.txt |tr -s ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2" "$1}'
