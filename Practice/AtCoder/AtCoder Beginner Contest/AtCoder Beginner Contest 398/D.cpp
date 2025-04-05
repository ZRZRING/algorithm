#include <bits/stdc++.h>

#define Fast_IOS                      \
    std::ios::sync_with_stdio(false), \
        std::cin.tie(0),              \
        std::cout.tie(0)

using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using A2 = std::array<int64, 2>;

int64 mod = 998244353;

int N = 1e5 + 10, T = 1;

void init() {
    // Fast_IOS;
    // std::cin >> T;
}

void solve() {
    int n, X, Y;
    std::cin >> n >> X >> Y;
    std::string s;
    std::cin >> s;
    std::map<char, int> dx = {
        {'N', -1},
        {'W', 0},
        {'S', 1},
        {'E', 0}
    };
    std::map<char, int> dy = {
        {'N', 0},
        {'W', -1},
        {'S', 0},
        {'E', 1}
    };
    A2 pos = {0, 0};
    std::map<A2, int> vis;
    vis[pos] = 1;
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        pos = {pos[0] + dx[s[i]], pos[1] + dy[s[i]]};
        // std::cout << pos[0] << ' ' << pos[1] << '\n';
        ans[i] = vis[{pos[0] - X, pos[1] - Y}];
        vis[pos] = 1;
    }
    for (auto x : ans) {
        std::cout << x;
    }
    std::cout << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}