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
		int n;
		std::cin >> n;
		std::vector<A2> ans;
		if (n == 5) {
			ans = {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}};
		} else if (n <= 6) {
			ans = {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}};
		} else {
			for (int i = 1; i <= 3; i++) {
				for (int j = i + 1; j <= n / 3 + 4 - i; j++) {
					ans.push_back({i, j});
				}
			}
			for (int i = 1; i <= n % 3; i++) {
				ans.push_back({1, n / 3 + 3 + i});
			}
			sort(ans.begin(), ans.end());
		}
		// std::cout << ans.size() << endl;
		for (int i = 0; i < n; i++) {
			std::cout << ans[i][0] << ' ' << ans[i][1] << endl;
		}
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