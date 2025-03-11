#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 2097152;

template <class T> T MOD(T &x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class BIT {
public:
	#define lowbit(x) ((x) & -(x))

	int n;

	std::vector<int> bit;

	BIT() {}

	BIT(int n) : n(n) {
		bit.resize(n + 1);
		add(0, 1);
	}

	void add(int x, int t) {
		x++;
		for (int i = x; i <= n; i += lowbit(i)) {
			bit[i] += t;
		}
	}

	int query(int x) {
		x++;
		int res = 0;
		for (int i = x; i; i -= lowbit(i)) {
			res += bit[i];
		}
		return res;
	}

	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int T;
		std::cin >> T;
		std::vector<BIT> bit(21);
		for (int i = 0; i <= 20; i++) {
			bit[i] = BIT(1 << i + 1);
		}
		std::vector<int> a(1);
		while (T--) {
			int t;
			std::cin >> t;
			while (t--) {
				int x = a.back();
				for (int i = 0; i <= 20; i++) {
					bit[i].add(MOD(-x, 1 << i + 1), -1);
				}
				a.pop_back();
			}
			int x, ans = 0;
			std::cin >> x;
			MOD(x += a.back());
			a.push_back(x);
			for (int i = 0; i <= 20; i++) {
				int p = 1 << i + 1, d = 1 << i, l = MOD(d - x, p), r = MOD(p - 1 - x, p), cnt;
				if (l <= r) {
					cnt = bit[i].query(l, r);
				} else {
					cnt = bit[i].query(l, p - 1) + bit[i].query(0, r);
				}
				ans |= (1 << i) * (cnt & 1);
				bit[i].add(MOD(-x, 1 << i + 1), 1);
			}
			std::cout << ans << endl;
		}
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