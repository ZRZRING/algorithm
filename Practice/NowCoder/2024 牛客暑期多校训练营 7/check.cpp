#include <bits/stdc++.h>
#include <windows.h>

using int64 = long long;

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
		int n, m;
		std::vector<std::vector<A2>> sort;
		std::cin >> n >> m;
		for (int i = 0; i < m; i++) {
			sort.push_back({});
			int k;
			std::cin >> k;
			for (int j = 0; j < k; j++) {
				int x, y;
				std::cin >> x >> y;
				sort[i].push_back({x, y});
			}
		}
		std::vector<int> a(n);
		std::iota(a.begin(), a.end(), 0);
		for (int i = 1; i <= 10000; i++) {
			std::random_shuffle(a.begin(), a.end());
			std::vector<int> b = a;
			for (auto s : sort) {
				for (auto [x, y] : s) {
					if (b[x] > b[y]) std::swap(b[x], b[y]);
				}
			}
			int flag = 0;
			for (int i = 1; i < n; i++) {
				if (b[i - 1] > b[i]) {
					flag = 1;
				}
			}
			if (flag) {
				std::cout << "No\n";
				for (auto x : a) {
					std::cout << x << ' ';
				}
				std::cout << '\n';
				for (auto x : b) {
					std::cout << x << ' ';
				}
				std::cout << '\n';
				system("pause");
			}
		}
		std::cout << "Yes\n";
	}
};

int main() {
	srand(time(0));
	// Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}