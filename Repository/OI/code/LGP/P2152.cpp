#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
char ch[20000];
int cnt;
struct big{
    int num[20000],len;
    void clean(){
        memset(num,0,sizeof(num));len=0;
    }
    big operator -(const big &a){
        big c;c.clean();c.len=len;
        for (int i=1;i<=c.len;i++){
            c.num[i]=num[i]-a.num[i];
            if (c.num[i]<0){
                c.num[i]+=10;num[i+1]--;
            }
        }
        while (c.num[c.len]==0)c.len--;
        return c;
    }
    bool operator <(const big &a){
        if (len<a.len)return 1;
        if (len>a.len)return 0;
        for (int i=len;i>=1;i--){
            if (num[i]<a.num[i])return 1;
            if (num[i]>a.num[i])return 0;
        }
        return 1;
    }
    bool operator ==(const big &a){
        if (len!=a.len)return 0;
        for (int i=len;i>=1;i--){
            if (num[i]!=a.num[i])return 0;
        }
        return 1;
    }
    big operator <<(const int &tmp){
        big a;a.clean();int x=0;a.len=len;
        for (int i=1;i<=len;i++){
            a.num[i]=(num[i]<<1)+x;
            x=a.num[i]/10;
            a.num[i]=a.num[i]%10;
        }if (x)a.num[++a.len]=x;
        return a;
    }
    big operator >>(const int &tmp){
        big a;a.clean();a.len=len;
        for (int i=len;i>=1;i--){
            num[i-1]+=(num[i]%2)*10;
            a.num[i]=num[i]>>1;
        }
        while(a.num[a.len]==0)a.len--;
        return a;
    }
}a,b;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
bool c(big x){
    return !(x.num[1]%2);
}
void debug(){
    printf("a:len:%d num:",a.len);for (int i=a.len;i>=1;i--)printf("%d",a.num[i]);
    printf("\n");
    printf("b:len:%d num:",b.len);for (int i=b.len;i>=1;i--)printf("%d",b.num[i]);
    printf("\n\n");
}
int main(){file();
    scanf("%s",ch);a.len=strlen(ch);
    for (int i=1;i<=a.len;i++)a.num[i]=ch[a.len-i]-'0';
    scanf("%s",ch);b.len=strlen(ch);
    for (int i=1;i<=b.len;i++)b.num[i]=ch[b.len-i]-'0';
    while(!(a==b)){
        if(a<b)swap(a,b);//debug();
        if(c(a)&&c(b))a=a>>1,b=b>>1,cnt++;
        else if(c(b))b=b>>1;
        else if(c(a))a=a>>1;
        else a=a-b;
    }
    for (int i=1;i<=cnt;i++)a=a<<1;
    for (int i=a.len;i>=1;i--)printf("%d",a.num[i]);
    return 0;
}