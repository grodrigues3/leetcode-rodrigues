class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        Solution.realSolution(nums)
    @staticmethod
    def cheaterSolution(nums):
        n = len(nums)
        x = []
        for thing in nums:
            if thing != 0:
                x += thing,
        nums[:] = x + [0]*(n-len(x))
        return        
    
    @staticmethod
    def realSolution(nums):
        n = len(nums)
        
        i = j = 0
        while j < n:
            
            while j < n and nums[j] == 0:
                j +=1
            if j < n:
                nums[i] = nums[j]
            else:
                break
            i += 1
            j +=1
            
        while i < j:
            nums[i] = 0
            i +=1
            
            
            
        