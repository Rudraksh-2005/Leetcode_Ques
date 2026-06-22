class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();

        unordered_map<char,int>mpp;

        for(int i=0;i<n;i++){
            mpp[text[i]]++;
        }


        int mini=INT_MAX;;
        string b="balloon";

        for(int i=0;i<b.length();i++){
            if(mpp['b']>0 && mpp['a']>0 && mpp['l']>1 && mpp['o']>1 && mpp['n']>0){
                if(b[i]=='l' || b[i]=='o'){
                    mini=min(mini, mpp[b[i]]/2);
                }
                else{
                    mini=min(mini, mpp[b[i]]);
                }
                
            }
            else{
                return 0;
            }
           
        }


        return mini;
    }
};