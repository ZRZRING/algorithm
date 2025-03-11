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

	WORK() {}
	
	struct NODE {
		int val, ls, rs;
	};

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<PII> seg(m + 1);
		#define l first
		#define r second
		for (int i = 1; i <= m; i++) {
			std::cin >> seg[i].l;
		}
		for (int i = 1; i <= m; i++) {
			std::cin >> seg[i].r;
		}
		std::sort(seg.begin() + 1, seg.end(), [](PII a, PII b) {
			return std::min(a.l, a.r) > std::min(b.l, b.r);
		});
		std::vector<int> last(n + 1);
		std::vector<NODE> tr;
		tr.push_back({n, 0, 0});
		for (int i = 1; i <= m; i++) {
			int u = last[std::max(seg[i].l, seg[i].r)];
			tr[u].ls = tr.size();
			tr.push_back((NODE){seg[i].l, 0, 0});
			tr[u].rs = tr.size();
			tr.push_back((NODE){seg[i].r, 0, 0});
			last[seg[i].l] = tr[u].ls;
			last[seg[i].r] = tr[u].rs;
		}
		int p = 0;
		std::vector<int> pos(n + 1);
		auto dfs = [&](auto self, int u) -> void {
			if (!tr[u].ls) {
				pos[tr[u].val] = ++p;
				return;
			}
			self(self, tr[u].ls);
			self(self, tr[u].rs);
		};
		dfs(dfs, 0);
		for (int i = 1; i <= n; i++) {
			std::cout << pos[i] << " \n"[i == n];
		}
		int64 cnt = 0, res = 1;
		std::vector<int> vis(n + 2);
		for (int i = n; i >= 1; i--) {
			if (pos[i]) {
				cnt += 2;
				if (vis[pos[i] + 1]) cnt--;
				if (vis[pos[i] - 1]) cnt--;
				vis[pos[i]] = 1;
			} else {
				std::cout << cnt << endl;
				res = res * cnt % mod;
				cnt++;
			}
		}
		std::cout << res << endl;
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