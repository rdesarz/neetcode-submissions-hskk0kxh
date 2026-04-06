class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::vector<int>> tab;

        for (int i=0;i<nums.size();++i)
        {
            tab[target-nums[i]].push_back(i);
        }

        for (int i=0;i<nums.size();++i)
        {
            if(tab.contains(nums[i]))
            {
                if (tab[nums[i]][0] == i && tab[nums[i]].size() == 1) continue;

                if (tab[nums[i]][0] == i && tab[nums[i]].size() == 2) 
                {
                    return i < tab[nums[i]][1] ? std::vector{i, tab[nums[i]][1]} : std::vector{tab[nums[i]][1], i};
                }

                return i < tab[nums[i]][0] ? std::vector{i, tab[nums[i]][0]} : std::vector{tab[nums[i]][0], i};
            }
        }

        return {};
    }
};
