class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> tab;
        for (int i=0;i<nums.size();++i) ++tab[nums[i]];

        vector<vector<int>> bucket(nums.size()+1);
        for (const auto& elem : tab)
        {
            bucket[elem.second].push_back(elem.first);
        }

        vector<int> output; 
        int count=k;
        for (auto it=bucket.rbegin();it!=bucket.rend();++it)
        {
            for (auto elem : *(it))
            {
                output.push_back(elem);
                --k;
            }
            if (k==0) break;
        }

        return output;
    }
};
