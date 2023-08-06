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
        long long over = 0;
        for (int i = 1; i <= n; ++i) {
            long long t;
            cin >> t;
            if (t == 1) over --;
            else over += t - 1;
        }
        if (over >= 0 && n != 1) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}