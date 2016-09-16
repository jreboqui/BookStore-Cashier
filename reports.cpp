#include "reports.h"
#include <iostream>

using namespace std;

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
    cout << "\nYou selected Inventory Listing.\n";
}

void repWholesale()
{
    cout << "\nYou selected Inventory Wholesale Value.\n";
}
void repRetail()
{
    cout << "\nYou selected Inventory Retail Value.\n";
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
