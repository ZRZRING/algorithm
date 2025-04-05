#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
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
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
string str;int cnt;
int main(){
    cin>>str;
    for (int i=0;i<str.length();i++){
        if (str[i]=='(')cnt++;
        if (str[i]==')')cnt--;
        if (cnt<0)break;
        if (str[i]=='@')break;
    }
    if (cnt<0||cnt>0)cout<<"NO";else cout<<"YES";
}