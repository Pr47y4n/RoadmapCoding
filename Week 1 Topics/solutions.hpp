#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <optional>
#include <utility>
#include <stdexcept>


// I/O Streams
void greet_user() {
    std::string name;
    int age;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "Hello, " << name << "! You are " << age << " years old.\n";
}

// Namespaces
namespace message_one {
    void print() {
        std::cout << "Hello from message one!\n";
    }
}

namespace message_two {
    void print() {
        std::cout << "Hello from message two!\n";
    }
}

// Casting
void demonstrate_casting() {
    double d = 3.7;
    int i = static_cast<int>(d);
    std::cout << "Double: " << d << ", Int: " << i << "\n";
}

// Enumerated Types
enum Color { Red = 1, Green, Blue };
void choose_color(int input) {
    Color c = static_cast<Color>(input);
    switch (c) {
        case Red: std::cout << "Red\n"; break;
        case Green: std::cout << "Green\n"; break;
        case Blue: std::cout << "Blue\n"; break;
        default: std::cout << "Invalid\n";
    }
}

// Structs
struct Person {
    std::string name;
    int age;
};

void print_person(const Person& p) {
    std::cout << p.name << " is " << p.age << " years old.\n";
}

// Conditional and Switch
void switch_example(int number) {
    switch (number) {
        case 1: std::cout << "One\n"; break;
        case 2: std::cout << "Two\n"; break;
        case 3: std::cout << "Three\n"; break;
        default: std::cout << "Other\n"; break;
    }
}

// Function Overloading
void print(int x) {
    std::cout << "Int: " << x << "\n";
}
void print(const std::string& s) {
    std::cout << "String: " << s << "\n";
}

//  C-Style Arrays
void sum_array() {
    int arr[5];
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    std::cout << "Sum: " << sum << "\n";
}

// std::array
void use_std_array() {
    std::array<int, 3> arr = {1, 2, 3};
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// std::vector
void use_vector() {
    std::vector<int> v;
    for (int i = 0; i < 5; ++i) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

// std::pair
void use_pair() {
    std::pair<std::string, int> student = {"John", 20};
    std::cout << student.first << ": " << student.second << "\n";
}

// std::optional
std::optional<int> is_even(int x) {
    if (x % 2 == 0)
        return x;
    else
        return std::nullopt;
}

// Loops
void print_even() {
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 == 0){ 
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}

// Initializer Lists
class Box {
    int dimensions[3];
public:
    Box(std::initializer_list<int> list) {
        int i = 0;
        for (auto it = list.begin(); it != list.end(); ++it) {
            dimensions[i] = *it;
            i++;
        }
    }

    void print() {
        for (int i = 0; i < 3; i++) {
            std::cout << dimensions[i] << " ";
        }
        std::cout << "\n";
    }
};

// Strings
void reverse_string(const std::string& s) {
    for (int i = s.length() - 1; i >= 0; --i) { 
        std::cout << s[i];
    }
    std::cout << "\n";
}

// OOP (Inheritance)
class Animal {
public:
    virtual void speak() { std::cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Bark\n"; }
};

// Pointers
void pointer() {
    int* p = new int(5);
    std::cout << *p << "\n";
    delete p;
}

// Dynamic Array
void dynamic_array_demo() {
    int* arr = new int[5];
    for (int i = 0; i < 5; ++i){ 
        arr[i] = i * 2;
    }
    for (int i = 0; i < 5; ++i) { 
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    delete[] arr;
}

// const
void const_demo() {
    const int x = 10;
    std::cout << x << "\n";
}

// const methods
class Book {
    std::string title;
public:
    Book(std::string t) {
        title = t;
    }
    std::string getTitle() const { 
        return title; 
    }
};

// constexpr
constexpr int square_constexpr(int x) {
    return x * x;
}

// References
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Reference Data Member
class RefHolder {
    int& ref;
public:
RefHolder(int& r) : ref(r) {}
    void print() { std::cout << ref << "\n"; }
};


// const_cast
void remove_const(const int* p) {
    int* modifiable = const_cast<int*>(p);
    *modifiable += 1;
    std::cout << *modifiable << "\n";
}

// Exceptions
int safe_divide(int a, int b) {
    if (b == 0) throw std::runtime_error("Divide by zero");
    return a / b;
}

#endif 
