#include <iostream>

#define SIZE 100

using namespace std;

class arraytype {
private:
    int arr[SIZE];
public:
    int& operator [](int i) {
        if (i < 0 || i >= SIZE) {
            cout << "Index value of " << i << " is out of bounds.\n";
            exit(1);
        }
        return arr[i];
    }
};

int main() {
    arraytype obj;
    obj[SIZE+100] = 99;
    return 0;
}