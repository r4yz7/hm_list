#ifndef ASDLIST_H
#define ASDLIST_H

#include <string>

class Movie {
public:
    Movie(std::string _title, int _year, double _rating) : title(_title), year(_year), rating(_rating) {}
    Movie() {}
    void displayInfo() const;

    int getYear() const { return year; }
    const std::string& getTitle() const { return title; }

private:
    std::string title;
    int year;
    double rating;
};

class Node {
public:
    Movie data;
    Node* next;

    Node(Movie _data) : data(_data), next(nullptr) {}
};

class ASDList {
private:
    Node* head;
    int size;

public:
    ASDList();
    ~ASDList();

    Node* getHead() const;

    void addElement(Movie movie);

    void sortByYear();

    void sortByTitle();

    void clearList();
};

#endif 
