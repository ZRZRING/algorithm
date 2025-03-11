#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

int64 mod[2] = {998244353, 1e9 + 7}, base[2] = {131, 13331};

template <class b> b lg(b x) {return (b)log10(x);}
template <class b> b log(b x) {return (b)log2(x);}
template <class b> b abs(b x) {return x < 0 ? -x : x;}
template <class b> b mysqrt(b x) {return std::floor(sqrtl(x));}
template <class b> b MOD(b &x, b p) {return x = (x % p + p) % p;}
template <class b> b MOD(b &&x, b p) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 B) {return x >> B & 1ll;}

class WORK {
public:
	int N;

	WORK() {}

	int64 qpow(int64 a, int64 x, int64 mod) {
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
		std::string A, B;
		std::cin >> A >> B;
		int n = A.length(), m = B.length();
		#define A2 std::array<int64, 2>
		std::vector<A2> a(n + 1), b(m + 1), mul(n + 1);
		mul[0] = {1, 1};
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				mul[i][j] = mul[i - 1][j] * base[j] % mod[j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				MOD(a[0][j] = a[0][j] * base[j] + A[i] - 'A', mod[j]);
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				MOD(a[i][j] = (a[i - 1][j] - (A[i - 1] - 'A') * mul[n - 1][j] % mod[j]), mod[j]);
				MOD(a[i][j] *= base[j], mod[j]);
				MOD(a[i][j] += A[i - 1] - 'A', mod[j]);
			}
		}
		std::set<A2> s;
		for (int i = 0; i < n; i++) {
			s.insert(a[i]);
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < 2; j++) {
				MOD(b[i][j] = b[i - 1][j] * base[j] % mod[j] + B[i - 1] - 'A', mod[j]);
			}
		}
		int64 ans = 0;
		for (int i = n; i <= m; i++) {
			A2 tt;
			for (int j = 0; j < 2; j++) {
				tt[j] = MOD(b[i][j] - b[i - n][j] * mul[n][j] % mod[j], mod[j]);
			}
			ans += s.count({tt});
		}
		std::cout << ans << endl;
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