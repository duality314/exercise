#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    int re = 0;
    int endx = 0, endy = 0, stx = 0, sty = 0;
    bool mmap[21][21] = {0};
    int len = 0, wid = 0;
    int dix[4] = {0, 0, 1, -1};
    int diy[4] = {1, -1, 0, 0};
    void dfs(int x, int y)
    {
        if (x < 0 || y < 0 || x >= wid || y >= len || mmap[x][y])
            return;
        mmap[x][y] = 1;
        if (x == endx && y == endy)
        {
            for (int i = 0; i < wid; i++)
                for (int j = 0; j < len; j++)
                {
                    if (mmap[i][j] == 0)
                        return;
                }
            re++;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dix[i];
            int ny = y + diy[i];
            if (nx < 0 || ny < 0 || nx >= wid || ny >= len || mmap[nx][ny])
                continue;
            dfs(nx, ny);
            mmap[nx][ny] = 0;
        }
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        wid = grid.size(), len = grid[0].size();
        for (int i = 0; i < wid; i++)
            for (int j = 0; j < len; j++)
            {
                if (grid[i][j] == 1)
                    stx = i, sty = j;
                else if (grid[i][j] == 2)
                    endx = i, endy = j;
                else if (grid[i][j] == -1)
                    mmap[i][j] = 1;
            }
        dfs(stx, sty);
        return re;
    }
};