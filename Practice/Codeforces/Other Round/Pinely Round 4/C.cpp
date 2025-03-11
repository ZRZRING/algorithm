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
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::vector<int> ans;
		for (int i = 0; i < 40; i++) {
			std::sort(a.begin(), a.end());
			n = std::unique(a.begin(), a.end()) - a.begin();
			a.resize(n);
			int x = (a[n - 1] + 1) / 2;
			for (int i = 0; i < n; i++) {
				a[i] = abs(x - a[i]);
			}
			ans.push_back(x);
		}
		std::sort(a.begin(), a.end());
		n = std::unique(a.begin(), a.end()) - a.begin();
		a.resize(n);
		if (a.size() != 1) {
			std::cout << -1 << endl;
			return;
		}
		std::cout << ans.size() << endl;
		for (auto x : ans) {
			std::cout << x << ' ';
		}
		std::cout << endl;
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