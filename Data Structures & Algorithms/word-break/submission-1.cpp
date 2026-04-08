class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<int> dp(s.size() + 1, -1);

        std::deque<int> q;
        dp[0] = 1;
        q.push_back(0);
        while (!q.empty())
        {
            auto i = q.front();
            q.pop_front();

            if (i == s.size())
            {
                return true;
            }

            for (auto& word : wordDict)
            {
                int len = word.size();
                if (i + len <= dp.size() && dp[i + len] == -1 && s.substr(i, len) == word)
                {
                    q.push_back(i + len);
                    dp[i + len] = 1;
                }
            }
        }

        return false;
    }
};
