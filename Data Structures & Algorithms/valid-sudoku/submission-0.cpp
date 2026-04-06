class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_check[9][9];
        int col_check[9][9];
        int box_check[9][9];

        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
            {
                row_check[i][j] = 0;
                col_check[i][j] = 0;
                box_check[i][j] = 0;
            }

        for (int row=0;row<9;++row)
        {
            for(int col=0;col<9;++col)
            {
                int num = board[row][col];

                if (num == '.')
                {
                    continue;
                }

                if (row_check[row][num-'1'] || col_check[col][num-'1'] || box_check[row/3+3*(col/3)][num-'1'])
                {
                    return false;
                }

                ++row_check[row][num-'1'];
                ++col_check[col][num-'1'];
                ++box_check[row/3+3*(col/3)][num-'1'];
            }
        }

        return true;
    }
};
