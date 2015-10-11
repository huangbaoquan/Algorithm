class Solution():
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """ 
        sums = 0
        for i in nums:
            sums = sums + i 
        length = len(nums)
        print((1+length)*length/2 - sums)
        return (1+length)*length/2 - sums
if __name__=="__main__":
    nums = [0,1,3]
    test = Solution()
    test.missingNumber(nums)
