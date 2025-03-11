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
	int n, k;
	std::cin >> n >> k;
	int tk = 0, tn = 0, x;
	x = k;
	while (x) {
		x >>= 1;
		tk++;
	}
	x = n;
	while (x) {
		x >>= 1;
		tn++;
	}
	std::vector<int> ans;
	for (int i = 0; i < tn; i++) {
		if (i == tk - 1) continue;
		ans.push_back(1 << i);
	}
	ans.push_back(k + 1);
	ans.push_back(1 << tk | 1 << tk - 1);
	ans.push_back(k - (1 << tk - 1));
	std::cout << ans.size() << endl;
	for (auto x : ans) {
		std::cout << x << ' ';
	}
	std::cout << endl;
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