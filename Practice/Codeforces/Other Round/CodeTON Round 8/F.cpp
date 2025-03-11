#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353, B = 100;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n, Q;
	std::cin >> n >> Q;
	int O = (B - n % B) % B;
	n += O;
	std::vector<int64> A(n);
	for (int i = O; i < n; i++) {
		std::cin >> A[i];
	}
	int m = n / B;
	std::vector<int64> val(m), up(m);
	auto build = [&](int x) -> void {
		int l = x * B, r = l + B - 1;
		int64 res = 0;
		for (int i = l; i <= r; i++) {
			res = mysqrt(res + A[i]);
		}
		val[x] = res;
		res = val[x] + 1;
		for (int i = r; i >= l; i--) {
			if (res > 2e9) {
				up[x] = 2e18;
				return;
			}
			res = res * res - A[i];
		}
		up[x] = res;
	};
	for (int i = 0; i < m; i++) {
		build(i);
	}
	while (Q--) {
		int64 x, t;
		std::cin >> x >> t;
		x = x + O - 1;
		A[x] = t;
		build(x / B);
		int64 res = 0;
		for (int i = 0; i < m; i++) {
			res = val[i] + (res >= up[i]);
		}
		std::cout << res << endl;
	}
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