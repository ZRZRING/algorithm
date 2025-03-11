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
    int n, m;
    std::cin >> n >> m;
    std::map<std::string, std::vector<std::string>> e;
    for (int i = 1; i <= m; i++) {
        std::string x, y;
        std::cin >> x >> y;
        e[y].push_back(x);
    }
    int ans = 0;
    std::queue<std::string> q;
    q.push("a");
    while (!q.empty()) {
        std::string t = q.front();
        q.pop();
        // std::cout << t << '\n';
        if (t.size() == n) {
            ans++;
            continue;
        }
        std::string u;
        u += t[0];
        t.erase(0, 1);
        for (auto v : e[u]) {
            q.push(v + t);
        }
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