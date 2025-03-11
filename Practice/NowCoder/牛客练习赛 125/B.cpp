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

	std::vector<int> prime, vis;

	WORK() {
		N = 1e5;
		vis.resize(N + 1);
		vis[1] = 1;
		for (int i = 2; i <= N; i++) {
			if (!vis[i]) {
				prime.push_back(i);
			}
			for (int j = 0; j < prime.size() && i * prime[j] <= N; j++) {
				vis[i * prime[j]] = 1;
				if (i % prime[j] == 0) {
					break;
				}
			}
		}
	}

	void solve() {
		int n;
		std::cin >> n;
		int flag = -1;
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			if (x == 3 || vis[x]) continue;
			if (flag == -1) flag = 0;
			else flag ^= 1;
		}
		std::cout << flag << endl;
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