#include <bits/stdc++.h>

struct DATA {
    std::string s;
    int x, y;
};

void solve() {
    int n;
    std::cin >> n;
    #define A2 std::array<int, 2>
    std::vector<A2> a(4);
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        if (s[1] == 'D') a[0][0]++;
        if (s[1] == 'C') a[1][0]++;
        if (s[1] == 'H') a[2][0]++;
        if (s[1] == 'S') a[3][0]++;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        while (a[i][0] >= 5) ans++, a[i][0] -= 5;
    }
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i][1];
    }
    int t0, t1;
    std::cin >> t0 >> t1;
    int t = t0 + t1;
    // for (auto [x, y] : a) {
    //     std::cout << x << ' ' << y << '\n';
    // }
    while (1) {
        std::sort(a.begin(), a.end(), [&](A2 a, A2 b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
        });
        // for (auto [x, y] : a) {
        //     std::cout << x << ' ' << y << '\n';
        // }
        if (a[0][1] == 0) break;
        if (a[0][0] < 2) break;
        int sum = 0;
        for (int i = 0; i < 4; i++) sum += a[i][0];
        // std::cout << sum << '\n';
        if (sum < 5) break;
        int cnt = std::min(3, 5 - a[0][0]), tmp = cnt, j = 3;
        // std::cout << tmp << '\n';
        while (j > 0 && tmp) {
            int tt = std::min(tmp, a[j][0]);
            tmp -= tt;
            a[j][0] -= tt;
            j--;
        }
        a[0][0] += cnt - tmp;
        a[0][1] = 0;
        if (a[0][0] >= 5) {
            ans++;
            a[0][0] -= 5;
        }
    }
    std::sort(a.begin(), a.end(), [&](A2 a, A2 b) {
        return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
    });
    if (a[0][1] == 1) {
        int cnt = 3, tmp = cnt, j = 3;
        // std::cout << tmp << '\n';
        while (j > 0 && a[j][0] != 4 && tmp) {
            int tt = std::min(tmp, a[j][0]);
            tmp -= tt;
            a[j][0] -= tt;
            j--;
        }
        a[0][0] += cnt - tmp;
        a[0][1] = 0;
    }
    std::sort(a.rbegin(), a.rend());
    // for (auto [x, y] : a) {
    //     std::cout << x << ' ' << y << '\n';
    // }
    if (t == 1) {
        if (a[0][0] == 4 && a[1][0] >= 1) ans++;
    }
    if (t == 2) {
        if (a[0][0] == 4 && a[1][0] == 4 && a[2][0] + a[3][0] >= 2) {
            ans += 2;
        } else if (a[0][0] == 3 && a[1][0] + a[2][0] + a[3][0] >= 2) {
            ans++;
        } else if (a[0][0] == 4 && a[1][0] >= 1) {
            ans++;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}