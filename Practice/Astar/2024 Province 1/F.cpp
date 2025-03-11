#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long
#define A4 std::array<int64, 4>

#define lowbit(x) (x & -x)

const int64 mod = 998244353;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> ans, num;
	while (n) {
		int t = lowbit(n);
		n -= lowbit(n);
		ans.push_back(t >> 1 - 1);
		num.push_back(t);
	}
	ans[ans.size() - 1] = num.back();
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << ' ' << num[i] << endl;
	}
}

int main() {
	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}