#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int, 2>
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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m, a, b;
		std::cin >> n >> m >> a >> b;
		if (n > m) std::swap(n, m);
		if (1ll * n * m % 2ll == 1ll) {
			std::cout << "No" << endl;
			return;
		}
		if (n == 1 && m == 2) {
			std::cout << "Yes" << endl;
			return;
		}
		if (!a && !b) { // 长短都不可以
			std::cout << "No" << endl;
			return;
		}
		if (!a) { // 长可以 短不可以
			if (n == 1) {
				std::cout << "No" << endl;
			} else {
				std::cout << "Yes" << endl;
			}
			return;
		}
		if (!b) { // 长不可以 短可以
			std::cout << (n == 1 ? "Yes" : "No") << endl;
			return;
		}
		std::cout << "Yes" << endl;
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}