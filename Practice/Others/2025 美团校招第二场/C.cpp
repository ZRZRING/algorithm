#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int, 2>;
using A3 = std::array<int, 3>;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

struct DSU {
    int n;

    std::vector<int> fa, size;

    DSU(int n) : n(n) {
        fa.resize(n + 1);
        size.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
        std::fill(size.begin(), size.end(), 1);
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    int merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return 0;
        fa[x] = y;
        size[y] += size[x];
        return 1;
    }
};

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<A3> e;
    DSU d0(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int x, y;
            int d = exgcd(a[i], a[j], x, y);
            if (k % d != 0) continue;
            x *= k / d;
            y *= k / d;
            // std::cout << a[i] << ' ' << a[j] << ' ' << x << ' ' << y << '\n';
            int kx = a[j] / d, ky = a[i] / d;
            int x0 = ((x % kx) + kx) % kx;
            int y0 = y + (x - x0) / kx * ky;
            // std::cout << a[i] << ' ' << a[j] << ' ' << x0 << ' ' << y0 << '\n';
            if (x0 <= 0 || y0 <= 0) continue;
            e.push_back({std::min((k - x0) / kx, (y0 - 1) / ky), i, j});
            // std::cout << e[i][0] << ' ' << e[i][1] << ' ' << e[i][2] << '\n';
            d0.merge(i, j);
        }
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        max = std::max(max, d0.size[i]);
    }
    std::vector<int> del(n + 1);
    for (int i = 1; i <= n; i++) {
        if (d0.size[i] != max) del[i] = 1;
    }
    std::sort(e.begin(), e.end(), [](
        const A3 a, const A3 b
    ) {
        return a[0] < b[0];
    });
    int64 ans = 0;
    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        int x = e[i][1], y = e[i][2];
        if (del[x] || del[y]) continue;
        if (dsu.merge(x, y)) {
            ans += e[i][0];
        }
    }
    std::cout << ans << '\n';
}

int main() {
    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }
}