#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int, 2>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

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
		int n, m, s;
		std::cin >> n >> m >> s;
		std::vector<int> d(n + 1);
		std::vector<std::vector<int>> e(n + 1);
		for (int i = 1; i <= m; i++) {
			int u, v;
			std::cin >> u >> v;
			d[u]++;
			d[v]++;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		std::vector<int64> dis_x(n + 1), dis_n(n + 1);
		auto bfs = [&](std::vector<int64> dis, int S) -> void {
			std::queue<int> q;
			std::vector<int> vis(n + 1);
			vis[1] = 1;
			q.push(S);
			dis[S] = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (auto v : e[u]) {
					if (vis[v]) continue;
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		};
		bfs(dis_x, s);
		bfs(dis_n, n);
		if (d[n] < 2) {
			std::cout << "Boring Game" << endl;
			return;
		}
		std::cout << "Vegetable fallleaves" << endl;
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