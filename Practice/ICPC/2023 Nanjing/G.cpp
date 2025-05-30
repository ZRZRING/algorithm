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
		int n, m, k;
		std::cin >> n >> m >> k;
		std::vector<PII> a(n + 1);
		std::vector<int> w(n + 1), val(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i].first >> a[i].second;
		}
		std::sort(a.begin(), a.end());
		for (int i = 1; i <= n; i++) {
			w[i] = a[i].first;
			val[i] = a[i].second;
		}
		std::vector<int64> max(n + 1);
		std::vector<std::vector<int64>> f(n + 1, std::vector<int64>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < w[i]; j++) {
				f[i][j] = f[i - 1][j];
				max[i] = std::max(max[i], f[i][j]);
			}
			for (int j = w[i]; j <= m; j++) {
				f[i][j] = std::max(f[i - 1][j], f[i - 1][j - w[i]] + val[i]);
				max[i] = std::max(max[i], f[i][j]);
			}
		}
		int64 ans = max[n];
		std::priority_queue<int, std::vector<int>, std::greater<int>> q;
		int64 sum = 0;
		for (int i = n; i >= 1; i--) {
			q.push(val[i]);
			sum += val[i];
			if (q.size() > k) {
				sum -= q.top();
				q.pop();
			}
			ans = std::max(ans, sum + max[i - 1]);
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