class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();

        // Initialize answer array with 0
        vector<int> answer(n, 0);

        // Stack stores INDICES
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            // Current temperature resolves previous colder days
            while(!st.empty() &&
                  temperatures[i] > temperatures[st.top()])
            {
                int prevIndex = st.top();
                st.pop();

                answer[prevIndex] = i - prevIndex;
            }

            // Current unresolved day waits in stack
            st.push(i);
        }

        return answer;
    }
};