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
		std::vector<PII> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i].first;
			a[i].second = i;
		}
		std::vector<PII> ans;
		for (int i = n - 1; i >= 1; i--) {
			std::vector<int> vis(i);
			for (int j = 1; j <= i; j++) {
				int t = MOD(a[i + 1].first - a[j].first, 1ll * i);
				if (t == 0) {
					ans.push_back({a[i + 1].second, a[j].second});
					break;
				} else {
					if (vis[t]) {
						// std::cout << i << ' ' << t << ' ' << vis[t] << ' ' << j << endl;
						std::swap(a[vis[t]], a[i + 1]);
						ans.push_back({a[i + 1].second, a[j].second});
						break;
					}
					vis[t] = j;
				}
			}
		}
		std::cout << "YES" << endl;
		std::reverse(ans.begin(), ans.end());
		for (auto [x, y] : ans) {
			std::cout << x << ' ' << y << endl;
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