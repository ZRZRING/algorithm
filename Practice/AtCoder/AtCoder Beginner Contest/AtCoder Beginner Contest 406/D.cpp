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
    Fast_IOS;
    // std::cin >> T;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::set<int>> row(n + 1), col(m + 1);
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        row[x].insert(y);
        col[y].insert(x);
    }
    int Q;
    std::cin >> Q;
    while (Q--) {
        int opt, x;
        std::cin >> opt >> x;
        if (opt == 1) {
            std::cout << row[x].size() << '\n';
            for (auto y : row[x]) {
                col[y].erase(x);
            }
            row[x].clear();
        } else {
            std::cout << col[x].size() << '\n';
            for (auto y : col[x]) {
                row[y].erase(x);
            }
            col[x].clear();
        }
    }
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}