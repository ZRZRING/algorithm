#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

int N = 2e5, T = 1;

std::vector<std::vector<A2>> P;

std::vector<int> np, prime, d, minp;

void init() {
	Fast_IOS;
	std::cin >> T;
	np.resize(N + 1);
	minp.resize(N + 1);
	for (int i = 2; i <= N; i++) {
		if (!np[i]) {
			minp[i] = i;
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && i * prime[j] <= N; j++) {
			np[i * prime[j]] = 1;
			minp[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	d.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			d[j]++;
		}
	}
	P.resize(N + 1);
	for (int i = 2; i <= N; i++) {
		int d = i, x = minp[i], cnt = 0;
		while (d > 1) {
			cnt = 0;
			while (d % x == 0) {
				d /= x;
				cnt++;
			}
			P[i].push_back({x, cnt});
			x = minp[d];
		}
	}
}

struct ANS {
	int B = 450, cnt = 0;

	std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> del_q;

	std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> ans_q;

	std::map<int, int> big;

	ANS() {
		ans_q.resize(B + 1);
		del_q.resize(B + 1);
		for (auto &x : ans_q) {
			x.push(1e9);
		}
		for (auto &x : del_q) {
			x.push(2e9);
		}
	}

	void add(int n) {
		// std::cout << "add " << n << '\n';
		for (auto [x, y] : P[n]) {
			if (x > B) {
				big[x]++;
			} else {
				ans_q[x].push(y);
			}
		}
		cnt++;
	}

	void del(int n) {
		// std::cout << "del " << n << '\n';
		for (auto [x, y] : P[n]) {
			if (x > B) {
				big[x]--;
				if (big[x] == 0) {
					big.erase(x);
				}
			} else {
				del_q[x].push(y);
			}
		}
		cnt--;
	}

	int query() {
		int ans = 1;
		for (int i = 0; prime[i] <= B; i++) {
			int x = prime[i];
			while (del_q[x].top() == ans_q[x].top()) {
				del_q[x].pop();
				ans_q[x].pop();
			}
			// std::cout << "heap " << x << " size " << ans_q[x].size() << '\n';
			if (ans_q[x].size() - del_q[x].size() != cnt) {
				continue;
			}
			int y = ans_q[x].top();
			if (y != 1e9) {
				while (y--) {
					ans *= x;
				}
			}
		}
		if (big.size() == 1) {
			auto [x, y] = *big.begin();
			if (y == cnt) ans *= x;
		}
		return ans;
	}
};

void solve() {
	int n, Q;
	std::cin >> n >> Q;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> vis(n + 1);
	ANS ans;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i + 1]) {
			ans.add(i);
		}
	}
	if (ans.cnt == 0) {
		std::cout << n << '\n';
	} else {
		std::cout << d[ans.query()] << '\n';
	}
	while (Q--) {
		int pos, t;
		std::cin >> pos >> t;
		if (pos + 1 <= n && a[pos] > a[pos + 1]) {
			ans.del(pos);
		}
		if (pos - 1 >= 1 && a[pos - 1] > a[pos]) {
			ans.del(pos - 1);
		}
		a[pos] = t;
		if (pos + 1 <= n && a[pos] > a[pos + 1]) {
			ans.add(pos);
		}
		if (pos - 1 >= 1 && a[pos - 1] > a[pos]) {
			ans.add(pos - 1);
		}
		if (ans.cnt == 0) {
			std::cout << n << '\n';
		} else {
			std::cout << d[ans.query()]  << '\n';
		}
	}
}


int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}