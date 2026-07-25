class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;

        while(n>0){
            int sum=n%10;
            n=n/10;
            ans.push_back(sum);
        }

        sort(ans.begin(),ans.end());

        int m=ans.size();

        int sol=ans[m-1]*ans[m-2];

        return sol;
    }
};