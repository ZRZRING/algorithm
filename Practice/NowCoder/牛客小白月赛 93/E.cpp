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

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::string s;
		std::cin >> s;
		s = " " + s;
		std::vector<int64> cnt0(n + 1), cnt1(n + 1);
		std::vector<int64> sum0(n + 1), sum1(n + 1);
		std::vector<int64> ans(n + 1);
		for (int i = 1; i <= n; i++) {
			cnt0[i] = cnt0[i - 1] + (s[i] == '0');
			cnt1[i] = cnt1[i - 1] + (s[i] == '1');
			MOD(sum0[i] = sum0[i - 1] + i * (s[i] == '0'));
			MOD(sum1[i] = sum1[i - 1] + i * (s[i] == '1'));
			if (s[i] == '0') {
				MOD(ans[i] = ans[i - 1] + cnt1[i - 1] * i - sum1[i - 1]);
			} else {
				MOD(ans[i] = ans[i - 1] + cnt0[i - 1] * i - sum0[i - 1]);
			}
		}
		for (int i = 1; i <= m; i++) {
			int l, r;
			std::cin >> l >> r;
			int64 res = 0;
			MOD(res += ans[r] - ans[l - 1]);
			MOD(res -= (cnt0[r] - cnt0[l - 1]) * (l * cnt1[l - 1] - sum1[l - 1]));
			MOD(res -= (cnt1[r] - cnt1[l - 1]) * (l * cnt0[l - 1] - sum0[l - 1]));
			MOD(res -= cnt0[l - 1] * (sum1[r] - sum1[l - 1] - l * (cnt1[r] - cnt1[l - 1])));
			MOD(res -= cnt1[l - 1] * (sum0[r] - sum0[l - 1] - l * (cnt0[r] - cnt0[l - 1])));
			std::cout << res << endl;
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