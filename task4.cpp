#include <iostream>
using namespace std;

class coord {
    int x, y; 
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    int operator==(const coord &obj);
    int operator&&(const coord &obj);
    int operator<(const coord &obj);
    int operator>(const coord &obj);
};

int coord::operator==(const coord &obj) {
    return x == obj.x && y == obj.y;
}

int coord::operator&&(const coord &obj) {
    return (x && obj.x) && (y && obj.y);
}

int coord::operator<(const coord &obj) {
    return (x < obj.x) && (y < obj.y);
}

int coord::operator>(const coord &obj) {
    return (x > obj.x) && (y > obj.y);
}

int main() {
    coord obj1(10, 10), obj2(5, 3), obj3(10, 10), obj4(0, 0), obj5(4,6);

    if (obj1 == obj2) cout << "obj1 same as obj2\n";
    else cout << "obj1 and obj2 differs\n";

    if (obj1 == obj3) cout << "obj1 same as obj3\n";
    else cout << "obj1 and obj3 differ\n";

    if (obj1 && obj2) cout << "obj1 && obj2 is true\n";
    else cout << "obj1 && obj2 is false\n";

    if (obj1 && obj4) cout << "obj1 && obj4 is true\n";
    else cout << "obj1 && obj4 is false\n";



    if (obj1 < obj2) cout << "Values of obj1 smaller then values of obj2\n";
    else cout << "Values of obj1 not smaller then values of obj2\n";

    if (obj1 > obj2) cout << "Values of obj1 bigger then values of obj2\n";
    else cout << "Values of obj1 not bigger then values of obj2\n";

    if (obj2 < obj5) cout << "Values of obj2 smaller then values of obj5\n";
    else cout << "Values of obj2 not smaller then values of obj5\n";

    if (obj2 > obj5) cout << "Values of obj2 bigger then values of obj5\n";
    else cout << "Values of obj2 not bigger then values of obj5\n";

    return 0;
}