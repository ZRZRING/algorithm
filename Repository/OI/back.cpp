#include <iostream>
#include <cstdio>
#include <cstring>
#define ls i << 1
#define rs i << 1 | 1
using namespace std;
const int N = 250005, M = 5;
const int MOD = 998244353;
int n, m;
int a[N], b[N], c[N];
int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    return x;
}
struct Matrix {
    int n, m;
    int mat[M][M];
    Matrix() {
        n = m = 0;
        memset(mat, 0, sizeof(mat));
        return;
    }
    Matrix operator+(const Matrix &b) const {
        Matrix c;
        c.n = n, c.m = m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) c.mat[i][j] = add(mat[i][j], b.mat[i][j]);
        return c;
    }
    Matrix operator*(const Matrix &b) const {
        Matrix c;
        c.n = n, c.m = b.m;
        for (int i = 1; i <= c.n; i++)
            for (int j = 1; j <= c.m; j++)
                for (int k = 1; k <= m; k++)
                    c.mat[i][j] = add(c.mat[i][j], 1LL * mat[i][k] * b.mat[k][j] % MOD);
        return c;
    }
    bool operator==(const Matrix &b) const {
        if (n != b.n || m != b.m)
            return false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (mat[i][j] != b.mat[i][j])
                    return false;
        return true;
    }
};
Matrix base;
struct Node {
    int l, r;
    Matrix sum, tag;
} tree[N << 2];
void push_up(int i) {
    tree[i].sum = tree[ls].sum + tree[rs].sum;
    return;
}
void build(int i, int l, int r) {
    tree[i].l = l, tree[i].r = r;
    tree[i].tag = base;
    if (l == r) {
        tree[i].sum.n = 1, tree[i].sum.m = 4;
        tree[i].sum.mat[1][1] = a[l], tree[i].sum.mat[1][2] = b[l], tree[i].sum.mat[1][3] = c[l],
        tree[i].sum.mat[1][4] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(i);
    return;
}
void push_down(int i) {
    if (tree[i].tag == base)
        return;
    tree[ls].sum = tree[ls].sum * tree[i].tag;
    tree[ls].tag = tree[ls].tag * tree[i].tag;
    tree[rs].sum = tree[rs].sum * tree[i].tag;
    tree[rs].tag = tree[rs].tag * tree[i].tag;
    tree[i].tag = base;
    return;
}
void modify(int i, int l, int r, const Matrix &val) {
    if (l <= tree[i].l && tree[i].r <= r) {
        tree[i].sum = tree[i].sum * val;
        tree[i].tag = tree[i].tag * val;
        return;
    }
    push_down(i);
    if (l <= tree[ls].r)
        modify(ls, l, r, val);
    if (r >= tree[rs].l)
        modify(rs, l, r, val);
    push_up(i);
    return;
}
Matrix query(int i, int l, int r) {
    if (l <= tree[i].l && tree[i].r <= r)
        return tree[i].sum;
    push_down(i);
    if (r <= tree[ls].r)
        return query(ls, l, r);
    else if (l >= tree[rs].l)
        return query(rs, l, r);
    else
        return query(ls, l, r) + query(rs, l, r);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
    base.n = base.m = 4;
    for (int i = 1; i <= base.n; i++) base.mat[i][i] = 1;
    build(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        int opt, l, r, v;
        scanf("%d%d%d", &opt, &l, &r);
        Matrix val = base;
        if (opt == 1) {
            val.mat[2][1] = 1;
            modify(1, l, r, val);
        } else if (opt == 2) {
            val.mat[3][2] = 1;
            modify(1, l, r, val);
        } else if (opt == 3) {
            val.mat[1][3] = 1;
            modify(1, l, r, val);
        } else if (opt == 4) {
            scanf("%d", &v);
            val.mat[4][1] = v;
            modify(1, l, r, val);
        } else if (opt == 5) {
            scanf("%d", &v);
            val.mat[2][2] = v;
            modify(1, l, r, val);
        } else if (opt == 6) {
            scanf("%d", &v);
            val.mat[3][3] = 0;
            val.mat[4][3] = v;
            modify(1, l, r, val);
        } else if (opt == 7) {
            Matrix res = query(1, l, r);
            printf("%d %d %d\n", res.mat[1][1], res.mat[1][2], res.mat[1][3]);
        }
    }
    return 0;
}
