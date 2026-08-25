class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        int num=k;
        

        while(mpp.find(num)!=mpp.end()){
            num+=k;
        }

        return num;

    }
};