class Solution {
public:
    std::string longestPalindrome(std::string s) {

        // If string has 0 or 1 character, it's already a palindrome — return it directly
        if (s.length() <= 1) {
            return s;
        }

        // maxLen tracks the length of the longest palindrome found so far
        int maxLen = 1;

        // maxStr stores the actual longest palindrome substring found so far
        // initialized to just the first character (any single char is a palindrome)
        std::string maxStr = s.substr(0, 1);

        // ── MANACHER'S TRANSFORM ──────────────────────────────────────────────
        // Insert '#' between every character (and at start/end) to handle
        // both even and odd length palindromes uniformly
        //
        // Example: "aba"  →  "#a#b#a#"
        // Example: "abba" →  "#a#b#b#a#"
        //
        // std::regex("") matches every empty string position (i.e. between chars)
        // std::regex_replace fills those gaps with "#"
        // Then we wrap the whole thing with "#" + ... + "#"
        //
        // Now EVERY palindrome in the transformed string has ODD length
        // which makes the algorithm uniform — no separate even/odd case needed
        s = "#" + std::regex_replace(s, std::regex(""), "#") + "#";

        // dp[i] = radius of the longest palindrome centered at index i
        // radius means how far it extends on each side (NOT including center)
        // Example: "#a#b#a#" → dp[3] = 3 (palindrome "#a#b#a#" extends 3 on each side)
        std::vector<int> dp(s.length(), 0);

        // center = index of the center of the rightmost palindrome found so far
        int center = 0;

        // right = the rightmost boundary (right edge) of that palindrome
        // i.e. right = center + dp[center]
        int right = 0;

        // ── MAIN MANACHER LOOP ────────────────────────────────────────────────
        for (int i = 0; i < s.length(); ++i) {

            // ── MIRROR TRICK ──────────────────────────────────────────────────
            // If current index i is within the known rightmost palindrome boundary,
            // we can reuse already-computed information instead of starting from 0
            if (i < right) {

                // mirror of i across 'center' is: 2*center - i
                // dp[mirror] already has the palindrome radius at the mirror position
                //
                // We take the MINIMUM of:
                //   (right - i)         → how far i is from the right boundary
                //   dp[2*center - i]    → palindrome radius at mirror position
                //
                // Why min? Because the mirror's palindrome might extend beyond
                // the known boundary — we can only GUARANTEE up to (right - i)
                dp[i] = std::min(right - i, dp[2 * center - i]);
            }

            // ── EXPAND AROUND CENTER i ────────────────────────────────────────
            // Try to grow the palindrome at i by checking one step further on each side
            //
            //   left  side:  i - dp[i] - 1
            //   right side:  i + dp[i] + 1
            //
            // Keep expanding while:
            //   - left boundary is within string (>= 0)
            //   - right boundary is within string (< s.length())
            //   - characters on both sides match
            while (i - dp[i] - 1 >= 0 
                && i + dp[i] + 1 < s.length() 
                && s[i - dp[i] - 1] == s[i + dp[i] + 1]) {
                dp[i]++;  // palindrome at i can grow by 1 more on each side
            }

            // ── UPDATE RIGHTMOST BOUNDARY ─────────────────────────────────────
            // If the palindrome centered at i extends beyond our current 'right',
            // update center and right to reflect the new rightmost palindrome
            if (i + dp[i] > right) {
                center = i;              // new center is i
                right  = i + dp[i];     // new right boundary
            }

            // ── CHECK IF THIS IS THE LONGEST SO FAR ───────────────────────────
            if (dp[i] > maxLen) {
                maxLen = dp[i];  // update max length

                // Extract the palindrome from the TRANSFORMED string
                // It starts at: i - dp[i]   (left edge)
                // Its length is: 2*dp[i]+1  (full span including center)
                maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);

                // Remove all '#' characters to get back the original palindrome
                // std::remove shifts all '#' to the end, erase() then deletes them
                maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
            }
        }

        // Return the longest palindromic substring found
        return maxStr;
    }
};