// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

#define poly vector<int>
#define SZ(a) int(a.size())
 
const int mod = 998244353;
const int G = 3, Gi = 332748118;
int add(int x, int y) {
  if ((x += y) >= mod) x -= mod;
  return x;
}
int sub(int x, int y) {
  if ((x -= y) < 0) x += mod;
  return x; 
}
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
namespace Poly {
vector<int> Rev, W;
int lim, L;
void getR(int len) {
  lim = 1, L = 0;
  while (lim <= len) lim <<= 1, L++;
  Rev.resize(lim), W.resize(lim), W[0] = 1;
  for (int i = 0; i < lim; i++) Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) << L - 1);
}
void NTT(poly &a, int opt) {
  assert(SZ(a) == lim); 
  for (int i = 0; i < lim; i++) if (i < Rev[i]) swap(a[i], a[Rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int Wn = qpow(opt == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int k = 1; k < mid; k++) W[k] = 1ll * W[k - 1] * Wn % mod;
    for (int j = 0; j < lim; j += mid << 1) {
      for (int k = 0; k < mid; k++) {
        int x = a[j + k], y = 1ll * W[k] * a[j + k + mid] % mod;
        a[j + k] = add(x, y);
        a[j + k + mid] = sub(x, y);
      }
    }
  }
  if (opt == -1) {
    int linv = qpow(lim);
    for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * linv % mod;
  }
}
poly operator * (poly a, poly b) {
  int len = a.size() + b.size() - 1;
  getR(len);
  a.resize(lim), b.resize(lim);
  NTT(a, 1), NTT(b, 1);
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
  NTT(a, -1);
  a.resize(len);
  return a;
}
poly Inv(poly a) {
  if (SZ(a) == 1) return vector<int> (1, qpow(a[0]));
  int len = a.size();
  poly tmpa = a; tmpa.resize((len + 1) / 2);
  poly tmpb = Inv(tmpa);
  getR(2 * len + 3), a.resize(lim), tmpb.resize(lim);
  NTT(a, 1), NTT(tmpb, 1);
  for (int i = 0; i < lim; i++) tmpb[i] = 1ll * tmpb[i] * (mod + 2 - 1ll * a[i] * tmpb[i] % mod) % mod;
  NTT(tmpb, -1);
  tmpb.resize(len);
  return tmpb;
}
}
using namespace Poly;

const int N = 200005;
int n, l, r;

int pw[N];
void init(int n) {
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = 1ll * pw[i - 1] * i % mod;
  for (int i = 1; i <= n; i++) pw[i] = qpow(qpow(pw[i], n));
  pw[0] = 0;
}

int main() {
  cin >> n >> l >> r;
//  n = 200000;
  init(n);
//  for (int i = 1; i <= n; i++) printf("pw[%d] = %d\n", i, pw[i]);
  int ans = 0;
  int fac = 1;
  for (int i = 1; i <= n; i++) fac = 1ll * fac * i % mod;
  fac = qpow(fac, n);
  for (int k = l; k <= r; k++) {
    poly f(n / k + 1);
    f[0] = 1;
    for (int i = 1; i <= n / k; i++) f[i] = pw[i * k];
    f = Inv(f);
    
//    for (auto &v: f) printf("%d ", v); puts("");
    
//    printf("k = %d, ", k); for (auto v: f) printf("%d ", v); puts("");
    int coef = 0;
    for (int i = 0; i <= n / k; i++) coef = add(coef, 1ll * f[i] * pw[n - i * k] % mod);
//    printf("k = %d, coef = %d\n", k, coef);
    ans = 0;
    if (((n - 1) / k) & 1) ans = sub(ans, coef);
    else ans = add(ans, coef);
    printf("%d ", 1ll * ans * fac % mod);
  }
  return 0;
}
