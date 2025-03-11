#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int, 2>
#define A26 std::array<int, 26>
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

class AC {
public:
	std::vector<int> vis, fail;

	std::vector<std::vector<int>> id;

	std::vector<A26> to;

	AC(int n) {
		id.push_back({});
		to.push_back({});
		vis.resize(n + 1);
	}

	void insert(std::string s, int t) {
		int x = 0, n = s.length();
		for (int i = 0; i < n; i++) {
			int d = s[i] - 'a';
			if (!to[x][d]) {
				id.push_back({});
				to.push_back({});
				to[x][d] = to.size() - 1;
			}
			x = to[x][d];
		}
		id[x].push_back(t);
	}

	void build() {
		fail.resize(to.size());
		std::queue<int> q;
		for (int i = 0; i < 26; i++) {
			if (to[0][i]) q.push(to[0][i]);
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < 26; i++) {
				int v = to[u][i];
				if (v) {
					fail[v] = to[fail[u]][i];
					q.push(v);
				} else {
					to[u][i] = to[fail[u]][i];
				}
			}
		}
	}

	void find(std::string s) {
		int n = s.length(), u = 0;
		for (int i = 0; i < n; i++) {
			int d = s[i] - 'a';
			u = to[u][d];
			for (int j = u; j; j = fail[j]) {
				for (auto x : id[j]) {
					vis[x] = 1;
				}
				id[j].clear();
			}
		}
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::string A, C;
		std::vector<std::string> B(n + 1);
		std::cin >> A >> C;
		AC ac(n);
		for (int i = 1; i <= n; i++) {
			std::string D;
			std::cin >> D >> B[i];
			ac.insert(D, i);
		}
		ac.build();
		ac.find(A);
		std::vector<int> fail(C.length() + 1), vis(n + 1);
		fail[0] = -1;
		for (int i = 1, j = -1; i < C.length(); i++) {
			while (~j && C[j + 1] != C[i]) j = fail[j];
			if (C[j + 1] == C[i]) j++;
			fail[i] = j;
		}
		for (int k = 1; k <= n; k++) {
			std::string D = B[k];
			for (int i = 0, j = -1; i < D.length(); i++) {
				while (~j && C[j + 1] != D[i]) j = fail[j];
				if (j + 1 < C.length() && C[j + 1] == D[i]) j++;
				if (j == C.length() - 1) {
					vis[k] = 1;
					break;
				}
			}
		}
		std::vector<int> ans;
		for (int i = 1; i <= n; i++) {
			// std::cout << ac.vis[i] << ' ' << vis[i] << endl;
			if (ac.vis[i] && vis[i]) {
				ans.push_back(i);
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			std::cout << ans[i] << " \n"[i == ans.size() - 1];
		}
	}
};

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}