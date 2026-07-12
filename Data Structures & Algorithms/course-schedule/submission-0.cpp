class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        queue<int> q;
        int cnt = 0;

        for (auto& i : prerequisites) {
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
            indeg[u]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                cnt++;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& i : adj[u]) {
                indeg[i]--;
                if (indeg[i] == 0) {
                    q.push(i);
                    cnt++;
                }
            }
        }
        return (cnt == numCourses) ? true : false;
    }
};
