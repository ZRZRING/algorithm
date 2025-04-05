#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
int n,m,trie[N][30],fail[N],cnt,wlen[N],pos[N];
bool p[N];
char ch[N],txt[N];
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
void insert(char *ch){
    int u=0,len=strlen(ch);
    for (int i=0;i<len;i++){
        int v=ch[i]-'a';
        if (!trie[u][v])trie[u][v]=++cnt;
        wlen[trie[u][v]]=wlen[u]+1;u=trie[u][v];
    }p[u]=1;
}
void build(){
    int q[N],head=0,tail=0;
    for (int i=0;i<30;i++){
        int v=trie[0][i];
        if (v){
            q[++tail]=v;fail[v]=0;
        }
    }
    while (head<tail){
        int u=q[++head];
        for (int i=0;i<30;i++){
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
	int len=strlen(txt),u=0,d=0;
	for (int i=0;i<len;i++){
		txt[i]=txt[i+d];
        int v=txt[i]-'a';
		u=trie[u][v];pos[i]=u;
		if (p[u]){
			d+=wlen[u];len-=wlen[u];
            i-=wlen[u];u=pos[i];
		}
	}txt[len]='\0';
}

int main(){
    scanf("%s",txt);n=read();
    for (int i=1;i<=n;i++){
        scanf("%s",ch);insert(ch);
    }
    build();find();
    printf("%s",txt);
    return 0;
}