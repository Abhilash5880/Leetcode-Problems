class Solution {
public:

    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> st;

        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() &&
                  heights[i] < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();

                int right = i;

                int left;

                if(st.empty())
                    left = -1;
                else
                    left = st.top();

                int width = right - left - 1;

                maxArea =
                    max(maxArea, height * width);
            }

            st.push(i);
        }

        while(!st.empty())
        {
            int height = heights[st.top()];
            st.pop();

            int right = n;

            int left;

            if(st.empty())
                left = -1;
            else
                left = st.top();

            int width = right - left - 1;

            maxArea =
                max(maxArea, height * width);
        }

        return maxArea;
    }
};