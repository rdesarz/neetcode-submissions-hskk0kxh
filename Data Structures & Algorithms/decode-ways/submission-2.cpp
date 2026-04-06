class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 1) return (s.back() != '0');

        std::vector<int> dp(s.size(), 0);
        dp[dp.size()-1] = (s.back() != '0');

        int i = dp.size()-2;
        if (s[i] == '0') 
        {
            dp[i] = 0;
        }
        else if (s[i] == '1')
        {
            dp[i] = 1 + dp[i+1];
        }
        else if (s[i] == '2' && '0' <= s[i+1] && s[i+1] <= '6')
        {
            dp[i] = 1 + dp[i+1];
        }
        else
        {
            dp[i] = dp[i+1];
        }


        for (int i=s.size()-3;i>=0;--i)
        {
            if (s[i] == '0') 
            {
                dp[i] = 0;
            }
            else if (s[i] == '1')
            {
                dp[i] = dp[i+1] + dp[i+2];
            }
            else if (s[i] == '2' && '0' <= s[i+1] && s[i+1] <= '6')
            {
                dp[i] = dp[i+1] + dp[i+2];
            }
            else
            {
                dp[i] = dp[i+1];
            }
        }

        return dp[0];
    }
};
