#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read();
	for (int i = 1; i <= n; i++) {
		
	}
	return 0;
}