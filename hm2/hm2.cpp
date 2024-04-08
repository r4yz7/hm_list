
#include <iostream>
#include <string>
#include "ASDList.h"


int main()
{
    ASDList movieList;

    int menu;
    do
    {
        std::cout << "1 - Add film\n2 - Show films\n3 - Sorted by year\n4 - Sorted by title\n0 - Exit\nChoice: ";
        std::cin >> menu;
        switch (menu)
        {
        case 0: {
            exit(0);
        }break;

        case 1: {
            std::string title;
            int year;
            double rating;

            std::cout << "Title: ";
            std::getline(std::cin >> std::ws, title);
            std::cout << "Year: ";
            std::cin >> year;
            std::cout << "Rating: ";
            std::cin >> rating;

            movieList.addElement(Movie(title, year, rating));

        }break;
        case 2: {
            for (Node* current = movieList.getHead(); current != nullptr; current = current->next) {
                current->data.displayInfo();
                std::cout << std::endl;
            }
        }break;
        case 3: {
            std::cout << "Sorted by year:" << std::endl;
            movieList.sortByYear();
            for (Node* current = movieList.getHead(); current != nullptr; current = current->next) {
                current->data.displayInfo();
                std::cout << std::endl;
            }
        }break;
        case 4: {
            std::cout << "Sorted by title:" << std::endl;
            movieList.sortByTitle();
            for (Node* current = movieList.getHead(); current != nullptr; current = current->next) {
                current->data.displayInfo();
                std::cout << std::endl;
            }
        }
        default:
            break;
        }
        system("pause");
        system("cls");
    } while (menu != 0);


    movieList.addElement(Movie("The Shawshank Redemption", 1994, 9.3));
    movieList.addElement(Movie("The Godfather", 1972, 9.2));
    movieList.addElement(Movie("Forrest Gump", 1994, 8.8));





    return 0;
}
