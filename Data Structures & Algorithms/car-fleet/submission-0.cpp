class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int,int>> sorted;

        for(int i=0;i<position.size();++i)
        {
            sorted.push_back({position[i], speed[i]});
        }

        std::sort(sorted.begin(), sorted.end(), [](auto& a, auto&b) { return a.first < b.first; });

        std::stack<float> s;
        for(int i=sorted.size()-1;i>=0;--i)
        {
            if(sorted[i].second == 0) break;
            
            float eta = static_cast<float>(target - sorted[i].first) / static_cast<float>(sorted[i].second); 
            if(s.empty() || eta > s.top())
            {
                s.push(eta);
            }
        }

        return s.size();
    }
};
