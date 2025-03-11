#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long qpow(long long a, long long x = mod - 2) {
    a %= mod;
    x %= mod - 1;
    long long res = 1;
    while (x) {
        if (x & 1) {
			res = res * a % mod;
		}
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

int main() {
    long long n, m;
    cin >> n >> m;
	long long ans = qpow(m, n - 1) * (n * m % mod - n + 1 + mod) % mod;
	std::cout << ans << endl;
}