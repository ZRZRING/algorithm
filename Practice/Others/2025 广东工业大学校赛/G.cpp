#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
    std::ios::sync_with_stdio(false), \
    std::cin.tie(0), \
    std::cout.tie(0)

const int64 mod = 998244353;

const int N = 5e5 + 10;

int T = 1;

struct ICPC {
    std::vector<int> div;

    void init() {
        // Fast_IOS;
        // std::cin >> T;
        div.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j += i) {
                div[j]++;
            }
        }
    }

    void solve() {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        int d = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            if (a[i] != i) {
                d = std::__gcd(d, abs(i - a[i]));
            }
        }
        if (d == 0) {
            std::cout << n << '\n';
        } else {
            std::cout << div[d] << '\n';
        }
    }
};

int main() {
    ICPC icpc;
    icpc.init();
    while (T--) {
        icpc.solve();
    }
    return 0;
}