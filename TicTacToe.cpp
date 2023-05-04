// code for j comp
// tic tac toe using minimax in c++

#include <iostream> 
#include <vector> 
#include <stdlib.h> 
#include <cstdlib>
 #include <ctime>

using namespace std;

const int size=3; const int X=1; const int O=2; const int NA=0; class board
{
private:
int t[size][size]; public:
void setMove(int x, int y, int player)
{
t[x][y]=player;
}
int getVal(int x,int y)
{
return t[x][y];
}
int checkVictory()
{
int c=0,c1=0,c2=0,d1=0,d2=0;
for(int i=0;i<size;i++)
{
if(t[i][i]==1) d1++;
if(t[i][(size-1)-i]==1) d2++;
}
if(d1==size) return 1;
if(d2==size) return 1;
 
d1=0; d2=0;
for(int i=0;i<size;i++)
{
if(t[i][i]==2) d1++;
if(t[i][(size-1)-i]==2) d2++;
}
if(d1==size) return 2;
if(d2==size) return 2;

for(int x=0;x<size;x++)
{
c1=0; c2=0;
for(int y=0;y<size;y++)
{
if(t[x][y]==1) c1++;
else if(t[x][y]==2) c2++;
}
if(c1==size) return 1;
if(c2==size) return 2;
}

for(int y=0;y<size;y++)
{
c1=0; c2=0;
for(int x=0;x<size;x++)
{
if(t[x][y]==1) c1++;
else if(t[x][y]==2) c2++;
else
c++;
}
if(c1==size) return 1;
 
if(c2==size) return 2;
}
if(c==0)
return 0; else
return -1;
}
void display()
{
cout<<"\t";
for(int j=0;j<size;j++) cout<<" 	";
cout<<"-\n";
for(int i=0;i<size;i++)
{
cout<<"\t";
for(int j=0;j<size;j++)
{

if(t[i][j]==0) cout<<"|\t \t";

else if(t[i][j]==1) cout<<"|\tX\t"; else
cout<<"|\tO\t";

}
cout<<"|\n\t";
for(int j=0;j<size;j++) cout<<" 	";
cout<<"-\n";
}
}
void startBoard()
{
for(int i=0;i<size;i++)
{
for(int j=0;j<size;j++)
{
t[i][j]=0;
}
 
}
}
bool isFilled(int x, int y)
{
if(t[x][y]==0) return false;
else
return true;
}
void setRandom(int p)
{
r1: srand(time(0));
int x=rand()%size; 
int y=rand()%size;
if(isFilled(x,y)==false) setMove(x,y,p);
else
goto r1;
}
};
struct AImove
{
int x; int y;
int score; AImove(){}
AImove(int s){score=s;}
};
class AI
{
private:
int aiPlayer;
int humanPlayer; public:
void setAI(int aival,int humabval)
{
aiPlayer=aival; humanPlayer=humabval;
}
AImove getBestMove(board &b,int player)
{
int v=b.checkVictory();
 
if(v==aiPlayer) return AImove(1);

else if(v==humanPlayer) return AImove(-1);

else if(v==NA) return AImove(0);
vector<AImove> moves;
 for(int x=0;x<size;x++)
{
for(int y=0;y<size;y++)
{
if(b.getVal(x,y)==NA)
{
AImove m; m.x=x;
m.y=y; b.setMove(x,y,player); if(player==aiPlayer)
{
m.score=getBestMove(b,humanPlayer).score;
}
else
{
m.score=getBestMove(b,aiPlayer).score;
}
moves.push_back(m); b.setMove(x,y,NA);
}
}
}
int bm=0;
if(player == aiPlayer)
{
int bs=-99999;
for(int i=0;i<moves.size();i++)
{
if(moves[i].score>bs)
{
 


}
}

}
else
 int bm;
 int i;
 int bs;
bm=i; 
bs=moves[i].score;
 
{
int bs=99999;
for(int i=0;i<moves.size();i++)
{
if(moves[i].score<bs)
{
bm=i; bs=moves[i].score;
}
}
}
return moves[bm];
}
void perform(board &b)
{
AImove bm=getBestMove(b,aiPlayer); b.setMove(bm.x,bm.y,aiPlayer);
}
};

int main()
{
board b;
int o,player,x,y,c; char p,s,q; mainMenu: system("cls");
cout<<"\n TIC TAC TOE"<<endl;
 l1:
cout<<"\n1) Multi Player \n"<<endl; cout<<"2) Single Player \n"<<endl; cout<<"Select an option : "; cin>>o;
player=X; p='X';
if(o==1)
{
multiPlayer: b.startBoard(); cout<<"\n";
while(b.checkVictory()==-1)
{
while(player==X && b.checkVictory()==-1)
{
system("cls");
cout<<"\n\t\t\t TIC TAC TOE"<<endl; cout<<"\n\n";
b.display(); cout<<"\n\n";
 
l2:
cout<<"\t"<<p<<" 's turn : "<<endl; cout<<"\tEnter x coordinate : "; cin>>x;
cout<<"\tEnter y coordinate : "; cin>>y;
cout<<"\n";
if(x<=size&&y<=size&&x>0&&y>0&&b.isFilled(x-1,y-1)==false)
{
b.setMove(x-1,y-1,player); player=O;
p='O';
}
else
{
cout<<"\tInvalid location \n\n"; goto l2;
}
}
while(player==O && b.checkVictory()==-1)
{
system("cls");
cout<<"\n\t\t\t TIC TAC TOE"<<endl; cout<<"\n\n";
b.display(); cout<<"\n\n"; l3:
cout<<"\t"<<p<<" 's turn : "<<endl; cout<<"\tEnter x coordinate : "; cin>>x;
cout<<"\tEnter y coordinate : "; cin>>y;
cout<<"\n";
if(x<=size&&y<=size&&x>0&&y>0&&b.isFilled(x-1,y-1)==false)
{
b.setMove(x-1,y-1,player); player=X;
p='X';
}
else
{
cout<<"\tInvalid location \n\n"; goto l3;
}
}
}
system("cls");
cout<<"\n\t\t\t TIC TAC TOE"<<endl; cout<<"\n\n";
 
b.display(); cout<<"\n\n"; if(b.checkVictory()==1)
{
cout<<"\tX win the game !!!\n";

}
else if(b.checkVictory()==2)
{
cout<<"\tO win the game !!!\n";
}
else
{
cout<<"\tIts a Tie !!!\n";
}
c1:
cout<<"\n\tPress 'C' to continue playing multi player,'M' to return to the menu or 'E' to exit:";
cin>>q;
if(q=='M' || q=='m') goto mainMenu;
else if(q=='C' || q=='c') goto multiPlayer;
else if(q=='E' || q=='e') system(0);
else
{
cout<<"\nEnter a valid option ! "; goto c1;
}
}
else if(o==2)
{
AI a;
int hp,aip; char xoo; goto s1; singlePlayer: system("cls"); s1:
c=0;
b.startBoard(); l4:
cout<<"\n\tSelect 'X' or 'O' : "; cin>>xoo; if(xoo=='x'|| xoo=='X')
{
a.setAI(2,1); hp=1;
 
aip=2;
}
else if(xoo=='o'||xoo=='O')
{
a.setAI(1,2); hp=2; aip=1;
}
else
{
cout<<"\n\tEnter valid option !\n"; goto l4;
}
l5:
cout<<"\n\tDo you want to start the game ? ( Y / N ) :"; cin>>s;
if(s=='y'||s=='Y') player=hp;
else if(s=='n'||s=='N') player=aip;
else
{
cout<<"\n\tEnter valid option !\n"; goto l5;
}

while(b.checkVictory()==-1)
{
while(player==hp&& b.checkVictory()==-1)
{
system("cls");
cout<<"\n\t\t\t TIC TAC TOE"<<endl; cout<<"\n\n";
b.display(); cout<<"\n\n"; l6:
cout<<"\tIt is your turn : "<<endl; cout<<"\tEnter x coordinate : "; cin>>x;
cout<<"\tEnter y coordinate : "; cin>>y;
cout<<"\n";
if(x<=size&&y<=size&&x>0&&y>0&&b.isFilled(x-1,y-1)==false)
{
b.setMove(x-1,y-1,player); player=aip;
system("cls");
 
cout<<"\n\t\t\t TIC TAC TOE"<<endl; cout<<"\n\n";
b.display(); cout<<"\n\n";
cout<<"\tThe computer is thinking	"<<endl;
}
else
{
cout<<"\tInvalid location \n\n"; goto l6;
}
}
while(player==aip && b.checkVictory()==-1)
{
if(c<1 && (s=='N'||s=='n'))
{
b.setRandom(player); c++;
}
else
a.perform(b); player=hp;
}
}
system("cls");
cout<<"\n\t\t\t TIC TAC TOE"<<endl; cout<<"\n\n";
b.display(); cout<<"\n\n"; if(b.checkVictory()==1)
{
cout<<"\tX win the game !!!\n";
}
else if(b.checkVictory()==2)
{
cout<<"\tO win the game !!!\n";
}

 
else
{

}
c2:
 


cout<<"\tIts a Tie !!! \n";
 

cout<<"\n\tPress 'C' to continue playing single player,'M' to return to the menu or 'E' to exit:";
cin>>q;
if(q=='M' || q=='m') 
goto mainMenu;
else if(q=='C' || q=='c')
goto singlePlayer; 
else if(q=='E' || q=='e')
system(0);
}
else
{
 
cout<<"\nEnter a valid option ! "; goto c2;
 
cout<<"\n\tInvalid option! \n"; goto l1;
}
return 0;
}
