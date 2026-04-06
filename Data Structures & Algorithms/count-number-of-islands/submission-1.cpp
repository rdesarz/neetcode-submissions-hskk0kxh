class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        std::vector<std::vector<bool>> v(grid.size(), std::vector<bool>(grid[0].size(), false));

        int n_islands = 0;
        for(int r=0;r<grid.size();++r)
        {
            for(int c=0;c<grid[0].size();++c)
            {
                if(!v[r][c] && grid[r][c] == '1')
                {
                    ++n_islands;
                    std::queue<std::pair<int, int>> q;
                    q.push({r,c});
                    v[r][c] = true;
                    while(!q.empty())
                    {
                        auto [r2, c2] = q.front();
                        q.pop();

                        if(r2 != 0 && !v[r2-1][c2] && grid[r2-1][c2] == '1') 
                        {
                            v[r2-1][c2] = true;
                            q.push({r2-1, c2});
                        }

                        if(c2 != 0 && !v[r2][c2-1] && grid[r2][c2-1] == '1') 
                        {
                            v[r2][c2-1] = true;
                            q.push({r2, c2-1});
                        }

                        if(r2 != grid.size()-1 && !v[r2+1][c2] && grid[r2+1][c2] == '1') 
                        {
                            v[r2+1][c2] = true;
                            q.push({r2+1, c2});
                        }

                        if(c2 != grid[0].size()-1 && !v[r2][c2+1] && grid[r2][c2+1] == '1') 
                        {
                            v[r2][c2+1] = true;
                            q.push({r2, c2+1});
                        }
                    }
                }
            }
        }

        return n_islands;
    }
};
