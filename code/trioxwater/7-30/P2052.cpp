#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int MAXN = 10000010;
long long n, cnt, ans;
long long size[MAXN], head[MAXN];
struct
{
    int weight, dest, next;
} Edges[MAXN * 2];
void add(int x, int y, int z, int f = 1)
{
    cnt++;
    Edges[cnt].dest = y;
    Edges[cnt].next = head[x];
    Edges[cnt].weight = z;
    head[x] = cnt;
    if (f)
        add(y, x, z, 0);
}
void dfs(int cur, int ancestor)
{
    size[cur] = 1;
    for (int i = head[cur]; i; i = Edges[i].next)
    {
        if (ancestor == Edges[i].dest)
            continue;
        dfs(Edges[i].dest, cur);
        size[cur] += size[Edges[i].dest];
        ans += Edges[i].weight * abs(2 * size[Edges[i].dest] - n);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}