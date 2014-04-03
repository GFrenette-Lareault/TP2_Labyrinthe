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
			if (tabSquare[i][j]->value == 'D')
			{
				startSquare = tabSquare[i][j];
			}
		}
	}

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