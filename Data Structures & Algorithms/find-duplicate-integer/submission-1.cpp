class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();++i)
        {
            if(nums[std::abs(nums[i])-1] < 0) return std::abs(nums[i]);

            nums[std::abs(nums[i])-1] *= -1;
        }

        return 0;
    }
};
