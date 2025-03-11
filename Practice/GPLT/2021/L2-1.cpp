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
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n, m, S;
	std::cin >> n >> m >> S;
	std::vector<std::string> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		std::reverse(a[i].begin(), a[i].end());
	}
	int opt = 0;
	std::string t, ans;	
	while (1) {
		std::cin >> opt;
		if (opt == -1) break;
		if (opt == 0) {
			if (t.empty()) continue;
			ans.push_back(t.back());
			t.pop_back();
		} else {
			if (a[opt].empty()) continue;
			if (t.size() == S) {
				ans.push_back(t.back());
				t.pop_back();
			}
			t.push_back(a[opt].back());
			a[opt].pop_back();
		}
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