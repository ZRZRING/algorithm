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
	int N;

	WORK() {}

	void solve() {
		int n, m, d;
		std::cin >> n >> d;
		int ans = n;
		m = n + d;
		for (int i = 30; i >= 0; i--) {
			if (n >> i != m >> i) {
				ans |= (1 << i + 1) - 1;
				break;
			}
		}
		m = std::max(0, n - d);
		for (int i = 30; i >= 0; i--) {
			if (n >> i != m >> i) {
				ans |= (1 << i + 1) - 1;
				break;
			}
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