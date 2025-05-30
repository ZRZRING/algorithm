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

	int gcd(int a, int b) {
		if (a < b) std::swap(a, b);
		return b ? gcd(b, a % b) : a;
	}

	void solve() {
		int n, m = 0;
		std::cin >> n;
		std::vector<int> vis(1e5 + 1);
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			m = std::max(m, x);
			vis[x] = 1;
		}
		int cnt = 0;
		for (int i = m; i >= 1; i--) {
			if (vis[i]) continue;
			int d = 0;
			for (int j = i + i; j <= m; j += i) {
				if (vis[j]) {
					d = gcd(d, j / i);
				}
			}
			if (d == 1) {
				// std::cout << i << '\n';
				vis[i] = 1;
				cnt++;
			}
		}
		std::cout << (cnt % 2 == 1 ? "dXqwq" : "Haitang") << '\n';
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