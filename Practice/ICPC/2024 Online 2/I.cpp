#include <bits/stdc++.h>

using int64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int a[32] = {0};
    a[31] = 1;
    for (int i = 0; i < 31; i++)
        a[i] = -1;
    if (n == 0||(((n-1)&3)==3)) {
        std::cout << "NO\n";
        return;
    }
	std::cout<<"YES\n";
	int p=n-1;
	for(int i=1;i<=30;i++){
		if(p>>i&1){
			a[i-1]=1;
		}
	}
	if(p&1)
		a[0]=0;
	for(int i=0;i<=31;i++){
		std::cout<<a[i]<<" ";
		if(i%8==7)
			std::cout<<"\n";
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}