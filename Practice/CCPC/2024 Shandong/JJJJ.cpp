#include <bits/stdc++.h>

#define IOS \
    std::ios::sync_with_stdio(0), \
    std::cin.tie(0), \
    std::cout.tie(0)

struct DATA {
    std::string s;
    int x, y;
};

void solve() {
    int n;
    std::cin >> n;
    #define A3 std::array<int, 3>
    std::vector<A3> a(n + 1);
    std::vector<std::map<int, int>> vis(3);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> a[i][j];
            vis[j][a[i][j]]++;
        }
    }
    std::vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            t[i] = std::max(t[i], vis[j][a[i][j]]);
        }
    }
    std::sort(t.begin() + 1, t.end());
    for (int i = 1, j = 0; i <= n; i++) {
        while (j < n && t[j + 1] < i) j++;
        std::cout << j << " \n"[i == n];
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