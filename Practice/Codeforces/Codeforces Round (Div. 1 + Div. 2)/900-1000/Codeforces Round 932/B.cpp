#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

int solve() {
	int n;
	std::cin >> n;
	int mex1 = 0, mex2 = 0;
	std::vector<int> a(n + 1), vis1(n + 1), vis2(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		vis2[a[i]]++;
	}
	while (vis2[mex2]) mex2++;
	for (int i = 1; i < n; i++) {
		vis2[a[i]]--;
		vis1[a[i]]++;
		if (vis2[a[i]] == 0) mex2 = std::min(mex2, a[i]);
		while (vis1[mex1]) mex1++;
		if (mex1 == mex2) {
			printf("2\n%d %d\n%d %d\n", 1, i, i + 1, n);
			return 0;
		}
	}
	std::cout << -1 << endl;
	return 0;
}

int main() {
	// Fast_IOS;
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