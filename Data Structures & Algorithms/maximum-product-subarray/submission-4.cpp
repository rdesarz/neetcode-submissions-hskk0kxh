class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        int max_prod = nums[0];
        int min_prod = nums[0];
        int best=nums[0];

        for (int i=1;i<nums.size();++i)
        {
            int a = nums[i];
            int b = min_prod * a;
            int c = max_prod * a;

            max_prod = std::max({a, b, c});
            min_prod = std::min({a, b, c});

            best = std::max(max_prod, best);
        }

        return best;
    }
};
