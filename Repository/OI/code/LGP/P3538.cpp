#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int unsigned long long
using namespace std;
const int mod=1e9+7,base=27;
int n,m,data[500010],min_prime[500010],cnt,Hash[500010],power[500010],prime[500010],factor[100010];
bool pd[500010];
string str;
int read(){
    int res=0,sym=0;char ch=getchar();
    while(!isdigit(ch)){sym|=ch=='-',ch=getchar();}
    while(isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void str_int(){
    for (int i=1;i<=n;i++){
        data[i]=str[i-1]-'a';
    }
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void start_prime(){
    for (int i=2;i<=n;i++){
        if (!pd[i]){
            prime[++cnt]=i;
            min_prime[i]=i;
        }
        for (int j=1;j<=cnt&&i*prime[j]<=n;j++){
            pd[i*prime[j]]=1;
            min_prime[i*prime[j]]=prime[j];
            if(!(i%prime[j]))break;
        }
    }
}
void cal_Hash(){
    for (int i=1;i<=n;i++){
        Hash[i]=Hash[i-1]*base+data[i];
    }
}
void cal_power(){
    power[0]=1;
    for (int i=1;i<=n;i++){
        power[i]=power[i-1]*base;
    }
}
void start(){
    str_int();start_prime();cal_power();cal_Hash();
}
int get_Hash(int l,int r){
    return Hash[r]-Hash[l-1]*power[r-l+1];
}
bool judge(int l,int r,int d){
    return get_Hash(l,r-d)==get_Hash(l+d,r);
}
signed main(){file();
    n=read();cin>>str;m=read();start();
    for (int i=1;i<=m;i++){
        int l=read(),r=read(),len=r-l+1;
        if (judge(l,r,1)){//1无法分解质因数，特判
            printf("1\n");
        }else{
            cnt=0;
            while(len!=1){
                factor[++cnt]=min_prime[len];
                len=len/min_prime[len];
            }len=r-l+1;
            for(int i=1;i<=cnt;i++){
                if(judge(l,r,len/factor[i])){
                    len/=factor[i];
                }
            }
            printf("%lld\n",len);
        }
    }
}