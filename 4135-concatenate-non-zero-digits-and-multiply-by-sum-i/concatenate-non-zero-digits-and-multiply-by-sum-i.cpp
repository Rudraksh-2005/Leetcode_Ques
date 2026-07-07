class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        stack<int>st;

        while(n>0){
            int m=n%10;

            if(m>0)st.push(m);
            n=n/10;
        }
        long long num=0;
        long long sum=0;
        while(!st.empty()){
            num=num*10+st.top();
            sum+=st.top();
            st.pop();
        }

        ans=sum* num;

        return ans;

    }
};