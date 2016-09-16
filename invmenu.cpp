#include "invmenu.h"
#include <iostream>

using namespace std;

void invMenu()
{
    int choice;

    do
    {
        cout << "Serendipity Booksellers\n";
        cout << "Invertory Database\n\n";

        cout << "\t1. Look-Up a Book\n";
        cout << "\t2. Add a Book\n";
        cout << "\t3. Edit a Book's Record\n";
        cout << "\t4. Delete a Book\n";
        cout << "\t5. Return to the Main Menu\n";

        cout << "Enter Your Choice: ";
        //Data Validation
        cin >> choice;
        if (choice > 5)
            cout << "\nPlease enter a valid number 1-5\n";
        else
        {
            switch(choice)
            {
                case 1: lookUpBook();
                        break;
                case 2: addBook();
                        break;
                case 3: editBook();
                        break;
                case 4: deleteBook(); 
                        break;
                case 5: cout << "\nYou selected 5 \n";
                        break;
    
            }//end of switch
        } //end of else
    }while (choice != 5);

}

void lookUpBook()
{
    cout << "\nYou selected Look Up Book!\n";
}

void addBook()
{
    cout << "\nYou selected Add A  Book!\n";
}

void editBook()
{
    cout << "\nYou selected Edit Book!\n";
}

void deleteBook()
{
    cout << "\nYou selected Delete Book!";
}
