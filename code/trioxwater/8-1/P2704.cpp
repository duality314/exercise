#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

const int N = 103, M = 11;
const int MAXSTATE = 88572;
int dp[N][MAXSTATE];
int state_cnt;

struct State {
    int state;
    std::string printAsBinary() {
        std::string res;
        for(int i = 0; i < M; ++i) {
            res += (state & (1 << i)) ? '1' : '0';
        }
        return res;
    }

    inline int get(int i) {
        return (state >> i) & 1;
    }

    inline void set(int i, int v) {
        if(v) state |= (1 << i);
        else state &= ~(1 << i);
    }
};

int encode_state(int state1, int state2, int m) {
    int hash = 0;
    for (int i = 1; i <= m; ++i) {
        hash = hash * 3 + (state1 >> i & 1) * 2 + (state2 >> i & 1);
    }
    return hash;
}

void decode_state(int &state1, int &state2, int code, int m) {
    state1 = state2 = 0;
    for(int i = 1; i <= m; ++i) {
        int t = code % 3;
        code /= 3;
        if(t == 1) state2 |= (1 << i);
        else if(t == 2) state1 |= (1 << i);
    }
}

int map[N];
std::vector<int> validStates;
std::vector<int> value;
void print_in_binary(int state, int m) {
    for(int i = m; i > 0; --i) {
        cout << ((state >> i) & 1);
    }
    cout << endl;
}

int main() {
    #ifdef LOCAL
    freopen("testdata.in","r",stdin);
    #endif

    int m, n;
    cin >> n >> m;
    state_cnt = pow(3, m);
    for(int j = 0; j < (1<<m); ++j) {   //筛选所有有用状态
        if (j & (j << 1)) continue;
        if (j & (j << 2)) continue;
        validStates.push_back(j);
        value.push_back(__builtin_popcount(j));
        print_in_binary(j, m);
    }
    std::string buff;
    cin >> buff;
    for(int j = 0; j < m; ++j) {
        if (buff[j] == 'H') map[1] |= (1 << j);
        else map[1] &= ~(1 << j);
    }

    

    for(int i = 0; i < validStates.size(); ++i) {
        if (validStates[i] & map[1]) continue;
        int t;
        dp[1][t = encode_state(0, validStates[i], m)] = value[i];
    }

        cout << "best till now: ";
        cout << *std::max_element(dp[1], dp[1] + state_cnt) << endl;
        int src_state[N][MAXSTATE] = {};

    for(int i = 2; i <=n; ++i) {
        buff.clear();
        cin >> buff;
        for(int j = 0; j < m; ++j) {
            if (buff[j] == 'H') map[i] |= (1 << j);
            else map[i] &= ~(1 << j);
        }
        for(int k = 0; k < validStates.size(); ++k) {
            if (validStates[k] & map[i]) continue; // validStates[k]表示本列状态
            for(int j = 0; j < state_cnt; ++j) {
                int state1, state2;
                decode_state(state1, state2, j, m);
                if (state1 & validStates[k]) continue;
                if (state2 & validStates[k]) continue;
                int t = encode_state(state2, validStates[k], m);
                dp[i][t] = std::max(dp[i][t], dp[i-1][j] + value[k]);
                src_state[i][t] = j;
            }
        } 
        cout << "best till now: ";
        cout << *std::max_element(dp[i], dp[i] + state_cnt) << endl;
    }
    cout << *std::max_element(dp[n], dp[n] + state_cnt) << endl;
    return 0;
}