class Solution {
public:
    bool check(int i,int t){
        int num=1;
        while(i>0){
            num*=i%10;
            i/=10;
        }
        return num%t==0;
    }
    int smallestNumber(int n, int t) {
        int ans=0;

        for(int i=n;i<=100;i++){
            if(check(i,t)){
                ans=i;
                break;
            }
        }

        return ans;
    }
};