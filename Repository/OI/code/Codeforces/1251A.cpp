#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
int flag[N];
char ch[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){
    int T=read();
    while (T--){
        scanf("%s",ch+1);
        memset(flag,0,sizeof(flag));
        int n=strlen(ch+1);
        for (int i=1;i<=n;i++){
            int j=1;
            while (ch[i]==ch[i+1])j++,i++;
            if (j%2){
                flag[ch[i]]=1;
            }
        }
        for (int i='a';i<='z';i++){
            if (flag[i]){
                printf("%c",(char)i);
            }
        }
        printf("\n");
    }
    return 0;
}