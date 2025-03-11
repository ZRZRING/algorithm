#include <bits/stdc++.h>

#define IOS \
    std::ios::sync_with_stdio(0), \
    std::cin.tie(0), \
    std::cout.tie(0)

#define A2 std::array<int, 2>

void solve() {
    int n;
    std::cin >> n;
    std::vector e(n + 1, std::vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (e[i].size() % 2 == 0) {
            root = i;
            break;
        }
    }
    if (!root) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<int> num(n + 1);
    std::iota(num.begin(), num.end(), 0);
    std::vector<A2> ans;
    auto dfs1 = [&](auto self, int u, int last) -> void {
        std::vector<int> son;
        for (auto v : e[u]) {
            if (v == last) continue;
            self(self, v, u);
            son.push_back(v);
        }
        for (int i = 0; i + 1 < son.size(); i += 2) {
            ans.push_back({num[son[i]], num[son[i + 1]]});
        }
        if (son.size() % 2 == 1) {
            num[u] = num[son.back()];
        }
    };
    dfs1(dfs1, root, root);
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        std::cout << x << ' ' << y << '\n';
    }
}

int main() {
    IOS;
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}