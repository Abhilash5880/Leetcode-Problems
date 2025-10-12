from typing import List

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        # A set to represent the characters currently in our window (O(1) lookup)
        char_set = set()
        
        # 'left' is the starting index of the current window
        left = 0
        
        # 'max_length' tracks the best result found so far
        max_length = 0

        # 'right' is the index being added to the window (represented by 'right' pointer)
        for right in range(len(s)):
            
            # 1. Collision Check (Shrink the window if the new character is a duplicate)
            # If the character s[right] is already in the set, we must remove elements 
            # from the left side until the duplicate is gone.
            while s[right] in char_set:
                
                # Remove the leftmost character from the set
                char_set.remove(s[left])
                
                # Move the left pointer one step to the right
                left += 1
                
            # 2. Expansion (Add the new, non-repeating character and update max length)
            
            # Add the current right character to the set (it's guaranteed to be unique now)
            char_set.add(s[right])
            
            # Calculate the length of the current window: right - left + 1
            # And update the overall maximum length
            max_length = max(max_length, right - left + 1)
            
        return max_length