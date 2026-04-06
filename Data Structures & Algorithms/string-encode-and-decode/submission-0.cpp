class Solution {
public:

    string encode(vector<string>& strs) {
        std::stringstream ss;
        for (int i=0;i<strs.size();++i)
        {
            int len = strs[i].size();
            ss << "#" << len << "#" << strs[i];
        }

        return ss.str();
    }

    vector<string> decode(string s) {
        std::vector<std::string> output;
        int i=0;
        int current_len=0;
        while (i<s.size())
        {
            output.push_back({});
            if (s[i] == '#')
            {
                ++i;
                std::string len;
                while (s[i] != '#')
                {
                    len.push_back(s[i]);
                    ++i;
                }

                current_len=std::stoi(len);
                ++i;
            }

            for(int k=0;k<current_len;++k)
            {
                output.back().push_back(s[i+k]);
            }
            i+=current_len;
        }

        return output;
    }
};
