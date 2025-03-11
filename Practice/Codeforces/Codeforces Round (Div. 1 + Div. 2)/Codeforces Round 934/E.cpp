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
	std::vector<int> d(n);
	std::vector<std::vector<int>> e(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;
		v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	auto bfs = [&](int s) {
		std::vector<int> d(n, -1);
		std::queue<int> q;
		q.push(s);
		d[s] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : e[u]) {
				if (d[v] != -1) continue;
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
		return d;
	};
	std::vector<int> d1 = bfs(0);
	int a = std::max_element(d1.begin(), d1.end()) - d1.begin();
	std::vector<int> d2 = bfs(a);
	int b = std::max_element(d2.begin(), d2.end()) - d2.begin();
	std::vector<int> d3 = bfs(b);
	std::vector<int> t;
	int dia = d2[b];
	// std::cout << dia << endl;
	for (int i = 0; i < n; i++) {
		if (d2[i] + d3[i] != dia) continue;
		if (d2[i] == dia / 2 || d3[i] == dia / 2) {
			t.push_back(i);
		}
	}
	std::vector<PII> ans;
	if (t.size() == 1) {
		for (int i = 0; i <= dia / 2; i++) {
			ans.push_back({t[0] + 1, i});
		}
	} else {
		if (dia % 4 == 3) {
			for (int i = 1; i <= dia / 2; i += 2) {
				ans.push_back({t[0] + 1, i});
			}
			for (int i = 1; i <= dia / 2; i += 2) {
				ans.push_back({t[1] + 1, i});
			}
		} else {
			for (int i = 0; i <= dia / 2; i += 2) {
				ans.push_back({t[0] + 1, i});
			}
			for (int i = 0; i <= dia / 2; i += 2) {
				ans.push_back({t[1] + 1, i});
			}
		}
	}
	std::cout << ans.size() << endl;
	for (auto [x, y] : ans) {
		std::cout << x << ' ' << y << endl;
	}
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