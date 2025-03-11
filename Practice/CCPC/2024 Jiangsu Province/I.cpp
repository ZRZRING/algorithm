#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

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

	void solve() {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& i : a)
			cin >> i;
		for (auto& i : b)
			cin >> i;
		auto check = [&](int x) -> bool {
			multiset<int> s;
			int num = 0;
			s.insert(a[0]);
			num = b[0] ? 1 : -1;
			for (int i = 1; i < n; i++) {
				if (num == 0) {
					s.insert(a[i]);
					num = b[i] ? 1 : -1;
				} else if (num < 0) {
					if (b[i] == 0)
						s.insert(a[i]), num--;
					else {
						auto k = lower_bound(s.begin(), s.end(), x - a[i]);
						if (k == s.end())
							return false;
						s.erase(k);
						num++;
					}
				} else {
					if (b[i] == 1)
						s.insert(a[i]), num++;
					else {
						auto k = lower_bound(s.begin(), s.end(), x - a[i]);
						if (k == s.end())
							return false;
						s.erase(k);
						num--;
					}
				}
			}
			return true;
		};
		int l = 1, r = 2e8 + 10, mid;
		while (l != r) {
			mid = l + r >> 1;
			if (check(mid))
				r = mid;
			else
				l = mid + 1;
		}
		cout << l << "\n";
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