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

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::set<int>> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) {
			int p;
			std::cin >> p;
			while (p--) {
				int x;
				std::cin >> x;
				a[i].insert(x);
			}
		}
		std::vector<int> last(m + 1);
		for (int i = n; i >= 1; i--) {
			for (auto x : a[i]) {
				if (!last[x]) last[x] = i;
			}
		}
		for (int i = 2; i <= n; i++) {
			int flag = 0;
			for (auto x : a[i]) {
				if (last[x] != i) continue;
				if (a[i - 1].find(x) != a[i - 1].end()) flag = 1;
			}
			if (flag) continue;
			std::cout << "Yes" << endl;
			std::vector<int> ans(n + 1);
			std::iota(ans.begin(), ans.end(), 0);
			std::swap(ans[i - 1], ans[i]);
			for (int j = 1; j <= n; j++) {
				std::cout << ans[j] << " \n"[j == n];
			}
			return;
		}
		std::cout << "No" << endl;
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