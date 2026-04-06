class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> tab;

        for (int i=0;i<nums.size();++i)
        {
            if(tab.contains(target - nums[i])) return {tab[target - nums[i]], i};

            tab[nums[i]] = i;
        }

        return {};
    }
};
