#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int pd[100010],prime[100010],n,cnt;
void rush(){
    for(int i=2;i<=10000;i++){
        if(!pd[i])prime[++cnt]=i;
        for(int j=1;j<=cnt;j++){
            if(i*prime[j]>10000)break;
            pd[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
	scanf("%d",&n);
	rush();
	for (int i=4;i<=n;i+=2){
		for (int j=1;j<=cnt&&prime[j]<i;j++){
			if (!pd[i-prime[j]]){
				printf("%d=%d+%d\n",i,prime[j],i-prime[j]);break;
			}
		}
	}
}
