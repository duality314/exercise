#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    #ifdef LOCAL
    freopen("testdata.in","r",stdin);
    #endif
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int height = 0;
        int pre = 0;
        int t = 0;
        for(int i = 1; i <=n; ++i) {
            cin >> t;
            if (t < pre) height = max(height, pre);
            pre = std::max(pre, t);
        }
        cout << height << endl;
    }
    return 0;
}