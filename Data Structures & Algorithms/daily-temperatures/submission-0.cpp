class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> out(temperatures.size(), 0);

        std::stack<std::pair<int, int>> s;
        for (int i=0;i<temperatures.size();++i)
        {
            while(!s.empty() && s.top().first < temperatures[i])
            {
                out[s.top().second] = i - s.top().second;
                s.pop();
            }

            s.push({temperatures[i], i});
        }

        return out;
    }
};
