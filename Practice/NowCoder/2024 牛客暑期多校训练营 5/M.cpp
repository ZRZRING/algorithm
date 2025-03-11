#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int, 2>
#define lowbit(x) ((x) & -(x))
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

int64 gcd(int64 a, int64 b) {
	if (a < b) std::swap(a, b);
	return b ? gcd(b, a % b) : a;
}

class FRAC {
public:
	int64 a, b;

	FRAC(int64 A, int64 B) {
		int64 d = gcd(A, B);
		a = A / d;
		b = B / d;
	}

	friend FRAC operator - (const FRAC a, int64 b) {
		return FRAC(a.a * b - a.b * b, a.b * b);
	}

	friend FRAC operator * (const FRAC a, int64 b) {
		return FRAC(a.a * b, a.b);
	}

	friend bool operator < (const FRAC a, const FRAC b) {
		return a.a * b.b < a.b * b.a;
	}

	friend std::ostream& operator << (std::ostream& out, const FRAC a) {
		out << a.a << '/' << a.b << endl;
		return out;
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int64 c, a, b;
		std::cin >> c >> a >> b;
		FRAC ans1(c, 2), ans2(std::max(FRAC(a, b), FRAC(b - a, b)) * c - 1);
		std::cout << std::max(ans1, ans2);
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}