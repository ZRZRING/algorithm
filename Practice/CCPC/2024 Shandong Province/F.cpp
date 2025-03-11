#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int64>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int64> a(n + 1);
    std::vector<int64> sum(n + 2);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        sum[i] = sum[i + 1] + a[i];
    }
    std::sort(sum.begin() + 2, sum.end() - 1, std::greater<int64>());
    int64 res = sum[1];
    std::cout << res << " \n"[n == 1];
    for (int i = 2; i <= n; i++) {
        res += sum[i];
        std::cout << res << " \n"[i == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}