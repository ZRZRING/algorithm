#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

/*

写在前面
（1）眩晕可以使人的一次非技能移动失效霸体可以使推进者一次非技能推进失效。
（2）攻击表示一次推进的格数。
（3）中毒可以使人每移动2格附带眩晕2次。
（4）剧毒可以使人每移动1格附带眩晕2次。
（5）迷魂持续10~30回合，到期自动消除。
（6）眩晕状态移动不消耗任何状态（除眩晕转霸体外）回合数，仅解除一次眩晕。
（7）冰冻状态下不能移动不能使用移动类技能，在解除冰冻后冻伤，冻伤每两次移动前进一格。 
（8）3格能量角色1格能量需要非技能移动15次。
（9）6格能量角色1格能量需要非技能移动10次。
（10）9格能量角色1格能量需要非技能移动7次 。
（11）闪现无视对手，移动若对手阻挡将会推进。
（12）封技能使自己释放不出技能，移动可解除次数 。 
（13）魅狐随机事件包括：眩晕5~10次，迷魂5~25回合，向前闪现-10~5格。 
（14）道具包括：给自己加3层眩晕，使对手退后10格，使对手眩晕2次退后5格并给自己加2层霸体，给对手加5层霸体， 
                使自己能量+1，使对手能量-1。 
*/
struct ZT1
{
	int nl,aj,ajn,gj,xy,bt; 
	int bt_xy,xy_bt;
	int zd,zdhh,jd,bd,ds,dax;       
	int mh,time,silence,FHnum;
}ZT[2];

struct SL1
{
	int jn,js,fh;
}SL;

struct BJ1
{
	int ay,ck,mhs,lz,ds;
}BJ[2];

struct FH1
{
	int wz,Lwz;
	char z;
}FH;

struct JS1
{
	int n,ajn,nln;
}JS[2];

const int H=4;
int J[2],LJ[2],JFX[2],hJ;  

/////////////////////////////
void start();
void play();
void end(); 
void pdnl(int); 
int pdds(int);
void pdbd(int);
void pdzd(int);
void pdjd(int);
void pdBJ(int,int);
void pdnl(int);
int pdds(int);
void pdbd(int);
void pdzd(int);
void pdjd(int);
void pdBJ(int,int);
int pdmh(int);
void write_now();
void pdFH(int,int);
void xzFH(int);
void write_now();
void pdFH(int,int);
void xzFH(int);
void xzWZ();
void jdFH(int,int);
void jdFH(int); 
void jdFH();
void chushihua();
void chuangjie(int);
void zhangzhe(int);
void cursor(int,int);
void spa(int);
void write_start();
void meihu(int);
////////////////////////////////

/////////////搞笑区//////////////
void cursor(int x,int y)
{
	COORD c;
	if (x<0)x=0;
	if (y<0)y=0; 
	c.X=x;c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
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
	printf(tmp ? "#" : "&");
}
void wz(int tmp)
{
	cout<<ZT[tmp].nl;
}
/////////////创界区///////////////
void chuangjie(int tmp)
{
	if (JS[!tmp].n==11)zhangzhe(tmp);
	if (JS[!tmp].n==12)meihu(tmp);
} 
void write_szhangzhe(int tmp)
{
	LJ[tmp]=J[tmp];
	for(int i=0;i<=H;i++)cout<<endl;
	for (int i=1;i<=80;i++)cout<<'-';
	for (int i=1;i<=80;i++)
	{
		int tmp1=0;
	    if (i==J[tmp]){w(!tmp);tmp1=1;}else
	    if (i==FH.wz){cout<<"?";tmp1=1;FH.Lwz=FH.wz;}
	    if (!tmp1)cout<<' ';
	}
	for (int i=1;i<=80;i++)
	{
		int tmp1=0;
	    if (i==J[tmp]){cout<<ZT[tmp].nl;tmp1=1;}
        if (!tmp1)cout<<' ';
	}
	for (int i=1;i<=80;i++)cout<<'-';cout<<endl;
	cout<<endl<<"你的剩余回合："<<ZT[tmp].time<<"    "<<"你捡到的道具数量："<<ZT[tmp].FHnum;
}
void zhangzhe(int tmp)
{
	s();jdFH(1);int tmpr;
	write_szhangzhe(tmp);
	ZT[tmp].time=200-ZT[!tmp].dax;
	while (J[tmp]>0&&J[tmp]<81&&ZT[tmp].time>0&&ZT[tmp].FHnum<3)
	{
		cursor(LJ[tmp]-1,H+2);cout<<' ';
		cursor(LJ[tmp]-1,H+3);cout<<' ';
		cursor(FH.Lwz-1,H+2);cout<<' ';
		cursor(14,H+7);cout<<"   ";
		cursor(39,H+7);cout<<"   "; 
		LJ[tmp]=J[tmp]; /////////////////
		FH.Lwz=FH.wz;   /////////////////
		cursor(J[tmp]-1,H+2);w(tmp);
		cursor(J[tmp]-1,H+3);cout<<ZT[0].nl;
		cursor(14,H+7);cout<<ZT[tmp].time;
		cursor(39,H+7);cout<<ZT[tmp].FHnum; 
		cursor(FH.wz-1,H+2);cout<<'?';
		int getch1=getch();
		if (tmp)
		{
			if (getch1==0xE0)
			getch1=getch();
			if (getch1==75){J[tmp]--;ZT[tmp].time--;}
			if (getch1==77){J[tmp]++;ZT[tmp].time--;}
		}
		else     
		{
			if (getch1=='d'){J[tmp]++;ZT[tmp].time--;}
			if (getch1=='a'){J[tmp]--;ZT[tmp].time--;}
		}
        if (J[tmp]==FH.wz)
        {
            ZT[tmp].FHnum++;jdFH(1);
        }
        tmpr=rand()%100;
		if (tmpr==1)jdFH(1);
	}
	if (ZT[tmp].FHnum<3)
	{
		s();J[tmp]=100;end();
	}
	ZT[!tmp].bt+=9;if (J[tmp]==J[!tmp])J[!tmp]++;
	ZT[tmp].time=0;ZT[tmp].FHnum=0; 
	s();write_start();
} 
void write_smeihu(int tmp)
{
	LJ[tmp]=J[tmp];J[tmp]=1;
	for(int i=0;i<=H;i++)cout<<endl;
	for (int i=1;i<=80;i++)cout<<'-';
	for (int i=1;i<=80;i++)
	{
		int tmp1=0;
	    if (i==J[tmp]){w(!tmp);tmp1=1;}else
	    if (i==80){cout<<")";tmp1=1;}
	    if (!tmp1)cout<<' ';
	}
	for (int i=1;i<=80;i++)
	{
		int tmp1=0;
	    if (i==J[tmp]){cout<<ZT[tmp].nl;tmp1=1;}
        if (!tmp1)cout<<' ';
	}
	for (int i=1;i<=80;i++)cout<<'-';cout<<endl;
	cout<<endl<<"你的剩余回合："<<ZT[tmp].time<<"    "<<endl;
}
void meihu_fh(int tmp,int tmpa)
{
	switch (tmpa)                                 //眩晕5~10次，迷魂25~50回合，向前闪现-10~5格。 
	{
		case 1:ZT[tmp].xy+=rand()%5+5;break;
		case 2:ZT[tmp].mh+=rand()%25+25;break;
		case 3:J[tmp]+=rand()%15-10; 
	}
}
void pxttt(int &a,int &b,int &c)
{
	int tmp;
	if (a>b)tmp=a,a=b,b=tmp;
	if (b>c)tmp=b,b=c,c=tmp;
	if (a>b)tmp=a,a=b,b=tmp;
}
void meihu(int tmp)
{
	s();int tmpa=J[tmp];
	clock_t start=clock();
	ZT[tmp].time=300-ZT[!tmp].dax;
	int p=0;
	int ta=rand()%79+1,tb=rand()%79+1,tc=rand()%79+1;
	pxttt(ta,tb,tc);
	int sa=rand()%2+1,sb=rand()%2+1,sc=rand()%2+1;
	int pa=0,pb=0,pc=0;
	write_smeihu(tmp);
	while (J[tmp]>0&&J[tmp]<80&&ZT[tmp].time>0)
	{
		int mhp=0;
		cursor(LJ[tmp]-1,H+2);cout<<' ';
		cursor(LJ[tmp]-1,H+3);cout<<' ';
		cursor(14,H+7);cout<<"   ";
		LJ[tmp]=J[tmp]; /////////////////
		FH.Lwz=FH.wz;   /////////////////
		cursor(J[tmp]-1,H+2);w(tmp);
		cursor(J[tmp]-1,H+3);cout<<ZT[0].nl;
		cursor(14,H+7);cout<<ZT[tmp].time;
		if (J[tmp]==ta&&!pa)cursor(0,H+8),cout<<"第一个随机事件开始",
		meihu_fh(tmp,sa),pa=1;
		if (J[tmp]==tb&&!pb)cursor(0,H+9),cout<<"第二个随机事件开始",
		meihu_fh(tmp,sb),pb=1;
		if (J[tmp]==tc&&!pc)cursor(0,H+10),cout<<"第三个随机事件开始",
		meihu_fh(tmp,sc),pc=1;
		while (ZT[tmp].xy>0)getch(),ZT[tmp].xy--;
		int getch1=getch();
		if (ZT[tmp].mh>0)ZT[tmp].mh--,mhp=1;
		if (tmp)
		{
			if (getch1==0xE0)
			getch1=getch();
			if (getch1==75){J[tmp]--;ZT[tmp].time--;}
			if (getch1==77){J[tmp]++;ZT[tmp].time--;}
		}
		else     
		{
			if (getch1=='d'){J[tmp]++;ZT[tmp].time--;}
			if (getch1=='a'){J[tmp]--;ZT[tmp].time--;}
		}
		if (mhp)
		{
			if (tmp)
			{
				if (getch1==0xE0)
				getch1=getch();
				if (getch1==75){J[tmp]+=2;ZT[tmp].time--;}
				if (getch1==77){J[tmp]-=2;ZT[tmp].time--;}
			}
			else     
			{
				if (getch1=='d'){J[tmp]-=2;ZT[tmp].time--;}
				if (getch1=='a'){J[tmp]+=2;ZT[tmp].time--;}
			}
		} 
        if (J[tmp]==80)
        {
            p=1;break;
        }
	}
	clock_t end1=clock();
	J[0]=20;J[1]=60;
	if (!p)
	{
		s();J[tmp]=100;end();
	}
	if (((double)(end1-start)/CLOCKS_PER_SEC)>15)
	{
		s();cout<<"超时！您所用的时间为："<<(double)(end1-start)/CLOCKS_PER_SEC<<"秒"<<endl;J[tmp]=100;end();
	}
	s();write_start();ZT[tmp].mh=0; 
}
/////////////核心区///////////////
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
		case 0:
            ZT[tmp].xy+=3;   
			break;
		
		case 1:
            J[!tmp]-=10*JFX[!tmp];
			break;
		
		case 2:
            ZT[!tmp].xy+=2;
			ZT[tmp].bt+=2;
            J[!tmp]-=5*JFX[!tmp];
			break;
		
		case 3:
            J[tmp]+=JFX[tmp];
            if (J[0]==J[1])
            {
            	J[!tmp]-=JFX[!tmp];
            }
			break;
			
		case 4:
            ZT[!tmp].bt+=5;  
			break; 
			
		case 5:
			if (ZT[tmp].nl<3)
			{
			    ZT[tmp].nl++;
            }
			break;
			
		case 7:
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
				if (ZT[tmp].silence)ZT[tmp].silence--; 
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
				if (ZT[tmp].silence)ZT[tmp].silence--; 
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
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])==1&&!ZT[tmp].silence)
					{
				    	if (ZT[!tmp].bt==0)
				    	{
				        	J[!tmp]-=5*JFX[!tmp];
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
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
				        J[!tmp]-=5*JFX[!tmp];
				        ZT[!tmp].xy+=2;
						ZT[tmp].nl--;
				    }
			    	break;
				
				case 3:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&J[tmp]>7&&J[tmp]<73&&!ZT[tmp].silence&&!ZT[tmp].bd)
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
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
					    ZT[tmp].bt+=3;
						ZT[!tmp].xy+=3;
						ZT[tmp].nl--;
				    }
					break;
					
				case 5:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&ZT[!tmp].bt==0&&!ZT[tmp].silence)
					{
					    ZT[!tmp].zd+=5;
						ZT[tmp].nl--;
				    }
					break;
					
				
				case 6:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&!ZT[tmp].silence&&!ZT[tmp].bd)
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
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&!ZT[tmp].silence)
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
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])<=1&&!ZT[tmp].silence)
					{
						J[!tmp]-=10*JFX[!tmp];
						ZT[tmp].nl-=2;
					}
					break;
				
				case 9:
					if (ZT[tmp].nl>=1&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						ZT[!tmp].ds+=5*2;
						ZT[tmp].nl--;
					}
					break;
					
				case 10:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&!ZT[tmp].silence&&!ZT[tmp].bd)
					{
						J[tmp]+=18*JFX[tmp]; 
						ZT[tmp].nl-=3;
						if (J[tmp]==J[!tmp])J[tmp]++;
					}
					break;	
				
				case 11:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						jdFH(1,tmp);
						ZT[tmp].bt+=3;
						ZT[tmp].nl-=2;
					}
					break;
					
				case 12:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						jdFH(2,tmp);
						ZT[!tmp].xy+=2;
						ZT[tmp].nl-=2;
					}
					break;
			} 
			break;
		case 'k': case'2':                                 //二技能 
			switch (JS[tmp].n)
			{ 
			    case 1:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])==1&&!ZT[tmp].silence)
					{
				    	if (ZT[!tmp].bt==0)
				    	{
				        	J[!tmp]-=10*JFX[!tmp];
				        	ZT[tmp].bt+=5;
				    	}
				    	else
				    	{
					    	ZT[!tmp].bt-=10;
					    	if (ZT[!tmp].bt<0)
					    	{
					    		ZT[!tmp].bt=0;
					        	ZT[!tmp].xy+=10;
					    	}
						}
						ZT[tmp].nl-=2;
				    }
			    	break;
				
				case 2:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
				        ZT[!tmp].xy+=10;
						ZT[tmp].nl-=2;
				    }
				    break;
				    
				case 3:
				    if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
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
			    	if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
				        ZT[!tmp].xy+=5;
				        ZT[tmp].xy_bt+=5;
				        ZT[tmp].nl-=2;
				    }
				    break;
				    
				case 5:
			    	if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
				        ZT[!tmp].zd+=12;
				        ZT[tmp].nl-=2;
				    }
				    break;
				    
				case 6:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence&&!ZT[tmp].bd)
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
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
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
					if (ZT[tmp].nl>=4&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])<=1&&!ZT[tmp].silence)
					{
						J[!tmp]-=15*JFX[!tmp];
						int tmp2=rand()%100;
						if (tmp2<=5)
						{
							BJ[tmp].lz+=10;
						}
						ZT[tmp].nl-=4;
					}
					break;
					
				case 9:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						ZT[!tmp].bd+=5;
						ZT[tmp].nl-=2;
					}
					break;
					
				case 10:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						ZT[tmp].dax+=2;
						ZT[tmp].nl-=2;
					}
					break;
					
				case 11:
					if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						int tmp2=rand()%7+3;
						ZT[tmp].dax+=tmp2;
						ZT[tmp].nl-=2;
					}
					break;
					
		    	case 12:
		    		if (ZT[tmp].nl>=2&&ZT[tmp].xy==0&&!ZT[tmp].silence)
		    		{
		    			int tmp2=rand()%3+2;
						ZT[tmp].dax+=tmp2;
						ZT[tmp].nl-=2;
		    		}
			} 
			break;
		case 'l': case '3':	                               //三技能 
			switch (JS[tmp].n)
			{ 
			    case 1:
			    	if (ZT[tmp].nl>=3)
			    	{
			    		ZT[tmp].xy=0;
			    		ZT[tmp].silence=0; 
			    		ZT[tmp].bd=0;
			    		ZT[tmp].zd=0;
			    		ZT[tmp].jd=0;
			    		ZT[tmp].ds=0;
			    		ZT[tmp].mh=0;
						ZT[tmp].bt+=30;
						ZT[tmp].nl-=3;
					}
			    	break;
				
				case 2:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
				        ZT[!tmp].xy+=20;
				        ZT[!tmp].nl=0;
						ZT[tmp].nl-=3;
				    }
				    break;
				case 3:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						BJ[tmp].ck+=50;
						ZT[!tmp].xy+=10;
						J[tmp]-=5*JFX[tmp];
						ZT[tmp].nl-=3;
				    }	
					break;
					
				case 4:
				    if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
				        ZT[tmp].bt+=10;
				        ZT[tmp].bt_xy+=10;
				        ZT[tmp].nl-=3;
				    }
				    break;
					
				case 5:
				    if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
				        ZT[!tmp].jd+=10;
				        ZT[!tmp].silence+=5;
				        ZT[tmp].nl-=3;
				    }
				    break;
				
				case 6:
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&!ZT[tmp].silence)
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
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						ZT[!tmp].xy+=10;
						BJ[tmp].mhs+=20;
						ZT[tmp].nl-=3;
					}
					break;
					
				case 8:
					if (ZT[tmp].nl>=9&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						for (int i=1;i<=5;i++)
						{
							J[!tmp]-=5*JFX[!tmp];
							write_now();
						}
						ZT[!tmp].xy+=5;
						int tmp2=rand()%100;
						if (tmp2<=20)
						{
							BJ[tmp].lz+=50;
						}
						ZT[tmp].nl-=9;
					}
					break;
					
				case 9: 
					if (ZT[tmp].nl>=3&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						ZT[!tmp].bd+=15;
						ZT[tmp].nl-=3;
					}
					break;
					
				case 10:
					if (ZT[tmp].nl>=6&&ZT[tmp].xy==0&&abs(J[tmp]-J[!tmp])<=10&&!ZT[tmp].silence)
					{
						for (int i=1;i<=(ZT[tmp].dax+5)/10;i++)
						{
							s();J[!tmp]-=10*JFX[!tmp];
							write_now();
						}
						J[!tmp]-=ZT[tmp].dax%10;
						s();write_now();
						BJ[tmp].ds+=50; 
						ZT[tmp].nl-=6;
					}
					break;
					
				case 11:
					if (ZT[tmp].nl>=6&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						ZT[tmp].nl-=6;
						ZT[!tmp].time+=200-ZT[tmp].dax;
						chuangjie(!tmp);
					}
					break;
				
				case 12:
					if (ZT[tmp].nl>=6&&ZT[tmp].xy==0&&!ZT[tmp].silence)
					{
						ZT[tmp].nl-=6;
						ZT[!tmp].time+=300-ZT[tmp].dax;
						chuangjie(!tmp);
					}
					break;
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
		BJ[tmp].ck--;
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

///////////////输出区//////////////// 
void write_start()
{
	hJ=0;
	LJ[0]=J[0];
	LJ[1]=J[1];
	for(int i=0;i<=H;i++)cout<<endl;
	for (int i=1;i<=80;i++)cout<<'-';
	for (int i=1;i<=80;i++)
	{
		int tmp=0;
	    if (i==J[0]){w(0);tmp=1;}
		if (i==J[1]){w(1);tmp=1;} 
	    if (i==FH.wz){cout<<"?";tmp=1;FH.Lwz=FH.wz;}
	    if (!tmp)cout<<" ";
	}
	for (int i=1;i<=80;i++)
	{
		int tmp=0;
	    if (i==J[0]){cout<<ZT[0].nl;tmp=1;}
		if (i==J[1]){cout<<ZT[1].nl;tmp=1;} 
        if (!tmp)cout<<' ';
    }
	for (int i=1;i<=80;i++)cout<<'-';
	cout<<endl;//
    cout<<"玩家1眩晕："<<ZT[0].xy<<"    ";   cout<<"玩家1霸体："<<ZT[0].bt<<"       ";
	if (JS[0].n==10||JS[0].n==11||JS[0].n==12)cout<<"玩家1大招效果："<<ZT[0].dax<<endl;else cout<<endl;
	if (JS[1].n==5)cout<<"玩家1中毒："<<ZT[0].zd<<"    ",cout<<"玩家1剧毒："<<ZT[0].jd<<"    ",hJ++;
	if (JS[1].n==5)cout<<"玩家2封技："<<ZT[1].silence<<endl; 
	if (JS[1].n==9)cout<<"玩家1冻伤："<<ZT[0].ds<<"    ",cout<<"玩家1冰冻："<<ZT[0].bd<<"    "<<endl,hJ++;
	printf("\n\n\n");//
    cout<<"玩家2眩晕："<<ZT[1].xy<<"    ";   cout<<"玩家2霸体："<<ZT[1].bt<<"       "; 
	if (JS[1].n==10||JS[1].n==11||JS[1].n==12)cout<<"玩家2大招效果："<<ZT[1].dax<<endl;else cout<<endl;
	if (JS[0].n==5)cout<<"玩家2中毒："<<ZT[1].zd<<"    ",cout<<"玩家2剧毒："<<ZT[1].jd<<"    ";
	if (JS[0].n==5)cout<<"玩家2封技："<<ZT[1].silence<<endl; 
	if (JS[0].n==9)cout<<"玩家2冻伤："<<ZT[1].ds<<"    ",cout<<"玩家2冰冻："<<ZT[1].bd<<"    "<<endl;
}
void write_now()
{
	cursor(LJ[1]-1,H+2); cout<<' ';
	cursor(LJ[0]-1,H+2); cout<<' ';
	cursor(FH.Lwz-1,H+2);cout<<' ';
	cursor(LJ[1]-1,H+3); cout<<' ';
	cursor(LJ[0]-1,H+3); cout<<' ';
	cursor(11,H+6);      cout<<"    ";
	cursor(27,H+6);      cout<<"    ";
	cursor(11,H+10+hJ);  cout<<"    ";  
	cursor(27,H+10+hJ);  cout<<"    ";
	
	if (JS[1].n==5)cursor(11,H+7);cout<<"    ",cursor(27,H+7);cout<<"    ";
	if (JS[1].n==5)cursor(43,H+7);cout<<"    ";
	if (JS[1].n==9)cursor(11,H+7);cout<<"    ",cursor(27,H+7);cout<<"    ";
	
	cursor(FH.wz-1,H+2); cout<<"?";FH.Lwz=FH.wz;
	cursor(J[1]-1,H+2);  w(0);LJ[0]=J[0];
	cursor(J[0]-1,H+2);  w(1);LJ[1]=J[1];
	cursor(J[1]-1,H+3);  cout<<ZT[1].nl;
	cursor(J[0]-1,H+3);  cout<<ZT[0].nl;

	cursor(11,H+6);      cout<<ZT[0].xy;
	cursor(27,H+6);      cout<<ZT[0].bt;
	if (JS[0].n==10||JS[0].n==11||JS[0].n==12){cursor(50,H+6);cout<<ZT[0].dax;}
	if (JS[1].n==5)cursor(11,H+7),cout<<ZT[0].zd,cursor(27,H+7),cout<<ZT[0].jd;
	if (JS[1].n==5)cursor(43,H+7),cout<<ZT[0].silence;
	if (JS[1].n==9)cursor(11,H+7),cout<<ZT[0].ds,cursor(27,H+7),cout<<ZT[0].bd;
	
	cout<<endl;cout<<endl;cout<<endl;//
	
	if (BJ[0].ay>0||BJ[0].ck>0||BJ[0].mhs>0||BJ[0].lz>0||BJ[0].ds>0)
	{
		cursor(J[0]-1,H+2);  cout<<'X';
	}
	else cursor(J[0]-1,H+2),  w(0);
	
	cursor(11,H+10+hJ);     cout<<ZT[1].xy;  
	cursor(27,H+10+hJ);     cout<<ZT[1].bt;
	if (JS[1].n==10||JS[1].n==11||JS[1].n==12){cursor(50,H+10);cout<<ZT[1].dax;}
	if (JS[0].n==5)cursor(11,H+10+hJ),cout<<ZT[1].zd,cursor(27,H+10+hJ),cout<<ZT[1].jd;
	if (JS[0].n==5)cursor(43,H+11+hJ),cout<<ZT[1].silence;
	if (JS[0].n==9)cursor(11,H+10+hJ),cout<<ZT[1].ds,cursor(27,H+10+hJ),cout<<ZT[1].bd;
	
	cout<<endl;cout<<endl;cout<<endl;//
	
	if (BJ[1].ay>0||BJ[1].ck>0||BJ[1].mhs>0||BJ[1].lz>0||BJ[1].ds>0)
	{
		cursor(J[1]-1,H+2);  cout<<'X';
	} 
	else cursor(J[1]-1,H+2),  w(1);
}

////////////////符号区//////////////////
void xzWZ()
{
	FH.wz=rand()%79+1;
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
void jdFH(int p,int tmp)
{
	int tmp1; 
    if (p==1) FH.z=4;
    if (p==2) FH.z=0;
	FH.wz=J[!tmp]-JFX[!tmp];
}
void jdFH(int p)
{
	if (p==1) FH.z=4;
	xzWZ();
}
void jdFH()
{
	int tmp=rand()%500;
	if (tmp<=SL.fh)
	{
		FH.z=tmp;
		xzWZ();
	}
}
//////////////角色区////////////////// 
void write_juese(int tmp)
{
	switch (tmp)
	{
		case 1:
		cout<<"【基础】正义的力量不可阻挡"<<endl;
		cout<<"角色被动；一、二技能需要贴身释放"<<endl; 
		cout<<"一技能：  使对手退后5格并获得2层霸体，若对方有霸体，则破对方霸体5层并眩晕5次"<<endl;
		cout<<"二技能：  使对手退后10格并获得5层霸体，若对方有霸体，则破对方霸体10层并眩晕10次"<<endl;
		cout<<"大招：    消除自身所有负面效果并获得30层霸体"<<endl;
		break;
		
		case 2: 
		cout<<"【基础】我的法术你瞧好了"<<endl;
		cout<<"角色被动：技能全部无视霸体"<<endl; 
		cout<<"一技能：  使对手眩晕2次并退后5格"<<endl;
		cout<<"二技能：  使对手眩晕10次"<<endl;
		cout<<"大招：    使对手眩晕20次并能量清0"<<endl;
		break;
		
		case 3:
	    cout<<"【稀有】来无影去无踪，小心吧你一会就输了"<<endl;
		cout<<"标记： 【刺客信条】可以使自己有一定概率使自己移动变成退后一格并使对手眩晕3次"<<endl;
		cout<<"一技能：瞬移到道具附近，并使对手退后3格，但使用技能时，自己至少离边界有7格距离"<<endl;
		cout<<"二技能：瞬移至对手面前并使对手眩晕5次，若已在对手面前并离边界超过15格距离，则跳"<<endl;         
		cout<<"        到对手后面并眩晕5次"<<endl;
		cout<<"大招：  使自己退后5格并拥有【刺客信条】持续50回合并使对手眩晕10次"<<endl;
		break;
		
		case 4:
		cout<<"【史诗】魔法能让万物转化，其本质就是科学的力量"<<endl;
		cout<<"一技能：让对手眩晕3次并给自己加3层霸体"<<endl;
		cout<<"二技能：让对手眩晕5次【专属被动：对手每破眩晕1次，给自身加1层霸体】"<<endl;
		cout<<"大招：  获得10层霸体【专属被动：每破1层霸体，就会让对手眩晕1次】"<<endl;
        break;
        
        case 5:
        cout<<"【稀有】毒不死你，但会让你生不如死"<<endl;
        cout<<"一技能：使对手中毒5次"<<endl;
        cout<<"二技能：使对手中毒12次"<<endl;
        cout<<"大招：  使对手中剧毒10次并封技5次"<<endl;
        break;
        
        case 6:
        cout<<"【史诗】你想赢，来，我们赌一把"<<endl;
		cout<<"标记：   【暗影标记】可以使自己移动时候较小概率移动2格并附带推进效果"<<endl;
        cout<<"角色被动：释放技能有较大概率给自己施加【暗影标记】，持续50回合"<<endl;
        cout<<"一技能：  向前闪现10格并使对手眩晕3次，但使用技能时，自己至少离边界有5格距离"<<endl;
        cout<<"二技能：  随机使自己出现在场上任意位置并使自己拥有10层霸体"<<endl;
        cout<<"大招：    重置自己和对手的位置并使自己拥有10层霸体并使对手眩晕10次"<<endl;
        break;
        
        case 7:
        cout<<"【稀有】感受支配的力量，你将无去可从"<<endl;
		cout<<"角色被动：如果对手处于迷魂状态再次触发迷魂将返还技能所需能量，迷魂失效"<<endl;
        cout<<"一技能：  使对手眩晕2次并有一定概率迷魂"<<endl;
        cout<<"二技能：  使对手眩晕5次并有较大概率迷魂"<<endl;
        cout<<"大招：    使对手眩晕10次并习得【迷魂术】可使用20次"<<endl;
        cout<<"附属技能：当自己拥有【迷魂术】时，使对手迷魂"<<endl;
        break;
        
        case 8:
		cout<<"【史诗】狼族的力量，这是狼族的力量"<<endl;
		cout<<"特殊消耗：一技能2点，二技能4点，大招9点，满格为9"<<endl;
		cout<<"角色被动：一、二技能需要贴身释放"<<endl;
		cout<<"一技能：  使对手退后10格"<<endl;
		cout<<"二技能：  使对手退后15格，有极小概率释放【狼族血脉】，持续10回合"<<endl;
		cout<<"大招：    使对手退后25格并使对手眩晕5次，有较小概率释放【狼族血脉】持续50回合"<<endl;
		cout<<"附属技能：当自己拥有【狼族血脉】时，消耗6点怒气值使自己攻击永久加1"<<endl;
		break;
		
		case 9:
		cout<<"【稀有】蹦蹦跳跳得多快活，来尝尝寒冰的滋味"<<endl;
		cout<<"一技能：使对手冻伤5回合"<<endl;
		cout<<"二技能：使对手冰冻5回合"<<endl;
		cout<<"大招：  使对手冰冻15回合"<<endl;
		break;
		
		case 10:
		cout<<"【史诗】俺老孙修行数百年，只为天地间这一棒"<<endl;
		cout<<"特殊消耗：一技能3点，二技能2点，大招6点，满格为6"<<endl;
		cout<<"一技能：  驾驶筋斗云向前闪现18格，使对手眩晕2次（飞出去了我不管）"<<endl;
		cout<<"二技能：  修行，提高大招效果+2格距离"<<endl;
		cout<<"大招：    使用金箍棒横扫前方10格距离，使范围内对手退后5格并拥有【大圣显威】持"<<endl;            
		cout<<"          续50回合"<<endl;
		cout<<"附属技能：当自己拥有【大圣显威】时，消耗3点能量获得10层霸体"<<endl; 
		break;
		
		case 11:
		cout<<"【传说】我是长者，长者是谁，来，我慢慢告诉你"<<endl;
		cout<<"创界：    将对手放入创界，持续200回合，不能攒能量并封技，道具永久为'%'"<<endl;
		cout<<"特殊消耗：一技能2点，二技能2点，大招6点，满格为6"<<endl;
		cout<<"一技能：  刷新场上道具为'给对手加3层霸体'，置于对手后方，加3层霸体"<<endl;
		cout<<"二技能：  减少创界持续3~10回合"<<endl;
		cout<<"大招：    开启创界，若对手没有在创界捡到3个道具，将其消灭"<<endl;
		break;
		
		case 12:
		cout<<"【传说】小心掉入我的梦境，你会出不来的"<<endl;
		cout<<"梦境：    将对手放入梦境起点，持续300回合/15秒，不能攒能量并封技，生成随机事件"<<endl;
		cout<<"          3件"<<endl;
		cout<<"特殊消耗：一技能2点，二技能2点，大招6点，满格为6"<<endl;
		cout<<"一技能：  刷新场上道具为'使自己眩晕3次'，置于对手后方，使对手眩晕2次"<<endl;
		cout<<"二技能：  减少梦境持续2~5回合"<<endl;
		cout<<"大招：    开启梦境，若对手没有在梦境到达终点，将其消灭，在回到原战场时回到起始"<<endl;
		cout<<"          位置"<<endl;
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
			case 9:cout<<"冰法师";break; 
			case 10:cout<<"孙悟空"<<endl;break;
			case 11:cout<<"长者";break; 
			case 12:cout<<"魅狐";break;
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
		case 10:case 11:case 12:
			JS[0].ajn=10;JS[0].nln=6;break;
	}	
	switch (JS[1].n)
	{
		case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 9:
			JS[1].ajn=15;JS[1].nln=3;break;
		case 8:
			JS[1].ajn=7;JS[1].nln=9;break;
		case 10:case 11:case 12:
			JS[1].ajn=10;JS[1].nln=6;break;
	}
	s();	
	if (p1||p2)
	{
		xzJS(tmp1,tmp2,p1,p2);
	}
}

//////////////初始区/////////////// 
void chushihua()
{
	ZT[0].nl=0,ZT[0].aj=0,ZT[0].gj=1,ZT[0].xy=0,ZT[0].bt=0;ZT[0].bd=0;ZT[0].ds=0;
	ZT[0].xy_bt=0,ZT[0].bt_xy=0;
	ZT[0].zd=0,ZT[0].zdhh=0,ZT[0].jd=0;ZT[0].dax=0;ZT[0].time=0;ZT[0].FHnum=0;
	BJ[0].ay=0;BJ[0].ck=0;BJ[0].mhs=0;BJ[0].lz=0;
	
    ZT[1].nl=0,ZT[1].aj=0,ZT[1].gj=1,ZT[1].xy=0,ZT[1].bt=0;ZT[1].bd=0;ZT[1].ds=0;
	ZT[1].xy_bt=0,ZT[1].bt_xy=0;
	ZT[1].zd=0,ZT[1].zdhh=0,ZT[1].jd=0;ZT[1].dax=0;ZT[1].time=0;ZT[1].FHnum=0;
	BJ[1].ay=0;BJ[1].ck=0;BJ[1].mhs=0;BJ[1].lz=0;
	
	J[0]=20;LJ[0]=20;J[1]=60;LJ[1]=60;
	SL.fh=6; SL.js=12;
    int tmp=rand()%SL.fh+1;
	if (tmp<=SL.fh)
	{
		FH.z=rand()%SL.fh; 
		xzWZ();
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
    xzJS(1,1,1,1);write_start();
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
            int tmp=rand()%SL.fh;
            FH.z=SL.fh;
			xzWZ();
        }
        if (J[1]==FH.wz)
        {
            pdFH(FH.z,1);
            int tmp=rand()%SL.fh;
            FH.z=tmp;
			xzWZ();
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
	}
	s();
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
	if (J[0]==100||J[1]==100)
	{
		cout<<"您在创界中出界或超出回合限制！"<<endl;
	}
	if ((J[0]<1||J[0]>80))
	{
		cout<<"P2玩家获胜"<<endl;
	}
	if ((J[1]<1||J[1]>80))
	{
		cout<<"P1玩家获胜"<<endl;
	}
	cout<<"是否重玩？【   1：重玩    2：退出   】";
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
