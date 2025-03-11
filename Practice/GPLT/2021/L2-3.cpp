#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a;
	std::map<std::vector<int>, int> s;
	for (int i = 1; i <= n; i++) {
		a.clear();
		for (int j = 1; j <= m; j++) {
			int x;
			std::cin >> x;
			a.push_back(x);
		}
		s[a]++;
	}
	typedef std::pair<std::vector<int>, int> PVI;
	std::vector<PVI> S(s.begin(), s.end());
	std::sort(S.begin(), S.end(), [](PVI a, PVI b) {
		if (a.second < b.second) return 0;
		if (b.second < a.second) return 1;
		for (int i = 0; i < a.first.size(); i++) {
			if (a.first[i] < b.first[i]) return 1;
			if (b.first[i] < a.first[i]) return 0;
		}
		return 0;
	});
	std::cout << S.size() << endl;
	for (int i = 0; i < S.size(); i++) {
		std::cout << S[i].second << ' ';
		int c = S[i].first.size();
		for (int j = 0; j < c; j++) {
			std::cout << S[i].first[j] << " \n"[j == c - 1];
		}
	}
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