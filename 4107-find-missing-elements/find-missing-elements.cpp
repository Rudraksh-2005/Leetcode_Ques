class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
         vector<int>ans;
        sort(nums.begin(),nums.end());
        int maxi=nums[nums.size()-1];
        int mini=nums[0];
        int p=0;
        for(int i=mini;i<maxi;i++){
            if(i==nums[p])p++;
            else if(i!=nums[p]){
                ans.push_back(i);
            }
            
        }
        
        

        return ans;
    }
};