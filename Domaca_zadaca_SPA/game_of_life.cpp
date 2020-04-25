#include "game_of_life.h"
#include<ctime>
	
bool game_of_life::slucajna_vrijednost()
{
	int broj = rand() % (100) + 1;
	return broj <= 25;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	bool v = _generacija[j][i];
	return v;
}

int game_of_life::broj_susjeda(int x, int y)
{
	//x=i
	//y==j
	int brojac = 0;
	for (int i =y - 1; i <= y + 1; i++) {
		for (int j = x-1; j <= x+1; j++)
		{
			if (i == y && j ==x ) {
				continue;
			}
			if (i >= REDAKA) {
				continue;
			}
			if (j >= STUPACA) {
				continue;
			}
			if (i < 0) {
				continue;
			}
			if (j < 0) {
				continue;
			}
			if (celija_zauzeta(j,i)) {
				brojac++;
			}
		}
	}
	return brojac;
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0;j < STUPACA; j++)
		{
			_generacija[i][j] = false;
			_sljedeca_generacija[i][j] = false;
		}
	}

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			if (slucajna_vrijednost() == true) {
				_generacija[i][j] = true;
			}
		}
	}
	
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			int susjedi = broj_susjeda(j, i);
			if (susjedi == 2) {
				_sljedeca_generacija[i][j] = _generacija[i][j];
			}
			if (susjedi == 3) {
				_sljedeca_generacija[i][j] = true;
			}
			if(susjedi <2 || susjedi>3) {
				_sljedeca_generacija[i][j] = false;
			}

		}
	}
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j]=_sljedeca_generacija[i][j] ;
		}
	}
}

void game_of_life::iscrtaj()
{
	system("cls");
	
	for (size_t i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			if (celija_zauzeta(j,i)) {
				cout << "*";
			}
			else {
				cout << "_";
			}
		}
		cout << endl;
	}
}
