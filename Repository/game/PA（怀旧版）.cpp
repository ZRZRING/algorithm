#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

const int jnSL=6;
int J[2];
int ZT_nl[2],ZT_aj[2],ZT_gj[2],ZT_xy[2],ZT_bt[2];
int FH_wz;
char FH_z;

////////////////////////////////
void S(double tmp)
{
	Sleep(tmp*1000);
}
void s()
{
	system("cls");
}
void w(int tmp)
{
	cout<<(char)tmp;
}
void wz(int tmp)
{
	cout<<ZT_nl[tmp];
}
/////////////////////////////////

void pdnl(int tmp)
{
	if (ZT_nl[tmp]<3)
	{
        ZT_aj[tmp]++;
        if (ZT_aj[tmp]>=20)
        {
            ZT_nl[tmp]++;
            ZT_aj[tmp]=0;
        }
	}
}
void pdFH(char tmp,int tmp1)
{
	switch (tmp)
	{
		case 'a':
			if (ZT_xy[0]==0)
			{
				J[0]--;
				pdnl(0);
				if (J[0]==J[1])
				    if (ZT_bt[1]==0)
						J[1]-=ZT_gj[0];
					else
					{
						ZT_bt[1]--;
						J[0]++;
					}
			}
			else
			{
				ZT_xy[0]--;
			}
			break;
				
		case 'd':
			if (ZT_xy[0]==0)
			{
				J[0]++;
				pdnl(0);
				if (J[0]==J[1])
				    if (ZT_bt[1]==0)
						J[1]+=ZT_gj[0];
					else
					{
						ZT_bt[1]--;
						J[0]--;
					}
			}
			else
			{
				ZT_xy[0]--;
			}
			break;
			
		case 'j':
			if (ZT_xy[1]==0)
			{
				J[1]--;
				pdnl(1);
				if (J[1]==J[0])
				    if (ZT_bt[0]==0)
						J[0]-=ZT_gj[1];
					else
					{
						ZT_bt[0]--;
						J[1]++;
					}
			}
			else
			{
				ZT_xy[1]--;
			}
			break;
			
		case 'l': 
		    if (ZT_xy[1]==0)
			{
				J[1]++;
				pdnl(1);
				if (J[1]==J[0])
				    if (ZT_bt[0]==0)
						J[0]+=ZT_gj[1];
					else
					{
						ZT_bt[0]--;
						J[1]--;
					}
			}
			else
			{
				ZT_xy[1]--;
			}
	        break;
		//////////////////////////////////
		
		case '!':
            ZT_xy[!tmp1]+=5;   
			break;
		
		case '@':
            if (tmp1==0)
            {
                J[1]+=10;
            }
            else
            {
                J[0]-=10;
            }
			break;
		
		case '#':
            ZT_xy[!tmp1]+=2;
			ZT_bt[tmp1]+=2;
	        if (tmp1==0)
            {
                J[1]+=5;
            }
            else
            {
                J[0]-=5;
            } 
			break;
		
		case '$':
            if (tmp1==1)
            {
                J[1]-=10;
                if (J[1]<=J[0])
				{
					J[1]=J[0]+1;
				} 
            }
            else
            {
                J[0]+=10;
                if (J[1]>=J[0])
				{
					J[0]=J[1]-1;
				} 
            }  
			break;
			
		case '%':
            ZT_bt[tmp1]+=5;  
			break; 
			
		case '^':
			if (ZT_nl[tmp]<3)
			{
			    ZT_nl[tmp]++;
            }
			break;
			
		case '&':
			if (ZT_nl[!tmp]>0)
			{
				ZT_nl[!tmp]--;
			}
			break;
		
		////////////////////////////////// 
		
		case 'z':
			if (ZT_nl[0]>=1)
			    if (ZT_xy[0]==0)
				    if (ZT_bt[1]==0)
				    {
				        J[1]+=5;
				        ZT_nl[0]-=1;
				    }
				    else
				    {
					    ZT_bt[1]-=2;
					    if (ZT_bt[1]>0)
					    {
					    	ZT_bt[1]=0;
					    }
					    ZT_nl[0]-=1;
					}
			break;
		
		case 'x':
			if (ZT_nl[0]>=2)
			    if (ZT_xy[0]==0)
				    if (ZT_bt[1]==0)
				    {
				        J[1]+=10;
				        ZT_xy[1]+=2; 
				        ZT_nl[0]-=2;
				    }
				    else
				    {
				    	ZT_bt[1]-=3;
				    	if (ZT_bt[1]<0)
				    	{
				    		ZT_bt[1]=0;
				    	}
				    	ZT_nl[0]-=2;
				    }
			break;
		
		case 'c':
			if (ZT_nl[0]>=3)
			    if (ZT_xy[0]==0)
				    if (ZT_bt[1]==0)
				    {
				        J[1]+=15;
				        ZT_bt[0]+=10;
				        ZT_nl[0]-=3;
				    }
				    else
				    {
				    	ZT_bt[1]=0;
				    	ZT_nl[0]-=3;
				    }
			break;
		
		//////////////////////////////////
		
		case 'm':
			if (ZT_nl[1]>=1)
			    if (ZT_xy[1]==0)
				    if (ZT_bt[0]==0)
				    {
				        J[0]-=5;
				        ZT_nl[1]-=1;
				    }
				    else
				    {
					    ZT_bt[0]-=2;
				    	if (ZT_bt[0]<0)
				    	{
				    		ZT_bt[0]=0;
				    	}
					    ZT_nl[1]-=1;
					}
			break;
		
		case ',':
			if (ZT_nl[1]>=2)
			    if (ZT_xy[1]==0)
				    if (ZT_bt[0]==0)
				    {
				        J[0]-=10;
				        ZT_xy[0]+=2; 
				        ZT_nl[1]-=2;
				    }
				    else
			    	{
				    	ZT_bt[0]-=3;
				    	if (ZT_bt[0]<0)
				    	{
				    		ZT_bt[0]=0;
				    	}
				    	ZT_nl[1]-=2;
				    }
			break;
		
		case '.':
			if (ZT_nl[1]>=3)
			    if (ZT_xy[1]==0)
				    if (ZT_bt[0]==0)
				    {
				        J[0]-=15;
				        ZT_bt[1]+=10;
				        ZT_nl[1]-=3;
				    }
				    else
				    {
				    	ZT_bt[0]=0;
				    	ZT_nl[1]-=3;
				    }
			break;
		
	}
}
void xzFH(int tmp)
{
	switch (tmp)
	{
		case 0:
			FH_z='!';
			break;
		case 1:
			FH_z='@';
			break;
		case 2:
			FH_z='#';
			break;
		case 3:
			FH_z='$';
			break;
		case 4:
			FH_z='%';
			break;
		case 5:
			FH_z='^';
			break;
		case 6:
			FH_z='&';
			break;
	}
}
void xzWZ()
{
	FH_wz=rand()%80;
    if (FH_wz==J[0])
    {
	    pdFH(FH_wz,0);
	    xzWZ();
    }
    if (FH_wz==J[1])
    {
        pdFH(FH_wz,1);
        xzWZ();
    }
}
void jdFH()
{
    int tmp=rand()%300;
	if (tmp<=jnSL)
	{
		xzFH(tmp);
		xzWZ();
	}
}
void write_now()
{
    for (int i=1;i<=80;i++)
	{
		int tmp=0;
	    if (i==J[0])
		{
		    w(1);
		    tmp=1;
        }
		if (i==J[1])
		{
            w(2);
		    tmp=1;
        } 
	    if (i==FH_wz)
	    {
	        cout<<FH_z;
		    tmp=1;
	    }
	    if (!tmp)
	    {
            cout<<" ";
        }
	}
	for (int i=1;i<=80;i++)
	{
		int tmp=0;
	    if (i==J[0])
		{
		    cout<<ZT_nl[0];
		    tmp=1;
        }
		if (i==J[1])
		{
            cout<<ZT_nl[1];
		    tmp=1;
        } 
        if (!tmp)
        {
        	cout<<' ';
        }
    }
    cout<<endl;
    cout<<"���1ѣ�Σ�"<<ZT_xy[0]<<endl;
	cout<<"���1���壺"<<ZT_bt[0]<<endl;
	cout<<"���1������"<<ZT_gj[0]<<endl; 
	cout<<"���2ѣ�Σ�"<<ZT_xy[1]<<endl;
	cout<<"���2���壺"<<ZT_bt[1]<<endl; 
	cout<<"���2������"<<ZT_gj[1]<<endl;
	cout<<endl; 
	cout<<"! ʹ����ѣ��5��"<<endl; 
	cout<<"@ ʹ�����˺�10��"<<endl; 
	cout<<"% ���Լ���5�����"<<endl; 
	cout<<"$ ���Լ���ǰ����10��,������ͣ"<<endl;
	cout<<"# ʹ�����˺�5��ѣ��2�Σ����Լ���2�����"<<endl; 
	cout<<"^ ���Լ���һ������"<<endl;
	cout<<"& �����ּ�һ������"<<endl;
}
void chushihua()
{
	ZT_nl[0]=-1,ZT_aj[0]=0,ZT_gj[0]=1,ZT_xy[0]=0,ZT_bt[0]=0;
	ZT_nl[1]=-1,ZT_aj[1]=0,ZT_gj[1]=1,ZT_xy[1]=0,ZT_bt[1]=0;
    int tmp=rand()%jnSL;
	if (tmp<=jnSL)
	{
		xzFH(tmp);
		xzWZ();
	}
	ZT_nl[0]=0;
	ZT_nl[1]=0;
	J[0]=20; J[1]=60;
}
void start()
{
    cout<<"˵����"<<endl;
    cout<<"���1 ad �����ƶ���z һ���ܣ�x �����ܣ�c ����"<<endl;
    cout<<"���2 jl �����ƶ���m һ���ܣ�, �����ܣ�. ����"<<endl;
    cout<<"һ���� �˺�5��           or �ư���2��"<<endl;
    cout<<"������ �˺�10��ѣ��2�� or �ư���3��"<<endl;
    cout<<"������ �˺�15�񲢰���5�� or �����а���"<<endl;
    system("pause");
    s();
}
void play()
{
	chushihua();
	while (J[0]>0&&J[1]<81&&J[1]>0&&J[0]<81)
	{
		write_now();
		int getch1=getch();
		if (getch1!='t'&&getch1!='r'&&getch1!='b'&&getch1!='u'&&getch1!='y')
        {    
			pdFH(getch1,0);
		}
        if (J[0]==FH_wz)
        {
            pdFH(FH_z,0);
            int tmp=rand()%3;
			if (tmp<=3)
			{
			    xzFH(tmp);
			    xzWZ();
            }
        }
        if (J[1]==FH_wz)
        {
            pdFH(FH_z,1);
            int tmp=rand()%3;
			if (tmp<=3)
			{
			    xzFH(tmp);
			    xzWZ();
            }
        }
        jdFH();
        s(); 
	}
}
void getch2()
{
	if (getch()!='5')
	{
		getch2();
	}
}
void end()
{
	if (J[0]<1||J[0]>81)
	{
		cout<<"�����һ�ʤ"<<endl;
	}
	else
	{
		cout<<"�ұ���һ�ʤ"<<endl;
	}
	cout<<"�����ּ�5�˳�";
	getch2();
}
int main()
{
	srand(time(0));
	start();
	play();
	end();
}
