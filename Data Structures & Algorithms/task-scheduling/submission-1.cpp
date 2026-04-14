class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> count(26, 0);
        for (auto c : tasks)
        {
            ++count[c -'A'];
        }

        int max_freq = 0;
        for (auto freq : count)
        {
            max_freq = std::max(max_freq, freq);
        }

        int n_max_freq = 0;
        for (auto freq : count)
        {
            if (freq == max_freq) ++n_max_freq;
        }

        return std::max(static_cast<int>(tasks.size()), (max_freq - 1) * (n + 1) + n_max_freq);
    }
};