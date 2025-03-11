#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int, 2>
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
		int64 n;
		std::cin >> n;
		int64 ans = 1e18;
		for (int64 A = std::max(2ll, (int64)sqrtl(n) - 100); A <= sqrtl(n) + 100; A++) {
			if (A % 2 && n % 2) continue;
			int64 B = n / (A - 1), d = n % (A - 1);
			if (d) {
				if (d % 2 == A % 2) {
					B += 2;
				} else {
					B++;
				}
			}
			ans = std::min(ans, A + B);
		}
		std::cout << ans << endl;
	}
};

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}