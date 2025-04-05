/*
院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；
五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；
成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；
西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；
班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；

接下来的N行每行是一位学生的数据，从左向右依次是
姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数。
第1行是获得最多奖金的学生的姓名。
第2行是这名学生获得的奖金总数。如果有两位或两位以上的学生获得的奖金最多，输出他们之中在输入文件中出现最早的学生的姓名。
第3行是这N个学生获得的奖学金的总数。
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
struct stu{
    string name;
    int sc1,sc2,lw,money;
    char gb,xb;
}a[1000000];
string namee;
int n,sum,maxx;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].name>>a[i].sc1>>a[i].sc2>>a[i].gb>>a[i].xb>>a[i].lw;
        if (a[i].sc1>80&&a[i].lw)a[i].money+=8000;
        if (a[i].sc1>85&&a[i].sc2>80)a[i].money+=4000;
        if (a[i].sc1>90)a[i].money+=2000;
        if (a[i].sc1>85&&a[i].xb=='Y')a[i].money+=1000;
        if (a[i].sc2>80&&a[i].gb=='Y')a[i].money+=850;
        sum+=a[i].money;
        if (a[i].money>maxx)maxx=a[i].money,namee=a[i].name;
    }
    cout<<namee<<endl<<maxx<<endl<<sum;
}
