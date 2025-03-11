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

class DOT {
public:
	int x, y;
	
	DOT(int x, int y): x(x), y(y) {}

	friend bool operator < (const DOT a, const DOT b) {
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	}
};

class WORK {
public:
	int N;

	WORK() {}

	bool check(std::set<DOT> a) {
		for (auto [x, y] : a) {
			if (a.count(DOT(x + 1, y)) == 1) continue;
			if (a.count(DOT(x - 1, y)) == 1) continue;
			if (a.count(DOT(x, y + 1)) == 1) continue;
			if (a.count(DOT(x, y - 1)) == 1) continue;
			return 0;
		}
		return 1;
	}

	void solve() {
		int n, m, k;
		std::cin >> k >> n >> m;
		std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
		std::set<DOT> origin;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x;
				std::cin >> x;
				if (x == 0) continue;
				origin.push_back(DOT(i, j));
			}
		}
		if (check(origin) == 0) {
			std::cout << -1;
			return;
		}
		std::set<std::set<DOT>> all, ans;
		ans.push_back();
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}