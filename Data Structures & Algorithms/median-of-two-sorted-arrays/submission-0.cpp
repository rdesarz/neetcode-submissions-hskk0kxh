class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Ensure A is the smaller array
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int m = (int)A.size();
        int n = (int)B.size();
        int totalLeft = (m + n + 1) / 2;

        int l = 0, r = m; // partition i in [0..m]
        while (l <= r) {
            int i = (l + r) / 2;        // cut in A
            int j = totalLeft - i;      // cut in B

            int Aleft  = (i == 0) ? INT_MIN : A[i - 1];
            int Aright = (i == m) ? INT_MAX : A[i];
            int Bleft  = (j == 0) ? INT_MIN : B[j - 1];
            int Bright = (j == n) ? INT_MAX : B[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                // correct partition
                if ((m + n) % 2 == 1) {
                    return (double)max(Aleft, Bleft);
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            } else if (Aleft > Bright) {
                // i too big, move left
                r = i - 1;
            } else {
                // Bleft > Aright => i too small, move right
                l = i + 1;
            }
        }

        return 0.0; // unreachable if inputs are valid
    }
};