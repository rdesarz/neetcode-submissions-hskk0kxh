class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i];

            int a = x;
            int b = x * maxEnding;
            int c = x * minEnding;

            maxEnding = max({a, b, c});
            minEnding = min({a, b, c});

            ans = max(ans, maxEnding);
        }

        return ans;
    }
};