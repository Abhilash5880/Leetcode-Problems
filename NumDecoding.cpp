class Solution {
public:
    int numDecodings(std::string s) {

        // ── EDGE CASE GUARD ───────────────────────────────────────────────────
        // If string is empty → nothing to decode → 0 ways
        // If first character is '0' → no valid letter maps to 0 → 0 ways
        // (e.g. "023" can never be decoded — no encoding starts with 0)
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        // Total number of characters in the string
        int n = s.length();

        // ── DP ARRAY SETUP ────────────────────────────────────────────────────
        // dp[i] = number of ways to decode the FIRST i characters of s
        // Size is n+1 to handle the base case dp[0] cleanly
        // All slots initialized to 0
        std::vector<int> dp(n + 1, 0);

        // BASE CASE 1 — empty string
        // There is exactly 1 way to decode an empty string (do nothing)
        // This is needed so dp[2] can correctly add dp[0] when a two-digit decode works
        dp[0] = 1;

        // BASE CASE 2 — first character
        // We already know s[0] != '0' (checked above)
        // So there is exactly 1 way to decode a single character
        dp[1] = 1;

        // ── MAIN DP LOOP ──────────────────────────────────────────────────────
        // Start from i=2 because dp[0] and dp[1] are already filled
        // i represents how many characters of s we're currently considering
        for (int i = 2; i <= n; ++i) {

            // ── SINGLE DIGIT CHECK ────────────────────────────────────────────
            // s[i-1] is the CURRENT character (i is 1-indexed, s is 0-indexed)
            // Subtract '0' to convert char to its integer value
            // Example: s[i-1] = '6' → '6' - '0' = 6
            int oneDigit = s[i - 1] - '0';

            // ── TWO DIGIT CHECK ───────────────────────────────────────────────
            // s.substr(i-2, 2) extracts the 2-character window ending at position i-1
            // stoi() converts that 2-char string to an integer
            // Example: i=3, s="226" → substr(1, 2) = "26" → twoDigits = 26
            int twoDigits = std::stoi(s.substr(i - 2, 2));

            // ── RULE 1 — decode current character as a single digit ───────────
            // Valid single digits are 1–9 (A–I)
            // If oneDigit == 0, s[i-1] is '0' which has no single-letter mapping
            // If valid → all ways to decode first (i-1) chars also work for i chars
            if (oneDigit != 0) {
                dp[i] += dp[i - 1];
            }

            // ── RULE 2 — decode last two characters as a pair ─────────────────
            // Valid two-digit codes are 10–26 (J–Z)
            // Below 10 → has a leading zero (e.g. "05") → invalid
            // Above 26 → no letter maps beyond Z → invalid
            // If valid → all ways to decode first (i-2) chars also work for i chars
            if (10 <= twoDigits && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }

            // NOTE: dp[i] can get contributions from BOTH rules at the same time
            // That's intentional — both ways of reading the last digit(s) are valid
        }

        // dp[n] holds the total number of ways to decode the entire string
        return dp[n];
    }
};