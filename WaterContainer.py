from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        res=[]

        left,right=0,len(height)-1
        
        while left<right:
            res.append( min(height[left],height[right]) * (right-left))
            if(height[left]>height[right]):
               right-=1

            elif(height[right]>height[left]):
                left+=1
            
            else:
                left+=1
                right-=1
        
        return max(res)
        