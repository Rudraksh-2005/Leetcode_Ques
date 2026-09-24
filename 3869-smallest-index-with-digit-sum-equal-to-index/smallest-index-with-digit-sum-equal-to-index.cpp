class Solution {
public:
    int f(int s){
        int sum=0;

        while(s>0){
            sum+=s%10;
            s/=10;
        }


        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;

        for(int i=0;i<n;i++){
            if(f(nums[i])==i){
                ans=i;
                break;
            }
        }

        return ans;
    }
};