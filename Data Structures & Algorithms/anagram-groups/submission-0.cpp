class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        std::unordered_set<int> seen;
        
        for (int i=0;i<strs.size();++i)
        {
            if(seen.contains(i)) continue;

            groups.push_back({strs[i]});
            seen.insert(i);

            for (int j=i+1;j<strs.size();++j)
            {
                if(strs[i].size() != strs[j].size()) continue;

                std::vector<int> tab(26, 0);
                for (int k=0;k<strs[i].size();++k)
                {
                    ++tab[strs[i][k] - 'a'];
                    --tab[strs[j][k] - 'a'];
                }

                bool is_ana = true;
                for (int k=0;k<tab.size();++k)
                {
                    if (tab[k] != 0) 
                    {
                        is_ana=false;
                        break;
                    }
                }

                if(is_ana)
                {
                    groups.back().push_back(strs[j]);
                    seen.insert(j);
                }
            }
        }

        return groups;
    }
};
