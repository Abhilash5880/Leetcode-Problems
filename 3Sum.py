from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()   # Sort array
        n = len(nums)
        res = []      

        for i in range(n - 2):
            # Skip duplicate
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, n - 1
            target = -nums[i]

            while left < right:
                s = nums[left] + nums[right]

                if s == target:
                    # Found a valid triplet
                    res.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1

                    # Skip duplicates for left
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    # Skip duplicates for right
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1

                elif s < target:
                    left += 1
                else:
                    right -= 1

        return res