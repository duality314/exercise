//划水的 饶了我吧qaq
#include <iostream>
#include <cmath>
using namespace std;
int ary[31];
long long s = 0;
int main()
{
    int p;
    while (cin >> ary[p++]);
    for (int i = 0; i < p; ++i)
        s += ary[i];
    s *= 1ll << (p - 2);
    cout << s << endl;
    return 0;
}