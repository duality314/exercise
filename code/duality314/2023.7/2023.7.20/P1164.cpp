#include <cstdio>

using namespace std;

int m, n, a, dp[10010];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        for (int j = m; j > a; --j)
            dp[j] += dp[j - a];
        ++dp[a];
    }
    printf("%d", dp[m]);
    return 0;
}
/*
    关键递推方程
    dp[i]+=dp[i-p[now]]
    其中
    dp[i]表示 一共i元钱有几种方法
*/