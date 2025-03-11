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
		int n, m, t;
		std::cin >> n >> m >> t;
		int x, y;
		std::string s;
		std::cin >> x >> y >> s;
		x--;
		y--;
		std::vector<std::string> a(n, std::string(m, ' '));
		for (int i = 0; i < n; i++) {
			a[i].resize(m);
			for (int j = 0; j < m; j++) {
				a[i][j] = (i ^ j) & 1 ? 'A' : 'B';
			}
		}
		if (a[x][y] != s[0]) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					a[i][j] = a[i][j] == 'A' ? 'B' : 'A';
				}
			}
		}
		int l = n + m, r = n + m;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (a[i][j] == 'A' && a[i + 1][j + 1] == 'A' && a[i + 1][j] == 'B' && a[i][j + 1] == 'B') {
					r++;
				}
			}
		}
		if (t < l || t > r) {
			std::cout << "No" << endl;
			return;
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (r > t && a[i][j] == 'A' && a[i + 1][j + 1] == 'A' && a[i + 1][j] == 'B' && a[i][j + 1] == 'B') {
					if (x == i && y == j) {
						a[i][j + 1] = a[i][j + 1] == 'A' ? 'B' : 'A';
					} else {
						a[i][j] = a[i][j] == 'A' ? 'B' : 'A';
					}
					r--;
				}
			}
		}
		std::cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << endl;
		}
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