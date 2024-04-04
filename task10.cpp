#include <iostream>
using namespace std;

class dynarray
{
    int *ptr;
    int size;

public:
    dynarray(int s) // pass size of array in s
    {
        size = s;
        ptr = new int[s];
        if (!ptr)
        {
            cout << "Allocation error\n";
            exit(1);
        }
    }
    int &put(int i)
    { 
        return ptr[i];
    }
    int get(int i)
    { 
        return ptr[i];
    }
    dynarray &operator=(const dynarray &obj)
    {
        if (size < obj.size)
        {
            delete[] ptr;
            ptr = new int[obj.size];
            if (!ptr)
            {
                cout << "Allocation error\n";
                exit(1);
            }
        }
        size = obj.size;
        for (int i = 0; i < size; i++)
            {
                ptr[i] = obj.ptr[i]; // copy values, not pointers
            }
        return *this;
    }
};

int main()
{
    dynarray arr1(5), arr2(2); 

    for (int i = 0; i < 5; i++)
    {
        arr1.put(i) = i; 
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr1.get(i) << " ";
    }

    cout << endl;

    arr2 = arr1;

    cout << arr1.get(0) << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << arr2.get(i) << " ";
    }

    return 0;
}