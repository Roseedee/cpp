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

        static int strlen(const char* source) {
            int i = 0;
            while(source[i] != '\0') i++;
            return i;
        }

        void strcopy(const char* source) {
            int i = 0;
            while(source[i] != '\0') {
                data[i] = source[i];
                ++i;
            }
            data[i] = '\0';
        }

        static void strcopy(char* target, const char* source) {
            int i = 0;
            while(source[i] != '\0') {
                target[i] = source[i];
                i++;
            }
            target[i] = '\0';
        }

        void append(char*& target, const char* source) {
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

        static bool cstrEquals(const char* s1, const char* s2) {
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

        bool equals(const char* source) const {
            return cstrEquals(data, source);
        }

    public:
        String();

        String(const char*);

        String(const String&);
        
        operator const char*() const;

        String& operator=(const String&);

        String& operator=(const char*);

        const char* ptr() const;

        bool operator==(const String&) const;

        bool operator==(const char*) const;

        bool operator!=(const String&) const;

        bool operator!=(const char*) const;

        String& operator+(const char*);

        String& operator+(const String&);


        String& operator+=(const char*);

        String& operator+=(const String&);

        char& operator[](int);
        
        const char& operator[](int) const;

        int length() const {
            return len;
        }

        bool isEmpty() const {
            return len == 0;
        }

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
};