class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // memo[i] will store the min coins for amount i.
        // Initialize with -2 to indicate "not computed yet".
        vector<int> memo(amount + 1, -2);
        return solve(coins, amount, memo);
    }
private:
    int solve(vector<int>& coins, int rem, vector<int>& memo) {
        if (rem < 0) return -1; // Invalid state
        if (rem == 0) return 0;  // Base case: amount is 0
        if (memo[rem] != -2) return memo[rem]; // Return cached result
        
        int min_count = INT_MAX;
        
        for (int coin : coins) {
            int res = solve(coins, rem - coin, memo);
            if (res >= 0 && res < min_count) {
                min_count = 1 + res;
            }
        }
        
        // Cache the result before returning
        memo[rem] = (min_count == INT_MAX) ? -1 : min_count;
        return memo[rem];
    }
};