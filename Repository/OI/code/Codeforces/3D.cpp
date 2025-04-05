#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define int long long
#define mp(x, y) make_pair(x, y)

using namespace std;

void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, cnt, ans;

char ch[N];

priority_queue<pair<int, int> >q;

signed main() {
    scanf("%s", ch + 1); n = strlen(ch + 1);
    if (n % 2) {printf("-1"); return 0;}
    for (int i = 1, j = 0; i <= n; i++) {
        if (ch[i] == '(') cnt++;
        if (ch[i] == ')') cnt--;
        if (ch[i] == '?') {
            int l = read(), r = read(); cnt--; ans += r; ch[i] = ')'; q.push(mp(r - l, i));
        }
        if (cnt < 0) {
            if (q.empty()) {printf("-1"); return 0;}
            pair<int, int> t = q.top(); q.pop();
            ans -= t.first; ch[t.second] = '('; cnt = 1; 
        }
    }
    if (cnt) {printf("-1"); return 0;}
    printf("%lld\n", ans); printf("%s", ch + 1);
    return 0;
}