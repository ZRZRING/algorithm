#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 2e6 + 10, mod = 20220911;

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

string st;

int n, s[N], top;

int main() {
	cin >> st; top = 1;
	while (st != "fin") {
		if (st[0] == 'a') {cin >> st; continue;}
		if (st[0] == 'r') {top++; cin >> st; continue;}
		if (st[0] == 'l') s[top]++;
		if (st[0] == 'f') {
			int x = read();
			s[top] = 1ll * s[top] * x % mod; top--;
			s[top] = 1ll * (s[top] + s[top + 1]) % mod;
			s[top + 1] = 0;
			cin >> st;
		}
		cin >> st;
		// for (int i = 1; i <= top; i++) printf("%d ", s[i]); printf("\n");
	}
	// printf("%d\n", top);
	printf("%d", s[1]);
}
