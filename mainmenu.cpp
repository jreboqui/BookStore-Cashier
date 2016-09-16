/* This version, we are modifying the data validation, we check if the value
/  is an integer that is 1-4, then we repeatedly show the menu until the user
/  enters 4, which exits the program
*/
#include <iostream>

using namespace std;

int main()
{
    int choice;
    
    do{
        cout << "Serendipity Booksellers\n";

        cout << "\tMain Menu\n\n";

        cout << "1. Cashier Module\n";
        cout << "2. Inventory Database Module\n";
        cout << "3. Report Module\n";
        cout << "4. Exit\n\n";

        cout << "Enter Your Choice: ";
        cin >> choice;
        /* Data Validation with switch branching(for later use) */
        if (choice < 1 || choice > 4){
            cout << "Please enter a valid choice next time!\n";
        }

        else
        {
            switch(choice)
            {
                case 1: cout << "You selected 1 \n\n";
                        break;
                case 2: cout << "You selected 2 \n\n";
                        break;
                case 3: cout << "You selected 3 \n\n";
                        break;
                case 4: cout << "You selected 4 \n\n";
                        break;

            }//end of switch
        } //end of else
    }while (choice !=4);
}
