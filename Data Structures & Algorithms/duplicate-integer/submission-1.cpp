class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> tab;

        for (int i=0;i<nums.size();++i)
        {
            if(tab.contains(nums[i])) return true;
            tab.insert(nums[i]);
        }

        return false;
    }
};