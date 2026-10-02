class Solution {
public:
    void f(int n,vector<string>&ans,int open, int close,string a){
        if(a.size()==2*n){
            ans.push_back(a);
            return;
        }

        if(open<n){
            f(n,ans,open+1,close,a+"(");
        }
        if(close<open){
            f(n,ans,open,close+1,a+")");
        }


    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        f(n,ans,0,0,"");

        return ans;
    }
};