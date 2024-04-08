#include "ASDList.h"
#include <iostream>
#include <algorithm>

void Movie::displayInfo() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Release year: " << year << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

ASDList::ASDList() : head(nullptr), size(0) {}

ASDList::~ASDList() {
    clearList();
}

Node* ASDList::getHead() const {
    return head;
}

void ASDList::addElement(Movie movie) {
    Node* newNode = new Node(movie);
    if (newNode == nullptr) {
        return;
    }
    newNode->next = head;
    head = newNode;
    size++;
}

void ASDList::sortByYear() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void ASDList::sortByTitle() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = head;
    Node* index = nullptr;
    Movie tempMovie;

    while (current != nullptr) {
        index = current->next;

        while (index != nullptr) {
            if (current->data.getTitle() > index->data.getTitle()) {
                tempMovie = current->data;
                current->data = index->data;
                index->data = tempMovie;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void ASDList::clearList() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}
