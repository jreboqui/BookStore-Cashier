#include "reports.h"
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>

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


void reports()
{
	int choice = 0;

	while (choice != 7)
	{

		cout << "Serendipity Booksellers\n";
		cout << "\tReports\n\n";

		cout << "1. Inventory Listing\n";
		cout << "2. Inventory Wholesale Value\n";
		cout << "3. Inventory Retail Value\n";
		cout << "4. Listing by Quantity\n";
		cout << "5. Listing by Cost\n";
		cout << "6. Listing by Age\n";
		cout << "7. Return to the Main Menu\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;

		//validate input
		while (choice < 1 || choice > 7)
		{
			cout << "\nPlease enter a number in the range 1 - 7\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}
			switch (choice)
			{
			case 1:
				repListing();
				break;
			case 2:
				repWholesale();
				break;
			case 3:
				repRetail();
				break;
			case 4:
				repQty();
				break;
			case 5:
				repCost();
				break;
			case 6:
				repAge();
				break;
			case 7:
				cout << "\nYou selected item 7";
				break;
			}

		cout << endl;

	}//end while choice !=7
}

void repListing()
{
	char end[] = { '\0' };
	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Inventory Report\n";
	cout << "Date: \t\t" << date;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(isbn[i],end) != 0) //not printing empty records
		{
			cout << "\n_____________________________________________________";
			cout << "\n\nTitle:\t\t\t" << bookTitle[i];
			cout << "\nISBN:\t\t\t" << isbn[i];
			cout << "\nAuthor:\t\t\t" << author[i];
			cout << "\nPublisher:\t\t" << publisher[i];
			cout << "\nDate Added:\t\t" << dateAdded[i];
			cout << fixed << showpoint << left << setprecision(2);
			cout << "\nQuantity on Hand:\t" << qtyOnHand[i];
			cout << "\nWholesale Cost: \t\t$ " << wholesale[i];
			cout << "\nRetail Price:\t\t $" << retail[i];
		}
	}

	cout << "\n\n________________________________________________________";
	cout << "\n\nEnd of Inventory Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}

void repWholesale()
{
	char end[] = { '\0' };
	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Wholesale Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "\t__________________________________________________\n\n";

	double itemSubTotal = 0;
	double subTotal = 0;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(isbn[i], end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << bookTitle[i];
			cout << left << setw(14) << isbn[i];
			cout << right << setw(6) << qtyOnHand[i] << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << wholesale[i];

			itemSubTotal = qtyOnHand[i] * wholesale[i];
			subTotal += itemSubTotal;
		}
	}

	cout << "\n\n\n\tTotal Wholesale Value: $ " << subTotal << endl;
	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Wholesale Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}

void repRetail()
{
	char end[] = { '\0' };
	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Retail Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tRetail\n";
	cout << "\t__________________________________________________\n\n";

	double itemSubTotal = 0;
	double subTotal = 0;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(isbn[i], end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << bookTitle[i];
			cout << left << setw(14) << isbn[i];
			cout << right << setw(6) << qtyOnHand[i] << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << retail[i];

			itemSubTotal = qtyOnHand[i] * retail[i];
			subTotal += itemSubTotal;
		}
	}

	cout << "\n\n\n\tTotal Retail Value: $ " << subTotal << endl;
	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Retail Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}

void repQty()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idPtr[NUM_BOOKS]; //pointer to tracking array
	int* qtyPtr[NUM_BOOKS]; //array of pointers to qtyOnHand array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		qtyPtr[i] = &qtyOnHand[i];
	}

	int startScan;
	int maxIndex;
	int* tempId;
	int* maxValue;

	//selection sort to do qtyOnHand in descending order
	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = qtyPtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(qtyPtr[index]) > *maxValue)
			{
				maxValue = qtyPtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		qtyPtr[maxIndex] = qtyPtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		qtyPtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Quantity Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\n";
	cout << "\t__________________________________________________\n\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(isbn[j], end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << bookTitle[*(idPtr[j])];
			cout << left << setw(14) << isbn[*(idPtr[j])];
			cout << right << setw(6) << *qtyPtr[j] << "\n";
		}
	}

	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Quantity Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}

void repCost()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idPtr[NUM_BOOKS]; //pointer to tracking array
	double* wholePtr[NUM_BOOKS]; //array of pointers to wholesale array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		wholePtr[i] = &wholesale[i];
	}

	int startScan;
	int maxIndex;
	int* tempId;
	double* maxValue;

	//selection sort to do qtyOnHand in descending order
	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = wholePtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(wholePtr[index]) > *maxValue)
			{
				maxValue = wholePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		wholePtr[maxIndex] = wholePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		wholePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Cost Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "\t__________________________________________________\n\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(isbn[j], end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << bookTitle[*(idPtr[j])];
			cout << left << setw(14) << isbn[*(idPtr[j])];
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << qtyOnHand[j];
			cout << setw(6) << "\t$ " << *wholePtr[j] << "\n";
		}
	}

	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Cost Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();

}

void repAge()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idPtr[NUM_BOOKS]; //pointer to tracking array
	char* datePtr[NUM_BOOKS]; //array of pointers to date added array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		datePtr[i] = dateAdded[i];
	}

	int startScan;
	int maxIndex;
	int* tempId;
	char* maxValue;

	//selection sort to do qtyOnHand in descending order
	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = datePtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(datePtr[index]) > *maxValue)
			{
				maxValue = datePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		datePtr[maxIndex] = datePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		datePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Age Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tDateAdded\n";
	cout << "\t__________________________________________________\n\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(isbn[j], end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << bookTitle[*(idPtr[j])];
			cout << left << setw(14) << isbn[*(idPtr[j])];
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << qtyOnHand[j];
			cout << setw(6) << "\t$ " << dateAdded[*(idPtr[j])] << "\n";
		}
	}

	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Age Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}
