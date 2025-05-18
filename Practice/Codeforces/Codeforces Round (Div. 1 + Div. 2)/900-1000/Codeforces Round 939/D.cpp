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
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int64 max = 0, T = 0;
		for (int S = 0; S < 1 << n; S++) {
			int64 sum = 0;
			for (int l = 0; l < n; l++) {
				if ((S >> l & 1) == 0) {
					sum += a[l];
				} else {
					int r = l;
					while (r + 1 < n && (S >> r + 1 & 1) == 1) {
						r++;
					}
					sum += (r - l + 1) * (r - l + 1);
					l = r;
				}
			}
			if (sum > max) {
				max = sum;
				T = S;
			}
		}
		std::vector<PII> ans;
		auto dfs = [&](auto self, int l, int r) -> void {
			if (l == r) {
				ans.push_back({l, r});
				return;
			}
			self(self, l, r - 1);
			for (int i = r - 2; i >= l; i--) {
				ans.push_back({l, i});
				self(self, l, i);
			}
			ans.push_back({l, r});
		};
		for (int l = 0; l < n; l++) {
			if ((T >> l & 1) == 0) continue;
			int r = l;
			while (r + 1 < n && (T >> r + 1 & 1) == 1) {
				r++;
			}
			for (int i = l; i <= r; i++) {
				if (a[i]) ans.push_back({i, i});
			}
			dfs(dfs, l, r);
			l = r;
		}
		std::cout << max << ' ' << ans.size() << endl;
		for (auto [x, y] : ans) {
			std::cout << x + 1 << ' ' << y + 1 << endl;
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