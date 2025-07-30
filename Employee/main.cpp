#include "impl.hpp"
#include <iostream>
 
int main() {

    std::vector<db::Person> people;

    db::loadDatabase(people);
 
    while (true) {

        std::cout << "\n1. Add\n2. Delete\n3. Change\n4. Find\n5. List All\n6. Count By Position\n0. Exit\n> ";

        int choice;

        std::cin >> choice;

        std::cin.ignore();
 
        if (choice == 0) break;
 
        switch (choice) {

            case 1: {

                std::string name, surname, phone, email, address, position, date;

                std::cout << "Name: "; std::getline(std::cin, name);

                std::cout << "Surname: "; std::getline(std::cin, surname);

                std::cout << "Phone: "; std::getline(std::cin, phone);

                std::cout << "Email: "; std::getline(std::cin, email);

                std::cout << "Address: "; std::getline(std::cin, address);

                std::cout << "Position: "; std::getline(std::cin, position);

                std::cout << "Date: "; std::getline(std::cin, date);
 
                int id = db::generateNewId(people);

                db::Person newPerson(id, name, surname, phone, email, address, position, date);

                db::addPerson(people, newPerson);

                break;

            }

            case 2: {

                int id;

                std::cout << "Enter ID to delete: ";

                std::cin >> id;

                std::cin.ignore();

                db::deletePerson(people, id);

                break;

            }

            case 3: {

                int id;

                std::cout << "Enter ID to change: ";

                std::cin >> id;

                std::cin.ignore();

                db::changePerson(people, id);

                break;

            }

            case 4: {

                std::string keyword;

                std::cout << "Enter search keyword (name, phone, email): ";

                std::getline(std::cin, keyword);

                db::findPerson(people, keyword);

                break;

            }

            case 5:

                db::listAllPeople(people);

                break;

            case 6:

                db::countByPosition(people);

                break;

            default:

                std::cout << "Invalid option.\n";

        }

    }
 
    std::cout << "Goodbye!\n";

    return 0;

}