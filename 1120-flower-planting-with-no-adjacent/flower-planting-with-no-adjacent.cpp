class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> adj(n + 1);
        for (auto it : paths) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int> color(n + 1, 0);


        for (int i = 1; i <= n; i++) {
             vector<bool> used(5, false);

            for (int neighbour : adj[i]) {
                if (color[neighbour] != 0) {
                    used[color[neighbour]] = true;
                }
            }
            for (int c = 1; c <= 4; c++) {
                if (!used[c]) {
                    color[i] = c;
                    break;
                }
            }
        }

        vector<int> ans;

        for (int i = 1; i <= n; i++) {
            ans.push_back(color[i]);
        }

        return ans;
    }
};