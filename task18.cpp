#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class strtype { 
    char *ptr;
    int len;

public:
    
    strtype(char const *s); 
    ~strtype(); 
    char *get() { return ptr; } 
    strtype & operator =(const strtype &obj); 
    strtype & operator =(const char* str); 
    strtype operator +(const strtype &obj);
    friend int operator ==(const strtype &obj1, const strtype &obj2);
    friend int operator >(const strtype &obj1, const strtype &obj2);
    friend int operator <(const strtype &obj1, const strtype &obj2);
    
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

strtype & strtype :: operator =(const char* str) {
    if (len < (int)strlen(str)) {
        delete [] ptr;
        ptr = new char[strlen(str)];
        if (!ptr) {
            cout << "Allocation error\n";
            exit(1);
        }
    }
    len = strlen(str);
    strcpy(ptr, str);
    return *this;
}

strtype strtype::operator +(const strtype &obj) {
    size_t newLen = obj.len + len;
    char* temp = new char[newLen + 1]; // +1 для '\0'
    if (!temp) {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(temp, ptr);
    strcat(temp, obj.ptr);
    
    strtype result(temp);

    return result;
}

int operator ==(const strtype &obj1, const strtype &obj2){
    return (obj1.len == obj2.len);
}

int operator >(const strtype &obj1, const strtype &obj2){
    return (obj1.len == obj2.len);
}

int operator <(const strtype &obj1, const strtype &obj2){
    return (obj1.len == obj2.len);
}

strtype::~strtype() {
    cout << "Freeing ptr\n";
    delete [] ptr;
}

int main() {
    strtype a("Hello"), b("Goodbye");
    cout << a.get() << endl;
    cout << b.get() << endl;

    strtype c = a + b;
    cout << c.get() << endl;

    strtype d = "NiceDay";

    cout << d.get() << endl;

    int q = d == b;
    cout << "d == b " << q << " (1 - true, 0 - false)" << endl;

    q = a > b;
    cout << "a > b " << q << " (1 - true, 0 - false)" << endl;

    q = d < a;
    cout << "d < a " << q << " (1 - true, 0 - false)" << endl;

    return 0;
}