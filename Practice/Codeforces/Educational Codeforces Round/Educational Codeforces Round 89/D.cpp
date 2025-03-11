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

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int n = read();
	std::vector<PII> ans;
	std::vector<int> prime;
	std::vector<bool> is_not_prime(1e7 + 10);
	for (int i = 2; i <= 1e7; i++) {
		if (!is_not_prime[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] <= 1e7; j++) {
			is_not_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = read();
		bool flag = 0;
		for (int j = 0; prime[j] * prime[j] <= x && j < prime.size(); j++) {
			if (x % prime[j] == 0) {
				int t = 1;
				while (x % prime[j] == 0) t *= prime[j], x /= prime[j];
				if (x != 1) ans.push_back({t, x}), flag = 1;
				break;
			}
		}
		if (!flag) ans.push_back({-1, -1});
	}
	for (auto [x, y] : ans) printf("%d ", x); puts("");
	for (auto [x, y] : ans) printf("%d ", y); puts("");
	return 0;
}