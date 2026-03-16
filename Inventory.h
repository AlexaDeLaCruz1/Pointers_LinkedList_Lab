#include "Inventory.h"
#include <iostream>

// constructor starts with an empty list
Inventory::Inventory() : head(nullptr) {}

// destructor walks the list and deletes each node and its book
Inventory::~Inventory() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current->data; 
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

// Add a book while maintaining alphabetical order
void Inventory::addBook(Book* bookPtr) {
    if (bookPtr == nullptr) return;

    Node* newNode = new Node(bookPtr);

    //list is empty or the new book should be the new head
    if (head == nullptr || bookPtr->getTitle() < head->data->getTitle()) {
        newNode->next = head;
        head = newNode;
    } 
    else {
        // traverse to find the correct insertion point
        Node* current = head;
        while (current->next != nullptr && 
               current->next->data->getTitle() < bookPtr->getTitle()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    std::cout << "Book '" << bookPtr->getTitle() << "' added to inventory.\n";
}

// Display all books by traversing the list
void Inventory::displayAll() const {
    if (isEmpty()) {
        std::cout << "No books in inventory.\n";
        return;
    }

    std::cout << "\n=== INVENTORY CONTENTS ===\n";
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        std::cout << "Book #" << index++ << ":\n";
        current->data->displayInfo();
        current = current->next;
    }
}

// Remove a book by title and free its memory
void Inventory::removeBook(const std::string& title) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data->getTitle() == title) {
            if (previous == nullptr) {
                head = current->next; // Removing the head
            } else {
                previous->next = current->next; // Bypassing the current node
            }

            std::cout << "Removing book: " << current->data->getTitle() << "\n";
            delete current->data; 
            delete current;       
            return;
        }
        previous = current;
        current = current->next;
    }
    std::cout << "Book '" << title << "' not found in inventory.\n";
}

size_t Inventory::getBookCount() const {
    size_t count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// search for book by title
Book* Inventory::findBook(const std::string& title) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data->getTitle() == title) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

bool Inventory::isEmpty() const {
    return head == nullptr;
}
