#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

struct RMQ {
	int n;
	
	std::vector<std::array<int, 30>> fmin, fmax;
	
	RMQ(std::vector<int> a) {
		n = a.size() - 1;
		fmin.resize(n + 1);
		fmax.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			fmin[i][0] = fmax[i][0] = a[i];
		}
		for (int i = 1; i < 30; i++) {
			if (1 << i > n) break;
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				fmin[j][i] = std::min(fmin[j][i - 1], fmin[j + (1 << i - 1)][i - 1]);
				fmax[j][i] = std::max(fmax[j][i - 1], fmax[j + (1 << i - 1)][i - 1]);
			}
		}
	}
	
	int max(int l, int r) {
		int k = log(r - l + 1);
		return std::max(fmax[l][k], fmax[r - (1 << k) + 1][k]);
	}
	
	int min(int l, int r) {
		int k = log(r - l + 1);
		return std::min(fmin[l][k], fmin[r - (1 << k) + 1][k]);
	}
};

int solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	RMQ A(a);
	std::vector<std::vector<int64>> f(n + 1, std::vector<int64>(m + 1, 1e15));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; i - k - 1 >= 0 && j - k >= 0; k++) {
				// std::cout << i << ' ' << j << ' ' << k << endl;
				f[i][j] = std::min(f[i][j], f[i - k - 1][j - k] + 1ll * A.min(i - k, i) * (k + 1));
			}
		}
	}
	int64 ans = 1e15;
	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= m; j++) {
	// 		std::cout << (f[i][j] == 1e15 ? -1 : f[i][j]) << " \n"[j == m];
	// 	}
	// }
	for (int i = 0; i <= m; i++) {
		ans = std::min(ans, f[n][i]);
	}
	std::cout << ans << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}