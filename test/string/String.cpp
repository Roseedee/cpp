#include "String.h"

String::String() {
    len = 0;
    data = new char[1];
    data[0] = '\0';
}

String::String(const char* s) : data(nullptr), len(0) {
    if(s != nullptr) {
        len = strlen(s);
        data = new char[len+1];
        strcopy(s);
    }else {
        data = new char[1];
        data[0] = '\0';
    }
}

String::String(const String& other) {
    len = other.len;
    data = new char[len + 1];
    strcopy(other.data);
}

String::operator const char*() const {
    return data;
}

String& String::operator=(const String& other) {
    if(this == &other) return *this;

    char* newData = new char[other.len + 1];

    strcopy(newData, other.data);

    delete[] data;

    data = newData;
    len = other.len;

    return *this;
}

String& String::operator=(const char* s) {
    int newLen = 0;

    if(s != nullptr) newLen = strlen(s);

    char* newData = new char[newLen + 1];

    if(s != nullptr) {
        strcopy(newData, s);
    }else {
        newData[0] = '\0';
    }

    delete[] data;

    data = newData;
    len = newLen;
            
    return *this;
}

String String::operator+(const char* source) const {
    if(source == nullptr) return String();
    String temp(source);
    return temp;
}

String String::operator+(const String& other) const {
    String temp(*this);
    temp += other;
    return temp;
}

String String::operator+(const int n) const {
    char* temp_n = nullptr;
    String temp_str(*this);
    intToString(temp_n, n);
    temp_str += String(temp_n);
    delete[] temp_n;
    return temp_str;
}

String String::operator+(const float f) const {

}

String& String::operator+=(const char* source) {
    if(source == nullptr) return *this = nullptr;
    append(data, source);
    return *this;
}

String& String::operator+=(const String& other) {
    append(data, other.data);
    return *this;
}

String& String::operator+=(const int n) {
    char* temp_n = nullptr;
    intToString(temp_n, n);
    append(data, temp_n);
    return *this;
}

bool String::operator==(const String& other) const {
    return equals(other.data);
}

bool String::operator==(const char* source) const {
    if(source == nullptr) return false;
    return equals(source);
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

bool String::operator!=(const char* source) const {
    return !(*this == source);
}

char& String::operator[](int index) {
    if(index < 0 || index >= len) throw std::out_of_range("index");
    return data[index];
}

const char& String::operator[](int index) const {
    if(index < 0 || index >= len) throw std::out_of_range("index");
    return data[index];
}

const char* String::ptr() const {
    return data;
}

