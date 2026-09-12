class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
         int n=nums.size();
        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        int ans=0;

        for(auto it:mpp){
            vector<int>a=it.second;
            if(a.size()>=3){
                int b=a[1]-a[0];
                int cnt=0;
                for(int i=1;i<a.size();i++){
                    if(a[i]-a[i-1]==b){
                        cnt++;
                    }

                }

                if(cnt==a.size()-1)ans++;
                
            }
        }

        return ans;
    }
};