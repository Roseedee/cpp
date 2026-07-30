#pragma once

#include <iostream>

class String {
    private:
        char* data;
        int len;

        // void update_source_len(const char* source) {
        //     int i = 0;
        //     while(source[i] != '\0') i++;
        //     len = i;
        // }

        static int strlen(const char*);

        void strcopy(const char*);

        static void strcopy(char*, const char*);

        void append(char*&, const char*);

        static bool cstrEquals(const char*, const char*);

        bool equals(const char*) const;

        static size_t intLenDigit(long long int);

        static bool isIntNegative(int);

        static void intToString(char*&, int);

        static void floatToString(char*&, float);

    public:
        String();

        String(const char*);

        String(const String&);
        
        operator const char*() const;

        String& operator=(const String&);

        String& operator=(const char*);

        String operator+(const char*) const;

        String operator+(const String&) const;
        
        String operator+(const int) const;

        String operator+(const float) const;

        String& operator+=(const char*);

        String& operator+=(const String&);

        String& operator+=(const int);
        
        bool operator==(const String&) const;
        
        bool operator==(const char*) const;
        
        bool operator!=(const String&) const;
        
        bool operator!=(const char*) const;
        
        char& operator[](int);
        
        const char& operator[](int) const;
        
        int length() const {
            return len;
        }
        
        bool isEmpty() const {
            return len == 0;
        }
        
        const char* ptr() const;

        bool isNotEmpty() const {
            return len > 0;
        }

        ~String() {
            delete[] data;
        }

        static int length(const char* s) {
            int i = 0;
            while(s[i] != '\0') i++;
            return i;
        }

        static bool equals(const char* s1, const char* s2) {
            return cstrEquals(s1, s2);
        }

        static String toString(const int n, const String& s) {
            char* temp_n = nullptr;
            intToString(temp_n, n);
            String temp_str(temp_n);
            temp_str += s;

            // std::cout << temp_str << std::endl;

            delete[] temp_n;
            return temp_str;
        } 
};