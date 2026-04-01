class Solution {
private:
    bool dfs(int node, int parent, const vector<vector<int>>& adj, vector<bool>& vis)
    {
        vis[node] = true;

        for (int next : adj[node]) {
            if (!vis[next]) 
            {
                if (dfs(next, node, adj, vis)) return true;
            }
            else if (next != parent) {
                return true;
            }
        }
    
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for(const auto& ed : edges)
        {
            adj[ed[1]].push_back(ed[0]);
            adj[ed[0]].push_back(ed[1]);
        }
        vector<bool> vis(n, false);

        if (dfs(0, -1, adj, vis)) return false;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i]) return false;
        }
        return true;
    }
};