#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1003;
int ary[N];
int to_next[N];
int main() {
    #ifdef LOCAL
    freopen("testdata.in","r",stdin);
    #endif
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> ary[i];
        }
        int ans = 0;
        for(int i = n; i >= 1; --i) {
            int kk = k, curans = 0;
            if (ary[i] < ary[i-1])
                continue;
            for(int j = i - 1; j >= 1; --j) {
                if (ary[j] < ary[j+1]) {
                    if (kk > ary[j] - ary[j+1] + 1) {
                        kk -= ary[j] - ary[j+1];
                        curans = std::max(curans, ary[j]);
                    } else {
                        break;
                    }
                } else {
                    curans++;
                }
            }
        }

    }
    return 0;
}