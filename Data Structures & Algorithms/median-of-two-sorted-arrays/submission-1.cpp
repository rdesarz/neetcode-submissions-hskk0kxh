class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int m = (int)A.size();
        int n = (int)B.size();

        int l = 0, r = m;
        int half = (m + n + 1) / 2;

        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft  = (i == 0) ? std::numeric_limits<int>::min() : A[i - 1];
            int Aright = (i == m) ? std::numeric_limits<int>::max() : A[i];

            int Bleft  = (j == 0) ? std::numeric_limits<int>::min() : B[j - 1];
            int Bright = (j == n) ? std::numeric_limits<int>::max() : B[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 1) {
                    return (double)std::max(Aleft, Bleft);
                } else {
                    return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;
                }
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return 0.0; // unreachable
    }
};