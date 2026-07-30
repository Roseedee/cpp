#include "String.h"

int String::strlen(const char* source) {
    int i = 0;
    while(source[i] != '\0') i++;
    return i;
}

void String::strcopy(const char* source) {
    int i = 0;
    while(source[i] != '\0') {
        data[i] = source[i];
        ++i;
    }
    data[i] = '\0';
}

void String::strcopy(char* target, const char* source) {
    int i = 0;
    while(source[i] != '\0') {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';
}

void String::append(char*& target, const char* source) {
    size_t len_s1 = strlen(target);
    size_t len_s2 = strlen(source);
    size_t sum_len = len_s1 + len_s2;

    char* temp = new char[sum_len + 1];

    // std::cout << "address temp append: " << (void*)temp << std::endl;
 
    strcopy(temp, data);
    strcopy(temp + len, source);

    if(target != nullptr) delete[] target;

    target = temp;
    len = sum_len;
}

bool String::cstrEquals(const char* s1, const char* s2) {
    if(s1 == nullptr || s2 == nullptr) return false;

    int s1_len = 0;
    int s2_len = 0;

    while(s1[s1_len] != '\0') s1_len++;
    while(s2[s2_len] != '\0') s2_len++;

    // std::cout << "source 1 len : " << s1_len << "\nsource 2 len : " << s2_len << std::endl; 

    if(s1_len != s2_len) return false;

    for(int i = 0; i < s1_len; i++) {
        // std::cout << "Compare(" << data[i] << "," << source[i] << ")" << std::endl;
        if(s1[i] != s2[i]) {
            return false;
        };
    }
    
    return true;
}

bool String::equals(const char* source) const {
    return cstrEquals(data, source);
}

size_t String::intLenDigit(long long int n) {
    int i = 1;
    while((n /= 10) != 0) i++;
    return i;
}

bool String::isIntNegative(int n) {
    return n < 0;
}

void String::intToString(char*& target, int n) {
    bool isNegative = isIntNegative(n);
    long long int _n = n;
    if(_n < 0) _n = -_n;
    int lenDigit = intLenDigit(_n);

    char* _temp = new char[lenDigit + 1 + isNegative];

    int pos = lenDigit - 1 + isNegative;
    if(isNegative) _temp[0] = '-';

    do{
        // std::cout << "index : " << pos << " : value : " << _n << std::endl;
        _temp[pos] = (_n % 10) + '0';
        _n /= 10;
        pos--;
    }while(_n != 0);

    _temp[lenDigit + isNegative] = '\0';

    if(target != nullptr) delete[] target;

    // std::cout << _temp << std::endl;

    target = _temp;
}

void String::floatToString(char*& target, float f) {
    
}
