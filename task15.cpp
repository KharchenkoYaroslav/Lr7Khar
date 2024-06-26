#include <iostream>
using namespace std;

class coord {
    int x, y; 
public:
    coord() {
        x = 0;
        y = 0;
    }
    coord(int i, int j) {
        x = i;
        y = j;
    }
    void get_xy(int &i, int &j) {
        i = x;
        j = y;
    }
    coord operator+(const coord &obj);

    coord operator-(const coord &obj);

    coord operator<<(const int i);

    coord operator>>(const int i);

    coord operator=(const coord &obj);
};

coord coord::operator+(const coord &obj) {
    coord temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

coord coord::operator-(const coord &obj) {
    coord temp;
    temp.x = x - obj.x;
    temp.y = y - obj.y;
    return temp;
}

coord coord::operator<<(const int i) {
    x = x - i; // можливо я трохи не правильно поняв і треба було x / pow(10, i)
    y = y - i;
    return *this;
}

coord coord::operator>>(const int i) {
    x = x + i;// можливо я трохи не правильно поняв і треба було x * pow(10, i)
    y = y + i;
    return *this;
}

coord coord::operator=(const coord &obj) {
    x = obj.x;
    y = obj.y;
    return *this;
}

int main() {
    coord obj1(10, 18), obj2(5, 3), obj3;
    int x, y;

    obj3 = obj1 + obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 + obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 - obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 - obj2) X: " << x << ", Y: " << y << "\n";

    obj1 << 3;
    obj1.get_xy(x, y);
    cout << "(obj1 << 3) X: " << x << ", Y: " << y << "\n";

    obj2 >> 5;
    obj2.get_xy(x, y);
    cout << "(obj1 >> 5) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1;
    obj3.get_xy(x, y);
    cout << "(obj3 = obj1) X: " << x << ", Y: " << y << "\n";

    return 0;
}