#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
struct hh{
    int s,f,num;
}a[10000];
int n,r,q;
int my_swap(hh a,hh b){
    if (a.s==b.s){
        return a.num<b.num;
    }
    return a.s>b.s;
}
int main(){
    cin>>n>>r>>q;n*=2;
    for (int i=1;i<=n;i++){
        cin>>a[i].s;
        a[i].num=i;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i].f;
    }
    sort(a+1,a+n+1,my_swap);
    for (int j=1;j<=r;j++){
        for (int i=1;i<=n;i+=2){
            a[i].s+=a[i].f>a[i+1].f?1:0;
            a[i+1].s+=a[i].f>a[i+1].f?0:1;
        }
        for (int i=1;i<=n;i++){
        	cout<<a[i].num<<':'<<a[i].s<<' ';
        }cout<<endl; 
        sort(a+1,a+n+1,my_swap);
    }
    cout<<a[q].num;
} 
