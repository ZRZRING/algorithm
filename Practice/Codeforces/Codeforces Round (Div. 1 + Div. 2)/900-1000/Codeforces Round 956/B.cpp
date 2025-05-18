#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 3;

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
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
		for (int i = 1; i <= n; i++) {
			std::string s;
			std::cin >> s;
			for (int j = 1; j <= m; j++) {
				int x = s[j - 1] - '0';
				a[i][j] = x;
			}
		}
		for (int i = 1; i <= n; i++) {
			std::string s;
			std::cin >> s;
			for (int j = 1; j <= m; j++) {
				int x = s[j - 1] - '0';
				a[i][j] = (a[i][j] + 3 - x) % 3;
			}
		}
		for (int i = 1; i < n; i++) {
			int k = 0, t = 0;
			for (int j = 1; j <= m; j++) {
				if (k && a[i][j]) {
					MOD(a[i][k] += t);
					MOD(a[i][j] += (t + 1 ^ 1) - 1);
					MOD(a[i + 1][k] += (t + 1 ^ 1) - 1);
					MOD(a[i + 1][j] += t);
					k = 0;
				}
				if (!k && a[i][j]) {
					k = j;
					t = 3 - a[i][j];
				}
			}
			if (k) {
				return (void)(std::cout << "NO" << endl);
			}
		}
		for (int j = 1; j <= m; j++) {
			if (a[n][j]) {
				return (void)(std::cout << "NO" << endl);
			}
		}
		std::cout << "YES" << endl;
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