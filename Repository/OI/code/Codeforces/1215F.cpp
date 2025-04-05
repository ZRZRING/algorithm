#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
int n, m, maxl = 0, indeg[N], b[N], t;
int head[N], edge[N], leng[N], nxt[N], from[N];
vector<int> ans;
bool v[N], w[N];
queue<int> q;
void add(int x, int y, int z, int i) {
    edge[i] = y;
    leng[i] = z;
    nxt[i] = head[x];
    head[x] = i;
    from[i] = x;
}
bool dfs(int x, int now) {
    v[x] = 1; w[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = edge[i], z = leng[i];
        if (z <= now) continue;
        if (w[y] || !dfs(y, now)) return 0;
    }
    w[x] = 0;
    return 1;
}

inline bool check(int now) {
    memset(v, 0, sizeof(v));
    memset(w, 0, sizeof(w));
    for (int i = 1; i <= n; i++)
        if (!v[i] && !dfs(i, now)) return 0;
    return 1;
}
void topsort(int now) {
    for (int i = 1; i <= n; i++)
        if (!indeg[i]) q.push(i);
    while (q.size()) {
        int x = q.front();
        q.pop();
        b[x] = ++t;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = edge[i], z = leng[i];
            if (z > now && !--indeg[y]) q.push(y);
        }
    }
}

int work(int now) {
    for (int i = 1; i <= m; i++) {
        int y = edge[i], z = leng[i];
        if (z > now) ++indeg[y];
    }
    topsort(now);
    for (int i = 1; i <= n; i++)
        if (!b[i]) b[i] = ++t;
    for (int i = 1; i <= m; i++) {
        int x = from[i], y = edge[i], z = leng[i];
        if (z <= now && b[x] > b[y]) ans.push_back(i);
    }
    return ans.size();
}
int main() {
    cin >> n >> m;
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z, i); maxl = max(maxl, z);
    }
    int l = 0, r = maxl;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << " " << work(l) << endl;
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}