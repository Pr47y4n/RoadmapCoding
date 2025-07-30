#include <string>
#include <vector>
 
namespace db {
 
constexpr int MAX_PEOPLE = 1000;
constexpr const char* DB_FILE = "db.txt";
 
class Person {
private:
    int id;
    std::string name;
    std::string surname;
    std::string phone;
    std::string email;
    std::string address;
    std::string position;
    std::string date;
 
public:
    Person() = default;
    Person(int id, std::string name, std::string surname, std::string phone, std::string email, std::string address, std::string position, std::string date);
 
    int getId() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string serialize() const;
    static Person deserialize(const std::string& line);
 
    void setEmail(const std::string&);
    void setAddress(const std::string&);
    void display() const;
};
 
void loadDatabase(std::vector<Person>& people);
void saveDatabase(const std::vector<Person>& people);
 
int generateNewId(const std::vector<Person>& people);
void addPerson(std::vector<Person>& people, const Person& p);
void deletePerson(std::vector<Person>& people, int id);
void changePerson(std::vector<Person>& people, int id);
void findPerson(const std::vector<Person>& people, const std::string& keyword);
void listAllPeople(const std::vector<Person>& people);
void countByPosition(const std::vector<Person>& people);
 
} // namespace db