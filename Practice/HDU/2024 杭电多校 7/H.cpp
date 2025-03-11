#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 1e9 + 7;

template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}
template <class T> T MOD(T &x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 t) {return x >> t & 1ll;}

class MATRIX {
public:
	int n;

	std::vector<std::vector<int64>> a;

	MATRIX(int n) : n(n) {
		a.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			a[i].resize(n + 1);
		}
	}

	friend MATRIX operator * (const MATRIX a, const MATRIX b) {
		int n = a.n;
		MATRIX c(a.n);
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					MOD(c.a[i][j] += a.a[i][k] * b.a[k][j]);
				}
			}
		}
		return c;
	}

	friend MATRIX operator + (const MATRIX a, const MATRIX b) {
		int n = a.n;
		MATRIX c(a.n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				MOD(c.a[i][j] = a.a[i][j] + b.a[i][j]);
			}
		}
		return c;
	}

	void print() {
		std::cout << '\n';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				std::cout << a[i][j] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int64 n, m, l, r;
		std::cin >> n >> m >> l >> r;
		l--;
		std::vector<MATRIX> S(n + 1, MATRIX(n + 1));
		std::vector<MATRIX> T(60, MATRIX(n + 1));
		MATRIX SS(n + 1);
		for (int i = 1; i <= m; i++) {
			int64 u, v, t;
			std::cin >> u >> v >> t;
			if (v <= n) {
				S[1].a[u][v] = t;
			} else {
				T[0].a[u][v - n] = t; 
			}
		}
		for (int i = 2; i <= n; i++) {
			S[i] = S[i - 1] * S[1];
		}
		for (int i = 1; i <= n; i++) {
			SS = SS + S[i];
		}
		for (int i = 1; i <= n; i++) {
			SS.a[i][i] = 1;
		}
		T[0] = T[0] * SS;
		for (int i = 1; i < 60; i++) {
			T[i] = T[i - 1] * T[i - 1];
		}
		for (int i = 0; i < 60; i++) {
			for (int j = 1; j <= n + 1; j++) {
				T[i].a[j][n + 1] = 1;
			}
		}
		auto cal = [&](int64 x) -> MATRIX {
			MATRIX A(n + 1);
			A.a[1][1] = 1;
			A = A * SS;
			A.print();
			int64 rd = (x + n - 1) / n - 1, rest = (x - 1) % n + 1;
			for (int i = 59; i >= 0; i--) {
				if (rd < 1ll << i) continue;
				rd -= 1 << i;
				A = A * T[i];
			}
			A.print();
			for (int i = 1; i <= rest; i++) {
				MOD(A.a[1][n + 1] += A.a[1][i]);
			}
			return A;
		};
		MATRIX L = cal(l), R = cal(r);
		std::cout << MOD(R.a[1][n + 1] - L.a[1][n + 1]) << '\n';
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}