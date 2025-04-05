#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
const ll orz=10000001;
ll n,add[orz],mul[orz],a[orz],tree[orz],m,p;
void build(ll now,ll l,ll r){
	if (l==r){
		tree[now]=a[l];return;
	}
	ll mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	tree[now]=(tree[now<<1]+tree[now<<1|1])%p;
}
void do_add(ll now,ll len,ll addtmp,ll multmp){
	mul[now]*=multmp;mul[now]%=p;
	add[now]*=multmp;add[now]%=p;
	add[now]+=addtmp;add[now]%=p;
	tree[now]*=multmp;tree[now]%=p;
    tree[now]+=len*addtmp%p;tree[now]%=p;
}
void pushdown(ll now,ll l,ll r,ll mid){
	if (mul[now]==1&&add[now]==0)return;
	do_add(now<<1,  mid-l+1,  0,       mul[now]);
	do_add(now<<1|1,r-mid,    0,       mul[now]);
	do_add(now<<1,  mid-l+1,  add[now],1);
	do_add(now<<1|1,r-mid,    add[now],1);
	add[now]=0;mul[now]=1;
}
ll qjh(ll now,ll l,ll r,ll x,ll y){
	if (l>=x&&r<=y)return tree[now];
	ll mid=(l+r)>>1,res=0;
	pushdown(now,l,r,mid);
	if (mid>=x)res+=qjh(now*2,l,mid,x,y),res%=p;
	if (mid<y)res+=qjh(now*2+1,mid+1,r,x,y),res%=p;
	return res%p;
}
void qjc(ll now,ll l,ll r,ll x,ll y,ll tmp){
	if (l>=x&&r<=y){
		do_add(now,r-l+1,0,tmp);
		return;
	}
	ll mid=(l+r)>>1;
	pushdown(now,l,r,mid);
	if (mid>=x)qjc(now*2,l,mid,x,y,tmp);
	if (mid<y)qjc(now*2+1,mid+1,r,x,y,tmp);
	tree[now]=(tree[now*2]+tree[now*2+1])%p;
}
void qjj(ll now,ll l,ll r,ll x,ll y,ll tmp){
	if (l>=x&&r<=y){
		do_add(now,r-l+1,tmp,1);
		return;
	}
	ll mid=(l+r)>>1;
	pushdown(now,l,r,mid);
	if (mid>=x)qjj(now*2,l,mid,x,y,tmp);
	if (mid<y)qjj(now*2+1,mid+1,r,x,y,tmp);
	tree[now]=(tree[now*2]+tree[now*2+1])%p;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){file();
	scanf("%lld%lld",&n,&p);
	for (ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n*2;i++)mul[i]=1;
	build(1,1,n);
	ll x,y,k,tmp;
    scanf("%lld",&m);
	for (ll i=1;i<=m;i++){
		scanf("%lld",&tmp);
		if (tmp==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			qjc(1,1,n,x,y,k);
		}
		if (tmp==2){
			scanf("%lld%lld%lld",&x,&y,&k);
			qjj(1,1,n,x,y,k);
		}
		if (tmp==3){
			scanf("%lld%lld",&x,&y);
			/*cout<<endl;
			for (int i=1;i<=n*2;i++){
				cout<<tree[i]<<' '<<add[i]<<' '<<mul[i]<<endl;
			}cout<<endl;*/
			ll ans=qjh(1,1,n,x,y)%p;
			printf("%lld\n",ans);
		}
	}
}