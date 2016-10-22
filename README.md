# BookStore-Cashier
Bookseller Program from Starting Out with C++ Book

All cpp files are separated on this one. This version ask the user for input but does not do anything to the input right now. No input validation as well. Main changes are in the cashier.cpp where we ask several inputs including string inputs with the use of getline method. Then formatted so it shows at then end as a summary receipt which also has calculations for the book being sold and taxes added to it.


---Edit 1

Most of the functions are now working except some parts of the reports. We use linear search to check for a book in the database for now, later we'll use binary search. Right now you can add books in an array data structure but I will change it to a better one. I'm moving into making book classes to hold book information on the next two updates.

--Edit 2 10/21/206
Added the reports functionality: generates a report based on the user selection. report can be by cost, by sale value, or by date added. to sort the books, I implemented a simple selection sort.
