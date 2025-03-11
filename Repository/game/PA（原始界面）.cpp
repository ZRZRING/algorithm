#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

/*
写在前面（exe不给开放）【测试服专属】
（1）眩晕可以使人的一次非技能移动失效霸体可以使推进者一次非技能推进失效。
（2）攻击表示一次推进的格数。
（3）中毒可以使人每移动2格附带眩晕2次。
（4）剧毒可以使人每移动1格附带眩晕2次。
（5）迷魂持续10~30回合，到期自动消除。
（6）眩晕状态移动不消耗迷魂回合数。
（7）冰冻状态下不能移动并在解除冰冻后每两次移动前进一格（相反操作自己试试吧）
（8）3格能量角色1格能量需要非技能移动15次。
（9）6格能量角色1格能量需要非技能移动10次。
（10）9格能量角色1格能量需要非技能移动7次 。
（11）闪现无视对手，移动若对手阻挡将会推进。
（12）其它带有中括号的名词请自己查看，不一一赘述了。

*/
struct ZT1
{
	int nl,aj,ajn,gj,xy,bt; 
	int bt_xy,xy_bt;
	int zd,zdhh,jd,bd,ds,dax;       
	int mh;
}ZT[2];

struct SL1
{
	int jn,js;
}SL;

struct BJ1
{
	int ay,ck,mhs,lz,ds;
}BJ[2];

struct FH1
{
	int wz;
	char z;
}FH;

struct JS1
{
	int n,ajn,nln;
}JS[2];

int J[2],JFX[2];  

void start();
void play();
void end(); 

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
	cout<<ZT[tmp].nl;
}
/////////////////////////////////

void pdnl(int tmp)
{
	if (ZT[tmp].nl<JS[tmp].nln)
	{
        ZT[tmp].aj++;
        if (ZT[tmp].aj>=JS[tmp].ajn)
        {
            ZT[tmp].nl++;
            ZT[tmp].aj=0;
        }
	}
}
int pdds(int tmp)
{
	if (ZT[tmp].ds>0)
	{
		ZT[tmp].ds--;
		if (ZT[tmp].ds%2==0)
		{
			return 1;
		}
	}
	return 0;
}
void pdbd(int tmp)
{
	if (ZT[tmp].bd>0)
	{
		ZT[tmp].bd--;
		if (ZT[tmp].bd==0)
		{
			ZT[tmp].ds+=(rand()%5+5)*2;
		}
	}
}
void pdzd(int tmp)
{
	if (ZT[tmp].zd>0)
	{
		ZT[tmp].zdhh++;
		if (ZT[tmp].zdhh>=2)
		{
			ZT[tmp].xy+=2;
			ZT[tmp].zd--;
			ZT[tmp].zdhh=0;
		}
	}
	
}
void pdjd(int tmp)
{
	if (ZT[tmp].jd>0)
	{
		ZT[tmp].xy+=2;
		ZT[tmp].jd--;
	}
}
void pdBJ(int tmp,int FX)
{
	if (BJ[tmp].ay>0)
	{
		int tmp2=rand()%100+1;
		if (tmp2<=10)
		{
			J[tmp]+=FX;
			if (J[tmp]==J[!tmp])
				if (ZT[!tmp].bt==0)
					J[!tmp]+=FX;
				else
				{
					ZT[!tmp].bt--;
					J[tmp]-=FX;
				}
		}
		BJ[tmp].ay--;
	}
	if (BJ[tmp].ck>0)
	{
		int tmp2=rand()%100+1;
		if (tmp2<=10)
		{
			J[tmp]-=2*FX;
			if (J[tmp]==J[!tmp]) J[tmp]+=FX;
			if (J[tmp]>81)       J[tmp]=81;
			if (J[tmp]<0)        J[tmp]=0;
			ZT[!tmp].xy+=3;
		}
	}
	if (BJ[tmp].lz>0)
	{
		BJ[tmp].lz--; 
	}
	if (BJ[tmp].ds>0)
	{
		BJ[tmp].ds--;
	} 
}
int pdmh(int tmp1)
{
	if (tmp1=='q') return 'e'; 
	if (tmp1=='e') return 'q';
	if (tmp1=='a') return 'd';
	if (tmp1=='d') return 'a';
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
	    if (i==FH.wz)
	    {
	        cout<<FH.z;
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
		    cout<<ZT[0].nl;
		    tmp=1;
        }
		if (i==J[1])
		{
            cout<<ZT[1].nl;
		    tmp=1;
        } 
        if (!tmp)
        {
        	cout<<' ';
        }
    }
    cout<<endl;
    cout<<"玩家1眩晕："<<ZT[0].xy<<' ';   cout<<"玩家1霸体："<<ZT[0].bt<<endl;
    cout<<"玩家1中毒："<<ZT[0].zd<<' ';   cout<<"玩家1剧毒："<<ZT[0].jd<<endl;	
    cout<<"玩家1攻击："<<ZT[0].gj<<' ';   cout<<"玩家1冰冻："<<ZT[0].bd<<endl;
	cout<<"玩家1冻伤："<<ZT[0].ds/2<<' '; 
	cout<<endl;
	if (BJ[0].ay>0)  cout<<"玩家1拥有暗影标记!"<<endl; 
	if (BJ[0].ck>0)  cout<<"玩家1拥有刺客信条!"<<endl; 
	if (BJ[0].mhs>0) cout<<"玩家1习得迷魂术!"<<endl; 
	if (BJ[0].lz>0) cout<<"玩家1释放狼族血脉!"<<endl;
	if (BJ[0].ds>0) cout<<"玩家1释放大圣显威!"<<endl;  
	cout<<endl;
	
    cout<<"玩家2眩晕："<<ZT[1].xy<<' ';   cout<<"玩家2霸体："<<ZT[1].bt<<endl;
	cout<<"玩家2中毒："<<ZT[1].zd<<' ';   cout<<"玩家2剧毒："<<ZT[1].jd<<endl;
	cout<<"玩家2攻击："<<ZT[1].gj<<' ';   cout<<"玩家2冰冻："<<ZT[1].bd<<endl;
	cout<<"玩家2冻伤："<<ZT[1].ds/2<<' '; 
	cout<<endl;
	if (BJ[1].ay>0)  cout<<"玩家2拥有暗影标记!"<<endl;
	if (BJ[1].ck>0)  cout<<"玩家2拥有刺客信条!"<<endl; 
	if (BJ[1].mhs>0) cout<<"玩家2习得迷魂术!"<<endl; 
	if (BJ[1].lz>0) cout<<"玩家2释放狼族血脉!"<<endl; 
	if (BJ[1].ds>0) cout<<"玩家2释放大圣显威!"<<endl; 
	cout<<endl;
	
	cout<<"! 使对手眩晕5次"<<endl; 
	cout<<"@ 使对手退后10格"<<endl; 
	cout<<"% 给自己加5层霸体"<<endl; 
	cout<<"$ 给自己向前闪现10格"<<endl;
	cout<<"# 使对手退后5格并眩晕2次，给自己加2层霸体"<<endl; 
	cout<<"^ 给自己加一格能量"<<endl;
	cout<<"& 给对手减一格能量"<<endl;
}
void pdFH(int tmp1,int tmp)
{
    if (tmp1==0xE0)
    {
        int ch=getch();
        if (ch==75)
        {
        	tmp1='q';
        }
        else
        {
            if (ch==77)
			{
				tmp1='e';
			} 
        }
    }
	switch (tmp1)
	{
		case '!':
            ZT[!tmp].xy+=5;   
			break;
		
		case '@':
            J[!tmp]-=10*JFX[!tmp];
			break;
		
		case '#':
            ZT[!tmp].xy+=2;
			ZT[tmp].bt+=2;
            J[!tmp]-=5*JFX[!tmp];
			break;
		
		case '$':
            J[tmp]+=JFX[tmp];
            if (J[0]==J[1])
            {
            	J[!tmp]-=JFX[!tmp];
            }
			break;
			
		case '%':
            ZT[tmp].bt+=5;  
			break; 
			
		case '^':
			if (ZT[tmp].nl<3)
			{
			    ZT[tmp].nl++;
            }
			break;
			
		case '&':
			if (ZT[!tmp].nl>0)
			{
				ZT[!tmp].nl--;
			}
			break;
			
		case 'a':tmp=0;break;
		case 'd':tmp=0;break;	
		case 'j':tmp=0;break;
		case 'k':tmp=0;break;
		case 'l':tmp=0;break;
		case 'h':tmp=0;break;
		case 'q':tmp=1;break;
		case 'e':tmp=1;break;
		case '1':tmp=1;break;
		case '2':tmp=1;break;
		case '3':tmp=1;break;
		case '0':tmp=1;break;
	}
	if (ZT[tmp].mh>0&&ZT[tmp].xy==0)
	{
		tmp1=pdmh(tmp1);
		ZT[tmp].mh--;
	}
	switch (tmp1)                                      
	{
		case 'a': case 'q':                            
			if (ZT[tmp].xy==0)
			{
				if (pdds(tmp))break;
				if (ZT[tmp].bd>0)
				{
					pdbd(tmp);
					break;
				}
				pdzd(tmp);
				pdjd(tmp);
				pdBJ(tmp,-1);
				pdnl(tmp);
				J[tmp]--;
				if (J[tmp]==J[!tmp])
				    if (ZT[!tmp].bt==0)
						J[!tmp]-=ZT[tmp].gj;
					else
					{
						ZT[!tmp].bt--;
						if (ZT[!tmp].bt_xy>0)
						{
							ZT[tmp].xy++;
							ZT[!tmp].bt_xy--;
						}
						J[tmp]++;
					}
			}
			else
			{
				ZT[tmp].xy--;
				if (ZT[!tmp].xy_bt>0)
				{
					ZT[!tmp].bt++;
					ZT[!tmp].xy_bt--;
				}
			}
			break;
				
		case 'd': case 'e':
			if (ZT[tmp].xy==0)
			{
				if (pdds(tmp))break;
				if (ZT[tmp].bd>0)
				{
					pdbd(tmp);
					break;
				}
				pdzd(tmp);
				pdjd(tmp);
				pdBJ(tmp,1);
				pdnl(tmp);
				J[tmp]++;
				if (J[tmp]==J[!tmp])
				    if (ZT[!tmp].bt==0)
						J[!tmp]+=ZT[tmp].gj;
					else
					{
						ZT[!tmp].bt--;
						if (ZT[!tmp].bt_xy>0)
						{
							ZT[tmp].xy++;
							ZT[tmp].bt_xy--;
						}
						J[tmp]--;
					}
			}
			else
			{
				ZT[tmp].xy--;
				if (ZT[!tmp].xy_bt>0)
				{
					ZT[!tmp].bt++;
					ZT[!tmp].xy_bt--;
				}
			}
			break;
			
		case 'j': case '1':                                //技能区 //一技能 
			switch (JS[tmp].n)
			{ 
			    case 1:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])==1)
					{
				    	if (ZT[!tmp].bt==0)
				    	{
				        	J[!tmp]-=7*JFX[!tmp];
				        	ZT[tmp].bt+=2;
				    	}
				    	else
				    	{
					    	ZT[!tmp].bt-=5;
					    	if (ZT[!tmp].bt<0)
					    	{
					    		ZT[!tmp].bt=0;
					    	    ZT[!tmp].xy+=5; 
					    	}
						}
						ZT[tmp].nl--;
				    }
				    break;
				
				case 2:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0)
					{
				        J[!tmp]-=5*JFX[!tmp];
				        ZT[!tmp].xy+=2;
						ZT[tmp].nl--;
				    }
			    	break;
				
				case 3:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&J[tmp]>7&&J[tmp]<73)
					{
					    J[tmp]=FH.wz+1;
					    if (J[0]==J[1])
					    {
						    J[tmp]=FH.wz-1;
						    J[!tmp]-=3*JFX[!tmp]; 
					    }
					    ZT[tmp].nl--;
				    }
				    break;
				    
				case 4:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0)
					{
					    ZT[tmp].bt+=3;
						ZT[!tmp].xy+=3;
						ZT[tmp].nl--;
				    }
					break;
					
				case 5:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&ZT[!tmp].bt==0)
					{
					    ZT[!tmp].zd+=3;
						ZT[tmp].nl--;
				    }
					break;
					
				
				case 6:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0)
					{
						if (J[tmp]>=5&&J[tmp]<=75)
						{
							J[tmp]+=10*JFX[tmp];
							if (J[tmp]==J[!tmp])
							{
								J[tmp]+=JFX[tmp];
							} 
						}
						ZT[!tmp].xy+=3;
						int tmp2=rand()%100+1;
						if (tmp2<=50)
						{
							BJ[tmp].ay+=50;
						} 
						ZT[tmp].nl--;
					}
					break;
					
				case 7:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0)
					{
						ZT[!tmp].xy+=2;
						int tmp2=rand()%100+1;
						if (tmp2<=25)
						{
							if (ZT[!tmp].mh>0)
							{
								ZT[tmp].nl++;
							}
							else
							{
								ZT[!tmp].mh+=rand()%21+10;
							}
						}
						ZT[tmp].nl--;
					}
					break;
					
				case 8:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])<=1)
					{
						J[!tmp]-=10*JFX[!tmp];
						ZT[tmp].nl-=2;
					}
					break;
				
				case 9:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0)
					{
						ZT[!tmp].ds+=5*2;
						ZT[tmp].nl--;
					}
					break;
					
				case 10:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
						J[tmp]+=18*JFX[tmp]; 
						ZT[tmp].nl-=2;
						if (J[tmp]==J[!tmp])J[tmp]++;
					}
					break;
			} 
			break;
		case 'k': case'2':                                 //二技能 
			switch (JS[tmp].n)
			{ 
			    case 1:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])==1)
					{
				    	if (ZT[!tmp].bt==0)
				    	{
				        	J[!tmp]-=12*JFX[!tmp];
				        	ZT[tmp].bt+=5;
				    	}
				    	else
				    	{
					    	ZT[!tmp].bt-=10;
					    	if (ZT[!tmp].bt<0)
					    	{
					    		ZT[!tmp].bt=0;
					        	ZT[!tmp].xy+=5;
					    	}
						}
						ZT[tmp].nl-=2;
				    }
			    	break;
				
				case 2:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
				        ZT[!tmp].xy+=10;
						ZT[tmp].nl-=2;
				    }
				    break;
				    
				case 3:
				    if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
				        if (abs(J[tmp]-J[!tmp])==1)
					    {
						    if (J[tmp]>15&&J[tmp]<65)
						    {
						        J[tmp]+=2*(J[!tmp]-J[tmp]);
						        ZT[!tmp].xy+=5; 
					        }
					        else
					        {
						        ZT[tmp].nl++;
						    }
						}
					    else
					    {
							if (J[tmp]>J[!tmp])
							{
								J[tmp]=J[!tmp]+1; 
							}
							else
						 	{ 
								J[tmp]=J[!tmp]-1;
							}
						    ZT[!tmp].xy+=5;
						}
						ZT[tmp].nl-=2;
				    }
			    	break;
			    	
			    case 4:
			    	if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
				        ZT[!tmp].xy+=5;
				        ZT[tmp].xy_bt+=5;
				        ZT[tmp].nl-=2;
				    }
				    break;
				    
				case 5:
			    	if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
				        ZT[!tmp].zd+=5;
				        ZT[tmp].nl-=2;
				    }
				    break;
				    
				case 6:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
				        J[tmp]=rand()%80;
				        if (J[tmp]==J[!tmp])
				        {
				        	J[tmp]+=JFX[tmp];
				        }
				        ZT[tmp].bt+=10; 
						int tmp2=rand()%100+1;
						if (tmp2<=50)
						{
							BJ[tmp].ay+=50;
						} 
						ZT[tmp].nl-=2;
				    }
				    break;
					
				case 7:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
						ZT[!tmp].xy+=5;
						int tmp2=rand()%100+1;
						if (tmp2<=80)
						{
							if (ZT[!tmp].mh>0)
							{
								ZT[tmp].nl+=2;
							}
							else
							{
								ZT[!tmp].mh+=rand()%21+10;
							}
						}
						ZT[tmp].nl-=2;
					}
					break;
					
				case 8:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])<=1)
					{
						J[!tmp]-=15*JFX[!tmp];
						int tmp2=rand()%100;
						if (tmp2<=5)
						{
							BJ[tmp].lz+=10;
						}
						ZT[tmp].nl-=3;
					}
					break;
					
				case 9:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
						ZT[!tmp].bd+=5;
						ZT[tmp].nl-=2;
					}
					break;
					
				case 10:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0)
					{
						ZT[tmp].dax+=2;
						ZT[tmp].nl-=2;
					}
					break;
			} 
			break;
		case 'l': case '3':	                               //三技能 
			switch (JS[tmp].n)
			{ 
			    case 1:
			    	if (ZT[tmp].nl>=3)
			    	{
			    		ZT[tmp].xy=0;
						ZT[tmp].bt+=30;
						ZT[tmp].nl-=3;
					}
			    	break;
				
				case 2:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0)
					{
				        ZT[!tmp].xy+=20;
				        ZT[!tmp].nl=0;
						ZT[tmp].nl-=3;
				    }
				    break;
				case 3:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0)
					{
						BJ[tmp].ck+=50;
						ZT[!tmp].xy+=15;
						J[tmp]-=5*JFX[tmp];
						ZT[tmp].nl-=3;
				    }	
					break;
					
				case 4:
				    if (ZT[tmp].nl>=3&&ZT[tmp].xy==0)
					{
				        ZT[tmp].bt+=10;
				        ZT[tmp].bt_xy+=10;
				        ZT[tmp].nl-=3;
				    }
				    break;
					
				case 5:
				    if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&ZT[!tmp].bt==0)
					{
				        ZT[!tmp].jd+=8;
				        if (ZT[!tmp].nl>0)
				        {
				            ZT[!tmp].nl-=1;
				        }
				        ZT[tmp].nl-=3;
				    }
				    break;
				
				case 6:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0)
					{
						J[tmp]=rand()%80;
						J[!tmp]=rand()%80;
						if (J[tmp]==J[!tmp])
						{
							J[tmp]+=JFX[tmp];
						}
						int tmp2=rand()%100+1;
						if (tmp2<=50)
						{
							BJ[tmp].ay+=50;
						} 
						if (BJ[tmp].ay>0)
						{
							ZT[tmp].nl++;
						}
						ZT[tmp].bt+=10;
						ZT[!tmp].xy+=10; 
						ZT[tmp].nl-=3;
					}
					break;
					
				case 7:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0)
					{
						ZT[!tmp].xy+=10;
						BJ[tmp].mhs+=20;
						ZT[tmp].nl-=3;
					}
					break;
					
				case 8:
					if (ZT[tmp].nl>=9&&ZT[tmp].xy==0)
					{
						for (int i=1;i<=5;i++)
						{
							s();J[!tmp]-=5*JFX[!tmp];
							write_now();
						}
						ZT[!tmp].xy+=5;
						int tmp2=rand()%100;
						if (tmp2<=25)
						{
							BJ[tmp].lz+=50;
						}
						ZT[tmp].nl-=9;
					}
					break;
					
				case 9: 
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0)
					{
						ZT[!tmp].bd+=15;
						ZT[tmp].nl-=3;
					}
					break;
					
				case 10:
					if (ZT[tmp].nl>=6&&ZT[tmp].xy==0)
					{
						J[!tmp]-=(15+ZT[tmp].dax)*JFX[!tmp];
						BJ[tmp].ds+=50; 
						ZT[tmp].nl-=6;
					}
			} 
			break;
			
		case 'h': case'0':                                     //附属技能 
			switch (JS[tmp].n)
			{
				case 7:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&BJ[tmp].mhs>0)
					{
						if (ZT[!tmp].mh>0)
						{
							ZT[tmp].nl++;
						}
						else
						{
							ZT[!tmp].mh+=rand()%16+5;
							BJ[tmp].mhs--;
						}
						ZT[tmp].nl--;
					}
					break;
					
				case 8:
					if (ZT[tmp].nl>=6&&ZT[tmp].xy==0&&BJ[tmp].lz>0)
					{
						ZT[tmp].gj++;
						ZT[tmp].nl-=6; 
					}
					break;
					
			    case 10:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&BJ[tmp].ds>0)
					{
						ZT[tmp].bt+=10;
						ZT[tmp].nl-=3;
					}
			}
			break;
	} 
}

void xzFH(int tmp)
{
	switch (tmp)
	{
		case 0:
			FH.z='!';
			break;
		case 1:
			FH.z='@';
			break;
		case 2:
			FH.z='#';
			break;
		case 3:
			FH.z='$';
			break;
		case 4:
			FH.z='%';
			break;
		case 5:
			FH.z='^';
			break;
		case 6:
			FH.z='&';
			break;
	}
}
void xzWZ()
{
	FH.wz=rand()%80;
    if (FH.wz==J[0])
    {
	    pdFH(FH.z,0);
	    xzWZ();
    }
    if (FH.wz==J[1])
    {
        pdFH(FH.z,1);
        xzWZ();
    }
}
void jdFH()
{
    int tmp=rand()%500;
	if (tmp<=SL.jn)
	{
		xzFH(tmp);
		xzWZ();
	}
}
void chushihua()
{
	ZT[0].nl=0,ZT[0].aj=0,ZT[0].gj=1,ZT[0].xy=0,ZT[0].bt=0;ZT[0].bd=0;ZT[0].ds=0;
	ZT[0].xy_bt=0,ZT[0].bt_xy=0;
	ZT[0].zd=0,ZT[0].zdhh=0,ZT[0].jd=0;ZT[0].dax=0;
	BJ[0].ay=0;BJ[0].ck=0;BJ[0].mhs=0;BJ[0].lz=0;
    ZT[1].nl=0,ZT[1].aj=0,ZT[1].gj=1,ZT[1].xy=0,ZT[1].bt=0;ZT[1].bd=0;ZT[1].ds=0;
	ZT[1].xy_bt=0,ZT[1].bt_xy=0;
	ZT[1].zd=0,ZT[1].zdhh=0,ZT[1].jd=0;ZT[1].dax=0;
	BJ[1].ay=0;BJ[1].ck=0;BJ[1].mhs=0;BJ[1].lz=0;
	J[0]=20; J[1]=60;
	SL.jn=7; SL.js=10;
    int tmp=rand()%SL.jn+1;
	if (tmp<=SL.jn)
	{
		xzFH(tmp);
		xzWZ();
	}
}
void cin1(int &a)
{
	cin>>a;
	if (a<1||a>SL.js)
	{
		cin1(a);
	}
}
void write_juese(int tmp)
{
	switch (tmp)
	{
		case 1:
		cout<<"特点：    擅长霸体、推进"<<endl;
		cout<<"角色被动；一、二技能需要贴身释放"<<endl; 
		cout<<"一技能：  使对手退后7格并获得2层霸体，若对方有霸体，则破对方霸体5层并眩晕5次"<<endl;
		cout<<"二技能：  使对手退后12格并获得5层霸体，若对方有霸体，则破对方霸体10层并眩晕5次"<<endl;
		cout<<"大招：    消除自身所有负面效果并获得30层霸体"<<endl;
		break;
		
		case 2: 
		cout<<"特点：擅长眩晕"<<endl;
		cout<<"角色被动：技能全部无视霸体"<<endl; 
		cout<<"一技能：  使对手退后5格并眩晕2次"<<endl;
		cout<<"二技能：  使对手眩晕10次"<<endl;
		cout<<"大招：    使对手能量清0，眩晕20次"<<endl;
		break;
		
		case 3:
	    cout<<"特点：擅长瞬移"<<endl;
		cout<<"【刺客信条】可以使自己有一定概率使自己移动变成退后一格并使对手眩晕3次"<<endl;
		cout<<"一技能：瞬移到道具附近，并使对手退后3格，但使用技能时，自己至少离边界有7格距离"<<endl;
		cout<<"二技能：瞬移至对手面前并使对手眩晕5次，若已在对手面前并离边界超过15格距离，则跳         到对手后面并眩晕5次"<<endl;
		cout<<"大招：  使自己退后5格并拥有【刺客信条】持续50回合并使对手眩晕15次"<<endl;
		break;
		
		case 4:
		cout<<"特点：擅长膜蛤，技能附带特殊效果"<<endl;
		cout<<"一技能：  让对手眩晕3次并给自己加3层霸体"<<endl;
		cout<<"二技能：  让对手眩晕5次【专属被动：对手每破眩晕1次，给自身加1层霸体】"<<endl;
		cout<<"大招：    获得10层霸体【专属被动：每破1层霸体，就会让对手眩晕1次】"<<endl;
        break;
        
        case 5:
        cout<<"特点：擅长用毒，中毒可以使人移动时附带眩晕"<<endl;
        cout<<"一技能：使对手中毒3次"<<endl;
        cout<<"二技能：使对手中毒5次【专属被动：此技能无视霸体】"<<endl;
        cout<<"大招：  使对手中剧毒8次并扣除1点能量"<<endl;
        break;
        
        case 6:
        cout<<"特点：擅长移动，拥有重置战场的能力"<<endl;
		cout<<"【暗影标记】可以使自己移动时候较小概率移动2格【注意：不是闪现】"<<endl;
        cout<<"角色被动：释放技能有一定概率给自己施加【暗影标记】，持续50回合"<<endl;
        cout<<"一技能：  向前闪现10格并使对手眩晕3次，但使用技能时，自己至少离边界有5格距离"<<endl;
        cout<<"二技能：  随机使自己出现在场上任意位置并使自己拥有10层霸体"<<endl;
        cout<<"大招：    重置自己和对手的位置并使自己拥有10层霸体并使对手眩晕10次"<<endl;
        break;
        
        case 7:
        cout<<"特点：擅长迷魂术，感受被支配的感觉吧233"<<endl;
		cout<<"角色被动：如果对手处于迷魂状态再次触发迷魂将返还技能所需能量，迷魂失效"<<endl;
        cout<<"一技能：  使对手眩晕2次并有一定概率迷魂"<<endl;
        cout<<"二技能：  使对手眩晕5次并有较大概率迷魂"<<endl;
        cout<<"大招：    使对手眩晕10次并习得【迷魂术】可使用20次"<<endl;
        cout<<"附属技能：当自己拥有【迷魂术】时，消耗1格能量并使对手迷魂"<<endl;
        break;
        
        case 8:
		cout<<"特点：擅长推进，【狼族血脉】让他的能量条变为怒气值，满格为9"<<endl;
		cout<<"特殊消耗：一技能2点，二技能3点，大招9点"<<endl;
		cout<<"角色被动：一、二技能需要贴身释放"<<endl;
		cout<<"一技能：  使对手退后10格"<<endl;
		cout<<"二技能：  使对手退后15格，有极小概率释放【狼族血脉】，持续10回合"<<endl;
		cout<<"大招：    使对手退后25格并使对手眩晕5次，有较小概率释放【狼族血脉】持续50回合"<<endl;
		cout<<"附属技能：当自己拥有【狼族血脉】时，消耗6点怒气值使自己攻击永久加1"<<endl;
		break;
		
		case 9:
		cout<<"特点：擅长冰冻"<<endl;
		cout<<"一技能：使对手冻伤5回合"<<endl;
		cout<<"二技能：使对手冰冻5回合"<<endl;
		cout<<"大招：  使对手冰冻15回合"<<endl;
		break;
		
		case 10:
		cout<<"特点：    孙悟空接受了极高的力量，能量条满格为6"<<endl;
		cout<<"特殊消耗：一技能2点，二技能2点，三技能6点"<<endl;
		cout<<"一技能：  驾驶筋斗云向前闪现18格，使对手眩晕2次（飞出去了我不管）"<<endl;
		cout<<"二技能：  提高大招效果+2格距离"<<endl;
		cout<<"大招：    使用金箍棒横扫前方10格距离，使范围内对手退后15格并拥有【大圣显威】持           续50回合"<<endl;
		cout<<"附属技能：当自己拥有【大圣显威】时，消耗3点能量获得10层霸体"<<endl; 
		break;
	}
	cout<<endl;
}
void write_sj(int tmp1,int tmp2)
{
	for (int i=1;i<=SL.js;i++)
	{
		int pp=1;
		cout<<' ';
		if (tmp1==tmp2&&tmp1==i){cout<<"TS:";pp=0;}else
		if (tmp1==i){cout<<"P1:";pp=0;}else
		if (tmp2==i){cout<<"P2:";pp=0;}
		if (pp) cout<<"    ";
		else    cout<<' ';
		switch (i)
		{
			case 1:cout<<"骑士";break; 
			case 2:cout<<"法师";break; 
			case 3:cout<<"刺客";break;
			case 4:cout<<"膜法师";break;
			case 5:cout<<"药剂师"<<endl;break;
			case 6:cout<<"暗影";break;
			case 7:cout<<"巫师";break;
			case 8:cout<<"狼人";break;
			case 9:cout<<"冰法  ";break; 
			case 10:cout<<"孙悟空";break;
		}
	}
	cout<<endl;
}
void xzJS(int tmp1,int tmp2,int p1,int p2)
{
	cout<<"请选择角色："<<endl<<endl;
	cout<<"P1的选择介绍："<<endl;
	write_juese(tmp1);
	cout<<endl<<"P2的选择介绍："<<endl;
	write_juese(tmp2);
	write_sj(tmp1,tmp2);
	
	int tmp=getch();
	switch (tmp)
	{
		case 'w':
			if (tmp1>4&&p1)
			{
				tmp1-=5;
			}
			break;
		case 's':
			if (tmp1<=SL.js-5&&p1)
			{
				tmp1+=5;
			}
			break;
		case 'd':
			if (tmp1<SL.js&&p1)
			{ 
				tmp1++;
			}
			break;
		case 'a':
			if (tmp1>1&&p1)
			{
			    tmp1--;
			}
			break;
			
		case 'j':
			JS[0].n=tmp1;
			p1=0;
			break;
			
		case '1':
			JS[1].n=tmp2;
			p2=0;
			break;
	}
	if (tmp==0xE0)
	{
		int ch=getch();
		if (ch==72)
            if (tmp2>5&&p2)
			{
				tmp2-=5;
			}
        if (ch==80) 
			if (tmp2<=SL.js-5&&p2)
			{
				tmp2+=5;
			}
        if (ch==77)
            if (tmp2<SL.js&&p2)
			{
				tmp2++;
            }
        if (ch==75)
            if (tmp2>1&&p2)
            {
                tmp2--;
            }
    }
	switch (JS[0].n)
	{
		case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 9:
			JS[0].ajn=15;JS[0].nln=3;break;
		case 8:
			JS[0].ajn=7;JS[0].nln=9;break;
		case 10:
			JS[0].ajn=10;JS[0].nln=6;break;
	}	
	switch (JS[1].n)
	{
		case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 9:
			JS[1].ajn=15;JS[1].nln=3;break;
		case 8:
			JS[1].ajn=7;JS[1].nln=9;break;
		case 10:
			JS[1].ajn=10;JS[1].nln=6;break;
	}
	s();	
	if (p1||p2)
	{
		xzJS(tmp1,tmp2,p1,p2);
	}
}
void start()
{
    cout<<"说明书"<<endl<<endl;
    
    cout<<"基本操作：玩家1 ad     左右移动，j 一技能，k 二技能，h 附属技能，l 大招"<<endl;
    cout<<"          玩家2 方向键 左右移动，1 一技能，2 二技能，0 附属技能，3 大招"<<endl<<endl;
    
    cout<<"选择人物时：玩家1 WSAD 控制，玩家2 方向键 控制【剩下的自己领会】"<<endl;
    cout<<"            玩家1 按 j 确定，玩家2 按 1 确定"<<endl<<endl;
    
    cout<<"游戏内：技能需要人物下方的能量"<<endl;
    cout<<"        游戏中有效果道具，拾取即触发"<<endl<<endl;
    
    cout<<"一定要仔细看，过了就没了"<<endl<<endl;
    
    system("pause");
    s();
}
void play()
{
    xzJS(1,1,1,1);
	while (J[0]>0&&J[1]<81&&J[1]>0&&J[0]<81)
	{
		write_now();
		int getch1=getch();
		if (getch1!='!'&&getch1!='@'&&getch1!='#'&&getch1!='$'&&getch1!='%'&&getch1!='^'&&getch1!='&')
        {    
			pdFH(getch1,0);
		}
        if (J[0]==FH.wz)
        {
            pdFH(FH.z,0);
            int tmp=rand()%3;
			if (tmp<=3)
			{
			    xzFH(tmp);
			    xzWZ();
            }
        }
        if (J[1]==FH.wz)
        {
            pdFH(FH.z,1);
            int tmp=rand()%3;
			if (tmp<=3)
			{
			    xzFH(tmp);
			    xzWZ();
            }
        }
        jdFH();
        if (J[0]<J[1])
        {
	        JFX[0]=1;JFX[1]=-1;
        }
        else
        {  	
	        JFX[0]=-1;JFX[1]=1;
        }
        s(); 
	}
}
void getch2()
{
	char a=getch();
	if (a!='1'&&a!='2')
	{
		getch2();
	}
	if (a=='1')
	{
	    s();
	    chushihua();
	    play();
	    end();
	}
	if (a=='2')
	{
		return;
	}
}
void end()
{
	if (J[0]<1||J[0]>81)
	{
		cout<<"P2玩家获胜"<<endl;
	}
	else
	{
		cout<<"P1玩家获胜"<<endl;
	}
	cout<<"是否重玩？【1.是 2.退出】";
	getch2();
}
int main()
{
	srand(time(0));
	chushihua();
	/*ios::sync.with.stdio(false);*/
	start();
	play();
	end();
}
