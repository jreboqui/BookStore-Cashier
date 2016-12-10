#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include "strupper.h"

using namespace std;
const int NUM_BOOKS = 20;
const int STR_SIZE = 51;

extern char bookTitle[NUM_BOOKS][STR_SIZE];
extern char isbn[NUM_BOOKS][STR_SIZE];
extern char author[NUM_BOOKS][STR_SIZE];
extern char publisher[NUM_BOOKS][STR_SIZE];
extern char dateAdded[NUM_BOOKS][STR_SIZE];
extern int qtyOnHand[NUM_BOOKS];
extern double wholesale[NUM_BOOKS];
extern double retail[NUM_BOOKS];

void invMenu()
{
	int choice = 0;

	while (choice != 5)
	{
		cout << "Serendipity Booksellers\n";
		cout << "   Inventory Database\n\n";

		cout << "1. Look Up a Book\n";
		cout << "2. Add a Book\n";
		cout << "3. Edit a Book's Record\n";
		cout << "4. Delete a Book\n";
		cout << "5. Return to the Main Menu\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;


		//validate input
		while (choice < 1 || choice > 5)
		{
			cout << "\nPlease enter a number in the range 1 - 5\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			lookUpBook();
			break;
		case 2:
			addBook();
			break;
		case 3:
			editBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			cout << "\nYou selected item 5";
			break;
		}

		cout << endl;
	}//end while choice !=5
}

void lookUpBook()
{
	char YesNo = ' ';
	int row = 0;
	char searchTitle[STR_SIZE];

	cin.ignore();

	cout << "Enter the title of the book to search for: ";
	cin.getline(searchTitle, STR_SIZE);

	strUpper(searchTitle);

	for (row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(bookTitle[row],searchTitle))
		{
			cout << "\nPossible Match found: " << bookTitle[row] << "\n\n";
			cout << "Is this a correct match? (Y or N)  ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible Match found: " << bookTitle[row] << "\n\n";
				cout << "Is this a correct match? (Y or N)  ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y')
			{
				bookInfo(isbn[row], bookTitle[row], author[row], publisher[row],
					dateAdded[row], qtyOnHand[row], wholesale[row], retail[row]);
				break;
			}
		}
	}
	if (row > NUM_BOOKS -1)
		cout << "The book you searched for is not in the inventory" << endl;

}

void addBook()
{
	for (int row = 0; row < NUM_BOOKS; row++)
	{
		//find the first book whose element is 0
		if (bookTitle[row][0] == 0)
		{
			cin.ignore();
			cout << "Enter Title: ";
			cin.getline(bookTitle[row], STR_SIZE);
			strUpper(bookTitle[row]);

			cout << "Enter ISBN :";
			cin.getline(isbn[row], STR_SIZE);
			strUpper(isbn[row]);

			cout << "Enter Author :";
			cin.getline(author[row], STR_SIZE);
			strUpper(author[row]);

			cout << "Enter Publisher :";
			cin.getline(publisher[row], STR_SIZE);
			strUpper(publisher[row]);

			cout << "Enter Date Added to Inventory :";
			cin.getline(dateAdded[row], STR_SIZE);
			strUpper(dateAdded[row]);

			cout << "Enter Quantity Added :";
			cin >> qtyOnHand[row];

			cout << "Enter Wholesale Price :";
			cin >> wholesale[row];

			cout << "Enter Retail Price:";
			cin >> retail[row];

			cout << "\n\nRecord was entered.";
			break;
		} //end if	
		cout << "No more books may be added\n";
	} //end for loop
}

void editBook()
{
	int row = 0;
	int choice = 0;
	char YesNo = ' ';
	char searchTitle[STR_SIZE];

	cin.ignore();

	cout << "Enter thetitle of the book to edit: ";
	cin.getline(searchTitle, STR_SIZE);
	strUpper(searchTitle);

	for (row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(bookTitle[row], searchTitle))
		{
			cout << "\nPossible Match found: " << bookTitle[row] << "\n\n";
			cout << "Is this a correct match? (Y or N)  ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible Match found: " << bookTitle[row] << "\n\n";
				cout << "Is this a correct match? (Y or N)  ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y')
			{
				bookInfo(isbn[row], bookTitle[row], author[row], publisher[row],
					dateAdded[row], qtyOnHand[row], wholesale[row], retail[row]);

				do
				{
					cout << "\nYou may edit any of the following: " << endl;
					cout << "1. ISBN\n";
					cout << "2. Title\n";
					cout << "3. Author\n";
					cout << "4. Publisher\n";
					cout << "5. Date book was added to inventory\n";
					cout << "6. Quantity on hand\n";
					cout << "7. Wholesale cost\n";
					cout << "8. Retail Price\n";
					cout << "9. Exit\n\n";
					cin >> choice;

					while (choice < 1 || choice > 9)
					{
						cout << "\nPlease enter a number in the range between 1 and 9." << endl;
						cout << "Enter your choice :";
						cin >> choice;
					}

					switch (choice)
					{
					case 1:
						cout << "\nCurrent ISBN: ";
						cout << isbn[row] << endl;
						cin.ignore();
						cout << "Enter new ISBN: ";
						cin.getline(isbn[row], STR_SIZE);
						strUpper(isbn[row]);
						break;
					case 2:
						cout << "\nCurrent Title: ";
						cout << bookTitle[row] << endl;
						cin.ignore();
						cout << "Enter new Title: ";
						cin.getline(bookTitle[row], STR_SIZE);
						strUpper(bookTitle[row]);
						break;
					case 3:
						cout << "\nCurrent Author: ";
						cout << author[row] << endl;
						cin.ignore();
						cout << "Enter new Author: ";
						cin.getline(author[row], STR_SIZE);
						strUpper(author[row]);
						break;
					case 4:
						cout << "\nCurrent Publisher: ";
						cout << publisher[row] << endl;
						cin.ignore();
						cout << "Enter new Publisher: ";
						cin.getline(publisher[row], STR_SIZE);
						strUpper(publisher[row]);
						break;
					case 5:
						cout << "\nCurrent Date Added: ";
						cout << dateAdded[row] << endl;
						cin.ignore();
						cout << "Enter new Date: ";
						cin.getline(dateAdded[row], STR_SIZE);
						strUpper(dateAdded[row]);
						break;
					case 6:
						cout << "\nCurrent Quantity on Hand: ";
						cout << qtyOnHand[row] << endl;
						cin.ignore();
						cout << "Enter new Quantity On Hand: ";
						cin >> qtyOnHand[row];
						break;
					case 7:
						cout << "\nCurrent Wholesale Cost: ";
						cout << wholesale[row] << endl;
						cin.ignore();
						cout << "Enter new Wholesale Cost: ";
						cin >> wholesale[row];
						break;
					case 8:
						cout << "\nCurrent Retail Price: ";
						cout << retail[row] << endl;
						cin.ignore();
						cout << "Enter new Retail Price: ";
						cin >> retail[row];
						break;
					}
				} while (choice != 9);
				break;
			}// end if yesno
		}
	} //end for loop
	if (row > NUM_BOOKS - 1)
		cout << "\nSorry, no title matching: " << searchTitle << " was found\n\n";
}


void deleteBook()
{
	char searchTitle[STR_SIZE];
	int row = 0;
	char YesNo = ' ';

	cin.ignore();

	cout << "Enter the title of the book to delete: ";
	cin.getline(searchTitle,STR_SIZE);

	strUpper(searchTitle);

	for (row = 0; row < NUM_BOOKS; row ++)
	{
		if (strstr(bookTitle[row], searchTitle))
		{
			cout << "\nPossible Match found: " << bookTitle[row] << "\n\n";
			cout << "Is this a correct match? (Y or N)  ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible Match found: " << bookTitle[row] << "\n\n";
				cout << "Is this a correct match? (Y or N)  ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y')
			{
				bookInfo(isbn[row], bookTitle[row], author[row], publisher[row],
					dateAdded[row], qtyOnHand[row], wholesale[row], retail[row]);
				cout << "Would you like to delete entire record? Y/N\: ";
				cin >> YesNo;

				while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
				{
					cout << "Please enter Y or N\n\n";
					cout << "\nPossible Match found: " << bookTitle[row] << "\n\n";
					cout << "Would you like to delete entire record? Y/N\: ";
					cin >> YesNo;
				}

				if (YesNo == 'Y' || YesNo == 'y')
				{
					bookTitle[row][0] = 0;
					isbn[row][0] = 0;
					cout << "\nRecord was deleted\n";
				}
				else
					cout << "\nRecord was NOT deleted\n";
				break;
			}			
		}
	}
	if (row > NUM_BOOKS - 1)
		cout << "\nSorry, no title matching: " << searchTitle << " was found\n\n";
}