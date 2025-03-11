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

struct WORK {
	int n, m;

	WORK() {}

	struct NODE {
		#define pos first
		#define val second

		int64 n, ans = 0;

		std::vector<int64> a;

		std::set<PII> s;

		NODE(int n) : n(n) {
			s.emplace(1, 0);
			s.emplace(n + 1, 1e15);
			a.resize(n + 1);
		}

		void update(int x, int64 t) {
			a[x] += t;
			auto it = std::prev(s.upper_bound({x, 1e15}));
			if (it->val > a[x]) return;
			ans -= (next(it)->pos - it->pos) * it->val;
			ans += (x - it->pos) * it->val + (next(it)->pos - x) * a[x];
			it = s.emplace(x, a[x]).first;
			// std::cout << it->pos << ' ' << it->val << endl;
			while (next(it)->val < it->val) {
				ans -= (next(it)->pos - x) * a[x] + (next(next(it))->pos - next(it)->pos) * next(it)->val;
				s.erase(next(it));
				ans += (next(it)->pos - x) * a[x];
			}
		}
	};

	void solve() {
		int n;
		int64 sum = 0, max = 0;
		std::cin >> n;
		std::vector<int64> a(n + 1);
		NODE f(n), g(n);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			max = std::max(max, a[i]);
			sum += a[i];
			f.update(i, a[i]);
			g.update(n - i + 1, a[i]);
		}
		int m;
		std::cin >> m;
		while (m--) {
			int x, t;
			std::cin >> x >> t;
			a[x] += t;
			sum += t;
			max = std::max(max, a[x]);
			f.update(x, t);
			g.update(n - x + 1, t);
			// std::cout << f.ans << endl;
			// std::cout << g.ans << endl;
			std::cout << f.ans + g.ans - sum - max * n << endl;
		}
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}