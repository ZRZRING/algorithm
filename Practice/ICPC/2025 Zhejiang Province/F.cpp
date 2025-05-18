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
        e[0].clear();
        for (auto x : color[i]) {
            e[0].push_back(x);
        }
        std::vector<int> vis(n + 1);
        std::vector<A2> dis(n + 1, (A2){(int64)1e9, (int64)1e9});
        std::priority_queue<A2, std::vector<A2>, std::greater<A2>> q;
        dis[0] = {0, 0};
        q.push({0, 0});
        while (!q.empty()) {
            int u = q.top()[1];
            q.pop();
            if (vis[u]) {
                continue;
            }
            vis[u] = 1;
            for (auto v : e[u]) {
                if (dis[u][0] + 1 < dis[v][0]) {
                    dis[v][1] = dis[v][0];
                    dis[v][0] = dis[u][0] + 1;
                    q.push({dis[v][0], v});
                } else if (dis[u][0] + 1 < dis[v][1]) {
                    dis[v][1] = dis[u][0] + 1;
                }
            }
        }
        for (auto x : color[i]) {
            // std::cout << dis[x][0] << ' ' << dis[x][1] << '\n';
            if (dis[x][1] <= k) {
                std::cout << "NO\n";
                return;
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