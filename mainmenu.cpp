/* This version, we are converting it to a multi-file program and adding 
/  header files(which will be created later. 
*/
#include <iostream>
//Include the header files
#include "bookinfo.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"

using namespace std;
//Globals
const int SIZE = 20;

string bookTitle[SIZE];
string isbn[SIZE];
string author[SIZE];
string publisher[SIZE];
string dateAdded[SIZE];
int qtyOnHand[SIZE];
double wholesale[SIZE];
double retail[SIZE];

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
                case 1: cashier();
                        break;
                case 2: invMenu();
                        break;
                case 3: reports();
                        break;
                case 4: cout << "You selected 4 \n\n";
                        break;

            }//end of switch
        } //end of else
    }while (choice !=4);
}
