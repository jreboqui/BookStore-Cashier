#include <iostream>

using namespace std;

int main()
{
    int choice;

    cout << "Serendipity Booksellers\n";
    cout << "Invertory Database";

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
            case 1: cout << "\nYou selected 1 \n";
                    break;
            case 2: cout << "\nYou selected 2 \n";
                    break;
            case 3: cout << "\nYou selected 3 \n";
                    break;
            case 4: cout << "\nYou selected 4 \n";
                    break;
            case 5: cout << "\nYou selected 5 \n";
                    break;

        }//end of switch
    } //end of else
}
