#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int orz=500010;
int n,a[orz],cnt,q[orz],l,r,mid,ans,k,maxx,p;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int k=1;k<=n;k++){
    cout<<k<<':';
        cnt=0;q[0]=1<<30;ans=0;
        for (int i=k;i>=1;i--){
            if (a[i]<q[cnt])q[++cnt]=a[i];
            else{
                if (a[i]==q[cnt])continue;
                l=1;r=cnt;p=1;
                while (l<r){
                    mid=(l+r)>>1;
                    if (a[i]==q[mid]){p=0;break;}
                    if (a[i]<q[mid])r=mid;
                    if (a[i]>q[mid])l=mid+1;
                }
                if (p)q[l]=a[i];
            }
        }
        for (int i=1;i<=cnt;i++)cout<<q[i]<<' ';cout<<endl;
        ans+=cnt;cnt=0;
        for (int i=k;i<=n;i++){
            if (a[i]<q[cnt])q[++cnt]=a[i];
            else{
                if (a[i]==q[cnt])continue;
                l=1;r=cnt;p=1;
                while (l<r){
                    mid=(l+r)>>1;
                    if (a[i]==q[mid]){p=0;break;}
                    if (a[i]<q[mid])r=mid;
                    if (a[i]>q[mid])l=mid+1;
                }
                if (p)q[l]=a[i];
            }
        }
        for (int i=1;i<=cnt;i++)cout<<q[i]<<' ';cout<<endl;
        ans+=cnt;maxx=max(maxx,ans-1);
        cout<<ans<<endl;
    }
    cout<<n-maxx;
}
