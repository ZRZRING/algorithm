#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

/*
д��ǰ�棨exe�������ţ������Է�ר����
��1��ѣ�ο���ʹ�˵�һ�ηǼ����ƶ�ʧЧ�������ʹ�ƽ���һ�ηǼ����ƽ�ʧЧ��
��2��������ʾһ���ƽ��ĸ�����
��3���ж�����ʹ��ÿ�ƶ�2�񸽴�ѣ��2�Ρ�
��4���綾����ʹ��ÿ�ƶ�1�񸽴�ѣ��2�Ρ�
��5���Ի����10~30�غϣ������Զ�������
��6��ѣ��״̬�ƶ��������Ի�غ�����
��7������״̬�²����ƶ����ڽ��������ÿ�����ƶ�ǰ��һ���෴�����Լ����԰ɣ�
��8��3��������ɫ1��������Ҫ�Ǽ����ƶ�15�Ρ�
��9��6��������ɫ1��������Ҫ�Ǽ����ƶ�10�Ρ�
��10��9��������ɫ1��������Ҫ�Ǽ����ƶ�7�� ��
��11���������Ӷ��֣��ƶ��������赲�����ƽ���
��12���������������ŵ��������Լ��鿴����һһ׸���ˡ�

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
    cout<<"���1ѣ�Σ�"<<ZT[0].xy<<' ';   cout<<"���1���壺"<<ZT[0].bt<<endl;
    cout<<"���1�ж���"<<ZT[0].zd<<' ';   cout<<"���1�綾��"<<ZT[0].jd<<endl;	
    cout<<"���1������"<<ZT[0].gj<<' ';   cout<<"���1������"<<ZT[0].bd<<endl;
	cout<<"���1���ˣ�"<<ZT[0].ds/2<<' '; 
	cout<<endl;
	if (BJ[0].ay>0)  cout<<"���1ӵ�а�Ӱ���!"<<endl; 
	if (BJ[0].ck>0)  cout<<"���1ӵ�д̿�����!"<<endl; 
	if (BJ[0].mhs>0) cout<<"���1ϰ���Ի���!"<<endl; 
	if (BJ[0].lz>0) cout<<"���1�ͷ�����Ѫ��!"<<endl;
	if (BJ[0].ds>0) cout<<"���1�ͷŴ�ʥ����!"<<endl;  
	cout<<endl;
	
    cout<<"���2ѣ�Σ�"<<ZT[1].xy<<' ';   cout<<"���2���壺"<<ZT[1].bt<<endl;
	cout<<"���2�ж���"<<ZT[1].zd<<' ';   cout<<"���2�綾��"<<ZT[1].jd<<endl;
	cout<<"���2������"<<ZT[1].gj<<' ';   cout<<"���2������"<<ZT[1].bd<<endl;
	cout<<"���2���ˣ�"<<ZT[1].ds/2<<' '; 
	cout<<endl;
	if (BJ[1].ay>0)  cout<<"���2ӵ�а�Ӱ���!"<<endl;
	if (BJ[1].ck>0)  cout<<"���2ӵ�д̿�����!"<<endl; 
	if (BJ[1].mhs>0) cout<<"���2ϰ���Ի���!"<<endl; 
	if (BJ[1].lz>0) cout<<"���2�ͷ�����Ѫ��!"<<endl; 
	if (BJ[1].ds>0) cout<<"���2�ͷŴ�ʥ����!"<<endl; 
	cout<<endl;
	
	cout<<"! ʹ����ѣ��5��"<<endl; 
	cout<<"@ ʹ�����˺�10��"<<endl; 
	cout<<"% ���Լ���5�����"<<endl; 
	cout<<"$ ���Լ���ǰ����10��"<<endl;
	cout<<"# ʹ�����˺�5��ѣ��2�Σ����Լ���2�����"<<endl; 
	cout<<"^ ���Լ���һ������"<<endl;
	cout<<"& �����ּ�һ������"<<endl;
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
			
		case 'j': case '1':                                //������ //һ���� 
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
		case 'k': case'2':                                 //������ 
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
		case 'l': case '3':	                               //������ 
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
			
		case 'h': case'0':                                     //�������� 
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
		cout<<"�ص㣺    �ó����塢�ƽ�"<<endl;
		cout<<"��ɫ������һ����������Ҫ�����ͷ�"<<endl; 
		cout<<"һ���ܣ�  ʹ�����˺�7�񲢻��2����壬���Է��а��壬���ƶԷ�����5�㲢ѣ��5��"<<endl;
		cout<<"�����ܣ�  ʹ�����˺�12�񲢻��5����壬���Է��а��壬���ƶԷ�����10�㲢ѣ��5��"<<endl;
		cout<<"���У�    �����������и���Ч�������30�����"<<endl;
		break;
		
		case 2: 
		cout<<"�ص㣺�ó�ѣ��"<<endl;
		cout<<"��ɫ����������ȫ�����Ӱ���"<<endl; 
		cout<<"һ���ܣ�  ʹ�����˺�5��ѣ��2��"<<endl;
		cout<<"�����ܣ�  ʹ����ѣ��10��"<<endl;
		cout<<"���У�    ʹ����������0��ѣ��20��"<<endl;
		break;
		
		case 3:
	    cout<<"�ص㣺�ó�˲��"<<endl;
		cout<<"���̿�����������ʹ�Լ���һ������ʹ�Լ��ƶ�����˺�һ��ʹ����ѣ��3��"<<endl;
		cout<<"һ���ܣ�˲�Ƶ����߸�������ʹ�����˺�3�񣬵�ʹ�ü���ʱ���Լ�������߽���7�����"<<endl;
		cout<<"�����ܣ�˲����������ǰ��ʹ����ѣ��5�Σ������ڶ�����ǰ����߽糬��15����룬����         �����ֺ��沢ѣ��5��"<<endl;
		cout<<"���У�  ʹ�Լ��˺�5��ӵ�С��̿�����������50�غϲ�ʹ����ѣ��15��"<<endl;
		break;
		
		case 4:
		cout<<"�ص㣺�ó�Ĥ�򣬼��ܸ�������Ч��"<<endl;
		cout<<"һ���ܣ�  �ö���ѣ��3�β����Լ���3�����"<<endl;
		cout<<"�����ܣ�  �ö���ѣ��5�Ρ�ר������������ÿ��ѣ��1�Σ��������1����塿"<<endl;
		cout<<"���У�    ���10����塾ר��������ÿ��1����壬�ͻ��ö���ѣ��1�Ρ�"<<endl;
        break;
        
        case 5:
        cout<<"�ص㣺�ó��ö����ж�����ʹ���ƶ�ʱ����ѣ��"<<endl;
        cout<<"һ���ܣ�ʹ�����ж�3��"<<endl;
        cout<<"�����ܣ�ʹ�����ж�5�Ρ�ר���������˼������Ӱ��塿"<<endl;
        cout<<"���У�  ʹ�����о綾8�β��۳�1������"<<endl;
        break;
        
        case 6:
        cout<<"�ص㣺�ó��ƶ���ӵ������ս��������"<<endl;
		cout<<"����Ӱ��ǡ�����ʹ�Լ��ƶ�ʱ���С�����ƶ�2��ע�⣺�������֡�"<<endl;
        cout<<"��ɫ�������ͷż�����һ�����ʸ��Լ�ʩ�ӡ���Ӱ��ǡ�������50�غ�"<<endl;
        cout<<"һ���ܣ�  ��ǰ����10��ʹ����ѣ��3�Σ���ʹ�ü���ʱ���Լ�������߽���5�����"<<endl;
        cout<<"�����ܣ�  ���ʹ�Լ������ڳ�������λ�ò�ʹ�Լ�ӵ��10�����"<<endl;
        cout<<"���У�    �����Լ��Ͷ��ֵ�λ�ò�ʹ�Լ�ӵ��10����岢ʹ����ѣ��10��"<<endl;
        break;
        
        case 7:
        cout<<"�ص㣺�ó��Ի��������ܱ�֧��ĸо���233"<<endl;
		cout<<"��ɫ������������ִ����Ի�״̬�ٴδ����Ի꽫�������������������Ի�ʧЧ"<<endl;
        cout<<"һ���ܣ�  ʹ����ѣ��2�β���һ�������Ի�"<<endl;
        cout<<"�����ܣ�  ʹ����ѣ��5�β��нϴ�����Ի�"<<endl;
        cout<<"���У�    ʹ����ѣ��10�β�ϰ�á��Ի�������ʹ��20��"<<endl;
        cout<<"�������ܣ����Լ�ӵ�С��Ի�����ʱ������1��������ʹ�����Ի�"<<endl;
        break;
        
        case 8:
		cout<<"�ص㣺�ó��ƽ���������Ѫ������������������Ϊŭ��ֵ������Ϊ9"<<endl;
		cout<<"�������ģ�һ����2�㣬������3�㣬����9��"<<endl;
		cout<<"��ɫ������һ����������Ҫ�����ͷ�"<<endl;
		cout<<"һ���ܣ�  ʹ�����˺�10��"<<endl;
		cout<<"�����ܣ�  ʹ�����˺�15���м�С�����ͷš�����Ѫ����������10�غ�"<<endl;
		cout<<"���У�    ʹ�����˺�25��ʹ����ѣ��5�Σ��н�С�����ͷš�����Ѫ��������50�غ�"<<endl;
		cout<<"�������ܣ����Լ�ӵ�С�����Ѫ����ʱ������6��ŭ��ֵʹ�Լ��������ü�1"<<endl;
		break;
		
		case 9:
		cout<<"�ص㣺�ó�����"<<endl;
		cout<<"һ���ܣ�ʹ���ֶ���5�غ�"<<endl;
		cout<<"�����ܣ�ʹ���ֱ���5�غ�"<<endl;
		cout<<"���У�  ʹ���ֱ���15�غ�"<<endl;
		break;
		
		case 10:
		cout<<"�ص㣺    ����ս����˼��ߵ�����������������Ϊ6"<<endl;
		cout<<"�������ģ�һ����2�㣬������2�㣬������6��"<<endl;
		cout<<"һ���ܣ�  ��ʻ�����ǰ����18��ʹ����ѣ��2�Σ��ɳ�ȥ���Ҳ��ܣ�"<<endl;
		cout<<"�����ܣ�  ��ߴ���Ч��+2�����"<<endl;
		cout<<"���У�    ʹ�ý𹿰���ɨǰ��10����룬ʹ��Χ�ڶ����˺�15��ӵ�С���ʥ��������           ��50�غ�"<<endl;
		cout<<"�������ܣ����Լ�ӵ�С���ʥ������ʱ������3���������10�����"<<endl; 
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
			case 1:cout<<"��ʿ";break; 
			case 2:cout<<"��ʦ";break; 
			case 3:cout<<"�̿�";break;
			case 4:cout<<"Ĥ��ʦ";break;
			case 5:cout<<"ҩ��ʦ"<<endl;break;
			case 6:cout<<"��Ӱ";break;
			case 7:cout<<"��ʦ";break;
			case 8:cout<<"����";break;
			case 9:cout<<"����  ";break; 
			case 10:cout<<"�����";break;
		}
	}
	cout<<endl;
}
void xzJS(int tmp1,int tmp2,int p1,int p2)
{
	cout<<"��ѡ���ɫ��"<<endl<<endl;
	cout<<"P1��ѡ����ܣ�"<<endl;
	write_juese(tmp1);
	cout<<endl<<"P2��ѡ����ܣ�"<<endl;
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
    cout<<"˵����"<<endl<<endl;
    
    cout<<"�������������1 ad     �����ƶ���j һ���ܣ�k �����ܣ�h �������ܣ�l ����"<<endl;
    cout<<"          ���2 ����� �����ƶ���1 һ���ܣ�2 �����ܣ�0 �������ܣ�3 ����"<<endl<<endl;
    
    cout<<"ѡ������ʱ�����1 WSAD ���ƣ����2 ����� ���ơ�ʣ�µ��Լ���᡿"<<endl;
    cout<<"            ���1 �� j ȷ�������2 �� 1 ȷ��"<<endl<<endl;
    
    cout<<"��Ϸ�ڣ�������Ҫ�����·�������"<<endl;
    cout<<"        ��Ϸ����Ч�����ߣ�ʰȡ������"<<endl<<endl;
    
    cout<<"һ��Ҫ��ϸ�������˾�û��"<<endl<<endl;
    
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
		cout<<"P2��һ�ʤ"<<endl;
	}
	else
	{
		cout<<"P1��һ�ʤ"<<endl;
	}
	cout<<"�Ƿ����棿��1.�� 2.�˳���";
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
