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
	int N = 1e6;

	WORK() {}

	int gcd(int a, int b) {
		if (a < b) std::swap(a, b);
		return b ? gcd(b, a % b) : a;
	}

	void solve() {
		int s, x;
		std::cin >> s >> x;
		if (gcd(s, x) == 1) {
			std::cout << 1 << '\n' << s << '\n';
			return;
		}
		std::vector<int> ans;
		if (s % 2 == 1 && x % 2 == 0) {
			s--;
			ans.push_back(1);
		}
		for (int i = 1; i <= N; i++) {
			if (gcd(i, x) == 1 && gcd(abs(s - i), x) == 1) {
				ans.push_back(i);
				ans.push_back(s - i);
				break;
			}
		}
		std::cout << ans.size() << '\n';
		for (auto x : ans) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
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