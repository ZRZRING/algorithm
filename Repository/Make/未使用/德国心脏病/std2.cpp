#include<bits/stdc++.h>
using namespace std;

int t , n , k , s;
char c;

int key[100001];
int cnt[100001];
int a[100001];

void check(int keys , int cnts , int now){
	key[now] = keys;
	cnt[now] = cnts;
}

int judge(){
	
	for(int i=1;i<=7;i++) a[i] = 0;
	for(int i=1;i<=n;i++){
		a[key[i]] += cnt[i];
	}
	
	for(int i=1;i<=4;i++){
		if(a[i] == 5) return 1;
	}
	if((a[5] > 0 && a[1] == 0) || (a[6] > 0 && a[2] == 0) || a[7] > 0) return 1;
	return 0;
}

int main(){
	freopen("3.in", "r", stdin);
	freopen("3.out", "w", stdout);
	cin >> t;
	
	while(t--){
		int res;
		cin >> n >> k;
		
		for(int i=1;i<=n;i++) cnt[i] = key[i] = 0;
		for(int i=1;i<=7;i++) a[i] = 0;
		
		int now = 1 ,ans;bool f = 0;
		
		for(int i=1;i<=k;i++){
			cin >> c;
			if(c == 'L' || c == 'S' || c == 'A' || c == 'B'){
				cin >> s;
				if(c == 'L') check(1,s,now);
				if(c == 'S') check(2,s,now);
				if(c == 'A') check(3,s,now);
				if(c == 'B') check(4,s,now);
			}else{
				if(c == 'M') check(5,1,now);
				if(c == 'E') check(6,1,now);
				if(c == 'P') check(7,1,now);
			}
			if(judge() && !f){
				f = 1;
				ans = now; res = i;
			}
			now = now + 1;
			if(now > n) now -= n;
		} 
		
		if(f) cout << ans << "\n";
		else cout << "-1\n" ;
	}

	return 0;
}
