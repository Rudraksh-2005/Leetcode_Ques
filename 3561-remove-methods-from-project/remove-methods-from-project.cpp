class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto &it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

        // Mark all suspicious methods reachable from k
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(k);
        vis[k] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nxt : adj[node]) {
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
        }

        // If any non-suspicious method invokes a suspicious one,
        // then no methods can be removed.
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                for (int nxt : adj[i]) {
                    if (vis[nxt]) {
                        vector<int> ans;
                        for (int j = 0; j < n; j++)
                            ans.push_back(j);
                        return ans;
                    }
                }
            }
        }

        // Otherwise, return all non-suspicious methods.
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};