#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int64, 2>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}
template <class T> T MOD(T &x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 t) {return x >> t & 1ll;}

class WORK {
public:
    int N;

    WORK() {}

    void solve() {
        int n;
        std::cin >> n;
        std::vector<A2> ans;
        std::map<int, int> vis, vis2;
        for (int i = 1; i <= n; i++) {
            int x, y;
            std::cin >> x >> y;
            vis2[x]++;
            vis2[y]++;
            if (x != y) {
                if (ans.empty() || ans.back()[1] == x) {
                    ans.push_back({y, x});
                } else {
                    ans.push_back({x, y});
                }
            } else {
                vis[x]++;
            }
        }
        for (auto [x, t] : vis2) {
            if (t >= n + 2) {
                std::cout << "No" << endl;
                return;
            }
        }
        std::priority_queue<A2> q;
        for (auto [x, y] : vis) {
            q.push({y, x});
        }
        while (!q.empty()) {
            if (ans.empty()) {
                auto [t, x] = q.top();
                q.pop();
                ans.push_back({x, x});
                t--;
                if (t) q.push({t, x});
            } else if (q.size() == 1) {
                auto [t, x] = q.top();
                q.pop();
                if (ans[0][0] != x) {
                    ans.insert(ans.begin(), {x, x});
                    break;
                }
                if (ans.back()[1] != x) {
                    for (int i = 1; i <= t; i++) {
                        ans.push_back({x, x});
                    }
                    break;
                }
                for (int i = 1; i < ans.size(); i++) {
                    if (ans[i - 1][1] != x && ans[i][0] != x) {
                        ans.insert(ans.begin() + i, {x, x});
                        t--;
                        if (!t) break;
                    }
                }
            } else {
                auto [t1, x] = q.top();
                q.pop();
                auto [t2, y] = q.top();
                q.pop();
                if (ans.back()[1] == x) {
                    ans.push_back({y, y});
                    ans.push_back({x, x});
                } else {
                    ans.push_back({x, x});
                    ans.push_back({y, y});
                }
                t1--;
                t2--;
                if (t1) q.push({t1, x});
                if (t2) q.push({t2, y});
            }
        }
        std::cout << "Yes" << endl;
        for (auto [x, y] : ans) {
            std::cout << x << ' ' << y << endl;
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