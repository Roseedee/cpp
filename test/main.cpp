#include <iostream>
#include <variant>
#include "string/String.h"


// using namespace std;

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

        class MemberProxy {
            Student& st;
            String key;

            public:
                MemberProxy(Student& st, const String& key): st(st), key(key) {}

                void operator=(const String& val) {
                    if(key == "id") st.id = val;
                    else if(key == "name") st.name = val;
                    else throw std::out_of_range("Key type mismatch or invalid key");
                }

                operator String() {
                    if(key == "id") return st.id;
                    else if(key == "name") return st.name;
                    else throw std::out_of_range("Key type mismatch or invalid key");
                }

                void operator=(size_t val) {
                    if(key == "age") st.age = st.age_validate(val);
                    else throw std::out_of_range("Key type mismatch or invalid key");
                }

                void operator=(int val) {
                    if(key == "age") {
                        st.age = st.age_validate(static_cast<size_t>(val));
                    }else throw std::out_of_range("Key type mismatch or invalid key");
                }

                operator size_t() {
                    if(key == "age") return st.age;
                    else throw std::out_of_range("Key type mismatch or invalid key");
                }

                operator int() {
                    if(key == "age") return static_cast<int>(st.age);
                    else throw std::out_of_range("Key type mismatch or invalid key");
                }

                void operator=(float val) {
                    if(key == "gpa") st.gpa = st.gpa_validate(val);
                    else throw std::out_of_range("Key type mismatch or invalid key");
                }

                void operator=(double val) {
                    if(key == "gpa") {
                        st.gpa = st.gpa_validate(static_cast<float>(val));
                    }else throw std::out_of_range("Key type mismatch or invalid key");
                }

                operator float() {
                    if(key == "gpa") return st.gpa;
                    else throw std::out_of_range("Key type mismatch or invalid key");
                }

                operator double() {
                    if(key == "gpa") return static_cast<double>(st.gpa);
                    else throw std::out_of_range("Key type mismatch or invalid key");
                }

                operator std::variant<String , size_t, float>() const { 
                    if(key == "id") return st.id;
                    if(key == "name") return st.name;
                    if(key == "age") return st.age;
                    if(key == "gpa") return st.gpa;
                    throw std::out_of_range("No matching key found.");
                }
        };

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

        Student(const Student& other) {
            id = other.id;
            name = other.name;
            age = other.age;
            gpa = other.gpa;
        }

        Student& operator=(const Student& other) {
            id = other.id;
            name = other.name;
            age = other.age;
            gpa = other.gpa;

            return *this;
        }

        bool operator==(const Student& other) const {
            if(id != other.id) return false;
            if(name != other.name) return false;
            if(age != other.age) return false;
            if(gpa != other.gpa) return false;
            return true;
        }

        bool operator!=(const Student& other) const {
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream& os, const Student::MemberProxy& proxy) {
            std::variant<String, size_t, float> v = proxy;
            
            if (std::holds_alternative<String>(v)) {
                os << std::get<String>(v);
            } else if (std::holds_alternative<size_t>(v)) {
                os << std::get<size_t>(v);
            } else if (std::holds_alternative<float>(v)) {
                os << std::get<float>(v);
            }
            return os;
        }

        MemberProxy operator[](const String& key) {
            if(key != "id" && key != "name" && key != "age" && key != "gpa") {
                throw std::out_of_range("No matching key found.");
            }
            return MemberProxy(*this, key);
        }
        
        void print() {
            std::cout << "------------------------------" << std::endl;
            std::cout << "ID : " << id << std::endl;
            std::cout << "Name : " << name << std::endl;
            std::cout << "Age : " << age << std::endl;
            std::cout << "GPA : " << gpa << std::endl;
            std::cout << "------------------------------" << std::endl;
        } 
};

class StudentList {
    Student* students;
    size_t cap;
    size_t current_pos;
    public:
        StudentList(size_t _cap) : cap(_cap) {
            students = new Student[cap];
            current_pos = 0;
        }

        Student operator[](int index) const {
            if(index >= current_pos) throw std::out_of_range("index is over size");
            return students[index];
        }
        
        void add(const Student& student) {
            students[current_pos] = student;
            current_pos++;
        }

        void update(int index, const Student& student) {
            if(index >= current_pos) throw std::out_of_range("index is over size");
            students[index] = student;
        }

        void remove(size_t index) {
            if(index >= current_pos) throw std::out_of_range("index is over size");

            if(index == current_pos - 1) {
                students[index] = Student();
            }else { // index >= 0 && index < current_pos
                for(int i = index; i + 1 < current_pos; i++) {
                    students[i] = students[i + 1];
                }
                students[current_pos - 1] = Student();
            }

            current_pos--;
        }

        void clear() {
            for(int i = 0; i < current_pos; i++) {
                students[i] = Student();
            }
            current_pos = 0;
        }

        size_t capacity() const {
            return cap;
        }

        size_t size() const {
            return current_pos;
        }

        size_t find(const String& id) {
            if(current_pos == 0) throw std::invalid_argument("now list is empty");
            if(id.isEmpty()) throw std::invalid_argument("id is empty");
            for(int i = 0; i < current_pos; i++) {
                String _id = students[i]["id"];
                if(_id == id) {
                    return i;
                }
            }
            return -1;
        }

        void print() const {
            std::cout << "<====== All student list ======>" << std::endl;
            for(int i = 0; i < cap; i++) {
                // std::cout << i + 1 << ". " << students[i]["id"] << " : " << students[i]["name"] << " : "<< students[i]["age"] << " : " << students[i]["gpa"] << std::endl;
                std::cout << i + 1 << " (" << &students[i] << ") ------------" << std::endl;
                students[i].print();
            }
            std::cout << "<---------- List end ---------->" << std::endl;
        }

        ~StudentList() {
            if(students != nullptr) delete[] students;
        }
};

bool operator==(const char* s1, const String& s2) {
    return String::equals(s1, s2);
}

String operator+(const int n, const String& s) {
    return String::toString(n, s);
}

int main() {
    // String s1("Roseedee");
    // String s2("Muhammad");
    // String s31 = s1;
    // String s4("A");
    // String s5("B");

    // s4 += s5;

    // if(s1.isEmpty()) {
    //     std::cout << "String is empty" << std::endl;
    // }

    // if(s1.isNotEmpty()) {
    //     std::cout << "String is not empty" << std::endl;
    // }

    // std::cout << "<---------------Memory Address Test--------------->" << std::endl;
    
    // std::cout << "Data : " << s1 << std::endl;
    // std::cout << "Address : " << (void*)s1.ptr() << std::endl;
    // std::cout << "Data : " << s2 << std::endl;
    // std::cout << "Address : " << (void*)s2.ptr() << std::endl;
    // std::cout << "Data : " << s31 << std::endl;
    // std::cout << "Address : " << (void*)s31.ptr() << std::endl;
    // std::cout << "Data : " << s4 << std::endl;
    // std::cout << "Address : " << (void*)s4.ptr() << std::endl;
    // std::cout << "Data : " << s5 << std::endl;
    // std::cout << "Address : " << (void*)s5.ptr() << std::endl;
    // //s5 after s5 += nullptr
    // s5 += nullptr;
    // std::cout << "Data : " << s5 << std::endl;
    // std::cout << "Address : " << (void*)s5.ptr() << std::endl;
    // //s5 after s5 += "String"
    // s5 += "str";
    // s5 += "ing";
    // s5 += s4;
    // s5 += s1 + s2;
    // s5 += s1 + "end";
    // s2 += s1 + s1;
    // s2 += 100;
    // s2 += -100 + s1 + 100 + s1 + 10 + 40;
    // std::cout << "Data : " << s5 << std::endl;
    // std::cout << "Data : " << (-100 + s1) << std::endl;
    // std::cout << "Data : " << (void*)s1.ptr() << std::endl;
    // std::cout << "Data : " << s2 << std::endl;
    // String sf("float");
    // std::cout << "Data : " << sf << std::endl;
    
    
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
    
    // Student st1("120", "Roseedee", 15, 4.0);
    // Student st2("001", "Muhammad", 18, 3.1);
    // Student st3("002", "Furkhon", 20, 2.2);

    // st1.print();

    // st1 = st2;

    // st2 = st3;

    // st1.print();
    // st2.print();

    // Student stp1("00", "one", 15, 2.0);
    // Student stp2("001", "one", 15, 2.0);

    // if(stp1 == stp2) std::cout << "stp1 == stp2" << std::endl;

    // st1["id"] = "000";
    // st1["name"] = "Uninitialize";
    // st1["age"] = 25;
    // st1["gpa"] = 3.2;

    // st3["name"] = "Ismaael";

    // st1.print();
    // st3.print();

    // std::cout << std::endl;
    
    // String st2_id = st2["id"];
    // String st2_name = st2["name"];
    // int st2_age = st2["age"];
    // double st2_gpa = st2["gpa"];
    
    // std::cout << "st1 id is : " << st1["id"] << std::endl;
    // std::cout << "st1 name is : " << st1["name"] << std::endl;
    // std::cout << "st1 age is : " << st1["age"] << std::endl;
    // std::cout << "st1 gpa is : " << st1["gpa"] << std::endl;
    
    // std::cout << std::endl;

    // std::cout << "st1 id is : " << st2_id << std::endl;
    // std::cout << "st1 name is : " << st2_name << std::endl;
    // std::cout << "st1 age is : " << st2_age << std::endl;
    // std::cout << "st1 gpa is : " << st2_gpa << std::endl;
    Student st1("0001", "Muhammad", 20, 2.3);
    Student st2("0002", "Solahudeen", 23, 3.5);
    Student st3("0003", "Roseedee", 24, 4.0);
    Student st4("0004", "Wanaichoh", 28, 3.8);

    StudentList studentlist(10);

    studentlist.add(st1);
    studentlist.add(st2);
    studentlist.add(st3);

    studentlist.update(0, st4);
    int index_find = studentlist.find("0005"); // return -1 when data not found

    std::cout << "index of result find : " << index_find << std::endl;


    return 0;
}
