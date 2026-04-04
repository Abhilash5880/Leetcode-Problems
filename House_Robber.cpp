class Solution {
private:
    vector<int> memo;

    int rob(vector<int>& nums, int i)
    {
        if (i < 0)
        {
            return 0;
        }
        if (memo[i] >= 0)
        {
            return memo[i];
        }
        int result = max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
        memo[i] = result;
        return result;
    }

public:
    int rob(vector<int>& nums)
    {
        memo.assign(nums.size(), -1);   // fill all slots with -1
        return rob(nums, nums.size() - 1);
    }
};