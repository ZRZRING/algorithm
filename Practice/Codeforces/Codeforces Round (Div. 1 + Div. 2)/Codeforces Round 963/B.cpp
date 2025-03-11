#include <bits/stdc++.h>

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
		int n;
		std::cin >> n;
		std::vector<int64> a;
		int64 max = 0;
		for (int i = 1; i <= n; i++) {
			int64 x;
			std::cin >> x;
			if (x % 2 == 1) {
				max = std::max(max, x);
			} else {
				a.push_back(x);
			}
		}
		if (max == 0 || a.empty()) {
			std::cout << 0 << '\n';
			return;
		}
		std::sort(a.begin(), a.end());
		int64 ans = 0, flag = 0;
		for (auto x : a) {
			if (max < x) {
				flag = 1;
				break;
			} else {
				max += x;
			}
		}
		std::cout << (flag ? a.size() + 1 : a.size()) << '\n';
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