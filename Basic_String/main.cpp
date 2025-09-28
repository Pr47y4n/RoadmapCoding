#include "string.h"
#include <iostream>

int main() {
    basic_string s1;                       
    basic_string s2("Hello");              
    basic_string s3(s2);                   
    basic_string s4(std::move(s2));        

    s1 = "World";                          
    s3 = 'A';                              
    s4 = s1;                               
    s1 = std::move(s3);                    

    std::cout << "s1 length: " << s1.length() << std::endl;
    std::cout << "s4 empty? " << (s4.empty() ? "yes" : "no") << std::endl;

    return 0;
}
