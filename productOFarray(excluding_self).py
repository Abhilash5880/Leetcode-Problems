from typing import List

class Solution:
    """
    Calculates the product of all elements of nums except nums[i] 
    for each index i in O(N) time without using the division operation.
    """
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        # Initialize the result array. 
        # result[i] will first store the product of all elements to the left of i.
        result = [1] * n
        
        # --- PASS 1: Calculate Prefix Products (Left to Right) ---
        # After this loop, result[i] holds the product of nums[0] * ... * nums[i-1].
        prefix_product = 1
        for i in range(n):
            # The result at the current index gets the product calculated so far (left product)
            result[i] = prefix_product
            
            # Update the prefix product by including the current element
            prefix_product *= nums[i]
            
        # --- PASS 2: Calculate Suffix Products (Right to Left) ---
        # We now multiply the prefix product (already in result[i]) by the suffix product.
        suffix_product = 1
        for i in range(n - 1, -1, -1):
            # The final result at index i is: (Prefix Product) * (Suffix Product)
            # result[i] already holds the Prefix Product from Pass 1
            result[i] *= suffix_product
            
            # Update the suffix product by including the current element
            suffix_product *= nums[i]
            
        return result

# Example Usage (Input: [-1, 1, 0, -3, 3])
# 1. Prefix Pass:
# i=0: result[0]=1, prefix=1*(-1)=-1
# i=1: result[1]=-1, prefix=-1*1=-1
# i=2: result[2]=-1, prefix=-1*0=0
# i=3: result[3]=0, prefix=0*(-3)=0
# i=4: result[4]=0, prefix=0*3=0
# Result after Pass 1: [1, -1, -1, 0, 0]

# 2. Suffix Pass:
# i=4: result[4]=0*1=0, suffix=1*3=3
# i=3: result[3]=0*3=0, suffix=3*(-3)=-9
# i=2: result[2]=-1*(-9)=9, suffix=-9*0=0
# i=1: result[1]=-1*0=0, suffix=0*1=0
# i=0: result[0]=1*0=0, suffix=0*(-1)=0
# Final Result: [0, 0, 9, 0, 0]
