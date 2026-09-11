class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {
        
        int n = friends.size();

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(id);
        vis[id] = 1;

        int currLevel = 0;

        while (!q.empty() && currLevel < level) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                int node = q.front();
                q.pop();

                for (int neighbour : friends[node]) {

                    if (!vis[neighbour]) {
                        vis[neighbour] = 1;
                        q.push(neighbour);
                    }
                }
            }

            currLevel++;
        }

        unordered_map<string, int> mpp;

        while (!q.empty()) {

            int person = q.front();
            q.pop();

            for (string video : watchedVideos[person]) {
                mpp[video]++;
            }
        }

        vector<pair<string, int>> videos;

        for (auto& p : mpp) {
            videos.push_back(p);
        }

        sort(videos.begin(), videos.end(),
            [](auto& a, auto& b) {

                if (a.second == b.second) {
                    return a.first < b.first;
                }

                return a.second < b.second;
            }
        );

        vector<string> ans;

        for (auto& p : videos) {
            ans.push_back(p.first);
        }

        return ans;
    }
};