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
		int n, m;
		std::string s;
		std::cin >> s >> m;
		n = s.length();
		std::string ans;
		int t = m;
		for (int i = 0; i < n && ans.size() < n - m; i++) {
			int pos = i;
			for (int j = i; j <= std::min(n - 1, i + t); j++) {
				if (s[j] < s[pos]) pos = j;
			}
			t -= pos - i;
			ans.push_back(s[pos]);
			i = pos;
		}
		while (ans.front() == '0') ans.erase(0, 1);
		if (ans.empty()) std::cout << 0 << endl;
		else std::cout << ans << endl;
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