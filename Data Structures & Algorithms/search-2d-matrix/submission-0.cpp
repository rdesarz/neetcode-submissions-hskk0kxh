class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        int l=0;
        int r=matrix.size();
        while(l<r)
        {
            row=(l+r)/2;
            if(matrix[row].front() <= target && target <= matrix[row].back()) break;
            else if(matrix[row][0] < target) l=row+1;
            else r=row;
        }

        l=0;
        r=matrix[row].size();
        while(l<r)
        {
            int mid=(l+r)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) l=mid+1;
            else r=mid;
        }

        return false;
    }
};
