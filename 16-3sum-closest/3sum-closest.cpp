class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int mini=INT_MAX;
        int ans=0;


        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(mini>(abs(target-sum))){
                        mini=abs(target-sum);
                        ans=sum;
                    }
                }
            }
        }

        return ans;
    }
};