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
	const int dx1[4] = {1, 0, 0, -1};
	const int dy1[4] = {0, -1, 1, 0};
	const int dx2[4] = {1, 0, 0, -1};
	const int dy2[4] = {0, 1, -1, 0};
	const char O[4] = {'D', 'L', 'R', 'U'};

	int n, m;

	WORK() {}

	void solve() {
		int n = 20;
		std::vector<std::string> m1(n + 2), m2(n + 2);

		m1[0].resize(n + 2);
		m2[0].resize(n + 2);
		m1[n + 1].resize(n + 2);
		m2[n + 1].resize(n + 2);
		std::fill(m1[0].begin(), m1[0].end(), '#');
		std::fill(m2[0].begin(), m2[0].end(), '#');
		std::fill(m1[n + 1].begin(), m1[n + 1].end(), '#');
		std::fill(m2[n + 1].begin(), m2[n + 1].end(), '#');
		for (int i = 1; i <= n; i++) {
			std::cin >> m1[i];
			std::cin >> m2[i];
			m1[i] = "#" + m1[i] + "#";
			m2[i] = "#" + m2[i] + "#";
		}

		#define V std::vector
		V<V<V<V<int>>>> f(n + 2, V<V<V<int>>>(n + 2, V<V<int>>(n + 2, V<int>(n + 2, -1))));
		V<V<V<V<int>>>> pre(n + 2, V<V<V<int>>>(n + 2, V<V<int>>(n + 2, V<int>(n + 2, -1))));
		V<V<V<V<int>>>> pre(n + 2, V<V<V<int>>>(n + 2, V<V<int>>(n + 2, V<int>(n + 2, -1))));
		#undef V

		f[n][n][n][1] = 0;
		std::queue<std::array<int, 4>> q;
		q.push({n, n, n, 1});
		while (!q.empty()) {
			auto [x1, y1, x2, y2] = q.front();
			if (x1 == 1 && y1 == n && x2 == 1 && y2 == 1) break;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int X1, Y1, X2, Y2;
				if (m1[x1 + dx1[i]][y1 + dy1[i]] == '#') {
					X1 = x1;
					Y1 = y1;
				} else {
					X1 = x1 + dx1[i];
					Y1 = y1 + dy1[i];
				}
				if (m2[x2 + dx2[i]][y2 + dy2[i]] == '#') {
					X2 = x2;
					Y2 = y2;
				} else {
					X2 = x2 + dx2[i];
					Y2 = y2 + dy2[i];
				}
				if (f[X1][Y1][X2][Y2] != -1) continue;
				f[X1][Y1][X2][Y2] = f[x1][y1][x2][y2] + 1;
				pre[X1][Y1][X2][Y2] = i; 
				q.push({X1, Y1, X2, Y2});
			}
		}

		int x1 = 1, y1 = n, x2 = 1, y2 = 1;
		std::string ans;
		while (pre[x1][y1][x2][y2] != -1) {
			int i = pre[x1][y1][x2][y2];
			ans.push_back(O[i]);
			x1 -= dx1[i];
			y1 -= dy1[i];
			x2 -= dx2[i];
			y2 -= dy2[i];
		}
		std::reverse(ans.begin(), ans.end());
		std::cout << ans.size() << endl << ans << endl;
		
		std::map<char, int> r;
		r['D'] = 0;
		r['L'] = 1;
		r['R'] = 2;
		r['U'] = 3;
		m1[n][n] = 'A';
		m2[n][1] = 'A';
		x1 = n, y1 = n, x2 = n, y2 = 1;
		for (auto x : ans) {
			x1 += dx1[r[x]];
			y1 += dy1[r[x]];
			x2 += dx2[r[x]];
			y2 += dy2[r[x]];
			m1[x1][y1] = 'A';
			m2[x2][y2] = 'A';
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				std::cout << m1[i][j];
			}
			std::cout << ' ';
			for (int j = 1; j <= n; j++) {
				std::cout << m2[i][j];
			}
			std::cout << endl;
		}
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