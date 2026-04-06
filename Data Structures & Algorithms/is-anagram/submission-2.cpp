class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        std::vector<int> tab(26, 0);

        for (int i=0;i<s.size();++i)
        {
            ++tab[s[i]-'a'];
            --tab[t[i]-'a'];
        }

        for(int i=0;i<tab.size();++i)
        {
            if(tab[i]) return false;
        }

        return true;
    }
};
