#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class strtype { 
    char *ptr;
    int len;

public:
    
    strtype(char const *s); // Конструктор, який приймає рядок s і створює новий об'єкт strtype з ним
    ~strtype(); // Деструктор, який звільняє пам'ять
    char *get() { return ptr; } // Метод, який повертає покажчик на рядок
    strtype & operator =(const strtype &obj); // Перевантажений оператор присвоювання
    char & operator [](int i);

};

strtype::strtype(char const *s) {
    len = strlen(s) + 1;
    ptr = new char[len];
    if (!ptr) {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(ptr, s);
}

strtype & strtype :: operator =(const strtype &obj) {
    if (len < obj.len) {
        delete [] ptr;
        ptr = new char[obj.len];
        if (!ptr) {
            cout << "Allocation error\n";
            exit(1);
        }
    }
    len = obj.len;
    strcpy(ptr, obj.ptr);
    return *this;
}

char & strtype :: operator [](int i) {
    if (i < 0 || i >= len) {
            cout << "Index value of " << i << " is out of bounds.\n";
            exit(1);
        }
    return ptr[i];
}

strtype::~strtype() {
    cout << "Freeing ptr\n";
    delete [] ptr;
}

int main() {
    strtype a("Hello"), b("Goodbye");
    cout << a.get() << '\n';
    cout << b.get() << '\n';
    a[0] = b[3];

    a[2] = 'f';
    cout << a[4] << '\n';

    cout << a.get() << '\n';
    cout << b.get() << '\n';

    return 0;
}