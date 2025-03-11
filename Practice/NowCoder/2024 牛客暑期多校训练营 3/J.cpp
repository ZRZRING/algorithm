#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
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

#define A2 std::array<int, 2>

A2 operator + (const A2 a, const A2 b) {
	return {a[0] + b[0], a[1] + b[1]};
}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, A, B;
		std::cin >> n >> A >> B;
		std::string s;
		std::cin >> s;
		int m = n + 2 * A - 1;
		while (s.length() < m) s = s + s;
		A2 cnt = {0, 0};
		int x, y;
		std::vector<std::vector<int>> to(n + 1, std::vector<int>(20));
		std::vector<std::vector<A2>> win(n + 1, std::vector<A2>(20));
		cnt[0] = cnt[1] = 0;
		x = 0;
		y = 0;
		while (cnt[0] < A && cnt[1] < A) {
			cnt[s[x] - '0']++;
			x++;
		}
		to[y][0] = x % n;
		win[y][0] = {cnt[0] == A, cnt[1] == A};
		for (int i = 1; i < n; i++) {
			cnt[s[y] - '0']--;
			y++;
			while (cnt[0] < A && cnt[1] < A) {
				cnt[s[x] - '0']++;
				x++;
			}
			to[y][0] = x % n;
			win[y][0] = {cnt[0] == A, cnt[1] == A};
		}
		// for (int i = 0; i < n; i++) {
		// 	std::cout << i << ' ' << to[i][0] << ' ' << win[i][0][1] << endl;
		// }
		for (int j = 1; j < 20; j++) {
			for (int i = 0; i < n; i++) {
				to[i][j] = to[to[i][j - 1]][j - 1];
				win[i][j] = win[i][j - 1] + win[to[i][j - 1]][j - 1];
			}
		}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < 4; j++) {
		// 		std::cout << i << ' ' << j << ' ' << to[i][j] << ' ' << win[i][j][1] << endl;
		// 	}
		// }
		std::vector<int> ans(n + 1);
		for (int i = 0; i < n; i++) {
			A2 cnt = {0, 0};
			int u = i;
			for (int j = 19; j >= 0; j--) {
				A2 t = cnt + win[u][j];
				if (t[0] < B && t[1] < B) {
					u = to[u][j];
					cnt = t;
				}
			}
			cnt = cnt + win[u][0];
			ans[i] = (cnt[1] == B);
		}
		for (int i = 0; i < n; i++) {
			std::cout << ans[i];
		}
		std::cout << endl;
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