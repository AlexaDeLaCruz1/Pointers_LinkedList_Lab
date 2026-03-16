/*
Author: Alexa De La Cruz
Date: 3/12/2026
Purpose: Pointers, Vectors Lab
*/

#include "Inventory.h"
#include <iostream>
#include <string>

// Constructor initializes head to nullptr
Inventory::Inventory() : head(nullptr), count(0) {}

// Destructor walks the list and deletes each node and its book
Inventory::~Inventory() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current->bookPtr; // Clean up the Book object
        delete current;          // Clean up the Node itself
        current = nextNode;
    }
    head = nullptr;
}


void Inventory::addBook(Book* bookPtr) {
    if (bookPtr == nullptr) {
        std::cout << "Error: Cannot add null book pointer.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->bookPtr = bookPtr;
    newNode->next = nullptr;

    // List is empty or a new book comes before the head
    if (head == nullptr || bookPtr->getTitle() < head->bookPtr->getTitle()) {
        newNode->next = head;
        head = newNode;
    } 
    else {
        // traverse to find the insertion point
        Node* current = head;
        while (current->next != nullptr && 
               current->next->bookPtr->getTitle() < bookPtr->getTitle()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    count++;
    std::cout << "Book '" << bookPtr->getTitle() << "' added to inventory.\n";
}

// Shows all books by traversing nodes
void Inventory::displayAll() const {
    if (head == nullptr) {
        std::cout << "No books in inventory.\n";
        return;
    }

    std::cout << "\n=== INVENTORY CONTENTS ===\n";
    std::cout << "Total books: " << count << "\n\n";
    
    Node* current = head;
    int i = 1;
    while (current != nullptr) {
        std::cout << "Book #" << i++ << ":\n";
        current->bookPtr->displayInfo();
        current = current->next;
    }
    std::cout << "\n";
}

// Removes a book by title
void Inventory::removeBook(const std::string& title) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->bookPtr->getTitle() == title) {
            if (previous == nullptr) {
                // Removing the head
                head = current->next;
            } else {
                // Removing from the middle or end
                previous->next = current->next;
            }

            delete current->bookPtr;
            delete current;
            count--;
            std::cout << "Removing book: " << title << "\n";
            return;
        }
        previous = current;
        current = current->next;
    }

    std::cout << "Book '" << title << "' not found in inventory.\n";
}

// Gets the number of books
size_t Inventory::getBookCount() const {
    return count;
}

// Search for a book by title
Book* Inventory::findBook(const std::string& title) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->bookPtr->getTitle() == title) {
            return current->bookPtr;
        }
        current = current->next;
    }
    return nullptr;
}

bool Inventory::isEmpty() const {
    return head == nullptr;
}
