class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int,int> tab;

        int max_len = 0;
        for (int k=0;k<nums.size();++k)
        {
            if (tab.contains(nums[k])) continue;

            int i=0;
            if(tab.contains(nums[k]+1))
            {
                i=tab[nums[k]+1];
            }

            int j=0;
            if(tab.contains(nums[k]-1))
            {
                j=tab[nums[k]-1];
            }

            tab[nums[k]] = 1 + i + j;
            tab[nums[k]+i] = 1 + i + j;
            tab[nums[k]-j] = 1 + i + j;
            max_len = std::max(max_len, 1 + i + j);
        }

        return max_len;
    }
};
