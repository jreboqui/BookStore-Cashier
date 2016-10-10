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
    cout << "\nYou selected Inventory Quantity.\n";
}
void repCost()
{
    cout << "\nYou selected Inventory Cost.\n";
}
void repAge()
{
    cout << "\nYou selected Inventory Listing by Age.\n";
}
