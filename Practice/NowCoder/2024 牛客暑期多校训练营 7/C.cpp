#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)ceil(log2(x));}
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
		std::vector<int> lg2(n + 1);
		lg2[1] = 0;
		for (int i = 2; i <= n; i++) {
			lg2[i] = lg2[i >> 1] + 1;
		}
		std::vector<std::vector<int>> ans;
		auto sort = [&](int L, int R, int k) -> void {
			for (int j = 13; j >= 0; j--) {
				std::vector<int> t;
				std::vector<int> vis(R);
				int B = 1 << j;
				for (int i = L; i < R; i++) {
					if (vis[i]) continue;
					int x = i, y = i + B;
					if (y >= R) continue;
					if (k) std::swap(x, y);
					t.push_back(x);
					t.push_back(y);
					vis[x] = 1;
					vis[y] = 1;
				}
				if (!t.empty()) ans.push_back(t);
			}
		};
		auto build = [&](auto self, int L, int R) -> void {
			int len = R - L;
			for (int B = 2; B <= len / 2; B *= 2) {
				// std::cout << "B: " << B << '\n';
				for (int C = B / 2; C >= 1; C /= 2) {
					// std::cout << "C: " << C << '\n';
					ans.push_back({});
					for (int i = L; i < R; i += C * 2) {
						// std::cout << "i: " << i << '\n';
						for (int j = i; j < i + C; j++) {
							// std::cout << "j: " << j << '\n';
							int x = j, y = j + C;
							if (((x - L) / B & 1) == 0) std::swap(x, y);
							ans.back().push_back(x);
							ans.back().push_back(y);
						}
					}
				}
			}
		};
		if ((n & -n) == n) {
			build(build, 0, n);
			sort(0, n, 0);
		} else {
			build(build, 0, 1 << lg2[n]);
			sort(0, 1 << lg2[n], 1);
			build(build, n - (1 << lg2[n]), n);
			sort(n - (1 << lg2[n]), n, 0);
			sort(0, n, 0);
		}
		std::cout << ans.size() << '\n';
		for (auto x : ans) {
			std::cout << x.size() / 2 << ' ';
			for (auto y : x) {
				std::cout << y << ' ';
			}
			std::cout << '\n';
		}
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}