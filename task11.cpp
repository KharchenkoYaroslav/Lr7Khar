#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class strtype {
public:
char *ptr;//так зазвичай не роблять, це для прикладу!!!
int len;
    strtype(char const *s);
    strtype(const strtype &obj);
    ~strtype() { delete [] ptr;}
    char *get() { return ptr; }
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

strtype::strtype(const strtype &obj) {
    int len = strlen(obj.ptr) + 1;
    ptr = new char[len];
    if (!ptr) { exit(1); }
    strcpy(ptr, obj.ptr);
}

void show(strtype x) {
    char *s = x.get();
    cout << s << "\n";
}

int main() {
    strtype a("Hello"), b("Ok");
    a = b;// Використання конструктора копій тут не викликається, 
    //що дозволяє тимчасово зв'язати параметри кількох об'єктів

    a.len = 10; 
    cout << "a.len: " << a.len << " b.len " << b.len << endl;

    *a.ptr = 'q';

    char* temp = new char[b.len];
    strcpy(temp, b.ptr);
    b.ptr = temp;

    show(a);
    show(b);

    return 0;
}