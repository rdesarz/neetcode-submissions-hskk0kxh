class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> out;
        for(int i=0;i<nums.size()-2;++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target=-nums[i];
            int p1=i+1;
            int p2=nums.size()-1;
            while(p1<p2)
            {
                int sum=nums[p1]+nums[p2];
                if(sum==target)
                {
                    out.push_back({nums[i], nums[p1], nums[p2]});
                    
                    int a=nums[p1];
                    int b=nums[p2];
                    while(p1<p2 && a==nums[p1]) ++p1;
                    while(p1<p2 && b==nums[p2]) --p2;
                }
                else if(sum>target) --p2;
                else ++p1;
            }
        }

        return out;
    }
};
