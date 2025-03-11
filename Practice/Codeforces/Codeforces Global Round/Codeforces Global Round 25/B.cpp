#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}

int solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::swap(a[k], a[1]);
	int ans1 = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[1]) break;
		ans1++;
	}
	std::swap(a[k], a[1]);
	int t = 0;
	for (int i = 1; i <= k; i++) {
		if (a[i] > a[k]) {
			std::swap(a[i], a[k]);
			t = i;
			break;
		}
	}
	if (!t) {
		std::cout << ans1 << endl;
		return 0;
	}
	int ans2 = t != 1;
	for (int i = t + 1; i <= n; i++) {
		if (a[i] > a[t]) break;
		ans2++;
	}
	std::cout << std::max(ans1, ans2) << endl;
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