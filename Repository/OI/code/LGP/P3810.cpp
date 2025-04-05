#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define a(x) dat[x].a
#define b(x) dat[x].b
#define c(x) dat[x].c
#define tot(x) dat[x].tot
#define ans(x) dat[x].ans
#define lowbit(x) (x & -x)
using namespace std;
const int N=200010;
int n, m, k, p = 1, ans[N], tree[N];
struct node{
    int a, b, c, tot, ans;
}dat[N], dat2[N];
inline int read(){
    int sym = 0, res = 0; char ch = 0;
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
void file(){
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
bool cmp(node a, node b){
    return a.a == b.a ? a.b == b.b ? a.c < b.c : a.b < b.b : a.a < b.a;
}
void add(int x, int t) {
    for (int i = x; i <= k; i+=lowbit(i)) tree[i] += t;
}
int query(int x) {
    int res = 0;
    for (int i = x; i; i-=lowbit(i)) res += tree[i];
    return res;
}
void cdq(int l, int r){
    if (l == r) return;
    int mid = l + r >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    int p = l, p1 = l;
    for (int p2 = mid + 1; p2 <= r; p2++) {
        while (p1 <= mid && b(p1) <= b(p2)) {
            add(c(p1), tot(p1));
            dat2[p++] = dat[p1]; p1++;
        }
        ans(p2) += query(c(p2));
        dat2[p++] = dat[p2];
    }
    for (int i = p1; i <= mid; i++){
        dat2[p++] = dat[i];
    }
    for (int i = l; i < p1; i++) {
        add(c(i), -tot(i));
    }
    for (int i = l; i < p; i++) {
        dat[i] = dat2[i];
    }
}
int main(){
    n = read(); k = read();
    for (int i = 1;i <= n;i++){
        a(i) = read(); b(i) = read(); c(i) = read(); tot(i) = 1;
    }
    sort(dat + 1,dat + n + 1,cmp);
    for (int i = 2; i <= n; i++){
        if (a(p) == a(i) && b(p) == b(i) && c(p) == c(i)) tot(p)++;
        else dat[++p] = dat[i];
    }
    cdq(1, p);
    for (int i = 1; i <= p; i++) {
        ans[ans(i) + tot(i)] += tot(i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}