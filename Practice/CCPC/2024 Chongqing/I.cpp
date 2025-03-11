#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define bit1(x) __builtin_popcountll(x)
#define Pqueue priority_queue
#define lc p << 1
#define rc p << 1 | 1
#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define fi first
#define se second
#define lowbit(x) (x & -x)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;

const ll mod = 998244353;
const ll N = 1e6 + 10;
const ld eps = 1e-9;
const ll inf = 1e18;
const ll P = 131;
const ll dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

class MOD {
   public:
    ll num, p;
    MOD()
        : num(0), p(mod) {};
    MOD(ll Num, ll P = mod)
        : num(Num % P), p(P) {};
    MOD operator+(const MOD& other) const { return MOD((num % p + other.num % p) % p, p); };
    MOD operator-(const MOD& other) const { return MOD((num % p - other.num % p + p) % p, p); };
    MOD operator*(const MOD& other) const { return MOD((num % p) * (other.num % p) % p, p); };
    MOD operator%(const MOD& other) const { return MOD(num % other.num); };
    bool operator==(const MOD& other) const { return num == other.num; };
    bool operator!=(const MOD& other) const { return num != other.num; };
    bool operator>(const MOD& other) const { return num > other.num; };
    bool operator<(const MOD& other) const { return num < other.num; };
    bool operator<=(const MOD& other) const { return num <= other.num; };
    bool operator>=(const MOD& other) const { return num >= other.num; };
    MOD max(const MOD& other) const { return num > other.num ? *this : other; };
    MOD min(const MOD& other) const { return num < other.num ? *this : other; };

    template <typename T>
    T operator%(const T& other) const { return (T)num % other; };
    template <typename T>
    T operator&(const T& other) const { return (T)num & other; };
    template <typename T>
    bool operator==(const T& other) const { return (T)num == other; };
    template <typename T>
    bool operator!=(const T& other) const { return (T)num != other; };
    template <typename T>
    bool operator>(const T& other) const { return (T)num > other; };
    template <typename T>
    bool operator<(const T& other) const { return (T)num < other; };
    template <typename T>
    bool operator<=(const T& other) const { return (T)num <= other; };
    template <typename T>
    bool operator>=(const T& other) const { return (T)num >= other; };
    template <typename T>
    T max(const T& other) const { return num > other ? (T)num : other; };
    template <typename T>
    T min(const T& other) const { return num < other ? (T)num : other; };
    ll q_pow(ll a, ll b, ll m) const {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = ((res % m) * (a % m)) % m;
            b >>= 1;
            a = ((a % m) * (a % m)) % m;
        }
        return res;
    }
    ll inv(ll a, ll m) const {
        return q_pow(a, m - 2, m);
    }
    MOD operator/(const MOD& other) const { return MOD((num % p) * inv(other.num, p), p); };
    friend istream& operator>>(istream& in, MOD& a) {
        in >> a.num;
        a.num %= a.p;
        return in;
    };
    friend ostream& operator<<(ostream& out, const MOD& a) {
        out << a.num;
        return out;
    };
};

ll q_pow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = ((res % m) * (a % m)) % m;
        b >>= 1;
        a = ((a % m) * (a % m)) % m;
    }
    return res;
}
ll inv(ll a, ll m) {
    return q_pow(a, m - 2, m);
}

void solve() {
    int n = 9;
    vector<int> f(n + 2);
    for (int i = 1; i <= 9; i++)
        cin >> f[i];
    // f[2] += f[1] / 2;

    int mi = min(f[1], f[2]);
    f[1] -= mi;
    f[2] -= mi;
    f[3] += mi;

    if (f[1]) {
        f[3] += f[1] / 3;
        f[1] = f[1] % 3;

        f[2] += f[1] / 2;
        f[1] = f[1] % 2;
    }
    if (f[1]) {
        for (int i = 2; i <= 9; i++)
            if (f[i]) {
                f[i]--;
                f[i + 1]++;
                break;
            }
    }
    // cout << f[1] << " " << f[2] << " " << f[3] << "\n";
    MOD p(1);
    for (int i = 2; i <= 10; i++) {
        if (f[i])
            p = p * q_pow(i, f[i], mod);
    }
    cout << p << "\n";
}

int main() {
    IOS int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

/*
oxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxox
x                                                                                      o
o       _/_/_/_/                                                              _/       x
x      _/                                                                              o
o     _/_/_/_/ _/  _/_/   _/_/   _/_/_/ _/_/   _/_/_/     _/_/    _/_/_/    _/ _/   _/ x
x    _/       _/_/     _/    _/ _/   _/   _/  _/    _/ _/    _/  _/    _/  _/   _/ _/  o
o   _/       _/       _/    _/ _/   _/   _/  _/    _/ _/    _/  _/    _/  _/    _/_/   x
x  _/       _/         _/_/   _/   _/   _/  _/_/_/     _/_/ _/ _/    _/  _/      _/    o
o                                          _/                           _/      _/     x
x                                         _/                        _/_/       _/      o
o                                                                                      x
xoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxo
*/