class Solution {
public:
    int countSubstrings(string s) 
    {
        // 'count' accumulates the total number of palindromic substrings found
        int count = 0;

        // Visit every character in the string as a potential palindrome center
        for(int i = 0; i < s.length(); i++)
        {
            // Case 1 — ODD length palindromes
            // Center is a single character at index i
            // Example: "aba" → center is 'b' at index 1
            // expand(s, i, i) means left and right both start at the SAME character
            count += expand(s, i, i);

            // Case 2 — EVEN length palindromes
            // Center is BETWEEN characters at index i and i+1
            // Example: "abba" → center is between the two 'b's
            // expand(s, i, i+1) means left=i and right=i+1 (adjacent pair)
            count += expand(s, i, i+1);
        }

        // Return the total count of all palindromic substrings
        return count;
    }

    // expand() counts how many palindromes exist centered at (left, right)
    // It keeps growing outward as long as characters on both sides match
    //
    // 'left'  → starting left  boundary of expansion
    // 'right' → starting right boundary of expansion
    // Note: string is passed by VALUE here (a copy), not reference
    //       (minor inefficiency — passing by const reference would be better)
    int expand(string s, int left, int right)
    {
        // 'count' tracks how many valid palindromes this center produces
        int count = 0;

        // Keep expanding outward while ALL three conditions hold:
        //   left  >= 0           → left pointer hasn't gone out of bounds
        //   right < s.length()   → right pointer hasn't gone out of bounds
        //   s[left] == s[right]  → characters on both sides still match
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            // Current window [left...right] is a valid palindrome → count it
            count++;

            // Expand outward — move left one step back, right one step forward
            left--;
            right++;
        }

        // Return total palindromes found from this center
        return count;
    }
};