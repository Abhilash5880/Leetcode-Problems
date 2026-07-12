class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        if(digits.empty())
        {
            return ans;
        }

        string mapping[10] = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        string output = "";

        solve(mapping, 0, ans, digits, output);

        return ans;
    }

private:
    void solve(string mapping[],
               int i,
               vector<string>& ans,
               string& digits,
               string& output)
    {
        if(i >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        int num = digits[i] - '0';

        string value = mapping[num];

        for(int j = 0; j < value.length(); j++)
        {
            output.push_back(value[j]);

            solve(mapping, i + 1, ans, digits, output);

            output.pop_back();
        }
    }
};