#include "reports.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int SIZE = 20;
//external declarations
extern string bookTitle[SIZE];
extern string isbn[SIZE];
extern string author[SIZE];
extern string publisher[SIZE];
extern string dateAdded[SIZE];
extern int qtyOnHand[SIZE];
extern double wholesale[SIZE];
extern double retail[SIZE];

void reports()
{
    int choice;
    do
    {

        cout << "Serendipity Booksellers\n";
        cout << "\tReports\n\n";
    
        cout << "1. Inventory Listing\n";
        cout << "2. Inventory Wholesale Value\n";
        cout << "3. Inventory Retail Value\n";
        cout << "4. Listing by Quantity\n";
        cout << "5. Listing by Cost\n";
        cout << "6. Listing by Age\n";
        cout << "7. Return to the Main Menu\n";
    
        cout << "Enter Your Choice: ";
        cin >> choice;
        /* Data Validation with switch branching(for later use) */
        if (choice > 7){
            cout << "Please enter a valid choice next time!\n";
        }
    
        else
        {
            switch(choice)
            {
                case 1: repListing();
                        break;
                case 2: repWholesale();
                        break;
                case 3: repRetail();
                        break;
                case 4: repQty();
                        break;
                case 5: repCost();
                        break;
                case 6: repAge;
                        break;
                case 7: cout << "You selected 7 \n\n";
                        break;

            }//end of switch
        } //end of else
    } while (choice != 7);

}

void repListing()
{
    string date; //todays date
    cout << "\n\nEnter Today's date: ";
    cin >> date;
    cout << endl;

    cout << "\n\n\t\tSerendipity Booksellers Inventory Report\n";
    cout << "Date: \t\t" << date;

    //loop and display the arrays
    for (int i =0; i < SIZE; i++)
    {
        if (isbn[i] != "") //not printing empty records
        {
            cout << "\n_______________________________________";
            cout << "\n\n\nTitle:\t\t\t" << bookTitle[i];
            cout << "\nISBN:\t\t\t" << isbn[i];
            cout << "\nAuthor:\t\t\t" << author[i];
            cout << "\nPublisher:\t\t" << publisher[i];
            cout << "\nDate Added:\t\t" << dateAdded[i];
            cout << fixed << showpoint << right << setprecision(2);
            cout << "\nQuantity on Hand:\t" << qtyOnHand[i];
            cout << "\nWholesale Cost: \t\t" << wholesale[i];
            cout << "\nRetail Price:\t\t" << retail[i];
        }
    }

    cout << "\n\n_______________________________________________";
    cout << "\n\nEnd of Inventory Report\n\n\n";
    
    //pause report on screen
    cout << "Press enter to continue";
    cin.ignore();
    cin.get();
}

void repWholesale()
{
    string date; //todays date
    cout << "\n\nEnter Today's date: ";
    cin >> date;
    cout << endl;

    cout << "\n\n\t\tSerendipity Booksellers Wholesale Report\n";
    cout << "Date: \t\t" << date;
    
    cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\tWholesale\n";
    cout << "\t___________________________________________________\n\n";

    double itemSubTotal = 0;
    double subTotal = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        if (isbn[i] != "") // checking for empty records
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
    cout << "\n\n_______________________________________________";
    cout << "\n\nEnd of Wholesale Report\n\n\n";
    
    //pause report on screen
    cout << "Press enter to continue";
    cin.ignore();
    cin.get();
}

void repRetail()
{
    string date; //todays date
    cout << "\n\nEnter Today's date: ";
    cin >> date;
    cout << endl;

    cout << "\n\n\t\tSerendipity Booksellers Retail Report\n";
    cout << "Date: \t\t" << date;
    
    cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\tWholesale\n";
    cout << "\t___________________________________________________\n\n";
    
    double itemSubTotal = 0;
    double subTotal = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        if (isbn[i] != "") // checking for empty records
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

    cout << "\n\n\n\tTotal Retail  Value: $ " << subTotal << endl;
    cout << "\n\n_______________________________________________";
    cout << "\n\nEnd of Retail  Report\n\n\n";
    
    //pause report on screen
    cout << "Press enter to continue";
    cin.ignore();
    cin.get();

}

void repQty()
{
    int id[SIZE]; //array to track original subscripts
    int* idPtr[SIZE]; //pointer to tracking array
    int* qtyPtr[SIZE]; //array of pointers to qtyOnHand array
    
    for (int i = 0; i< SIZE; i++)
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
    for (startScan = 0; startScan < SIZE - 1; startScan++)
    {
        maxIndex = startScan;
        maxValue = qtyPtr[startScan];
        tempId = idPtr[startScan];

        for (int index = startScan + 1; index < SIZE; index++)
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

    //Prompt user for date and then print the infosheet
    string date; //todays date
    cout << "\n\nEnter Today's date: ";
    cin >> date;
    cout << endl;

    cout << "\n\n\t\tSerendipity Booksellers Quantity Report\n";
    cout << "Date: \t\t" << date;
    
    cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\n";
    cout << "\t___________________________________________________\n\n";
    
    for (int j = 0; j < SIZE; j++)
    {
        if (isbn[*(idPtr[j])] != "") //not printing empty records
        {
            cout << "\n\t" << left << setw(26) << bookTitle[*(idPtr[j])];
            cout << left  << setw(14) << isbn[*(idPtr[j])];
            cout << right << setw(6) << *qtyPtr[j] << "\n";
        }
    }

    cout << "\n\n_______________________________________________";
    cout << "\n\nEnd of Quantity Report\n\n\n";
    
    //pause report on screen
    cout << "Press enter to continue";
    cin.ignore();
    cin.get();
}

void repCost()
{
    int id[SIZE]; //array to track original subscripts
    int* idPtr[SIZE]; //pointer to tracking array
    double* wholePtr[SIZE]; //array of pointers to qtyOnHand array
    
    for (int i = 0; i< SIZE; i++)
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
    for (startScan = 0; startScan < SIZE - 1; startScan++)
    {
        maxIndex = startScan;
        maxValue = wholePtr[startScan];
        tempId = idPtr[startScan];

        for (int index = startScan + 1; index < SIZE; index++)
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
    
    //Prompt user for date and then print the infosheet
    string date; //todays date
    cout << "\n\nEnter Today's date: ";
    cin >> date;
    cout << endl;

    cout << "\n\n\t\tSerendipity Booksellers Cost  Report\n";
    cout << "Date: \t\t" << date;
    
    cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\tWholesale\n";
    cout << "\t___________________________________________________\n\n";
    
    for (int j = 0; j < SIZE; j++)
    {
        if (isbn[*(idPtr[j])] != "") //not printing empty records
        {
            cout << "\n\t" << left << setw(26) << bookTitle[*(idPtr[j])];
            cout << left  << setw(14) << isbn[*(idPtr[j])];
            cout << fixed << showpoint << right << setprecision(2);
            cout << right << setw(6) << qtyOnHand[j];
            cout << setw(6) << "\t$ " << *wholePtr[j] << "\n\n";
        }
    }

    cout << "\n\n_______________________________________________";
    cout << "\n\nEnd of Cost  Report\n\n\n";
    
    //pause report on screen
    cout << "Press enter to continue";
    cin.ignore();
    cin.get();

}
void repAge()
{
    int id[SIZE]; //array to track original subscripts
    int* idPtr[SIZE]; //pointer to tracking array
    string* datePtr[SIZE]; //array of pointers to date added  array
    
    for (int i = 0; i< SIZE; i++)
    {
        id[i] = i;
        idPtr[i] = &id[i];
        datePtr[i] = &dateAdded[i];

    }

    int startScan;
    int maxIndex;
    int* tempId;
    string* maxValue;

    //selection sort to do qtyOnHand in descending order
    for (startScan = 0; startScan < SIZE - 1; startScan++)
    {
        maxIndex = startScan;
        maxValue = datePtr[startScan];
        tempId = idPtr[startScan];

        for (int index = startScan + 1; index < SIZE; index++)
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
    
    //Prompt user for date and then print the infosheet
    string date; //todays date
    cout << "\n\nEnter Today's date: ";
    cin >> date;
    cout << endl;

    cout << "\n\n\t\tSerendipity Booksellers Age  Report\n";
    cout << "Date: \t\t" << date;
    
    cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\tDateAdded\n";
    cout << "\t___________________________________________________\n\n";
    
    for (int j = 0; j < SIZE; j++)
    {
        if (isbn[*(idPtr[j])] != "") //not printing empty records
        {
            cout << "\n\t" << left << setw(26) << bookTitle[*(idPtr[j])];
            cout << left  << setw(14) << isbn[*(idPtr[j])];
            cout << fixed << showpoint << right << setprecision(2);
            cout << right << setw(6) << qtyOnHand[j];
            cout << setw(6) << "\t$ " << dateAdded[*(idPtr[j])] << "\n\n";
        }
    }

    cout << "\n\n_______________________________________________";
    cout << "\n\nEnd of Age  Report\n\n\n";
    
    //pause report on screen
    cout << "Press enter to continue";
    cin.ignore();
    cin.get();

}
