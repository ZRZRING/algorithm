#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> void MOD(T &m) {m = (m % mod + mod) % mod;}
template <class T> T lg(T m) {return (T)log10(m);}
template <class T> T log(T m) {return (T)log2(m);}
template <class T> T abs(T m) {return m < 0 ? -m : m;}
template <class T> T mysqrt(T m) {return std::floor(sqrtl(m));}

struct WORK {
	int n, m;

	WORK() {}

	void solve() {
		std::string s;
		std::cin >> s;
		int n = s.length();
		std::set<int> fac;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				fac.insert(i);
				fac.insert(n / i);
			}
		}
		int flag = 1;
		for (auto m : fac) {
			std::vector<int> suf(m + 1);
			std::vector<std::vector<int>> vis(m, std::vector<int>(30));
			for (int i = 0; i < m; i++) {
				for (int j = i; j < n; j += m) {
					vis[i][s[j] - 'a']++;
					suf[i] = std::max(suf[i], vis[i][s[j] - 'a']);
				}
			}
			for (int i = m - 2; i >= 0; i--) {
				suf[i] += suf[i + 1];
			}
			std::string ans;
			ans.resize(m);
			if (2 * suf[0] < n) continue;
			int sum = 0;
			for (int s = 0; s < m; s++) {
				for (int i = 0; i < 26; i++) {
					if (2 * (vis[s][i] + sum + suf[s + 1]) >= n) {
						sum += vis[s][i];
						ans[s] = i + 'a';
						break;
					}
				}
			}
			std::cout << ans << endl;
			return;
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