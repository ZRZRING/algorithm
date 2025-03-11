#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int64>

const int64 mod = 998244353;

struct NODE {
    int64 val;
    int x, y;
};

struct DSU {
    int n;

    std::vector<int> fa, size;

    DSU(int n) : n(n) {
        fa.resize(n + 1);
        size.resize(n + 1);
        std::fill(size.begin(), size.end(), 1);
        std::iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
    }

    int merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if (size[x] < size[y]) fa[x] = y;
        else fa[y] = x;
        return 1;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int64>> e(n + 1, std::vector<int64>(n + 1));
    std::vector<NODE> E;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> e[i][j];
            E.push_back({e[i][j], i, j});
        }
    }
    std::sort(E.begin(), E.end(), [](NODE a, NODE b) {
        return a.val < b.val;
    });
    DSU dsu(n);
    int64 ans = 0;
    std::vector<int64> min(n + 1, 1e9);
    for (auto [t, u, v] : E) {
        if (dsu.merge(u, v) == 0) continue;
        ans += t;
        min[u] = std::min(min[u], t);
        min[v] = std::min(min[v], t);
    }
    for (int i = 1; i <= n; i++) {
        ans += std::min(min[i], e[i][i]) * (a[i] - 1);
    }
    std::cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}