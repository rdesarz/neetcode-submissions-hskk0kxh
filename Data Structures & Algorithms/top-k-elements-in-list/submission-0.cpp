class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> tab;
        for (int i=0;i<nums.size();++i) ++tab[nums[i]];

        std::priority_queue<std::pair<int,int>, std::vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
        for (const auto& elem : tab)
        {
            if(pq.size() < k)
            {
                pq.push({elem.second, elem.first});
            }
            else if (pq.top().first < elem.second)
            {
                pq.pop();
                pq.push({elem.second, elem.first});  
            }
        }

        vector<int> output;
        while(!pq.empty())
        {
            output.push_back(pq.top().second);
            pq.pop();
        }

        return output;
    }
};
