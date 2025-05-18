#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class TIRE {
	std::vector<std::array<int, 2>> ch;
	std::vector<int> max;

public:
	TIRE() {
		ch.push_back({0, 0});
		max.push_back(0);
	}

	void insert(int x, int t) {
		int u = 0;
		for (int i = 30; i >= 0; i--) {
			int X = x >> i & 1;
			if (!ch[u][X]) {
				ch.push_back({0, 0});
				max.push_back(t);
				ch[u][X] = ch.size() - 1;
			}
			u = ch[u][X];
			max[u] = t;
		}
	}

	int query(int x, int y) {
		int u = 0, ans = 0;
		for (int i = 30; i >= 0; i--) {
			int X = x >> i & 1, Y = y >> i & 1;
			if (Y == 1) {
				ans = std::max(ans, max[ch[u][X ^ Y ^ 1]]);
			}
			u = ch[u][X ^ Y];
			if (!u) return ans;
		}
		ans = std::max(ans, max[u]);
		return ans;
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int64 n, m;
		std::cin >> n >> m;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int64 l = 0, r = 2e9;
		auto check = [&](int x) -> bool {
			TIRE T;
			int64 ans = 0;
			T.insert(a[1], 1);
			for (int i = 2, j = 0; i <= n; i++) {
				j = std::max(j, T.query(a[i], x));
				ans += j;
				T.insert(a[i], i);
			}
			return ans >= m;
		};
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		std::cout << r << endl;
	}
};

int main() {
	Fast_IOS;
	// TIRE t;
	// t.insert(1, 1);
	// t.insert(2, 2);
	// t.insert(3, 3);
	// std::cout << t.query(4, 4) << endl;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}