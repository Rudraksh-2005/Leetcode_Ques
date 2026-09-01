class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, -1);

        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] != -1)
                continue;

            int node = i;
            int step = 0;

            unordered_map<int, int> path;

            while (node != -1 && visited[node] == -1) {
                visited[node] = i;
                path[node] = step++;

                node = edges[node];
            }

            if (node != -1 && visited[node] == i) {
                ans = max(ans, step - path[node]);
            }
        }

        return ans;
    }
};