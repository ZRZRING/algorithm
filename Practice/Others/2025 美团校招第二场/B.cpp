#include <bits/stdc++.h>

void solve() {
    int l1, r1, l2, r2;
    std::cin >> l1 >> r1 >> l2 >> r2;
    long long ans = 0;
    for (int i = l2; i <= std::min(r1, r2); i++) {
        for (int j = (i + l1 - 1) / i; i * j <= r1; j++) {
            // std::cout << i << ' ' << j << '\n';
            ans++;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }
}