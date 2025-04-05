#include <bits/stdc++.h>

#define Fast_IOS                      \
    std::ios::sync_with_stdio(false), \
        std::cin.tie(0),              \
        std::cout.tie(0)

struct ICPC {
    using int64 = long long;
    using uint64 = unsigned long long;
    using A2 = std::array<int64, 2>;

    int64 mod = 998244353;

    int N = 1e5 + 10, T = 1;

    void init() {
        Fast_IOS;
        std::cin >> T;
    }

    void solve() {
        std::string s;
        std::cin >> s;
        int n = s.length();
        uint64 res;
        std::cin >> res;
        std::vector<int64> f(4);
        auto cal = [](char c) -> int {
            if (c == 'G') return 0;
            if (c == 'D') return 1;
            if (c == 'U') return 2;
            if (c == 'T') return 3;
            return -1;
        };
        uint64 mul = 1;
        std::reverse(s.begin(), s.end());
        for (int i = 0, j = cal(s[i]); i < n; i++, j = cal(s[i])) {
            if (s[i] == '+') {
                mul = 1;
                continue;
            }
            if (mul == 0 || f[j] == -1) {
                f[j] = -1;
            } else {
                f[j] += mul;
            }
            if (f[j] > 1e18) {
                f[j] = -1;
            }
            mul = (mul == 1e18 ? 0 : mul * 10);
        }
        std::vector<int64> g(4);
        for (g[0] = 0; g[0] < 10; g[0]++) {
            for (g[1] = 0; g[1] < 10; g[1]++) {
                for (g[2] = 0; g[2] < 10; g[2]++) {
                    uint64 sum = 0;
                    for (int i = 0; i < 3; i++) {
                        sum += f[i] * g[i];
                    }
                    if (sum == res) {
                        std::cout << "YES\n";
                        for (int i = 0; i < 4; i++) {
                            std::cout << g[i] << " \n"[i == 3];
                        }
                        return;
                    }
                    if (f[3] == 0 || f[3] == -1 || sum > res) {
                        continue;
                    }
                    uint64 rest = res - sum;
                    if (rest % f[3] != 0 || rest / f[3] >= 10) {
                        continue;
                    }
                    g[3] = rest / f[3];
                    std::cout << "YES\n";
                    for (int i = 0; i < 4; i++) {
                        std::cout << g[i] << " \n"[i == 3];
                    }
                    return;
                }
            }
        }
        std::cout << "NO\n";
    }
};

int main() {
    ICPC icpc;
    icpc.init();
    while (icpc.T--) {
        icpc.solve();
    }
    return 0;
}