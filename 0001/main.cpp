#include <iostream>
#include <string>

class User {
    public:
        User() {
            std::cout << "Create" << std::endl;
        }

        std::string Name() {
            return "Roseedee";
        }

        ~User() {
            std::cout << "Destroy" << std::endl;
        }
};

class MyPtr {
    private:
        User* ptr;

    public:
        MyPtr(User *p) {
            std::cout << p->Name() << std::endl;
            ptr = p;
        }

        User* operator->() {
            return ptr;
        }

        User& operator*() {
            return *ptr;
        }

        ~MyPtr() {
            delete ptr;
        }
};


int main() {

    MyPtr p(new User);

    std::cout << "Hello : " << (*p).Name() << std::endl;

    return 0;
}