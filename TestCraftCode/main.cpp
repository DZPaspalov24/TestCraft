#include <iostream>
#include <cstdlib>
#include <string>
#include "menu.h"

using namespace std;

int main()
{
	int choice = 0;

	while (true) {
		system("cls");
		choice = showMenu();

		if (choice == 1) {
			page1();
		}
		else if (choice == 2) {
			page2();
		}
		else if (choice == 3) {
			scoresPage();
		}
		else if (choice == 4) {
			cout << "Goodbye!" << endl;
			return 0;
		}
		else {
			system("cls");
			cout << "No option available, choose again: ";
			cin >> choice;
		}
	}



}
