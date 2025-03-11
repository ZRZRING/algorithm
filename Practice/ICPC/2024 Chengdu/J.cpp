#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

class ICPC {
public:
	int N, T = 1;

	ICPC() {
		Fast_IOS;
		std::cin >> T;
	}

	void solve() {
		int n, m, Q;
		std::cin >> n >> m >> Q;
		std::vector<int> score(n + 1, m);
		std::vector<A2> ans(m + 1);
		for (int i = 1; i <= m; i++) {
			ans[i][1] = i;
		}
		int start = 0;
		std::map<A2, int> vis;
		while (Q--) {
			int o;
			std::cin >> o;
			if (o == 1) {
				int x;
				std::cin >> x;
				start = x;
			}
			if (o == 2) {
				int id, x;
				std::cin >> id >> x;
				if (start != x) continue;
				if (vis[{id, x}]) continue;
				vis[{id, x}] = 1;
				ans[id][0] += score[x];
				score[x]--;
			}
			if (o == 3) {
				int id, x;
				std::cin >> id >> x;
				if (start != x) continue;
				vis[{id, x}] = 1;
			}
		}
		std::sort(ans.begin() + 1, ans.end(), [](A2 a, A2 b) {
			return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
		});
		for (int i = 1; i <= m; i++) {
			std::cout << ans[i][1] << ' ' << ans[i][0] << '\n';
		}
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}