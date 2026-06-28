class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int cnt=1;
            if(arr[0]!=1)arr[0]=1;
            for(int i=1;i<arr.size();i++){
                if(abs(arr[i]-arr[i-1])<=1){
                    cnt=max(cnt,max(arr[i],arr[i-1]));

                }
                else{
                    cnt++;
                    arr[i]=cnt;
                }
            }
        


        return cnt;
    }
};