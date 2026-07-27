#include <iostream>

using namespace std;

size_t intDigit(long long int value) {
    int i = 1;
    while((value /= 10) != 0) {
        i++;
    }
    return i;
}

bool isNegative(int value) {
    return value < 0;
}

void intToString(char*& target, int value) {
    bool isnegative = isNegative(value);
    long long int _value = value;
    if(_value < 0) _value = -_value;
    int digit = intDigit(_value);

    char* _temp = new char[digit + 1 + isnegative];

    int pos = digit - 1 + isnegative;
    if(isnegative) _temp[0] = '-';
    do {
        // cout << "index : " << pos << " value : " << _value << endl;
        _temp[pos] = (_value % 10) + '0';
        _value /= 10;
        pos--;
    }while(_value != 0);

    _temp[digit + isnegative] = '\0';

    // cout << "temp data in function : " << _temp << endl;

    if(target != nullptr) delete[] target;
    target = _temp;
}

int main() {

    cout << "Hello" << endl;
    // cout << toChar(10) << endl;
    
    // int n = 1234567;

    // int temparr[10];
    // // int tempn = 0;
    // int i = 0;
    // do{
    //     temparr[i] = n % 10;
    //     n = n / 10;
    //     i++;
    // }while(n != 0);
    
    // char *c = new char[i + 1];
    
    // int a = 0;
    // for(int j = i - 1; j >= 0; j--) {
    //     c[a] = temparr[j] + '0';
    //     a++;
    // }
    
    // cout << c;

    char* c = nullptr;

    intToString(c, 100);
    cout << c << endl;
    intToString(c, 1234);
    cout << c << endl;
    intToString(c, 0);
    cout << c << endl;
    intToString(c, 1);
    cout << c << endl;
    intToString(c, -2147483648);
    cout << c << endl;

    cout << "is negative : " << isNegative(2147483648) << endl;

    int n2 = 2147483647;

    cout << n2;
    return 0;
}