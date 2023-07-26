#include <iostream>
#include <cmath>
using namespace std;

int re = 0;
int n, m;
int number[25];
bool vis[25];
bool check_prime(int x)
{
    if (x == 1)
        return 0;
    if (x == 2 || x == 3)
        return 1;
    if (x % 2 == 0 || x % 3 == 0)
        return 0;
    for (int i = 3; i < sqrt(x); i += 2)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void dfs(int step, int sum, int index)
{
    if (step == m)
    {
        if (check_prime(sum) && sum != 0)
            re++;
        return;
        // cout << sum << " ";
        // return;
    }
    for (int i = index; i < n; i++)
    {
        if (vis[i])
            continue;
        else
        {
            vis[i] = 1;
            dfs(step + 1, sum + number[i], i);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    dfs(0, 0, 0);
    cout << re;
    return 0;
}
/*
    选组合不能重 dfs要加第三个index变量


*/