#include <bits/stdc++.h>

#define Fast_IOS                      \
    std::ios::sync_with_stdio(false), \
        std::cin.tie(0),              \
        std::cout.tie(0)

using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using A2 = std::array<int64, 2>;

int64 mod = 998244353;

int N = 1e5 + 10, T = 1;

void init() {
    // Fast_IOS;
    // std::cin >> T;
}

struct Soldier {
    int cost, times;
};

void solve() {
    int64 n, S, sum = 0;
    std::cin >> n >> S;
    std::vector<Soldier> soldier(n);
    for (int i = 0; i < n; i++) {
        std::cin >> soldier[i].cost >> soldier[i].times;
    }
    std::sort(soldier.begin(), soldier.end(), [](Soldier a, Soldier b) {
        return a.times < b.times;
    });
    int p = 0;
    while (sum > S) {
        sum -= soldier[p].cost;
        p++;
        while (p < n && soldier[p].cost == soldier[p].cost) {
            sum -= soldier[p].cost;
            p++;
        }
    }
    int64 ans = 0, together = 0;
    if (p != 0) {
        together = soldier[p - 1].times;
    }
    ans = together * S;
    for (int i = p; i < n; i++) {
        ans += soldier[i].cost * (soldier[i].times - together);
    }
    std::cout << ans << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}