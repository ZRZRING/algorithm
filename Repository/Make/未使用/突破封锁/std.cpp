#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

const int64 mod = 998244353, gox[4] = {0, 0, -1, 1}, goy[4] = {-1, 1, 0, 0};

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        int a[n + 1][m + 1], ans[n + 1][m + 1];
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                std::cin >> a[i][j];
            }
        }
        std::queue<PII> q;
        q.push({1, 1});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int i = 0; i < 4; i++) {
                int tx = x + gox[i], ty = y + goy[i];
                if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
                if (a[tx][ty] == 0) continue;
                if (!ans[tx][ty]) {
                    ans[tx][ty] = ans[x][y] + 1; q.push({tx, ty});
                }
            }
        }
        if (ans[n][m]) printf("%d\n", ans[n][m] - 1);
        else printf("-1\n");
    }
    return 0;
}