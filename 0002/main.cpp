
class IntArray {
    private:
        int data[5];

    public:
        int& operator[](int index) {
            return data[index];
        }
};

int main() {

    IntArray arr;

    arr[0] = 10;
    arr[1] = 20;

    return 0;
}