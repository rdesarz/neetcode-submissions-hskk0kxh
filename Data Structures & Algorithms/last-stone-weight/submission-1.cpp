class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() >= 2)
        {
            int stone_1 = pq.top();
            pq.pop();

            int stone_2 = pq.top();
            pq.pop();

            if (stone_1 == stone_2) 
            {
                continue;
            }
            else
            {
                pq.push(std::max(stone_1, stone_2) - std::min(stone_1, stone_2));
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
