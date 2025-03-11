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

int solve() {
	int64 n, k;
	std::cin >> n;
	std::map<int64, int64> a, b;
	for (int i = 1; i <= n; i++) {
		int64 x;
		std::cin >> x;
		a[x]++;
	}
	std::cin >> k;
	int64 ans = a[k];
	while (!a.empty()) {
		for (auto [x, y] : a) {
			if ((x + 2) / 3 < k) continue;
			b[(x + 2) / 3] += y * 2;
		}
		ans = std::max(ans, b[k]);
		if (b[k] == 0) b.erase(k);
		a.swap(b);
		b.clear();
	}
	std::cout << ans << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}