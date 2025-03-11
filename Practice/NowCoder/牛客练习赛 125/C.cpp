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
		std::string s;
		std::cin >> s;
		int n = s.size(), ans = 0;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = s[i] - '0';
		}
		// if (n == 1) {
		// 	std::cout << s[0] - '0' << endl;
		// 	return;
		// }
		auto solve = [&](int x) -> int {
			int S;
			if (x > a[0]) {
				S = 2;
				x = a[0] * 10 + a[1] - x;
			} else {
				S = 1;
				x = a[0] - x;
			}
			for (int i = S; i < s.size(); i++) {
				if ()
			}
			if (d) return 0;
			return 1;
		};
		for (int i = 1; i < 10; i++) {
			ans += solve(i);
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