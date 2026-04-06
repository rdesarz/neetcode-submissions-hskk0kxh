class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1=0;
        int p2=heights.size()-1;
        int max_water = 0;
        while(p1<p2)
        {
            max_water = std::max(max_water, (p2-p1)*std::min(heights[p1], heights[p2]));

            if(heights[p1]<heights[p2]) ++p1;
            else --p2;
        }

        return max_water;
    }
};
