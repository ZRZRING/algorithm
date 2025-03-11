#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T MOD(T &x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int64 n, x, y;
		std::cin >> n >> x >> y;
		std::string s;
		std::cin >> s;
		s = " " + s;
		if (x == 0 && y == 0) {
			std::cout << n * (n + 1ll) / 2ll << endl;
			return;
		}
		std::vector<std::array<int, 2>> a(n + 1);
		a[0] = {0, 0};
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'A') {
				a[i] = {a[i - 1][0] - 1, a[i - 1][1]};
			}
			if (s[i] == 'D') {
				a[i] = {a[i - 1][0] + 1, a[i - 1][1]};
			}
			if (s[i] == 'S') {
				a[i] = {a[i - 1][0], a[i - 1][1] - 1};
			}
			if (s[i] == 'W') {
				a[i] = {a[i - 1][0], a[i - 1][1] + 1};
			}
		}
		int64 ans = 0;
		std::map<PII, int> map;
		for (int i = n; i >= 0; i--) {
			if (map.find({a[i][0] + x, a[i][1] + y}) != map.end()) {
				ans += n - map[{a[i][0] + x, a[i][1] + y}] + 1;
			}
			// std::cout << ans << endl;
			map[{a[i][0], a[i][1]}] = i;
		}
		std::cout << ans << endl;
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