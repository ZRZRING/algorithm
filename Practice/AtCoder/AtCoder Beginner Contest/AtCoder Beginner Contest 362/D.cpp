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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<std::vector<PII>> e(n + 1);
		for (int i = 1; i <= m; i++) {
			int u, v, t;
			std::cin >> u >> v >> t;
			e[u].push_back({v, t});
			e[v].push_back({u, t});
		}
		std::vector<int64> dis(n + 1, 2e15), vis(n + 1);
		std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
		q.push({0, 1});
		dis[1] = a[1];
		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto [v, t] : e[u]) {
				if (dis[u] + t + a[v] < dis[v]) {
					dis[v] = dis[u] + t + a[v];
					q.push({dis[v], v});
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			std::cout << dis[i] << " \n"[i == n];
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