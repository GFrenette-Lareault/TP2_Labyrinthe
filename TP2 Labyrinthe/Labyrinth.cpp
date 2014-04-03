#include "labyrinth.h"

Labyrinth::Labyrinth(string _fileName)
{
	cout << "File reading start" << endl;
	ifstream file("Ressources/" + _fileName);
	string str;
	for(int i = 0; i < 20; i++)
	{
		getline(file, str);
		for(int j = 0; j < 20; j++)
		{
			tabSquare[i][j] = new Square(j, i, str[j]);
			tabSquare[i][j]->visited = false;
			if (tabSquare[i][j]->value == 'D')
			{
				startSquare = tabSquare[i][j];
			}
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			tabSquare[i][j]->lowerSquare = tabSquare[i+1][j];
			tabSquare[i][j]->rightSquare = tabSquare[i][j+1];

			tabSquare[i+1][j]->upperSquare = tabSquare[i][j];
			tabSquare[i][j+1]->leftSquare = tabSquare[i][j];
		}
	}

	tabSquare[19][18]->rightSquare = tabSquare[19][19];
	tabSquare[18][19]->lowerSquare = tabSquare[19][19];

	tabSquare[19][19]->leftSquare = tabSquare[19][18];
	tabSquare[19][19]->upperSquare = tabSquare[18][19];
}

Labyrinth::~Labyrinth()
{
	delete [] tabSquare;
	delete startSquare;
}

string Labyrinth::ToString()
{
	string str = "";
	for(int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			str += tabSquare[i][j]->value;
		}
		str += "\n";
	}
	return str;
}

Square* Labyrinth::GetStartSquare()
{
	return startSquare;
}