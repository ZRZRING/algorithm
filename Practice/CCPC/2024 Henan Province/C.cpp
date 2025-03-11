#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T>
void MOD(T& x) {
    x = (x % mod + mod) % mod;
}
template <class T>
T lg(T x) {
    return (T)log10(x);
}
template <class T>
T log(T x) {
    return (T)log2(x);
}
template <class T>
T abs(T x) {
    return x < 0 ? -x : x;
}
template <class T>
T mysqrt(T x) {
    return std::floor(sqrtl(x));
}

struct WORK {
    int N;

    WORK() {}

    void solve() {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        std::vector<std::vector<int>> vis(n + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            vis[a[i]].push_back(i);
        }
        std::vector<int> t(n + 2);
        for (int i = 1; i <= n; i++) {
            if (vis[i].size() <= 1) continue;
            t[vis[i].front()]++;
            t[vis[i].back() + 1]--;
        }
        for (int i = 1; i <= n; i++) {
            t[i] += t[i - 1];
        }
        for (int l = 1; l <= n; l++) {
            int r = l;
            while (t[r + 1]) r++;
            std::sort(a.begin() + l, a.begin() + r + 1, std::greater<int>());
            l = r;
        }
        std::vector<int> f(1);
        for (int i = 1; i <= n; i++) {
            if (f.back() <= a[i]) {
				f.push_back(a[i]);
			} else {
                int p = lower_bound(f.begin() + 1, f.end(), a[i]) - f.begin();
                f[p] = a[i];
            }
        }
		// for (int i = 0; i < f.size(); i++) {
		// 	std::cout << f[i] << " \n"[i == f.size() - 1];
		// }
        std::cout << f.size() << endl;
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