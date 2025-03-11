#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A3 std::array<int, 3>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

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
template <class T>
T MOD(T& x, int64 p = mod) {
    return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
    return x = (x % p + p) % p;
}
template <class T1, class T2>
T1 getbit(T1 x, T2 t) {
    return x >> t & 1ll;
}

class WORK {
public:
    int N;

    WORK() {}

    void solve() {
        int n, Q;
        std::cin >> n >> Q;
        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        int B = 500;
        std::vector<A3> qry(Q + 1);
        for (int i = 1; i <= Q; i++) {
            std::cin >> qry[i][1] >> qry[i][0];
            qry[i][2] = i;
        }
        std::sort(qry.begin() + 1, qry.end());
        // for (int i = 1; i <= Q; i++) {
        //     std::cout << qry[i][1] << ' ' << qry[i][0] << '\n';
        // }
        int step = 0, S = Q + 1;
        std::vector<int> ans(n + 1), res(Q + 1);
        for (int i = 1; i <= Q; i++) {
            int t = qry[i][0], x = qry[i][1], id = qry[i][2];
            if (t > B) {
                S = i;
                break;
            }
            if (t != step) {
                step = t;
                ans[0] = 1;
                int cnt = 0;
                for (int i = 1; i < n; i++) {
                    if (ans[i - 1] <= a[i])
                        cnt++;
                    if (cnt == step) {
                        cnt = 0;
                        ans[i] = ans[i - 1] + 1;
                    } else {
                        ans[i] = ans[i - 1];
                    }
                }
            }
            res[id] = (ans[x - 1] <= a[x]);
        }
        if (S != Q + 1) {
            int t = qry[S][0], x = qry[S][1], id = qry[S][2];
            ans.clear();
            step = t;
            ans.push_back(0);
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] >= ans.size())
                    cnt++;
                if (cnt == step) {
                    cnt = 0;
                    ans.push_back(i);
                }
            }
            res[id] = (a[x] >= ans.size() || x <= ans[a[x]]);
        }
        for (int i = S + 1; i <= Q; i++) {
            int t = qry[i][0], x = qry[i][1], id = qry[i][2];
            if (t != step) {
                int next = -step;
                for (int i = 1; i < ans.size(); i++) {
                    int rest = next + t, j = ans[i];
                    next = -step;
                    while (rest && j <= n) {
                        j++;
                        rest -= (a[j] >= i);
                        next += (a[j] >= i + 1);
                    }
                    ans[i] = j;
                }
                step = t;
            }
            // for (auto x : ans) {
            //     std::cout << x << ' ';
            // }
            // std::cout << '\n';
            res[id] = (a[x] >= ans.size() || x <= ans[a[x]]);
        }
        for (int i = 1; i <= Q; i++) {
            std::cout << (res[i] ? "YES" : "NO") << endl;
        }
    }
};

int main() {
    // Fast_IOS;
    WORK work;
    int T = 1;
    // std::cin >> T;
    while (T--) {
        work.solve();
    }
    return 0;
}