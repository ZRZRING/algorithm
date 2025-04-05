#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5;
int w[N],h1,t1,h2,t2,q1[N],q2[N],len[N],n,lim;
void ins(int id)
{
    while(h1<=t1&&w[id]>=w[q1[t1]])--t1;
    q1[++t1]=id;
    while(h2<=t2&&w[id]<=w[q2[t2]])--t2;
    q2[++t2]=id;
}
int main()
{
    scanf("%d%d",&n,&lim);
    for(int i=1;i<=n;i++)scanf("%d",w+i);
    int r=0,mxlen=0,cnt=0;
    h1=1,t1=0,h2=1,t2=0;
    for(int i=1;i<=n;i++)
    {
        if(r<i)ins(++r);
        if(h1<=t1&&q1[h1]<i)++h1;
        if(h2<=t2&&q2[h2]<i)++h2;
        while(r<n&&max(w[r+1],w[q1[h1]])-min(w[r+1],w[q2[h2]])<=lim)ins(++r);
        len[i]=r-i+1; mxlen=max(mxlen,len[i]);
    }
    for(int i=1;i<=n;i++)if(len[i]==mxlen)++cnt;
    cout<<mxlen<<" "<<cnt<<endl;
    for(int i=1;i<=n;i++)if(len[i]==mxlen)printf("%d %d\n",i,i+len[i]-1);
}
