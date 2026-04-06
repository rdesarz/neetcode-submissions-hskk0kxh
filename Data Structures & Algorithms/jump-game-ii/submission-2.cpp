class Solution {
public:
    int minJumps(const std::vector<int>& nums, std::vector<int>& dp, int i)
    {
        if (dp[i] != -1) {
            return dp[i];
        }

        int best = std::numeric_limits<int>::max();

        for (int j = 1; j <= nums[i]; ++j) {
            if (i + j < nums.size()) {
                int result = minJumps(nums, dp, i + j);
                if (result != std::numeric_limits<int>::max())
                {
                    best = std::min(best, 1 + result);
                }
            }
        }

        dp[i] = best;
        return best;
    }

    int jump(vector<int>& nums) {
        std::vector<int> dp(nums.size(), -1);
        dp.back() = 0;
        return minJumps(nums, dp, 0);
    }
};