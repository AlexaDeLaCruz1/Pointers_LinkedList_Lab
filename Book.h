#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price;
    int year;

public:
   
    Book(const std::string& title, const std::string& author, double price, int year);


    std::string getTitle() const;
    std::string getAuthor() const;
    double getPrice() const;
    int getYear() const;

    //display book information
    void displayInfo() const;
};

#endif
