
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,top,stack[100010],goal,p[100010],T,ans,cnt,flag,word[100010],q[100010],lock;
string str,str1,str2;
char ch[100010];
void read(int m){
    for (int i=1;i<=m;i++){
        cin>>ch[0];
        if (ch[0]=='F'){
            cin>>ch[1]>>str1>>str2;
        }
    }
}
int check(string str1,string str2){
    if (str1.length()>str2.length())return 0;
    if (str1.length()<str2.length())return 1;
    int tmp=0;
    while (str1[tmp]==str2[tmp]&&tmp<=str2.length())tmp++;
    return str1[tmp]<=str2[tmp];
}
int main(){
    cin>>T;
    for (int t=1;t<=T;t++){
        ans=0;memset(p,0,sizeof(p));cnt=0,top=0;flag=1;lock=1;
        //q是复杂度栈，word是字母栈，同步修改 
        cin>>n;
        cin>>str;
        if (str[2]=='n'){//非常数级别
            goal=str[4]-'0';
            if (str[5]>='0'&&str[5]<='9'){
                goal*=10;goal+=str[5]-'0';
            }
        }else{//常数级别 
            goal=0;
        }
        int i; 
        for (i=1;i<=n;i++){
            cin>>ch[0];
            if (ch[0]=='E'){//出栈 
                if (top){
                    if (q[top]==1&&cnt>0)cnt--;//如果这一层不是常数复杂度，复杂度减减 
                    if (q[top]==2)lock=1;//解锁
                    p[word[top]]=0;//单词栈同步出栈 
                    top--;//安心离开栈（莫名伤感） 
                }else flag=0;//栈为空还出栈？bomm 
            }else{
                cin>>ch[1]>>str1>>str2;
                if (!p[ch[1]]){
                    if (str1[0]=='n'){
                        if (str2[0]=='n'){//前面n后面n 
                            top++;//只加栈不加复杂度，此处省略q[top]=0 
                        }else{//前面n后面常数，锁住目前ans 
                            q[++top]=2;lock=0;
                        }
                        p[ch[1]]=1;word[top]=ch[1];//随栈同步修改
                    }else{
                        if (str2[0]!='n'){//前面常数后面常数
                            if (check(str1,str2)){//判断前后大小关系 
                                top++;
                            }else{
                                q[++top]=2;lock=0;
                            }
                        }else{//前面常数后面n
                            top++;q[top]=1;cnt++;
                        } 
                        p[ch[1]]=1;word[top]=ch[1];
                    }
                    if (lock)ans=max(ans,cnt);//复杂度为出现过的最大的cnt
                }else flag=0;//这个变量被用过了，bomm 
            }
            if (!flag)break;//出现错误了，跳出去进行机械读入 
        }
        if (flag&&top==0){
            if (ans==goal)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            read(n-i);cout<<"ERR"<<endl;//机械读入状态
        }
    }
}