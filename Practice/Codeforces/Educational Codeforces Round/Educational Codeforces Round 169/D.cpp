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
		std::vector<std::string> s(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> s[i];
		}
		std::vector<int> last(n + 1), next(n + 1);
		std::set<std::string> dict;
		std::map<std::string, int> vis;
		std::map<std::string, std::string> rev;
		dict = {
			"BG", "RY", "BR", "GY", "BY", "GR"
		};
		rev = {
			{"BG", "RY"},
			{"RY", "BG"},
			{"BR", "GY"},
			{"GY", "BR"},
			{"BY", "GR"},
			{"GR", "BY"}
		};
		for (int i = 1; i <= n; i++) {
			int max = -1e9;
			for (auto t : dict) {
				if (t == s[i] || t == rev[s[i]]) continue;
				// if (vis.find(t) == vis.end()) continue;
				max = std::max(max, vis[t]);
			}
			last[i] = max;
			vis[s[i]] = i;
		}
		vis.clear();
		for (int i = n; i >= 1; i--) {
			int min = 1e9;
			for (auto t : dict) {
				if (t == s[i] || t == rev[s[i]]) continue;
				// if (vis.find(t) == vis.end()) continue;
				min = std::min(min, vis[t]);
			}
			next[i] = min;
			vis[s[i]] = i;
		}
		while (Q--) {
			int l, r;
			std::cin >> l >> r;
			if (r < l) std::swap(l, r);
			if (s[l] != rev[s[r]] || last[r] > l || next[l] < r) {
				std::cout << r - l << '\n';
				continue;
			}
			// std::cout << last[r] << ' ' << next[l] << '\n';
			int t = std::min(l - last[r], next[l] - r) * 2 + r - l;
			if (t > 1e9) {
				std::cout << -1 << '\n';
			} else {
				std::cout << t << '\n';
			}
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