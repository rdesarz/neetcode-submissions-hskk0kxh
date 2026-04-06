class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        std::vector<int> tab_s(26, 0);
        std::vector<int> tab_t(26, 0);

        for (int i=0;i<s.size();++i)
        {
            ++tab_s[s[i]-'a'];
            ++tab_t[t[i]-'a'];
        }

        for(int i=0;i<tab_s.size();++i)
        {
            if(tab_t[i] != tab_s[i]) return false;
        }

        return true;
    }
};
