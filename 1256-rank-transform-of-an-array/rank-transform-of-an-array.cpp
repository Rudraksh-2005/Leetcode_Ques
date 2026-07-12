class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
       
        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }

        vector<pair<int,vector<int>>>nums;
        for(auto it:mpp){
            nums.push_back({it.first,it.second});
        }

        sort(nums.begin(),nums.end());

        vector<int>ans(n,0);


        for(int i=0;i<nums.size();i++){
            int a=nums[i].first;
            vector<int>b=nums[i].second;
            for(int j=0;j<b.size();j++){
                ans[b[j]]=i+1;
            }
        }


        return ans;

        
    }
};