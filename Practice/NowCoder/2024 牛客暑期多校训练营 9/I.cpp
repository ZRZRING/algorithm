#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
#define i128 __int128
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

void printt(i128 x) {
    if (!x) return;
    if (x < 0) {
		putchar('-');
		x = -x;
	}
    printt(x / 10);
    putchar(x % 10 + '0');
}

void print(i128 x) {
	if (x == 0) {
		putchar('0');
	} else {
		printt(x);
	}
}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::string L, R;
		std::cin >> n >> L >> R;
		i128 L1 = 0, L2 = 0, R1 = 0, R2 = 0, S = 1;
		for (int i = 1; i <= n / 2; i++) {
			S *= 10;
		}
		for (int i = 0; i < n / 2; i++) {
			L1 *= 10;
			R1 *= 10;
			L1 += L[i] - '0';
			R1 += R[i] - '0';
		}
		for (int i = n / 2; i < n; i++) {
			L2 *= 10;
			R2 *= 10;
			L2 += L[i] - '0';
			R2 += R[i] - '0';
		}
		auto find = [](i128 a) -> i128 {
			i128 l = 0, r = a;
			while (l < r) {
				i128 mid = (l + r + 1) / 2;
				if (mid > a / mid || mid * mid > a) {
					r = mid - 1;
				} else {
					l = mid;
				}
			}
			return l;
		};
		i128 l1 = find(L1);
		i128 r1 = find(R1);
		auto cal = [&](i128 X) -> i128 {
			if (X < 0) return 0;
			i128 x = find(X);
			// print(x);
			// std::cout << '\n';
			return x + 1;
		};
		print((cal(R1 - 1) - cal(L1 - 1)) * cal(S - 1) + cal(R2) * (r1 * r1 == R1) - cal(L2 - 1) * (l1 * l1 == L1));
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}