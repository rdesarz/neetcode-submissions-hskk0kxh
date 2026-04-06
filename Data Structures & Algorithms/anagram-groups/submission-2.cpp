class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (int i=0;i<strs.size();++i)
        {
            std::vector<int> tab(26, 0);
            for (int k=0;k<strs[i].size();++k)
            {
                ++tab[strs[i][k] - 'a'];
            }

            std::stringstream ss;
            for (int k=0;k<tab.size();++k)
            {
                ss << tab[k] << "#";
            }

            groups[ss.str()].push_back(strs[i]);
        }

        vector<vector<string>> output;
        for(const auto& group : groups)
        {
            output.push_back(group.second);
        }

        return output;
    }
};
