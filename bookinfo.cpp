#include <iostream>
#include "bookinfo.h"

using namespace std;

void bookInfo(string isbn, string title, string author, string publisher,
              string date, int qty, double wholesale, double retail)
{
    cout << "Serendipity Booksellers\n";
    cout << "Book Information\n";

    cout << "ISBN: " << isbn << "\n";
    cout << "Title: " << title << "\n";
    cout << "Author: " << author <<" \n";
    cout << "Publisher: " << publisher << "\n";
    cout << "Date Added: " << date << "\n";
    cout << "Quantity-On-Hand: " << qty << "\n";
    cout << "Wholesale Cost: " << wholesale << "\n";
    cout << "Retail Price: " << retail << "\n\n";

    cout << "Enter Your Choice: ";


}

