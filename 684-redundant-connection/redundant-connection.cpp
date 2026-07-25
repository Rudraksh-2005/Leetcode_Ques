class DSU{
    private:
        vector<int> parent;
        vector<int> size;

    public:
        DSU(int n)
        {
            parent.resize(n+1);
            size.resize(n+1);

            for(int i = 1; i<=n; i++)
            {
                parent[i]=i;
            }

              for(int i = 1; i<=n; i++)
            {
                size[i]=1;
            }
        }

        int find(int x)
        {
            if(parent[x]==x) return x;

            return parent[x] = find(parent[x]);
        }

        void Union(int a, int b)
        {
            int rootA = find(a);
            int rootB = find(b);

            if(rootA==rootB) return;

            if(size[rootA]<size[rootB])
            {
                parent[rootA]=rootB;
                size[rootB]+= size[rootA];
            }

            else
            {
                parent[rootB]=rootA;
                size[rootA]=size[rootB];
            }
        }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(int i=0; i<n; i++)
        {
                int a = edges[i][0];
                int b = edges[i][1];

                int rootA = dsu.find(a);
                int rootB = dsu.find(b);

                if(rootA==rootB)
                {
                    return {a,b};
                }
                dsu.Union(a,b);
        }
        return {};
    }
};