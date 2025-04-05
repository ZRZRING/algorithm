#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char st1[1000010],st2[1000010],st3[1000010],cnt;
int pd[1000010],len1,len2,len3,flag,p[1000010];
int main(){
	cin>>st1+1>>st2+1;
	len1=strlen(st1+1);len2=strlen(st2+1);
	for (int i=1;i<=len1;i++){
		if (!pd[st1[i]]&&!p[st2[i]]){
			pd[st1[i]]=st2[i];cnt++;p[st2[i]]=st1[i];
		}else
		if (pd[st1[i]]!=st2[i]||p[st2[i]]!=st1[i]){
			flag=1;break;
		}
	}
	if (flag||cnt<26){
		printf("Failed");return 0;
	}
	cin>>st3+1;len3=strlen(st3+1);
	for (int i=1;i<=len3;i++){
		cout<<(char)pd[st3[i]];
	}
}
