#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>

using namespace std;
const int SIZE = 20;
extern string bookTitle[SIZE];
extern string isbn[SIZE];
extern string author[SIZE];
extern string publisher[SIZE];
extern string dateAdded[SIZE];
extern int qtyOnHand[SIZE];
extern double wholesale[SIZE];
extern double retail[SIZE];

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
    bool found = false;
    int index = 0;
    string searchTitle;
    
    cin.ignore(); //ignore the newline from menu

    cout << "Enter the title of the book to search for: ";
    getline(cin, searchTitle);

    while (!found & index < SIZE)
    {
        if (bookTitle[index] == searchTitle)
            found = true;
        else
            index++;
    }
    if (found)
    {
        bookInfo(isbn[index], bookTitle[index], author[index],
        publisher[index], dateAdded[index], qtyOnHand[index],
        wholesale[index], retail[index]);
    }
    else
         cout << "The book you searched for is not in the inventory" << endl;
}

void addBook()
{
    bool found = false;
    int index = 0;

    while (!found & index < SIZE)
    {
        if (bookTitle[index] == "")
            found = true;
        else
            index++;
    }
    
    if (found) //book doesn't exist
    {
        cin.ignore();
        cout << "\nEnter Title: ";
        getline(cin, bookTitle[index]);

        cout << "\nEnter ISBN: ";
        getline(cin, isbn[index]);

        cout << "\nEnter ISBN: ";
        getline(cin, isbn[index]);

        cout << "\nEnter Author: ";
        getline(cin, author[index]);
        
        cout << "\nEnter Publisher: ";
        getline(cin, publisher[index]);

        cout << "\nEnter Date added to Inventory: ";
        getline(cin, dateAdded[index]);

        cout << "\nEnter Quantity Added: ";
        cin >> qtyOnHand[index];

        cout << "\nEnter Wholesale Price: ";
        cin >> wholesale[index];

        cout << "\nEnter Retail Price: ";
        cin >> retail[index];

        cout << "\n\nRecord saved.";

    }
    else
        cout << "No more books may be added\n";
}

void editBook()
{
    bool found = false;
    int index = 0;
    int choice = 0;
    string searchTitle;
    
    cin.ignore();
    
    cout << "Enter the title of the book to edit: ";
    getline(cin, searchTitle);

    while (!found & index < SIZE)
    {
        if (bookTitle[index] == searchTitle)
            found = true;
        else
            index++;
    }

    if (found)
    {
        bookInfo(isbn[index], bookTitle[index], author[index],
        publisher[index], dateAdded[index], qtyOnHand[index],
        wholesale[index], retail[index]);
        
        do
        {
            cout << "\nYou mayedit any of the following: " << endl;
            cout << "1. ISBN\n";
            cout << "2. Title\n";
            cout << "3. Author\n";
            cout << "4. Publisher\n";
            cout << "5. Date book was added to inventory\n";
            cout << "6. Quantity on hand\n";
            cout << "7. Wholesale cost\n";
            cout << "8. Retail Price\n";
            cout << "9. Exit\n\n";
            cin >> choice;

            while (choice < 1 || choice > 9)
            {
                cout << "\nPlease enter a number in the range 1-9";
                cout << "Enter your choice: ";
                cin >> choice;
            }//end of while loop
            
            switch(choice)
            {
            case 1:
                cout << "\nCurrent ISBN: ";
                cout << isbn[index] << endl;
                cin.ignore();
                cout << "Enter new ISBN: ";
                cin >> isbn[index];
                break;
            case 2:
                cout << "\nCurrent Title: ";
                cout << bookTitle[index] << endl;
                cin.ignore();
                cout << "Enter new Title: ";
                getline(cin, bookTitle[index]);
                break;
            case 3:
                cout << "\nCurrent Author: ";
                cout << author[index] << endl;
                cin.ignore();
                cout << "Enter new Author: ";
                getline(cin, author[index]);
                break;
            case 4:
                cout << "\nPublisher: ";
                cout << publisher[index] << endl;
                cin.ignore();
                cout << "Enter new Publisher: ";
                getline(cin, publisher[index]);
                break;
            case 5:
                cout << "\nCurrent Date Added: ";
                cout << dateAdded[index] << endl;
                cin.ignore();
                cout << "Enter new Date: ";
                getline(cin, dateAdded[index]);
                break;
            case 6:
                cout << "\nCurrent Quantity on Hand: ";
                cout << qtyOnHand[index] << endl;
                cin.ignore();
                cout << "Enter new Quantity on Hand: ";
                cin >> qtyOnHand[index];
                break;
            case 7:
                cout << "\nCurrent Wholesale Cost: ";
                cout << wholesale[index] << endl;
                cin.ignore();
                cout << "Enter new Wholesale Cost: ";
                cin >> wholesale[index];
                break;
            case 8:
                cout << "\nCurrent Retail Price: ";
                cout << retail[index] << endl;
                cin.ignore();
                cout << "Enter new Retail Price: ";
                cin >> retail[index];
                break;
            
            }//end of switch


        }//end do
        while (choice != 9);
    }//end of big if
    else
        cout << "The book you searched for is not in the inventory\n\n";       

}

void deleteBook()
{

    bool found = false;
    int index = 0;
    string searchTitle;
    char confirm;

    cin.ignore();

    cout << "Enter the title of the book you want to delete: ";
    getline(cin, searchTitle);

    while (!found & index < SIZE)
    {
        if (bookTitle[index] == searchTitle)
            found = true;
        else
            index++;
    }
    if (found)
    {
        bookInfo(isbn[index], bookTitle[index], author[index],
        publisher[index], dateAdded[index], qtyOnHand[index],
        wholesale[index], retail[index]);
     
        cout << "Are you sure you want to delete this book from the inventory?";
        cin >> confirm;

        if (confirm == 'Y' || confirm == 'y')
        {
            bookTitle[index] = "";
            isbn[index] = "";
            author[index] = "";
            publisher[index] = "";
            dateAdded[index] = "";
            qtyOnHand[index] = 0;
            wholesale[index] = 0;
            retail[index] = 0;
        }   
    } 
    else
        cout << "Book not found!\n\n";
}
