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
		std::vector<std::string> S;
		while (std::getline(std::cin, s)) {
			S.push_back(s);
		}
		// std::sort(S.begin(), S.end());
		std::random_shuffle(S.begin(), S.end());
		int len = std::unique(S.begin(), S.end()) - S.begin();
		S.resize(len);
		for (auto x : S) {
			std::cout << x << endl;
		}
	}
};

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}