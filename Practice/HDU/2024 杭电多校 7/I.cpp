#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353, UP = 1e9 + 1;

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
		int n, k;
		std::cin >> n >> k;
		std::vector<int> time(n + 1);
		std::vector<std::vector<A2>> e1(n + 1), e2(n + 1);
		std::vector<int> d1(n + 1, 0), d2(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			int opt;
			std::cin >> opt;
			if (opt == 1) {
				int k;
				std::cin >> k;
				for (int j = 1; j <= k; j++) {
					int t, x;
					std::cin >> t >> x;
					d1[x]++;
					e1[i].push_back({x, t});
					d2[i]++;
					e2[x].push_back({i, t});
				}
			} else {
				std::cin >> time[i];
			}
		}
		std::vector<int64> cnt(n + 1);
		cnt[k] = 1;
		std::queue<int> q;
		q.push(k);
		std::vector<int> d = d1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (time[u]) {
				cnt[u] = std::min(UP, cnt[u] * time[u]);
				continue;
			}
			for (auto [v, t] : e1[u]) {
				cnt[v] = std::min(UP, cnt[v] + (cnt[u] * t));
				d[v]--;
				if (!d[v]) q.push(v);
			}
		}
		std::vector<int64> fin(n + 1);
		for (int i = 1; i <= n; i++) {
			if (time[i]) q.push(i), fin[i] = cnt[i];
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto [v, t] : e2[u]) {
				fin[v] += fin[u];
				d2[v]--;
				if (!d2[v]) q.push(v);
			}
		}
		int max = 0;
		for (auto [x, t] : e1[k]) {
			if (fin[x] > fin[max]) max = x;
		}
		for (auto &[x, t] : e1[k]) {
			if (x == max) t = 0;
		}
		cnt.clear();
		cnt.resize(n + 1);
		cnt[k] = 1;
		q.push(k);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (time[u]) {
				cnt[u] = std::min(UP, cnt[u] * time[u]);
				continue;
			}
			for (auto [v, t] : e1[u]) {
				cnt[v] = std::min(UP, cnt[v] + (cnt[u] * t));
				d1[v]--;
				if (!d1[v]) q.push(v);
			}
		}
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!time[i]) continue;
			ans += cnt[i];
		}
		if (ans > 1e9) {
			std::cout << "Impossible\n";
		} else {
			std::cout << ans << '\n';
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