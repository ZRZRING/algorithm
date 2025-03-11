#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'

int main() {
	int n, m;
	std::cin >> n;
	char t;
	t = getchar();
	std::map<std::string, std::vector<std::string>> vis;
	for (int i = 1; i <= n; i++) {
		std::string s, t;
		std::getline(std::cin, t);
		if (t[0] != ' ') s.push_back(t[0]);
		for (int j = 0; j + 1 < t.size(); j++) {
			if (t[j] == ' ' && t[j + 1] != ' ') {
				s.push_back(t[j + 1]);
			}
		}
//		std::cout << s << endl;
		vis[s].push_back(t);
	}
	std::cin >> m;
	t = getchar();
	for (int i = 1; i <= m; i++) {
		std::string s, t;
		std::getline(std::cin, t);
		if (t[0] != ' ') s.push_back(t[0]);
		for (int j = 0; j + 1 < t.size(); j++) {
			if (t[j] == ' ' && t[j + 1] != ' ') {
				s.push_back(t[j + 1]);
			}
		}
//		std::cout << s << endl;
		if (vis[s].empty()) {
			std::cout << t << endl;
			continue;
		}
		std::sort(vis[s].begin(), vis[s].end());
		int c = vis[s].size();
		for (int i = 0; i < c; i++) {
			std::cout << vis[s][i] << "|\n"[i == c - 1];
		}
	}
}
