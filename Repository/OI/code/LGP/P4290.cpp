#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int p[150];
const int qwq=210;
int n,edge[5][5][5],dp[5][qwq][qwq],c[qwq];
char ch1,ch2;
string str;
int main(){
	p['W']=1;p['I']=2;p['N']=3;p['G']=4;
    for (int i=1;i<=4;i++)cin>>c[i];
    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=c[i];j++){
            cin>>ch1>>ch2;
            edge[i][p[ch1]][p[ch2]]=1;
        }
    }
    cin>>str;
    for (int i=str.length()+1;i>=1;i--)str[i]=str[i-1];n=str.length();
    for (int i=1;i<=n;i++){
        dp[p[str[i]]][i][i]=1;
    }
    for (int l=1;l<=n;l++){
        for (int r=l;r>=1;r--){
            for (int c=1;c<=4;c++){
                for (int c1=1;c1<=4&&!dp[c][l][r];c1++){
                    for (int c2=1;c2<=4&&!dp[c][l][r];c2++){
                        if (!edge[c][c1][c2])continue;
                        for(int k=l;k<r&&!dp[c][l][r];k++)dp[c][l][r]|=(dp[c1][l][k]&dp[c2][k+1][r]);
                    }
                } 
            }
        }
    }
    int flag=0;
    if(dp[1][n][1]){putchar('W');flag=1;}
    if(dp[1][n][2]){putchar('I');flag=1;}
    if(dp[1][n][3]){putchar('N');flag=1;}
    if(dp[1][n][4]){putchar('G');flag=1;}
    if(!flag)printf("The name is wrong!");
} 
