#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int cx[9]={-1,0,0,1,-1,-1,0,1,1};
const int cy[9]={0,-1,1,0,-1,1,0,-1,1};
int mp[5000][5000],flag,n,m,startx,starty;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
char read(){
    char ch=getchar();
    while(ch!='.'&&ch!='#'&&ch!='S')ch=getchar(),cout<<"wow";
    return ch;
}
void dfs(int x,int y){
    if (flag)return;
    if (x<=1||x>=3*n||y<=1||y>=3*n){
        cout<<"Yes"<<endl;flag=1;return;
    }else{
        for (int i=0;i<=3;i++){
            int tx=x+cx[i],ty=y+cy[i];
            if (mp[tx][ty]==1){
                mp[tx][ty]=2;dfs(tx,ty);
            }
        }
    }
}
int main(){
    while (cin>>n>>m){
        memset(mp,0,sizeof(mp));flag=0;
        for (int i=n+1;i<=n*2;i++){
            cin>>ch;
            for (int j=0;j<ch.length();j++){
                if (ch[j]=='S'){
                    startx=i;starty=j;
                    for (int i=0;i<=8;i++){
                        mp[i+cx[i]*n][j+cy[i]*n]=1;
                    }
                }if (ch[j]=='.'){
                    for (int i=0;i<=8;i++){
                        mp[i+cx[i]*n][j+cy[i]*n]=1;
                    }
                }if (ch[j]=='#'){
                    for (int i=0;i<=8;i++){
                        mp[i+cx[i]*n][j+cy[i]*n]=2;
                    }
                }
            }
        }
        dfs(startx,starty);if (!flag)cout<<"No"<<endl;
    }
}
