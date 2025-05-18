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
	int64 A, B, ans = 0;
	std::cin >> A >> B;
	for (int a = 1; a * a <= A; a++) {
		for (int b = 1; b * b <= B; b++) {
			if (std::__gcd(a, b) != 1) continue;
			ans += std::min(A / a, B / b) / (a + b);
		}
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