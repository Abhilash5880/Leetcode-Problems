class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // 🔹 If s1 is larger, permutation impossible
        if (s1.size() > s2.size())
            return false;

        // 🔹 Frequency arrays for:
        // target string and current sliding window
        vector<int> s1Freq(26, 0);
        vector<int> windowFreq(26, 0);

        // 🔹 Build frequency map of s1
        for (char c : s1)
        {
            s1Freq[c - 'a']++;
        }

        int l = 0;

        // 🔹 Traverse s2 using sliding window
        for (int r = 0; r < s2.size(); r++)
        {
            // Add current character to window
            windowFreq[s2[r] - 'a']++;

            // 🔹 Keep window size fixed
            if (r - l + 1 > s1.size())
            {
                windowFreq[s2[l] - 'a']--;
                l++;
            }

            // 🔹 Compare frequencies
            if (windowFreq == s1Freq)
            {
                return true;
            }
        }

        return false;
    }
};