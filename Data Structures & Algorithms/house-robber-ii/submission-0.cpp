class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        std::vector<int> dp1(nums.size()-1, 0);
        dp1[0] = nums[0];
        dp1[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < nums.size()-1; ++i) {
            dp1[i] = std::max(dp1[i - 1], nums[i] + dp1[i - 2]);
        }

        std::vector<int> dp2(nums.size()-1, 0);
        dp2[0] = nums[1];
        dp2[1] = std::max(nums[1], nums[2]);

        for (int i = 2; i < nums.size(); ++i) {
            dp2[i] = std::max(dp2[i - 1], nums[i+1] + dp2[i - 2]);
        }

        return std::max(dp1.back(), dp2.back());
    }
};
