class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // 🔹 Step 1: Sort intervals
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        // 🔹 Step 2: Start with first interval
        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            // 🔹 Case 1: Overlapping
            if (intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            }
            // 🔹 Case 2: No overlap
            else {
                res.push_back(current);
                current = intervals[i];
            }
        }

        // 🔹 Step 3: Add last interval
        res.push_back(current);

        return res;
    }
};