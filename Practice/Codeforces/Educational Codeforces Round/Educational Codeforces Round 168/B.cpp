#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}
template <class T> T MOD(T &x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 t) {return x >> t & 1ll;}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<std::string> s(2);
		std::cin >> s[0] >> s[1];
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j < n - 1; j++) {
				if (s[i][j] == '.' && s[i ^ 1][j] == '.' && s[i][j + 1] == '.' && s[i][j - 1] == '.') {
					if (s[i ^ 1][j - 1] == 'x' && s[i ^ 1][j + 1] == 'x') {
						ans++;
					}
				}
			}
		}
		std::cout << ans << endl;
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