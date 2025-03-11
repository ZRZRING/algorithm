#include <bits/stdc++.h>

using A2 = std::array<int, 2>;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, std::vector<A2>> X, Y; 
    for (int i = 1; i <= n; i++) {
        int x, y;
        std::cin >> x >> y;
        X[x].push_back({y, i});
        Y[y].push_back({x, i});
    }
    std::vector<int> ans(n + 1);
    for (auto [x, s] : X) {
        std::sort(s.begin(), s.end());
        // for (auto t : s) {
        //     std::cout << t[0] << ' ';
        // }
        // std::cout << '\n';
        int m = s.size();
        for (int i = 0; i < m - 2; i++) {
            ans[s[i][1]]++;
        }
        for (int i = 2; i < m; i++) {
            ans[s[i][1]]++;
        }
    }
    for (auto [y, s] : Y) {
        std::sort(s.begin(), s.end());
        // for (auto t : s) {
        //     std::cout << t[0] << ' ';
        // }
        // std::cout << '\n';
        int m = s.size();
        for (int i = 0; i < m - 2; i++) {
            ans[s[i][1]]++;
        }
        for (int i = 2; i < m; i++) {
            ans[s[i][1]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }
}
// 64 位输出请用 printf("%lld")