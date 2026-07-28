class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";
        string supp = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                for (int j = 0; j < freq[i] / 2; j++) {
                    ans += (i + 'a');
                }
            }
        }

        supp = ans;
        reverse(supp.begin(), supp.end());

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                ans += (i + 'a');
                break;
            }
        }

        ans += supp;

        return ans;
    }
};