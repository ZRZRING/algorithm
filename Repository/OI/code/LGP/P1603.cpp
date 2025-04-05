#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
map<string,int>f;
string str;
int a[100010],cnt,flag;
int main()
{
    f["one"]=f["One"]=1;
    f["two"]=f["Two"]=4;
    f["three"]=f["Three"]=9;
    f["four"]=f["Four"]=16;
    f["five"]=f["Five"]=25;
    f["six"]=f["Six"]=36;
    f["seven"]=f["Seven"]=49;
    f["eight"]=f["Eight"]=64;
    f["nine"]=f["Nine"]=81;
    f["ten"]=f["Ten"]=0;
    f["eleven"]=f["Eleven"]=12;
    f["twelve"]=f["Twelve"]=44;
    f["thriteen"]=f["Thriteen"]=69;
    f["fourteen"]=f["Fourteen"]=96;
    f["fifteen"]=f["Fifteen"]=25;
    f["sixteen"]=f["Sixteen"]=56;
    f["seventeen"]=f["Seventeen"]=89;
    f["eighteen"]=f["Eighteen"]=24;
    f["nineteen"]=f["Nineteen"]=61;
    f["twenty"]=f["Twenty"]=0;
    f["a"]=f["A"]=1;
    f["both"]=f["Both"]=4;
    f["another"]=f["Another"]=1;
    f["first"]=f["First"]=1;
    f["second"]=f["Second"]=4;
    f["third"]=f["Third"]=9;
    for (int i=1;i<=6;i++){
    	cin>>str;if (f[str]){
    		a[++cnt]=f[str];flag=1;
		}
	}
	if (!flag){
		cout<<0;return 0;
	}
	sort(a+1,a+cnt+1);
	for (int i=1;i<=cnt;i++){
		if (!(a[i]/10)&&i!=1)cout<<0;
		cout<<a[i];
	}
}
