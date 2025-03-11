#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
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
	int N = 1e7;

	std::vector<int> np, prime, sg;

	WORK() {
		np.resize(N + 1);
		sg.resize(N + 1);
		prime.push_back(2);
		sg[1] = 1;
		sg[2] = 0;
		np[4] = 1;
		for (int i = 3; i <= N; i++) {
			if (!np[i]) {
				prime.push_back(i);
				sg[i] = prime.size();
			}
			for (int j = 0; j < prime.size() && i * prime[j] <= N; j++) {
				np[i * prime[j]] = 1;
				sg[i * prime[j]] = sg[prime[j]];
				if (i % prime[j] == 0) break;
			}
		}
	}

	void solve() {
		int n;
		std::cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			// std::cout << sg[x] << '\n';
			ans ^= sg[x];
		}
		std::cout << (ans ? "Alice" : "Bob") << '\n';
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