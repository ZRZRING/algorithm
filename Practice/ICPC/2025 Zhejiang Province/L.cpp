#include <bits/stdc++.h>

#define Fast_IOS                      \
    std::ios::sync_with_stdio(false), \
        std::cin.tie(0),              \
        std::cout.tie(0)

using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using A2 = std::array<int64, 2>;
using A4 = std::array<int64, 4>;

int64 mod = 998244353;

int N = 1e5 + 10, T = 1;

void init() {
    // Fast_IOS;
    // std::cin >> T;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> d(n + 1), to(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> to[i];
        d[to[i]]++;
    }
    std::vector<int> vis(n + 1);
    std::vector R(0, std::vector<int>());
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        int x = i;
        while (!vis[x]) {
            vis[x] = i;
            x = to[x];
        }
        if (vis[x] != i) {
            continue;
        }
        R.push_back({});
        while (vis[x] != -1) {
            vis[x] = -1;
            R.back().push_back(x);
            x = to[x];
        }
    }
    // for (int i = 1; i <= n; i++) std::cout << vis[i] << " \n"[i == n];
    std::vector<A2> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i][1] = 1;
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = to[u];
        f[v][0] += std::max(f[u][0], f[u][1]);
        f[v][1] += f[u][0];
        d[v]--;
        if (!d[v]) {
            q.push(v);
        }
    }
    // for (int i = 1; i <= n; i++) std::cout << f[i][0] << " \n"[i == n];
    // for (int i = 1; i <= n; i++) std::cout << f[i][1] << " \n"[i == n];
    int ans = 0;
    for (auto r : R) {
        std::vector<A4> g(r.size());
        g[0][0] = f[r[0]][0];
        g[0][3] = f[r[0]][1];
        for (int i = 1; i < r.size(); i++) {
            g[i][0] = std::max(g[i - 1][0], g[i - 1][1]) + f[r[i]][0];
            g[i][1] = g[i - 1][0] + f[r[i]][1];
            g[i][2] = std::max(g[i - 1][2], g[i - 1][3]) + f[r[i]][0];
            g[i][3] = g[i - 1][2] + f[r[i]][1];
        }
        ans += std::max({g.back()[0], g.back()[1], g.back()[2]});
    }
    std::cout << ans << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}