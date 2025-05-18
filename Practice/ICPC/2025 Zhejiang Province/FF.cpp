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
    std::cin >> T;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> c(n + 1);
    std::vector color(51, std::vector<int>());
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
        color[c[i]].push_back(i);
    }
    std::vector e(n + 1, std::vector<int>());
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        e[x].push_back(y);
    }
    for (int i = 1; i <= 50; i++) {
        if (color[i].empty()) {
            continue;
        }
        std::vector<int> dis(n + 1);
        std::queue<int> q;
        for (auto x : color[i]) {
            q.push(x);
            dis[x] = 1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : e[u]) {
                if (c[v] == i && dis[u] + 1 <= k) {
                    std::cout << "NO\n";
                    return;
                }
                if (dis[v]) {
                    continue;
                }
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    std::cout << "YES\n";
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}