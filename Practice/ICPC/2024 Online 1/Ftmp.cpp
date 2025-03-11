#include<bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)
#define A3 std::array<int, 3>

using int64 = long long;
using ll = long long;

const int inf = 2e9;

struct DSU {
	int n;

	std::vector<int> fa;

	std::vector<A3> d;

	DSU(std::vector<int> a) : n(n) {
		d.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			d[i] = {i, i, i};
		}
	}

	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	
	A3 merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return d[x];
		fa[y] = x;
		int t;
		if (d[x] == d[y]) {
			t = 0;
		} else if (d[x][0] > d[y][0]) {
			t = d[y][2] - d[y][1] + 1;
		} else {
			t = d[x][2] - d[x][1] + 1;
		}
		d[x] = {std::max(d[x][0], d[y][0]), std::min(d[x][1], d[y][1]), std::max(d[x][2], d[y][2])};
		return d[x];
	}
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<A3> a(n + 2);
	std::priority_queue<A3, std::vector<A3>, std::greater<A3>> q;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		a[i] = {x, i, i};
		q.push({x, i, i});
	}
	a[0] = {inf, 0, 0};
	a[n + 1] = {inf, 0, 0};
	DSU dsu(a);
	int64 ans = 0;
	std::map<A3, int> del;
	while (q.top().at(2) - q.top().at(0) + 1 != n) {
		auto [t, l, r] = q.top();
		q.pop();
		if (del[{t, l, r}]) continue;
		A3 t = a[dsu.find(l)], t1 = a[dsu.find(l - 1)], t2 = a[dsu.find(r + 1)], res;
		if (dsu.max[t1] < dsu.max[t2]) {
			res = dsu.merge(t, t1);
			ans += res[0];
		} else {
			res = dsu.merge(t, t2);
			ans += res[0];
		}
		q.push(res);
	}
	std::cout << ans << '\n';
}

int main() {
	IOS;
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}