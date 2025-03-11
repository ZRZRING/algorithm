#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct DSU {
	std::vector<int> fa;

	DSU (int n) {
		fa.resize(n + 1);
		std::iota(fa.begin(), fa.end(), 0);
	}

	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}

	void merge(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) fa[y] = x;
	}
};

int main() {
	int n = read(), m = read(), Q = read();
	std::string s;
	std::cin >> s;
	int all = 0;
	for (auto x : s) all += x == '1';
	DSU dsu(n);
	std::vector<int> q;
	for (int i = 0; i < m; i++) {
		int l = read() - 1, r = read();
		for (int j = dsu.find(l); j < r; j = dsu.find(j)) {
			q.push_back(j); dsu.merge(j + 1, j);
		}
	}
	int cnt = 0, RK = 0, size = q.size();
	std::vector<int> rank(n, 0);
	for (auto x : q) rank[x] = ++RK;
	for (int i = 0; i < std::min(all, size); i++) cnt += s[q[i]] == '1';
	while (Q--) {
		int x = read() - 1;
		if (s[x] == '0') {
			all++; cnt += all <= size && s[q[all - 1]] == '1';
			s[x] = '1'; cnt += rank[x] && rank[x] <= all;
		} else {
			cnt -= all <= size && s[q[all - 1]] == '1'; all--;
			s[x] = '0'; cnt -= rank[x] && rank[x] <= all;
		}
		// std::cout << std::min(all, size) << ' ' << cnt << ' ' << s << endl;
		printf("%d\n", std::min(all, size) - cnt);
	}
	return 0;
}