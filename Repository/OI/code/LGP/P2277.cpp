#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
//5*5-5/5
int num[10],ans;
void search(int now,int code){
	if (now==1){
		if (num[1]==24&&p[code]){
			ans++;
		}
	}else{
		for (int i=1;i<=now;i++){
			for (int j=i+1;j<=now;j++){
				int a=num[i],b=num[j];
				code+=num[i]*1007+num[j]*10007;
				num[j]=num[now];
				num[i]=a+b;
				search(now-1);
				num[i]=a-b;
				search(now-1);
				num[i]=b-a;
				search(now-1);
				num[i]=a*b;
				search(now-1);
				if (b!=0&&a%b==0){
					num[i]=a/b;
					search(now-1);
				}
				if (a!=0&&b%a==0){
					num[i]=b/a;
					search(now-1);
				}
				num[i]=a;
				num[j]=b;
			}
		}
	}
}
int main(){
	for (int i=1;i<=4;i++)cin>>num[i];
	search(4);
	cout<<ans;
}
