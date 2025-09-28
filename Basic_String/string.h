#ifndef STRING_H
#define STRING_H

#include <cstddef>

class basic_string {
private:
    char* data;
    size_t len;

public:
    basic_string();
    basic_string(const basic_string& str);
    basic_string(basic_string&& str) noexcept;
    basic_string(const char* s);

    ~basic_string();

    basic_string& operator=(const basic_string& str);
    basic_string& operator=(basic_string&& str) noexcept;
    basic_string& operator=(const char* s);
    basic_string& operator=(char c);

    bool empty() const;
    size_t size() const;
    size_t length() const;
};

#endif
