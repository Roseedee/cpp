#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
        string owner;
        double balance;
    public:
        BankAccount(string owner, double balance) : owner(owner), balance(balance)  {}

        void deposit(double amount)  {
            balance += amount;
        }

        void withdraw(double amount) {
            balance -= amount;
        }

        void print() {
            cout << "Owner : " << owner << endl;
            cout << "Balance : " << balance << endl;
        }
};

class Vector2D {
    private:
        int x;
        int y;
    public:
        Vector2D(int x, int y) : x(x), y(y) {}

        Vector2D operator+(const Vector2D& other) const {
            return Vector2D(x + other.x, y + other.y);
        }

        void print() {
            cout << "x : " << x << endl;
            cout << "y : " << y << endl;
        }
};

class Array {
    private:
        int* data;
        int size;

        string printData() {
            string temp = "[";
            for(int i = 0; i < size; i++) {
                temp += to_string(*(data + i));
                if(i < size - 1) {
                    temp += ",";
                }
            }
            temp += "]";

            return temp;
        }

    public:
        Array(int n) {
            data = new int[n];
            size = n;
            for(int i = 0; i < n; i++) {
                *(data + i) = 0;
            }
        }

        void set(int index, int value) {
            *(data + index) = value;
        }

        int get(int index) {
            return *(data + index);
        }

        void print() {
            cout << "Data : " << printData() << endl;
            cout << "Size : " << size << endl;
            
        }

        ~Array() {
            delete[] data;
        }
};

class MyString {
    private:
        char* data;
        int length;
        int strlen(const char* c) {
            int len = 0;
            while(*(c + len) != '\0'){
                len++;
            }

            return len + 1;
        }

        void copy(const char* c) {
            int i = 0;
            while(*(c + i) != '\0') {
                data[i] = c[i];
                i++;
            }
            data[i] = '\0';
        }

    public:
        MyString(char *c) {
            length = strlen(c);
            data = new char[length];
            copy(c);
        }

        MyString(const MyString& other) {
            length = strlen(other.data);
            data = new char[length];
            copy(other.data);
        }

        char* ptr() {
            return data;
        }

        operator char*() {
            return data;
        }

        ~MyString() {
            delete[] data;
        }
};


int main() {

    BankAccount acc("Roseedee", 1000);

    acc.deposit(500);
    acc.withdraw(300);

    acc.print();

    // -----------------------------------//
    
    Vector2D v1(10, 20);
    Vector2D v2(5, 8);
    
    Vector2D v3 = v1 + v2;
    
    v3.print();
    
    // -----------------------------------//
    
    Array arr(10);
    
    arr.set(0, 1);
    arr.set(1, 2);
    arr.set(2, 3);
    
    arr.print();
    
    // -----------------------------------//

    MyString s1((char*)"Roseedee");

    MyString s2 = s1;

    cout << "S1 Value : " << s1 << endl;
    cout << "S1 Address : " << (void*)s1.ptr() << endl;

    cout << "S2 Value : " << s2 << endl;
    cout << "S2 Address : " << (void*)s2.ptr() << endl;

    return 0;
}