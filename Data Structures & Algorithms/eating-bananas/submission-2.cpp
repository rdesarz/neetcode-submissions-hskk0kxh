class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = 0;
        for(int i=0;i<piles.size();++i) max_pile = std::max(max_pile, piles[i]);

        int k=max_pile;
        int r=1;
        int l=max_pile;
        while(r<=l)
        {
            int mid=(r+l)/2;
            
            int n_hours=0;
            for(int i=0;i<piles.size();++i) 
                n_hours += static_cast<int>(std::ceil(static_cast<double>(piles[i]) / static_cast<double>(mid)));

            if(n_hours > h)
            {
                r=mid+1;
            }
            else
            {
                l=mid-1;
                k=mid;
            }
        }

        return k;
    }
};
