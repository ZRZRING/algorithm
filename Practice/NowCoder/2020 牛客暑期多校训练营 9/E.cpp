#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

struct NODE {
	int64 p, k1, k2, k;
};

int64 qpow(int64 a, int64 x = mod - 2) {
	a %= mod;
	x %= mod - 1;
	int64 res = 1;
	while (x) {
		if (x & 1) res = res * a % mod;
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}

int solve() {
	int64 L1, R1, L2, R2, X, Y;
	std::cin >> L1 >> R1 >> L2 >> R2 >> X >> Y;
	int n = std::max(X, Y), m = std::max(R1, R2);
	std::vector<int> vis(1e5 + 1), prime;
	for (int i = 2; i <= 1e5; i++) {
		if (!vis[i]) {
			prime.push_back(i);
		}
		for (int j = 0; i * prime[j] <= 1e5 && j < prime.size(); j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	std::vector<NODE> res;
	for (auto t : prime) {
		if (X % t == 0 && Y % t == 0) {
			int cnt1 = 0, cnt2 = 0;
			while (X % t == 0) {
				cnt1++;
				X /= t;
			}
			while (Y % t == 0) {
				cnt2++;
				Y /= t;
			}
			res.push_back({t, cnt1, cnt2, 0});
			continue;
		}
		while (X % t == 0) {
			X /= t;
		}
		while (Y % t == 0) {
			Y /= t;
		}
	}
	if (X > 1 && X == Y) {
		res.push_back({X, 1, 1, 0});
	}
	int64 ans = 1;
	auto cal = [&](int64 l, int64 r) -> int64 {
		if (l > r) return 0;
		return (l + r) * (r - l + 1ll) / 2ll;
	};
	for (auto x : res) {
		// std::cout << x.p << ' ' << x.k1 << ' ' << x.k2 << endl;
		for (int i = L1; i <= R1; i++) {
			int64 d = i * x.k1 / x.k2;
			x.k += cal(L2, std::min(R2, d)) * x.k2 % (mod - 1);
			x.k += std::max(0ll, R2 - std::max(L2 - 1, d)) * x.k1 % (mod - 1) * i % (mod - 1);
			x.k %= mod - 1;
		}
		// std::cout << x.p << ' ' << x.k << endl;
		ans = ans * qpow(x.p, x.k) % mod;
	}
	std::cout << ans << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}