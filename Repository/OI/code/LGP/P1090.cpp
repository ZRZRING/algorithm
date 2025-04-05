#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll q[1000010],cnt,tmp,n,ans,a,b;
void push(int x){
    q[++cnt]=x;
    for (int tmp=cnt;tmp!=1;tmp>>=1){
        if (q[tmp>>1]>q[tmp]){
            swap(q[tmp>>1],q[tmp]);
        }else{
            break;
        }
    }
}
void pop(){
    q[1]=q[cnt];cnt--;
    for (int tmp=1;(tmp<<1)<=cnt;){
        if (q[tmp]>q[tmp<<1]||q[tmp]>q[(tmp<<1)+1]){
            if (q[tmp<<1]>q[(tmp<<1)+1]&&(tmp<<1)+1<=cnt){
                swap(q[tmp],q[(tmp<<1)+1]);tmp<<=1;tmp++;
            }else{
                swap(q[tmp],q[tmp<<1]);tmp<<=1;
            }
        }else{
            break;
        }
    }
}
int main(){
	freopen("1090.in","r",stdin);
	freopen("my1090.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>tmp;push(tmp);
    }
    for (int i=1;i<n;i++){
        a=q[1];pop();
        b=q[1];pop();
        ans+=a+b;
        push(a+b);
    }
    cout<<ans;
}

/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll ans,a[1000010],n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans+=(n-1)*a[1];
	for (int i=2;i<=n;i++){
		ans+=a[i]*(n-i+1);
	}
	cout<<ans;
} 
*/