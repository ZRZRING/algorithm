#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int orz=100010;
int m,n,a[orz],sum,p[orz],read,tn,flag;
int cmp(int a,int b){
	return a>b;
}
void search(int now,int cnt,int last){
	if (flag)return;
	if (cnt==m){
		cnt=0,last=0,now++;
	}
	if (now==sum/m+1){
		cout<<m<<endl;flag=1;
	}else{
		for (int i=last+1;i<=n;i++){
			if (cnt+a[i]>m)continue;
			if (!p[i]){
				cnt+=a[i];p[i]=1;
				search(now,cnt,i);
				cnt-=a[i];p[i]=0;
				if(m-cnt==a[i]||cnt==0)return;
				while (a[i+1]==a[i])i++;
			}
		}
	}
}
int main(){
	while(cin>>tn){
		if(tn==0)break;		
		n=0;sum=0;flag=0;
		for (int i=1;i<=tn;i++){
			cin>>read;
			if (read<=50){
				a[++n]=read;sum+=a[n];
			}
		}
		sort(a+1,a+n+1,cmp);
		for (m=a[1];m<=sum;m++){
			memset(p,0,sizeof(p));
			if (sum%m!=0)continue;
			search(1,0,0);
		}
	}
}
