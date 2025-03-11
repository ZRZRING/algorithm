#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int64>

const int64 mod = 998244353;

void solve() {
    int64 n, m;
    std::cin >> n >> m;
    #define l first
    #define r second
    std::vector<PII> a(n + 1);
	std::set<int64> s;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].l >> a[i].r;
		s.insert(a[i].l);
		s.insert(a[i].r);
    }
	std::vector<int64> S(1);
	for (auto x : s) {
		S.push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		a[i].l = std::lower_bound(S.begin(), S.end(), a[i].l) - S.begin();
		a[i].r = std::lower_bound(S.begin(), S.end(), a[i].r) - S.begin();
	}
	std::sort(a.begin() + 1, a.end(), [](PII a, PII b) {
		return a.l < b.l;
	});
	std::vector<int64> f(n + 1);
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		while (!q.empty() && q.top() < a[i].l) q.pop();
		int64 t = m - q.size();
		q.push(a[i].r);
		f[i] = f[i - 1] * t % mod;
	}
	std::cout << f[n] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}