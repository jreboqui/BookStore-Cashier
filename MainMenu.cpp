#include <iostream>
#include "bookinfo.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"

using namespace std;

const int NUM_BOOKS = 20;
const int STR_SIZE = 51;

char bookTitle[NUM_BOOKS][STR_SIZE];
char isbn[NUM_BOOKS][STR_SIZE];
char author[NUM_BOOKS][STR_SIZE];
char publisher[NUM_BOOKS][STR_SIZE];
char dateAdded[NUM_BOOKS][STR_SIZE];
int qtyOnHand[NUM_BOOKS];
double wholesale[NUM_BOOKS];
double retail[NUM_BOOKS];

int main()
{
	int choice = 0;

	while (choice != 4)
	{
		cout << "Serendipity Booksellers\n";
		cout << "\tMain Menu\n\n";

		cout << "1. Cashier Module\n";
		cout << "2. Inventory Database Module\n";
		cout << "3. Report Module\n";
		cout << "4. Exit\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;

		//validate input
		while (choice < 1 || choice > 4)
		{
			cout << "\nPlease enter a number in the range 1 - 4\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}

			switch (choice)
			{
			case 1:
				cashier();
				break;
			case 2:
				invMenu();
				break;
			case 3:
				reports();
				break;
			case 4:
				cout << "\nYou selected item 4";
				break;
			}

		cout << endl;
	}

	return 0;
}