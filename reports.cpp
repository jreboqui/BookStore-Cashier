#include <iostream>

using namespace std;

int main()
{
    int choice;

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
            case 1: cout << "You selected 1 \n";
                    break;
            case 2: cout << "You selected 2 \n";
                    break;
            case 3: cout << "You selected 3 \n";
                    break;
            case 4: cout << "You selected 4 \n";
                    break;
            case 5: cout << "You selected 5 \n";
                    break;
            case 6: cout << "You selected 6 \n";
                    break;
            case 7: cout << "You selected 7 \n";
                    break;

        }//end of switch
    } //end of else


}


