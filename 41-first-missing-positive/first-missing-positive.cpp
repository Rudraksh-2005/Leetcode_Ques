class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int cnt=1;
        int i=0;
        int n=nums.size();


        while(i<n){
            if(nums[i]<=0){
                i++;
                continue;
            }
            if(i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            else{
                if(nums[i]==cnt){
                    i++;
                    cnt++;
                }
                
                else{
                    break;
                }
            }
        }

        return cnt;
    }
};