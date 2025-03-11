#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), d(n + 1);
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 0; i < n; i++) {
		int m;
		std::cin >> m;
		while (m--) {
			int x;
			std::cin >> x;
			e[x].push_back(i);
			d[i]++;
		}
	}
	std::queue<int> q;
	std::vector<int> f(n + 1), to(n + 1, -1);
	for (int i = 0; i < n; i++) {
		if (!d[i]) q.push(i), f[i] = 1;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : e[u]) {
			if (f[u] + 1 > f[v] || f[u] + 1 == f[v] && u < to[v]) {
				f[v] = f[u] + 1;
				to[v] = u;
			}
			if (!--d[v]) q.push(v);
		}
	}
	int S = 0;
	for (int i = 0; i < n; i++) {
		if (e[i].size() == 0) S = i;
	}
	std::cout << f[S] << endl;
	int u = S;
	while (to[u] != -1) {
		std::cout << u << ' ';
		u = to[u];
	}
	std::cout << u << endl;
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