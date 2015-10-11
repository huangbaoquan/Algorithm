import sys
def trailingZeros(n):
    result = 0 
    if n < 0 :
        return "the n is not legal input"
    elif n < 5 :
        return 0
    else :
        while n/5 != 0 :
            result += n / 5
            n = n / 5
        return result
if __name__ == "__main__":
	n = raw_input()
        result = trailingZeros(int(n))
        print(str(result))
