/* This version, we are adding data validation, we check if the value
/  is an integer that is 1-4, note that this version doesn't have a loop
/  and terminates either way.
*/
#include <iostream>

using namespace std;

int main()
{
    int choice;

    cout << "Serendipity Booksellers\n";

    cout << "\tMain Menu\n\n";

    cout << "1. Cashier Module\n";
    cout << "2. Inventory Database Module\n";
    cout << "3. Report Module\n";
    cout << "4. Exit\n\n";

    cout << "Enter Your Choice: ";
    cin >> choice;
    /* Data Validation with switch branching(for later use) */
    if (choice > 4){
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

        }//end of switch
    } //end of else
}
