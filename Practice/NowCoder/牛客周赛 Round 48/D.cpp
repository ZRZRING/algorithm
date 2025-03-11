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
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int64 ans = 1e15, sum = 0;
		for (int i = 1; i < n; i++) {
			sum += abs(a[i] - a[i + 1]);
		}
		for (int i = 2; i <= n - 2; i++) {
			int64 t = sum;
			t -= abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i + 2]);
			t += abs(a[i - 1] - a[i] * 2) + abs(a[i] * 2 - a[i + 1] / 2) + abs(a[i + 1] / 2 - a[i + 2]);
			ans = std::min(ans, t);
		}
		for (int i = 2; i <= n - 2; i++) {
			int64 t = sum;
			t -= abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i + 2]);
			t += abs(a[i - 1] - a[i] / 2) + abs(a[i] / 2 - a[i + 1] * 2) + abs(a[i + 1] * 2 - a[i + 2]);
			ans = std::min(ans, t);
		}
		for (int i = 2; i <= n - 1; i++) {
			int64 t = sum;
			t -= abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]);
			t += abs(a[i - 1] - a[i] / 2 * 2) + abs(a[i] / 2 * 2 - a[i + 1]);
			ans = std::min(ans, t);
		}
		std::vector<int> up(n + 1), down(n + 1);
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                up[i] += abs(a[i] * 2 - a[i + 1]) - abs(a[i] - a[i + 1]);
                down[i] += abs(a[i] / 2 - a[i + 1]) - abs(a[i] - a[i + 1]);
            }
            if (i < n) {
                up[i] += abs(a[i] * 2 - a[i - 1]) - abs(a[i] - a[i - 1]);
                down[i] += abs(a[i] / 2 - a[i - 1]) - abs(a[i] - a[i - 1]);
            }
        }
		std::vector<int> pre_up(n + 2, 2e9);
		std::vector<int> pre_down(n + 2, 2e9);
		std::vector<int> suf_up(n + 2, 2e9);
		std::vector<int> suf_down(n + 2, 2e9);
		for (int i = 1; i <= n; i++) {
			pre_up[i] = std::min(pre_up[i - 1], up[i]);
			pre_down[i] = std::min(pre_down[i - 1], down[i]);
		}
		for (int i = n; i >= 1; i--) {
			suf_up[i] = std::min(suf_up[i + 1], up[i]);
			suf_down[i] = std::min(suf_down[i + 1], down[i]);
		}
		for (int i = 3; i <= n; i++) {
			int64 t = sum;
			t -= abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
			t += abs(a[i] / 2 - a[i - 1]) + abs(a[i] / 2 - a[i + 1]);
			t += pre_up[i - 2];
			ans = std::min(ans, t);
		}
		for (int i = 1; i <= n - 2; i++) {
			int64 t = sum;
			t -= abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
			t += abs(a[i] / 2 - a[i - 1]) + abs(a[i] / 2 - a[i + 1]);
			t += suf_up[i + 2];
			ans = std::min(ans, t);
		}
		for (int i = 3; i <= n; i++) {
			int64 t = sum;
			t -= abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
			t += abs(a[i] * 2 - a[i - 1]) + abs(a[i] * 2 - a[i + 1]);
			t += pre_down[i - 2];
			ans = std::min(ans, t);
		}
		for (int i = 1; i <= n - 2; i++) {
			int64 t = sum;
			t -= abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
			t += abs(a[i] * 2 - a[i - 1]) + abs(a[i] * 2 - a[i + 1]);
			t += suf_down[i + 2];
			ans = std::min(ans, t);
		}
		std::cout << ans << endl;
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