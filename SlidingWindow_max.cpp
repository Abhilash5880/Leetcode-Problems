class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;      // Stores INDICES
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            // 🔹 Remove indices that are OUTSIDE current window
            // Window valid range: [i-k+1 ... i]
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // 🔹 Remove smaller elements from BACK
            // because they can never become maximum again
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            // 🔹 Insert current index
            dq.push_back(i);

            // 🔹 Window starts producing answers only after size k
            if (i >= k - 1)
            {
                // Front always stores maximum element index
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};