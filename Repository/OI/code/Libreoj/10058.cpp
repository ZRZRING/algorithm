#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1000010;
int n,m,trie[N][4],fail[N],p[N],cnt;
char txt[10000010],ch[N][150];
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
int cal(char ch){
    if (ch=='E')return 0;
    if (ch=='W')return 1;
    if (ch=='N')return 2;
    if (ch=='S')return 3;
}
void insert(char *ch){
    int u=0,len=strlen(ch);
    for (int i=0;i<len;i++){
        int v=cal(ch[i]);
        if (!trie[u][v])trie[u][v]=++cnt;
        u=trie[u][v];
    }
}
void build(){
    int q[N],head=0,tail=0;
    for (int i=0;i<=3;i++){
        int v=trie[0][i];
        if (v){
            fail[v]=0;q[++tail]=v;
        }
    }
    while (head<tail){
        int u=q[++head];
        for (int i=0;i<=3;i++){
            int v=trie[u][i];
            if (v){
                fail[v]=trie[fail[u]][i];q[++tail]=v;
            }else{
                trie[u][i]=trie[fail[u]][i];
            }
        }
    }
}
void find(){
    int u=0,len=strlen(txt);
    for (int i=0;i<len;i++){
        int v=cal(txt[i]);u=trie[u][v];
        for (int j=u;j;j=fail[j]){
            if (p[j])break;p[j]=1;
        }
    }
}
int query(char *ch){
    int u=0,len=strlen(ch);
    for (int i=0;i<len;i++){
        int v=cal(ch[i]);u=trie[u][v];
        if (!p[u])return i;
    }
}
int main(){
    m=read();n=read();scanf("%s",txt);
    for (int i=1;i<=n;i++){
        scanf("%s",ch[i]);insert(ch[i]);
    }
    build();find();
    for (int i=1;i<=n;i++){
        printf("%d\n",query(ch[i]));
    }
    return 0;
}