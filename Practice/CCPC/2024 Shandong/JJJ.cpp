#include <bits/stdc++.h>

#define IOS \
    std::ios::sync_with_stdio(0), \
    std::cin.tie(0), \
    std::cout.tie(0)

void solve() {
    int n;
    std::cin >> n;
    std::vector a(3, std::vector<int>(n + 1));
    std::vector vis(3, std::map<int, int>());
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < 3; i++) {
            std::cin >> a[i][j];
            vis[i][a[i][j]]++;
        }
    }
    std::vector<int> t(n + 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            t[i] = std::max(t[i], vis[i][a[i][j]]);
        }
    }
    #define A2 std::array<int, 2>
    std::priority_queue<A2> q;
    for (int j = 1; j <= n; j++) {
        q.push(t[j]);
    }
    std::vector<int> ans;
    for (int k = n; k >= 1; k--) {
        while (q.top().at(0) >= k) {
            q.pop();
        }
        ans.push_back(q.size());
    }
    std::reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    // IOS;
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}