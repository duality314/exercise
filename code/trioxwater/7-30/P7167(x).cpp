#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
const int N = 100005;
using namespace std;

int v[N];
int r[N];
int nxt[20][N];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> r[i] >> v[i];
    }
    for (int i = n-1; i >= 1; --i) {
        for (int k = 19; k >= 0; --k) {
            if (i + (1 << k) <= n) {
                if (r[i] + v[i] >= r[i + (1 << k)]) {
                    nxt[k][i] = nxt[k][i + (1 << k)];
                } else {
                    nxt[k][i] = i + (1 << k);
                }
            }
        }
    }
    return 0;
}