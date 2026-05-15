class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int n = position.size();

        // Store {position, speed}
        vector<pair<int,int>> cars;

        for(int i = 0; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        // Sort based on position
        sort(cars.begin(), cars.end());

        stack<double> st;

        // Traverse from closest to target -> backward
        for(int i = n - 1; i >= 0; i--)
        {
            double time = (double)(target - cars[i].first) / cars[i].second;

            // New independent fleet
            if(st.empty() || time > st.top())
            {
                st.push(time); //only pushing the higher values and not caring for the lesser ones
            }

            // Else:
            // current car merges into fleet ahead
        }

        return st.size();
    }
};