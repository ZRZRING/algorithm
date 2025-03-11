#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
    std::ios::sync_with_stdio(false), \
    std::cin.tie(0), \
    std::cout.tie(0)

const int64 mod = 998244353;

int N, T = 1;

void init() {
    // Fast_IOS;
    // std::cin >> T;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> pos(m + 1, std::vector<int>());
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        pos[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        
    }
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}