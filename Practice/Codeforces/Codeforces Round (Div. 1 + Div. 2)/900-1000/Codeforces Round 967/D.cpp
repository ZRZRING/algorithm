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
		int n;
		std::cin >> n;
		std::map<int, int> pos;
		std::vector<A2> R;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			pos[a[i]] = i;
		}
		for (auto [x, y] : pos) {
			R.push_back({y, x});
		}
		std::sort(R.begin(), R.end());
		std::reverse(R.begin(), R.end());
		std::multiset<int> s;
		std::vector<int> vis(n + 1), ans;
		int l = 1, r = 0, p = -1;
		while (1) {
			while (!R.empty() && vis[R.back()[1]]) {
				R.pop_back();
			}
			if (R.empty()) {
				break;
			}
			while (r < R.back()[0]) {
				r++;
				if (vis[a[r]]) continue;
				s.insert(a[r]);
			}
			if (p == -1) {
				int t = *s.rbegin();
				while (a[l] != t) {
					auto it = s.find(a[l]);
					if (it != s.end()) s.erase(it);
					l++;
				}
				s.erase(t);
				vis[t] = 1;
				ans.push_back(t);
			} else {
				int t = *s.begin();
				while (a[l] != t) {
					auto it = s.find(a[l]);
					if (it != s.end()) s.erase(it);
					l++;
				}
				s.erase(t);
				vis[t] = 1;
				ans.push_back(t);
			}
			p = -p;
		}
		std::cout << ans.size() << '\n';
		for (auto x : ans) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}