class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int,int>> s;

        int max_val=0;
        for(int i=0;i<heights.size();++i)
        {
            int start_idx=i;
            while(!s.empty() && s.top().first > heights[i])
            {
                max_val = std::max(max_val, (i-s.top().second) * s.top().first);
                start_idx = s.top().second;
                s.pop(); 
            }

            s.push({heights[i], start_idx});
        }

        int idx = heights.size()-1;
        while(!s.empty())
        {
            max_val = std::max(max_val, (idx-s.top().second+1) * s.top().first);
            s.pop();
        }

        return max_val;
    }
};
