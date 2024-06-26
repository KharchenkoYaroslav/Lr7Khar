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

    friend coord operator*(const coord &obj, const int i);    
    friend coord operator*(const int i, const coord &obj);   

    friend coord operator-(const coord &obj, const int i);    
    friend coord operator-(const int i, const coord &obj);  
    friend coord operator-(const coord &obj1, const coord &obj2);    
    friend coord operator-(const coord &obj1);  
};

coord operator*(const coord &obj, const int i) {
    coord temp;
    temp.x = obj.x * i;
    temp.y = obj.y * i;
    return temp;
}

coord operator*(const int i, const coord &obj) {
    coord temp;
    temp.x = obj.x * i;
    temp.y = obj.y * i;
    return temp;
}

coord operator-(const coord &obj, const int i){
    coord temp;
    temp.x = obj.x - i;
    temp.y = obj.y - i;
    return temp;
}   
    
coord operator-(const int i, const coord &obj){
    coord temp;
    temp.x = obj.x - i;
    temp.y = obj.y - i;
    return temp;
} 

coord operator-(const coord &obj1, const coord &obj2){
    coord temp;
    temp.x = obj1.x - obj2.x;
    temp.y = obj1.y - obj2.y;
    return temp;
}
coord operator-(const coord &obj1){
    coord temp;
    temp.x = - obj1.x;
    temp.y = - obj1.y;
    return temp;
} 

int main() {
    coord obj1(10, 10), obj2(5, 2), obj3;
    int x, y;

    obj3 = obj1 * 10;
    obj3.get_xy(x, y);
    cout << "(obj1 * 10) X: " << x << ", Y: " << y << "\n";

    obj3 = 10 * obj2;
    obj3.get_xy(x, y);
    cout << "(10 * obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 - 10;
    obj3.get_xy(x, y);
    cout << "(obj1 - 10) X: " << x << ", Y: " << y << "\n";

    obj3 = 10 - obj2;
    obj3.get_xy(x, y);
    cout << "(10 - obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 - obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 - obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = -obj1;
    obj3.get_xy(x, y);
    cout << "(-obj1) X: " << x << ", Y: " << y << "\n";


    return 0;
}