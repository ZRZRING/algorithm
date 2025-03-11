#include <bits/stdc++.h>

#define IOS \
    std::ios::sync_with_stdio(0), \
    std::cin.tie(0), \
    std::cout.tie(0)

struct DATA {
    std::string s;
    std::vector<int> line;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector a(3, std::vector<int>(n + 1));
    std::vector<std::map<int, std::vector<DATA>>> vis(3);
    std::vector<std::priority_queue<DATA, std::vector<DATA>, std::greater<DATA>>> q(3);
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < 3; i++) {
            int x;
            std::cin >> x;
            a[i][j] = x;
            vis[i][x].push_back(j);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (auto [x, y] : vis[i]) {
            q[i].push((DATA){y.size(), y});
        }
    }
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        int flag = 1;
        int tt = 0;
        while (flag) {
            if (tt++ == 20) return;
            flag = 0;
            for (int p = 0; p < 3; p++) {
                if (q[p].empty()) continue;
                auto [t, x] = q[p].top();
                if (t >= k) continue;
                for (int i = 0; i < 3; i++) {
                    vis[i][x]--;
                }
                int ttt = 0;
                while (!q[p].empty() && t != vis[p][a[p][x]]) {
                    if (ttt++ == 20) return;
                    std::cout << t << ' ' << x << ' ' << q[p].size() << '\n';
                    q[p].pop();
                    if (vis[p][x] == 0) {
                        t = q[p].top().at(0);
                        x = q[p].top().at(1);
                        continue;
                    }
                    q[p].push({vis[p][x], x});
                    t = q[p].top().at(0);
                    x = q[p].top().at(1);
                }
                flag = 1;
            }
        }
        // std::cout << ans << " ";
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