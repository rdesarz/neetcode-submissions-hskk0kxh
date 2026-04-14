class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        std::unordered_set<int> added_val;

        for(const auto& val : nums)
        {
            if (pq.size() < k)
            {
                pq.push(val);
                added_val.insert(val);
            }
            else
            {
                if (val > pq.top())
                {
                    added_val.erase(pq.top());
                    pq.pop();

                    pq.push(val);
                    added_val.insert(val);
                }
            }
        }

        return pq.top();
    }
};
