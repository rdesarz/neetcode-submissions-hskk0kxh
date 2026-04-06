class Solution {
public:
    int trap(vector<int>& h) {
    int n = (int)h.size();
    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0;
    long long water = 0;

    while (l < r) {
        if (h[l] <= h[r]) {
            leftMax = max(leftMax, h[l]);
            water += leftMax - h[l];
            ++l;
        } else {
            rightMax = max(rightMax, h[r]);
            water += rightMax - h[r];
            --r;
        }
    }
    return (int)water;
}
};
