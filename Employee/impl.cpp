#include "impl.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

namespace db {

Person::Person(int id_, std::string name_, std::string surname_, std::string phone_,
               std::string email_, std::string address_, std::string position_, std::string date_)
    : id(id_), name(name_), surname(surname_), phone(phone_),
      email(email_), address(address_), position(position_), date(date_) {}

int Person::getId() const { return id; }
std::string Person::getName() const { return name + " " + surname; }
std::string Person::getPhone() const { return phone; }
std::string Person::getEmail() const { return email; }

void Person::setEmail(const std::string& e) { email = e; }
void Person::setAddress(const std::string& a) { address = a; }

std::string Person::serialize() const {
    return std::to_string(id) + "," + name + "," + surname + "," + phone + "," +
           email + "," + address + "," + position + "," + date;
}

Person Person::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::string field;
    std::vector<std::string> fields;

    while (std::getline(ss, field, ',')) {
        fields.push_back(field);
    }

    if (fields.size() != 8) {
        throw std::runtime_error("Invalid record format");
    }

    return Person(
        std::stoi(fields[0]), fields[1], fields[2], fields[3],
        fields[4], fields[5], fields[6], fields[7]
    );
}

void Person::display() const {
    std::cout << "ID: " << id << "\n"
              << "Name: " << name << " " << surname << "\n"
              << "Phone: " << phone << "\n"
              << "Email: " << email << "\n"
              << "Address: " << address << "\n"
              << "Position: " << position << "\n"
              << "Date: " << date << "\n"
              << "---------------------------\n";
}

void loadDatabase(std::vector<Person>& people) {
    std::ifstream file(DB_FILE);
    std::string line;
    people.clear();

    while (std::getline(file, line)) {
        try {
            people.push_back(Person::deserialize(line));
        } catch (...) {
            std::cerr << "Skipping malformed line: " << line << "\n";
        }
    }
}

void saveDatabase(const std::vector<Person>& people) {
    std::ofstream file(DB_FILE);
    for (const auto& p : people) {
        file << p.serialize() << "\n";
    }
}

int generateNewId(const std::vector<Person>& people) {
    int maxId = 0;
    for (const auto& p : people) {
        if (p.getId() > maxId) maxId = p.getId();
    }
    return maxId + 1;
}

void addPerson(std::vector<Person>& people, const Person& p) {
    if (people.size() >= MAX_PEOPLE) {
        std::cerr << "Database full!\n";
        return;
    }
    people.push_back(p);
    saveDatabase(people);
    std::cout << "Person added with ID: " << p.getId() << "\n";
}

void deletePerson(std::vector<Person>& people, int id) {
    auto it = std::remove_if(people.begin(), people.end(), [&](const Person& p) {
        return p.getId() == id;
    });

    if (it != people.end()) {
        people.erase(it, people.end());
        saveDatabase(people);
        std::cout << "Person deleted.\n";
    } else {
        std::cout << "ID not found.\n";
    }
}

void changePerson(std::vector<Person>& people, int id) {
    for (auto& p : people) {
        if (p.getId() == id) {
            std::string newEmail, newAddress;
            std::cout << "Enter new email: ";
            std::getline(std::cin, newEmail);
            std::cout << "Enter new address: ";
            std::getline(std::cin, newAddress);
            p.setEmail(newEmail);
            p.setAddress(newAddress);
            saveDatabase(people);
            std::cout << "Person updated.\n";
            return;
        }
    }
    std::cout << "ID not found.\n";
}

void findPerson(const std::vector<Person>& people, const std::string& keyword) {
    bool found = false;
    for (const auto& p : people) {
        if (p.getName().find(keyword) != std::string::npos ||
            p.getPhone().find(keyword) != std::string::npos ||
            p.getEmail().find(keyword) != std::string::npos) {
            p.display();
            found = true;
        }
    }
    if (!found) std::cout << "No matches found.\n";
}

void listAllPeople(const std::vector<Person>& people) {
    if (people.empty()) {
        std::cout << "Database empty.\n";
        return;
    }
    for (const auto& p : people) {
        p.display();
    }
}

void countByPosition(const std::vector<Person>& people) {
    std::vector<std::pair<std::string, int>> counts;

    for (const auto& p : people) {
        std::stringstream ss(p.serialize());
        std::string token;

        for (int i = 0; i < 6; ++i)
            std::getline(ss, token, ',');

        std::getline(ss, token, ','); 
        bool found = false;
        for (auto& pair : counts) {
            if (pair.first == token) {
                pair.second++;
                found = true;
                break;
            }
        }

        if (!found) {
            counts.push_back({token, 1});
        }
    }

    for (const auto& pair : counts) {
        std::cout << pair.first << ": " << pair.second << " people\n";
    }
}

} // namespace db
