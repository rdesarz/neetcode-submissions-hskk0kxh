class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::deque<uint64_t> q;
        std::vector<int> n_coins(amount + 1, -1);

        n_coins[0] = 0;
        q.push_back(0);
        while(!q.empty())
        {
            auto val = q.front();
            q.pop_front();

            if (val == amount)
            {
                return n_coins[amount];
            }

            for (auto& coin : coins)
            {
                if ((val + coin) <= amount && n_coins[val + coin] == -1)
                {
                    n_coins[val + coin] = n_coins[val] + 1;
                    q.push_back(val + coin);
                }
            }
        }

        return -1;
    }
};
