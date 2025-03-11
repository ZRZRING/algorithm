#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int64>

void solve() {
    int n;
    std::cin >> n;
    std::cout << "Yes" << endl;
    std::vector<std::vector<int>> a(n + 2, std::vector<int>(n + 2, 1));

    int cnt = 1;
    if (n == 2) {
        std::cout << "1 2\n";
        std::cout << "3 4\n";
        return;
    }
    if (n == 3) {
        std::cout << "3 2 6\n";
        std::cout << "4 3 3\n";
        std::cout << "3 1 5\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0)
                a[i][j] = 1;
        }
    }
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 1)
                a[i][j] = ++cnt;
        }
    }
    for (int i = 3; i < n; i++) {
        cnt++;
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 1)
                a[i][j] = cnt;
        }
    }
    if (n % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            a[n][i] = a[1][i];
        }
        a[n][2] = 2 * n - 1;
        a[n][n - 1] = 2 * n;
    } else {
        for (int i = 1; i <= n; i++) {
            a[n][i] = a[2][i];
        }
        a[n][1] = 2 * n - 1;
        a[n][n - 1] = 2 * n;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }
}