#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
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
		int n, Q;
		std::cin >> n >> Q;
		std::vector<int> fa(n + 1);
		std::vector to(n + 1, std::vector<int>());
		for (int i = 2; i <= n; i++) {
			int x;
			std::cin >> x;
			to[x].push_back(i);
			fa[i] = x;
		}
		std::vector<int> seq(n + 1), pos(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> seq[i];
			pos[seq[i]] = i;
		}
		std::vector son(n + 1, std::set<int>());
		std::vector<int> size(n + 1);
		auto dfs = [&](auto self, int u) -> void {
			size[u] = 1;
			for (auto v : to[u]) {
				self(self, v);
				son[u].insert(pos[v]);
				size[u] += size[v];
			}
		};
		dfs(dfs, 1);
		auto check = [&](int x) -> bool {
			if (son[x].empty()) return 1;
			int min = *son[x].begin(), max = *son[x].rbegin();
			return pos[x] < min && max + size[seq[max]] <= pos[x] + size[x];
		};
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!check(i)) cnt++;
		}
		while (Q--) {
			int i, j, x, y;
			std::cin >> i >> j;
			x = seq[i];
			y = seq[j];
			std::set<int> s;
			s.insert(x);
			s.insert(y);
			s.insert(fa[x]);
			s.insert(fa[y]);
			for (auto t : s) {
				if (t && !check(t)) cnt--;
			}
			son[fa[x]].erase(i);
			son[fa[y]].erase(j);
			std::swap(seq[i], seq[j]);
			std::swap(pos[x], pos[y]);
			son[fa[x]].insert(j);
			son[fa[y]].insert(i);
			for (auto t : s) {
				if (t && !check(t)) cnt++;
			}
			std::cout << (cnt == 0 ? "YES\n" : "NO\n");
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