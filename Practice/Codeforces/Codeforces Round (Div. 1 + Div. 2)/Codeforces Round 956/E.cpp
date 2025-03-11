#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 1e9 + 7;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class WORK {
public:
	int N;

	WORK() {}

	int64 qpow(int64 a, int64 x = mod - 2) {
		a %= mod;
		x %= mod - 1;
		int64 res = 1;
		while (x) {
			if (x & 1) res = res * a % mod;
			a = a * a % mod;
			x >>= 1;
		}
		return res;
	}

	void solve() {
		int64 n, k, sum1 = 0, sum2 = 0;
		std::cin >> n >> k;
		for (int i = 1; i <= k; i++) {
			int x;
			std::cin >> x;
			sum1 += x;
		}
		MOD(sum1);
		for (int i = k + 1; i <= n; i++) {
			int x;
			std::cin >> x;
			sum2 += x;
		}
		MOD(sum2);
		int y = n - k;
		// std::cout << y << endl;
		std::cout << (sum1 * (y + 2 >> 1) % mod * qpow(y + 1) % mod + sum2 * (y + 1 >> 1) % mod * qpow(y) % mod) % mod << ' ';
		std::cout << (sum1 * (y + 1 >> 1) % mod * qpow(y + 1) % mod + sum2 * (y >> 1) % mod * qpow(y) % mod) % mod << endl;
		// std::cout << (sum1 * 1ll * qpow(2) % mod + sum2 * qpow(2) % mod) % mod << endl;
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