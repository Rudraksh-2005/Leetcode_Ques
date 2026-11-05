class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1=arr1.size();
        int n2=arr2.size();

        int ans=0;

        for(int i=0;i<n1;i++){
            int num=arr1[i];
            int cnt=0;
            for(int j=0;j<n2;j++){
                
                if(abs(num-arr2[j])>d){
                    cnt++;
                }
            }

            if(cnt==n2){
                ans++;
            }
            
        }

        return ans;
    }
};