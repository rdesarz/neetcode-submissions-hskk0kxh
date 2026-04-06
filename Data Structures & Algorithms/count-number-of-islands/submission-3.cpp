class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n_islands = 0;
        for(int r=0;r<grid.size();++r)
        {
            for(int c=0;c<grid[0].size();++c)
            {
                if(grid[r][c] == '1')
                {
                    ++n_islands;
                    std::queue<std::pair<int, int>> q;
                    q.push({r,c});
                    grid[r][c] = '0';
                    while(!q.empty())
                    {
                        auto [r2, c2] = q.front();
                        q.pop();

                        if(r2 != 0 && grid[r2-1][c2] == '1') 
                        {
                            grid[r2-1][c2] = '0';
                            q.push({r2-1, c2});
                        }

                        if(c2 != 0 && grid[r2][c2-1] == '1') 
                        {
                            grid[r2][c2-1] = '0';
                            q.push({r2, c2-1});
                        }

                        if(r2 != grid.size()-1 && grid[r2+1][c2] == '1') 
                        {
                            grid[r2+1][c2] = '0';
                            q.push({r2+1, c2});
                        }

                        if(c2 != grid[0].size()-1 && grid[r2][c2+1] == '1') 
                        {
                            grid[r2][c2+1] = '0';
                            q.push({r2, c2+1});
                        }
                    }
                }
            }
        }

        return n_islands;
    }
};
