#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

map<int, int> dis;
map<int, bool> inq;
int w[55], X[5345], D[5345], len; // 5342
void init() {
    for (int i = 2; i <= 54; i++) {
        w[i] = floor(pow(i, 8. / 7));
    }
    queue<int> q;
    dis[1] = 1, q.push(1), inq[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for (int i = 2; i <= 54 && u <= inf / i / i; i++) {
            int v = u * i * i, new_dis = dis[u] * w[i];
            if (!dis.count(v) || new_dis > dis[v]) {
                dis[v] = new_dis;
                if (!inq.count(v) || !inq[v])
                    inq[v] = 1, q.push(v);
            }
        }
    }
    for (auto [x, d]: dis) {
        X[++len] = x;
        D[len] = max(D[len - 1], d);
    }
}

void sc() {
    int l, r; scanf("%d%d", &l, &r);
    r /= l;
    int pos = upper_bound(X + 1, X + len + 1, r) - X - 1;
    printf("%d\n", D[pos]);
}

int main() {
    init();
    // cerr << clock() << '\n';
    int T; scanf("%d", &T);
    while (T--) sc();
    return 0;
}