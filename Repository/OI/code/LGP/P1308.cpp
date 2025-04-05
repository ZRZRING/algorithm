#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int pd,sta,sum,n;
char a[11], b[1000001];
int main(){
    gets(a);
    gets(b);
    strcat(a," "); 
    strcat(b," ");
    for (int i=0;a[i]!='\0';i++) {
        if (a[i]>='a')
            a[i]-='a'-'A';
    }
    for (int i=0;b[i]!='\0';i++) {
        if (b[i]>='a')
            b[i]-='a'-'A';
    }
	for (int i=0;b[i]!='\0';i++){
		if (b[i]!=' '){
		 	continue;
		}
		pd=1;
		for (int j=n,k=0;j<=i,a[k]!='\0';j++,k++) {
            if(b[j]!=a[k])pd=0;
        }
        if (pd){
            sum++; 
        }
        if (sum==1&&pd) {
            sta=n;  
        }
        n=i;n++;
	}
	if (!sum)cout<<-1;
	else cout<<sum<<' '<<sta;
}
