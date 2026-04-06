class Solution {
public:
    int trap(vector<int>& height) {
        // forward pass
        std::vector<int> forward_max_h(height.size(), 0);
        forward_max_h[0] = height[0];
        for(int i=1;i<height.size();++i)
        {
            forward_max_h[i] = std::max(forward_max_h[i-1], height[i]);
        }

        // backward pass
        std::vector<int> backward_max_h(height.size(), 0);
        backward_max_h.back() = height.back();
        for(int i=height.size()-2;i>=0;--i)
        {
            backward_max_h[i] = std::max(backward_max_h[i+1], height[i]);
        }

        // take min
        std::vector<int> max_h(height.size(), 0);
        for(int i=0;i<height.size();++i)
        {
            max_h[i] = std::min(forward_max_h[i], backward_max_h[i]);
        }

        int count=0;
        for(int i=0;i<height.size();++i)
        {
            count += (max_h[i]-height[i]);
        }

        return count;
    }
};
