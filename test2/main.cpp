#include <iostream>

using namespace std;

int pow(int base, int pow) {
    int temp = base;
    int i = 1;
    while(i < pow) {
        temp *= base;
        i++;
    }
    return temp;
}

int truncateToInt(float f) {
    return static_cast<int>(f);
}

bool isNegative(float f) {
    return f < 0.0;
}

bool isNegative(int n) {
    return n < 0;
}

int fractionalPart(float f) {
    int n = truncateToInt(f);
    f -= n;
    f *= 1000000;
    if(f < 0.0) f = -f;
    int fp = static_cast<int>(f);
    cout << "truncate f number(function) : " << f << endl;
    cout << "truncate number(function) : " << n << endl;
    cout << "frac number(function) : " << fp << endl;
    int fparr[6] = {0, 0, 0, 0, 0, 0};
    int pos = 0;
    do {
        int temp = fp % 10;
        // cout << "pos : " << pos << " value : " << fp << endl;
        fp /= 10;
        if(temp) {
            fparr[pos] = temp;
            pos++;
        }else {
            continue;
        }
    }while(fp != 0);
    for(int i = 0; i < 6; i++) {
        cout << fparr[i] << ", ";
    }
    cout << endl;

    int frac_n;
    // for(int i = pos; i > 0; i--) {
    //     cout << "index : " << i << " value : " << fparr[i] << endl;
    //     frac_n = fparr[i] * pow(10, i);
    // }
    return frac_n;
}

size_t intDigit(int n) {
    int digit = 0;
    do {
        n /= 10;
        digit++;
    }while((n % 10) != 0);
    return digit;
}

// size_t fractionalPartDigit(int n) {
//     for(int i = 6; i > 0; i--) {

//     }
// } 

void floatToString(char*& target, float f) {
    cout << "--------------------------" << endl;
    target = new char[4];
    target = (char*)"End\0";
    int n = truncateToInt(f);
    bool negative = isNegative(n);
    int nlen = intDigit(n);
    int fp = fractionalPart(f);
    
    
    cout << "Value : " << n << endl;
    cout << "digit : " << nlen << endl;
    cout << "frac : " << fp << endl;
}

int main() {
    char* data = nullptr;

    floatToString(data, 0.2124);
    floatToString(data, -1.254);
    floatToString(data, -21.245);
    floatToString(data, 321.244);
    floatToString(data, 1.2557);

    cout << data << endl;
    cout << pow(10, 2) << endl;
    cout << pow(2, 8) << endl;
    cout << pow(2, 16) << endl;

    delete[] data;
    return 0;
}