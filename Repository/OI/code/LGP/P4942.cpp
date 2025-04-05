#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll l,r,T;
ll cal(ll l,ll r){
    ll tmp1=l+r,tmp2=r-l+1;
    return (tmp1*5%9*tmp2%9)%9;
}
int main(){
    scanf("%lld",&T);
    for (;T;T--){
        scanf("%lld%lld",&l,&r);
        cout<<cal(l,r)<<endl;
    }
}