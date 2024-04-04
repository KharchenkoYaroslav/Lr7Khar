#include <iostream>
using namespace std;

class three_d {
    int x, y, z;

public:
    three_d(int i, int j, int k) : x(i), y(j), z(k) {}
    three_d() : x(0), y(0), z(0) {}

    void get(int &i, int &j, int &k) {
        i = x;
        j = y;
        k = z;
    }

    three_d operator+(const three_d &obj);
    three_d operator-(const three_d &obj);
    friend three_d operator++(three_d &obj);
    friend three_d operator--(three_d &obj);

    friend bool operator==(const three_d &obj1, const three_d &obj2);
    friend bool operator!=(const three_d &obj1, const three_d &obj2);
    friend bool operator||(const three_d &obj1, const three_d &obj2);
    friend three_d operator+(int value, const three_d &obj);
    friend three_d operator+(const three_d &obj, int value);
};

three_d three_d::operator+(const three_d &obj){
    return three_d(x + obj.x, y + obj.y, z + obj.z);
}

three_d three_d::operator-(const three_d &obj){
    return three_d(x - obj.x, y - obj.y, z - obj.z);
}

three_d operator++(three_d &obj) {
    ++obj.x;
    ++obj.y;
    ++obj.z;
    return obj;
}

three_d operator--(three_d &obj) {
    --obj.x;
    --obj.y;
    --obj.z;
    return obj;
}

bool operator==(const three_d &obj1, const three_d &obj2) {
    return obj1.x == obj2.x && obj1.y == obj2.y && obj1.z == obj2.z;
}

bool operator!=(const three_d &obj1, const three_d &obj2) {
    return !(obj1 == obj2);
}

bool operator||(const three_d &obj1, const three_d &obj2) {
    return obj1.x || obj2.x || obj1.y || obj2.y || obj1.z || obj2.z;
}

three_d operator+(int value, const three_d &obj) {
    return three_d(value + obj.x, value + obj.y, value + obj.z);
}

three_d operator+(const three_d &obj, int value) {
    return three_d(obj.x + value, obj.y + value, obj.z + value);
}

int main() {
    three_d a(1, 2, 3), b(4, 5, 6), c;

    c = a + b;
    int i, j, k;
    c.get(i, j, k);
    cout << "a + b = (" << i << ", " << j << ", " << k << ")" << endl;

    c = a - b;
    c.get(i, j, k);
    cout << "a - b = (" << i << ", " << j << ", " << k << ")" << endl;

    ++c;
    c.get(i, j, k);
    cout << "++c = (" << i << ", " << j << ", " << k << ")" << endl;

    --c;
    c.get(i, j, k);
    cout << "--c = (" << i << ", " << j << ", " << k << ")" << endl;

    c = 5 + a;
    c.get(i, j, k);
    cout << "5 + a = (" << i << ", " << j << ", " << k << ")" << endl;

    c = b + 7;
    c.get(i, j, k);
    cout << "b + 7 = (" << i << ", " << j << ", " << k << ")" << endl;

    bool equal = (a == b);
    cout << "a == b: " << (equal ? "true" : "false") << endl;

    bool notEqual = (a != b);
    cout << "a != b: " << (notEqual ? "true" : "false") << endl;

    bool logicalOr = (a || b);
    cout << "a || b: " << (logicalOr ? "true" : "false") << endl;

    return 0;
}