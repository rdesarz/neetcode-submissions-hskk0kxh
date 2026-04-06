class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for(int i=0;i<nums.size();++i)
        {
            ++count[nums[i]];
        }

        std::vector<std::vector<int>> bucket(nums.size()+1);
        for(const auto&[key,val]:count)
        {
            bucket[val].push_back(key);
        }

        vector<int> out;
        for(int j=0;j<bucket.size();++j)
        {
            for(int i=0;i<bucket[bucket.size()-1-j].size();++i)
            {
                out.push_back(bucket[bucket.size()-1-j][i]);
                --k;
                if (k==0)
                {
                    return out;
                }
            }
        }

        return out;
    }
};