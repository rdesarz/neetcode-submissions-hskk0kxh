class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for(const auto& val : nums)
        {
            if (pq.size() < k)
            {
                pq.push(val);
            }
            else
            {
                if (val > pq.top())
                {
                    pq.pop();
                    pq.push(val);
                }
            }
        }

        return pq.top();
    }
};
