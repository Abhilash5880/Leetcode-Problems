class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        // 🔹 Edge case: no meetings → no rooms needed
        if (intervals.empty()) return 0;

        // 🔹 Separate start and end times
        vector<int> start, end;

        for (auto& it : intervals) {
            start.push_back(it[0]);  // collect all start times
            end.push_back(it[1]);    // collect all end times
        }

        // 🔹 Sort both arrays to simulate timeline
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        // 🔹 Two pointers for start[] and end[]
        int i = 0, j = 0;

        // 🔹 Track current active meetings and maximum overlap
        int currentRooms = 0, maxRooms = 0;

        int n = intervals.size();

        // 🔹 Sweep through all start times
        while (i < n) {

            // 🔸 If next meeting starts BEFORE earliest one ends
            if (start[i] < end[j]) {
                
                // → need a new room
                currentRooms++;

                // → update max rooms required
                maxRooms = max(maxRooms, currentRooms);

                i++;  // move to next start time
            }
            else {
                // 🔸 A meeting has ended BEFORE (or exactly when) next starts
                
                // → free a room
                currentRooms--;

                j++;  // move to next end time
            }
        }

        // 🔹 maxRooms = peak number of overlapping meetings
        return maxRooms;
    }
};