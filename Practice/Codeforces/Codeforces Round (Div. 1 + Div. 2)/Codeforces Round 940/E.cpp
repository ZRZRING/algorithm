#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 1e9 + 7;

template <class T> T MOD(T &x) {return x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n = 1e6;
	std::vector<int> prime, vis(n + 1);
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	std::vector<int64> ans(2 * n + 1);
	for (auto j : prime) {
		for (int i = 1; i * j <= n; i++) {
			int t = (j - 1) * i % j;
			MOD(ans[i * j] += t);
			MOD(ans[(i + 1) * j] -= t);
		}
	}
	for (int i = 1; i * 4 <= n; i++) {
		int t = 6 * i % 4;
		MOD(ans[i * 4] += t);
		MOD(ans[(i + 1) * 4] -= t);
	}
	std::vector<int64> res(n + 1);
	for (int i = 1; i <= n; i++) {
		MOD(ans[i] += ans[i - 1]);
		MOD(res[i] = ans[i] + res[i - 1]);
	}
	int Q;
	std::cin >> Q;
	while (Q--) {
		int x;
		std::cin >> x;
		std::cout << res[x] << endl;
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