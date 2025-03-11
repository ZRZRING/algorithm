#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	int n, k, p;
	std::cin >> n >> k >> p;
	std::vector<int> t(n + 1), d(n + 1);
	std::vector<int64> f(n + 1, 1e15);
	std::vector<std::vector<int>> col(k + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> t[i];
		col[t[i]].push_back(i);
	}
	int64 sum = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i];
		sum += d[i];
	}
	f[0] = 0;
	std::vector<std::priority_queue<PII, std::vector<PII>, std::greater<PII>>> q(k + 1);
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + d[i];
		if (!q[t[i]].empty() && q[t[i]].top().second) {
			f[i] = std::min(f[i], f[q[t[i]].top().second - 1]);
		}
		q[t[i]].push({f[i - 1], i});
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << f[i] << ' ';
	// }
	// std::cout << endl;
	std::cout << sum - f[n] << endl;
	return 0;
}