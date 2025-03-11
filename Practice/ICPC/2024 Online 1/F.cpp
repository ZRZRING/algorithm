#include<bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)
#define A3 std::array<int, 3>

using int64 = long long;
using ll = long long;

const int inf = 2e9;

struct DSU {
	int n;
	
	std::vector<int> fa;
	
	DSU(int n) : n(n) {
		fa.resize(n + 2);
		std::iota(fa.begin(), fa.end(), 0);
	}

	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		fa[y] = x;
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
		q.push(a[i]);
	}
	a[0] = {inf, 0, 0};
	a[n + 1] = {inf, n + 1, n + 1};
	DSU dsu(n);
	int64 ans = 0;
	std::map<A3, int> del;
	auto merge = [&](int x, int y) -> A3 {
		a[x] = {std::max(a[x][0], a[y][0]), std::min(a[x][1], a[y][1]), std::max(a[x][2], a[y][2])};
		return a[x];
	};
	while (q.top().at(2) - q.top().at(1) + 1 != n) {
		auto x = q.top();
		q.pop();
		if (del[x]) continue;
		int t = dsu.find(x[1]), t1 = dsu.find(x[1] - 1), t2 = dsu.find(x[2] + 1);
		A3 res;
		if (a[t1][0] < a[t2][0]) {
			del[a[t1]] = 1;
			if (a[t][0] < a[t2][0]) {
				ans += a[t][2] - a[t][1] + 1;
			}
			dsu.merge(t, t1);
			res = merge(t, t1);
		} else {
			del[a[t2]] = 1;
			if (a[t][0] < a[t2][0]) {
				ans += a[t][2] - a[t][1] + 1;
			}
			dsu.merge(t, t2);
			res = merge(t, t2);
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