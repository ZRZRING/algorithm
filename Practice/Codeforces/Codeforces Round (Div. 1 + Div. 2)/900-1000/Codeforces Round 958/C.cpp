#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int64 n;
		std::cin >> n;
		std::vector<int64> ans;
		for (int i = 60; i >= 0; i--) {
			int x = n >> i & 1ll;
			if (x == 1ll) {
				ans.push_back(n ^ 1ll << i);
			}
		}
		if (ans.size() == 1) {
			std::cout << 1 << endl;
			std::cout << n << endl;
			return;
		}
		std::cout << ans.size() + 1 << endl;
		for (auto x : ans) {
			std::cout << x << ' ';
		}
		std::cout << n << endl;
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