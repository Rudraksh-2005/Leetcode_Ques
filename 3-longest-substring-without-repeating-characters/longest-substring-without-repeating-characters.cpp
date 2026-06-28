class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        unordered_map<char,int>mpp;
        int l=0;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])==0 || mpp[s[i]]<l){
                mpp[s[i]]=i;
                maxi=max(maxi,i-l+1);
            }
            else{
                l=mpp[s[i]]+1;
                mpp[s[i]]=i;
            }
        }

        return maxi;
    }
};