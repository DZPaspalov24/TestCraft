#include <iostream>
#include <cstdlib>
#include <string>
#include "menu.h"
 
using namespace std;

int showMenu() {
	int choice;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                           TEST CRAFT-BIOLOGY TESTS                          " << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "1. Take a test" << endl;
	cout << "2. How to use Test Craft" << endl;
	cout << "3. Test marks" << endl;
	cout << "4. Exit" << endl;
	cout << " " << endl;
	cout << "What page do you want to go to: ";
	cin >> choice;

	return choice;
}

void page1() {
	system("cls");
	int back;
	cout << "Take a Test page." << endl;
	cout << "Press 1 to go back: ";
	cin >> back;
}

void page2() {
	system("cls");
	int back;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                           TEST CRAFT-HOW TO USE                             " << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Test Craft is an application designed to help students improve their grades in school or learn something new." << endl;
	cout << "Within the app, users can take biology tests, complete homework assignments, and prepare for upcoming" << endl;
	cout << "school exams." << endl;
	cout << " " << endl;
	cout << "After completing a test, students enter their name and are placed in a ranking system that includes all" << endl;
	cout << "students who have taken that particular test. Additionally, users can view their average score across all" << endl;
	cout << "completed tests and homework assignments, allowing them to track their academic progress over time." << endl;
	cout << " " << endl;
	cout << "Press 1 to go back to the main menu: ";
	cin >> back;
}

void page3() {
	system("cls");
	int back;
	cout << "Test marks page." << endl;
	cout << "Press 1 to go back: ";
	cin >> back;
}