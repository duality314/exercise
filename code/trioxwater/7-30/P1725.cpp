#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <deque>
#include <algorithm>
#include <utility>

const int MAXN = 2e5+6;
int ary[MAXN];
int dp[MAXN];

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;
    for(int i = 0; i <=n; ++i) {
        std::cin >> ary[i];
    }
    memset(dp, 0x80, sizeof(dp));
    dp[0] = 0;
    int ans = -0x80000000;
    std::deque<std::pair<int, int> > Q;
    for(int i = l; i <= n; ++i) {
        while(!Q.empty() && Q.front().second < i - r) Q.pop_front();
        while(!Q.empty() && Q.back().first <= dp[i-l]) Q.pop_back();
        Q.push_back(std::make_pair(dp[i - l], i - l));
        if (Q.empty()) dp[i] = 0;
        else dp[i] = Q.front().first + ary[i];
        if (i + r > n) ans = std::max(ans, dp[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}