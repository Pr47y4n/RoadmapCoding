#include "solutions.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== greet_user ===\n";
    greet_user();

    std::cout << "\n=== Namespaces ===\n";
    message_one::print();
    message_two::print();

    std::cout << "\n=== demonstrate_casting ===\n";
    demonstrate_casting();

    std::cout << "\n=== choose_color ===\n";
    int colorInput = 2; // Green
    choose_color(colorInput);

    std::cout << "\n=== print_person ===\n";
    Person p{"Alice", 25};
    print_person(p);

    std::cout << "\n=== switch_example ===\n";
    switch_example(3);

    std::cout << "\n=== print (overloading) ===\n";
    print(42);
    print(std::string("Hello"));

    std::cout << "\nEnter 5 numbers for sum_array:\n";
    sum_array();

    std::cout << "\n=== use_std_array ===\n";
    use_std_array();

    std::cout << "\n=== use_vector ===\n";
    use_vector();

    std::cout << "\n=== use_pair ===\n";
    use_pair();

    std::cout << "\n=== is_even ===\n";
    int testNum = 10;
    auto result = is_even(testNum);
    if (result) std::cout << testNum << " is even\n";
    else std::cout << testNum << " is odd\n";

    std::cout << "\n=== print_even ===\n";
    print_even();

    std::cout << "\n=== Box ===\n";
    Box box{3, 4, 5};
    box.print();

    std::cout << "\n=== reverse_string ===\n";
    std::string sample = "Hello";
    reverse_string(sample);

    std::cout << "\n=== OOP ===\n";
    Animal animal;
    Dog dog;
    animal.speak();
    dog.speak();

    std::cout << "\n=== pointer ===\n";
    pointer();

    std::cout << "\n=== dynamic_array_demo ===\n";
    dynamic_array_demo();

    std::cout << "\n=== const_demo ===\n";
    const_demo();

    std::cout << "\n=== Book class ===\n";
    Book myBook("C++ Primer");
    std::cout << "Book title: " << myBook.getTitle() << "\n";

    std::cout << "\n=== constexpr ===\n";
    constexpr int val = square_constexpr(5);
    std::cout << "Square constexpr: " << val << "\n";

    std::cout << "\n=== swap ===\n";
    int x = 10, y = 20;
    std::cout << "Before swap: x=" << x << ", y=" << y << "\n";
    swap(x, y);
    std::cout << "After swap: x=" << x << ", y=" << y << "\n";

    std::cout << "\n=== RefHolder ===\n";
    int refVal = 100;
    RefHolder holder(refVal);
    holder.print();

    std::cout << "\n=== remove_const ===\n";
    const int constVal = 5;
    remove_const(&constVal);

    std::cout << "\n=== safe_divide ===\n";
    try {
        std::cout << "10 / 2 = " << safe_divide(10, 2) << "\n";
        std::cout << "10 / 0 = " << safe_divide(10, 0) << "\n";  // Will throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
