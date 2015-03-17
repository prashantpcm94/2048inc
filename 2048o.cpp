#include<iostream>
using namespace std;
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int A[4][4];
int game()
{
	int i,j,c=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(A[i][j]!=0)
			{
				c++;
			}
		}
	}
	if(c==16)
	{
		for(i=0;i<4;i++)
		{
			int j=0;
			while(j<3)
			{
				if(A[i][j]==A[i][j+1])
				{
					return(1);
				}
				j++;
			}
			j=0;
			while(j<3)
			{
				if(A[j][i]==A[j+1][i])
				{
					return(1);
				}
				j++;
			}
		}
		return(0);
	}
	else
	{
		return(1);
	}
}
int main()
{
	int i,j,x,p;
	char ch;
	int score=0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//Innitialising The Matrix
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			A[i][j]=0;
		}
	}
	i=0;
	j=0;
	if(rand()%2==0)
	{
		A[i][j]=2;
	}
	else
	{
		A[i][j]=4;
	}
	i=1;
	j=1;
	if(rand()%2==0)
		A[i][j]=4;
	else
		A[i][j]=2;

	//GAME
	while(game())
	{
		SetConsoleTextAttribute(hConsole, 7);
		system("cls");
		cout<<"       \t\t2222222	   0000000     4     4     8888888\n";
		cout<<"       \t\t      2	   0	 0     4     4     8     8\n";
		cout<<"       \t\t      2	   0	 0     4     4     8     8\n";
		cout<<"       \t\t      2	   0     0     4     4     8     8\n";
		cout<<"       \t\t2222222	   0     0     4444444     8888888\n";
		cout<<"       \t\t2      	   0	 0           4     8     8\n";
		cout<<"       \t\t2     	   0	 0           4     8     8\n";
		cout<<"       \t\t2     	   0	 0           4     8     8\n";
		cout<<"       \t\t2222222	   0000000           4     8888888\n";
		cout<<endl<<endl<<endl<<endl;
		for(i=0;i<4;i++)
		{
			SetConsoleTextAttribute(hConsole, 7);
			cout<<endl<<"\t\t\t    ";
			for(j=0;j<4;j++)
			{
				if(A[i][j]==0)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout<<"     ";
				}
				else if(A[i][j]==2)
				{
					SetConsoleTextAttribute(hConsole, 112);
					cout<<"  2  ";
				}
				else if(A[i][j]==4)
				{
					SetConsoleTextAttribute(hConsole, 128);
					cout<<"  4  ";
				}
				else if(A[i][j]==8)
				{
					SetConsoleTextAttribute(hConsole, 160);
					cout<<"  8  ";
				}
				else if(A[i][j]==16)
				{
					SetConsoleTextAttribute(hConsole, 176);
					cout<<"  16 ";
				}
				else if(A[i][j]==32)
				{
					SetConsoleTextAttribute(hConsole, 158);
					cout<<"  32 ";
				}
				else if(A[i][j]==64)
				{
					SetConsoleTextAttribute(hConsole, 28);
					cout<<"  64 ";
				}
				else if(A[i][j]==128)
				{
					SetConsoleTextAttribute(hConsole, 224);
					cout<<" 128 ";
				}
				else if(A[i][j]==256)
				{
					SetConsoleTextAttribute(hConsole, 223);
					cout<<" 256 ";
				}
				else if(A[i][j]==512)
				{
					SetConsoleTextAttribute(hConsole, 79);
					cout<<" 512 ";
				}
				else if(A[i][j]==1024)
				{
					SetConsoleTextAttribute(hConsole, 78);
					cout<<" 1024";
				}
				else if(A[i][j]==2048)
				{
					SetConsoleTextAttribute(hConsole, 207);
					cout<<" 2048";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 192);
					cout<<setw(5)<<A[i][j];
				}
			}
			SetConsoleTextAttribute(hConsole, 7);
			cout<<endl;
		}
		ch=getch();
		pos:
		if((ch!='w')&&(ch!='W')&&(ch!='a')&&(ch!='A')&&(ch!='s')&&(ch!='S')&&(ch!='d')&&(ch!='D'))
		{
			ch=getch();
			goto pos;
		}
		else
		{
			if((ch=='w')||(ch=='W'))
			{
				for(j=0;j<4;j++)
				{
					i=0;
					while(i<3)
					{
						p=i+1;
						while(p<4)
						{
							if(A[p][j]!=0)
								break;
							else
								p++;
						}
						if(A[i][j]==A[p][j])
						{
							A[i][j]=A[i][j]+A[p][j];
							A[p][j]=0;
							score=score+A[i][j];
						}
						i++;
					}
				}
				for(j=0;j<4;j++)
				{
					x=0;
					for(i=0;i<4;i++)
					{
						if(A[i][j]!=0)
						{
							A[x][j]=A[i][j];
							x++;
						}
					}
					while(x<4)
					{
						A[x][j]=0;
						x++;
					}
				}
			}
			else if((ch=='a')||(ch=='A'))
			{
				for(i=0;i<4;i++)
				{
					j=0;
					while(j<3)
					{
						p=j+1;
						while(p<4)
						{
							if(A[i][p]!=0)
								break;
							else
								p++;

						}
						if(A[i][j]==A[i][p])
						{
							A[i][j]=A[i][j]+A[i][p];
							A[i][p]=0;
							score=score+A[i][j];
						}
						j++;
					}
				}
				for(i=0;i<4;i++)
				{
					x=0;
					for(j=0;j<4;j++)
					{
						if(A[i][j]!=0)
						{
							A[i][x]=A[i][j];
							x++;
						}
					}
					while(x<4)
					{
						A[i][x]=0;
						x++;
					}
				}
			}
			else if((ch=='s')||(ch=='S'))
			{
				for(j=0;j<4;j++)
				{
					i=3;
					while(i>0)
					{
						p=i-1;
						while(p>=0)
						{
							if(A[p][j]!=0)
								break;
							else
								p--;
						}
						if(A[i][j]==A[p][j])
						{
							A[i][j]=A[i][j]+A[p][j];
							A[p][j]=0;
							score=score+A[i][j];
						}
						i--;
					}
				}
				for(j=0;j<4;j++)
				{
					x=3;
					for(i=3;i>=0;i--)
					{
						if(A[i][j]!=0)
						{
							A[x][j]=A[i][j];
							x--;
						}
					}
					while(x>=0)
					{
						A[x][j]=0;
						x--;
					}
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					j=3;
					while(j>0)
					{
						p=j-1;
						while(p>=0)
						{
							if(A[i][p]!=0)
								break;
							else
								p--;
						}
						if(A[i][j]==A[i][p])
						{
							A[i][j]=A[i][j]+A[i][p];
							A[i][p]=0;
							score=score+A[i][j];
						}
						j--;
					}
				}
				for(i=0;i<4;i++)
				{
					x=3;
					for(j=3;j>=0;j--)
					{
						if(A[i][j]!=0)
						{
							A[i][x]=A[i][j];
							x--;
						}
					}
					while(x>=0)
					{
						A[i][x]=0;
						x--;
					}
				}
			}
		}
		p=rand()%2;
		if(p)
		{
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(A[i][j]==0)
					{
						A[i][j]=4;
						goto end;
					}
				}
			}
		}
		else
		{
			for(i=3;i>=0;i--)
			{
				for(j=3;j>=0;j--)
				{
					if(A[i][j]==0)
					{
						A[i][j]=2;
						goto end;
					}
				}
			}
		}
		end:
		SetConsoleTextAttribute(hConsole, 7);
		system("cls");
		cout<<"       \t\t2222222	   0000000     4     4     8888888\n";
		cout<<"       \t\t      2	   0	 0     4     4     8     8\n";
		cout<<"       \t\t      2	   0	 0     4     4     8     8\n";
		cout<<"       \t\t      2	   0     0     4     4     8     8\n";
		cout<<"       \t\t2222222	   0     0     4444444     8888888\n";
		cout<<"       \t\t2      	   0	 0           4     8     8\n";
		cout<<"       \t\t2     	   0	 0           4     8     8\n";
		cout<<"       \t\t2     	   0	 0           4     8     8\n";
		cout<<"       \t\t2222222	   0000000           4     8888888\n";
		cout<<endl<<endl<<endl<<endl;
		for(i=0;i<4;i++)
		{
			cout<<endl<<"\t\t\t    ";
			for(j=0;j<4;j++)
			{
				if(A[i][j]==0)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout<<"     ";
				}
				else if(A[i][j]==2)
				{
					SetConsoleTextAttribute(hConsole, 112);
					cout<<"  2  ";
				}
				else if(A[i][j]==4)
				{
					SetConsoleTextAttribute(hConsole, 128);
					cout<<"  4  ";
				}
				else if(A[i][j]==8)
				{
					SetConsoleTextAttribute(hConsole, 160);
					cout<<"  8  ";
				}
				else if(A[i][j]==16)
				{
					SetConsoleTextAttribute(hConsole, 176);
					cout<<"  16 ";
				}
				else if(A[i][j]==32)
				{
					SetConsoleTextAttribute(hConsole, 158);
					cout<<"  32 ";
				}
				else if(A[i][j]==64)
				{
					SetConsoleTextAttribute(hConsole, 28);
					cout<<"  64 ";
				}
				else if(A[i][j]==128)
				{
					SetConsoleTextAttribute(hConsole, 224);
					cout<<" 128 ";
				}
				else if(A[i][j]==256)
				{
					SetConsoleTextAttribute(hConsole, 223);
					cout<<" 256 ";
				}
				else if(A[i][j]==512)
				{
					SetConsoleTextAttribute(hConsole, 79);
					cout<<" 512 ";
				}
				else if(A[i][j]==1024)
				{
					SetConsoleTextAttribute(hConsole, 78);
					cout<<" 1024";
				}
				else if(A[i][j]==2048)
				{
					SetConsoleTextAttribute(hConsole, 207);
					cout<<" 2048";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 192);
					cout<<setw(5)<<A[i][j];
				}
			}
			SetConsoleTextAttribute(hConsole, 7);
			cout<<endl;
		}
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"\t\t\t      ";
	SetConsoleTextAttribute(hConsole, 192);
	cout<<"*** GAME OVER ***";
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"\n\t\t\t        ";
	SetConsoleTextAttribute(hConsole, 192);
	cout<<"SCORE:- "<<score;
	SetConsoleTextAttribute(hConsole, 7);
	return(0);
}
