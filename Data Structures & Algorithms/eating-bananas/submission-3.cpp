class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_val=0;
        for (int i=0;i<piles.size();++i)
        {
            max_val=std::max(max_val, piles[i]);
        }

        int low=1;
        int high=max_val;
        while(low<high)
        {
            int mid=(low+high)/2;

            int n_hours=0;
            for (int i=0;i<piles.size();++i)
            {
                n_hours+=std::ceil(piles[i]/static_cast<double>(mid));
            }

            if(n_hours<=h) high=mid;
            else low=mid+1;
        }

        return low;
    }
};
