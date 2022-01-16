#pragma once
#include "AllocFunctions.h"

int main()
{
	CTable c_tab_0, c_tab_1, c_tab_2;

	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);

	//c_tab_0 = c_tab_1;

	/*Zad 1
	Po zako�czeniu programu nast�puje crash, poniewa� operator = wykonuje shallow copy co sprawia, �e 2 obiekty wskazuj� na ten sam fragment pami�ci, przez co
	przy wywo�aniu destruktora pod koniec programu dla obiektu c_tab_0 nie sprawia problem�w, natomiast przy pr�bie usuni�cia obiektu c_tab_1 pr�bujemy drugi raz
	usun�� pami�� kt�ra zosta�a ju� usuni�ta*/

	/*Zad 2
	Je�li usuniemy destruktor w klasie CTable spowoduje to, �e zaalokowana pami�� dla piTable nie zostanie usuni�ta, przez co wyst�pi memory leak i nie b�dziemy mieli mo�liwo�ci �ledzenie tego fragmentu pamieci*/
	
	std::cout << "c_tab_0:\n";
	c_tab_0.vSetValueAt(0, 15);
	c_tab_0.vSetValueAt(1, 20);
	c_tab_0.vSetValueAt(2, 25);
	c_tab_0.vSetValueAt(3, 30);
	c_tab_0.vSetValueAt(4, 35);
	c_tab_0.vSetValueAt(5, 40);
	c_tab_0.vSetValueAt(6, 45);
	c_tab_0.vPrint();

	std::cout << '\n';

	std::cout << "c_tab_1:\n";
	c_tab_1.vSetValueAt(-1, 15555);
	c_tab_1.vSetValueAt(0, 50);
	c_tab_1.vSetValueAt(1, 55);
	c_tab_1.vSetValueAt(2, 60);
	c_tab_1.vSetValueAt(3, 65);
	c_tab_1.vSetValueAt(4, 70);
	c_tab_1.vPrint();

	c_tab_2 = c_tab_0 + c_tab_1;
	c_tab_2.vPrint();

	return 0;
}