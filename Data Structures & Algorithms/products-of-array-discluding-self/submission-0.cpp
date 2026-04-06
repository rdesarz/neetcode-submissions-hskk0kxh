class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prod_forward(nums.size());
        std::vector<int> prod_backward(nums.size());

        prod_forward[0] = nums[0];
        for(int i=1;i<nums.size();++i)
        {
            prod_forward[i] = nums[i] * prod_forward[i-1];
        }

        prod_backward.back() = nums.back();
        for(int i=1;i<nums.size();++i)
        {
            prod_backward[nums.size()-1-i] = nums[nums.size()-i-1] * prod_backward[nums.size()-i];
        }

        std::vector<int> output(nums.size());

        output[0] = prod_backward[1];
        for(int i=1;i<nums.size()-1;++i)
        {
            output[i] = prod_forward[i-1] * prod_backward[i+1];
        }
        output.back() = prod_forward[nums.size()-2];

        return output;
    }
};
