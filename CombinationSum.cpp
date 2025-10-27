class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        backtrack(candidates, target, 0, cur, res);
        return res;
    }
private:
    void backtrack(const vector<int>& candidates, int remain, int start,
                   vector<int>& cur, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i) {
            int val = candidates[i];
            if (val > remain) break;          
            cur.push_back(val);
            backtrack(candidates, remain - val, i, cur, res);
            cur.pop_back();
        }
    }
};