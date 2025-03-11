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
		int n;
		std::cin >> n;
		std::string s, t;
		std::cin >> s >> t;
		s = " " + s;
		t = " " + t;
		std::vector<int> a(n + 1);
		std::vector<PII> ans;
		for (int i = 1; i <= n; i++) {
			a[i] = (s[i] == '1') ^ (t[i] == '1') ^ a[i - 1];
			if (i == n) break;
			if (a[i]) {
				ans.push_back({i, i + 1});
			}
		}
		if (a[n]) {
			std::cout << -1 << endl;
			return;
		} else {
			std::cout << ans.size() << endl;
			for (auto [x, y] : ans) {
				std::cout << x << ' ' << y << endl;
			}
		}
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