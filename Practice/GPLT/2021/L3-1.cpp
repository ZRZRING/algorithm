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

typedef std::string STR;

int solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<STR> > a(n + 1);
	for (int i = 1; i <= n; i++) {
		STR s;
		std::cin >> s;
		int l, r;
		for (l = 0, r = 0; r < s.length(); r++) {
			if (s[r] == '.') {
				a[i].push_back(s.substr(l, r - l));
				l = r + 1;
			}
		}
		a[i].push_back(s.substr(l, r - l));
	}
	int cnt = 0;
	std::unordered_map<STR, int> d;
	std::unordered_map<STR, std::vector<STR>> e;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			d[a[i][j]] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (a[i].size() != a[i - 1].size()) continue;
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] == a[i - 1][j]) continue;
			e[a[i - 1][j]].push_back(a[i][j]);
			d[a[i][j]]++;
			break;
		}
	}
	std::priority_queue<STR, std::vector<STR>, std::greater<STR>> q;
	for (auto [x, y] : d) {
		if (!d[x]) q.push(x);
	}
	std::vector<std::string> ans;
	while (!q.empty()) {
		auto u = q.top();
		q.pop();
		ans.push_back(u);
		for (auto v : e[u]) {
			if (!--d[v]) q.push(v);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << ".\n"[i == ans.size() - 1];
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
