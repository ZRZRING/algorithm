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
	int N = 1e5, n, m;

	std::vector<int> np, prime, num;

	WORK() {
		np.resize(N + 1);
		num.resize(N + 1);
		for (int i = 2; i <= N; i++) {
			if (np[i] == 0) {
				prime.push_back(i);
			}
			for (int j = 0; j < prime.size() && i * prime[j] <= N; j++) {
				np[i * prime[j]] = 1;
				if (i % prime[j] == 0) break;
			}
		}
		for (int i = 0; i < prime.size(); i++) {
			num[prime[i]] = i;
		}
	}

	int pt(int x, int y) {
		return (x - 1) * n + y;
	}

	int pt(int x) {
		return n * m + x + 1;
	}

	void solve() {
		std::cin >> n >> m;
		std::vector<std::vector<PII>> e(n * m + prime.size() + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int64 x;
				std::cin >> x;
				for (int k = 0; k < prime.size(); k++) {
					int p = prime[k];
					if (1ll * p * p > x) break;
					if (x % p != 0) continue;
					e[pt(i, j)].push_back({pt(k), 0});
					e[pt(k)].push_back({pt(i, j), 1});
					while (x % p == 0) x /= p;
				}
				if (x != 1) {
					e[pt(i, j)].push_back({pt(num[x]), 0});
					e[pt(num[x])].push_back({pt(i, j), 1});
				}
				if (i + 1 <= n) e[pt(i, j)].push_back({pt(i + 1, j), 1});
				if (j + 1 <= n) e[pt(i, j)].push_back({pt(i, j + 1), 1});
			}
		}
		std::vector<int> vis(n * m + prime.size() + 1);
		std::vector<int> dis(n * m + prime.size() + 1, 1e9);
		std::priority_queue<PII, std::vector<PII>, std::greater<PII> > q;
		dis[1] = 0;
		q.push({0, 1});
		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto [v, t] : e[u]) {
				// std::cout << u << ' ' << v << ' ' << t << endl;
				if (dis[u] + t < dis[v]) {
					dis[v] = dis[u] + t;
					q.push({dis[v], v});
				}
			}
		}
		std::cout << dis[n * m] << endl;
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