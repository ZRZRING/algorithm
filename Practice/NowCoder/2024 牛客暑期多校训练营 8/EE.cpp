//
// Created by 35263 on 2024/8/8.
// J有一个巧妙的观察，如果m=n-2那么一定不行，因为包含1的区间一定会出现巨大的问题
// m=n-2是上界
// 11 2 10 3 9 4 7 5 6 1 6correct
// 1 2 3 4 5 6 7 8 9 10 8correct
// 6 0
// 6 3 2 5 1 4
// 7 0
// 7 4 2 6 3 1 5
// 8 0
// 8 4 3 7 2 1 6 5==>偶数的,放n/2,n/2-1,然后放最大的可行解
// 9 0
// 9 5 3 8 4 2 7 1 6==》奇数->n/2+1,n/2-1,然后放最大的可行解
// 10 0
// 10 4 5 9 3 2 8 1 6 7==>大数中间夹上两个小的

// 讨论1的情况，我们考虑在原来0的情况上加数
#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200005;
ll n, cnt = 0;
int s(ll x) {
    int an = 0;
    while (x > 0) {
        an += x % 10;
        x /= 10;
    }
    return an;
}
bool check(ll d, ll m) {
    // if(answer.find(m)==answer.end())answer[m]=s(m);
    if (d >= m) return false;
    if (d == s(m)) return true;
    return false;
}
void init() {
}
void solve() {
    cin >> n;
    ll sqn = sqrt(n);
    int ans = 0;
    // cout << sqn << "\n";
    ll l = n - 108;
    for (int i = 1; i <= sqn; ++i) {
        ll r = n - n % i;  // 枚举i表示的是now的因数，
        for (ll j = r; j >= l; j -= i) {
            ans += check(n - j, i);
            if (j != i * i) {
                ans += check(n - j, j / i);
            }
        }
        /*if(check(i)) ans++;
        for (ll j = max(sqn+1,(n - 99) / i); j <=min(lastr, n / i); j++) {
            if(check(j)) ans++;
        }
        lastr=(n-99)/i-1;*/
    }
    cout << ans << "\n";
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    std::cout << cnt << '\n';
    return 0;
}
