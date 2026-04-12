class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;  
        // res[i] = smallest possible ending value of an increasing subsequence of length (i+1)

        for (int n : nums) {
            // Case 1: extend the longest subsequence
            if (res.empty() || res.back() < n) {
                res.push_back(n);
                // n is greater than all endings → new longer subsequence possible
            } else {
                // Case 2: replace to improve future possibilities
                int idx = binarySearch(res, n);
                res[idx] = n;
                // Replace first element >= n
                // This keeps length same but makes ending smaller (more flexible)
            }
        }

        return res.size();  
        // Length of LIS = number of valid "length slots" maintained
    }

private:
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        // Goal: find first index where arr[idx] >= target
        // (i.e., lower_bound behavior)

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == target) {
                return mid;
                // Exact match → valid replacement position
            } 
            else if (arr[mid] > target) {
                right = mid - 1;
                // Move left to find smaller valid position
            } 
            else {
                left = mid + 1;
                // Move right since target is larger
            }
        }

        return left;
        // Insertion point:
        // first index where element >= target
    }    
};