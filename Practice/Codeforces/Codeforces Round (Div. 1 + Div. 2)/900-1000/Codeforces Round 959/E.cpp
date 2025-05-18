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
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			for (int j = 1; j < a[i]; j++) {
				int x;
				std::cin >> x;
			}
		}
		std::sort(a.begin() + 1, a.end());
		std::reverse(a.begin() + 1, a.end());
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			for (int j = 19; j >= 0; j--) {
				int x = a[i] >> j & 1;
				if (x == 0) continue;
				int y = ans >> j & 1;
				if (y == 0) {
					ans |= 1 << j;
				} else {
					ans |= (1 << j) - 1;
				}
			}
		}
		std::cout << ans << endl;
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