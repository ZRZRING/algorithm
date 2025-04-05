#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
ll i=1,n,ans[1000100],m,cnt,c,tmp,sum;
int main(){
    cin>>n;m=n;
    while (n){
        i=ceil((double)n/2);n-=i;ans[++cnt]=i;
    }
    sort(ans+1,ans+cnt+1);
    cout<<cnt<<endl;
    for (int i=1;i<=cnt;i++)cout<<ans[i]<<' ';
}
