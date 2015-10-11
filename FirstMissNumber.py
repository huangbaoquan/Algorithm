# @param A, a list of integers
# @return an integer
def firstMissingPositive(A):
    # write your code here
    for i in range(0,len(A)):
        if A[i] == i+1:
            continue
        elif A[i] > 0 and A[i] < len(A) and A[i] != A[A[i-1]]:
            temp = A[i]
            A[i] = A[temp - 1]
            A[temp - 1] = temp
    for i in range(0,len(A)):
        if i + 1 != A[i]:
            return i + 1 
            break

if __name__ == "__main__":
    A  = [3,4,-1,1]
    firstMissingPositive(A)
