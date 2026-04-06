class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> output_map;
        for(int i=0;i<strs.size();++i)
        {
            vector<int> tab(26, 0);
            for(int j=0;j<strs[i].size();++j)
            {
                ++tab[strs[i][j]-'a'];
            }

            string hash;
            for(int j=0;j<tab.size();++j)
            {
                hash.append(std::to_string(tab[j]));
                hash.push_back('#');
            }

            output_map[hash].push_back(strs[i]);
        }

        vector<vector<string>> output;
        for(auto& [key, val] : output_map)
        {
            output.push_back({});
            for(auto& elem : val)
            {
                output.back().push_back(elem);
            }
        }

        return output;
    }
};
