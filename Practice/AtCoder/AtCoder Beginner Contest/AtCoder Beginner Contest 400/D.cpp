#include <bits/stdc++.h>

#define Fast_IOS                      \
    std::ios::sync_with_stdio(false), \
        std::cin.tie(0),              \
        std::cout.tie(0)

using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using A2 = std::array<int64, 2>;
using A3 = std::array<int64, 3>;

int64 mod = 998244353;

int N = 1e5 + 10, T = 1;

void init() {
    // Fast_IOS;
    // std::cin >> T;
}

const int gox[4] = {0, -1, 0, 1};
const int goy[4] = {-1, 0, 1, 0};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> map(n);
    for (int i = 0; i < n; i++) {
        std::cin >> map[i];
    }
    int X, Y, GX, GY;
    std::cin >> X >> Y >> GX >> GY;
    X--, Y--, GX--, GY--;
    std::priority_queue<A3, std::vector<A3>, std::greater<A3>> q;
    q.push({0, X, Y});
    std::vector vis(n, std::vector<int>(m));
    auto check = [&](int x, int y) -> bool {
        return x > -1 && y > -1 && x < n && y < m;
    };
    while (!q.empty()) {
        auto [t, x, y] = q.top();
        // std::cout << t << ' ' << x << ' ' << y << '\n';
        q.pop();
        if (vis[x][y]) {
            continue;
        }
        vis[x][y] = 1;
        if (x == GX && y == GY) {
            std::cout << t << '\n';
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx, yy, flag = 0;
            xx = x + gox[i], yy = y + goy[i];
            if (check(xx, yy)) {
                if (map[xx][yy] == '.') {
                    q.push({t + flag, xx, yy});
                } else {
                    flag = 1;
                    q.push({t + flag, xx, yy});
                }
            }
            xx = x + gox[i] * 2, yy = y + goy[i] * 2;
            if (check(xx, yy)) {
                if (map[xx][yy] == '.') {
                    q.push({t + flag, xx, yy});
                } else {
                    flag = 1;
                    q.push({t + flag, xx, yy});
                }
            }
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