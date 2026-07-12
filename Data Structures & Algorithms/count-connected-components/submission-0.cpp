class Solution {
public:

    void solve(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (auto& i : adj[node]) {
            if (!vis[i]) {
                solve(i, adj, vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        int ans = 0;

        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                solve(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};
