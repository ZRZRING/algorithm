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

struct WORK {
	int n, m;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<PII> a(m + 1);
		#define x first
		#define y second
		a[0] = {0, 0};
		for (int i = 1; i <= m; i++) {
			std::cin >> a[i].x >> a[i].y;
		}
		std::sort(a.begin(), a.end());
		int flag = 0;
		for (int i = 1; i <= m; i++) {
			if (a[i].x - a[i - 1].x != a[i].y - a[i - 1].y && a[i].x - a[i - 1].x - 1 < a[i].y) {
				std::cout << "No" << endl;
				return;
			}
		}
		std::cout << "Yes" << endl;
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