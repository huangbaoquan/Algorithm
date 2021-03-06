# author:bqhuang
# date: 2015/10/15

#*******************************************************************************************************
#Given a text file file.
#txt that contains list of phone numbers (one per line), 
#write a one liner bash script to print all valid phone numbers.
#You may assume that a valid phone number must appear in one of the following two formats: 
#(xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)
#You may also assume each line in the text file must not contain leading or trailing white spaces.
#For example, assume that file.txt has the following content:
#987-123-4567
#123 456 7890
#(123) 456-7890
#Your script should output the following valid phone numbers:
#987-123-4567
#(123) 456-7890
#*******************************************************************************************************
# 使用grep全文检索 -E 把匹配拓展成正则表达式 -o：--only-matching,仅仅输出匹配出的内容
# ^([0-9]{3}-){2}([0-9]{4})$ 匹配出: 987-123-4567
# ^(\([0-9]{3}\) )([0-9]{3}-)([0-9]{4})$ 匹配出:(123) 456-7890

cat ./file.txt |grep -Eo "^([0-9]{3}-){2}([0-9]{4})$|^(\([0-9]{3}\) )([0-9]{3}-)([0-9]{4})$"

