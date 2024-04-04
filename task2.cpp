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
    coord operator+(const coord &obj);

    coord operator-(const coord &obj);

    coord operator%(const coord &obj);

    coord operator=(const coord &obj);
};

coord coord::operator+(const coord &obj)
{
    coord temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

coord coord::operator-(const coord &obj)
{
    coord temp;
    temp.x = x - obj.x;
    temp.y = y - obj.y;
    return temp;
}

coord coord::operator%(const coord &obj)// передаємо посилання щоб не створювати копій
{
        // double i;
        // cout << "Enter a number: "; Навіщо вводити додаткову змінну?
        // cin >> i;
        // cout << "root of "<< i<< " is "; До чого тут взагалі корень?
        // cout << sqrt(i); Код повинен повертати об'єкт
        // Висновок, це настільки неправильний код що його вважай і нема
    coord temp;
    temp.x = x % obj.x;
    temp.y = y % obj.y;
    return temp;
}

coord coord::operator=(const coord &obj)
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

    obj3 = obj1 % obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 " << "%" << " obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1;
    obj3.get_xy(x, y);
    cout << "(obj3 = obj1) X: " << x << ", Y: " << y << "\n";

    return 0;
}