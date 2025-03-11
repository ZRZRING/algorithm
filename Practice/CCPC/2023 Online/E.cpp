#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define endl '\n'

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n; std::cin >> n;
	std::string s;
	std::cin >> s;
	std::map<char, PII> mp;
	mp['L'] = {-1, 0};
	mp['R'] = {1, 0};
	mp['D'] = {0, -1};
	mp['U'] = {0, 1};
	std::set<PII> ans;
	for (int i = 0; i < 1 << n; i++) {
		int vis[50][50], x = 25, y = 25;
		bool flag = 0;
		memset(vis, -1, sizeof(vis));
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				vis[x][y] = 0;
				x += mp[s[j]].first; y += mp[s[j]].second;
				if (vis[x][y] == 1) {flag = 1; break;}
			} else {
				int tx = x + mp[s[j]].first, ty = y + mp[s[j]].second;
				if (vis[tx][ty] == 0) {flag = 1; break;}
				vis[tx][ty] = 1;
			}
		}
		if (!flag) ans.insert({x, y});
	}
	std::cout << ans.size() << endl;
	for (auto [x, y] : ans) {
		std::cout << x - 25 << ' ' << y - 25 << endl;
	}
	return 0;
}