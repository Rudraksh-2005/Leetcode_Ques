class Solution {
public:
    int maximumLength(vector<int>& nums) {
           unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            ans = max(ans, freq[1]);
            if (ans % 2 == 0)
                ans--;
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1)
                continue;

            long long curr = x;
            int len = 0;

            while (freq.count(curr) && freq[curr] >= 2) {
                len += 2;

                // Prevent overflow
                if (curr > 1e9)
                    break;

                curr = curr * curr;
            }

            if (freq.count(curr)) {
                if (freq[curr] == 1)
                    len++;
                else
                    len--;
            } else {
                len--;
            }

            ans = max(ans, len);
        }

        return ans;

    }
};