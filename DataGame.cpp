#include <iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
	srand((unsigned) time(NULL));
	int score1 = 0;
	int score2 = 0;
	int onewins = 0;
	int twowins = 0;
	int dicesuits[3];
	int cards[39];
	for (int count = 1; count <= 100000000; count++)
	{
		int diceroll = 1+rand() % 6;
		int dicesuit = 1+rand() % 4;
		int cardnum = 1+rand() % 40;
		if (dicesuit == (((cardnum-1) / 10)+1))
			if (cardnum%10 == 0)
				score1 = 10*diceroll;
			else
				score1 = (cardnum%10)*diceroll;
		else
			if (cardnum%10 == 0)
				score1 = 10+diceroll;
			else
				score1 = (cardnum%10)+diceroll;
		int spot = 0;
		for (int count = 1; count <= 4; count ++)
		{
			if (count != diceroll)
			{
				dicesuits[spot] = count;
				spot ++;
			}
		}
		spot = 0;
		for (int count = 1; count <= 40; count ++)
		{
			if (count != cardnum)
			{
				cards[spot] = count;
				spot ++;
			}
		}
		dicesuit = dicesuits[rand()% 3];
		diceroll = 1+rand() % 6;
		cardnum = cards[rand()%39];
		if (dicesuit == (((cardnum-1) / 10) + 1))
			if (cardnum%10 == 0)
				score2 = 10*diceroll;
			else
				score2 = (cardnum%10)*diceroll;
		else
			if (cardnum%10 == 0)
				score2 = 10+diceroll;
			else
				score2 = (cardnum%10)+diceroll;
		if (score1 >= score2)
			onewins ++;
		else
			twowins ++;
	}
	cout << onewins << "\n";
	cout << twowins << "\n";
	return EXIT_SUCCESS;
}