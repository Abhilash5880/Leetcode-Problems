class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //adjancency list
        vector<vector<int>> adj(numCourses);

        //In-degree vector
        vector<int> indegree(numCourses, 0);

        //build graph

        for(auto& preq:prerequisites)
        {
            int course = preq[0];
            int prereq = preq[1];
            
            adj[prereq].push_back(course);
            indegree[course]++;        
         
        }

        //queue for all nodes with indegree 0
        queue<int> q;

        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for(int neighbor : adj[curr])
            {
                indegree[neighbor]--;

                if(indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        // Cycle Detection
        if(ans.size() != numCourses)
        {
            return {};
        }

        return ans;
    }
};