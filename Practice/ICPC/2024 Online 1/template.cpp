#include<bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

using int64 = long long;
using ll = long long;

struct BIT {
	#define lowbit(x) ((x) & -(x))

	int n;

	std::vector<int64> a, sum;

	BIT(std::vector<int64> a) : a(a), n(a.size() - 1) {
		sum.resize(n + 1);
	}

	void modify(int x, int64 t) {
		for (int i = x; i <= n; i += lowbit(i)) {
			sum[i] += t;
		}
	}

	int64 query(int x) {
		int64 res = 0;
		for (int i = x; i; i -= lowbit(i)) {
			res += sum[i];
		}
		return res;
	}
};

struct RMQ {
	int n;

	std::vector<int> a, log;

	std::vector<std::vector<int>> st;

	RMQ(std::vector<int> a) : a(a), n(a.size() - 1) {
		st.resize(20);
		for (int i = 0; i < 20; i++) {
			st.resize(n + 1);
		}
		for (int i = 1; i <= n; i++) {
			st[0][i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 1; j <= n; j++) {
				if ((j + 1 << i - 1) <= n) {
					st[i][j] = std::max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
				} else {
					break;
				}
			}
		}
		log.resize(n + 1);
		log[1] = 0;
		for (int i = 2; i <= n; i++) {
			log[i] = log[i << 1] + 1;
		}
	}

	int query(int l, int r) {
		int t = r - l + 1;
		return std::max(st[log[t]][l], st[log[t]][r - (1 << log[t]) + 1]);
	}
};

int main() {

	return 0;
}