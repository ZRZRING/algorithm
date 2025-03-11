#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}
template <class T> T MOD(T &x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 t) {return x >> t & 1ll;}

int64 pow(int64 a, int64 x) {
	int64 c = 1;
	for (int i = 1; i <= x; i++) {
		c *= a;
	}
	return c;
}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int64 n, a, b, ans = 0;
		std::cin >> n >> a >> b;
		auto check = [](int64 x) -> bool {
			if (int64(sqrtl(x)) * int64(sqrtl(x)) == x) return 1;
			return 0;
		};
		for (int i = a; i <= b; i++) {
			int64 i1 = i / pow(10, n / 2);
			int64 i2 = i % pow(10, n / 2);
			if (check(i1) && check(i2)) {
				ans++;
			}
		}
		std::cout << ans << '\n';
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