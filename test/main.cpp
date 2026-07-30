#include <iostream>

#include "string/String.h"

using namespace std;

class Student {
    String id;
    String name;
    size_t age;
    float gpa;

    size_t age_validate(size_t _age) {
        return _age > 0 && _age <= 30 ? _age : throw std::out_of_range("you are over 30 year old");
    }

    float gpa_validate(float _gpa) {
        return _gpa >= 0 && _gpa <= 4.0 ? _gpa : throw std::out_of_range("gpa is wrong");
    }

    public:
        Student() {
            id = "";
            name = "";
            age = 0;
            gpa = 0.0;
        }

        Student(String _id, String _name, size_t _age, float _gpa) : id(_id), name(_name) {
            age = age_validate(_age);
            gpa = gpa_validate(_gpa);
        }
        void print() {
            std::cout << "<---------- Student ---------->" << std::endl;
            // std::cout << "ID : " << id << std::endl;
            // std::cout << "Name : " << name << std::endl;
            // std::cout << "Age : " << age << std::endl;
            // std::cout << "GPA : " << gpa << std::endl;
            String temp("");
            String s1("Roseedee");
            String s2("12");
            int i = 123;

            // temp = s1 + 10;
            std::cout << temp << std::endl;
            std::cout << s1 << std::endl;

        } 
};

class List {

};

bool operator==(const char* s1, const String& s2) {
    return String::equals(s1, s2);
}

String operator+(const int n, const String& s) {
    return String::toString(n, s);
}

int main() {
    String s1("Roseedee");
    String s2("Muhammad");
    String s31 = s1;
    String s4("A");
    String s5("B");

    s4 += s5;

    if(s1.isEmpty()) {
        std::cout << "String is empty" << std::endl;
    }

    if(s1.isNotEmpty()) {
        std::cout << "String is not empty" << std::endl;
    }

    std::cout << "<---------------Memory Address Test--------------->" << std::endl;
    
    std::cout << "Data : " << s1 << std::endl;
    std::cout << "Address : " << (void*)s1.ptr() << std::endl;
    std::cout << "Data : " << s2 << std::endl;
    std::cout << "Address : " << (void*)s2.ptr() << std::endl;
    std::cout << "Data : " << s31 << std::endl;
    std::cout << "Address : " << (void*)s31.ptr() << std::endl;
    std::cout << "Data : " << s4 << std::endl;
    std::cout << "Address : " << (void*)s4.ptr() << std::endl;
    std::cout << "Data : " << s5 << std::endl;
    std::cout << "Address : " << (void*)s5.ptr() << std::endl;
    //s5 after s5 += nullptr
    s5 += nullptr;
    std::cout << "Data : " << s5 << std::endl;
    std::cout << "Address : " << (void*)s5.ptr() << std::endl;
    //s5 after s5 += "string"
    s5 += "str";
    s5 += "ing";
    s5 += s4;
    s5 += s1 + s2;
    s5 += s1 + "end";
    s2 += s1 + s1;
    s2 += 100;
    s2 += -100 + s1 + 100 + s1 + 10 + 40;
    std::cout << "Data : " << s5 << std::endl;
    std::cout << "Data : " << (-100 + s1) << std::endl;
    std::cout << "Data : " << (void*)s1.ptr() << std::endl;
    std::cout << "Data : " << s2 << std::endl;
    String sf("float");
    sf = s1 + 1.2;
    std::cout << "Data : " << sf << std::endl;
    
    
    // std::cout << "<---------------Operator Test--------------->" << std::endl;
    
    // std::cout << (s1 == s31) << std::endl;
    // std::cout << (s1 == s2) << std::endl;
    // std::cout << (s1 == "Roseedee") << std::endl;
    // std::cout << (s1 == "not equals") << std::endl;
    // s1[0] = '1';
    // std::cout << ("Roseedee" == s1) << std::endl;
    // s1[0] = 'R';
    // std::cout << ("Roseedee" == s1) << std::endl;
    // std::cout << s31 << std::endl;
    // std::cout << s1[s1.length() - 1] << std::endl;
    
    // std::cout << "<---------------Student Test--------------->" << std::endl;
    
    // Student st("120", "Roseedee", 15, 4.0);

    // st.print();
    return 0;
}
