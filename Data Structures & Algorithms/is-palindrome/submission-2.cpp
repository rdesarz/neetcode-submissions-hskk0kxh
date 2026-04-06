class Solution {
public:
    bool isPalindrome(string s) {
        int p1=0;
        int p2=s.size()-1;
        while(p1<p2)
        {
            while(!(('a'<=s[p1] && s[p1]<='z') || ('A'<=s[p1] && s[p1]<='Z') || ('0'<=s[p1] && s[p1]<='9')))
            {
                ++p1;
            }

            while(!(('a'<=s[p2] && s[p2]<='z') || ('A'<=s[p2] && s[p2]<='Z') || ('0'<=s[p2] && s[p2]<='9')))
            {
                --p2;
            }

            if(p1>=p2)
            {
                return true;
            }

            // Transform to lower case for comparison
            char s1 = s[p1];
            if('A'<=s1 && s1<='Z')
            {
                s1 += ('a' - 'A');
            }

            char s2 = s[p2];
            if('A'<=s2 && s2<='Z')
            {
                s2 += ('a' - 'A');
            }

            if(s1 != s2)
            {
                return false;
            }

            ++p1;
            --p2;
        }

        return true;
    }
};
