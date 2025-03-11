#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

struct WORK {
	int n, m;

	WORK() {}

	int64 qpow(int64 a, int64 x = mod - 2) {
		a %= mod;
		x %= mod - 1;
		int64 res = 1ll;
		while (x) {
			if (x & 1) {
				res = res * a % mod;
			}
			a = a * a % mod;
			x >>= 1;
		}
		return res;
	}

	void solve() {
		int64 m, a, b, c;
		std::cin >> m >> a >> b >> c;
		int64 A = m * (m - 1) * (m - 2) % mod * qpow(m * m * m) % mod * a % mod;
		int64 B = (m * m * m % mod - m * (m - 1) * (m - 2) % mod + mod - m + mod) % mod * qpow(m * m * m) % mod * b;
		int64 C = qpow(m * m) * c % mod;
		std::cout << (A + B + C) % mod << endl;
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