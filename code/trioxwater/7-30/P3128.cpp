#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
const int N = 5e4+5;
std::vector<int> Edges[N];

int a[N];
int ans[N];
int lca[20][N], depth[N];


void dfs1(int cur, int ance) {
    std::stack<std::pair<int, int> > S;
    depth[cur] = depth[ance] + 1;
    
    S.push(std::make_pair(cur, ance));
    while(!S.empty()) {
        std::pair<int, int> tmp = S.top();
        S.pop();
        int cur = tmp.first, ance = tmp.second;
        for(int k = 1; k < 20; ++k) {
            lca[k][cur] = lca[k-1][lca[k-1][cur]];
        }
        for (int i = 0; i<Edges[cur].size(); ++i) {
            int v = Edges[cur][i];
            if (v == ance) continue;
            lca[0][v] = cur;
            depth[v] = depth[cur] + 1;
            S.push(std::make_pair(v, cur));
        }
    }   
}
void build(int n) { 
    dfs1(1, 0);
}
int getLCA(int x, int y) {
    if (depth[x] < depth[y]) std::swap(x, y);
    int px = x, py = y;
    for (int k = 19; k >= 0; --k) {
        if (depth[lca[k][px]] >= depth[py]) {
            px = lca[k][px];
        }
    }
    if (px == py) return px;
    for (int k = 19; k >= 0; --k) {
        if (lca[k][px] != lca[k][py]) {
            px = lca[k][px];
            py = lca[k][py];
        }
    }
    return lca[0][px];
}

void add(int x, int y) {
    int l = getLCA(x, y);
    a[l] --;
    a[x]++;
    a[y]++;
    a[lca[0][l]]--;
}

void dfs2(int cur, int ance) {
    int tmp = 0;
    for (int i = 0; i<Edges[cur].size(); ++i) {
        int v = Edges[cur][i];
        if (v == ance) continue;
        dfs2(v, cur);
        tmp += ans[v];
    }
    ans[cur] = tmp + a[cur];

}

int main() {
    #ifdef LOCAL
    freopen("testdata.in","r",stdin);
    #endif
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i<n; ++i) {
        int u, v;
        std::cin >> u >> v;
        Edges[u].push_back(v);
        Edges[v].push_back(u);
    }

    build(n);
    // perror("build");
    for(int i = 1; i<=k; ++i) {
        int u, v;
        std::cin >> u >> v;
        add(u, v);
    }
    // perror("add");

    dfs2(1, 0);
    // perror("dfs2");
    std::cout << *std::max_element(ans+1, ans+n+1) << std::endl;
    return 0;    
}