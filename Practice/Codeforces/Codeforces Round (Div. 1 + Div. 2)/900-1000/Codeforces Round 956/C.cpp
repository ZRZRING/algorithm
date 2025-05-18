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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int64 n, tot = 0;
		std::cin >> n;
		std::vector<std::vector<int64>> a(3, std::vector<int64>(n + 1));
		for (int s = 0; s < 3; s++) {
			for (int i = 1; i <= n; i++) {
				std::cin >> a[s][i];
				tot += a[s][i];
			}
		}
		tot = (tot / 3 + 2) / 3;
		// std::cout << tot << endl;
		std::vector<int> o(3);
		o[0] = 0;
		o[1] = 1;
		o[2] = 2;
		do {
			int64 t;
			int l = 1, r = n;
			t = 0;
			for (int i = 1; i <= n; i++) {
				t += a[o[0]][i];
				if (t >= tot) {
					l = i + 1;
					break;
				}
			}
			t = 0;
			for (int i = n; i >= 1; i--) {
				t += a[o[2]][i];
				if (t >= tot) {
					r = i - 1;
					break;
				}
			}
			t = 0;
			std::vector<PII> ans(3);
			for (int i = l; i <= r; i++) {
				t += a[o[1]][i];
				if (t >= tot) {
					ans[o[0]] = {1, l - 1};
					ans[o[1]] = {l, r};
					ans[o[2]] = {r + 1, n};
					#define l first
					#define r second
					std::cout << ans[0].l << ' ' << ans[0].r << ' ';
					std::cout << ans[1].l << ' ' << ans[1].r << ' ';
					std::cout << ans[2].l << ' ' << ans[2].r << endl;
					return;
				}
			}
		} while (std::next_permutation(o.begin(), o.end()));
		std::cout << -1 << endl;
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