'''def hammingWeight(num):
        res = 0

        while num > 0:
            # Check the least significant bit (LSB): num & 1 
            # If the LSB is 1, the result is 1, so we increment res.
            res += (num & 1) 
            
            # Shift bits to the right by 1 (equivalent to integer division by 2)
            # This discards the LSB and moves the next bit into the LSB position.
            num >>= 1  
            
        return res
class Solution:
    
    def countBits(self, n: int) -> List[int]:
        l=[]
        for i in range(n+1):
            l.append(hammingWeight(i))

        return l
        
'''
from typing import List

class Solution:
    def countBits(self, n: int) -> List[int]:
        
        dp = [0] * (n + 1)
        
        for i in range(1, n + 1):
            dp[i] = dp[i >> 1] + (i & 1)
        return dp
