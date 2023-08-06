class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int sum = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            sort(grid[0].begin(), grid[0].end());
        }
        for (int i = 0; i < n; i++)
        {
            int xmax = 0;
            for (int j = 0; j < m; j++)
            {
                xmax = max(xmax, grid[i][j]);
            }
            sum += xmax;
        }
        return sum;
    }
};