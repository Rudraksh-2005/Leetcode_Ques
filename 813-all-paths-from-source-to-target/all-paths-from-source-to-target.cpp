class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int>&s, vector<int>&vis){
        int n=graph.size();
        if(node==n-1){
            
            ans.push_back(s);
            return;
        }

        vis[node]=1;

        for(auto it:graph[node]){
            if(!vis[it]){
                s.push_back(it);
                dfs(it,graph,ans,s,vis);
                vis[it]=0;
                s.pop_back();

            }
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>s;

        int n=graph.size();

        s.push_back(0);
        vector<int>vis(n,0);
        dfs(0,graph,ans,s,vis);


        return ans;

    }
};