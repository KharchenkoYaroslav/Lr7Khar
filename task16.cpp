#include <iostream>
using namespace std;

class three_d
{
    int x, y, z;

public:
    three_d(int i, int j, int k)
    {
        x = i;
        y = j;
        z = k;
    }
    three_d()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    void get(int &i, int &j, int &k)
    {
        i = x;
        j = y;
        k = z;
    }

    three_d operator+(const three_d &obj);

    three_d operator-(const three_d &obj);

    three_d operator++();

    three_d operator--();
};

three_d three_d::operator+(const three_d &obj){
    return three_d(x + obj.x, y + obj.y, z + obj.z);
}

three_d three_d::operator-(const three_d &obj){
    return three_d(x - obj.x, y - obj.y, z - obj.z);
}

three_d three_d::operator++()
{
    x ++;
    y ++;
    z ++;
    return *this; 
}

three_d three_d::operator--()
{
    x --;
    y --;
    z --;
    return *this; 
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

    return 0;
}