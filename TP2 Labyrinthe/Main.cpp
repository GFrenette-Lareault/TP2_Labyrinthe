#include "ConsoleMenu.h"

using namespace std;

/** @file Main.cpp
	Fichier responsable de lancer le programme.

	@author Jean-David Moisan
	@author Gabriel Frenette-Lareault
	@date 4 avril 2014
	@version 1.0
 */

void main()
{
	setlocale(LC_ALL, "");

	ConsoleMenu menu;
	menu.Run();
}
