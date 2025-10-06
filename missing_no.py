# METHOD 1 - Using Vectors (list implementation)
'''class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        v = [-1] * (n + 1)
        for num in nums:
            v[num] = num
        for i in range(len(v)):
            if v[i] == -1:
                return i
        return 0
'''
# METHOD 2 - XOR operations (bitwise operations)
'''
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(1, n + 1):
            ans ^= i
        for num in nums:
            ans ^= num
        return ans

'''

# METHOD 3 - Sum of elements 
'''
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        Tsum = (n * (n + 1)) // 2
        actual_sum = sum(nums)
        return Tsum - actual_sum

'''

# METHOD 4 - Sorting 
'''
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        
        # Case 1
        if nums[0] != 0:
            return 0
        
        # Case 2
        if nums[-1] != n:
            return n
        
        # Case 3
        for i in range(1, len(nums)):
            if nums[i] != i:
                return i
        
        return 0

'''