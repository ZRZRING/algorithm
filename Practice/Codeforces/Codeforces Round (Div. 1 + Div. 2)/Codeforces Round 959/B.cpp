#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T MOD(T &x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::string s, t;
		std::cin >> s >> t;
		int min = 0;
		while (min < n && s[min] != '1') min++;
		int c = 0;
		while (c < n && (s[c] ^ t[c]) == 0) c++;
		if (c >= min) std::cout << "YES" << endl;
		else std::cout << "NO" << endl;
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