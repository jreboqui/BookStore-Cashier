#include <iostream>
#include <string>
#include <iomanip>
#include "cashier.h"

using namespace std;

void cashier()
{
    const double SALES_TAX = 0.06; //6% sales tax
    
    string date;
    string isbn;
    string title;
    int quantity;
    double price;
    double subtotal;
    double tax;
    double total;
    char doAgain;

    do
    {
    
        cout << "Serendipity Booksellers\n";
        cout << "Cashier Module\n\n";
        
        cin.ignore();

        cout << "Enter Date: ";
        getline(cin, date);  //takes input from cin and pass it to date variable   
    
        cout << "Quantity of the Book: ";
        cin >> quantity;
        cin.ignore(); //ignore the new line character when enter is pressed
   
        cout << "ISBN: ";
        getline(cin, isbn);

        cout << "Title: ";
        getline(cin, title);

        cout << "Price: ";
        cin >> price;

        //Calculations
        subtotal = quantity * price;
        tax = subtotal * SALES_TAX;
        total = subtotal + tax;
    
        cout << "Date: " << date << " \n\n";
    
        cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n ";
        cout << "________________________________________________________________________";
        cout << "\n\n\n";
    
        cout << quantity << "\t"; //display quantity
        cout << left << setw(14) << isbn << "\t"; //display ISBN
        cout << left << setw(26) << title << "\t$ "; //display title
        cout << fixed << showpoint << right << setprecision(2); //format numbers
        cout << setw(6) << price << "\t$ "; //display price
        cout << setw(6) << subtotal << "\n\n"; //display subtotal in line
    
        //calculated totals
        cout << "\t\tSubtotal\t\t\t\t\t\t$ ";
        cout << setw(6) << subtotal << "\n";
        cout << "\t\tTax\t\t\t\t\t\t\t$ ";
        cout << setw(6) << tax << "\n";
        cout << "\t\tTotal\t\t\t\t\t\t\t$ ";
        cout << setw(6) << total << "\n\n";

        cout << "Do again? (Y/N)";
        cin >> doAgain;
        cin.ignore();
        cout << "\n\n\n";
    }while (doAgain == 'Y' || doAgain == 'y');
    
    cout << "\n\nThank you for shopping at Serendipity\n";
    

}
