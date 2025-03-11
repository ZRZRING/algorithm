#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 2e6 + 10;

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, k, t;

int main() {
	int T = read();
	while (T--) {
		n = read(); k = read();
		int r1 = n % k, r2 = k - n % k, b = n / k, a = b + 1, c = n / 2;
		if (n == 1) {printf("Yes\n"); continue;}
		if (c % a == 0) {
			if (c / a <= r1) {printf("Yes\n"); continue;}
		}
		if (c % b == 0) {
			if (c / b <= r2) {printf("Yes\n"); continue;}
		}
		t = c - a * r1;
		if (t > 0) {
			t %= b; int x, y; if (t == 0) x = r1; else x = r1 - (b - t); y = (c - x * a) / b;
			if (x <= r1 && x >= 0 && y <= r2 && y >= 0) {printf("Yes\n"); continue;}
		}
		t = c - b * r2;
		if (t > 0) {
			t %= a; int x, y; y = r2 - t; x = (c - y * b) / a;
			if (x <= r1 && x >= 0 && y <= r2 && y >= 0) {printf("Yes\n"); continue;}
		}
		printf("No\n");
	}
	return 0;
}