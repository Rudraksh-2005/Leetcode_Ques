class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[a] = b;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        for (int i = 1; i < n; i++) {
            if (v[i].first - v[i-1].first <= maxDiff)
                unite(v[i].second, v[i-1].second);
        }

        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }

        return ans;
    }
};