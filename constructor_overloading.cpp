#include <iostream>
#include <cstring>

using namespace std;

class Input
{
private:
    int number;
    char name[30];

public:
    // Default Constructor
    Input()
    {
        number = 3;
        strcpy(name, "NIKHIL");
    }

    // Parameterized Constructor
    Input(int num, const char str[])
    {
        number = num;
        strcpy(name, str);
    }

    // Copy Constructor
    Input(const Input &obj)
    {
        number = obj.number;
        strcpy(name, obj.name);
    }

    // Display Function
    void display() const
    {
        cout << "Number : " << number << endl;
        cout << "Name   : " << name << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    // Calls Default Constructor
    Input obj1;
    cout << "Default Constructor" << endl;
    obj1.display();

    // Calls Parameterized Constructor
    Input obj2(30, "CHARLES");
    cout << "Parameterized Constructor" << endl;
    obj2.display();

    // Calls Copy Constructor
    Input obj3 = obj2;
    cout << "Copy Constructor" << endl;
    obj3.display();

    return 0;
}