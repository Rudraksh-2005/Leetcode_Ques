class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        vector<int>hasharr(3,0);
        int cnt=0;
        while(r<n){
            hasharr[s[r]-'a']++;
            while(hasharr[0]>0 && hasharr[1]>0 && hasharr[2]>0){
                cnt+=(n-r);
                hasharr[s[l]-'a']--;
                l++;
            }
            r++;
        }

        return cnt;
    }
};