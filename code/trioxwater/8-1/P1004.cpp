//方格取数走两遍
#include <bits/stdc++.h>
const int MAXN = 10;
int map[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
int main()
{
    int n;
    std::cin >> n;
    int x, y, c;
    while (std::cin >> x >> y >> c && x)
        map[x][y] = c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int l = 1; l <= n; l++)
                for (int k = 1; k <= n; k++)
                {
                    dp[i][j][l][k] = std::max({dp[i - 1][j][l - 1][k], dp[i][j - 1][l][k - 1], dp[i - 1][j][l][k - 1], dp[i][j - 1][l - 1][k]}) + map[i][j];
                    if (i != 1 && j != k)
                        dp[i][j][l][k] += map[l][k];
                }
    std::cout << dp[n][n][n][n] << std::endl;
    return 0;
}