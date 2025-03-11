#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T MOD(T &x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		#define A2 std::array<int, 2>
		std::vector<int> a(2 * n + 2), to(2 * n + 2);
		std::vector<A2> seg(n + 1);
		seg[0] = {0, 2 * n + 1};
		for (int i = 1; i <= 2 * n; i++) {
			int x;
			std::cin >> x;
			a[i] = x;
			if (seg[x][0]) {
				seg[x][1] = i;
				to[i] = seg[x][0];
			} else {
				seg[x][0] = i;
			}
		}
		std::sort(seg.begin(), seg.end(), [&](A2 a, A2 b) {
			return a[1] - a[0] < b[1] - b[0];
		});
		std::vector<int64> f(n + 1);
		for (auto [L, R] : seg) {
			int x = a[L];
			std::vector<int64> g(2 * n + 2);
			g[L] = x;
			for (int i = L + 1; i <= R - 1; i++) {
				int y = a[i], l = to[i], r = i;
				if (l <= L || r >= R) {
					g[i] = g[i - 1] + x;
					continue;
				}
				g[i] = std::max(g[i - 1] + x, g[l - 1] + f[y]);
			}
			g[R] = g[R - 1] + x;
			f[x] = g[R];
		}
		std::cout << f[0] << endl;
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