#include <iostream>
using namespace std;

class coord
{
    int x, y;

public:
    coord()
    {
        x = 0;
        y = 0;
    }
    coord(int i, int j)
    {
        x = i;
        y = j;
    }
    void get_xy(int &i, int &j)
    {
        i = x;
        j = y;
    }

    int coord::operator+(const coord &obj);

    bool coord::operator-(const coord &obj);

    double coord::operator*(const coord &obj);

    char coord::operator/(const coord &obj);

    string coord::operator%(const coord &obj);

    long coord::operator=(const coord &obj);
};

int coord::operator+(const coord &obj)
{
    coord temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

bool coord::operator-(const coord &obj)
{
    coord temp;
    temp.x = x - obj.x;
    temp.y = y - obj.y;
    return temp;
}

double coord::operator*(const coord &obj)
{
    coord temp;
    temp.x = x * obj.x;
    temp.y = y * obj.y;
    return temp;
}

char coord::operator/(const coord &obj)
{
    coord temp;
    temp.x = x / obj.x;
    temp.y = y / obj.y;
    return temp;
}

string coord::operator%(const coord &obj)
{
    coord temp;
    temp.x = x % obj.x;
    temp.y = y % obj.y;
    return temp;
}

long coord::operator=(const coord &obj)
{
    x = obj.x;
    y = obj.y;
    return *this;
}

int main()
{
    coord obj1(10, 18), obj2(5, 3), obj3;
    int x, y;

    obj3 = obj1 + obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 + obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 - obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 - obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 * obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 * obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 / obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 / obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 % obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 "
         << "%"
         << " obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1;
    obj3.get_xy(x, y);
    cout << "(obj3 = obj1) X: " << x << ", Y: " << y << "\n";

    return 0;
}