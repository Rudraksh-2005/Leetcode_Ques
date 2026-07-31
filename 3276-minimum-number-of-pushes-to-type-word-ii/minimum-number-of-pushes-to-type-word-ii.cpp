class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;

        for(int i=0;i<word.size();i++){
            mpp[word[i]]++;
        }

        vector<pair<char,int>>freq;
        for(auto it:mpp){
            freq.push_back({it.first,it.second});
        }

        sort(freq.begin(),freq.end(),[](const auto a,const auto b){
            return a.second>b.second;
        });


        int ans=0;
        for(int i=0;i<freq.size();i++){
            ans+=freq[i].second*((i/8)+1);
        }

        return ans;
    }
};