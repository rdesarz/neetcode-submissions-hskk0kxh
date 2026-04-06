class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;

        if (nums[0] == 0) return false;

        int n_jump = nums[0];
        for(int i=1;i<nums.size() - 1;++i)
        {
            n_jump = std::max(--n_jump, nums[i]);
            if(n_jump <= 0) return false;
        }

        return true;
    }
};
