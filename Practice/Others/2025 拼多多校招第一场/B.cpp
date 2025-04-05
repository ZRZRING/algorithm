#include <bits/stdc++.h>

std::vector<long long> ans;

int T = 1;

void init() {
    std::cin >> T;
    ans.resize(1000);
    for (int i = 0; i < 1000; i++) {
        int x = i;
        std::vector<int> a;
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
        int sum = 0;
        std::vector<int> vis(3);
        vis[0] = 1;
        for (int j = 0; j < a.size(); j++) {
            sum = (sum + a[j]) % 3;
            if (vis[sum]) {
                ans[i] = 1;
            }
            vis[sum] = 1;
        }
    }
    for (int i = 1; i < 1000; i++) {
        ans[i] += ans[i - 1];
    }
}

void solve() {
    long long L, R;
    std::cin >> L >> R;
    std::cout << ans[std::min(999ll, R)] - ans[std::min(999ll, L - 1)] + std::max(1000ll, R) - std::max(1000ll, L - 1) << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
}