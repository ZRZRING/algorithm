#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<string,int>mp;
int n=1,qza[1000010],qzb[1000010];
string begin,end,nowa,nowb,c1[10],c2[10],qa[1000010],qb[1000010],x,y,tx,ty;
int pd(string a,string b){
    if (a.length()!=b.length())return 0;
    for (int i=0;i<a.length();i++){
        if (a[i]!=b[i])return 0;
    }return 1;
}
int main(){
    cin>>begin>>end;
    while (cin>>c1[n]>>c2[n])n++;n--;
    int head=0,taila=1,tailb=1;qa[taila]=begin;qb[tailb]=end;
    while (head<tailb){
        head++;
        nowa=qa[head];nowb=qb[head];
		if (mp[nowa])continue;mp[nowa]=1;
        cout<<nowa<<"\n"<<nowb<<endl;
        if (pd(nowa,nowb)){
            cout<<qza[head]+qzb[head];return 0;
        }
        for (int i=1;i<=n;i++){
            for (int j=0;j<=nowa.length()-1;j++){
                int ct=nowa.find(c1[i],j);
                if (ct!=-1){
                    string tmp1;
                    for (int k=0;k<ct;k++){
                        tmp1+=nowa[k];
                    }
                    tmp1+=c2[i];
                    for (int k=ct+c1[i].length();k<=nowa.length()-1;k++){
                        tmp1+=nowa[k];
                    }
                    qa[++taila]=tmp1;qza[taila]=qza[head]+1;
                }
            }
        }
		if (mp[nowb])continue;mp[nowb]=1;
        for (int i=1;i<=n;i++){
            for (int j=0;j<=nowb.length()-1;j++){
                int ct=nowb.find(c2[i],j);
                if (ct!=-1){
                    string tmp1;
                    for (int k=0;k<ct;k++){
                        tmp1+=nowb[k];
                    }
                    tmp1+=c1[i];
                    for (int k=ct+c2[i].length();k<=nowb.length()-1;k++){
                        tmp1+=nowb[k];
                    }
                    qb[++tailb]=tmp1;qzb[tailb]=qzb[head]+1;
                }
            }
        }
    }
    cout<<"NO ANSWER!";
}
