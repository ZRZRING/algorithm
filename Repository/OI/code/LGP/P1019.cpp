#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
string str[100];
char ch;
int len[10000],a[1000][1000],p[10000],ans,maxx;
int n;
int check(string a,string b){
	for(int i=1;i<min(a.length(),b.length());i++) {
        int pd=1; 
		for(int j=0;j<i;j++)
            if(a[a.length()-i+j]!=b[j])pd=0;
        if (pd)return i;
    }
    return 0;
}
void search(int now,int ans){
	int tmp=0;
	for (int i=1;i<=n;i++){
		if (a[now][i]!=0&&p[i]<2){
			p[i]++;search(i,ans+len[i]-a[now][i]);p[i]--;tmp=1;
		}
	}
	if (!tmp){
		if (ans>maxx)maxx=ans;
	}
} 
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>str[i];len[i]=str[i].length();//cout<<str[i].length();
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			a[i][j]=check(str[i],str[j]);
		}
	}
	/*for (int i=1;i<=n;i++){
		cout<<len[i]<<' ';
	}printf("\n\n");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}cout<<endl;
	}*/
	cin>>ch;
	for (int i=1;i<=n;i++){
		if (str[i][0]==ch){
			p[i]=1;search(i,len[i]);p[i]=0;
		}
	}
	cout<<maxx;
} 
