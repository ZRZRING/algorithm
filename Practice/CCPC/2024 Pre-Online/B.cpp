#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T>
T lg(T x) {
    return (T)log10(x);
}
template <class T>
T log(T x) {
    return (T)log2(x);
}
template <class T>
T abs(T x) {
    return x < 0 ? -x : x;
}
template <class T>
T mysqrt(T x) {
    return std::floor(sqrtl(x));
}
template <class T>
T MOD(T& x, int64 p = mod) {
    return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
    return x = (x % p + p) % p;
}
template <class T1, class T2>
T1 getbit(T1 x, T2 t) {
    return x >> t & 1ll;
}

class WORK {
   public:
    int N;

    WORK() {}

    void solve() {
        int64 la, lb, lc, ld;
        std::cin >> la >> lb >> lc >> ld;
        int64 a2, b2, c2 = sqrtl(lb);
        for (int64 d = 1; d * d <= lb; d++) {
            if (lb % d != 0)
                continue;
            for (int64 i = 1; i * i < d; i++) {
                if (sqrtl(d - i * i) * sqrtl(d - i * i) == d - i * i) {
                    int64 j = sqrtl(d - i * i);
					std::cout << i << ' ' << j << '\n';
                    if (i == j)
                        continue;
                    a2 = 2 * t / d * i * j;
                    b2 = t / d * abs(i * i - j * j);
                    break;
                }
            }
            d = t / d;
            for (int64 i = 1; i * i < d; i++) {
                if (sqrtl(d - i * i) * sqrtl(d - i * i) == d - i * i) {
                    int64 j = sqrtl(d - i * i);
					std::cout << i << ' ' << j << '\n';
                    if (i == j)
                        continue;
                    a2 = 2 * t / d * i * j;
                    b2 = t / d * abs(i * i - j * j);
                    break;
                }
            }
        }
        A2 A, B, C, D;
        A = {0, int64(sqrtl(la))};
        B = {a2, b2};
        D = {0 + b2 - t, t + a2};
        C = {a2 + b2 - t, b2 + a2};
        std::cout << A[1] << ' ';
		std::cout << B[0] << ' ' << B[1] << ' ';
		std::cout << C[0] << ' ' << C[1] << ' ';
		std::cout << D[0] << ' ' << D[1] << '\n';
    }
};

int main() {
    Fast_IOS;
    WORK work;
    int T = 1;
    // std::cin >> T;
    while (T--) {
        work.solve();
    }
    return 0;
}