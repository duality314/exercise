#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m, ance[151], b[151];
struct Pair
{
    int x;
    int y;
} a[5001];

inline int findAnce(int u) 
{
    if (ance[u] == u)
        return u;
    return ance[u] = findAnce(ance[u]);
}
inline void unionNode(int x, int y)
{
    int x1 = findAnce(x), y1 = findAnce(y);
    ance[y1] = ance[x1];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].x >> a[i].y;
        if (a[i].y < a[i].x)
            swap(a[i].x, a[i].y);
    }
    sort(a + 1, a + m + 1, [](Pair x, Pair y) -> bool {
        if (x.x == y.x)
            return x.y < y.y;
        return x.x < y.x; });
    for (int i = 1; i <= m; i++)
    {
        int f = 0;
        for (int j = 1; j <= n; j++)
            ance[j] = j;
        for (int j = 1; j <= m; j++)
        {
            if (j != i)
                unionNode(a[j].x, a[j].y);
        }
        for (int j = 2; j <= n; j++)
            if (ance[findAnce(j)] != ance[findAnce(j - 1)])
            {
                cout << a[i].x << " " << a[i].y << endl;
                break;
            }
    }
    return 0;
}