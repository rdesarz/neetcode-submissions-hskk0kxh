class Solution {
public:
    int findMin(vector<int> &nums) {
        int r=0;
        int l=nums.size();
        while(r<l)
        {
            int mid=(r+l)/2;
            if (mid == 0 || nums[mid] < nums[mid-1]) return nums[mid];
            else if (nums[mid] > nums[0]) r=mid+1;
            else l=mid;
        }

        return nums[0];
    }
};
