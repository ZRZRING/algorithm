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
		std::string s;
		std::cin >> s;
		int n = s.length();
		std::vector<int64> cnt(30);
		int64 ans = 0;
		for (int i = 0; i < n; i++) {
			if (i < n - i - 1) cnt[s[n - i - 1] - 'a'] += i + 1;
			else cnt[s[i] - 'a'] -= n - i;
			for (int j = 0; j < 26; j++) {
				if (j == s[i] - 'a') continue;
				ans += cnt[j];
			}
		}
		std::reverse(s.begin(), s.end());
		for (int i = 0; i < n; i++) {
			if (i < n - i - 1) cnt[s[n - i - 1] - 'a'] += i + 1;
			else cnt[s[i] - 'a'] -= n - i;
			for (int j = 0; j < 26; j++) {
				if (j == s[i] - 'a') continue;
				ans += cnt[j];
			}
		}
		for (int i = 0; i < n - i - 1; i++) {
			if (s[i] != s[n - i - 1]) ans -= i + 1;
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