#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

void solve() {
    int64 n, m;
    std::cin >> n >> m;
    std::vector<int64> cost(n + 1), cap(n + 1), down(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> cost[i] >> cap[i] >> down[i];
    }
    int64 l = 0, r = 2e18;
    auto check = [&](int64 x) -> bool {
        int64 sum = 0;
        for (int i = 1; i <= n; i++) {
            int64 t = x, c = t / (cost[i] * cap[i] + down[i]);
            sum += cap[i] * c;
            if (sum >= m) return 1;
            t -= c * (cost[i] * cap[i] + down[i]);
            sum += std::min(cap[i], t / cost[i]);
            if (sum >= m) return 1;
        }
        return sum >= m;
    };
    while (l < r) {
        int64 mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << r << endl;
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