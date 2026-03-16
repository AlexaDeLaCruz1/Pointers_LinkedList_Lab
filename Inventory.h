#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <string>
#include <cstddef> 

class Inventory {
private:
    struct Node {
        Book* data;   // Pointer to the Book object
        Node* next;   // Pointer to the next Node in the list

        Node(Book* b) : data(b), next(nullptr) {}
    };

    Node* head;

public:
    Inventory();
    ~Inventory();

    Inventory(const Inventory& other) = delete;
    Inventory& operator=(const Inventory& other) = delete;

    void addBook(Book* bookPtr);
    void displayAll() const;
    void removeBook(const std::string& title);
    size_t getBookCount() const;
    Book* findBook(const std::string& title) const;
    bool isEmpty() const;
};

#endif // INVENTORY_H
