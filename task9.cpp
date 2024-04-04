#include <iostream>
using namespace std;

class alphabetChar
{
    char character;

public:
    alphabetChar() : character('a') {}

    friend alphabetChar operator++(alphabetChar &obj);
    friend alphabetChar operator++(alphabetChar &obj, int notused);

    void print() const
    {
        cout << character << endl;
    }
};

alphabetChar operator++(alphabetChar &obj)
{
    if (obj.character == 'z')
    {
        obj.character = 'a';
    }
    else
    {
        ++obj.character;
    }
    return obj;
}

alphabetChar operator++(alphabetChar &obj, int notused)
{
    alphabetChar temp = obj;
    ++obj;
    return temp;
}

int main()
{
    alphabetChar letter;

    ++letter;
    letter.print();

    letter++;
    letter.print();

    for (int i = 0; i < 24; ++i)
    {
        ++letter;
    }
    letter.print();

    return 0;
}