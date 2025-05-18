#include <bits/stdc++.h>

int cal(std::string s) {
	int res = 0;
	res += (s[0] - '0') * 10 * 60 * 60;
	res += (s[1] - '0') * 60 * 60;
	res += (s[3] - '0') * 10 * 60;
	res += (s[4] - '0') * 60;
	res += (s[6] - '0') * 10;
	res += (s[7] - '0');
//	std::cout << res << '\n';
	return res;
}

int main() {
	int n;
	std::cin >> n;
	int N = 24 * 60 * 60;
	std::vector<int> vis(N + 1);
	for (int i = 1; i <= n; i++) {
		std::string s, t;
		std::cin >> s >> t;
		int l = cal(s), r = cal(t);
		vis[r + 1]--;
		vis[l]++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (i) vis[i] += vis[i - 1];
		ans = std::max(ans, vis[i]);
	}
	std::cout << ans << '\n';
}
