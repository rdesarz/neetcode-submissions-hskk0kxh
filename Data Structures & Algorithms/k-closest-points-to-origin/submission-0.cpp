class Solution {
public:
    int dist(const std::vector<int>& pnt)
    {
        return pnt[0] * pnt[0] + pnt[1] * pnt[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [this](const std::vector<int>& a, const std::vector<int>& b)
        {
            return dist(a) < dist(b);
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> pq(compare);

        for(const auto& val : points)
        {
            if(pq.size() < k)
            {
                pq.push(val);
            }
            else
            {
                auto& largest_point = pq.top();
                if (dist(val) < dist(largest_point))
                {
                    pq.pop();
                    pq.push(val);
                }
            }
        }

        std::vector<std::vector<int>> output;
        while(!pq.empty())
        {
            output.push_back(pq.top());
            pq.pop();
        }

        return output;
    }
};
