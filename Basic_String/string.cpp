#include "string.h"

basic_string::basic_string() : data(nullptr), len(0) {}

basic_string::basic_string(const basic_string& str) {
    len = str.len;
    if (len > 0) {
        data = new char[len + 1];
        for (size_t i = 0; i < len; i++) {
            data[i] = str.data[i];
        }
        data[len] = '\0';
    } else {
        data = nullptr;
    }
}

basic_string::basic_string(basic_string&& str) noexcept {
    data = str.data;
    len = str.len;
    str.data = nullptr;
    str.len = 0;
}

basic_string::basic_string(const char* s) {
    if (s) {
        len = 0;
        while (s[len] != '\0') {
            len++;
        }
        data = new char[len + 1];
        for (size_t i = 0; i < len; i++) {
            data[i] = s[i];
        }
        data[len] = '\0';
    } else {
        data = nullptr;
        len = 0;
    }
}

basic_string::~basic_string() {
    delete[] data;
}

basic_string& basic_string::operator=(const basic_string& str) {
    if (this != &str) {
        delete[] data;
        len = str.len;
        if (len > 0) {
            data = new char[len + 1];
            for (size_t i = 0; i < len; i++) {
                data[i] = str.data[i];
            }
            data[len] = '\0';
        } else {
            data = nullptr;
        }
    }
    return *this;
}

basic_string& basic_string::operator=(basic_string&& str) noexcept {
    if (this != &str) {
        delete[] data;
        data = str.data;
        len = str.len;
        str.data = nullptr;
        str.len = 0;
    }
    return *this;
}

basic_string& basic_string::operator=(const char* s) {
    delete[] data;
    if (s) {
        len = 0;
        while (s[len] != '\0') {
            len++;
        }
        data = new char[len + 1];
        for (size_t i = 0; i < len; i++) {
            data[i] = s[i];
        }
        data[len] = '\0';
    } else {
        data = nullptr;
        len = 0;
    }
    return *this;
}

basic_string& basic_string::operator=(char c) {
    delete[] data;
    len = 1;
    data = new char[2];
    data[0] = c;
    data[1] = '\0';
    return *this;
}

bool basic_string::empty() const { return len == 0; }
size_t basic_string::size() const { return len; }
size_t basic_string::length() const { return len; }
