class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        vector<bool> vis(n, false);
        for (const auto& ed:edges)
        {
            adj [ed[1]].push_back(ed[0]);
            adj[ed[0]].push_back(ed[1]);
        }

        int compo=0;
        for (int node=0; node<n; ++node)
        {
            if(!vis[node])
            {
                dfs(adj, vis, node);
                compo++;
            }
        }
        return compo;


    }
private:
    void dfs(const vector<vector<int>>& adj, vector<bool>&vis, int node)
    {
        vis[node]=true;
        for (int next:adj[node])
        {
            if(!vis[next])
            {
                dfs(adj, vis, next);
            }
        }
    }
    
};
