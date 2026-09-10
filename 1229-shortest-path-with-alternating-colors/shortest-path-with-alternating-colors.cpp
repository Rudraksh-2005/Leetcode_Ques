class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
         vector<vector<pair<int,int>>>adj(n);
        vector<int>ans(n,-1);
        for(auto edge:redEdges){
            adj[edge[0]].push_back({edge[1],1});
        }
        for(auto edge:blueEdges){
            adj[edge[0]].push_back({edge[1],0});
        }
        ans[0]=0;
        vector<vector<bool>>visited(n,vector<bool>(2,false));
        queue<pair<int,int>>q;
        visited[0][0]=true;
        visited[0][1]=true;
        q.push({0,1});
        int distance=0;
        q.push({0,0});
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto[node,prevcolor]=q.front();
                q.pop();
                 if (ans[node] == -1) {
                    ans[node] = distance;
                }
                for(auto a:adj[node]){
                    int next=a.first;
                    int color=a.second;
                    if(color==prevcolor) continue;
                    if(!visited[next][color]){
                        visited[next][color]=true;
                        q.push({next,color});
                    }

                }
            }
            distance++;
        }
        return ans;
    }
};