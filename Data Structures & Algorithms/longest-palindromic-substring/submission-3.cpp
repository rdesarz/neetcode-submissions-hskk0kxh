class Solution {
public:
    string longestPalindrome(string s) {
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));

        int i_out=0;
        int j_out=1;
        // Fill the vector for one character strings
        for(int i=0;i<s.size();++i)
        {
            dp[i][i] = true;
        }

        // Fill the vector for two character strings
        for(int i=0;i<s.size()-1;++i)
        {
            dp[i][i+1] = s[i] == s[i+1];
            if (dp[i][i+1])
            {
                i_out=i;
                j_out=2;
            }
        }

        // Now apply DP principle
        for (int j=2;j<s.size();++j)
        {
            for (int i=0;i<s.size()-j;++i)
            {
                dp[i][i+j] = (s[i] == s[i+j]) && dp[i+1][i+j-1];
                if (dp[i][i+j]) 
                {
                    i_out=i;
                    j_out=j+1;
                }
            }
        }

        return s.substr(i_out, j_out);
    }
};
