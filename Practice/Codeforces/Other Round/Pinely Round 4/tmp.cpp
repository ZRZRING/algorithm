#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int, 2>
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
	int N = 262143;

	std::vector<int> prime, vis, ans;

	WORK() {
		vis.resize(N + 1);
		ans.resize(N + 1);
		vis[1] = 1;
		for (int i = 2; i <= N; i++) {
			if (!vis[i]) {
				prime.push_back(i);
			}
			for (int j = 0; j < prime.size() && i * prime[j] <= N; j++) {
				vis[i * prime[j]] = 1;
				if (i % prime[j] == 0) break;
			}
		}
		// for (int i = 1; i <= N; i++) {
		// 	std::vector<int> col(N + 1);
		// 	for (int j = 1; j < i; j++) {
		// 		if (!vis[i ^ j]) {
		// 			col[ans[j]] = 1;
		// 		}
		// 	}
		// 	for (int j = 1; j <= N; j++) {
		// 		if (col[j] == 0) {
		// 			ans[i] = j;
		// 			break;
		// 		}
		// 	}
		// }
	}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		int max = 0;
		vis.clear();
		vis.resize(41);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			std::cout << i << ' ' << a[i] << endl;
		}
	}
};

int main() {
	freopen("1.out", "r", stdin);
	freopen("1.ans", "w", stdout);
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}