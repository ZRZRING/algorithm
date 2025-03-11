#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

using namespace std;

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

    int fa[5001];

    int find(int x) {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int a, int b) {
        int y = find(b), x = find(a);
        fa[x] = y;
    }

    void solve() {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= 2 * n; i++)
            fa[i] = i;
        for (int i = 1; i <= m; i++) {
            char x;
            cin >> x;
            int a, b;
            cin >> a >> b;
            if (x == 'E') {
                merge(a, b + n);
                merge(b, a + n);
            } else
                merge(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (find(i) == i || find(i) == i + n)
                ans++;
        cout << ans;
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