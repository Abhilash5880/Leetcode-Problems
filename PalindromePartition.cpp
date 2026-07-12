class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
        
    }
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& res)
    //if we have reached the end of the string, add the current partition to the list
    {
        if(start==s.length())
        {
            res.push_back(path);
            return;
        }

        for(int end=start+1; end<=s.length(); ++end)
        {
            if(isPalin(s,start,end-1))
            {
                path.push_back(s.substr(start, end-start));
                backtrack(s,end,path,res);
                path.pop_back(); //remove last added element to backtrack
            }
        }
    }
    bool isPalin(const string& s, int left, int right)
    {
        //check elements are same till mid point (left<right)
        while(left<right)
        {
            if(s[left++]!=s[right--])
            {
                return false;
            }
        }
        return true;
    }
};