/*
DSA Project
TIC TAC TOE
Mohammad Abdullah(049) & Saad Ahmed(077)
*/
#include <iostream>
#include <vector> 
#include <stdlib.h> 
#include <cstdlib> 
#include <ctime>
#include <conio.h>

using namespace std;

const int Size = 3;
const int X = 1;
const int O = 2;
const int NA = 0;

class Board  //class Board
{
private:
	int t[Size][Size];
public:
	void setMove(int x, int y, int player)
	{
		t[x][y] = player;
	}
	int getVal(int x, int y)
	{
		return t[x][y];
	}
	int checkVictory()
	{
		int c = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
		for (int i = 0; i < Size; i++)
		{
			if (t[i][i] == 1)
				d1++;
			if (t[i][(Size - 1) - i] == 1)
				d2++;
		}
		if (d1 == Size)
			return 1;
		if (d2 == Size)
			return 1;

		d1 = 0; d2 = 0;
		for (int i = 0; i < Size; i++)
		{
			if (t[i][i] == 2)
				d1++;
			if (t[i][(Size - 1) - i] == 2)
				d2++;
		}
		if (d1 == Size)
			return 2;
		if (d2 == Size)
			return 2;

		for (int x = 0; x < Size; x++)
		{
			c1 = 0; c2 = 0;
			for (int y = 0; y < Size; y++)
			{
				if (t[x][y] == 1)
					c1++;
				else if (t[x][y] == 2)
					c2++;
			}
			if (c1 == Size)
				return 1;
			if (c2 == Size)
				return 2;
		}

		for (int y = 0; y < Size; y++)
		{
			c1 = 0;
			c2 = 0;
			for (int x = 0; x < Size; x++)
			{
				if (t[x][y] == 1)
					c1++;
				else if (t[x][y] == 2)
					c2++;
				else
					c++;
			}
			if (c1 == Size)
				return 1;

			if (c2 == Size)
				return 2;
		}
		if (c == 0)
			return 0;
		else
			return -1;
	}
	void display()
	{
		cout << "\t";
		for (int j = 0; j < Size; j++)
			cout << " 	";
		cout << "-\n";
		for (int i = 0; i < Size; i++)
		{
			cout << "\t";
			for (int j = 0; j < Size; j++)
			{

				if (t[i][j] == 0) cout << "|\t \t";

				else if (t[i][j] == 1) cout << "|\tX\t"; else
					cout << "|\tO\t";

			}
			cout << "|\n\t";
			for (int j = 0; j < Size; j++)
				cout << " 	";
			cout << "-\n";
		}
	}
	void startBoard()
	{
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				t[i][j] = 0;
			}
		}
	}
	bool isFilled(int x, int y)
	{
		if (t[x][y] == 0)
			return false;
		else
			return true;
	}
	void setRandom(int p)
	{
	r1:
		srand(time(0));
		int x = rand() % Size;
		int y = rand() % Size;
		if (isFilled(x, y) == false)
			setMove(x, y, p);
		else
			goto r1;
	}
};
//Structure AI
struct AImove
{
	int x;
	int y;
	int score;
	AImove() {}
	AImove(int s)
	{
		score = s;
	}
};
//Class AI
class AI
{
private:
	int AIPlayer;
	int humanPlayer;
public:
	void setAI(int aival, int humanval)
	{
		AIPlayer = aival;
		humanPlayer = humanval;
	}
	AImove getBestMove(Board& b, int player)
	{
		int v = b.checkVictory();

		if (v == AIPlayer)
			return AImove(1);

		else if (v == humanPlayer)
			return AImove(-1);

		else if (v == NA)
			return AImove(0);

		vector <AImove> moves;

		for (int x = 0; x < Size; x++)
		{
			for (int y = 0; y < Size; y++)
			{
				if (b.getVal(x, y) == NA)
				{
					AImove m;
					m.x = x;
					m.y = y;
					b.setMove(x, y, player);
					if (player == AIPlayer)
					{
						m.score = getBestMove(b, humanPlayer).score;
					}
					else
					{
						m.score = getBestMove(b, AIPlayer).score;
					}
					moves.push_back(m);
					b.setMove(x, y, NA);
				}
			}
		}
		int bm = 0;
		int bs;
		int i{};
		if (player == AIPlayer)
		{
			int bs = -99999;
			for (int i = 0; i < moves.size(); i++)
			{
				if (moves[i].score > bs)
				{

				}
			}
		}
		else
			bm = i;

		bs = moves[i].score;
		bs = 99999;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score < bs)
			{
				bm = i; bs = moves[i].score;
			}
		}
		return moves[bm];
	}
	void perform(Board& b)
	{
		AImove bm = getBestMove(b, AIPlayer);
		b.setMove(bm.x, bm.y, AIPlayer);
	}
};

//start main
int main()
{
	Board b;
	int o, x, y, c, Player;
	char p, s, q;
mainMenu:
	system("cls");
	cout << "\t -- DSA Project Spring 22 -- \n";
	cout << "\tMohammad Abdullah & Saad Ahmed\n";
	cout << "\t\t BS(CS)-3B\n";
	cout << "\n\n\t*************************\n";
	cout << "\t   WELCOME TO OUR GAME" << endl;
	cout << "\n\t       TIC TAC TOE" << endl;
	cout << "\t*************************\n";
l1:
	cout << "\n1) Multi Player \n" << endl;
	cout << "2) Single Player \n" << endl;
	cout << "Select an option : ";
	cin >> o;
	if (o == 1) {
	multiPlayer: b.startBoard();
		cout << "\n";
		while (b.checkVictory() == -1)
		{
			while (Player == X && b.checkVictory() == -1)
			{
				system("cls");
				cout << "\n\t\t\t TIC TAC TOE" << endl; 
				cout << "\n\n";
				b.display(); 
				cout << "\n\n";

			l2:
				cout << "\t" << p << " 's turn : " << endl;
				cout << "\tEnter x coordinate : "; cin >> x;
				cout << "\tEnter y coordinate : "; cin >> y;
				cout << "\n";
				if (x <= Size && y <= Size && x > 0 && y > 0 && b.isFilled(x - 1, y - 1) == false)
				{
					b.setMove(x - 1, y - 1, Player); 
					Player = O;
					p = 'O';
				}
				else
				{
					cout << "\tInvalid location \n\n"; 
					goto l2;
				}
			}
			while (Player == O && b.checkVictory() == -1)
			{
				system("cls");
				cout << "\n\t\t\t TIC TAC TOE" << endl;
				cout << "\n\n";
				b.display();
				cout << "\n\n"; 
			l3:
				cout << "\t" << p << " 's turn : " << endl;
				cout << "\tEnter x coordinate : "; 
				cin >> x;
				cout << "\tEnter y coordinate : ";
				cin >> y;
				cout << "\n";
				if (x <= Size && y <= Size && x > 0 && y > 0 && b.isFilled(x - 1, y - 1) == false)
				{
					b.setMove(x - 1, y - 1, Player); 
					Player = X;
					p = 'X';
				}
				else
				{
					cout << "\tInvalid location \n\n"; 
					goto l3;
				}
			}
		}
		system("cls");
		cout << "\n\t\t\t TIC TAC TOE" << endl; 
		cout << "\n\n";

		b.display(); cout << "\n\n"; if (b.checkVictory() == 1)
		{
			cout << "\tX win the game !!!\n";
		}
		else if (b.checkVictory() == 2)
		{
			cout << "\tO win the game !!!\n";
		}
		else
		{
			cout << "\tIts a Tie !!!\n";
		}
	c1:
		cout << "\n\tPress 'C' to continue playing multi player,'M' to return to the menu or 'E' to exit:";
		cin >> q;
		if (q == 'M' || q == 'm')
			goto mainMenu;
		else if (q == 'C' || q == 'c')
			goto multiPlayer;
		else if (q == 'E' || q == 'e')
			system(0);
		else
		{
			cout << "\nEnter a valid option ! ";
			goto c1;
		}
	}
	else if (o == 2)
	{
		AI a;
		int hp, aip;
		char xoo;
		goto s1;
	singlePlayer:
		system("cls");
	s1:
		c = 0;
		b.startBoard();
	l4:
		cout << "\n\tSelect 'X' or 'O' : ";
		cin >> xoo;
		if (xoo == 'X' || xoo == 'x')
		{
			a.setAI(2, 1); hp = 1;

			aip = 2;
		}
		else if (xoo == 'O' || xoo == 'o')
		{
			a.setAI(1, 2);
			hp = 2;
			aip = 1;
		}
		else
		{
			cout << "\n\tEnter valid option !\n";
			goto l4;
		}
	l5:
		cout << "\n\tDo you want to start the game ? ( Y / N ) : ";
		cin >> s;
		if (s == 'y' || s == 'Y')
			Player = hp;
		else if (s == 'n' || s == 'N')
			Player = aip;
		else
		{
			cout << "\n\tEnter valid option !\n";
			goto l5;
		}

		while (b.checkVictory() == -1)
		{
			while (Player == hp && b.checkVictory() == -1)
			{
				system("cls");
				cout << "\n\t\t\t TIC TAC TOE" << endl;
				cout << "\n\n";
				b.display();
				cout << "\n\n"; l6:
				cout << "\tIt is your turn : " << endl;
				cout << "\tEnter x coordinate : ";
				cin >> x;
				cout << "\tEnter y coordinate : ";
				cin >> y;
				cout << "\n";
				if (x <= Size && y <= Size && x > 0 && y > 0 && b.isFilled(x - 1, y - 1) == false)
				{
					b.setMove(x - 1, y - 1, Player);
					Player = aip;
					system("cls");

					cout << "\n\t\t\t TIC TAC TOE" << endl;
					cout << "\n\n";
					b.display();
					cout << "\n\n";
					cout << "\tThe computer is thinking	" << endl;
				}
				else
				{
					cout << "\tInvalid location \n\n";
					goto l6;
				}
			}
			while (Player == aip && b.checkVictory() == -1)
			{
				if (c < 1 && (s == 'N' || s == 'n'))
				{
					b.setRandom(Player); c++;
				}
				else
					a.perform(b); Player = hp;
			}
		}
		system("cls");
		cout << "\n\t\t\t TIC TAC TOE" << endl; cout << "\n\n";
		b.display(); cout << "\n\n"; if (b.checkVictory() == 1)
		{
			cout << "\tX win the game !!!\n";
		}
		else if (b.checkVictory() == 2)
		{
			cout << "\tO win the game !!!\n";
		}
		else
		{
			cout << "\tIts a Tie !!! \n";
		}
	c2:
		cout << "\n\tPress 'C' to continue playing single player,'M' to return to the menu or 'E' to exit:";
		cin >> q;
		if (q == 'M' || q == 'm')
			goto mainMenu;
		else if (q == 'C' || q == 'c')

			goto singlePlayer;
		else if (q == 'E' || q == 'e')
			system(0);
		else
		{
		}
	}
	else
	{
		cout << "\nEnter a valid option ! "; 
		goto c2;

		cout << "\n\tInvalid option! \n"; 
		goto l1;
	}
	_getch();
	return 0;
} //end main
