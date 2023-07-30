#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int N = 1000008;
int ufset[N];
bool label[N];
struct Edge
{
    int u, v, c;
} edge[N];
int find(int x) { return ufset[x] == x ? x : ufset[x] = find(ufset[x]); }
int query(int x, int y) { return find(x) == find(y); }
int main(void)
{
    long long ans = 0;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        ufset[i] = i;

    for (int i = 1, x; i <= k; ++i)
        cin >> x, label[x] = true;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].c;
        ans += edge[i].c;
    }
    std::sort(edge + 1, edge + n, [](const Edge &a, const Edge &b)
              { return a.c > b.c; });
    for (int i = 1; i <= n - 1; ++i)
    {
        int& u = edge[i].u, &v = edge[i].v, &c = edge[i].c;
        int fu = find(u), fv = find(v);
        if (label[fu] && label[fv])
            continue;
        ufset[fu] = fv;
        ans -= c;
        if (label[fu])
            label[fv] = true;
        else if (label[fv])
            label[fu] = true;
    }
    printf("%lld\n", ans);
    return 0;
}