class Solution {
public:
    int countSubstrings(string s) {
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));

        int counter = 0;
        for(int i=0;i<s.size();++i)
        {
            dp[i][i] = true;
            ++counter;
        }

        for(int i=0;i<s.size();++i)
        {
            if (s[i] == s[i+1]) 
            {
                dp[i][i+1] = true;
                ++counter;
            }
        }

        for(int j=2;j<s.size();++j)
        {
            for(int i=0;i<s.size()-j;++i)
            {
                if (s[i] == s[i+j] && dp[i+1][i+j-1]) 
                {
                    dp[i][i+j] = true;
                    ++counter;
                }
            }
        }

        return counter;
    }
};
