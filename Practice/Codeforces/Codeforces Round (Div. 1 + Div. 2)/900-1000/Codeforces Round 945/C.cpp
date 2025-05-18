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
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<int> ans(n + 1), pmin(n + 2), smin(n + 2);
		pmin[0] = 1e9;
		pmin[1] = a[1];
		smin[n + 1] = 1e9;
		smin[n] = a[n];
		for (int i = 2; i <= n; i++) {
			pmin[i] = std::min(pmin[i - 2], a[i]);
		}
		for (int i = n - 1; i >= 1; i--) {
			smin[i] = std::min(smin[i + 2], a[i]);
		}
		int s = 2;
		for (int i = 2; i <= n; i += 2) {
			if (std::min(pmin[i - 2], smin[i + 1]) > std::min(pmin[s - 2], smin[s + 1])) {
				s = i;
			}
		}
		std::set<PII> s1, s2;
		for (int i = s + 1; i <= n + 1; i += 2) {
			if (i <= n - 1) s1.emplace(a[i], i);
			if (i - 1 <= n) s2.emplace(a[i - 1], i - 1);
			if (i + 1 <= n) s2.emplace(a[i + 1], i + 1);
		}
		for (int i = s - 2; i >= 0; i -= 2) {
			if (i >= 2) s1.emplace(a[i], i);
			if (i - 1 >= 1) s2.emplace(a[i - 1], i - 1);
			if (i + 1 >= 1) s2.emplace(a[i + 1], i + 1);
		}
		int p = n;
		for (auto it = s1.begin(); it != s1.end(); it++) {
			auto [x, y] = *it;
			ans[y] = p--;
		}
		p = 1;
		for (auto it = s2.rbegin(); it != s2.rend(); it++) {
			auto [x, y] = *it;
			ans[y] = p++;
		}
		for (int i = 1; i <= n; i++) {
			std::cout << ans[i] << " \n"[i == n];
		}
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