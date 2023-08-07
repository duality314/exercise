#include <iostream>
#include <cstdio>
using std::min;

const int MAXN = 20003;
int l[MAXN], r[MAXN], dp[2][MAXN];
int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> l[i] >> r[i];
    dp[0][1] = r[1] + r[1] - l[1] - 1;
    dp[1][1] = r[1] - 1;
    for (int i = 2; i <= n; ++i){

        dp[0][i] = min(dp[0][i - 1] + abs(l[i - 1] - r[i]) + r[i] - l[i] + 1, dp[1][i - 1] + abs(r[i - 1] - r[i]) + r[i] - l[i] + 1),
        dp[1][i] = min(dp[0][i - 1] + abs(l[i - 1] - l[i]) + r[i] - l[i] + 1, dp[1][i - 1] + abs(r[i - 1] - l[i]) + r[i] - l[i] + 1);
    }
    std::cout << min(dp[0][n] + n - l[n], dp[1][n] + n - r[n]) << std::endl;
    return 0;
}