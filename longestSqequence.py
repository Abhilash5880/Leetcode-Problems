from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Edge case: If the list is empty, the length is 0.
        if not nums:
            return 0
        
        # 1. Store all numbers in a Set for O(1) average time lookups.
        num_set = set(nums)
        longest_streak = 0
        
        # 2. Iterate through every unique number in the set.
        for num in num_set:
            # Check if 'num' is the start of a sequence.
            # A number is the start if num - 1 is NOT present in the set.
            if num - 1 not in num_set:
                # This is the start of a new sequence, so we start counting.
                current_num = num
                current_streak = 1
                
                # 3. Extend the sequence forward.
                # While the next number (current_num + 1) is present in the set:
                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1
                
                # 4. Update the overall longest streak found.
                longest_streak = max(longest_streak, current_streak)
                
        return longest_streak

# Example Usage:
# input_data = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
# expected_output = 9
# solution = Solution()
# print(f"Input: {input_data}")
# print(f"Longest Consecutive Sequence Length: {solution.longestConsecutive(input_data)}")
