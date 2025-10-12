#include <string>
#include <unordered_map>
#include <algorithm> // For std::max
#include <vector>    // For std::vector (though not strictly needed here, often used with LeetCode)

// Using std namespace for convenience in this context
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        
        // Dictionary/Hash Map equivalent: stores character frequencies
        unordered_map<char, int> freq;
        int res = 0;

        // The 'right' pointer expands the sliding window
        for (int right = 0; right < s.length(); ++right) {
            
            // Python's try/except for freq[s[right]]+=1 is achieved idiomatically 
            // in C++ by map's auto-initialization. If the key doesn't exist, 
            // it's initialized to 0, then incremented to 1.
            freq[s[right]]++;

            int curlen = right - left + 1; // Finding total number of elements in the current sliding window

            // --- Translating max(freq.values()) ---
            // This loop ensures we find the maximum frequency (maxF) in the current window.
            // Note: This is an O(N) operation inside the main O(N) loop, making this solution O(N^2).
            int maxF = 0;
            for (auto const& [key, val] : freq) {
                maxF = max(maxF, val);
            }
            
            // Check if the number of characters needing replacement (curlen - maxF) 
            // exceeds the allowed limit (k).
            if ((curlen - maxF) > k) {
                
                // 1. Decrement the frequency of the character leaving the window (s[left]).
                // The C++ logic preserves the original Python intention: decrement BEFORE moving left.
                freq[s[left]]--;
                
                // 2. Slide the window (move the left pointer one step to the right).
                left++;
            }

            // Update the maximum length found so far.
            // Since the window only grows or stays the same size, we update here.
            res = max(res, right - left + 1);
        }

        return res;
    }
};
