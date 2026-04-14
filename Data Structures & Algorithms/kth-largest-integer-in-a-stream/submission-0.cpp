class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : 
     pq(std::greater<int>()), k_(k)
    {
        for(const auto& val : nums)
        {
            add(val);
        }
    }
    
    int add(int val) {
        if (pq.size() < k_)
        {
            pq.push(val);
        }
        else if(pq.top() < val)
        {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k_;
};
