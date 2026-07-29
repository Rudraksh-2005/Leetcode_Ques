class Solution {
private:
    void assignFlower(
        int garden,
        vector<int>&partition,
        const vector<vector<int>>&adjList
    ){
        queue<int>q;
        partition[garden] = 1;
        q.push(garden);
        while(!q.empty()){
            int currGarden = q.front();
            q.pop();

            for(auto&adjacentGarden:adjList[currGarden]){
                bool isVisited = (partition[adjacentGarden]!=-1);
                bool hasSameColor = (partition[adjacentGarden] == partition[currGarden]);

                if(!isVisited){
                    partition[adjacentGarden] = (partition[currGarden]%4) +1;
                    q.push(adjacentGarden);
                    continue;
                }

                if(hasSameColor){
                    partition[adjacentGarden] = (partition[adjacentGarden])%4 +1;
                }
            }
        }

        return;
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adjList(n);
        for(auto&path:paths){
            int u = path[0]-1;
            int v = path[1]-1;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int>partition(n,-1);
        for(int i=0;i<n;++i){
            if(partition[i]!=-1) continue;
            
            assignFlower(i,partition,adjList);
        }

        return partition;
    }
};