#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

#define lowbit(x) ((x) & -(x))

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int64 l, r;
	std::cin >> l >> r;
	std::vector<PII> ans;
	while (r && l <= r - lowbit(r)) {
		ans.push_back({r - lowbit(r), r});
		r -= lowbit(r);
	}
	while (l && l + lowbit(l) <= r) {
		ans.push_back({l, l + lowbit(l)});
		l += lowbit(l);
	}
	std::sort(ans.begin(), ans.end());
	std::cout << ans.size() << endl;
	for (auto [x, y] : ans) {
		std::cout << x << ' ' << y << endl;
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